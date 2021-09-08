//
// Created by alessio on 08/09/21.
//

#include "Utente.h"

const std::string &Utente::getNome() const {
    return nome;
}

Utente::Utente(std::string nome) : nome(nome){}

std::shared_ptr<Chat> Utente::nuovaChat(Utente &u) {
    Chat *c = new Chat((*this),u);
    auto ptr = std::make_shared<Chat>(*c);
    chats.insert(std::make_pair(u.getNome(),ptr));
    u.aggiungiChat(ptr, *this);
    return ptr;
}

void Utente::rimuoviChat(const Utente &u) {
    auto r = chats.find(u.getNome());
    chats.erase(r);

}

void Utente::aggiungiChat(std::shared_ptr<Chat> c, Utente &u) {
    chats.insert(std::make_pair(u.getNome(),c));

}

Utente::~Utente() {

}

std::shared_ptr<Chat> Utente::ricercaChat(const Utente &u) {
    auto r = chats.find(u.getNome());
    return (r->second);

}
