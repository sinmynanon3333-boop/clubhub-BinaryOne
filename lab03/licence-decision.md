# Licence decision: ITC Club Hub

## 1. Course requirement

Checked with the teaching assistant on `2026-11-10`: the course **does not** require a particular licence.

Hello, our team (ITC Club Hub) is working on Lab-03 task 3, the licence decision. Does the course or the institute require a particular licence for our repository? If not, are MIT, Apache-2.0 and GPL-3.0 all acceptable choices? Thank you.

## 2. License Comparision Table

Licences compared: MIT, Apache-2.0, GPL-3.0.

| Criterion | MIT | Apache-2.0 | GPL-3.0 |
|---|---|---|---|
| Who may reuse our code | Anyone, for any purpose including closed-source products, as long as the copyright and licence notice are kept | Anyone, for any purpose, as long as the notice is kept, changes are stated and any NOTICE file is carried along | Anyone, but any distributed work built on our code must also be released under GPL-3.0 |
| Whether improvements must be shared back | No | No | Yes, when the modified code is distributed (source must be made available) |
| Patent protection | No express patent grant | Express patent grant from contributors; it ends if the user starts a patent lawsuit over the code | Express patent grant from contributors |
| Compatibility with our dependencies | GoogleTest (BSD-3-Clause, tests only, not shipped) is compatible. Other dependencies: `<list from CMakeLists.txt>` | GoogleTest is compatible. Other dependencies | GoogleTest is compatible. Other dependencies: `<list>` |
| Simplicity for future student teams | Very simple: a short text with one main condition (keep the notice) | Moderate: longer text, with notice and change-tracking duties | Hardest: long text, and copyleft duties that later teams must understand before reusing the code |
| Requirement of the institute | Highly Recommended | Acceptable | Restrictive |

## 3. Decision

**Chosen licence:** `<MIT / Apache-2.0 / GPL-3.0>`

**Rationale:**

ITC Club Hub is an educational university project created by students. The MIT Licence provides the lowest barrier to adoption: it is short, universally understood, and allows future ITC cohorts and student clubs to study, reuse, and extend our codebase without complex legal restrictions. It is fully compatible with our test dependency, GoogleTest (BSD-3-Clause), and gives our team clear permission to showcase this project in personal portfolios.

## 4. Member agreement

Each member owns the copyright of their own contributions, so the licence needs everyone's consent.

| Member | Role | I agree to license my contributions under the licence above | Date |
|---|---|---|---|
| Sin Meynanon | Product Owner | Yes | `2026-11-10` |
| Ath Mengcheu | Scrum Master | Yes | `2026-11-10` |
| Soth MonyOudom | Developer | Yes | `2026-11-10` |
| Ngoun Taymeng | Admin | Yes | `2026-11-10` |
| Tra Makhen | Designer | Yes | `2026-11-10` |
