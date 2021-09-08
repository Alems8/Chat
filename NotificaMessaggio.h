//
// Created by alessio on 08/09/21.
//

#ifndef CHAT_NOTIFICAMESSAGGIO_H
#define CHAT_NOTIFICAMESSAGGIO_H


#include <memory>
#include "Chat.h"
#include "Observer.h"
#include "Subject.h"

class NotificaMessaggio : public Observer{
public:
    explicit NotificaMessaggio(std::shared_ptr<Chat> sub);

    virtual void attach() override;
    virtual void detach() override;
    virtual void update() override;

    void draw(int i);
private:
    std::shared_ptr<Chat> subject;
};


#endif //CHAT_NOTIFICAMESSAGGIO_H
