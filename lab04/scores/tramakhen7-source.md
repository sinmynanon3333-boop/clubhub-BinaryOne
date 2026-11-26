# Process comparison · tramakhen7-source · v1.0

Scale: 1 = fits Club Hub badly on this criterion, 5 = fits very well.

| Criterion               | Weight | Waterfall | Incremental | Scrum-style | Justification (one line each) |
|-------------------------|-------:|----------:|------------:|------------:|-------------------------------|
| Requirements stability  |     25 |         2 |           4 |           5 | Evolving acceptance criteria from a brief case study favor short Scrum sprints over rigid upfront specs. |
| Client availability     |     20 |         1 |           3 |           4 | Client availability of 30 minutes per week works well with bi-weekly or weekly sprint reviews. |
| Team experience         |     20 |         2 |           4 |           4 | Familiarity with C++20, CMake, and Git makes incremental builds and test automation easy to maintain. |
| Deadline (week 14)      |     20 |         2 |           4 |           5 | Sprints ensure a working, tested C++ release by week 14 even if lower-priority stories are deferred. |
| Risk                    |     15 |         1 |           4 |           4 | Early GoogleTest suites and frequent merges catch defects before they block the final demo. |
| **Weighted score**      |    100 |      1.65 |        3.80 |        4.45 |                               |