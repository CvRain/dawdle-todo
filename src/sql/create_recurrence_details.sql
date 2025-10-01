CREATE TABLE IF NOT EXISTS RecurrenceDetails
(
    id                    INTEGER PRIMARY KEY AUTOINCREMENT,
    todo_id               INTEGER NOT NULL,
    recurrence_pattern    TEXT, -- DAILY, WEEKLY, MONTHLY, CUSTOM
    interval_value        INTEGER          DEFAULT 1,
    end_condition         TEXT    NOT NULL DEFAULT 'NEVER' CHECK (end_condition IN ('NEVER', 'ON_DATE', 'AFTER_OCCURRENCES')),
    end_date              TEXT,
    total_occurrences     INTEGER,
    completed_occurrences INTEGER NOT NULL DEFAULT 0,

    CHECK (recurrence_pattern IN ('DAILY', 'WEEKLY', 'MONTHLY', 'CUSTOM')),

    FOREIGN KEY (todo_id) REFERENCES Todos (todo_id) ON DELETE CASCADE
);