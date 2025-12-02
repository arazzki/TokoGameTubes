#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#include "GAME.h"
#include "USER.h"

struct Purchase {
    string date;
    int playtime;
};

struct elmRelasi;
typedef elmRelasi* adrRelasi;

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
adrRelasi newRelasi(Purchase x, adrGame G, adrUser U);
void insertLastRelasi(ListRelasi &LR, adrRelasi R);
adrRelasi findRelation(ListRelasi LR, adrGame G, adrUser U);

void deleteRelation(ListRelasi &LR, adrGame G, adrUser U);

void showRelations(ListRelasi LR);
void showUsersOfGame(ListRelasi LR, adrGame G);
void showGamesOfUser(ListRelasi LR, adrUser U);

#endif
