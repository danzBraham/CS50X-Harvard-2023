SELECT COUNT(*)
FROM movies AS m
    JOIN ratings AS r
    ON r.movie_id = m.id
WHERE rating = 10.0;
