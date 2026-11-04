#include "include/clubhub/event_csv.hpp"
#include <sstream>
#include <stdexcept>

namespace clubhub {
    EventLoadResult loadEventsCsv(std::istream& in) {
        EventLoadResult result;
        std::string line;
        int lineNo = 1;

        // Skip the header row
        if (!std::getline(in, line)) {
            return result;
        }

        while (std::getline(in, line)) {
            ++lineNo;
            // Strip trailing '\r' (Windows line endings)
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
            if (line.empty()) {
                continue;
            }

            std::stringstream ss{line};
            std::string id, title, startStr, location, capStr;

            if (!std::getline(ss, id, ',') ||
                !std::getline(ss, title, ',') ||
                !std::getline(ss, startStr, ',') ||
                !std::getline(ss, location, ',') ||
                !std::getline(ss, capStr, ',')) {
                result.errors.push_back({lineNo, "expected exactly 5 comma-separated fields"});
                continue;
            }

            std::string extra;
            if (std::getline(ss, extra, ',')) {
                result.errors.push_back({lineNo, "more than 5 fields in CSV row"});
                continue;
            }

            try {
                int capacity = std::stoi(capStr);
                TimePoint start = parseTimePoint(startStr);
                result.events.emplace_back(id, title, start, location, capacity);
            } catch (const std::exception& ex) {
                result.errors.push_back({lineNo, ex.what()});
            }
        }
        return result;
    }
}