--list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.

SELECT movies.title FROM movies WHERE movies.id IN(
    SELECT movies.id FROM movies
    JOIN stars
    ON movies.id = stars.movie_id WHERE stars.person_id IN(
        SELECT id FROM people WHERE
        name = 'Johnny Depp'))
AND movies.id IN(
    SELECT movies.id FROM movies
    JOIN stars
    ON movies.id = stars.movie_id WHERE stars.person_id IN(
    SELECT id FROM people WHERE
    name = 'Helena Bonham Carter'));
