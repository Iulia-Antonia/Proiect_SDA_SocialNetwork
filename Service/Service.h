//
// Created by asus on 5/14/2022.
//

#ifndef PROIECT_SDA_SERVICE_H
#define PROIECT_SDA_SERVICE_H
#include "../Repository/RepositoryList.h"
#include "../Repository/RepositoryMultiMap.h"
#include "../Repository/ReposytoryFriendship.h"
#include "../Repository/RepositoryMessages.h"
#include "../Domain/User.h"
#include "../Domain/Friendship.h"
#include "../Domain/Message.h"

class Service{
private:
    RepositoryList<User> listUsers;
    RepoFriendship listFriendships;
    RepositoryMessages listMessages;
public:
    /// Constructor fara parametrii
    Service(){};
    /// Destructor
    ~Service(){};

    /// Gaseste un utilizator dat prin id
    /// \param id id-ul utilizatorului pe care dorim sa il gasim
    /// \return - un utilizator nou, fara date daca id-ul nu corespunde vreunui utilizator din memorie
    ///         - utilizatorul cautat in caz contrar
    User getUserById(int id){
        for(int i=0;i<listUsers.getSize();i++)
            if(listUsers.getElem(i).getId()==id)return listUsers.getElem(i);
        return User();
    }

    /// Gaseste numele unui utilizator dat prin id
    /// \param id id-ul utilizatorului cautat
    /// \return numele utilizatorului cautat
    string getUserNameById(int id){
        return getUserById(id).getName();
    }

    /// Construieste un utilizator pe baza parametrilor primiti si il adauga in memorie
    /// \param id id-ul noului utilizator
    /// \param name numele noului utilizator
    /// \param varsta varsta noului utilizator
    void addUser(int id, string name, int varsta){
        User user(id, name, varsta);
        listUsers.add(user);
    };

    /// Sterge un utilizator dat prin id
    /// \param id id-ul utilizatorului pe care dorim sa il stergem
    void deleteUser(int id){
        vector<int>valuesKey = listFriendships.getKeyElems(id);
        for(int i=0;i<valuesKey.size();i++){
            if(listFriendships.isFrienshipbetween(id, valuesKey[i]))
                deleteFrendship(id, valuesKey[i]);
        }
        for(int i=0;i<listUsers.getSize();i++){
            if(listUsers.getElem(i).getId()!=id){
                deleteConversation(id, listUsers.getElem(i).getId());
            }
        }
        for(int i=0;i<listUsers.getSize();i++){
            if(listUsers.getElem(i).getId() == id){
                listUsers.remove(listUsers.getElem(i));
            }
        }
    };

    /// Modifica un utilizator dat prin id
    /// \param idV id-ul utilizatorului ale carui date dorim sa le modificam (id-ul ramane nemodificat)
    /// \param nameN noul nume al utilizatorului
    /// \param varstaN noua varsta a utilizatorului
    void updateU(int idV, string nameN, int varstaN){
        User user(idV, nameN, varstaN);
        for(int i=0;i<listUsers.getSize();i++){
            if(listUsers.getElem(i).getId() == idV)
                listUsers.update(listUsers.getElem(i), user);
        }
    };

    /// Afiseaza o lista cu toti utilizatorii si datele lor
    void showUsers(){
        for(int i = 0; i< this->listUsers.getSize(); i++)
            cout<<this->listUsers.getElem(i).toString()<<endl;
    };

    /// Creeaza o prietenie intre doi utilizatori dati prin id si o salveaza in memorie
    /// \param id1 id-ul unuia din utilizatorii viitori prieteni
    /// \param id2 id-ul celuilalt utilizator viitor prieten
    void addFriendship(int id1, int id2){
        if(!listFriendships.isFrienshipbetween(id1,id2)) {
            Friendship friendship(getUserById(id1), getUserById(id2));
            listFriendships.addFriend(friendship);
        }
        else cout<<"Exista deja o prietenie intre cei 2!";
    };

    /// Creeaza o prietenie intre doi utilizatori dati prin id si o strege in memorie
    /// \param id1 id-ul unuia din utilizatori
    /// \param id2 id-ul celuilalt utilizator
    void deleteFrendship(int id1, int id2){
        Friendship friendship(getUserById(id1), getUserById(id2));
        listFriendships.removeFriend(friendship);
    };

    /// Afiseaza o lista cu toti prietenii unui utilizator dat prin id
    /// \param id id-ul utilizatorului pentru care vrem sa vedem prietenii
    void showFriendshipsAfterId(int id){
        vector<int> result = listFriendships.getKeyElems(id);
        cout<<getnameuserAfterID(id)<<": ";
        if(!result.empty()){
            for(int i=0;i<result.size()-1;i++){
                cout<<getnameuserAfterID(result[i])<<", ";
            }
            cout<<getnameuserAfterID(result[result.size()-1]);
        }
        cout<<endl;
    };

    /// Afiseaza o lista cu toti utilizatorii si cu toti prietenii fiecaruia
    void showAllFriendships(){
        vector<int>listaId;
        for(int i=0;i<listUsers.getSize();i++)
            listaId.push_back(listUsers.getElem(i).getId());
        if(listaId.size()!=0){
            for(int i=0;i<listaId.size();i++)
                showFriendshipsAfterId(listaId[i]);
        }
        else cout<<"Nu exista prietenii!"<<endl;
    };

    /// Sterge mesajele trimise de un utilizator, dintr-o anumita conversatie (cel care a trimis mesajele si cel care le-a primit sunt dati prin id)
    /// \param transmitterID id-ul celui care a trimis mesajele
    /// \param receiverID id-ul  celui care a primit mesajele
    void deleteMessage(int transmitterID, int receiverID){
        Friendship f(getUserById(transmitterID), getUserById(receiverID));
        vector<Message> messages = listMessages.getKeyElems(f);
        for(int i=0;i<messages.size();i++){
            if(messages[i].getTransmitter().getId() == transmitterID)
                listMessages.deleteMessageFromConversation(messages[i]);
        }
    };

    /// Sterge conversatia dintre doi utilizatori dati prin id
    /// \param id1 id-ul unuia dintre utilizatori
    /// \param id2 id-ul celuilalt utilizator
    void deleteConversation (int id1, int id2){
        deleteMessage(id1,id2);
        deleteMessage(id2,id1);
    };

    /// Afiseaza conversatia dintre doi utilizatori dati prin id
    /// \param id1 id-ul unuia dintre utilizatori
    /// \param id2 id-ul celuilalt utilizator
    void showConversation(int id1, int id2){
        Friendship f(getUserById(id1), getUserById(id2));
        vector<Message> messages = listMessages.getKeyElems(f);
        cout<<"Conversatia dintre "<<getUserById(id1).getName()<<" & "<<getUserById(id2).getName()<<endl;
        if(listMessages.existConversationBetweenUsers(f)){
            for(int i=messages.size()-1; i>=0;i--){
                cout<<messages[i].getTransmitter().getName()[0]<<": "<<messages[i].getMessage()<<endl;
            }
        }
    };

    /// Adauga un mesaj in memorie
    /// \param idTransmitter id-ul celui ce scrie mesajul
    /// \param idReceiver id-ul celui ce primeste mesajul
    /// \param message textul mesajului
    void addMessage(int idTransmitter, int idReceiver, string message){
        Message m(getUserById(idTransmitter), getUserById(idReceiver), message);
        listMessages.addMessageInConversation(m);
    };

    /// Verifica daca varsta citita e valida (e un numar si e un numar pozitiv)
    /// \param varsta parametrul primit pe care dorim sa il verificam
    /// \return true - daca varsta data e valida (e un numar si e un numar pozitiv)
    ///         false - in caz contrar
    bool validateVarsta(string varsta){
        if(isNumber(varsta) && stoi(varsta)>=0)return true;
        return false;
    };

    /// Verifica daca un id  exista deja il lista de utilizatori (id-ul trebuie sa fie unic)
    /// \param id id-ul de verificat
    /// \return true - daca id-ul dat nu corespunde vreunui utilizator din lista de utilizatori (daca nu apartine deja vreunui utilizator) si se poate converti in numar
    ///         false - in caz contrar
    bool validateIdUnic(string id){
        if(isNumber(id)){
            for(int i=0;i<listUsers.getSize();i++){
                if(listUsers.getElem(i).getId()== stoi(id))return false;
            }
            return true;
        }
        return false;
    };

    /// Verifica daca un id dat ca sir de caractere se poate converti in int si daca exista in memorie un utilizator cu id-ul respectiv
    /// \param id id-ul de verificat
    /// \return true - daca id-ul se poate converti in int si exista in lista de id-uri
    ///         false - daca id-ul nu se poate converti in int / nu exista in lista de id-uri
    bool validateId(string id){
        if(isNumber(id)) {
            for (int i = 0; i < listUsers.getSize(); i++)
                if (listUsers.getElem(i).getId() == stoi(id))return true;
            return false;
        }
        return false;
    };

    /// Verifica daca un sir de caractere se poate converti in numar
    /// \param s sirul de caractere
    /// \return true - daca s se poate converti in numar, false - daca nu poate fi transformat in numar
    bool isNumber(string &s){
        string::const_iterator it = s.begin();
        while (it != s.end() && isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    };

    /// Gaseste numele unui utilizator dat prin id (primeste un id valid)
    /// \param id id-ul utilizatorului caruia vrem sa ii aflam numele
    /// \return numele utilizatorului dat prin id
    string getnameuserAfterID(int id){
        for(int i=0;i<listUsers.getSize();i++)
            if(listUsers.getElem(i).getId()==id)return listUsers.getElem(i).getName();
        return "";
    };

    /// Afiseaza o lista cu numele si id-urile tuturor utilizatorilor existenti
    void userIdName(){
        for(int i=0;i<listUsers.getSize();i++)
            cout<<listUsers.getElem(i).getName()<<" cu id-ul "<<listUsers.getElem(i).getId()<<endl;
    }
};

#endif //PROIECT_SDA_SERVICE_H
