//
// Created by alessio on 08/09/21.
//

#ifndef CHAT_UTENTE_H
#define CHAT_UTENTE_H


#include <string>

class Utente {
public:
    Utente(std::string nome);

    const std::string &getNome() const;


private:std::string nome;

};


#endif //CHAT_UTENTE_H
