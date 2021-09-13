//
// Created by alessio on 10/09/21.
//

#include "gtest/gtest.h"
#include "../Chat.h"
#include "../Utente.h"
#include "../Messaggio.h"
#include "../NotificaMessaggio.h"
#include "../TestNotifica.h"

class NotificaSuite : public ::testing::Test {
protected:
    Utente *u1 = new Utente("Alessio");
    Utente *u2 = new Utente("Marco");

    std::shared_ptr<Chat> c = u1->nuovaChatUtente(*u2);
    NotificaMessaggio *nm = new NotificaMessaggio(c);
    TestNotifica *tn = new TestNotifica(c);

    Messaggio *m1 = new Messaggio("Alessio","Marco","1");
    Messaggio *m2 = new Messaggio("Marco","Alessio","2");
    Messaggio *m3 = new Messaggio("Alessio","Marco","3");
    Messaggio *m4 = new Messaggio("Marco","Alessio","4");
    Messaggio *m5 = new Messaggio("Alessio","Marco","5");
    Messaggio *m6 = new Messaggio("Marco","Alessio","6");
    Messaggio *m7 = new Messaggio("Alessio","Marco","7");
};

TEST_F(NotificaSuite, MessaggiDaLeggere){
    nm->attach();
    tn->attach();
    c->addMex(*m1);
    c->addMex(*m2);
    c->addMex(*m3);
    c->addMex(*m4);
    ASSERT_EQ(2,c->getNotifica());
    c->leggiChat();
    ASSERT_EQ(0,c->getNotifica());
    c->addMex(*m5);
    c->addMex(*m6);
    c->addMex(*m7);
    ASSERT_EQ(1,c->getNotifica());

}
