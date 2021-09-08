//
// Created by alessio on 08/09/21.
//

#ifndef CHAT_CHAT_H
#define CHAT_CHAT_H


#include <memory>
#include <list>
#include <vector>
#include "Subject.h"
#include "Messaggio.h"
#include "Utente.h"

class Chat : public Subject{
    explicit Chat(Utente u1, Utente u2);


    void addMex(const Messaggio &nMex);

    const Messaggio &ultimoMex() const;

    int mexNonLetti() const;

    virtual void subscribe(std::shared_ptr<Observer> o) override;
    virtual void unsubscribe(std::shared_ptr<Observer> o) override;
    virtual void notify() override;


private:
    std::list<std::shared_ptr<Observer>> observers;
    std::vector<Messaggio> mex;
    std::string utente1;
    std::string utente2;

};


#endif //CHAT_CHAT_H
