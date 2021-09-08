//
// Created by alessio on 08/09/21.
//

#include "NuovoMessaggio.h"

bool NuovoMessaggio::isNc() const {
    return nc;
}

void NuovoMessaggio::setNc(bool nc) {
    NuovoMessaggio::nc = nc;
}

NuovoMessaggio::NuovoMessaggio(bool nc, std::shared_ptr<Chat> sub) : nc(nc), subject(sub){}

NuovoMessaggio::~NuovoMessaggio() {}

void NuovoMessaggio::attach() {
    std::shared_ptr<NuovoMessaggio> ptr = std::make_shared<NuovoMessaggio>(*this);
    subject->subscribe(ptr);
}

void NuovoMessaggio::detach() {
    std::shared_ptr<NuovoMessaggio> ptr = std::make_shared<NuovoMessaggio>(*this);
    subject->unsubscribe(ptr);
}

void NuovoMessaggio::update() {
    if (nc)
        this->draw(subject->ultimoMex());
}

void NuovoMessaggio::draw(const Messaggio &mex) {
    char buffer [80];
    time_t  ora = mex.getOrario();
    struct tm *lt = localtime(&ora);
    strftime(buffer,80,"%I:%M%p",lt);
    std::cout <<"Notifica: " << std::endl;
    std::cout << "Ultimo messaggio inviato alle " << buffer << " da: " << mex.getMittente() << " a " <<mex.getDestinatario()
                << mex.getTesto() << std::endl;

}
