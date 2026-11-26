// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors
#include <gtest/gtest.h>
#include "clubhub/CancellationPolicy.hpp"

using namespace std::chrono;
using namespace std::chrono_literals;
using clubhub::canCancel;

namespace {
    // Event starts on Nov 7, 2026 at 14:00:00 UTC
    constexpr sys_seconds kStart = sys_days{2026y / November / 7} + 14h;
}

TEST(CancellationPolicyTest, AllowsCancellationOneWeekBefore) {
    EXPECT_TRUE(canCancel(kStart - 7 * 24h, kStart));
}

TEST(CancellationPolicyTest, AllowsExactly24HoursBefore) {
    // Exactly 24h before: 2026-11-06 14:00:00
    EXPECT_TRUE(canCancel(kStart - 24h, kStart));
}

TEST(CancellationPolicyTest, RejectsOneSecondTooLate) {
    // 23 hours, 59 minutes, 59 seconds before: 2026-11-06 14:00:01
    EXPECT_FALSE(canCancel(kStart - 24h + 1s, kStart));
}

TEST(CancellationPolicyTest, RejectsOneHourBefore) {
    EXPECT_FALSE(canCancel(kStart - 1h, kStart));
}

TEST(CancellationPolicyTest, RejectsAfterEventStarted) {
    EXPECT_FALSE(canCancel(kStart + 30min, kStart));
}