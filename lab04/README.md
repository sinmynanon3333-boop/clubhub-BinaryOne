# Lab-04: Reuse inventory

**Author of this README:** Ath Mengcheu (Scrum Master) | **Branch:** `lab-04` | **Date:** 2026-11-18

Lab-04 decides what Club Hub reuses, builds or defers, checks each reused library's licence against our repository licence, and adds GoogleTest and rapidcsv to the build with a smoke test.

## Lab-04 files

| File | Task | Description |
|------|------|-------------|
| `lab04/fundemental-activites.md` | 1 | Fundamental software process activities and how Club Hub covers each one  | 
| `lab04/scores/*.md` | 2 | Individually process scoring file (one per member)  |
| `lab04/process-comparision.md` | 2 | Weighted the process decision (Scrum style, Waterfall, Incremental) by sensitivity analysis |
| `lab04/process-decision.md` | 3 | Chosen process model and the reasons behind the choice |
| `lab04/process.mmd` | 3 | Mermaid source for the diagram of the chosen process |
| `CMakeLists.txt` | 3 | Keeps the pinned GoogleTest v1.15.2, adds pinned rapidcsv v9.07, `csv_smoke_test` target and `gtest_discover_tests` |
| `lab04/iteration-plan.md` | 4 | Plan for the iterations: scope and goals for each one |
| `tests/data/events.csv` | 4 | Two sample events used by the smoke test |
| `tests/csv_smoke_test.cpp` | 4 | Reads the two events through rapidcsv and checks a title and a capacity |
| `lab04/reuse-inventory.md` | 5 | Make-or-reuse table (9 needs), licence check, CTest verification |
| `lab04/README.md` | 5 | This file | Summary record of files, changes, and reused input. | 

## Inputs reused

Fill the hash column with `git log -1 --format=%h -- <file>` (run it on the branch you built from).

| Input | Commit hash used | Why we reuse it |
|-------|------------------|-----------------|
| `lab01/team-charter.md` | `<hash>` | Roles for who commits and who writes the README |
| `lab01/problem-statement.md` | `<hash>` | Needs the registration rules and reports must support |
| `lab02/application-type.md` | `<hash>` | Application type and the CSV storage decision |
| `LICENSE` | `<hash>` | Repository licence the reused libraries are checked against |

## Dependencies added

| Dependency | Version | Licence | Used for |
|------------|---------|---------|----------|
| GoogleTest | v1.15.2 (already used since Lab-03) | BSD-3-Clause | Unit tests (tests only) |
| rapidcsv | v9.07 | BSD-3-Clause | Reading and writing the CSV event store |

Both are fetched by CMake `FetchContent` from pinned release archives (GoogleTest was added in Lab-03, rapidcsv is new), so nothing is committed under `third_party/`.

## Change log

| Date | Change | Author | Commit |
|------|--------|--------|--------|
| 2026-11-18 | Add reuse inventory, licence check, FetchContent GoogleTest and rapidcsv, CSV smoke test | Soth MonyOudom (Developer), Sin Meynanon (Product Owner) | `Lab-04 task 5: FetchContent GoogleTest and rapidcsv, smoke test`; `Lab-04 task 5: record what changed` |
