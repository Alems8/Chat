//
// Created by alessio on 10/09/21.
//

#ifndef CHAT_NOTIFICAMESSAGGIO_H
#define CHAT_NOTIFICAMESSAGGIO_H


#include "Observer.h"
#include "Utente.h"
#include "Chat.h"
#include "Messaggio.h"

class NotificaMessaggio : public Observer{
public:
    explicit NotificaMessaggio(std::shared_ptr<Chat> sub) : subject(sub){}

    ~NotificaMessaggio(){}

    virtual void attach() override;

    virtual void detach() override;

    virtual void update() override;

    void draw(int i);

private:
    std::shared_ptr<Chat> subject;
};


#endif //CHAT_NOTIFICAMESSAGGIO_H
