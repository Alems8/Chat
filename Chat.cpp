//
// Created by alessio on 08/09/21.
//

#include <iostream>
#include "Chat.h"

Chat::Chat(Utente utent1, Utente utent2) : utente1(utent1.getNome()), utente2(utent2.getNome()){};

void Chat::addMex(const Messaggio &nMex) {
    if((utente1 == nMex.getMittente()) || (utente1 == nMex.getDestinatario()) && (utente2 == nMex.getMittente())
        || (utente2 == nMex.getDestinatario()))
        mex.push_back(nMex);
    if(utente1 == nMex.getDestinatario())
        this->notify();
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

void Chat::leggiChat() {
    if(mex.size() != 0){
        std::cout << "\nChat tra: " << utente1 << " e " << utente2 << std::endl;
        for (auto &m:mex){
            std::cout <<m.getMittente()<<" ha scritto: " << m.getTesto() <<std::endl;
            m.setVisualizzato(true);
            this->notify();
        }
    }else
        throw std::out_of_range("Nessun messaggio presente in questa chat");

}
