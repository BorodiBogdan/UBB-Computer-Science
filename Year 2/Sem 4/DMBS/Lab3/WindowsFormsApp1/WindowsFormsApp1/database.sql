-- First scenario: Music Library (Artists and Albums)
-- Drop detail tables first
IF OBJECT_ID('dbo.Album', 'U') IS NOT NULL
    DROP TABLE dbo.Album;

IF OBJECT_ID('dbo.Book', 'U') IS NOT NULL
    DROP TABLE dbo.Book;

-- Then drop master tables
IF OBJECT_ID('dbo.Artist', 'U') IS NOT NULL
    DROP TABLE dbo.Artist;

IF OBJECT_ID('dbo.Author', 'U') IS NOT NULL
    DROP TABLE dbo.Author;

CREATE TABLE Artist (
    artist_id INT PRIMARY KEY IDENTITY(1,1),
    name NVARCHAR(100) NOT NULL,
    country NVARCHAR(50),
    founded_year INT
);

CREATE TABLE Album (
    album_id INT PRIMARY KEY IDENTITY(1,1),
    title NVARCHAR(100) NOT NULL,
    release_year INT,
    genre NVARCHAR(50),
    artist_id INT NOT NULL,
    FOREIGN KEY (artist_id) REFERENCES Artist(artist_id)
);

-- Second scenario: Book Library (Authors and Books)
CREATE TABLE Author (
    author_id INT PRIMARY KEY IDENTITY(1,1),
    name NVARCHAR(100) NOT NULL,
    birth_year INT,
    nationality NVARCHAR(50)
);

CREATE TABLE Book (
    book_id INT PRIMARY KEY IDENTITY(1,1),
    title NVARCHAR(100) NOT NULL,
    publication_year INT,
    genre NVARCHAR(50),
    author_id INT NOT NULL,
    FOREIGN KEY (author_id) REFERENCES Author(author_id)
);

-- Insert sample data for Music Library
INSERT INTO Artist (name, country, founded_year) VALUES 
('The Beatles', 'UK', 1960),
('Queen', 'UK', 1970),
('Pink Floyd', 'UK', 1965);

INSERT INTO Album (title, release_year, genre, artist_id) VALUES
('Abbey Road', 1969, 'Rock', 1),
('Let It Be', 1970, 'Rock', 1),
('A Night at the Opera', 1975, 'Rock', 2),
('The Dark Side of the Moon', 1973, 'Progressive Rock', 3);

-- Insert sample data for Book Library
INSERT INTO Author (name, birth_year, nationality) VALUES
('J.K. Rowling', 1965, 'British'),
('George R.R. Martin', 1948, 'American'),
('Stephen King', 1947, 'American');

INSERT INTO Book (title, publication_year, genre, author_id) VALUES
('Harry Potter and the Philosopher''s Stone', 1997, 'Fantasy', 1),
('Harry Potter and the Chamber of Secrets', 1998, 'Fantasy', 1),
('A Game of Thrones', 1996, 'Fantasy', 2),
('The Shining', 1977, 'Horror', 3);

select * from Album;