// COMSC-210 | Lab 19 | Vevaan Verma
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Movie;
struct RatingNode;
struct ReviewNode;

/* FUNCTION PROTOTYPES */
void getMovieData(vector<Movie>&);
void addRatingFront(RatingNode*& head, RatingNode*&);
void addReviewFront(ReviewNode*& head, ReviewNode*&);

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

// struct Movie is a movie that holds a title, ratings, and reviews
class Movie {

public:
	Movie(string title, RatingNode*& ratings, ReviewNode*& reviews) {

		this->title = title;
		this->ratings = ratings;
		this->reviews = reviews;

	}

	string getTitle() { return title; }

	RatingNode* getRatings() { return ratings; }

	ReviewNode* getReviews() { return reviews; }

private:
	string title;
	// the lab instructions said to separate the ratings and reviews into separate linked lists
	RatingNode* ratings;
	ReviewNode* reviews;

};

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

	fin.close(); // close the input file
	return 0;

}

// addRatingFront() adds a rating to the front of the linked list
// arguments: RatingNode*& head - the head of the linked list, RatingNode*& nodeToAdd - the rating node to add to the front of the linked list
// returns: void
void addRatingFront(RatingNode*& head, RatingNode*& nodeToAdd) {

	nodeToAdd->next = head; // set the next of the rating node to the current head
	head = nodeToAdd; // set the head to the rating node

}

// addReviewFront() adds a review to the front of the linked list
// arguments: ReviewNode*& head - the head of the linked list, ReviewNode*& nodeToAdd - the review node to add to the front of the linked list
// returns: void
void addReviewFront(ReviewNode*& head, ReviewNode*& nodeToAdd) {

	nodeToAdd->next = head; // set the next of the review node to the current head
	head = nodeToAdd; // set the head to the review node

}