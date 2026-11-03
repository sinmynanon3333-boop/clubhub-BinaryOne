# Challenge: Offline-First Check-In for ITC Club Hub
Version 1.0 2026-11-02 Team: BinaryOne

---

## 1. Sequence Diagram: Offline Scan & Reconciliation 
This diagram illustrates an organizer scanning a QR code while disconnected, saving it locally, reconnecting to Wi-Fi and batch-syncing to the server.
```mermaid
sequenceDiagram
    autonumber
    participant O as Organiser
    participant P as PWA
    participant SW as ServiceWorker
    participant Q as IndexedDB queue
    participant API as Club Hub API

    Note over O,API: Phase 1 - the phone is offline
    O->>P: Scan student QR code
    P->>Q: enqueue(clientCheckInId, eventId, studentId, scannedAt)
    Q-->>P: stored with status Pending
    P-->>O: Local green tick "Saved on this phone"
    P->>SW: register background sync "upload-checkins"
    SW-->>P: waiting for network

    Note over O,API: Phase 2 - the network comes back
    SW->>SW: sync event fires, phone is online
    SW->>Q: read pending()
    Q-->>SW: pending records, oldest scan first
    SW->>API: POST /checkins/batch (items plus deviceSentAt)
    API->>API: apply each item once per clientCheckInId
    API-->>SW: 200 with one result per item

    loop for each item in the response
        alt result is accepted
            SW->>Q: markAccepted(clientCheckInId)
        else result is rejected with a reason
            SW->>Q: markRejected(clientCheckInId, reason)
        end
    end

    SW->>P: postMessage(sync finished)
    P-->>O: Badge "38 synced, 2 need attention" with the reasons
```
## 2.Conflict Resolution Rule
| # | Case | Winner | What Organizer sees | What is stored on the server |
| :-: | :--- | :--- | :--- | :---|
| **1** | 