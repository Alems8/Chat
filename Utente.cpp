//
// Created by alessio on 08/09/21.
//

#include "Utente.h"

const std::string &Utente::getNome() const {
    return nome;
}

Utente::Utente(std::string nome) {
    this->nome = nome;

}
