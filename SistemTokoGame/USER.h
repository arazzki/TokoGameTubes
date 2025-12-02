#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct User {
    string idUser;
    string username;
    string email;
    int level;
};

typedef struct elmUser *adrUser;

struct elmUser {
    User info;
    adrUser next;
};

struct ListUser {
    adrUser first;
};

void createListUser(ListUser &LU);
adrUser newUser(User x);
void insertLastUser(ListUser &LU, adrUser U);
adrUser findUser(ListUser LU, string idUser);
void deleteUserOnly(ListUser &LU, string idUser);
void showAllUsers(ListUser LU);

#endif
