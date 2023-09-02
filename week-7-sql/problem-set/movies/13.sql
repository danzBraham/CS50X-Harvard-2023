SELECT DISTINCT(name)
FROM stars AS s
    JOIN movies AS m
    ON m.id = s.movie_id
    JOIN people AS p
    ON p.id = s.person_id
WHERE movie_id IN (
        SELECT m2.id
        FROM movies AS m2
            JOIN stars AS s2
            ON s2.movie_id = m2.id
            JOIN people AS p2
            ON p2.id = s2.person_id
        WHERE name = 'Kevin Bacon'
        AND birth = 1958
    )
AND person_id != (
    SELECT id
    FROM people
    WHERE name = 'Kevin Bacon'
    AND birth = 1958
);
