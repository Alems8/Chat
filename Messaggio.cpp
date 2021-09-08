//
// Created by alessio on 08/09/21.
//

#include "Messaggio.h"

Messaggio::Messaggio(std::string mitt, std::string r, std::string mes, bool visualizzato) {
    this->mittente = mitt;
    this->destinatario = r;
    this->testo = mes;
    this->visualizzato = visualizzato;
    this->orario = time(&orario);
}

const std::string &Messaggio::getMittente() const {
    return mittente;
}

void Messaggio::setMittente(const std::string &mittente) {
    Messaggio::mittente = mittente;
}

const std::string &Messaggio::getDestinatario() const {
    return destinatario;
}

void Messaggio::setDestinatario(const std::string &destinatario) {
    Messaggio::destinatario = destinatario;
}

const std::string &Messaggio::getTesto() const {
    return testo;
}

void Messaggio::setTesto(const std::string &testo) {
    Messaggio::testo = testo;
}

bool Messaggio::isVisualizzato() const {
    return visualizzato;
}

void Messaggio::setVisualizzato(bool visualizzato) {
    Messaggio::visualizzato = visualizzato;
}

time_t Messaggio::getOrario() const {
    return orario;
}

void Messaggio::setOrario(time_t orario) {
    Messaggio::orario = orario;
}

bool Messaggio::operator==(const Messaggio &mdm) const {
    return (mittente == mdm.mittente && destinatario == mdm.destinatario && testo == mdm.testo);
}

bool Messaggio::operator!=(const Messaggio &mdm) const {
    return !(mdm == *this);
}
