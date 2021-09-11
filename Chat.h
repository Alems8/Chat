//
// Created by alessio on 08/09/21.
//

#ifndef CHAT_CHAT_H
#define CHAT_CHAT_H


#include <memory>
#include <list>
#include <vector>
#include <iostream>

#include "Subject.h"
#include "Messaggio.h"
#include "Utente.h"


class Utente;
class Chat : public Subject{
public:
    explicit Chat(Utente u1, Utente u2);

    virtual ~Chat();

    void addMex(const Messaggio &nMex);

    int mexNonLetti() ;

    void leggiChat();

    int getChatDim() const;

    int getNotifiche() const;

    void setNotifiche(int notifiche);

    const std::string &getUtente1() const;

    const std::string &getUtente2() const;

    virtual void subscribe(std::shared_ptr<Observer> o) override;
    virtual void unsubscribe(std::shared_ptr<Observer> o) override;
    virtual void notify() override;


private:
    std::list<std::shared_ptr<Observer>> observers;
    std::vector<Messaggio> mex;
    std::string utente1;
    std::string utente2;
    int notifiche;
};


#endif //CHAT_CHAT_H
