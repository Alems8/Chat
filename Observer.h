//
// Created by alessio on 08/09/21.
//

#ifndef CHAT_OBSERVER_H
#define CHAT_OBSERVER_H

class Observer{
public:
    virtual ~Observer() = default;

    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual void update() = 0;
};


#endif //CHAT_OBSERVER_H
