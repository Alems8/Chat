//
// Created by alessio on 08/09/21.
//

#ifndef CHAT_NUOVOMESSAGGIO_H
#define CHAT_NUOVOMESSAGGIO_H

#include <memory>
#include <ctime>
#include <list>
#include <vector>
#include <iostream>

#include "Messaggio.h"
#include "Observer.h"
#include "Chat.h"

class NuovoMessaggio : public Observer {
public:
    explicit NuovoMessaggio(bool nc, std::shared_ptr<Chat> sub);
    virtual ~NuovoMessaggio();

    bool isNc() const;

    void setNc(bool nc);

    virtual void attach() override;

    virtual void detach() override;

    virtual void update() override;

    void draw(const Messaggio &mex);


private:
    bool nc;
    std::shared_ptr<Chat> subject;
};


#endif //CHAT_NUOVOMESSAGGIO_H
