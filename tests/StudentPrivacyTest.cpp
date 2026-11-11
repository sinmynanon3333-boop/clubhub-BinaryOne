// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors
#include "clubhub/Student.h"
#include <gtest/gtest.h>
#include <stdexcept>

using clubhub::Student;
using clubhub::maskId;

// Test 1: Redacted hides name, email, phone
TEST(StudentPrivacy, RedactedHidesPersonalData) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    s.giveSmsConsent("012 345 678");
    const std::string r = s.redacted();
    EXPECT_EQ(r, "Student{id=e2******7}");
    EXPECT_EQ(r.find("Test"), std::string::npos);
    EXPECT_EQ(r.find("example.edu"), std::string::npos);
    EXPECT_EQ(r.find("345"), std::string::npos);
}

// Test 2: Optional consents start as OFF (false / empty)
TEST(StudentPrivacy, OptionalConsentsStartOff) {
    Student s{"e20990417", "Alice", "alice@example.edu"};
    EXPECT_FALSE(s.phone().has_value());
    EXPECT_FALSE(s.remindersByEmail());
}

// Test 3: Withdrawing SMS consent completely clears the phone
TEST(StudentPrivacy, WithdrawingSmsConsentErasesPhone) {
    Student s{"e20990417", "Bob", "bob@example.edu"};
    s.giveSmsConsent("012 345 678");
    EXPECT_TRUE(s.phone().has_value());

    s.withdrawSmsConsent();
    EXPECT_FALSE(s.phone().has_value());
}

// Test 4: Rejects email without '@'
TEST(StudentPrivacy, RejectsEmailWithoutAt) {
    EXPECT_THROW((Student{"e20990417", "Charlie", "no-at-sign"}), std::invalid_argument);
}

// Test 5: Rejects phone numbers containing letters
TEST(StudentPrivacy, RejectsPhoneWithLetters) {
    Student s{"e20990417", "David", "david@example.edu"};
    EXPECT_THROW(s.giveSmsConsent("012-CALL-ME"), std::invalid_argument);
}

// Test 6: maskId correctly masks short and regular IDs
TEST(StudentPrivacy, MaskIdHidesShortIdsCompletely) {
    EXPECT_EQ(maskId("1234"), "****");
    EXPECT_EQ(maskId("12"), "**");
    EXPECT_EQ(maskId("e20990417"), "e2******7");
}