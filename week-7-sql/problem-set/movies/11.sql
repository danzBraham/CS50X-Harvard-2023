SELECT title
FROM movies AS m
    JOIN ratings AS r
    ON r.movie_id = m.id

    JOIN stars AS s
    ON s.movie_id = m.id

    JOIN people AS p
    ON p.id = s.person_id
WHERE name = 'Chadwick Boseman'
ORDER BY rating DESC
LIMIT 5;
