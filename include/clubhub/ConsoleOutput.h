// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors
#pragma once
#include <string>
#include <string_view>

namespace clubhub {

    enum class RegistrationStatus {
        Registered,
        Cancelled,
        CheckedIn,
        Waitlisted
    };

    // Returns plain text label (e.g. "[REGISTERED]")
    std::string_view statusLabel(RegistrationStatus s);

    // Checks whether color output should be enabled
    bool colourEnabled(bool noColorFlag);

    // Formats status: if colour is true, wraps with ANSI codes, but ALWAYS includes the text label
    std::string formatStatus(RegistrationStatus s, bool colour);

    // Returns actionable, structured error: "Error: <what>. Why: <why>. Next step: <next>"
    std::string formatError(std::string_view what, std::string_view why, std::string_view next);

} // namespace clubhub