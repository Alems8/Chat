//
// Created by alessio on 08/09/21.
//

#include "Chat.h"

Chat::Chat(Utente utent1, Utente utent2) : utente1(utent1.getNome()), utente2(utent2.getNome()){};

void Chat::addMex(const Messaggio &nMex) {
    if((utente1 == nMex.getMittente()) || (utente1 == nMex.getDestinatario()) && (utente1 == nMex.getMittente())
        || (utente2 == nMex.getDestinatario()))
        mex.push_back(nMex);
    if(utente1 == nMex.getDestinatario())
        this->notify();
}

const Messaggio &Chat::ultimoMex() const {
    return mex.back();
}

int Chat::mexNonLetti() const {
    int i = 0;
    for(auto &m :mex){
        if (m.getDestinatario() == utente1){
            if (!m.isVisualizzato())
                i++;
        }
    }
    return i;
}

void Chat::subscribe(std::shared_ptr<Observer> o) {
    observers.push_back(o);
}

void Chat::unsubscribe(std::shared_ptr<Observer> o) {
    observers.remove(o);
}

void Chat::notify() {
    for(auto obs:observers)
        obs->update();
}

Chat::~Chat() {

}