#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>


using namespace std;

class User {

private:
	string userName, score;

	struct TempUser
	{
		string userName;	//username
		string score;	//score
	};

public:
	bool LoggedIn;



};
#endif