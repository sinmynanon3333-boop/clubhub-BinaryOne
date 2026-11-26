# Fundamental activities · Team BinaryOne · v1.0 (2026-11-13)

| Activity | What happens in Club Hub | Who leads (role, name) | Weeks | Artifact | Done when |
|---|---|---|---|---|---|
| Specification | Elicit requirements from students, club leaders and administrators. Define user stories for event registration, cancellation, attendance reports and consent. Specify the 24-hour cancellation rule, event capacity and privacy requirements. | Product Owner, Sin Meynanon | 5–6 | lab05/srs.md, user stories | Requirements are documented, reviewed and approved by the Product Owner and client. |
| Design and implementation | Design the PWA and responsive interfaces for students, organisers and administrators. Implement registration, cancellation, attendance tracking and role-based access control. Develop classes such as Student, Event and Registration. | Technical Lead/Developer, Soth Monyoudam | 6-8 | src/, include/, design diagrams, ADRs | Required Must-have features are implemented, reviewed and successfully built. |
| Validation | Test event capacity, duplicate registrations, the 24-hour cancellation rule and attendance calculations using GoogleTest. Conduct peer reviews and demonstrate the CLI or application during sprint reviews. | Test Lead, Tra Makhen | 8-9 | tests/, CI run history, lab09/review-notes.md | All Must-have stories have passing tests in CI and the TA accepts the work at the review. |
| Evolution | Collect feedback from sprint reviews and users. Fix reported defects, update requirements and improve existing features such as consent, accessibility and attendance reporting. | Product Owner, Sin Meynanon | 9 | CHANGELOG.md, GitHub Issues, updated user stories | Feedback and defects are recorded, prioritized and addressed in the product backlog. |

## Sub-activities and ISO/IEC/IEEE 12207 processes

- Specification: Elicitation, analysis, specification and validation of requirements.  
  12207: Stakeholder Needs and Requirements Definition; System Requirements Analysis.

- Design and implementation: Architectural design, detailed design, coding and integration.  
  12207: Architecture Definition; Design Definition; Implementation; Integration.

- Validation: Test planning, test execution, defect reporting and acceptance testing.  
  12207: Verification; Validation.

- Evolution: Change requests, impact analysis, maintenance and continuous improvement.  
  12207: Maintenance; Configuration Management.

## Overlaps and loops

1. Week 10 – Sprint 1 review: Feedback from the client may reveal missing requirements, such as displaying the number of seats remaining for an event. The Product Owner creates a new user story, which returns to specification and is prioritized for a future sprint.

2. Weeks 9–14 – Design and validation: Implementation and testing happen together. Each pull request contains code and relevant tests. Review feedback may require changes to the design or implementation before merging.

3. After each sprint review: Client feedback and discovered defects return to the product backlog. The Product Owner prioritizes the changes, leading to another cycle of specification, design, implementation and validation.