//
// Created by alessio on 08/09/21.
//

#include "Chat.h"

Chat::Chat(Utente u1, Utente u2) {
    this->utente1 = u1.getNome();
    this->utente2 = u2.getNome();


}

void Chat::addMex(const Messaggio &nMex) {
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
