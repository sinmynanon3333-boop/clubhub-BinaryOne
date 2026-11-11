#include "../include/clubhub/event.hpp"
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace clubhub {
    Event::Event(std::string id, std::string title, TimePoint start,
                 std::string location, int capacity)
        : id_{std::move(id)}, title_{std::move(title)}, start_{start},
          location_{std::move(location)}, capacity_{capacity} {
        if (id_.empty()) {
            throw std::invalid_argument{"Event id cannot be empty"};
        }
        if (title_.empty()) {
            throw std::invalid_argument{"Event title cannot be empty"};
        }
        if (capacity_ <= 0) {
            throw std::invalid_argument{"Event capacity must be positive (got " + std::to_string(capacity_) + ")"};
        }
    }

    TimePoint parseTimePoint(const std::string& text) {
        using namespace std::chrono;
        std::istringstream in{text};
        int y{}, mo{}, d{}, h{}, mi{};
        char dash1{}, dash2{}, colon{};

        // Extract expected pattern: YYYY-MM-DD HH:MM
        if (!(in >> y >> dash1 >> mo >> dash2 >> d >> h >> colon >> mi)) {
            throw std::invalid_argument{"bad date-time format '" + text + "'"};
        }

        // Ensure nothing follows after minute
        char trailing{};
        if (in >> trailing) {
            throw std::invalid_argument{"unexpected trailing characters in '" + text + "'"};
        }

        // Validate exact separators
        if (dash1 != '-' || dash2 != '-' || colon != ':') {
            throw std::invalid_argument{"invalid date-time separators in '" + text + "'"};
        }

        // Validate valid calendar day (e.g. Feb 30 throws)
        const year_month_day date{year{y}, month{static_cast<unsigned>(mo)}, day{static_cast<unsigned>(d)}};
        if (!date.ok()) {
            throw std::invalid_argument{"invalid calendar date in '" + text + "'"};
        }

        // Validate hour and minute ranges
        if (h < 0 || h > 23 || mi < 0 || mi > 59) {
            throw std::invalid_argument{"invalid hour or minute in '" + text + "'"};
        }

        return sys_days{date} + hours{h} + minutes{mi};
    }

    std::string formatTimePoint(TimePoint t) {
        using namespace std::chrono;
        const auto midnight = floor<days>(t);
        const year_month_day date{midnight};
        const hh_mm_ss time{t - midnight};
        std::ostringstream out;
        out << std::setfill('0') << static_cast<int>(date.year()) << '-'
            << std::setw(2) << static_cast<unsigned>(date.month()) << '-'
            << std::setw(2) << static_cast<unsigned>(date.day()) << ' '
            << std::setw(2) << time.hours().count() << ':'
            << std::setw(2) << time.minutes().count();
        return out.str();
    }
}