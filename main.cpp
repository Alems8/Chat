#include <iostream>
#include <memory>
#include <unistd.h>

#include "Chat.h"
#include "Messaggio.h"
#include "Utente.h"
#include "NotificaMessaggio.h"


int main() {
    Utente Alessio("Alessio");
    Utente Marco("Marco");
    Utente Lucia("Lucia");
    std::shared_ptr<Chat> ptr = Alessio.nuovaChatUtente(Marco);
    std::shared_ptr<Chat> ptr2 = Alessio.nuovaChatUtente(Lucia);
    std::shared_ptr<Chat> ptr3 = Marco.nuovaChatUtente(Lucia);


    Messaggio m1("Alessio","Marco","Ciao, come va?");
    Messaggio m2("Marco","Alessio","Tutto bene, te?");
    Messaggio m3("Alessio","Marco","Bene, grazie.");

    Messaggio m4("Alessio","Lucia","Ehi come va?");

    Messaggio m5("Marco","Lucia","Ciao, che fai stasera?");
    Messaggio m6("Lucia","Marco","Niente di che. Usciamo insieme?");
    Messaggio m7("Marco","Lucia","Va bene. A dopo");
    NotificaMessaggio nm(ptr);
    nm.attach();
    ptr->addMex(m1);

    ptr2->addMex(m4);

/*    sleep(10);*/

    ptr->addMex(m2);
    ptr3->addMex(m5);

/*    sleep(20);*/

    ptr3->addMex(m6);
    ptr->addMex(m3);
    ptr3->addMex(m7);
    try{
        ptr->leggiChat();
        ptr2->leggiChat();
        ptr3->leggiChat();

        Alessio.cronologiaChat();
        Marco.cronologiaChat();
    } catch (std::out_of_range &e) {
        std::cerr << "Out of range " << e.what() << std::endl;

    }
    Alessio.rimuoviChat(Marco);
    nm.detach();
    Alessio.rimuoviChat(Lucia);
    Marco.rimuoviChat(Lucia);
}
