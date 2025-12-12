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
    if (LG.first == NULL) {
        cout << "Belum ada data game.\n";
        return;
    }

    cout << "================ DAFTAR GAME ================\n";
    cout << "ID\tTitle\t\tGenre\t\tHarga\n";
    cout << "----------------------------------------------\n";

    adrGame p = LG.first;
    while (p != NULL) {
        cout << p->info.idGame << "\t"
             << p->info.title << "\t\t"
             << p->info.genre << "\t\t"
             << p->info.price << endl;
        p = p->next;
    }
}


