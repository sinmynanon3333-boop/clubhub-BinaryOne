# Process comparison · Ngountaymeng · v1.0

Scale: 1 = fits Club Hub badly on this criterion, 5 = fits very well.

| Criterion               | Weight | Waterfall | Incremental | Scrum-style | Justification (one line each) |
|-------------------------|-------:|----------:|------------:|------------:|-------------------------------|
| Requirements stability  |     25 |         2 |           4 |           5 | Brief case study means rules will evolve during development, making Scrum sprints safer than Waterfall. |
| Client availability     |     20 |         1 |           3 |           4 | Client is available 30 minutes per week, which aligns well with regular sprint demos over upfront sign-off. |
| Team experience         |     20 |         3 |           4 |           4 | Our experience with C++20, CMake, and Git supports modular incremental and sprint-based workflows smoothly. |
| Deadline (week 14)      |     20 |         2 |           4 |           5 | Time-boxed sprints guarantee a working, testable C++ build by week 14 even if minor features are cut. |
| Risk                    |     15 |         1 |           3 |           5 | Frequent Git integration and GoogleTest runs catch C++ logic bugs early instead of right before submission. |
| **Weighted score**      |    100 |      1.85 |        3.65 |        4.60 |                               |