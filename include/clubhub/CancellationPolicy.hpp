// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors
#pragma once
#include <chrono>

namespace clubhub {

    /**
     * @brief Determines whether a cancellation is legally permitted under REQ-12.
     * @param now Current timestamp (sys_seconds)
     * @param start Event start timestamp (sys_seconds)
     * @return true if cancellation occurs at least 24 hours before start, false otherwise.
     */
    [[nodiscard]] constexpr bool canCancel(std::chrono::sys_seconds now, std::chrono::sys_seconds start) noexcept {
        using namespace std::chrono_literals;
        // Start must be strictly in the future, and difference must be >= 24 hours
        if (now >= start) {
            return false;
        }
        return (start - now) >= 24h;
    }

} // namespace clubhub