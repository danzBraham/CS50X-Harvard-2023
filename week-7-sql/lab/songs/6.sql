SELECT songs.name FROM songs
JOIN artists ON artists.id = songs.artist_id
WHERE artists.name = 'Post Malone';