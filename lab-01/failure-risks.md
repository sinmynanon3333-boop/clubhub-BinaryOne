# Failure risks · ITC Club Hub (v1.0, 2026-10-20)

| # | How the project could fail | Chapter 01 topic | Early warning sign | First countermeasure | Owner |
|---|----------------------------|------------------|--------------------|----------------------|-------|
| **F1** | **Scope Creep and Feature Bloat:** Trying to build a full GUI/Web app instead of focusing on core C++ business rules. | Requirements Engineering & Planning | Backlog grows with non-essential UI features during Sprint planning. | Enforce strict MoSCoW prioritization; keep UI model-only. | Soth Mony Oudam |
| **F2** | Two developers implement "capacity" differently (seats vs. registrations) and the rules drift apart. | Essential difficulties (invisibility) | The same rule appears in two places in the code. | One function per business rule + a unit test; rules listed in the README. | Sin Meynanon |
| **F3** | **Communication Bottlenecks:** Team members work in silos, leading to merge conflicts and duplicated work. | Communication overhead ($n(n-1)/2$) | PRs remain unreviewed for >3 days; sudden merge collisions on `main`. | Standup sync twice a week; assign specific module owners. | Ngoun Taymeng |
| **F4** | Student e-mails and phone numbers leak through a CSV file pushed to a public repository. | Reliability, security and safety | Real data files appear in `git status`. | Only invented test data in the repo; data/ in `.gitignore`. | Tra Makhen |
| **F5** | **Last-Minute Integration Disaster:** Code only runs on one student's laptop and fails on CI or other machines. | Accidental difficulty / Tooling consistency | "It works on my machine" excuses during lab checks. | Standardize CMake build scripts and enforce automated GitHub Actions CI. | Ath Mengcheu |
