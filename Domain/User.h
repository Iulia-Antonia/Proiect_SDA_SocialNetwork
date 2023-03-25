//
// Created by asus on 5/9/2022.
//

#ifndef PROIECT_SDA_USER_H
#define PROIECT_SDA_USER_H
#include "../TAD/List.h"
#include <string>
using namespace std;

class User {
private:
    int id;
    string name;
    int varsta;

    void setId(int id);
public:
    /// Constructor fara parametrii
    User();


    /// Constructor cu parametrii
    /// \param id id-ul pentru noul utilizator
    /// \param nume numele noului utilizator
    /// \param varsta varsta noului utilizator
    User(int id,string nume, int varsta);


    /// Constructor de copiere
    User(const User& u);


    /// Destructor
    ~User();


    /// Setteri pentru nume si varsta, nu si pentru id, care nu se poate modifica
    void setName(string name);
    void setVarsta(const int varsta);


    /// Getteri pentru id, nume, varsta
    int getId() const;
    string getName() const;
    int getVarsta() const;


    /// Suprascriere operatorul ==
    bool operator==(const User &rhs) const;


    /// Suprascriere operatorul !=
    bool operator!=(const User &rhs) const;


    /// Suprascriere operatorul =
    User& operator=(const User& user);


    /// Transforma obiectul intr-un string
    /// \return stringul cu informatiile despre obiect
    string toString();
};


#endif //PROIECT_SDA_USER_H
