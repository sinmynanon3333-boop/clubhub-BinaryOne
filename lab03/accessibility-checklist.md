# Accessibility Checklist · ITC Club Hub (Planned Web and Mobile PWA UI)
Target: WCAG 2.2 Level AA · Version 1.0 · 2026-11-06

## 1. WCAG 2.2 Success Criteria (POUR Matrix)

| SC | Name | Level | Screen | How we meet it | How we test it |
| :--- | :--- | :---: | :--- | :--- | :--- |
| **1.1.1** *(Perceivable)* | Non-text Content | A | Door QR Check-in & Event List | Provide descriptive `alt` text on event banners and textual ticket IDs beneath every student QR code. | Run Lighthouse accessibility audit and inspect DOM with NVDA/VoiceOver screen reader. |
| **1.4.1** *(Perceivable)* | Use of Color | A | Event List | Status badges display explicit text (`[OPEN]`, `[FULL]`, `[CANCELLED]`) alongside background colours and icons. | Enable OS greyscale filter and verify all event statuses remain distinguishable. |
| **1.4.3** *(Perceivable)* | Contrast (Minimum) | AA | All Screens | Enforce a minimum 4.5:1 contrast ratio for body text and 3:1 for large headings and UI boundaries. | Measure hex pairs using WebAIM Contrast Checker and Chrome DevTools CSS Overview. |
| **2.1.1** *(Operable)* | Keyboard | A | Admin Dashboard & Registration Form | All interactive controls (filters, modals, submit buttons) use native `<button>`, `<a>`, and `<input>` elements reachable via `Tab`. | Unplug mouse and complete an entire event creation and registration flow using only `Tab`, `Shift+Tab`, `Enter`, and `Space`. |
| **2.4.11** *(Operable - 2.2)* | Focus Not Obscured (Minimum) | AA | Event List & Registration Form | Apply `scroll-padding-top: 4.5rem` and `scroll-padding-bottom: 5rem` so sticky PWA navigation headers/footers never cover focused elements. | Tab sequentially from top to bottom on a 375x667 mobile viewport and verify the focus ring is never hidden behind sticky bars. |
| **2.5.7** *(Operable - 2.2)* | Dragging Movements | AA | Admin Roster Reordering & Date Picker | Provide explicit up/down arrow buttons and direct numeric text inputs alongside any drag-and-drop list or slider. | Attempt to reorder waitlist priority and select event dates using single tap/click activations without pointer dragging. |
| **2.5.8** *(Operable - 2.2)* | Target Size (Minimum) | AA | Registration Form & Door Scanner | All buttons, checkboxes, and action icons have a minimum hit area of `44x44 CSS px` (exceeding the `24x24 CSS px` AA floor). | Inspect computed box models in Chrome DevTools Device Mode and run axe DevTools target-size rules. |
| **3.2.6** *(Understandable - 2.2)* | Consistent Help | A | All PWA & Admin Screens | Place a persistent "Need Help? Student Affairs Support" link in the global footer at the exact same DOM order across every view. | Navigate across 5 different routes and verify the help link stays in the identical relative footer location. |
| **3.3.2** *(Understandable)* | Labels or Instructions | A | Registration Form | Every input field has an explicit `<label for="...">` element and persistent `aria-describedby` format hints (e.g., `e.g., e20240001`). | Click each label to verify focus jumps to its input; inspect Accessibility Tree in browser DevTools. |
| **3.3.7** *(Understandable - 2.2)* | Redundant Entry | A | Event Registration Flow | Auto-populate student name, ITC ID, and email from the cached PWA session/IndexedDB profile so users never type them twice. | Register for two consecutive events and verify personal details are pre-filled on the second form. |
| **3.3.8** *(Understandable - 2.2)* | Accessible Authentication (Minimum) | AA | Student & Organiser Login | Support password managers (`autocomplete="username"`, `autocomplete="current-password"`), copy-paste into OTP fields, and magic email links without puzzle CAPTCHAs. | Paste a generated token from a password manager into the login field and verify no paste-blocking scripts interfere. |
| **4.1.2** *(Robust)* | Name, Role, Value | A | Door QR Check-in Scanner | Expose offline queue sync counts and camera scan results via `<div role="status" aria-live="polite">` regions. | Trigger a simulated offline ticket scan and verify VoiceOver/TalkBack announces "Ticket Checked In (Queued Offline)". |

---

## 2. Screen Design Decisions & Contrast Measurements

### Screen 1: Student Event List & Registration Form (Mobile PWA)
1. **Explicit Text + Icon Status Badges:** Event cards never rely on green/red dots alone; they render uppercase text pills (`[OPEN - 12 SEATS]`, `[WAITLIST ONLY]`, `[CANCELLED]`) with a solid border so students viewing in sunlight or greyscale immediately see availability.
2. **Generous Touch Targets & Sticky-Safe Focus:** All form inputs, radio buttons, and the primary "Register Now" button enforce `min-height: 48px` with `12px` vertical spacing, while `scroll-padding-top: 72px` prevents the PWA top app bar from obscuring keyboard focus.
3. **Zero Redundant Typing with Inline Format Hints:** Student ID and institutional email pre-fill from local storage, and date/time fields display unambiguous ISO-style hints (`2026-10-14 17:30`) directly above the input rather than disappearing placeholder text.

#### Measured Contrast Ratios (Screen 1)
| Element | Foreground Hex | Background Hex | Measured Ratio | WCAG AA Requirement | Result |
| :--- | :---: | :---: | :---: | :---: | :---: |
| Primary Body Text & Input Labels | `#1E293B` (Slate 800) | `#FFFFFF` (White) | **14.68 : 1** | 4.5 : 1 (Normal Text) | **PASS** |
| Primary "Register" Button Text | `#FFFFFF` (White) | `#0F52BA` (ITC Sapphire) | **7.12 : 1** | 4.5 : 1 (Normal Text) | **PASS** |
| Input Field Border (Default State) | `#64748B` (Slate 500) | `#FFFFFF` (White) | **4.76 : 1** | 3.0 : 1 (UI Component) | **PASS** |
| `[FULL]` Badge Text on Amber Pill | `#451A03` (Amber 950) | `#FEF3C7` (Amber 100) | **13.52 : 1** | 4.5 : 1 (Normal Text) | **PASS** |

---

### Screen 2: Organiser Offline Door QR Check-In (Mobile / Tablet PWA)
1. **Multimodal Scan Feedback (Text + Shape + Audio/Haptic):** When a ticket QR code is scanned at the venue entrance, the screen shows a large banner with an explicit word (`[CHECKED IN]` or `[DUPLICATE TICKET]`), a distinct icon (`✓` vs `!`), and an `aria-live="assertive"` announcement.
2. **Keyboard/Manual Fallback for Camera Failures:** Below the camera viewfinder, a high-contrast manual Student ID input (`min-height: 48px`) allows organisers to check in students without dragging or camera gestures if permissions fail or a phone screen is cracked.
3. **Persistent Offline Queue Banner:** When venue Wi-Fi drops, a top status bar displays `Offline Mode: 14 check-ins queued locally — will auto-sync` alongside a manual "Retry Sync" button (`48x48 px` minimum target size).

#### Measured Contrast Ratios (Screen 2)
| Element | Foreground Hex | Background Hex | Measured Ratio | WCAG AA Requirement | Result |
| :--- | :---: | :---: | :---: | :---: | :---: |
| `[CHECKED IN]` Success Banner Text | `#FFFFFF` (White) | `#15803D` (Green 700) | **5.14 : 1** | 4.5 : 1 (Normal Text) | **PASS** |
| `[INVALID / DUPLICATE]` Error Banner Text | `#FFFFFF` (White) | `#B91C1C` (Red 700) | **6.47 : 1** | 4.5 : 1 (Normal Text) | **PASS** |
| Offline Queue Status Bar Text | `#0F172A` (Slate 900) | `#FACC15` (Yellow 400) | **11.95 : 1** | 4.5 : 1 (Normal Text) | **PASS** |
| Manual Check-In Button Boundary | `#38BDF8` (Sky 400) | `#0F172A` (Dark Scanner BG) | **8.28 : 1** | 3.0 : 1 (UI Component) | **PASS** |