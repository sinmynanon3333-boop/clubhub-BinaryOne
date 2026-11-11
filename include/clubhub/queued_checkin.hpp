#pragma once
#include <chrono>
#include <optional>
#include <string>
#include <vector>

namespace clubhub {
    // Current synchronization state with the central server
    enum class SyncState { Pending, Sent, Accepted, Rejected };

    struct QueuedCheckIn {
        // Idempotency Key: Unique UUID generated on the client device at scan time.
        // Prevents the server from double-counting if an HTTP POST request is retried.
        std::string localId;

        std::string deviceId;      // e.g. "door-scanner-gate-1"
        std::string eventId;       // e.g. "E001"
        std::string studentId;     // e.g. "e20230001"
       std::chrono::system_clock::time_point scannedAt;  // Timestamp when QR was scanned

        int attempts{0};
        SyncState state{SyncState::Pending};
        std::optional<std::string> rejectReason{std::nullopt};
    };

    class CheckInQueue {
    public:
        // Adds an offline scan to the local queue
        bool enqueue(QueuedCheckIn item) {
            for (const auto& existing : items_) {
                if (existing.localId == item.localId) {
                    return false; // Prevent client-side duplicate
                }
            }
            items_.push_back(std::move(item));
            return true;
        }

        // Returns all records waiting to be synced to the server
        std::vector<QueuedCheckIn> pending() const {
            std::vector<QueuedCheckIn> result;
            for (const auto& item : items_) {
                if (item.state == SyncState::Pending) {
                    result.push_back(item);
                }
            }
            return result;
        }

        void markAccepted(const std::string& localId) {
            for (auto& item : items_) {
                if (item.localId == localId) {
                    item.state = SyncState::Accepted;
                    return;
                }
            }
        }

        void markRejected(const std::string& localId, std::string reason) {
            for (auto& item : items_) {
                if (item.localId == localId) {
                    item.state = SyncState::Rejected;
                    item.rejectReason = std::move(reason);
                    return;
                }
            }
        }

    private:
        std::vector<QueuedCheckIn> items_;
    };
}