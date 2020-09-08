--SQL query to determine the number of movies with an IMDb rating of 10.0.

SELECT COUNT(movie_id) AS 'movies with 10.0 ratings' FROM ratings WHERE rating = 10.0;