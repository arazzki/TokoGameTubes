#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#include "Game.h"
#include "User.h"

struct Purchase {
    string date;
    int playtime;
};

typedef struct elmRelasi *adrRelasi;

struct elmRelasi {
    Purchase info;
    adrGame game;
    adrUser user;
    adrRelasi next;
};

struct ListRelasi {
    adrRelasi first;
};

void createListRelasi(ListRelasi &LR);
adrRelasi newRelasi(const Purchase &x, adrGame G, adrUser U);
void insertLastRelasi(ListRelasi &LR, adrRelasi R);
adrRelasi findRelation(ListRelasi LR, adrGame G, adrUser U);
void deleteRelation(ListRelasi &LR, adrGame G, adrUser U); // delete first match
void showRelations(ListRelasi LR);
void showUsersOfGame(ListRelasi LR, adrGame G);
void showGamesOfUser(ListRelasi LR, adrUser U);

int countUsersOfGame(ListRelasi LR, adrGame G);
int countGamesOfUser(ListRelasi LR, adrUser U);
int countGameWithoutUser(ListGame LG, ListRelasi &LR);
int countUserWithoutGame(ListUser LU, ListRelasi &LR);

void editRelation(ListRelasi &LR, adrGame oldG, adrUser oldU, adrGame newG, adrUser newU);

#endif
