# Lab-02. Types of Applications & Architecture (v1.0, 2026-10-28)

# Files of this Lab
| File | Task | Author(s) |
| :--- | :---: | :--- |
| `lab02/offline-checkin.md`, `README.md` | Task 1 | Srum Master |
| `lab02/app-classification.md`, `lab02/app-quadrant.md` | Task 2 | Admin |
| `lab02/quality-scenarios.md`, `lab02/context-diagram` | Task 3 | Developer |
| `lab02/adr-001-application.md`, `lab02/architectures.md` | Task 4 | Designer | 
| `src/cli/main.cpp`, `CMakeLists.txt`, `data/events.csv` | Task 5 | Product Owner |
| `include/clubhub/event*.hpp`, `src/event*.cpp` | Task 5 | Product Owner | 

# Inputs Reused from Lab-01
* Problem statement & Stakeholder list from `lab01/team-charter.md`
* Decision rules from `lab01/decision.md`

# Architecture Diagram 
```mermaid
flowchart LR

    Student([Student])
    Leader([Club Leader])
    Organiser([Event Organiser])
    Admin([Administrator])

    ClubHub[ITC Club Hub]

    Email[[E-mail Service]]
    Directory[[ITC Student Directory]]

    Student -->|Browse events, register and cancel registration| ClubHub
    ClubHub -->|Event list and registration status| Student

    Leader -->|Create events and update event details| ClubHub
    ClubHub -->|Event information and registration lists| Leader

    Organiser -->|QR code scans and attendance records| ClubHub
    ClubHub -->|Check-in status and attendance lists| Organiser

    Admin -->|User management and monthly report requests| ClubHub
    ClubHub -->|User information and monthly reports| Admin

    ClubHub -->|Confirmation and reminder requests| Email
    Email -->|Confirmation and reminder emails| Student
    Email -->|Email delivery status| ClubHub

    ClubHub -->|Student ID lookup request| Directory
    Directory -->|Verified student name and email| ClubHub