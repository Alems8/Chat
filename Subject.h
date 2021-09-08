//
// Created by alessio on 08/09/21.
//

#ifndef CHAT_SUBJECT_H
#define CHAT_SUBJECT_H
#include "Observer.h"

class Subject {
public:
    virtual ~Subject(){}
    virtual void subscrib(std::shared_ptr<Observer> observer) = 0;
    virtual void unsubscribe(std::shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
};


#endif //CHAT_SUBJECT_H
