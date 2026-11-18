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

## Why these weights
- **Requirements stability (25):** Assigned the highest weight because the client only provided a brief case study, meaning unclear rules will likely change as we develop.
- **Client availability (20):** Weighted at 20% because the client can only meet for 30 minutes per week, making regular check-ins essential to prevent building the wrong thing.
- **Team experience (20):** Weighted at 20% because our team's strength in C++20, CMake, and Git directly influences how quickly we can adapt to iterative workflows and testing[cite: 1].
- **Deadline (week 14) (20):** Weighted at 20% because week 14 is a strict semester cutoff where having a working system matters more than unfinished documentation[cite: 1].
- **Risk (15):** Weighted at 15% to account for the chance of failing tests or late integration issues in C++, though strong tool familiarity helps keep this slightly lower than the other factors[cite: 1].

## Calculation for one model
Calculation, Scrum-style:
(25×5 + 20×4 + 20×4 + 20×5 + 15×5) / 100 = (125 + 80 + 80 + 100 + 75) / 100 = 460 / 100 = 4.60

*(Verification for other models: Waterfall = (25×2 + 20×1 + 20×2 + 20×2 + 15×1) / 100 = 1.65; Incremental = (25×4 + 20×3 + 20×4 + 20×4 + 15×4) / 100 = 3.80)*[cite: 1]