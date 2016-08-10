#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>

using namespace std;

class hangman{
public:
	int guess(int amountGuessed); // constructor 
	int print()const;
	int guess(); //default constructor 
	int guesses;
};

int hangman::guess(){
	return guesses;
}
int hangman::guess(int amountGuessed){
	guesses = amountGuessed;
	return guesses;
}

int hangman::print() const {
	if (guesses == 0) {
		cout << " _________     " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
	}
	else if (guesses == 1) {
		cout << " _________     " << endl;
		cout << "|         |    " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
	}
	else if (guesses == 2) {
		cout << " _________     " << endl;
		cout << "|         |    " << endl;
		cout << "|         0    " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
	}
	else if (guesses == 3) {
		cout << " _________     " << endl;
		cout << "|         |    " << endl;
		cout << "|         0    " << endl;
		cout << "|         |    " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
	}
	else if (guesses == 4) {
		cout << " _________     " << endl;
		cout << "|         |    " << endl;
		cout << "|         0    " << endl;
		cout << "|         |\\    " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
	}
	else if (guesses == 5) {
		cout << " _________     " << endl;
		cout << "|         |    " << endl;
		cout << "|         0    " << endl;
		cout << "|        /|\\  " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
	}
	else if (guesses == 6) {
		cout << " _________     " << endl;
		cout << "|         |    " << endl;
		cout << "|         0    " << endl;
		cout << "|        /|\\  " << endl;
		cout << "|        /     " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
	}
	else if (guesses == 7) {
		cout << " _________     " << endl;
		cout << "|         |    " << endl;
		cout << "|         0    " << endl;
		cout << "|        /|\\  " << endl;
		cout << "|        / \\  " << endl;
		cout << "|              " << endl;
		cout << "|              " << endl;
		cout << "GAME OVER      " << endl;
	}
	return guesses;
}
#endif