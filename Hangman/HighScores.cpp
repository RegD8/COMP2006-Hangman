#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "HighScores.h"

using namespace std;
int index = 0;


//main menu
void HighScores::PrintMenu() {
	cout << "Welcome to Hangman!" << endl;
	cout << "1. Play Now!" << endl;
	cout << "2. View HighScores List" << endl;
	cout << "3. Exit" << endl;
}

//this method will take inputs to write a new highscore, if the user already has a 
//score it will overwrite it.
void HighScores::WriteHighScore(string username, int highscore, string date) {

	bool found = false; //true if the user is already in the file
	bool higherScore = true; // true if the user has a higher score than before
	readFile(); //call the read file function

				//compare username and check if the current score is greater or not.
	for (int i = 0; i < index; i++)
	{
		// compare first name, last name of the user
		// and check if current score is greater or not
		if (scoresArray[i].username == username && scoresArray[i].score < highscore)
		{
			cout << "Congratulations on a higher score! We've updated it to the list." << endl;
			scoresArray[i].score = highscore;
			found = true;		// user found in file
			break;				// break from this loop when found
		}
		//if the user is found in the file but not with a higher score 
		//change the higherscore variable to false
		if (scoresArray[i].username == username) {
			cout << "Sorry, your previous highscore was higher. This highscore has not been recorded." << endl;
			higherScore = false;
			break; //break if found
		}
	}

	// if not found in file
	if (!found && higherScore)
	{
		cout << "We've added your Score to the High Score List" << endl;
		// add to current users variables
		scoresArray[index].username = username;
		scoresArray[index].score = highscore;
		scoresArray[index++].date = date;
	}

	// sort the scores by high score number
	sortScores(scoresArray);

	//file name
	string fileName = "highscores.txt";

	// open file to write
	ofstream outFile(fileName);

	// loop through user loaded from file
	for (int i = 0; i < index; i++)
	{
		// write all user to file one by one
		outFile << scoresArray[i].username << " " << scoresArray[i].score << " " << scoresArray[i].date << endl;
	}

	//close the file
	outFile.close();
}

//this function reads the file and loads it into the scores array
void HighScores::readFile() {

	//open file for read
	ifstream scoresFile("highscores.txt");
	string  username, date;
	double score;
	// read all usernames, scores and dates from files and load them
	// in variables
	// read till end of file
	while (scoresFile >> username && scoresFile >> score && scoresFile >> date)
	{
		scoresArray[index].username = username;
		scoresArray[index].score = score;
		scoresArray[index++].date = date;
	}
}


//this method will find the top 10 high scores and print them to the screen
void HighScores::PrintHighScore() {

	string highscores[10]; // variable to store the top 10 highscores in
	int count = 0;
	ifstream input;
	string username, date, score;

	input.open("highscores.txt"); //open the highscores file

	if (input.is_open()) {
		cout << "User Name" << "\t" << "Score" << "\t\t" << "Date" << endl;
		cout << "---------------------------------------------------" << endl;
		//loop through the top 10 from the text file
		for (int i = 0; i < 10; i++) {
			//get each line from the text file
			while (getline(input, highscores[i])) {

				istringstream ss(highscores[i]);

				while (ss >> username >> score >> date)
				{
					cout << username << "\t\t" << score << "\t\t" << date << endl; //output the file in a table format
				}
			}
		}
		cout << endl;
		input.close();
	}
	else {
		cout << "Could not open the HighScores File" << endl;
	}
}

// sort highscores loaded from file
// sort them from highest to lowest
void HighScores::sortScores(PlayerHighScores *array) {

	PlayerHighScores temp;		// temp variable to swap for sorting
	for (int i = 0; i<index; i++) {
		for (int j = i + 1; j<index; j++) {
			//compare the highScore
			if (array[i].score < array[j].score) {
				// swap variables/highscores
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}// end of inner for loop
	}// end of for loop
}