--to list the titles and release years of all Harry Potter movies, in chronological order

SELECT title, year AS 'release year' FROM movies WHERE title LIKE 'Harry Potter%' ORDER BY year;