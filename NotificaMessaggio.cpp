//
// Created by alessio on 08/09/21.
//

#include <iostream>
#include "NotificaMessaggio.h"

NotificaMessaggio::NotificaMessaggio(std::shared_ptr<Chat> sub) {
    this->subject = sub;

}

void NotificaMessaggio::attach() {
    auto ptr = std::make_shared<NotificaMessaggio>(*this);
    subject->subscribe(ptr);
}

void NotificaMessaggio::detach() {
    auto ptr = std::make_shared<NotificaMessaggio>(*this);
    subject->subscribe(ptr);

}

void NotificaMessaggio::update() {
    this->draw(subject->mexNonLetti());
}

void NotificaMessaggio::draw(int i) {
    std::cout << "Messaggi non letti: " << i << std::endl;
}

NotificaMessaggio::~NotificaMessaggio() {

}
