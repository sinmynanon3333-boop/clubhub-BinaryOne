
#include "clubhub/ConsoleOutput.h"

#include <cstdlib>
#include <string>
#include <string_view>

namespace clubhub {

namespace {
constexpr std::string_view kAnsiReset  = "\033[0m";
constexpr std::string_view kAnsiGreen  = "\033[32m";
constexpr std::string_view kAnsiRed    = "\033[31m";
constexpr std::string_view kAnsiCyan   = "\033[36m";
constexpr std::string_view kAnsiYellow = "\033[33m";

std::string_view statusAnsiCode(RegistrationStatus s) {
    switch (s) {
        case RegistrationStatus::Registered:
            return kAnsiGreen;
        case RegistrationStatus::Cancelled:
            return kAnsiRed;
        case RegistrationStatus::CheckedIn:
            return kAnsiCyan;
        case RegistrationStatus::Waitlisted:
            return kAnsiYellow;
    }
    return "";
}
}  // namespace

std::string_view statusLabel(RegistrationStatus s) {
    switch (s) {
        case RegistrationStatus::Registered:
            return "REGISTERED";
        case RegistrationStatus::Cancelled:
            return "CANCELLED";
        case RegistrationStatus::CheckedIn:
            return "CHECKED IN";
        case RegistrationStatus::Waitlisted:
            return "WAITLISTED";
    }
    return "UNKNOWN";
}

bool colourEnabled(bool noColorFlag) {
    if (noColorFlag) {
        return false;
    }
    // According to https://no-color.org/, when NO_COLOR is present and
    // non-empty in the environment, ANSI colour should be disabled.
    const char* envNoColor = std::getenv("NO_COLOR");
    if (envNoColor != nullptr && envNoColor[0] != '\0') {
        return false;
    }
    return true;
}

std::string formatStatus(RegistrationStatus s, bool colour) {
    std::string bracketed = "[";
    bracketed.append(statusLabel(s));
    bracketed.push_back(']');

    if (!colour) {
        return bracketed;
    }

    std::string result;
    std::string_view ansi = statusAnsiCode(s);
    result.reserve(ansi.size() + bracketed.size() + kAnsiReset.size());
    result.append(ansi);
    result.append(bracketed);
    result.append(kAnsiReset);
    return result;
}

std::string formatError(std::string_view what, std::string_view why,
                        std::string_view next) {
    std::string result = "Error: ";
    result.append(what);
    result.append(": ");
    result.append(why);
    if (why.empty() || why.back() != '.') {
        result.push_back('.');
    }
    result.append("\nNext step: ");
    result.append(next);
    return result;
}

}  // namespace clubhub