// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors
#include "clubhub/Student.h"
#include <stdexcept>
#include <algorithm>
#include <cctype>

namespace clubhub {

    std::string maskId(std::string_view id) {
        if (id.length() <= 4) {
            return std::string(id.length(), '*');
        }
        // Keep first 2 and last 1 char: e.g. e20990417 -> e2******7
        std::string masked;
        masked.reserve(id.length());
        masked.push_back(id[0]);
        masked.push_back(id[1]);
        masked.append(id.length() - 3, '*');
        masked.push_back(id.back());
        return masked;
    }

    Student::Student(std::string id, std::string name, std::string email)
        : id_(std::move(id)), name_(std::move(name)), email_(std::move(email)) {
        if (id_.empty()) {
            throw std::invalid_argument("Student ID cannot be empty");
        }
        if (name_.empty()) {
            throw std::invalid_argument("Student name cannot be empty");
        }
        if (email_.find('@') == std::string::npos) {
            throw std::invalid_argument("Invalid email: missing '@'");
        }
    }

    void Student::giveSmsConsent(std::string phone) {
        if (phone.empty()) {
            throw std::invalid_argument("Phone number cannot be empty");
        }
        // Validate digits, spaces, and '+' only (reject letters)
        for (char c : phone) {
            if (!std::isdigit(static_cast<unsigned char>(c)) && c != ' ' && c != '+' && c != '-') {
                throw std::invalid_argument("Phone number contains invalid characters");
            }
        }
        phone_ = std::move(phone);
    }

    void Student::withdrawSmsConsent() noexcept {
        phone_.reset();
    }

    std::string Student::redacted() const {
        return "Student{id=" + maskId(id_) + "}";
    }

} // namespace clubhub