//
// Created by asus on 5/9/2022.
//

#ifndef PROIECT_SDA_ListSI_H
#define PROIECT_SDA_ListSI_H

#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class List {
private:
    Node<T>* head;
public:
    /// Constructor fara parametrii
    List(){ head = nullptr;}
    /// Constructor cu parametrii
    List(Node<T> *head) : head(head) {}
    /// Destructor
    virtual ~List() {}

    /// Adauga un element in lista
    /// \param elem elementul de adaugat in lista
    void add(T elem){
        if (head==nullptr)
        {
            head=new Node<T>(elem);
        }
        else
        {
            Node<T>* p=head;
            while (p->next!=nullptr) p=p->next;
            p->next=new Node<T>(elem);
        }
    }

    /// Modifica (schimba) un element din lista
    /// \param oldElem elementul pe care dorim sa il modificam
    /// \param newElem elementul nou
    void update(T oldElem, T newElem){
        int poz = this->search(oldElem);
        if(poz!=-1){
            Node<T>* p = head;
            while(p->next!= nullptr){
                if(p->info == oldElem)p->info = newElem;
                p = p->next;
            }
            if(p->info == oldElem)p->info = newElem;
        }
    }

    /// Sterge un element din lista
    /// \param e elementul pe care dorim sa il stergem
    void remove(T e){
        Node<T> *NodeToDelete = nullptr;

        if (head!= nullptr) { // if the List is not empty
            if (head->info == e) {
                NodeToDelete = head;
                head = head->next; //head points to the next Node
            }
            else {
                Node<T> *p= head->next;
                Node <T> *q=head;
                while (p!= nullptr)
                    if (p->info == e) {
                        NodeToDelete = p;
                        p= nullptr;
                    } else {
                        p = p->next;
                        q = q->next;
                    }
                if (NodeToDelete != nullptr)
                    q->next= NodeToDelete->next;
            }
        }
        if (NodeToDelete != nullptr) { // if the elem e was found
            delete NodeToDelete;
        }
    }

    /// Cauta un element in lista
    /// \param elem elementul pe care il cautam
    /// \return pozitia primului element din lista, egal cu elem sau -1 daca elementul nu este in lista
    int search(T elem){
        int poz = 0;
        Node<T>* p = head;
        while(p->next && p->info != elem){
            poz++;
            p = p->next;
        }
        if(p->info == elem)return poz;
        else
            return -1;
    }

    /// Ia din lista un elemet dat prin pozitia sa
    /// \param index pozitia elementului pe care il dorim
    /// \return elementul de pe pozitia data
    T get(int index){
        int poz = 0;
        Node<T>* p = head;
        while(poz<index && p->next){
            p = p->next;
            poz++;
        }
        if(poz!=index)return T();
        else
            return p->info;
    }

    /// Afla cate elemente sunt in lista
    /// \return numarul de elemente din lista
    int size(){
        int nr=0;
        Node<T>*p = head;
        if(head == nullptr) return 0;
        while(p->next){
            p = p->next;
            nr++;
        }
        nr++;
        return nr;
    }

    /// Suprascrierea operatorului de atribuire =
    List<T>& operator=(const List<T>& newList){
        delete[]this;
        this->head = newList.head;
        return *this;
    }
};


#endif //PROIECT_SDA_ListSI_H
