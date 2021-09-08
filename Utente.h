//
// Created by alessio on 08/09/21.
//

#ifndef CHAT_UTENTE_H
#define CHAT_UTENTE_H


#include <string>
#include "Chat.h"
#include <memory>
#include <map>

class Chat;
class Utente {
public:
    Utente(std::string nome);

    ~Utente();

    const std::string &getNome() const;

    std::shared_ptr<Chat> nuovaChat(Utente &u);

    void rimuoviChat(const Utente &u);

    void aggiungiChat(std::shared_ptr<Chat> c, Utente &u);


private:
    std::string nome;
    std::map <std::string, std::shared_ptr<Chat>> chats;
};


#endif //CHAT_UTENTE_H
