--to determine the average rating of all movies released in 2012.

 SELECT ROUND(AVG(rating), 1) AS 'average rating' FROM ratings WHERE movie_id IN(SELECT id FROM movies WHERE year = 2012);

--Rounding the average rating to one decimal place similar to the imdb ratings.