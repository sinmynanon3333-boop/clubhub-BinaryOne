# V-Model Traceability · Requirement REQ-12 · Team I2-ISE
Version 1.0 · 2026-11-04 · Bonus Challenge

---

## 1. Requirement Definition

- **Requirement ID:** `REQ-12`
- **Title:** Event Registration Cancellation Deadline
- **Statement:** A student who is registered for an event may cancel their registration at any time up to **strictly 24 hours before the event start time**. If the cancellation request is received less than 24 hours before the start, the system shall reject the request and retain the registration status as `Registered`. When a valid cancellation occurs, the registration status becomes `Cancelled` and the event's available capacity increases by 1 seat.

---

## 2. Four-Level V-Model Traceability Matrix

The V-Model connects each left-side design phase to its corresponding right-side testing phase:

| V-Level | Left Side: Design Element | Right Side: Test Level & Artifact | Concrete Boundary Test Values |
| :--- | :--- | :--- | :--- |
| **Level 1: System / Acceptance** | User Story `US-12`: Student self-service cancellation via CLI or Mobile web. | **Acceptance Test `AT-12`:** Gherkin BDD scenarios executed by Product Owner with client. | Event starts `2026-11-07 14:00`. Test A: cancel at `2026-11-06 14:00:00` (Pass). Test B: cancel at `2026-11-06 14:00:01` (Fail). |
| **Level 2: System / Architecture** | 3-Tier Architecture (`lab02`): CLI calls `RegistrationService::cancel(regId)`. | **System / Integration Test `IT-12`:** Integration test verifying CSV updates and seat count recalculation. | Initial capacity: 25. Registered: 25. Cancel accepted &rarr; Available becomes 1. Cancel rejected &rarr; Available remains 0. |
| **Level 3: Component / Subsystem** | `RegistrationService` domain component coordinates `EventRepository` and business rules. | **Subsystem Test `ST-12`:** Service test verifying that cancelled registrations update `RegistrationStatus::Cancelled`. | Verify return status: `true` when $\Delta t \ge 24\text{h}$; `false` with error message when $\Delta t < 24\text{h}$. |
| **Level 4: Unit / Module** | Pure C++20 function: `clubhub::canCancel(now, start)` in `include/clubhub/CancellationPolicy.hpp`. | **Unit Test `UT-12`:** GoogleTest suite `tests/cancellation_rule_test.cpp`. | • Boundary 1: `start - 24h` &rarr; `true`<br>• Boundary 2: `start - 24h + 1s` &rarr; `false`<br>• Boundary 3: `start - 7d` &rarr; `true`<br>• Boundary 4: `start + 1h` &rarr; `false` |

---

## 3. Gherkin Acceptance Scenarios (BDD)

```gherkin
Feature: Cancel an Event Registration (REQ-12, Acceptance Test AT-12)

  Background:
    Given the event "Robotics Workshop" starts on 2026-11-07 at 14:00
    And student "S001" is registered for "Robotics Workshop" with status "Registered"
    And the current event available seats is 0

  Scenario: Cancellation exactly 24 hours before the start is allowed
    Given the current time is 2026-11-06 14:00:00
    When student "S001" cancels their registration
    Then the registration status becomes "Cancelled"
    And the event available seats becomes 1
    And the student receives a cancellation confirmation

  Scenario: Cancellation less than 24 hours before the start is rejected
    Given the current time is 2026-11-06 14:00:01
    When student "S001" cancels their registration
    Then the cancellation is rejected with message "Cancellation closed: must cancel at least 24 hours before start"
    And the registration status remains "Registered"
    And the event available seats remains 0

  Scenario: Cancellation after the event has started is rejected
    Given the current time is 2026-11-07 14:30:00
    When student "S001" cancels their registration
    Then the cancellation is rejected with message "Cannot cancel an event that has already started"
    And the registration status remains "Registered"
```