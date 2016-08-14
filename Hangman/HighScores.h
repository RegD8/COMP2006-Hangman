#pragma once
#include <iostream>

using namespace std;

class HighScores {


private:

	//struct for storing the user info and their highscore
	struct PlayerHighScores {
		string username;
		int score;
		string date;
	};

	//array to store the highscore structures in
	PlayerHighScores scoresArray[10];
	int index = 0;
public:
	void PrintMenu();
	void WriteHighScore(string username, int highscore, string date);
	void PrintHighScore();
	void readFile();
	void sortScores(PlayerHighScores *arrayx);

};