# Ethics Case Analyses · ITC Club Hub

Version 1.0 · 2026-11-10 · Lead A = [Name]

---

## Scenario A: "Just a small report"

| Step | Analysis |
|------|----------|
| **1. Facts** | The Robotics Club leader requests a report showing which students attended events organized by other clubs. The purpose is to identify active students for recruitment. Although the report would only be accessible to club leaders, attendance records contain personal information. Students may have originally provided their information for event management rather than recruitment. We still need to investigate the privacy notice, students' permissions, the clubs office's data-sharing policy, the administrator's actual authorization, and the lawful basis for processing this information. |
| **2. Stakeholders and harms** | **Students:** Their attendance history could be exposed or reused without their knowledge, violating their privacy and damaging their trust. **Robotics Club leader:** Could face complaints or disciplinary consequences for requesting unauthorized data access. **Other club leaders:** May receive information they are not authorized to access. **Development team:** Could damage its professional reputation by implementing inappropriate data access. **Clubs office:** Could lose students' trust and become responsible for inappropriate information sharing. |
| **3. Codes, law, policy** | **Software Engineering Code of Ethics, Principle 1 (Public):** Software engineers shall act consistently with the public interest. **ACM Code 1.6 (Respect Privacy):** Computing professionals should respect individuals' privacy and protect personal information from unauthorized access and disclosure. **GDPR Article 5(1)(a):** Personal data must be processed lawfully, fairly, and transparently. **GDPR Article 5(1)(b):** Personal data must be collected for specified and legitimate purposes and not reused for incompatible purposes. These principles indicate that attendance information should not automatically be reused for recruitment without proper authorization and transparency. |
| **4. Options** | **(a)** Implement the requested report immediately because the club leader claims the administrator will approve. **(b)** Reject the request completely and refuse to provide any attendance information. **(c)** Suspend the request until the clubs office verifies authorization, the purpose, and applicable privacy requirements. **(d)** Offer an alternative recruitment method using voluntary participation, such as an opt-in recruitment form or anonymous attendance statistics. |
| **5. Tests** | **(a) Immediate implementation:** Harm test: Fails because students could lose control over their personal information. Rights test: Fails because students may not have been informed about this secondary use. Fairness test: Fails because students could be targeted without their knowledge. Publicity test: Fails because students and administrators may consider the data sharing inappropriate. **(b) Complete rejection:** Harm test: Passes because it prevents unauthorized disclosure. Rights test: Passes because student privacy is protected. Fairness test: Passes, although it may unnecessarily restrict legitimate recruitment. Publicity test: Passes because the decision can be openly explained. **(c) Suspend pending authorization:** Harm test: Passes because disclosure is prevented until approval. Rights test: Passes because authorization and privacy requirements are checked. Fairness test: Passes because the same requirements apply to everyone. Publicity test: Passes because the decision is transparent. **(d) Voluntary or anonymous alternative:** Harm test: Passes because privacy risks are minimized. Rights test: Passes because students retain control over participation. Fairness test: Passes because participation is voluntary. Publicity test: Passes because the method is transparent and defensible. |
| **6. Decision and action** | Choose **(c) and (d)**. Do not implement the report until the clubs office confirms authorization, the original purpose of data collection, and the applicable privacy requirements. Meanwhile, propose an opt-in recruitment form or anonymous statistics. The development team must not rely solely on the club leader's personal relationship with the administrator as evidence of authorization. Document the decision and require proper approval before cross-club attendance information becomes accessible. |
| **7. Reflection** | This situation demonstrates that having technical access to information does not mean having ethical permission to use it. Even a report intended to support recruitment can violate privacy if students are unaware of how their information is being reused. We learned that developers must question requests involving personal information, verify authorization, and prioritize users' rights over convenience or informal promises. |

**Message to the club leader:**

Thank you for suggesting this recruitment report. However, attendance records contain students' personal information, and we cannot reuse or share them for recruitment without confirming proper authorization and informing students about the purpose. We will first consult the clubs office to verify the applicable data-sharing policy and permissions. In the meantime, we suggest an opt-in recruitment form or anonymous attendance statistics as safer alternatives. We want to support recruitment while protecting students' privacy and maintaining their trust.

**Preventive engineering change:**

Implement Role-Based Access Control (RBAC) for attendance reports.

Requirements:

1. Club leaders can only access attendance records belonging to their own clubs.
2. Cross-club attendance reports require administrative authorization.
3. Every report access attempt must be recorded in an audit log.
4. Unauthorized access attempts must receive an access-denied response.
5. Access permissions must be verified on the server side.

**GitHub issue:** #5 (Label: ethics)

---
