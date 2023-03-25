//
// Created by asus on 5/16/2022.
//

#ifndef PROIECT_SDA_REPOSYTORYFRIENDSHIP_H
#define PROIECT_SDA_REPOSYTORYFRIENDSHIP_H
#include "RepositoryMultiMap.h"
#include "../Domain/User.h"
#include "../Domain/Friendship.h"

class RepoFriendship: public RepositoryMultiMap<int, int>{
public:
    /// Constructor fara parametrii
    RepoFriendship():RepositoryMultiMap<int, int>(){};
    /// Destructor
    virtual ~RepoFriendship(){};

    /// Adauga o prietenie in memorie
    /// \param friendship prietenia pe care dorim sa o adaugam
    void addFriend(Friendship friendship){
        this->add(friendship.getPrieten1().getId(), friendship.getPrieten2().getId());
        this->add(friendship.getPrieten2().getId(), friendship.getPrieten1().getId());
    }

    /// Sterge o prietenie din memorie
    /// \param friendship prietenia pe care dorim sa o stergem
    void removeFriend(Friendship friendship){
        this->removeValue(friendship.getPrieten1().getId(), friendship.getPrieten2().getId());
        this->removeValue(friendship.getPrieten2().getId(), friendship.getPrieten1().getId());
    }

    /// Verifica daca exista o prietenie intre doi utilizatori dati prin id-uri
    /// \param id1 id-ul unuia dintre posibilii prieteni
    /// \param id2 id-ul celuilalt posibil prieten
    /// \return true - daca exista prietenie intre cei doi, false - in caz contrar
    bool isFrienshipbetween(int id1, int id2){
        vector<int> valoriKey = getKeyElems(id1);
        for(int i=0;i<valoriKey.size();i++)
            if(valoriKey[i]==id2)return true;
        return false;
    }

};

#endif //PROIECT_SDA_REPOSYTORYFRIENDSHIP_H
