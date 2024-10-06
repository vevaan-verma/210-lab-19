// COMSC-210 | Lab 19 | Vevaan Verma
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct RatingNode;
struct ReviewNode;
class Movie;

/* FUNCTION PROTOTYPES */
void getMovieData(vector<Movie>&);
void outputMovies(vector<Movie>&);
string getStringInput();
int getIntInput();
double getDoubleInput();

/* CONSTANTS */
const string FILE_PATH = "movie-reviews.txt"; // name of the input file

/* FILE FORMAT */
// title
// number of reviews (this is to allow for scalability)
// review 1
// review 2
// ...

/* GLOBAL VARIABLES */
ifstream fin;

// struct RatingNode is a node that holds a rating
struct RatingNode {

	double rating;
	RatingNode* next;

};

// struct ReviewNode is a node that holds a review comment
struct ReviewNode {

	string review;
	ReviewNode* next;

};

// struct Movie is a movie that holds a title, ratings, and reviews
class Movie {

public:
	Movie(string title) {

		this->title = title;
		ratings = nullptr;
		reviews = nullptr;

	}

	string getTitle() { return title; }

	RatingNode* getRatings() { return ratings; }

	void addRating(RatingNode* ratingNode) {

		ratingNode->next = ratings;
		ratings = ratingNode;

	}

	ReviewNode* getReviews() { return reviews; }

	void addReview(ReviewNode* reviewNode) {

		reviewNode->next = reviews;
		reviews = reviewNode;

	}

private:
	string title;
	// the lab instructions said to separate the ratings and reviews into separate linked lists
	RatingNode* ratings;
	ReviewNode* reviews;

};

// main() is the entry point of the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	vector<Movie> movies; // create a vector of movies
	fin.open(FILE_PATH); // open the input file for reading

	if (!fin.good()) { // if the file does not exist

		cout << "File " << FILE_PATH << " not found" << endl; // output error message
		return 1; // return an error code

	}

	getMovieData(movies); // get the movie data from the input file
	outputMovies(movies); // output the movie data to the console

	fin.close(); // close the input file
	return 0;

}

// getMovieData() reads the movie data from the input file and stores it in the vector of movies
// arguments: vector<Movie>& movies - the vector of movies to store the movie data in
// returns: void
void getMovieData(vector<Movie>& movies) {

	// check file format guide above

	string title;

	while (!fin.eof()) { // while the end of the file has not been reached

		title = getStringInput(); // get the title of the movie
		Movie movie(title); // create a new movie with the title

		int numReviews = getIntInput(); // get the number of reviews for the movie

		for (int i = 0; i < numReviews; i++) { // for each rating

			RatingNode* ratingNode = new RatingNode; // create a new rating node
			ratingNode->rating = rand() % 5 + 1; // set the rating of the rating node to a random number between 1.0 and 5.0
			movie.addRating(ratingNode); // add the rating node to the front of the ratings linked list

			ReviewNode* reviewNode = new ReviewNode; // create a new review node
			reviewNode->review = getStringInput(); // set the review of the review node to the review read from the input file
			movie.addReview(reviewNode); // add the review node to the front of the reviews linked list

		}

		movies.push_back(movie); // add the movie to the vector of movies

	}
}

// outputMovies() outputs the given vector of movies to the console
// arguments: vector<Movie>& movies - the vector of movies to output
// returns: void
void outputMovies(vector<Movie>& movies) {

	for (int i = 0; i < movies.size(); i++) {

		cout << "Title: " << movies[i].getTitle() << endl;

		RatingNode* ratings = movies[i].getRatings();
		ReviewNode* reviews = movies[i].getReviews();

		cout << "Ratings:" << endl; // output ratings header

		// loop through the ratings linked list and output each rating
		while (ratings != nullptr) {

			cout << "    > " << ratings->rating << endl;
			ratings = ratings->next;

		}

		cout << "Reviews:" << endl; // output reviews header

		// loop through the reviews linked list and output each review
		while (reviews != nullptr) {

			cout << "    > " << reviews->review << endl;
			reviews = reviews->next;

		}

		cout << endl;

	}
}

// getStringInput() gets the string input from a file stream; it will also exit the program if the file is not formatted as expected
// arguments: none
// returns: string - the validated string input
string getStringInput() {

	string inputStr; // variable to store the input (of type string)
	getline(fin, inputStr); // get the input from the input file stream

	if (inputStr.empty()) { // if the input is empty

		cout << "Invalid input. File does not contain valid formatting." << endl; // output an error message (this makes sure the program does not continue if the file is not formatted as expected)
		exit(1); // exit the program with an error code

	}

	return inputStr;

}

// getIntInput() gets the int input from a file stream
// arguments: none
// returns: int - the int input
int getIntInput() {

	int inputInt; // variable to store the input (of type int)
	fin >> inputInt; // get the input from the input file stream
	fin.ignore(INT_MAX, '\n'); // ignore the invalid input

	return inputInt;

}

// getDoubleInput() gets the double input from a file stream
// arguments: none
// returns: double - the double input
double getDoubleInput() {

	double inputDbl; // variable to store the input (of type double)
	fin >> inputDbl; // get the input from the input file stream
	fin.ignore(INT_MAX, '\n'); // ignore the invalid input

	return inputDbl;

}