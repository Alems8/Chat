//
// Created by alessio on 12/09/21.
//

#include "TestNotifica.h"

void TestNotifica::attach() {
    std::shared_ptr<TestNotifica> ptr = std::make_shared<TestNotifica>(*this);
    subject->subscribe(ptr);
}

void TestNotifica::detach() {
    std::shared_ptr<TestNotifica> ptr = std::make_shared<TestNotifica>(*this);
    subject->unsubscribe(ptr);
}

void TestNotifica::update() {
    int i = subject->mexNonLetti();
    setNotifica(i);
}

void TestNotifica::setNotifica(int i) {
    notifica = i;
}

int TestNotifica::getNotifica() const {
    return notifica;
}


