
# Decision Log · BinaryOne (v0.1, 2026-10-21)

This document tracks all architectural, organizational, and technical decisions made by Team **CouterBlock** for the ITC Club Hub project throughout the semester.

## Decision History

| # | Date | Decision | Decided By | Alternatives Considered | Rationale |
|---|------|----------|------------|-------------------------|-----------|
| 1 | 2026-10-21 | **Team Name:** Selected "BinaryOne" as the official team identity and repository suffix (`clubhub-BinaryOne`). | Consensus (all 5 members) | 1. "CouterBlock" 2. "Larpathon"  | One name shared by the GitHub repository and every lab document avoids confusion for the instructor and the client. |
| 2 | 2026-10-21 | **Team roles:**<br>• Product Owner: Sin Meynanon<br>• Scrum Master: Ath Mengcheu<br>• Developer: Soth MonyOudom<br>• Admin: Ngoun Taymeng<br>• Designer: Tra Makhen | Anonymous Vote(4-1) | 1. Rotating the Product Owner every sprint  | A fixed Product Owner gives the client one stable contact (see #2). [Add why each person fits their role.] |
| 3 | 2026-10-21 | **Client communication model:** only the Product Owner (Meynanon) talks to the client (model b). | Everyone | 1. Every member talks to the client (model a, 15 paths) | Cuts communication paths from 15 to 11, so overhead drops from 5.00 h to 3.67 h/week (33.3 % to 24.4 % of team capacity). |
| 4 | 2026-10-21 | **Task tracking:** GitHub Issues and the project board are the single source of truth. The Product Owner turns every client request into an Issue with one assignee. | Soth Monyoudom(DEV) | 1. Tracking tasks only in chat | Status and ownership are read from the board instead of asked, so cost per member path drops from 20 to 10 min and overhead from 3.67 h to 2.00 h/week. |
| 5 | 2026-10-21 | **Meeting rhythm:** 20-minute stand-up on Mon, Wed and Fri, run by the Scrum Master (Mengcheu). | Team vote(4-1) | 1. No regular meeting, only ad-hoc chats | One shared meeting replaces most one-to-one status chats, so overhead drops from 3.67 h to 1.67 h/week. |
| 6 | 2026-21-10 | **Sixth member in week 11:** decline the offer. | Team members | 1. Accept the sixth member | Brooks's law: paths rise from 11 to 16 and overhead from 3.67 h to 5.33 h/week (24.4 % to 29.6 %), before onboarding time. |

