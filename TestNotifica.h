//
// Created by alessio on 12/09/21.
//

#ifndef CHAT_TESTNOTIFICA_H
#define CHAT_TESTNOTIFICA_H

#include "Observer.h"
#include "Utente.h"
#include "Chat.h"
#include "Messaggio.h"


class TestNotifica : public Observer{
public:
    explicit TestNotifica(std::shared_ptr<Chat> sub) : subject(sub){}

    virtual void attach() override;

    virtual void detach() override;

    virtual void update() override;

    void setNotifica(int i);
    int getNotifica() const;

private:
    std::shared_ptr<Chat> subject;
    int notifica;


};


#endif //CHAT_TESTNOTIFICA_H
