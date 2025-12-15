#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <string>
#include "Game.h"
#include "User.h"
using namespace std;

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
adrRelasi newRelasi(Purchase x, adrGame G, adrUser U);
void insertLastRelasi(ListRelasi &LR, adrRelasi R);
adrRelasi findRelation(ListRelasi LR, adrGame G, adrUser U);
void deleteRelation(ListRelasi &LR, adrGame G, adrUser U);

void showAllRelations(ListRelasi LR);

#endif
