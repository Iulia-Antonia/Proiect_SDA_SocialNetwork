//
// Created by asus on 5/16/2022.
//

#ifndef PROIECT_SDA_MESSAGE_H
#define PROIECT_SDA_MESSAGE_H
#include "User.h"
#include <vector>


class Message {
private:
    User transmitter;
    User receiver;
    string message;
public:
    /// Constructor fara parametrii
    Message();


    /// Constructor cu parametrii
    /// \param transmitter cel care transmite noul mesaj
    /// \param receiver cel care primeste mesajul
    /// \param message textul mesajului
    Message(User transmitter, User receiver, string message);


    /// Constructor care adauga inca un mesaj conversatiei dintre emitatorul si receptrul actual
    /// \param mesaj textul mesajului
    Message(const Message &mesaj);


    /// Destructorul
    ~Message();


    /// Getteri si setteri pentru cel care transmite mesaul
    const User &getTransmitter() const;
    void setTransmitter(const User &transmitter);


    /// Getteri si setteri pentru cel care primeste mesajul
    const User &getReceiver() const;
    void setReceiver(const User &receiver);


    /// Getteri si stteri pentru textul mesajului
    const string &getMessage() const;
    void setMessage(const string &message);


    /// Suprascriere operatorul =
    Message& operator=(const Message& mesaj);


    /// Suprascriere operatorul ==
    bool operator==(const Message &rhs) const;


    /// Suprascriere operatorul !=
    bool operator!=(const Message &rhs) const;
};


#endif //PROIECT_SDA_MESSAGE_H
