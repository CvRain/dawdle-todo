CREATE TABLE IF NOT EXISTS Todos
(
    todo_id       INTEGER PRIMARY KEY AUTOINCREMENT,
    group_id      INTEGER,
    title         TEXT    NOT NULL,
    description   TEXT,
    due_date      TEXT,
    is_completed  INTEGER NOT NULL DEFAULT 0 CHECK (is_completed IN (0, 1)),
    completed_at  TEXT,
    priority      INTEGER NOT NULL DEFAULT 3,
    todo_type     TEXT    NOT NULL DEFAULT 'SINGLE' CHECK (todo_type IN ('SINGLE', 'TIMED', 'MULTIPLE', 'RECURRING')),
    recurrence_id INTEGER,

    FOREIGN KEY (group_id) REFERENCES Groups (group_id) ON DELETE SET NULL,
    FOREIGN KEY (recurrence_id) REFERENCES RecurrenceDetails (id) ON DELETE CASCADE
);