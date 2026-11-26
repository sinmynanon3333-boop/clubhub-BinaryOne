# Process comparison · Team CounterBlock · v1.0

Scale: 1 = fits Club Hub badly on this criterion, 5 = fits very well.

| Criterion               | Weight | Waterfall | Incremental | Scrum-style | Justification |
|-------------------------|-------:|----------:|------------:|------------:|-------------------------------|
| Requirements stability  |     25 |         2 |           4 |           5 | The client only gave a brief case study, so evolving requirements favor iterative Scrum sprints over rigid upfront specs. |
| Client availability     |     20 |         1 |           3 |           4 | With the client available only 30 minutes per week, short sprint reviews fit much better than Waterfall's single upfront sign-off. |
| Team experience         |     20 |         2 |           4 |           4 | The team is skilled in C++20, CMake, and Git, making modular incremental and sprint-based integration easy to execute. |
| Deadline (week 14)      |     20 |         2 |           4 |           5 | Time-boxed sprints ensure a working, demonstrable C++ build by the week 14 semester deadline even if lower-priority tasks are dropped. |
| Risk                    |     15 |         1 |           4 |           5 | Continuous Git integration and frequent testing catch C++ build bugs or misunderstood features early rather than at the end. |
| **Weighted score**      |    100 |      1.65 |        3.80 |        4.60 |                               |

## Why these weights
- **Requirements stability (25):** Assigned the highest weight because the client only provided a brief case study, meaning unclear rules will likely change as we develop.
- **Client availability (20):** Weighted at 20% because the client can only meet for 30 minutes per week, making regular check-ins essential to prevent building the wrong thing.
- **Team experience (20):** Weighted at 20% because our team's strength in C++20, CMake, and Git directly influences how quickly we can adapt to iterative workflows and testing.
- **Deadline (week 14) (20):** Weighted at 20% because week 14 is a strict semester cutoff where having a working system matters more than unfinished documentation.
- **Risk (15):** Weighted at 15% to account for the chance of failing tests or late integration issues in C++, though strong tool familiarity helps keep this slightly lower than the other factors.

## Calculation for one model
Calculation, Scrum-style:
(25×5 + 20×4 + 20×4 + 20×5 + 15×5) / 100 = (125 + 80 + 80 + 100 + 75) / 100 = 460 / 100 = 4.60

*(Verification for other models: Waterfall = (25×2 + 20×1 + 20×2 + 20×2 + 15×1) / 100 = 1.65; Incremental = (25×4 + 20×3 + 20×4 + 20×4 + 15×4) / 100 = 3.80)*

## Sensitivity check
Moving 10 points from Requirements stability (25 → 15) to Risk (15 → 25) changes the scores to Waterfall 1.55, Incremental 3.80, and Scrum-style 4.60, so the winner does not change.

## Conclusion
Scrum-style iterative development scores highest (4.60) because it directly addresses Club Hub's evolving requirements, limited 30-minute weekly client availability, and strict week 14 deadline through short, demonstrable increments. Its biggest weakness is the risk of scope creep and C++ class refactoring if we jump into coding without agreeing on module interfaces first, which we will manage with strict sprint backlogs and automated CMake tests. A lightweight hybrid—pairing Scrum sprints with a brief, upfront Waterfall-style architecture and CSV data design phase in week 1—would likely score even better by preventing structural rework mid-semester.