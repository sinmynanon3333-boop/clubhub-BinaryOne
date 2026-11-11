// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors
#pragma once
#include <optional>
#include <string>
#include <string_view>

namespace clubhub {

    class Student {
    public:
        // Constructor throws std::invalid_argument if id/name empty or email lacks '@'
        Student(std::string id, std::string name, std::string email);

        const std::string& id() const noexcept { return id_; }
        const std::string& name() const noexcept { return name_; }
        const std::string& email() const noexcept { return email_; }
        const std::optional<std::string>& phone() const noexcept { return phone_; }
        bool remindersByEmail() const noexcept { return remindByEmail_; }

        // Consent management
        void giveSmsConsent(std::string phone);
        void withdrawSmsConsent() noexcept;
        void setEmailReminders(bool on) noexcept { remindByEmail_ = on; }

        // Masked representation for logging (never leaks full name, email, or phone)
        std::string redacted() const;

    private:
        std::string id_;
        std::string name_;
        std::string email_;
        std::optional<std::string> phone_;
        bool remindByEmail_ = false;
    };

    // Free helper function: masks ID (e.g. e20990417 -> e2******7, or *** if <= 4 chars)
    std::string maskId(std::string_view id);

} // namespace clubhub