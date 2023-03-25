//
// Created by asus on 5/16/2022.
//

#include "Message.h"

Message::Message(){}
Message::Message(User transmitter, User receiver, string message){
    this->transmitter = transmitter;
    this->receiver = receiver;
    this->message = message;
}
Message::Message(const Message &mesaj){
    this->transmitter = mesaj.transmitter;
    this->receiver = mesaj.receiver;
    this->message = mesaj.message;
}
Message::~Message(){}

const User &Message::getTransmitter() const {
    return transmitter;
}
void Message::setTransmitter(const User &transmitter) {
    Message::transmitter = transmitter;
}

const User &Message::getReceiver() const {
    return receiver;
}
void Message::setReceiver(const User &receiver) {
    Message::receiver = receiver;
}

const string &Message::getMessage() const {
    return message;
}
void Message::setMessage(const string &message) {
    Message::message = message;
}

Message& Message::operator=(const Message& mesaj){
    this->setTransmitter(mesaj.transmitter);
    this->setReceiver(mesaj.receiver);
    this->setMessage(mesaj.message);
    return *this;
}
bool Message::operator==(const Message &rhs) const {
    return transmitter == rhs.transmitter &&
           receiver == rhs.receiver &&
           message == rhs.message;
}
bool Message::operator!=(const Message &rhs) const {
    return !(rhs == *this);
}
