# CMMI V3.0 Process Maturity Reflection · Team I2-ISE
Version 1.0 · 2026-11-04 · Bonus Challenge

---

## 1. Where We Are Today: Maturity Level 1 (Initial / Ad-Hoc)

Under the CMMI V3.0 model, our team is currently operating at **Maturity Level 1 (Initial)**. 

### Observable Evidence:
1. **Unpredictable Process Execution:** While we defined team roles in Lab-01, our development habits still rely heavily on individual heroics rather than institutionalized routines. When deadlines approach, team members push code late at night in disorganized bursts.
2. **Ad-Hoc Tooling:** Although we use Git, branch merges in earlier labs frequently caused accidental merge commits and uncoordinated file modifications due to inconsistent `git pull` habits.
3. **Implicit Work Tracking:** Task estimates and sprint workloads have been kept in informal chat messages rather than an actively managed, prioritized task board.

---

## 2. The Practice Area We Adopt Now: Planning (PLAN) & Estimating (EST)

To progress from Level 1 to **Maturity Level 2 (Managed)** during Sprint 1 (Weeks 9–10), Team I2-ISE formally adopts the CMMI practice area: **Planning (PLAN)**.

### Why Planning?
At Level 2, work must be planned, performed, measured, and controlled at the project level. In student software teams, the most common point of failure is "student syndrome"—underestimating technical complexity and postponing implementation until days before the demo. By institutionalizing structured sprint planning, our team creates realistic boundaries around our 48-hour sprint capacity and prevents burnout.

---

## 3. Three Concrete Actions for Sprint 1

Starting in Week 9 (Sprint 1 Planning on 2026-11-30), our team commits to the following three practices:

1. **Granular Work Breakdown (WBS):** The Product Owner and Developers will decompose every backlog user story into tasks requiring **no more than 4 hours each**. Tasks will be posted as distinct GitHub Issues with assigned owners.
2. **Explicit Definition of Done (DoD) Quality Gate:** No Pull Request will be merged into `main` unless it compiles with zero warnings, has accompanying GoogleTests, and is reviewed by at least one teammate.
3. **Weekly 15-Minute Sync & Variance Tracking:** During the weekly Wednesday lab session, the Scrum Master will compare planned task completion against actual progress to identify blocked developers immediately.

---

## 4. How We Measure It: Metric, Target, and Review Schedule

### Process Metric:
- **Sprint Commitment Delivery Rate (CDR):**  
  $$\text{CDR} = \frac{\text{Story Points / Tasks Completed according to DoD}}{\text{Story Points / Tasks Committed at Sprint Planning}} \times 100\%$$

### Quantitative Target:
- **Target:** **$\ge 80\%$ CDR** for both Sprint 1 (Week 10) and Sprint 2 (Week 12).
- **Secondary Target:** Zero unreviewed code merged directly to `main`.

### Review Schedule:
- **Checkpoint Review:** The Scrum Master will inspect the GitHub Project board every Friday afternoon.
- **Sprint Retrospective:** During the Sprint 1 Retrospective (2026-12-11), the team will calculate the actual CDR, document any variance, and calibrate task sizing for Sprint 2.