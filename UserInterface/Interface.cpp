//
// Created by asus on 5/9/2022.
//

#include "Interface.h"
#include "../Tests/TestsTAD.h"
#include "../Tests/TestsDomain.h"
#include "../Tests/TestsRepo.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

Interface::Interface(){}
Interface::~Interface() {};

/// Afiseaza obtiunile posibile
void showMenu(){
    cout<<endl<<"RETEA DE SOCIALIZARE"<<endl;
    cout<<"addU - Adauga un nou utilizator"<<endl;
    cout<<"showU - Vezi toti utilizatorii"<<endl;
    cout<<"delU - sterge un utilizator dat prin ID"<<endl;
    cout<<"updateU - modifica un utilizator dat prin ID"<<endl;
    cout<<"addF - adauga prietenie"<<endl;
    cout<<"delF - sterge prietenie"<<endl;
    cout<<"showF - arata toti prietenii unui utilizator dat prin id"<<endl;
    cout<<"showaF - Vezi toate preieteniile"<<endl;
    cout<<"delM - sterge toate mesajele trimise de un utilizator catre un alt utilisator"<<endl;
    cout<<"delC - sterge o conversatie dintre doi utilizatori"<<endl;
    cout<<"showC - afiseaza o conversatie dintre doi utilizatori"<<endl;
    cout<<"addM - Scrie un mesaj"<<endl;
    cout<<"x - iesire"<<endl;
    cout<<"Obtiunea aleasa: ";
}

void Interface::runMenu(){
    try {
        Interface::importEntities();
        Interface::tests();

        bool go = true;
        while (go) {
            showMenu();
            string choice;
            getline(cin, choice);
            string name, id, varsta;
            if (choice == "addU") {
                Interface::citireUser(id, name, varsta);
                Interface::addUser(id, name, varsta);
                continue;
            }
            if (choice == "showU") {
                Interface::listUsers();
                continue;
            }
            if (choice == "delU") {
                Interface::deleteUser();
                continue;
            }
            if (choice == "updateU") {
                Interface::updateUser();
                continue;
            }
            if (choice == "addF") {
                Interface::addFriendship();
                continue;
            }
            if (choice == "delF") {
                Interface::delFriendship();
                continue;
            }
            if (choice == "showF") {
                Interface::showFriendshipById();
                continue;
            }
            if (choice == "showaF") {
                Interface::showAllFriendships();
                continue;
            }
            if (choice == "delM") {
                Interface::deleteMessage();
                continue;
            }
            if (choice == "delC") {
                Interface::deleteConversation();
                continue;
            }
            if (choice == "showC") {
                Interface::showConversation();
                continue;
            }
            if (choice == "addM") {
                Interface::writeMessage();
                continue;
            }
            if (choice == "x") {
                go = false;
                continue;
            }
            cout << "Obtiune invalida! Mai incearca!" << endl;
        }
    }
    catch (...){
        cout<<"Eroare!";
    }
}

void Interface::citireUser(string& id, string &name, string &varsta){
    cout<<"Dati id-ul noului utilizator: ";
    getline(cin,id);
    cout<<"Dati numele noului utilizator: ";
    getline(cin,name);
    cout<<"Dati varsta noului utilizator: ";
    getline(cin,varsta);
}

void Interface::addUser(string id, string name, string varsta){
    if(service.validateIdUnic(id) && service.validateVarsta(varsta)) {
        service.addUser(stoi(id), name, stoi(varsta));
    }
    else{
        if(!service.validateIdUnic(id))cout<<"Id-ul dat exista deja sau e invalid!"<<endl;
        if(!service.validateVarsta(varsta))cout<<"Varsta trebuie sa fie un numar mai mare sau egal cu 0!"<< endl;
    }
}

void Interface::listUsers(){
    cout<<"Utilizatorii sunt:"<<endl;
    service.showUsers();
}

void Interface::deleteUser(){
    string id;
    cout << "Dati id-ul utilizatorului pe care doriti sa il stergeti: ";
    getline(cin,id);
    if(service.validateId(id)) {
        service.deleteUser(stoi(id));
    }
    else cout<<"Id invalid!"<<endl;
}

void Interface::updateUser() {
    string idV, varstaN;
    string nameN;
    cout<<"Dati id-ul Userului pe care doriti sa il modificati: ";
    getline(cin,idV);
    cout<<"Dati numele nou: ";
    getline(cin,nameN);
    cout<<"Dati varsta noua: ";
    getline(cin,varstaN);
    if(service.validateId(idV) && service.validateVarsta(varstaN))
        service.updateU(stoi(idV), nameN, stoi(varstaN));
    else {
        if (!service.validateId(idV)) cout << "Id invalid!" << endl;
        if (!service.validateVarsta(varstaN))cout << "Varsta trebuie sa fie un numar mai mare sau egal cu 0!" << endl;
    }
}


void Interface::addFriendship(){
    service.userIdName();
    string id1, id2;
    cout<<endl<<"Dati id-ul primului user prieten: ";
    getline(cin, id1);
    cout<<"Dati id-ul celui de-al doilea user prieten: ";
    getline(cin,id2);
    if(service.validateId(id1) && service.validateId(id2))
        service.addFriendship(stoi(id1), stoi(id2));
    else cout<<"Id-urile nu sunt valide!"<<endl;
}

void Interface::delFriendship(){
    service.userIdName();
    string id1, id2;
    cout<<"Dati prietenia(id-urile celor 2 prieteni): ";
    cout<<endl<<"Id-ul prietenului 1: ";
    getline(cin,id1);
    cout<<"Id-ul prietenului 2: ";
    getline(cin,id2);
    if(service.validateId(id1) && service.validateId(id2))
        service.deleteFrendship(stoi(id1),stoi(id2));
    else cout<<"Id-urile nu sunt valide!"<<endl;
}

void Interface::showFriendshipById() {
    service.userIdName();
    string id;
    cout<<"Dati id-ul utilizatorului caruia doriti sa ii vedeti prietenii: ";
    getline(cin, id);
    if(service.validateId(id))
        service.showFriendshipsAfterId(stoi(id));
    else cout<<"Id-ul nu e valid!"<<endl;
}

void Interface::showAllFriendships() {
    service.showAllFriendships();
}


void Interface::deleteMessage(){
    string transmitterId, receiverId;
    service.userIdName();
    cout<<"Dati id-ul persoanei care a trimis mesajele pe care doriti sa le stergeti: ";
    getline(cin, transmitterId);
    cout<<"Dati id-ul persoanei care a primit acele mesaje: ";
    getline(cin, receiverId);
    if(service.validateId(transmitterId) && service.validateId(receiverId))
        service.deleteMessage(stoi(transmitterId),stoi(receiverId));
    else cout<<"Id-urile nu sunt valide!"<<endl;
}

void Interface::deleteConversation(){
    string id1, id2;
    service.userIdName();
    cout<<"Dati id-ul unuia dintre utilizatori: ";
    getline(cin, id1);
    cout<<"dati id-ul celuilalt utilizator: ";
    getline(cin, id2);
    if(service.validateId(id1) && service.validateId(id2))
        service.deleteConversation(stoi(id1), stoi(id2));
    else cout<<"Id-urile nu sunt valide!"<<endl;
}

void Interface::showConversation(){
    string id1, id2;
    service.userIdName();
    cout<<"Dati id-ul unuia dintre utilizatori: ";
    getline(cin, id1);
    cout<<"dati id-ul celuilalt utilizator: ";
    getline(cin, id2);
    if(service.validateId(id1) && service.validateId(id2))
        service.showConversation(stoi(id1), stoi(id2));
    else cout<<"Id-urile nu sunt valide!"<<endl;
}

void Interface::writeMessage() {
    string mesaj, transmitter, receiver;
    service.userIdName();
    cout<<"Dati id-ul persoanei care trimite mesajul: ";
    getline(cin, transmitter);
    cout<<"Dati id-ul persoanei care primeste mesajul: ";
    getline(cin,receiver);
    cout<<"Dati mesajul: ";
    getline(cin,mesaj);
    if(service.validateId(transmitter) && service.validateId(receiver))
        service.addMessage(stoi(transmitter), stoi(receiver),mesaj);
    else cout<<"Id-urile nu sunt valide!"<<endl;
}


void Interface::importEntities(){
    ifstream fu("users.txt");
    ifstream ff("friendships.txt");
    ifstream fm("messages.txt");
    int id1,id2;
    int id, varsta;
    string name, mesaj;
    while(fu>>id){
        fu>>name>>varsta;
        service.addUser(id, name,varsta);
    }
    while(ff>>id1){
        ff>>id2;
        service.addFriendship(id1,id2);
    }
    while(fm>>id1){
        fm>>id2;
        getline(fm, mesaj);
        service.addMessage(id1,id2,mesaj);
    }
}

void Interface::tests() {
    testsDomain();
    testsTAD();
    testsRepo();
    cout<<"Testele au rulat cu succes!";
}
