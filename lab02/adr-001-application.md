# ADR-001 · Application Types for ITC Club Hub
Version 1.0 · 2026-10-18 · Status: Accepted (2026-10-18) · Deciders: Chan Dara (PO), Sokha Pich (SM), Team

## 1. User Groups & Constraints
| Group | Device (what they use?) | Where Used (where do they use?) | Connectivity (Do they have reliable internet?) | How Often | Must Never Fail (What is the most important function?)|
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Students**  | Android / iPhone | Campus, home, commuting | Mobile 4G/LTE, campus Wi-Fi | 2–3 times/week | Event registration must be saved correctly |
| **Organisers**  | Smartphones, tablets | Event Entrance | Flaky / congested Wi-Fi, weak 3G | During Events | Fast QR scan check-in at the door with zero lost tickets. |
| **Administrators**  | Desktop PCs (Windows) | Student Affairs Office | Fast wired campus LAN | Monthly| User and event records must remain accurate |

## 2. Options Considered (Compare the application type to build)
* **Option A: Native Apps (Kotlin for Android + Swift for iOS) + Web Admin:** High development cost; requires two separate mobile codebases and developer accounts.
* **Option B: Responsive Web Application (Single-Page App - React/Vue):** Runs in any browser, but lacks good offline check-in caching and push notification reliability on iOS.
* **Option C: Progressive Web App (PWA) + Responsive Web:** Single codebase, installable on mobile homescreens, ServiceWorkers enable offline check-in, responsive desktop interface for administrators.
* **Option D: Cross-Platform Framework (Flutter / React Native) + Web Admin:** Native performance and good camera QR access, but higher build complexity and app-store approval delays.

## 3. Weighted Comparison Matrix (Score 1–5 × Weight 1–3)
| Criterion | Weight | Why this weight? | Opt A (Native) | Opt B (Resp. Web) | Opt C (PWA) | Opt D (Flutter) |
| :--- | :---: | :--- | :---: | :---: | :---: | :---: |
| **1. Feasibility in 1 Semester** | **3** | Student team has limited time and resources. | 1 (3) | 5 (15) | 4 (12) | 3 (9) |
| **2. Device Reach (iOS/Android/PC)** | **3** | All three user groups need access. | 4 (12) | 4 (12) | 5 (15) | 4 (12) |
| **3. Offline Check-In at Door** | **3** | Entrance operations must contine without Wi-Fi. | 5 (15) | 1 (3) | 4 (12) | 5 (15) |
| **4. Event Reminders / Notifications** | **2** | Student should receive event reminders. | 5 (10) | 2 (4) | 4 (8) | 5 (10) |
| **5. Desktop Ergonomics for Admin** | **1** | Admins need to manage records and review data. | 2 (2) | 5 (5) | 5 (5) | 3 (3) |
| **Total Score** | | | **42** | **39** | **52 (Winner)** | **49** |

### Deal-Breaker Check:
* *Deal-Breaker:* Organisers at the door must be able to scan tickets even when venue Wi-Fi drops completely.
* *Result for Option C (PWA):* Passed! ServiceWorkers and client-side IndexedDB allow local queuing of check-in records which sync back when connectivity returns.

## 4. Decision
We choose **Option C: A Progressive Web App (PWA) with a Responsive Web layout**:
* **Students & Organisers:** Access via smartphone browser and install as a PWA homescreen icon.
* **Administrators:** Access standard responsive desktop web interface on office PCs.

## 5. Consequences
* `+` **Single Codebase:** Only one web frontend to design, test, and maintain.
* `+` **Offline Capable:** ServiceWorkers cache event rosters for offline door check-ins.
* `-` **iOS Push Limitations:** Older iOS Safari versions have stricter PWA push notification constraints compared to native apps (mitigated via email reminders).
* `-` **Hardware Access:** Camera QR scanning in browser requires user permission prompts.

## 6. Rejected Options

* **Option A: Native Mobile Apps (Kotlin / Swift) + Web Admin**  
  * **Why rejected:** Exceedingly high development cost and effort for a single semester. It would require our team to maintain two separate mobile codebases, handle Google Play / Apple App Store approval delays, and pay developer account fees.

* **Option B: Standard Responsive Web Application (Single-Page App)**  
  * **Why rejected:** **Failed the critical deal-breaker requirement.** Standard web applications cannot function without an active internet connection. During event arrivals, venue Wi-Fi at room doors often collapses, which would cause ticket scanning to fail completely.

* **Option D: Cross-Platform Mobile Framework (Flutter / React Native)**  
  * **Why rejected:** While it supports good offline caching and single-codebase mobile deployment, compiling and testing desktop web targets alongside mobile builds introduces unnecessary build complexity and tooling overhead for a 15-week student project.



## 7. How the Front Ends Reach the C++ Core
In the future system, the PWA and administrator web interface will communicate with the C++ core through an HTTP API. The API will pass requests to the business logic and return results to the interfaces.

In this lab, we will not implement the HTTP API or the web interfaces. Instead, the command-line interface (CLI) will call the C++ core directly. The core will contain the domain model and business rules so that it can later be reused by an API.

In simple words: The future website will communicate with the C++ core through and API, but for this lab, the CLI talks directly to the core.