# Process comparison · Team CounterBlock · v1.0

Scale: 1 = fits Club Hub badly on this criterion, 5 = fits very well.

| Criterion               | Weight | Waterfall | Incremental | Scrum-style | Justification (one line each) |
|-------------------------|-------:|----------:|------------:|------------:|-------------------------------|
| Requirements stability  |     25 |         2 |           4 |           5 | The client only gave a brief case study, so evolving requirements favor iterative Scrum sprints over rigid upfront specs. |
| Client availability     |     20 |         1 |           3 |           4 | With the client available only 30 minutes per week, short sprint reviews fit much better than Waterfall's single upfront sign-off. |
| Team experience         |     20 |         2 |           4 |           4 | The team is skilled in C++20, CMake, and Git, making modular incremental and sprint-based integration easy to execute. |
| Deadline (week 14)      |     20 |         2 |           4 |           5 | Time-boxed sprints ensure a working, demonstrable C++ build by the week 14 semester deadline even if lower-priority tasks are dropped. |
| Risk                    |     15 |         1 |           4 |           5 | Continuous Git integration and frequent testing catch C++ build bugs or misunderstood features early rather than at the end. |
| **Weighted score**      |    100 |      1.65 |        3.80 |        4.60 |                               |