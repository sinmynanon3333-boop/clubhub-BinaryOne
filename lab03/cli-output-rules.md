# CLI Output & Accessibility Rules · ITC Club Hub (`clubhub` CLI)

Our C++ command-line interface (`src/cli/main.cpp`) must be usable across screen readers, Braille displays, monochrome terminals, CI/CD logs, and piped shell scripts. Every CLI command must follow these six rules.

---

### Rule 1: Never use colour alone to convey meaning
Status values must always be printed as explicit, bracketed uppercase words (`[REGISTERED]`, `[CANCELLED]`, `[CHECKED IN]`, `[WAITLISTED]`). ANSI colour codes may only wrap the text as a secondary visual reinforcement.

```text
rule 1: never colour alone
  bad : E-017  Git Workshop      (shown in red)
  good: E-017  Git Workshop      [CANCELLED]