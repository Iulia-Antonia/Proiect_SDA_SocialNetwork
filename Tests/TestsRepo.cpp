//
// Created by asus on 5/16/2022.
//

#include "TestsRepo.h"
#include "../Repository/RepositoryList.h"
#include "../Repository/RepositoryMultiMap.h"
#include "../Repository/ReposytoryFriendship.h"
#include "../Repository/RepositoryMessages.h"
#include <vector>
#include "assert.h"

/// Testeaza implementarea repositoryului pentru List
void testReposytoryList(){
    RepositoryList<int>rep;
    rep.add(20);
    assert(rep.getSize() == 1);
    assert(rep.getElem(0)==20);
    rep.add(-2);
    rep.add(0);
    rep.add(1000);
    rep.add(20);
    assert(rep.getSize() == 5);
    assert(rep.search(-2));
    assert(!rep.search(5));
    assert(rep.search(0));
    rep.remove(0);
    assert(rep.getSize()==4);
    assert(!rep.search(0));
    rep.update(20, 26);
    assert(rep.getElem(0)==26);
    assert(rep.getElem(3)==26);
}

/// Testeaza implementarea repositoryului pentru MultiMap
void testReposytoryMultiMap(){
    RepositoryMultiMap<int, int>repoMultimap;
    repoMultimap.add(1, 2);
    repoMultimap.add(1, 3);
    repoMultimap.add(2, 0);
    repoMultimap.add(1, 4);
    assert(repoMultimap.getSize()==2);
    repoMultimap.add(3, 4);
    assert(repoMultimap.getSize()==3);
    vector<int> keys = repoMultimap.getKeys();
    assert(keys.size()==3);
    assert(keys[0]==1);
    assert(keys[1]==2);
    assert(keys[2]==3);
    vector<int> valori = repoMultimap.getKeyElems(1);
    assert(valori.size()==3);
    assert(valori[0]==4);
    assert(valori[1]==3);
    assert(valori[2]==2);

    repoMultimap.removeValue(1, 4);
    valori = repoMultimap.getKeyElems(1);
    assert(valori.size()==2);
    assert(valori[0]==3);
    assert(valori[1]==2);

    repoMultimap.removeKey(3);
    keys = repoMultimap.getKeys();
    assert(keys.size()==2);
    assert(keys[0]==1);
    assert(keys[1]==2);
}

/// Testeaza implementarea repositoryului pentru Friendship
void testReposytoryFriendship(){
    RepoFriendship repoFriendship;
    User u1(1, "Ana", 20);
    User u2(2 ,"Mihai", 32);
    User u3(3, "Radu", 12);
    Friendship f1(u1, u2);
    Friendship f2(u1, u3);
    repoFriendship.addFriend(f1);
    repoFriendship.addFriend(f2);
    assert(repoFriendship.getSize()==3);
    vector<int> keys = repoFriendship.getKeys();
    assert(keys.size()==3);
    assert(keys[0]==1);
    assert(keys[1]==2);
    assert(keys[2]==3);

    assert(repoFriendship.isFrienshipbetween(1,2));
    assert(repoFriendship.isFrienshipbetween(3,1));
    assert(!repoFriendship.isFrienshipbetween(3,2));

    vector<int>valori = repoFriendship.getKeyElems(1);
    assert(valori.size()==2);
    assert(valori[0]==3);
    assert(valori[1]==2);

    repoFriendship.removeFriend(f1);
    assert(repoFriendship.getSize()==3);
    keys = repoFriendship.getKeys();
    assert(keys.size()==3);

    valori = repoFriendship.getKeyElems(1);
    assert(valori.size()==1);
    assert(valori[0]==3);

    valori = repoFriendship.getKeyElems(2);
    assert(valori.size()==0);
}

/// Testeaza implementarea repositoryului pentru Message
void testRepositoryMessages(){
    User u1(1, "Ana", 20);
    User u2(2 ,"Mihai", 32);
    User u3(3, "Radu", 12);
    Friendship f2(u3, u2);
    Friendship f1(u1, u2);
    string msg1 = "Hei! Ce mai faci?", msg2 = "Hei! Bine. Tu?", msg3 = "Bine! Multumesc de intrebare!";
    RepositoryMessages listMessages;
    Message m1(u1, u2, msg1);
    Message m2(u1, u2, msg2);
    Message m3(u1, u2, msg3);
    Message m4(u2, u3, msg1);
    listMessages.addMessageInConversation(m1);
    listMessages.addMessageInConversation(m2);
    listMessages.addMessageInConversation(m3);
    listMessages.addMessageInConversation(m4);
    assert(listMessages.getSize() == 2);
    assert(listMessages.getKeyElems(f2)[0] == m4);
    assert(listMessages.getKeyElems(f1).size() == 3);

    listMessages.deleteMessageFromConversation(m1);
    assert(listMessages.getKeyElems(f1).size() == 2);
}

/// Apelarea tuturor testelor pentru Repository
void testsRepo(){
    testReposytoryList();
    testReposytoryMultiMap();
    testReposytoryFriendship();
    testRepositoryMessages();
}
