#pragma once
#include<windows.h>

class CMutex {

	HANDLE unMutex;
	void* unObjet;

public:
	CMutex() {
		unMutex = CreateMutex(NULL, false, NULL);
	}

	void Synchroniser() {
		WaitForSingleObject(unMutex, INFINITE);
	}

	void Liberer() {
		ReleaseMutex(unMutex);

	}

	void* getObjet() {
		return unObjet;
	}

	void setObjet(void* unObj) {
		unObjet = unObj;
	}
};