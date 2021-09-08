//
// Created by alessio on 08/09/21.
//

#ifndef CHAT_MESSAGGIO_H
#define CHAT_MESSAGGIO_H


#include <string>
#include <ctime>

class Messaggio {
public:
    Messaggio(std::string mitt, std::string r, std::string mes, bool visualizzato = false);

    const std::string &getMittente() const;

    void setMittente(const std::string &mittente);

    const std::string &getDestinatario() const;

    void setDestinatario(const std::string &destinatario);

    const std::string &getTesto() const;

    void setTesto(const std::string &testo);

    bool isVisualizzato() const;

    void setVisualizzato(bool visualizzato);

    time_t getOrario() const;

    void setOrario(time_t orario);

    bool operator==(const Messaggio &mdm) const;
    bool operator!=(const Messaggio &mdm) const;

private:
    std::string mittente;
    std::string destinatario;
    std::string testo;
    bool visualizzato;
    time_t orario;

};


#endif //CHAT_MESSAGGIO_H
