//
// Created by alessio on 10/09/21.
//

#include "gtest/gtest.h"
#include "../Chat.h"
#include "../Utente.h"
#include "../Messaggio.h"

class ChatSuite : public ::testing::Test {

protected:
protected:
    virtual void TearDown() {
        delete m;
        delete u1;
        delete u2;
    }

    virtual void SetUp() {
        u1 = new Utente("Alessio");
        u2 = new Utente("Marco");
        u3 = new Utente("Lucia");
        m = new Messaggio("Alessio","Marco","Questo è un test");
        c = u1->nuovaChatUtente(*u2);
        c2 = u1->nuovaChatUtente(*u3);
    }
    std::shared_ptr<Chat> c,c2;
    Messaggio *m;
    Utente *u1;
    Utente *u2;
    Utente *u3;

};


TEST_F(ChatSuite, aggiuntaMessaggio) {
    c->addMex(*m);
    ASSERT_EQ(1,c->getChatDim());
}


TEST_F(ChatSuite, costruttore){
    ASSERT_EQ("Alessio",c->getUtente1());
    ASSERT_EQ("Marco",c->getUtente2());
}

TEST_F(ChatSuite, modificheChat){
    ASSERT_EQ(2,u1->getNumeroChats());

    u1->rimuoviChat(*u2);
    ASSERT_EQ(1,u1->getNumeroChats());
}

TEST_F(ChatSuite, chatSbagliata){

    EXPECT_THROW(c2->addMex(*m),std::out_of_range);
}
