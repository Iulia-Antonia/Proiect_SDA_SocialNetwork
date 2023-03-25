//
// Created by asus on 5/14/2022.
//

#include "TestsDomain.h"

#include "../Domain/User.h"
#include "../Domain/Friendship.h"
#include "../Domain/Message.h"
#include "assert.h"

/// Testeaza implementarea clasei User
void testUser(){
    User u1(1, "Ana", 20);
    User u2(2 ,"Mihai", 32);
    User u3(3, "Radu", 12);
    User u;
    assert(u.getVarsta() == 0);
    assert(u.getId() == -1);
    assert(u1.getName() == "Ana");
    assert(u1.getVarsta()== 20);
    assert(u1.getId() == 1);

    u1.setName("Kui Ana");
    assert(u1.getName() == "Kui Ana");

    u1.setVarsta(21);
    assert(u1.getVarsta() == 21);
}

/// Testeaza implementarea clasei Friendship
void testFrendship(){
    User u1(1, "Ana", 20);
    User u2(2 ,"Mihai", 32);
    User u3(3, "Radu", 12);
    Friendship f1;
    f1.setPrieten1(u1);
    f1.setPrieten2(u2);
//    Friendship f1(u1, u2);
    Friendship f2(u1, u3);
    Friendship f3(u1, u3);
    assert(f1.getPrieten1()==u1);
    assert(f2.getPrieten1()==u1);
    assert(f1.getPrieten2()==u2);
    assert(f2.getPrieten2()==u3);

    assert(f1!=f2);
    assert(f2 == f3);

    f1.setPrieten1(u3);
    assert(f1.getPrieten1()==u3);
    assert(f1.getPrieten2()==u2);

    f1.setPrieten2(u1);
    assert(f1.getPrieten2() == u1);
    assert(f1.getPrieten1() == u3);

    assert(f1 == f2);
}

/// Testeaza implementarea clasei Message
void testMessage(){
    User u1(1, "Ana", 20);
    User u2(2 ,"Mihai", 32);
    User u3(3, "Radu", 12);
    string msg1 = "Hei! Ce mai faci?", msg2 = "Hei! Bine. Tu?", msg3 = "Bine! Multumesc de intrebare!";
    Message m1(u1, u2, msg1);
    Message m2(u2, u1, msg2);
    Message m4(u1,u3,msg3);
    Message m3, m5;
    assert(m1.getTransmitter() == u1);
    assert(m2.getTransmitter() == u2);
    assert(m1.getReceiver() == u2);
    assert(m2.getReceiver() == u1);
    assert(m1.getMessage() == msg1);
    assert(m2.getMessage() == msg2);

    m3.setTransmitter(u1);
    m3.setReceiver(u3);
    m3.setMessage(msg3);
    assert(m4 == m3);
    assert(m1 != m2);
    m5 = m3;
    assert(m5 == m4);
}

/// Apelarea tuturor testelor pentru Domain
void testsDomain(){
    testUser();
    testFrendship();
    testMessage();
}