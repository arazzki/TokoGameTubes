#include "Game.h"

void createListGame(ListGame &LG) {
    LG.first = NULL;
}

adrGame newGame(Game x) {
    adrGame G = new elmGame;
    G->info = x;
    G->next = NULL;
    return G;
}

void insertLastGame(ListGame &LG, adrGame G) {
    if (LG.first == NULL) {
        LG.first = G;
    } else {
        adrGame p = LG.first;
        while (p->next != NULL) p = p->next;
        p->next = G;
    }
}

adrGame findGame(ListGame LG, string idGame) {
    adrGame p = LG.first;
    while (p != NULL) {
        if (p->info.idGame == idGame) return p;
        p = p->next;
    }
    return NULL;
}

void deleteGameOnly(ListGame &LG, string idGame) {
    adrGame p = LG.first;

    if (!p) return;

    if (p->info.idGame == idGame) {
        LG.first = p->next;
        delete p;
        return;
    }

    adrGame prev = NULL;
    while (p != NULL && p->info.idGame != idGame) {
        prev = p;
        p = p->next;
    }

    if (p != NULL) {
        prev->next = p->next;
        delete p;
    }
}

void showAllGames(ListGame LG) {
    adrGame p = LG.first;
    while (p != NULL) {
        cout << p->info.idGame << " | "
             << p->info.title << " | "
             << p->info.genre << " | "
             << p->info.price << endl;
        p = p->next;
    }
}

