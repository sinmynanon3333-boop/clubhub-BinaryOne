// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors
#include <gtest/gtest.h>
#include <rapidcsv.h>
#include <string>
#include <vector>

TEST(CsvSmokeTest, ReadsEventTitlesAndCapacities) {
    // Load test CSV relative to the project source directory
    rapidcsv::Document doc("tests/data/events.csv");
    
    const std::vector<std::string> titles = doc.GetColumn<std::string>("title");
    const std::vector<int> capacities = doc.GetColumn<int>("capacity");
    
    // Verify file contents
    ASSERT_EQ(titles.size(), 2U);
    EXPECT_EQ(titles.at(0), "Robotics Workshop");
    EXPECT_EQ(titles.at(1), "Hackathon Night");
    EXPECT_EQ(capacities.at(0), 25);
    EXPECT_EQ(capacities.at(1), 30);
}