SELECT DISTINCT(name)
FROM people AS p
    JOIN directors AS d
    ON d.person_id = p.id

    JOIN movies AS m
    ON m.id = d.movie_id

    JOIN ratings AS r
    ON r.movie_id = m.id
WHERE rating >= 9.0;
