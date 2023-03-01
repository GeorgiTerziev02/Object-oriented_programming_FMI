#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned int maxTitle = 100;

int myStrlen(const char* str)
{
	if (str == nullptr)
	{
		return 0;
	}
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

enum Genre
{
	Comedy,
	Action,
	Horror,
	Romantic
};

struct Movie
{
	char name[maxTitle];
	unsigned int minutes;
	Genre genre;
	double rating;
};


void createMovie( Movie & movie, const char* name, unsigned int duration, Genre genre, double rating)
{
	int titleLen = myStrlen(name);
	for (int i = 0; i < titleLen && i < maxTitle; i++)
	{
		movie.name[i] = name[i];
	}
	movie.name[titleLen] = '\0';

	movie.minutes = duration;
	movie.genre = genre;
	movie.rating = rating;

}

void addMovie(Movie* movies, int numMovies, Movie movie)
{
	if (numMovies < 100)
	{
		movies[numMovies] = movie;
		numMovies++;
	}
}

void printMovie(Movie movie)
{
	cout << "Name: " << movie.name << endl;
	cout << "Duration: " << movie.minutes << "minutes" << endl;
	cout << "Genre: ";
	switch (movie.genre)
	{
	case Comedy:
		cout << "Comedy";
		break;
	case Action:
		cout << "Action";
		break;
	case Horror:
		cout << "Horror";
		break;
	case Romantic:
		cout << "Romantic";
		break;
	default:
		cout << "Unknown";
		break;
	}

	cout << endl;
	cout << "Rating: " << movie.rating << endl;
	cout << endl;
}

void printMovies(Movie* movies, unsigned int numMovies)
{
	for (int i = 0; i < numMovies; i++)
	{
		printMovie(movies[i]);
	}
}


Movie getTopMovie(Movie* movies, int numMovies)
{
	Movie topMovie = movies[0];
	for (int i = 1; i < numMovies; i++)
	{
		if (movies[i].rating > topMovie.rating)
		{
			topMovie = movies[i];
		}
	}
	return topMovie;
}

void SortByRating(Movie* movies, int n)
{
	Movie  temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j + 1 < n - i; j++)
		{
			if (movies[j].rating < movies[j + 1].rating)
			{
				temp = movies[j];
				movies[j] = movies[j + 1];
				movies[j + 1] = temp;
			}
		}
	}
}

int main()
{
	Movie movies[3];
	
	createMovie(movies[0], "Barbie", 175, Comedy, 9);
	createMovie(movies[1], "Harry Potter", 142, Action, 4);
	createMovie(movies[2], "The Dark Knight", 152, Action, 1);

    //cout << "printing movies" << endl;
	//printMovies(movies, 3);

	Movie topMovie = getTopMovie(movies, 3);

    //cout << "printing top movie" << endl;
	//printMovie(topMovie);

	SortByRating(movies, 3);
	printMovies(movies, 3);

}