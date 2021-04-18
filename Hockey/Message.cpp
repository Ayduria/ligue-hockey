#include "Message.h"

Message::Message(Negociateur* emetteur, string sujetMessage, float montantTransfert) {
	this->emetteur = emetteur;
	this->sujetMessage = sujetMessage;
	this->montantTransfert = montantTransfert;
}