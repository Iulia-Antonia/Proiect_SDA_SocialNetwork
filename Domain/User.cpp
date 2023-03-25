//
// Created by asus on 5/9/2022.
//

#include "User.h"
#include <cstring>
#include <iostream>
using namespace std;

User::User(){
    //name = nullptr;
    varsta = 0;
    id = -1;
}

User::User(int id,string name, int varsta){
    this->setId(id);
    this->setName(name);
    this->setVarsta(varsta);
}

User::User(const User& u){
    this->setId(u.id);
    this->setName(u.name);
    this->setVarsta(u.varsta);
}

User::~User(){
}

void User::setName(string name){
    this->name=name;
}

void User::setVarsta(const int varsta){
    this->varsta = varsta;
}

void User::setId(int id){
    this->id = id;
}

int User::getId() const{
    return this->id;
}

string User::getName() const{
    return this->name;
}

int User::getVarsta() const {
    return this->varsta;
}

bool User::operator==(const User &rhs) const {
    return name == rhs.name &&
           id == rhs.id &&
           varsta == rhs.varsta;
}

bool User::operator!=(const User &rhs) const {
    return !(rhs == *this);
}

User& User::operator=(const User& user){
    this->setName(user.name);
    this->setId(user.id);
    this->setVarsta(user.varsta);
    return *this;
}

string User::toString(){
    string s;
    s = s + to_string(this->id);
    s = s + " - ";
    s = s + this->name + " cu varsta ";
    s = s + to_string(this->varsta);
    return s;
}
