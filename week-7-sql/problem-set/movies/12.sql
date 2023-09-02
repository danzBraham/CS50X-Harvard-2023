SELECT title
FROM movies AS m
WHERE m.id IN (
    SELECT movie_id
    FROM stars AS s
    JOIN people AS p
    ON p.id = s.person_id
        AND p.name = 'Bradley Cooper'
)
AND m.id IN (
    SELECT movie_id
    FROM stars AS s2
    JOIN people AS p2
    ON p2.id = s2.person_id
        AND p2.name = 'Jennifer Lawrence'
);
