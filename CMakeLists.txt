cmake_minimum_required(VERSION 3.21)
project(Proiect_SDA)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proiect_SDA main.cpp TAD/List.h TAD/Node.h TAD/MultiMap.h Domain/User.cpp Domain/User.h UserInterface/Interface.cpp UserInterface/Interface.h Tests/TestsTAD.cpp Tests/TestsTAD.h Repository/RepositoryList.h Service/Service.h Domain/Friendship.cpp Domain/Friendship.h Tests/TestsDomain.cpp Tests/TestsDomain.h Repository/RepositoryMultiMap.h Repository/ReposytoryFriendship.h Tests/TestsRepo.cpp Tests/TestsRepo.h Domain/Message.cpp Domain/Message.h Repository/RepositoryMessages.h)
