//
// Created by asus on 5/16/2022.
//

#ifndef PROIECT_SDA_REPOSITORYMESSAGES_H
#define PROIECT_SDA_REPOSITORYMESSAGES_H
#include "RepositoryMultiMap.h"
#include "../Domain/Message.h"
#include "../Domain/User.h"
#include "../Domain/Friendship.h"

///RETINE ORDINEA (si mesajele) IN CARE SI-AU TRIMIS MESAJE DOI PRIETENI FALSI(nu exista o prietenie adevarata intre ei)

class RepositoryMessages: public RepositoryMultiMap<Friendship, Message>{
public:
    RepositoryMessages(): RepositoryMultiMap<Friendship, Message>(){};
    virtual ~RepositoryMessages(){};

    /// Adauga un mesaj in conversatia dintre doi useri
    /// \param msg mesajul de adaugat in conversatie
    void addMessageInConversation(Message msg){
        Friendship s(msg.getTransmitter(),msg.getReceiver());
        this->add(s, msg);
    }

    /// Sterge un mesaj din conversatia dintre doi useri
    /// \param msg mesajul de sters din conversatie
    void deleteMessageFromConversation(Message msg){
        Friendship s(msg.getTransmitter(),msg.getReceiver());
        this->removeValue(s, msg);
    }

    /// Verifica daa exista o conversatie (vreunn mesaj) intre doi utilizatori
    /// \param f prietenia (cei doi utilizatori)
    /// \return true - daca exista mesaje intre ei, false - in caz contrar
    bool existConversationBetweenUsers(Friendship f){
        vector<Message> messages = this->getKeyElems(f);
        if(messages.size()==0)return false;
        return true;
    }
};

#endif //PROIECT_SDA_REPOSITORYMESSAGES_H
