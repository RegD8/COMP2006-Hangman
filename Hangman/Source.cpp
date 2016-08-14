#include <iostream>
#include <string>
#include "hangman.h"
#include "HighScores.h"

using namespace std;

int main(){
	int userChoice, score;
	bool quit = false;
	int guessNum;
	hangman noose;
	HighScores highscore;
	string username, date;


	while (!quit) {
		do {
			highscore.PrintMenu(); //print the menu
			cin >> userChoice;

		} while (userChoice < 1 || userChoice > 3);

		if (userChoice == 1) {
			score = 10; // TESTING PURPOSES -- THIS SHOULD BE POPULATED BY A COUNTER WHILE PLAYING THE GAME

			cout << "Please enter your username" << endl; //get username for highscores
			cin >> username;
			cout << "Please enter today's date(MM-DD-YYYY)" << endl; //get todays date for highscores
			cin >> date;

			//begin game play methods here
			// **************************
			// *****************************
			//***********************************

			//Report the players score to the highscores list
			cout << "Thanks for playing! Your highscore has been added!" << endl;
			highscore.WriteHighScore(username, score, date); //write the highscore to the file
			highscore.PrintHighScore(); // print the highscores to the main
			cout << "---------------------------------------------" << endl;
			
		}
		else if (userChoice == 2) {
			highscore.PrintHighScore(); //PRINT THE HIGHSCORE MENU
		}
		else if (userChoice == 3) {
			quit = true;
		}
	}

	return 0;

	}

