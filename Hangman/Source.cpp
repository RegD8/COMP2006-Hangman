#include <iostream>
#include <string>
#include "hangman.h"


using namespace std;

int guessNum;
hangman noose;

int main(){
	while (guessNum != 10) {
		cout << "enter a number" << endl;
		cin >> guessNum;
		noose.guess(guessNum);
		noose.print();
		system("PAUSE");
	}
}