//
// Created by alessio on 10/09/21.
//

#include "gtest/gtest.h"
#include "../Messaggio.h"

TEST(Mex,Costruttore){
    Messaggio m("Alberto","Francesco","Oggi");

    ASSERT_EQ("Alberto",m.getMittente());
    ASSERT_EQ("Francesco",m.getDestinatario());
    ASSERT_EQ("Oggi",m.getTesto());
    ASSERT_EQ(false,m.isVisualizzato());

}