#pragma once
#include "NegoVendeur.h"
#include "NegoAcheteur.h"
#include "CMutex.h"
#include <windows.h>

class Negociation
{
public:
	Negociation();

	void creerThreads();
	void proposerOffre();
	void accepterOffre();
	void rejeterOffre();
};