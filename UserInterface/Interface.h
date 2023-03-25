//
// Created by asus on 5/9/2022.
//

#ifndef PROIECT_SDA_INTERFACE_H
#define PROIECT_SDA_INTERFACE_H
#include "../TAD/List.h"
#include "../Domain/User.h"
#include "../Service/Service.h"


class Interface {
private:
    Service service;
public:
    Interface();
    virtual ~Interface();
    void runMenu();
private:
    /// Citeste datele pentru un utilizator
    /// \param id id-ul noului utilizator
    /// \param name numele noului utilizator
    /// \param varsta varsta noului utilizator
    void citireUser(string& id, string &name, string &varsta);
    /// Adauga un utilizator
    /// \param id id-ul noului utilizator
    /// \param name numele noului utilizator
    /// \param varsta varsta noului utilizator
    void addUser(string id, string name, string varsta);
    /// Afiseaza o lista cu toti utilizatorii
    void listUsers();
    /// Sterge un utilizator
    void deleteUser();
    /// Modifica un utilizator existent
    void updateUser();

    /// Citeste datele si adauga o prietenie
    void addFriendship();
    /// Citeste datele si sterge o prietenie
    void delFriendship();
    /// Afiseaza lista de prieteni pentru un utilizator dat pri id(citeste id-ul)
    void showFriendshipById();
    /// Afiseaza pentru toti utilizatorii preteniile
    void showAllFriendships();

    /// Sterge mesajele trimise de un utilizator dintr-o conversatie
    void deleteMessage();
    /// Sterge o conversatie
    void deleteConversation();
    /// Afiseaza conversatia dintre doi utilizatori
    void showConversation();
    /// Citeste datele si adauga un mesaj
    void writeMessage();

    /// Importa entitatile (citeste din fisiere utilizatori, prietenii, mesaje) din fisiere
    void importEntities();
    /// Apeleaza toate testele
    void tests();
};


#endif //PROIECT_SDA_INTERFACE_H
