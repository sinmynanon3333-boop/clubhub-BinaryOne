# Lab-02 · Quality Attribute Scenarios for ITC Club Hub

Version 1.0 · 2026-11-02 · Reviewed by (Scrum Master): Pending

## QAS-01 · Availability

| Part | Content |
|---|---|
| Source | Students, club leaders and organisers accessing Club Hub. |
| Stimulus | Many students attempt to access the application when event registration opens. |
| Environment | Friday at 18:00, during the event registration period. |
| Artifact | Club Hub application, RegistrationService and event data storage. |
| Response | The system remains available and allows users to browse events, register and manage event information. If a temporary failure occurs, the system recovers without losing confirmed registrations. |
| Response measure | Maintain at least 99.5% monthly availability. For a 30-day month: 720 hours × 0.5% = 3.6 hours maximum downtime. |

## QAS-02 · Performance at Check-in

| Part | Content |
|---|---|
| Source | An event organiser checking students into an event. |
| Stimulus | The organiser scans a student's QR code or enters their registration information. |
| Environment | Friday at 18:00, with 200 students arriving within 10 minutes. Organisers may experience weak 3G or congested Wi-Fi. |
| Artifact | RegistrationService and the check-in function. |
| Response | The system verifies the student's registration and records attendance without significantly delaying the queue. When internet connectivity is unavailable, check-in records are stored locally for later synchronization. |
| Response measure | At least 95% of online check-in requests complete within 2 seconds. All 200 arrivals must be processed within 10 minutes, and queued offline records must synchronize within 60 seconds after connectivity returns. |

## QAS-03 · Usability

| Part | Content |
|---|---|
| Source | A student using Club Hub for the first time. |
| Stimulus | The student attempts to find an event and complete registration without assistance. |
| Environment | Friday at 18:00, using an Android or iPhone smartphone over a mobile 4G/LTE network or campus Wi-Fi. |
| Artifact | Club Hub's future PWA presentation layer and registration workflow. |
| Response | The interface provides clear navigation, understandable instructions and a confirmation message after successful registration. |
| Response measure | At least 90% of first-time test users complete registration within 60 seconds, using no more than 4 taps after opening the event page. |

## QAS-04 · Security

| Part | Content |
|---|---|
| Source | An unauthorized user attempting to access another student's personal information by guessing an organiser account or manipulating a request. |
| Stimulus | The user attempts to retrieve student registration details or attendance records without permission. |
| Environment | Normal operation on Friday at 18:00 while student registration and attendance records are being accessed. |
| Artifact | Authentication, authorization, RegistrationService and student records. |
| Response | The system rejects unauthorized requests, prevents access to protected information and records security events for review. |
| Response measure | 100% of unauthorized access attempts in the security test must be denied, with 0 successful unauthorized disclosures of student names, student IDs, email addresses, phone numbers or attendance records. |

## QAS-05 · Modifiability

| Part | Content |
|---|---|
| Source | A developer on the project team. |
| Stimulus | Adds a waiting-list feature so that new registrations for a full event receive the status `Waitlisted`. |
| Environment | Design time, after Sprint 1, when the core registration functionality has already been tested. |
| Artifact | `RegistrationService` and `Registration` in `include/clubhub/` and `src/`. |
| Response | The new business rule is implemented in the C++ core logic. The CLI only needs to display the new status, and existing registration behaviour remains unchanged. |
| Response measure | Complete within 2 person-days; modify no more than 4 files under `include/` and `src/`; make 0 changes in `src/cli/` other than display-related changes; and ensure all existing tests pass. |

## QAS-06 · Portability

| Part | Content |
|---|---|
| Source | Students, organisers and administrators accessing Club Hub from different devices. |
| Stimulus | Users open Club Hub using smartphones, tablets or desktop computers. |
| Environment | Students use Android or iPhone smartphones. Organisers use smartphones or tablets at event entrances, where Wi-Fi may be unreliable or unavailable. Administrators use Windows desktop PCs on the campus LAN. |
| Artifact | Club Hub's future Progressive Web App (PWA), responsive web interface and offline check-in functionality. |
| Response | The PWA provides a usable interface across supported devices. Organisers can access cached event rosters and record check-ins offline. Queued attendance records synchronize when connectivity returns. |
| Response measure | 100% of agreed Android, iPhone, tablet and Windows desktop test configurations must pass the applicable event browsing and registration tests. All 200 simulated offline check-ins must be queued successfully and synchronized within 60 seconds after connectivity returns. |

## Priorities

| Scenario | Business importance | Technical risk | Protects | First? |
|---|---|---|---|---|
| QAS-01 Availability | H | M | Students, club leaders and organisers | Yes |
| QAS-02 Performance | H | H | Organisers and students | Yes |
| QAS-03 Usability | M | M | Students and club leaders | No |
| QAS-04 Security | H | H | Students and administrators | No |
| QAS-05 Modifiability | M | M | Developers and maintainers | No |
| QAS-06 Portability | M | M | Students, organisers and administrators | No |

### Architecture Priorities

QAS-01 Availability and QAS-02 Performance are selected as the first two architecture priorities because Club Hub must remain accessible during registration and process student check-ins efficiently during busy events.

Security remains a high business priority and must also be addressed in the architecture.

### Review

Scrum Master review: Pending.
