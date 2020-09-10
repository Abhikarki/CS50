-- list the names of all people who starred in a movie in which Kevin Bacon also starred.

SELECT DISTINCT(people.name) AS names FROM people
JOIN stars
ON people.id = stars.person_id
WHERE movie_id IN(
    SELECT stars.movie_id
    FROM stars
    JOIN people
    ON stars.person_id = people.id
    WHERE people.name = 'Kevin Bacon' AND people.birth = 1958)
AND people.id NOT IN(
    SELECT people.id FROM people WHERE
    people.name = 'Kevin Bacon' AND people.birth = 1958);
