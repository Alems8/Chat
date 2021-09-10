//
// Created by alessio on 08/09/21.
//

#include "Utente.h"

const std::string &Utente::getNome() const {
    return nome;
}

Utente::Utente(std::string nome) : nome(nome){}

std::shared_ptr<Chat> Utente::nuovaChatUtente(Utente &u) {
    Chat *c = new Chat((*this),u);
    std::shared_ptr<Chat> ptr = std::make_shared<Chat>(*c);
    this->aggiungiChat(ptr,(u));
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

void Utente::cronologiaChat() {
    std::cout << "\nCronologia chat di: " << getNome() << std::endl;
    for(auto &c:chats)
        std::cout << c.first << std::endl;
}

int Utente::getNumeroChats() {
    return chats.size();
}

