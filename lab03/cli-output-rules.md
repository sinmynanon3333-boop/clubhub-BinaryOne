# CLI Output & Accessibility Rules · ITC Club Hub (`clubhub` CLI)

Our C++ command-line interface (`src/cli/main.cpp`) must be usable across screen readers, Braille displays, monochrome terminals, CI/CD logs, and piped shell scripts. Every CLI command must follow these six rules.

---

### Rule 1: Never use colour alone to convey meaning
Status values must always be printed as explicit, bracketed uppercase words (`[REGISTERED]`, `[CANCELLED]`, `[CHECKED IN]`, `[WAITLISTED]`). ANSI colour codes may only wrap the text as a secondary visual reinforcement.

```text
rule 1: never colour alone
  bad : E-017  Git Workshop      (shown in red)
  good: E-017  Git Workshop      [CANCELLED]
  rule 2: honour NO_COLOR and --no-color
  bad : $ NO_COLOR=1 clubhub status E-017
        \033[31m[CANCELLED]\033[0m
  good: $ NO_COLOR=1 clubhub status E-017
        [CANCELLED]
        rule 2: honour NO_COLOR and --no-color
  bad : $ NO_COLOR=1 clubhub status E-017
        \033[31m[CANCELLED]\033[0m
  good: $ NO_COLOR=1 clubhub status E-017
        [CANCELLED]
        rule 3: say what failed, why, and the next step
  bad : ERR_CAP
  good: Error: cannot register for E-017: the event is full (40 of 40 seats).
        Next step: clubhub waitlist E-017
        rule 4: non-zero exit code on error
  bad : $ clubhub register E-999 e20240012
        Event not found.
        $ echo $?
        0
  good: $ clubhub register E-999 e20240012
        Error: cannot register for E-999: event ID does not exist in data/events.csv.
        Next step: run 'clubhub list' to see valid event IDs.
        $ echo $?
        1
        rule 5: prompts state the expected format
  bad : Enter student ID and confirm:
  good: Enter ITC Student ID (format: eYYYYNNNN, e.g. e20240105): e20240105
        Confirm registration for E-017? [y/N]: y
        rule 6: unambiguous dates (YYYY-MM-DD HH:MM)
  bad : E-017  Git Workshop      10/14/26 5:30
  good: E-017  Git Workshop      2026-10-14 17:30
  ---

### Step 4: C++ Helper Implementation

#### `include/clubhub/ConsoleOutput.h`
```cpp
// include/clubhub/ConsoleOutput.h
// SPDX-License-Identifier: MIT
#pragma once
#include <string>
#include <string_view>

namespace clubhub {

// Declare here only if your repository does not define it yet.
enum class RegistrationStatus { Registered, Cancelled, CheckedIn, Waitlisted };

// Upper-case word for a status: "REGISTERED", "CHECKED IN", ...
std::string_view statusLabel(RegistrationStatus s);

// false when the --no-color flag is set or NO_COLOR exists (no-color.org)
bool colourEnabled(bool noColorFlag);

// "[CANCELLED]", wrapped in ANSI colour codes only if colour is true
std::string formatStatus(RegistrationStatus s, bool colour);

// "Error: <what>: <why>.\nNext step: <next>"
std::string formatError(std::string_view what, std::string_view why,
                        std::string_view next);

}  // namespace clubhub