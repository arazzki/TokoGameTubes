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
adrUser newUser(const User &x);
void insertLastUser(ListUser &LU, adrUser U);
adrUser findUser(ListUser LU, const string &idUser);
void deleteUser(ListUser &LU, struct ListRelasi &LR, const string &idUser);
void deleteUserOnly(ListUser &LU, const string &idUser);
void showAllUsers(ListUser LU);
int countUserNodes(ListUser LU);

#endif
