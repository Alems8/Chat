#include <iostream>
#include "Chat.h"
#include "Messaggio.h"
#include "NotificaMessaggio.h"
#include "Utente.h"
#include "NuovoMessaggio.h"


int main() {
    Utente Alessio("Alessio");
    Utente Marco("Marco");
    std::shared_ptr<Chat> ptr = Alessio.nuovaChat(Marco);
    std::shared_ptr<Chat> ptr2 = Alessio.ricercaChat(Marco);

    Messaggio m1("Alessio","Marco","Ciao, come va?");
    Messaggio m2("Marco","Alessio","Tutto bene, te?");
    Messaggio m3("Alessio","Marco","Bene, grazie.");

    NuovoMessaggio nm(true,ptr);
    NotificaMessaggio notmex(ptr);

    nm.attach();
    notmex.attach();
    ptr2->addMex(m1);
    ptr->addMex(m2);
    ptr->addMex(m3);

    try{
        ptr->leggiMessaggi(1);
        ptr2->leggiMessaggi(5);
    } catch (std::out_of_range &e) {
        std::cerr << "Out of range " << e.what() << std::endl;

    }
    Alessio.rimuoviChat(Marco);
}
