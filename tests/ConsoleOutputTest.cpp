// tests/ConsoleOutputTest.cpp
// SPDX-License-Identifier: MIT
#include "clubhub/ConsoleOutput.h"
#include <gtest/gtest.h>
#include <cstdlib>
#include <string>

namespace clubhub {
namespace {

TEST(ConsoleOutput, StatusIsReadableWithoutColour) {
    EXPECT_EQ(formatStatus(RegistrationStatus::Registered, false), "[REGISTERED]");
    EXPECT_EQ(formatStatus(RegistrationStatus::Cancelled, false), "[CANCELLED]");
    EXPECT_EQ(formatStatus(RegistrationStatus::CheckedIn, false), "[CHECKED IN]");
    EXPECT_EQ(formatStatus(RegistrationStatus::Waitlisted, false), "[WAITLISTED]");

    // Verify no ANSI escape character ('\033') is present when colour is false
    const std::string plain = formatStatus(RegistrationStatus::Cancelled, false);
    EXPECT_EQ(plain.find('\033'), std::string::npos);
}

TEST(ConsoleOutput, ColourOnlyRepeatsTheWord) {
    const std::string colouredCancelled =
        formatStatus(RegistrationStatus::Cancelled, true);
    const std::string colouredCheckedIn =
        formatStatus(RegistrationStatus::CheckedIn, true);

    // Must still contain the explicit bracketed word
    EXPECT_NE(colouredCancelled.find("[CANCELLED]"), std::string::npos);
    EXPECT_NE(colouredCheckedIn.find("[CHECKED IN]"), std::string::npos);

    // Must wrap with ANSI escape sequences when colour is enabled
    EXPECT_NE(colouredCancelled.find("\033["), std::string::npos);
    EXPECT_NE(colouredCancelled.find("\033[0m"), std::string::npos);

    // Verify --no-color flag disables colour
    EXPECT_FALSE(colourEnabled(true));
}

TEST(ConsoleOutput, ErrorSaysWhatWhyAndNextStep) {
    const std::string err = formatError(
        "cannot register for E-017",
        "the event is full (40 of 40 seats)",
        "clubhub waitlist E-017");

    EXPECT_EQ(
        err,
        "Error: cannot register for E-017: the event is full (40 of 40 seats).\n"
        "Next step: clubhub waitlist E-017");
    EXPECT_NE(err.find("Error: "), std::string::npos);
    EXPECT_NE(err.find("Next step: "), std::string::npos);
}

}  // namespace
}  // namespace clubhub