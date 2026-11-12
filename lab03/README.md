# Lab 03 – ClubHub

## 1. Files Created or Changed

The following files were created or modified during Lab 03.

| File | Status | Description |
|---|---|---|
| `CMakeLists.txt` | Modified | Updated project build configuration. |
| `include/clubhub/ConsoleOutput.h` | Added | Console output component declaration. |
| `include/clubhub/Student.h` | Added | Student data structure and declaration. |
| `src/ConsoleOutput.cpp` | Added | Console output implementation. |
| `src/Student.cpp` | Added | Student implementation. |
| `tests/ConsoleOutputTest.cpp` | Added | Tests for console output functionality. |
| `tests/StudentPrivacyTest.cpp` | Added | Tests related to student privacy. |
| `lab03/README.md` | Added | Lab 03 documentation and change record. |
| `lab03/accessibility-checklist.md` | Added | Accessibility requirements and checklist. |
| `lab03/ai-feature-proposal.md` | Added | Proposed AI feature documentation. |
| `lab03/cli-output-rules.md` | Added | Command-line output requirements. |
| `lab03/consent-flow.mmd` | Added | Consent workflow diagram. |
| `lab03/data-inventory.md` | Added | Inventory of collected and processed data. |
| `lab03/ethics-cases.md` | Added | Ethical case analyses and decisions. |
| `lab03/licence-decision.md` | Added | Software licence decision and rationale. |
| `lab03/privacy-notice.md` | Added | Privacy notice documentation. |
| `lab03/retention-rules.md` | Added | Data retention rules. |

## 2. Earlier Lab Inputs Reused

Lab 03 builds upon the work completed in the previous labs.

| Previous Lab | Commit Hash | Reused Input |
|---|---|---|
| Lab 01 | `15acfd2` | Previous project requirements, planning, and initial project context. |
| Lab 02 | `97cb469` | Previous implementation and project structure. |

## 3. Change Log

### Documentation and Ethics
- Added accessibility checklist and AI feature proposal.
- Documented command-line output requirements.
- Created consent flow diagram.
- Documented data inventory and privacy notice.
- Established data retention rules.
- Completed ethical analyses for Scenarios A and B.
- Documented software licence decisions.

### Implementation and Testing
- Updated the CMake build configuration.
- Added Student and ConsoleOutput components.
- Added console output tests.
- Added student privacy tests.

### Ethical Improvements
- Proposed role-based access control for cross-club attendance reports.
- Proposed automated regression tests for cancellation rules and attendance calculations.
- Documented decisions and communication with relevant stakeholders.

## 4. Open Client Questions

The following questions require clarification from the client:

1. Which roles should be allowed to access student attendance information?
2. Should cross-club attendance reports require explicit student consent?
3. What information should be included in attendance reports?
4. How long should student attendance and registration records be retained?
5. What should happen when a student cancels a registration within 24 hours of an event?
6. Should known defects be disclosed during a sprint review even when a fix is not yet available?

## 5. Licence

This project is released under the **MIT Licence**. The full text is in [LICENSE](LICENSE).

Copyright (c) 2026 **BinaryOne**, ITC Club Hub contributors.

## 6. Third-party Components

Third-party code used by this project is listed in [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md). The licence text of each component is kept in the [licenses](licenses/) folder.

| Component | Version | Licence | Source | Used for | Shipped? |
|---|---|---|---|---|---|
| GoogleTest | 1.15.2 | BSD-3-Clause | https://github.com/google/googletest | tests | no |
| FLTK | `Version 2` | LGPL-2.0 with FLTK exception | https://www.fltk.org | GUI | yes |

Full details are in [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md), and each component's licence text is in the [licenses](licenses/) folder.

ITC Club Hub is based in part on the work of the FLTK project (https://www.fltk.org).
