# Challenge: Offline-First Check-In for ITC Club Hub
Version 1.0 2026-11-02 Team: BinaryOne

---

## 1. Sequence Diagram: Offline Scan & Reconciliation 
This diagram illustrates an organizer scanning a QR code while disconnected, saving it locally, reconnecting to Wi-Fi and batch-syncing to the server.
```mermaid
sequenceDiagram
    autonumber
    actor Organizer
    participant UI as PWA Scanner UI
    participant SW as ServiceWorker
    participant DB as IndexedDB Queue
    participant API as Club Hub Backend

    Note over Organizer,DB: Phase 1: Offline Scan (No Wi-Fi at Door)
    Organizer->>UI: Scans student QR code (Student e20230001)
    UI->>SW: checkIn(studentId, eventId, timestamp)
    SW->>DB: Store QueuedCheckIn (localId: UUID, state: Pending)
    DB-->>SW: Stored successfully
    SW-->>UI: Return Cached OK
    UI-->>Organizer: Show Green Screen "Checked In (Offline Queue)"

    Note over Organizer,API: Phase 2: Wi-Fi Reconnects & Batch Sync
    SW->>SW: Network status change -> ONLINE
    SW->>DB: Read all pending check-ins
    DB-->>SW: Return batch [QueuedCheckIn #1, #2, ...]
    SW->>API: POST /api/v1/events/{id}/checkin-batch (Payload with UUIDs)
    
    alt Successful Batch Sync
        API->>API: Deduplicate via localId & validate registrations
        API-->>SW: HTTP 200 OK [{localId: UUID, status: "Accepted"}]
        SW->>DB: Mark items state = Accepted
    else Duplicate or Conflict Detected
        API-->>SW: HTTP 200 OK [{localId: UUID, status: "Rejected", reason: "Already checked in at Door 2"}]
        SW->>DB: Mark item state = Rejected (audit flagged)
    end
```