SELECT AVG(rating)
FROM movies AS m
    JOIN ratings AS r
    ON r.movie_id = m.id
WHERE year = 2012;
