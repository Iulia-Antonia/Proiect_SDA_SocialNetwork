//
// Created by asus on 5/9/2022.
//

#ifndef PROIECT_SDA_NodeLSILSI_H
#define PROIECT_SDA_NodeLSILSI_H

template <typename T>
class List;

template <class T>
class Node {
private:
    T info;
    Node<T>* next;
public:
    /// Constructorii si destructorul pentru noduri
    Node(){ next = nullptr;};
    Node(T info, Node<T>* next) : info(info), next(next){}
    Node(T info) : info(info){ next= nullptr;}
    ~Node(){
    };
    Node(const Node &n) {
        this->info=n.info;
        this->next = n.next;
    };

    /// Suprascriere operatorul ==
    bool operator==(const Node &rhs) const {
        return info == rhs.info &&
               next == rhs.next;
    }
    /// Suprascriere operatorul !=
    bool operator!=(const Node &rhs) const {
        return !(rhs == *this);
    }

    friend class List<T>;
};


#endif //PROIECT_SDA_NodeLSILSI_H
