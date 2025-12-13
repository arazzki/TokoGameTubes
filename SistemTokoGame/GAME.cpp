#include "Game.h"
#include "Relasi.h" // for declaration of ListRelasi in deleteGame

void createListGame(ListGame &LG) {
    LG.first = nullptr;
}

adrGame newGame(const Game &x) {
    adrGame G = new elmGame;
    G->info = x;
    G->next = nullptr;
    return G;
}

void insertLastGame(ListGame &LG, adrGame G) {
    if (LG.first == nullptr) {
        LG.first = G;
    } else {
        adrGame p = LG.first;
        while (p->next != nullptr) p = p->next;
        p->next = G;
    }
}

adrGame findGame(ListGame LG, const string &idGame) {
    adrGame p = LG.first;
    while (p != nullptr) {
        if (p->info.idGame == idGame) return p;
        p = p->next;
    }
    return nullptr;
}

void deleteGameOnly(ListGame &LG, const string &idGame) {
    adrGame p = LG.first;
    adrGame prev = nullptr;

    while (p != nullptr && p->info.idGame != idGame) {
        prev = p;
        p = p->next;
    }

    if (p == nullptr) return;

    if (prev == nullptr) {
        LG.first = p->next;
    } else {
        prev->next = p->next;
    }

    p->next = nullptr;
    delete p;
}

void deleteGame(ListGame &LG, ListRelasi &LR, const string &idGame) {
    // find game node pointer first
    adrGame G = findGame(LG, idGame);
    if (G == nullptr) return;

    // remove all relations that refer to this game
    adrRelasi r = LR.first;
    while (r != nullptr) {
        adrRelasi nextR = r->next;
        if (r->game == G) {
            deleteRelation(LR, r->game, r->user);
        }
        r = nextR;
    }

    // remove the game node itself
    deleteGameOnly(LG, idGame);
}

void showAllGames(ListGame LG) {
    if (LG.first == nullptr) {
        cout << "Belum ada data game.\n";
        return;
    }
    cout << "================ DAFTAR GAME ================\n";
    cout << "ID\tTitle\t\tGenre\t\tHarga\n";
    cout << "----------------------------------------------\n";
    adrGame p = LG.first;
    while (p != nullptr) {
        cout << p->info.idGame << "\t"
             << p->info.title << "\t\t"
             << p->info.genre << "\t\t"
             << p->info.price << "\n";
        p = p->next;
    }
}

int countGameNodes(ListGame LG) {
    int c = 0;
    adrGame p = LG.first;
    while (p != nullptr) { c++; p = p->next; }
    return c;
}
