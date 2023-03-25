//
// Created by asus on 5/14/2022.
//

#include "Friendship.h"

Friendship::Friendship(){

}
Friendship::Friendship(User prieten1, User prieten2){
    this->prieten1 = prieten1;
    this->prieten2 = prieten2;
}
Friendship::Friendship(const Friendship &friendship){
    this->setPrieten1(friendship.prieten1);
    this->setPrieten2(friendship.prieten2);
}
Friendship::~Friendship() {

}


const User &Friendship::getPrieten1() const {
    return prieten1;
}
void Friendship::setPrieten1(const User &prieten1) {
    Friendship::prieten1 = prieten1;
}

const User &Friendship::getPrieten2() const {
    return prieten2;
}
void Friendship::setPrieten2(const User &prieten2) {
    Friendship::prieten2 = prieten2;
}


bool Friendship::operator==(const Friendship &rhs) const {
    return (prieten1 == rhs.prieten1 && prieten2 == rhs.prieten2) ||
    (prieten1 == rhs.prieten2 && prieten2 == rhs.prieten1);
}
bool Friendship::operator!=(const Friendship &rhs) const {
    return !(rhs == *this);
}
Friendship& Friendship::operator=(Friendship &friendship){
    this->setPrieten1(friendship.getPrieten1());
    this->setPrieten2(friendship.getPrieten2());
    return *this;
}
