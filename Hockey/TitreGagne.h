#pragma once
#include "Palmares.h"
#include "Club.h"
#include <vector>

using namespace std;

class TitreGagne
{
private:
	Palmares palmares;
	Club* club;

public:
	TitreGagne(Palmares palmares, Club* club);
};