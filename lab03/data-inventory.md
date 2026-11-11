# Data inventory · ITC Club Hub
Version 0.1 · 2026-11-06 · Authors: <CounterBlock>

| Field | Subject | Purpose | Legal basis / consent | Retention | Who can see it | Stored in | Decision |
|-------|---------|---------|-----------------------|-----------|----------------|-----------|----------|
| studentId | student | identify; block double registration | necessary for the service | while account is active,delete after account closure and required retention period | student and authorized administrator | data/students.csv | Mask for organisers: because they don't need the full ID |
| name | student | TODO | TODO | TODO | TODO | TODO | TODO |
| phone | student | TODO | consent (opt-in) | TODO | TODO | TODO | TODO |
| attendance | student | TODO | legitimate interest: TODO why | TODO | TODO | data/registrations.csv | TODO |
| dateOfBirth | student | TODO: is there any? | TODO | TODO | TODO | TODO | TODO |

## Copies of personal data
| Copy | Rule |
|------|------|
| log files | only `redacted()` output, never name, email or phone |
| CSV exports | TODO |
| test fixtures | TODO |
| backups | TODO |
| screenshots in docs | TODO |

## Lifecycle of the phone field
```mermaid
flowchart LR
  C["Collect<br/>student give phone<br/>with consent"]
  S["Store<br/>secure database<br/>restricted acess"]
  U["Use<br/>send club updates"]
  R["Receive<br/>check consent<br/>and necesity]
  D["Delet<br/>remove phone number<br/>when no longer needed"]

  C --> S --> U --> R --> D
```

## Client feedback
- TODO