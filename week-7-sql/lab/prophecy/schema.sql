DROP TABLE students;
DROP TABLE houses;
DROP TABLE assignments;

CREATE TABLE students (
    id INTEGER,
    student_name TEXT,
    house TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE assignments (
    id INTEGER,
    student_id INTEGER,
    house_id INTEGER,
    PRIMARY KEY(id)
);
