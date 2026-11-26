# Process comparison · sothmonyoudom-cyber · v1.0

Scale: 1 = fits Club Hub badly on this criterion, 5 = fits very well.

| Criterion               | Weight | Waterfall | Incremental | Scrum-style | Justification (one line each) |
|-------------------------|-------:|----------:|------------:|------------:|-------------------------------|
| Requirements stability  |     25 |         2 |           4 |           5 | The brief case study leaves room for evolving requirements, favoring Scrum sprints over rigid upfront specs. |
| Client availability     |     20 |         1 |           3 |           4 | With the client available only 30 minutes per week, short sprint reviews fit much better than Waterfall's single sign-off. |
| Team experience         |     20 |         2 |           4 |           4 | Strong team skills in C++20, CMake, and Git make modular incremental and sprint-based integration straightforward. |
| Deadline (week 14)      |     20 |         2 |           4 |           5 | Time-boxed sprints guarantee a working, demonstrable C++ build by week 14 even if lower-priority features are cut. |
| Risk                    |     15 |         1 |           4 |           5 | Continuous Git integration and frequent testing catch C++ build bugs early rather than right before the deadline. |
| **Weighted score**      |    100 |      1.65 |        3.80 |        4.60 |                               |