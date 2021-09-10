//
// Created by alessio on 10/09/21.
//

#include "NotificaMessaggio.h"

void NotificaMessaggio::attach() {
    std::shared_ptr<NotificaMessaggio> ptr = std::make_shared<NotificaMessaggio>(*this);
    subject->subscribe(ptr);
}

void NotificaMessaggio::detach() {
    std::shared_ptr<NotificaMessaggio> ptr = std::make_shared<NotificaMessaggio>(*this);
    subject->unsubscribe(ptr);
}

void NotificaMessaggio::update() {
    int i = subject->mexNonLetti();
    this->draw(i);
}

void NotificaMessaggio::draw(int i) {
    std::cout << "Hai " << i ;
    if(i==1)
        std::cout<<" messaggio non letto" << std::endl;
    else
        std::cout<<" messaggi non letti" << std::endl;
}


