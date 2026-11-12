# Retention and Purge Rules · ITC Club Hub Version 1.0 · 2026-10-26

| Field | Trigger | Action | Who / What Runs It | How to Verify |
|---|---|---|---|---|
| `studentId`, `name`, `email` | Graduation or departure + 6 months | **Delete** account and record from `students.csv` | Automated yearly cron script (`purge_graduates.py`) run by IT Admin | Query database: verify graduated cohort IDs return no records |
| `phone` | Student unchecks "SMS Alerts" box in profile | **Delete immediately**; field set to null | Web API endpoint / C++ `withdrawSmsConsent()` | Check student record: `phone` field is empty (`null`/empty string) |
| `clubMemberships` | Student leaves club or club dissolves | **Delete** membership record from `memberships.csv` | Club Leader or Admin | Check club roster: student ID no longer appears |
| `attendance` | 1 year after event conclusion | **Aggregate & Anonymise**: convert to count (e.g., "54 attendees"), purge student IDs | End-of-year maintenance script run by Admin | `registrations.csv` has individual rows removed; summary table holds counts |