#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
using namespace std;

struct User {
    string idUser;
    string username;
    string email;
};

typedef struct elmUser *adrUser;

struct elmUser {
    User info;
    adrUser next;
    adrUser prev;
};

struct ListUser {
    adrUser first;
};

void createListUser(ListUser &LU);
adrUser newUser(User x);
void insertLastUser(ListUser &LU, adrUser U);
adrUser findUser(ListUser LU, string idUser);
void deleteUser(ListUser &LU, struct ListRelasi &LR, string idUser);
void showAllUsers(ListUser LU);
int countUser(ListUser LU);

#endif
