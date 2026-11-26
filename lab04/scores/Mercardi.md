# Process comparison · Mercardi · v1.0

Scale: 1 = fits Club Hub badly on this criterion, 5 = fits very well.

| Criterion               | Weight | Waterfall | Incremental | Scrum-style | Justification (one line each) |
|-------------------------|-------:|----------:|------------:|------------:|-------------------------------|
| Requirements stability  |     25 |         2 |           4 |           5 | Brief case study leaves room for changing requirements, so Scrum sprints fit much better than rigid specs. |
| Client availability     |     20 |         1 |           3 |           4 | Client meets for 30 minutes weekly, supporting short sprint reviews rather than a single upfront sign-off. |
| Team experience         |     20 |         2 |           4 |           4 | Strong team skills in C++20, CMake, and Git make modular incremental and sprint integration straightforward. |
| Deadline (week 14)      |     20 |         2 |           4 |           5 | Time-boxed sprints ensure a working C++ build by week 14 even if lower-priority tasks are dropped. |
| Risk                    |     15 |         1 |           4 |           5 | Continuous Git integration and frequent testing catch C++ build bugs early rather than at the end. |
| **Weighted score**      |    100 |      1.65 |        3.80 |        4.60 |                               |