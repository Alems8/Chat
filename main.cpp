#include <iostream>
#include <memory>

#include "Chat.h"
#include "Messaggio.h"
#include "Utente.h"



int main() {
    Utente Alessio("Alessio");
    Utente Marco("Marco");
    Utente Lucia("Lucia");
    std::shared_ptr<Chat> ptr = Alessio.nuovaChatUtente(Marco);
    std::shared_ptr<Chat> ptr2 = Alessio.nuovaChatUtente(Lucia);


    Messaggio m1("Alessio","Marco","Ciao, come va?");
    Messaggio m2("Marco","Alessio","Tutto bene, te?");
    Messaggio m3("Alessio","Marco","Bene, grazie.");

    Messaggio m4("Alessio","Lucia","Ehi come va?");


    ptr->addMex(m1);
    ptr->addMex(m2);
    ptr->addMex(m3);
    ptr2->addMex(m4);

    try{
        ptr->leggiChat();
        ptr2->leggiChat();
        Alessio.cronologiaChat();
    } catch (std::out_of_range &e) {
        std::cerr << "Out of range " << e.what() << std::endl;

    }
    Alessio.rimuoviChat(Marco);
}
