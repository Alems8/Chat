//
// Created by alessio on 08/09/21.
//


#include "NotificaMessaggio.h"

NotificaMessaggio::NotificaMessaggio(std::shared_ptr<Chat> sub) : subject(sub) {}

void NotificaMessaggio::attach() {
    std::shared_ptr<NotificaMessaggio> ptr = std::make_shared<NotificaMessaggio>(*this);
    subject->subscribe(ptr);
}

void NotificaMessaggio::detach() {
    std::shared_ptr<NotificaMessaggio> ptr = std::make_shared<NotificaMessaggio>(*this);
    subject->unsubscribe(ptr);

}

void NotificaMessaggio::update() {
    this->draw(subject->mexNonLetti());
}

void NotificaMessaggio::draw(int i) {
    std::cout << "Messaggi non letti: " << i << std::endl;
}

NotificaMessaggio::~NotificaMessaggio() {

}
