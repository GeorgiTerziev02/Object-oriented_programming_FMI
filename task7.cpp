#include<iostream>
using namespace std;
struct Movies {
    char name[30];
    char genre[30];
    int runtime;
    int rating;
};
void createMovie(Movies& movie, const char(&name)[30], const char (&genre)[30], const int& runtime, const int& rating) {
    int len1 = sizeof(movie.name) / sizeof(char);
    for (int i = 0; i < len1; i++) {
        movie.name[i] = name[i];
    }
    int len2 = sizeof(movie.genre) / sizeof(char);
    for (int i = 0; i < len2; i++) {
        movie.genre[i] = genre[i];
    }
    movie.runtime = runtime;
    movie.rating = rating;
}
void createArrayOfMovies(Movies(&movieArr)[3]) {
    char name[30];
    char genre[30];
    int runtime;
    int rating;
    for (int i = 0; i < 3; i++) {
        cout << "Enter Movie title:";
        cin.getline(name, 30);
        cout << "Enter genre:";
        cin >> genre;
        cout << "Enter runtime:";
        cin >> runtime;
        cout << "Enter rating:";
        cin >> rating;
        createMovie(movieArr[i], name, genre, runtime, rating);
        cout << endl;
        cin.ignore();
    }
}
void printMovies(Movies(&movieArr)[3]) {
    for (int i = 0; i < 3; i++) {
        cout << " Name: " << movieArr[i].name << endl;
        cout << " Genre: " << movieArr[i].genre << endl;
        cout << " Runtime: " << movieArr[i].runtime << endl;
        cout << " Rating: " << movieArr[i].rating << endl;
        cout << endl;
    }
}
void printHighestRatedMovies(Movies(&movieArr)[3]) {
    int max = 0;
    for (int i = 0; i < 3; i++) {
        if (movieArr[i].rating > max) {
            max = movieArr[i].rating;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (movieArr[i].rating == max) {
            cout << " Name: " << movieArr[i].name << endl;
            cout << " Genre: " << movieArr[i].genre << endl;
            cout << " Runtime: " << movieArr[i].runtime << endl;
            cout << " Rating: " << movieArr[i].rating << endl;
        }
    }
}
void sortingArray(Movies(&movieArr)[3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (movieArr[i].rating < movieArr[j].rating) {
                Movies temp;
                temp = movieArr[i];
                movieArr[i] = movieArr[j];
                movieArr[j] = temp;
            }
        }
    }
}
int main() {
    Movies movie,arrOfMovies[3];
    char name[30], genre[30];
    int runtime, rating;
    cout << "Enter Movie title:";
    cin.getline(name, 30);
    cout << "Enter genre:";
    cin >> genre;
    cout << "Enter runtime:";
    cin >> runtime;
    cout << "Enter rating:";
    cin >> rating;
    createMovie(movie, name, genre, runtime, rating);
    cout << endl;
    cin.ignore();
    createArrayOfMovies(arrOfMovies);
    printMovies(arrOfMovies);
    cout << "---------------------" << endl;
    printHighestRatedMovies(arrOfMovies);
    cout << "---------------------" << endl;
    sortingArray(arrOfMovies);
    printMovies(arrOfMovies);
}