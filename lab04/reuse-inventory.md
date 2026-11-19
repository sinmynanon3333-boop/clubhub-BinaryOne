# Lab-04: Reuse Inventory (make-or-reuse)

**Project:** ITC Club Hub (clubhub-BinaryOne) | **Branch:** `lab-04` | **Date:** 2026-11-19
**Repository licence (Lab-03):** MIT.

## 1. Make-or-reuse table

Decision key: **Reuse** = use an existing library, **Build** = write it ourselves, **Defer** = decide later, with a trigger.

| # | Need | Options considered | Decision | Reason | Licence | Pinned version | Evidence the project is maintained |
|---|------|--------------------|----------|--------|---------|----------------|------------------------------------|
| 1 | Unit testing | GoogleTest; Catch2; doctest; plain `assert` | **Reuse**: GoogleTest | Already used by `ConsoleOutputTest`; `gtest_discover_tests` registers every test with CTest; fixtures and matchers cover what we need. | BSD-3-Clause | v1.18.0 (release archive URL) | Latest tag v1.18.0, commit dated 2026-08-10; previous v1.17.0 on 2025-04-30 |
| 2 | File storage (CSV, as decided in Lab-02) | rapidcsv; hand-written CSV parser; nlohmann/json (if the team had chosen JSON); SQLite | **Reuse**: rapidcsv | Lab-02 chose CSV (the repo already has `src/event_csv.cpp`). Header-only, no build step, reads columns by header name, handles quoted fields (a comma in an event title breaks a naive `split(',')`). | BSD-3-Clause | v9.07 (release archive URL) | Last release v9.07 on 2026-08-15 (tagged commit `cbd8a0a`, 2026-07-26); v8.99 on 2026-06-14, so releases are frequent |
| 3 | Date and time (24-hour rule) | `std::chrono` (C++20 `year_month_day`, `hh_mm_ss`); Howard Hinnant `date` library; Boost.DateTime; C `<ctime>` | **Reuse**: `std::chrono` | Already in the C++20 toolchain, so no new dependency. Times are stored and shown as 24-hour `HH:MM` (00:00 to 23:59). Only the small `HH:MM` text check is our own code. | Standard library of the compiler (libstdc++: GPL-3.0 with GCC Runtime Library Exception; MSVC STL: Apache-2.0 with LLVM exception) | C++20 (verified with g++ 13.3.0) | Part of ISO C++20; shipped and maintained by compiler vendors |
| 4 | CLI input handling | CLI11; cxxopts; hand-written `argv` parsing | **Defer** | The CLI has one command (`list-events`), so a plain `argv` check is enough today. Revisit when `register` and `report` sub-commands need help text and validation. Candidate: CLI11 (header-only, BSD-3-Clause). | BSD-3-Clause (candidate) | not pinned (deferred) | Check last release date before adopting |
| 5 | Registration rules (capacity, one sign-up per student, closing time) | Rules engine library; plain C++ functions | **Build** | The rules are specific to our club policy and are a few `if` checks over an `Event`. No library models them, and pure functions are easy to unit test. | Our own code (repository licence, MIT) | n/a | n/a (own code, history in Git) |
| 6 | Reminders | OS scheduler (cron / Task Scheduler); timer thread; push notifications; e-mail library | **Defer** | Offline-first design (Lab-02) means delivery belongs to the PWA or service, not the C++ core. Until the delivery channel is chosen, the only code worth writing is a pure `dueReminders(now, events)` function. | n/a | not pinned (deferred) | n/a |
| 7 | Monthly report | `std::ostream` / `std::format` writing Markdown or CSV; {fmt}; template engine (inja); spreadsheet library | **Build** | A report is a count and a sum per month over the event rows: `std::map` plus the rapidcsv reader plus an output stream (`std::format` if the toolchain supports it). A template engine is heavier than the ~30 lines it replaces. | Our own code (MIT) | n/a | n/a |
| 8 | Logging | spdlog; glog; `std::clog` / `std::cerr`; own tiny logger | **Defer** | `ConsoleOutput.cpp` already covers user-facing text. No need for log levels or files yet. Start with `std::cerr`; adopt spdlog when we need levels or rotating files. | MIT (spdlog, candidate) | not pinned (deferred) | spdlog latest tag v1.17.0, commit dated 2026-01-04 |
| 9 | GUI toolkit *(extra row, confirm)* | FLTK; Qt; Dear ImGui | **Reuse**: FLTK | The repo already contains `src/gui` and `Licenses/FLTK-LICENSE.txt`. Listed here so the licence check covers it. | LGPL-2.0 with exception for static linking | FILL IN from your existing build | FILL IN (check the FLTK releases page) |

**Summary:** 3 Reuse (GoogleTest, rapidcsv, `std::chrono`) plus FLTK already in the repo, 2 Build, 3 Defer.

## 2. Licence check

Repository licence from Lab-03: **MIT**. A library is compatible when we can ship it inside an MIT repository without forcing the whole project under different terms.

| Reused library | Its licence | Compatible with MIT repo? | What we must do |
|----------------|-------------|---------------------------|-----------------|
| GoogleTest v1.18.0 | BSD-3-Clause | **Yes** | Used in tests only, never shipped to users. Keep it in `THIRD_PARTY_NOTICES.md` and `licenses/googletest-LICENSE.txt` (Lab-03). |
| rapidcsv v9.07 | BSD-3-Clause (Copyright (c) 2017, Kristofer Berggren) | **Yes** | Header-only, so it is compiled into our program. Keep its copyright notice and licence text with any source or binary we distribute, and do not use the author's name to endorse our product. Add a rapidcsv entry to `THIRD_PARTY_NOTICES.md` and `licenses/rapidcsv-LICENSE.txt`. |
| `std::chrono` (compiler standard library) | libstdc++: GPL-3.0 with GCC Runtime Library Exception | **Yes** | The runtime library exception lets programs built with GCC use libstdc++ without becoming GPL. No notice file needed beyond the compiler's own. |
| FLTK  | LGPL-2.0 with exception | **Yes, with conditions** | Keep `Licenses/FLTK-LICENSE.txt`. The exception permits static linking; if we ever modify FLTK itself, we must publish those modifications under the same licence. |

Deferred candidates (not added yet): CLI11 is BSD-3-Clause and spdlog is MIT, so both would be compatible.
### What a GPL library would require

GPL is a copyleft licence. If we linked a GPL library (for example GPL-3.0) into Club Hub, the combined program counts as a derivative work. When we distribute it, we would have to:

1. release the **whole program's** source under the GPL (not just the library);
2. keep the GPL notices and give recipients the GPL text and the right to get the source;
3. stop describing the program as MIT-only, because the repository LICENSE would no longer match what users receive.

MIT code can be included in a GPL program, but not the other way round, so the dependency would drag the repository to GPL. AGPL goes further (users of a network service can ask for the source). LGPL sits in between: dynamic linking is allowed under MIT terms if users can replace the library. This is a course summary, not legal advice. If a GPL dependency ever looks attractive, ask the teaching assistant first.


## 3. Verification of The first reused dependency

The run below was done in a clean Ubuntu 24.04 container.

Command (clean build folder):

```
cmake -S . -B build && cmake --build build && ctest --test-dir build --output-on-failure
```

Tool versions: g++ (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0, CMake 4.4.5 (the project requires 3.24 or newer).

CTest summary:

```
Test project /home/claude/clubhub/build
    Start 1: CsvSmoke.ReadsTwoEventsThroughRapidcsv
1/1 Test #1: CsvSmoke.ReadsTwoEventsThroughRapidcsv ...   Passed    0.00 sec

100% tests passed out of 1

Total Test time (real) =   0.00 sec
```


