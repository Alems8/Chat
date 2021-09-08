#include <iostream>
#include "Chat.h"
#include "Messaggio.h"
#include "NotificaMessaggio.h"
#include "Utente.h"


int main() {
    Utente Alessio("Alessio");
    Utente Marco("Marco");
    std::shared_ptr<Chat> ptr = Alessio.nuovaChat(Marco);

    Messaggio m1("Alessio","Marco","Ciao, come va?");
    Messaggio m2("Marco","Alessio","Tutto bene, te?");
    Messaggio m3("Alessio","Marco","Bene, grazie.");

    ptr->addMex(m1);
    ptr->addMex(m2);
    ptr->addMex(m3);

    try{
        ptr->leggiMessaggi(1);
    } catch (std::out_of_range &e) {
        std::cerr << "Out of range" << e.what() << std::endl;

    }

}
