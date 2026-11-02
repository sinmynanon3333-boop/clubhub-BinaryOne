# Lab 02 – ITC Club Hub Context Diagram

**Author:** Soth Mony Oudam  
**Version:** 1.0  
**Date:** 2026-11-03

## 1. Context Diagram

The context diagram illustrates ITC Club Hub as a single system and shows how its four main user roles and two external systems interact with it.

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
