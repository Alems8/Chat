//
// Created by alessio on 10/09/21.
//

#include "gtest/gtest.h"
#include "../Messaggio.h"

class MexSuite : public ::testing::Test {

protected:
    virtual void setUp(){
        m->setMittente("Alessio");
        m->setDestinatario("Marco");
        m->setTesto("Ciao");
    }
    Messaggio *m = new Messaggio("","","");
};


TEST_F(MexSuite, BoolOperatorTest) {
    ASSERT_EQ(true,m->operator==(*m));
    ASSERT_EQ(false,m->operator!=(*m));
}


