#include "Message.h"

Message::Message(string emetteur, string sujetMessage, float montantTransfert) {
	this->emetteur = emetteur;
	this->sujetMessage = sujetMessage;
	this->montantTransfert = montantTransfert;
}