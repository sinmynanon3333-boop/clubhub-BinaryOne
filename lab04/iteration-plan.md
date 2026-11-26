# Iteration Plan (Weeks 5 to 14) · Team I2-ISE
Version 1.0 · 2026-11-04 · Lead: Scrum Master (Sprint 1)

---

## 1. Semester Gantt Chart (Mermaid)

```mermaid
gantt
    title ITC Club Hub · Iteration Plan (Weeks 5 to 14)
    dateFormat  YYYY-MM-DD
    axisFormat  %d %b
    tickInterval 1week
    weekday monday
    excludes weekends

    section Requirements
    Elicitation interview with client   :req1, 2026-11-02, 5d
    SRS and Product Backlog creation    :req2, after req1, 5d

    section Models
    UML diagrams (Use Case & Class)     :mod1, 2026-11-16, 5d

    section Checkpoint
    Midterm Exam Week (No Sprint Work)  :crit, exam, 2026-11-23, 5d
    Checkpoint 1 Presentation           :milestone, cp1, 2026-11-27, 0d

    section Sprint 1
    Sprint 1 Planning                   :milestone, sp1_start, 2026-11-30, 0d
    Sprint 1 Development (Core Rules)   :sp1_dev, 2026-11-30, 10d
    Sprint 1 Review & Client Demo       :milestone, sp1_end, 2026-12-11, 0d

    section Sprint 2
    Sprint 2 Planning                   :milestone, sp2_start, 2026-12-14, 0d
    Sprint 2 Development (Check-in/CSV) :sp2_dev, 2026-12-14, 10d
    Sprint 2 Review & Retrospective     :milestone, sp2_end, 2026-12-25, 0d

    section Hardening
    Bug fixes only & Feature Freeze     :hard1, 2026-12-28, 5d

    section Submission
    Final Submission & Client Demo      :milestone, sub1, 2027-01-08, 0d

    section Labs Schedule
    Lab-05: Requirements & SRS          :lab5, 2026-11-02, 10d
    Lab-06: Architecture & UML          :lab6, 2026-11-16, 5d
    Lab-07: Domain Implementation       :lab7, 2026-11-30, 5d
    Lab-08: Unit & Integration Testing  :lab8, 2026-12-07, 5d
    Lab-09: File I/O & Persistence      :lab9, 2026-12-14, 5d
    Lab-10: Refactoring & Verification  :lab10, 2026-12-21, 5d
    Lab-11: Hardening & Packaging       :lab11, 2026-12-28, 5d
```

---

## 2. Iteration Goals and Capacity Table

### Capacity Formula:
$$\text{Capacity} = \text{Members (5)} \times \text{Hours/Week (6)} \times \text{Duration (2 weeks)} \times 0.8\text{ (Focus Factor)} = \mathbf{48\text{ productive person-hours}}$$

| Iteration | Weeks | Calendar Dates | Goal | Candidate Features | Capacity | Exit Criterion (Definition of Done) |
| :--- | :---: | :---: | :--- | :--- | :---: | :--- |
| **Requirements** | 5–6 | Nov 02 – Nov 13 | Elicit and document all functional & non-functional requirements. | User stories for Student, Club Leader, and Admin; initial backlog. | ~48h | SRS approved by TA; product backlog populated with prioritized user stories. |
| **Modeling** | 7 | Nov 16 – Nov 20 | Create structural and behavioral software architecture. | Use Case diagram, Domain Class diagram, sequence diagrams. | ~24h | UML models reviewed; complete alignment with SRS requirements. |
| **Checkpoint 1** | 8 | Nov 23 – Nov 27 | Review progress; focus on midterm exams (no coding). | Presentation slides and deliverable audit. | ~10h | Passing Checkpoint 1 evaluation with client/instructor. |
| **Sprint 1** | 9–10 | Nov 30 – Dec 11 | Build and verify core domain models and booking business rules in C++20. | `Event`, `Student`, `Registration`, capacity limits, 24h cancellation rule. | **48h** | All Sprint 1 user stories have passing GoogleTest unit tests; clean build with CMake. |
| **Sprint 2** | 11–12 | Dec 14 – Dec 25 | Implement persistence, door check-in, and accessible CLI frontend. | CSV storage reader/writer, check-in command, accessible error output. | **48h** | End-to-end CLI runs cleanly; 100% regression tests pass; client demo completed. |
| **Hardening** | 13 | Dec 28 – Jan 01 | Feature freeze; bug fixing, documentation polish, and release packaging. | Defect fixes, documentation updates, memory leak checks. | ~24h | Zero open high-priority bugs; clean build on Windows/Linux; README updated. |
| **Submission** | 14 | Jan 04 – Jan 08 | Final demonstration and project defense. | Final release tag, live demo presentation. | ~10h | Code merged to `main`; release tagged; successful client demonstration. |