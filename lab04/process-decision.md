# PDR-001 · Development Process for ITC Club Hub
Status: Accepted  
Date: 2026-11-20  
Deciders: All Team Members ([Team Name, e.g., Team I2-ISE])  
Lead: Product Owner  

---

## 1. Context (Driving Facts)

1. **Course Calendar:** A 15-week academic semester with fixed milestones: Checkpoint 1 in Week 8, and final submission/demo in Week 14 (`lab01/team-charter.md`).
2. **Team Capacity:** [5] student developers, each contributing approximately [6] hours per week alongside other university courses (`lab01/team-charter.md`).
3. **Client Availability:** The client (represented by the instructor / TA) is available for questions and demos for approximately 30 minutes once a week during lab sessions (`Case Brief`).
4. **Evolution of Requirements:** Features (club memberships, event booking, waiting lists, cancellation deadlines) will be discovered and refined progressively rather than remaining static (`lab04/process-comparison.md`).
5. **Technical Learning Curve:** The team is actively mastering modern C++20, CMake, GoogleTest, WCAG 2.2 accessibility/ANSI-safe CLI output, and Git branching workflows (`lab02/application-type.md`).

---

## 2. Options Considered

| Option | Weighted Score (Task 2) | Pros | Cons |
| :--- | :---: | :--- | :--- |
| **A. Waterfall** | 1.65 / 5.00 | Clear documentation; simple sequential milestones. | High risk if bugs or requirement flaws are found in Week 13; no working software until the end. |
| **B. Incremental Delivery** | 3.80 / 5.00 | Builds features slice-by-slice; allows early testing. | Lacks defined feedback rituals (retrospectives/reviews); assumes architecture is fixed early. |
| **C. Scrum-style Iterative** | **4.60 / 5.00** | Early working increments; embraces changing client needs; regular inspection and adaptation. | Needs strong team discipline; full textbook Scrum has too many meetings for part-time students. |
| **D. No Defined Process** | 0.00 / 5.00 | Maximum temporary freedom; zero documentation overhead. | Extreme panic, merge conflicts, missed deadlines, and guaranteed project failure. |

*(Note: Verify that the weighted scores above match your team's exact numbers from Task 2).*

---

## 3. Decision

We will adopt a **Tailored Scrum-Style Iterative Process** combined with a structured upfront specification and modeling phase.

Because textbook enterprise Scrum is designed for full-time industry teams, we customize (tailor) 6 key process elements to fit our university schedule and C++20 CLI project constraints:

### Process Tailoring Table

| Element | Reference Practice (Textbook Scrum) | Our Tailoring for ITC Club Hub | Reason for Tailoring |
| :--- | :--- | :--- | :--- |
| **1. Up-front Work** | Zero upfront architecture; emergent design from user stories. | **Structured Upfront Phase:** Weeks 5–6 for SRS/Backlog, Week 7 for UML models. | Required for Checkpoint 1 in Week 8 and academic course evaluation. |
| **2. Iteration Length** | 2 to 4 weeks flexible sprints. | **Strict Two-Week Sprints:** Sprint 1 (Weeks 9–10) and Sprint 2 (Weeks 11–12). | Fits the academic rhythm between Midterm (Week 8) and Hardening (Week 13). |
| **3. Team Meetings** | 15-minute daily standup in person every morning. | **One weekly in-person sync** during lab + asynchronous updates in Telegram chat. | Students have conflicting class schedules across weekdays. |
| **4. Team Roles** | Fixed Product Owner, Scrum Master, and Developers. | **Fixed Product Owner** (client liaison); **Rotating Scrum Master** (Sprint 1 vs Sprint 2). | Gives multiple students leadership experience while maintaining a single client point of contact. |
| **5. Documentation** | Working software over comprehensive documentation. | Lightweight Markdown and Mermaid artifacts kept inside repo (`docs/`, `lab04/`, etc.). | Project requires traceable artifacts for university grading. |
| **6. Definition of Done (DoD)** | Production-ready deployed software. | Code merged via PR to `main`, compiles cleanly with CMake, 100% tests pass in GoogleTest, ANSI-safe output verified, no raw PII in logs. | Tailored to C++20 CLI application testing and security criteria. |

---

## 4. Consequences

### Positive Consequences:
1. **Early Working Software:** By Week 10 (end of Sprint 1), we deliver a working, tested C++20 CLI increment to demonstrate to the client.
2. **Reduced Integration Risk:** Continuous feature-branch merging and automated GoogleTests prevent last-minute "merge hell."
3. **Client Alignment:** Bi-weekly sprint reviews allow our instructor/TA to catch requirement misunderstandings before final grading.

### Negative Consequences & Risks (with Mitigations):
1. **Risk: Student Procrastination ("Student Syndrome").**  
   *Mitigation:* The Scrum Master tracks weekly progress on GitHub Issues/Projects; tasks are broken down into small units (less than or equal to 4 hours each).
2. **Risk: Over-engineering Upfront.**  
   *Mitigation:* Keep UML models and SRS strictly focused on core business rules (event capacity, waiting list promotion, 24h cancellation).
3. **Risk: Meeting Fatigue.**  
   *Mitigation:* Limit weekly in-person syncs to 45 minutes; resolve daily blockers asynchronously via Telegram.

---

## 5. Process Diagram

The semester workflow from Weeks 5 to 14 is maintained in `process.mmd` and rendered below:

```mermaid
flowchart LR
    %% Custom Gray Theme Styling
    classDef phaseBox fill:#f4f4f5,stroke:#71717a,stroke-width:2px,color:#18181b
    classDef stepNode fill:#e4e4e7,stroke:#52525b,stroke-width:1.5px,color:#18181b
    classDef decisionNode fill:#d4d4d8,stroke:#3f3f46,stroke-width:2px,color:#09090b

    subgraph Phase1 ["Phase 1: Upfront Specification (Weeks 5–8)"]
        direction TB
        A["Requirements Elicitation & SRS<br/>(Weeks 5–6 · Product Owner)"]:::stepNode
        B["UML, GUI Wireframes & Architecture<br/>(Week 7 · Lead Developer)"]:::stepNode
        C["Midterm Exam & Checkpoint 1<br/>(Week 8 · Whole Team)"]:::stepNode
        A --> B --> C
    end

    subgraph Phase2 ["Phase 2: Iterative Sprint Cycles (Weeks 9–12)"]
        direction TB
        D["Sprint Planning<br/>(Sprint 1: Wk 9 / Sprint 2: Wk 11 · Rotating Scrum Master)"]:::stepNode
        E["GUI & Core Feature Implementation<br/>(Developers)"]:::stepNode
        F["CMake Build & GoogleTest CI<br/>(Scrum Master & Devs)"]:::stepNode
        G["Sprint Review, Demo & Retrospective<br/>(Product Owner, Team & Client)"]:::stepNode
        H{"Sprint 2<br/>Finished?"}:::decisionNode

        D --> E --> F --> G --> H
        H -- "No (End of Sprint 1)" --> D
        G -. "Client Feedback & Backlog Refinement" .-> D
    end

    subgraph Phase3 ["Phase 3: Release & Delivery (Weeks 13–14)"]
        direction TB
        I["Hardening, Bug Fixing & Docs Polish<br/>(Week 13 · Feature Freeze)"]:::stepNode
        J["Final Submission & Client Demo<br/>(Week 14 · Whole Team)"]:::stepNode
        I --> J
    end

    %% Connections between phases
    C --> D
    H -- "Yes" --> I

    %% Apply gray styling to the phase containers
    class Phase1,Phase2,Phase3 phaseBox
```
---

## 6. Approvals

Every team member has reviewed and approved this development process:

- **Sin Meynanon (Product Owner):** Approved (2026-11-22)
- **Ath Mengcheu (Scrum Master):** Approved (2026-11-22)
- **Soth MonyOudomy (Developer):** Approved (2026-11-22)
- **Ngoun Taymeng (Developer):** Approved (2026-11-22)
- **Tra Makhen (Developer):** Approved (2026-11-22)