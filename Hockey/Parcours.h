#pragma once
#include <string>
#include <vector>

using namespace std;

class Parcours
{
private:
	string club;
	string date;

public:
	Parcours() {}
	string getClub() { return club; }
	string getDate() { return date; }
	Parcours(string club, string date);
};