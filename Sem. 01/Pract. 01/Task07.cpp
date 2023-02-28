#include <iostream>

const int MAX_NAME_SIZE = 30;

enum class Genre {
	Comedy,
	Action,
	Horror,
	Romantic
};

struct Movie {
	double rating;
	Genre genre;
	int duration;
	char name[MAX_NAME_SIZE + 1];
};

void mySwap(Movie& lhs, Movie& rhs) {
	Movie temp = lhs;
	lhs = rhs;
	rhs = temp;
}

void myStrCopy(char* arr1, const char* arr2) {
	int index = 0;
	while (arr2[index] != '\0') {
		arr1[index] = arr2[index];
		index++;
	}
  
	arr1[index] = '\0';
}

void initMovie(Movie& movie, const char* name, const double rating, const int duration, const Genre genre) {
	myStrCopy(movie.name, name);
	movie.rating = rating;
	movie.duration = duration;
	movie.genre = genre;
}

void printMovies(const Movie* moviesArr, const int count) {
	for (size_t i = 0; i < count; i++) {
		std::cout << "Movie name: ";
		std::cout << moviesArr[i].name;
		std::cout << std::endl;
		std::cout << "Duration: " << moviesArr[i].duration << std::endl;
		std::cout << "Rating: " << moviesArr[i].rating << std::endl;
		std::cout << "Genre: ";

		switch (moviesArr[i].genre) {
			case Genre::Comedy: std::cout << "Comedy"; break;
			case Genre::Action: std::cout << "Action"; break;
			case Genre::Horror: std::cout << "Horror"; break;
			case Genre::Romantic: std::cout << "Romantic"; break;
		}

		std::cout << std::endl;
	}
}

void sortMoviesByRating(Movie* movies, const int count) {
	for (size_t i = 0; i < count - 1; ++i) {
		size_t indexOfMaxElement = i;
		for (size_t j = i + 1; j < count; ++j) {
			if (movies[indexOfMaxElement].rating < movies[j].rating) {
				indexOfMaxElement = j;
			}
		}
		
		if(indexOfMaxElement != i) {
			mySwap(movies[i], movies[indexOfMaxElement]);
		}
	}
  
}

void printNameOfBestRatedMovie(const Movie* movies, const int count) {
	int indexOfBest = 0;

	for (size_t i = 1; i < count; i++) {
		if (movies[indexOfBest].rating < movies[i].rating) {
			indexOfBest = i;
		}
	}

	std::cout << movies[indexOfBest].name << std::endl;
}

int main() {
	int numberOfMovies;
	std::cin >> numberOfMovies;

	Movie* movies = new Movie[numberOfMovies];

	for (int i = 0; i < numberOfMovies; i++) {
		char name[MAX_NAME_SIZE + 1];
		std::cin >> name;
		std::cin.ignore();
		double rating;
		int duration, type;
		std::cin >> rating >> duration >> type;
		Genre genre = (Genre)type; // TODO: validation / switch case
		initMovie(movies[i], name, rating, duration, genre);

	}

	printNameOfBestRatedMovie(movies, numberOfMovies);
	sortMoviesByRating(movies, numberOfMovies);
	printMovies(movies, numberOfMovies);
  
  	delete[] movies;
}
