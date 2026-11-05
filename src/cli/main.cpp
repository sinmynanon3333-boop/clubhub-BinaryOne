#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "../include/clubhub/event.hpp"
#include "../include/clubhub/event_csv.hpp"

namespace {
    int listEvents(const std::string& path) {
        std::ifstream file{path};
        if (!file) {
            std::cerr << "error: cannot open " << path << '\n';
            return 2;
        }

        auto [events, errors] = clubhub::loadEventsCsv(file);

        // Sort events chronologically by start time
        std::sort(events.begin(), events.end(), [](const clubhub::Event& a, const clubhub::Event& b) {
            return a.start() < b.start();
        });

        // Print aligned table
        std::cout << std::left << std::setw(6)  << "ID"
                  << std::setw(25) << "TITLE"
                  << std::setw(18) << "START"
                  << std::setw(15) << "LOCATION"
                  << std::right << std::setw(8)  << "CAPACITY" << '\n';
        std::cout << std::string(72, '-') << '\n';

        for (const auto& ev : events) {
            std::cout << std::left << std::setw(6)  << ev.id()
                      << std::setw(25) << ev.title()
                      << std::setw(18) << clubhub::formatTimePoint(ev.start())
                      << std::setw(15) << ev.location()
                      << std::right << std::setw(8)  << ev.capacity() << '\n';
        }

        std::cout << "\nLoaded " << events.size() << " event(s).\n";

        // Errors printed to std::cerr
        for (const auto& err : errors) {
            std::cerr << "line " << err.line << ": skipped (" << err.message << ")\n";
        }

        return errors.empty() ? 0 : 1;
    }

    void printUsage() {
        std::cerr << "usage: clubhub list-events [events.csv]\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 2;
    }
    const std::string command{argv[1]};
    if (command == "list-events") {
        return listEvents(argc > 2 ? argv[2] : "D:/clubhub-BinaryOne/data/event.csv");
    }
    std::cerr << "unknown command: " << command << '\n';
    printUsage();
    return 2;
}