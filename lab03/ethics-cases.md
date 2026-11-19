# Ethics Case Analyses · ITC Club Hub

Version 1.0 · 2026-11-10 · Lead A = Soth Mony Oudam · Lead B = Soth Mony Oudam

---

## Scenario A: "Just a small report"

| Step | Analysis |
|------|----------|
| **1. Facts** | The Robotics Club leader requests a report showing which students attended events organized by other clubs. The purpose is to identify active students for recruitment. Although the report would only be accessible to club leaders, attendance records contain students' personal information. Students may have originally provided their information for event registration and attendance tracking rather than recruitment by other clubs. Before proceeding, the team needs to investigate the existing privacy notice, students' permissions, the clubs office's data-sharing policy, the administrator's actual authorization, and the applicable lawful basis for processing this information. |
| **2. Stakeholders and harms** | **Students:** Their attendance history could be exposed or reused without their knowledge, compromising their privacy and damaging their trust in Club Hub. **Robotics Club leader:** Could face complaints or disciplinary consequences for requesting unauthorized access to personal information. **Other club leaders:** May receive information they are not authorized to access, creating potential privacy concerns. **Development team:** Could damage its professional reputation by implementing inappropriate data-sharing functionality. **Clubs office:** Could lose students' trust and face responsibility for inappropriate information sharing. |
| **3. Codes, law, policy** | **Software Engineering Code of Ethics, Principle 1 (Public):** Software engineers shall act consistently with the public interest. **ACM Code 1.6 (Respect Privacy):** Computing professionals should respect individuals' privacy and protect personal information from unauthorized access and disclosure. **GDPR Article 5(1)(a) (Lawfulness, fairness and transparency):** Personal data must be processed lawfully, fairly, and transparently. **GDPR Article 5(1)(b) (Purpose limitation):** Personal data must be collected for specified, explicit, and legitimate purposes and not further processed in a manner incompatible with those purposes. These principles demonstrate that attendance information should not automatically be reused for recruitment without appropriate authorization, transparency, and consideration of students' rights. |
| **4. Options** | **(a)** Implement the requested report immediately because the club leader claims the administrator will approve. **(b)** Reject the request completely and refuse to provide any attendance information. **(c)** Suspend the request until the clubs office verifies the authorization, intended purpose, and applicable privacy requirements. **(d)** Offer alternative recruitment methods based on voluntary participation, such as an opt-in recruitment form or anonymous attendance statistics. |
| **5. Tests** | **(a) Immediate implementation:** Harm test: Fails because students could lose control over their personal information. Rights test: Fails because students may not have been informed about this secondary use. Fairness test: Fails because students could be targeted without their knowledge or agreement. Publicity test: Fails because students and administrators may consider the data sharing inappropriate if publicly disclosed. **(b) Complete rejection:** Harm test: Passes because it prevents unauthorized disclosure. Rights test: Passes because student privacy is protected. Fairness test: Passes, although it may unnecessarily restrict legitimate recruitment activities. Publicity test: Passes because the decision can be openly explained. **(c) Suspend pending authorization:** Harm test: Passes because disclosure is prevented until proper authorization is verified. Rights test: Passes because privacy requirements and the original purpose of data collection are examined. Fairness test: Passes because the same approval requirements apply to everyone. Publicity test: Passes because the decision is transparent and professionally defensible. **(d) Voluntary or anonymous alternative:** Harm test: Passes because privacy risks are minimized. Rights test: Passes because students retain control over participation. Fairness test: Passes because recruitment participation is voluntary. Publicity test: Passes because the method is transparent and can be publicly justified. |
| **6. Decision and action** | Choose **(c) and (d)**. Do not implement the requested report until the clubs office confirms the authorization, original purpose of data collection, and applicable privacy requirements. Meanwhile, propose an opt-in recruitment form or anonymous attendance statistics. The development team must not rely solely on the club leader's personal relationship with the administrator as evidence of authorization. Document the decision and require appropriate approval before cross-club attendance information becomes accessible. |
| **7. Reflection** | This situation demonstrates that having technical access to information does not mean having ethical permission to use it. Even a report intended to support recruitment can violate privacy if students are unaware of how their information is being reused. We learned that software developers must question requests involving personal information, verify authorization, and prioritize users' privacy rights over convenience or informal promises. Ethical software development requires protecting individuals even when a requested feature appears harmless or beneficial. |

**Message to the club leader:**

Thank you for suggesting this recruitment report. However, attendance records contain students' personal information, and we cannot reuse or share them for recruitment without confirming proper authorization and informing students about the purpose. We will first consult the clubs office to verify the applicable data-sharing policy and permissions. In the meantime, we suggest an opt-in recruitment form or anonymous attendance statistics as safer alternatives. We want to support recruitment while protecting students' privacy and maintaining their trust.

**Preventive engineering change:**

Implement Role-Based Access Control (RBAC) for attendance reports to ensure that users can only access information they are authorized to view.

Requirements:

1. Club leaders can only access attendance records belonging to their own clubs.
2. Cross-club attendance reports require explicit administrative authorization.
3. Every report access attempt must be recorded in an audit log.
4. Unauthorized access attempts must receive an access-denied response.
5. Access permissions must be verified on the server side rather than relying only on the user interface.
6. Access permissions must follow the principle of least privilege, granting users only the minimum access necessary to perform their responsibilities.

**GitHub issue:** [#5 - Implement role-based access control for cross-club attendance reports](https://github.com/sinmynanon3333-boop/clubhub-BinaryOne/issues/5) (Label: ethics)

---

## Scenario B: "Don't mention it in the demo"

| Step | Analysis |
|------|----------|
| **1. Facts** | Two days before the Sprint 1 review, a developer discovers two defects: cancellations made inside the 24-hour window are incorrectly accepted, and the monthly attendance report counts cancelled registrations as attendance. The Scrum Master asks the developer to hide these problems during the client demonstration and postpone fixing them until Sprint 2. Before deciding how to proceed, the team needs to investigate the affected code, identify the root causes, determine how many registrations and reports are affected, assess the severity of the defects, and estimate whether safe fixes and regression tests can be completed before the review. |
| **2. Stakeholders and harms** | **Students:** May experience incorrect cancellation results and inaccurate attendance records. **Club leaders:** May make decisions using incorrect monthly attendance reports. **Client/Product Owner:** May misunderstand the actual system capabilities and make decisions based on misleading information. **Developer:** May face pressure to compromise professional integrity and conceal known defects. **Scrum Master:** Risks damaging the client's trust by encouraging the concealment of software problems. **Development team:** Could lose credibility, create technical debt, and face additional maintenance costs if defects remain unresolved. |
| **3. Codes, law, policy** | **Software Engineering Code of Ethics, Principle 3 (Product):** Software engineers shall ensure that their products and modifications meet the highest professional standards possible. **Software Engineering Code 6.12:** Engineers should express concerns to the people involved when significant violations are detected. **ACM Code 1.3 (Be Honest and Trustworthy):** Computing professionals should be honest and trustworthy, providing accurate information about system capabilities, limitations, and potential problems. These principles establish that developers have a professional responsibility to communicate known defects honestly rather than deliberately conceal them from the client. |
| **4. Options** | **(a)** Stay silent as requested and demonstrate the system as if everything works correctly. **(b)** Postpone the entire Sprint 1 review until both defects are fixed. **(c)** Continue with the planned demonstration but disclose both defects in a clearly identified "Known Issues" section, including their impact and planned correction date. **(d)** Attempt to fix both defects within the remaining two days, add regression tests, and remove another lower-priority demonstration item if necessary. |
| **5. Tests** | **(a) Stay silent:** Harm test: Fails because students and club leaders may continue relying on incorrect results. Rights test: Fails because the client is denied accurate information needed to evaluate the product. Fairness test: Fails because the client is misled about the actual system quality. Publicity test: Fails because the team would appear dishonest if the defects were discovered later. **(b) Postpone the entire review:** Harm test: Passes because it avoids presenting misleading functionality, but may unnecessarily delay feedback. Rights test: Passes because the client is not misled. Fairness test: Depends on whether postponement is justified by the severity of the defects and communicated consistently. Publicity test: Passes if the reason for postponement is communicated honestly. **(c) Disclose known issues:** Harm test: Passes because stakeholders are warned about the defects and can avoid relying on incorrect results. Rights test: Passes because the client receives accurate information about system limitations. Fairness test: Passes because the client can make informed decisions. Publicity test: Passes because the team can openly explain and justify its decision. **(d) Fix and test before the review:** Harm test: Passes if the defects are corrected and properly verified. Rights test: Passes because the team provides more reliable functionality and accurate information. Fairness test: Passes because the client receives a properly tested product. Publicity test: Passes if the team can demonstrate successful tests and honestly disclose any remaining limitations. However, rushing the fixes could introduce additional defects, so adequate testing and code review are necessary. |
| **6. Decision and action** | Choose **(c) as the minimum requirement**, with **(d) as an additional action if testing confirms that the fixes are safe**. The developer should first raise the concern with the Scrum Master, following Software Engineering Code 6.12. The Product Owner must also be informed, and both defects must be included in the review agenda. The team should demonstrate only verified functionality, clearly disclose unresolved defects, and provide a realistic correction schedule. Neither defect should be hidden to create a misleading impression of product quality. |
| **7. Reflection** | This situation demonstrates that professional responsibility is more important than making a demonstration appear successful. Hiding known defects may temporarily protect the team's image, but it can damage client trust, mislead stakeholders, and cause further problems for users. We learned that transparency, proper testing, and early communication are essential responsibilities in software engineering. A successful demonstration should represent the actual condition of the software, including its limitations and known defects. |

**Message to the Scrum Master and Product Owner:**

We have identified two defects before the Sprint 1 review: cancellations within 24 hours are incorrectly accepted, and cancelled registrations are included in monthly attendance reports. We should not conceal these issues because they affect system reliability and client trust. We propose documenting both defects in the Known Issues section and explaining their impact during the review. The development team will investigate and attempt to fix them with regression tests before the review, provided there is sufficient time for proper verification. Any unresolved issue will have a clear correction schedule for Sprint 2.

**Preventive engineering change:**

Add automated regression tests for the 24-hour cancellation rule and monthly attendance calculations to prevent these defects from recurring.

Requirements:

1. Cancellations inside the prohibited 24-hour window must be rejected.
2. Cancellations outside the prohibited window must follow the approved cancellation policy.
3. Cancelled registrations must be excluded from attendance totals.
4. Monthly reports must count only valid attended registrations.
5. Boundary cases around the 24-hour cancellation limit must be tested.
6. All regression tests must pass before changes are merged into the main branch.

**GitHub issue:** [#6 - Add regression tests for cancellation rules and attendance reports](https://github.com/sinmynanon3333-boop/clubhub-BinaryOne/issues/6) (Label: ethics)

---

## References

1. IEEE-CS/ACM Joint Task Force. Software Engineering Code of Ethics and Professional Practice. Principle 1 (Public), Principle 3 (Product), and Clause 6.12.
2. Association for Computing Machinery (ACM). ACM Code of Ethics and Professional Conduct. Items 1.3 (Be Honest and Trustworthy) and 1.6 (Respect Privacy).
3. European Union. General Data Protection Regulation (GDPR). Article 5(1)(a) (Lawfulness, fairness and transparency) and Article 5(1)(b) (Purpose limitation).

**Note:** GDPR principles are used as an ethical privacy benchmark. Their legal applicability to ITC Club Hub has not been established.