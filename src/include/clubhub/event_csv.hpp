#pragma once
#include <istream>
#include <string>
#include <vector>
#include "event.hpp"

namespace clubhub {
    struct CsvError {
        int line;
        std::string message;
    };

    struct EventLoadResult {
        std::vector<Event> events;
        std::vector<CsvError> errors;
    };

    // Reads "id,title,start,location,capacity" rows after one header line
    EventLoadResult loadEventsCsv(std::istream& in);
}