#include <iostream>
#include "Game.h"
#include "Relasi.h"

void createListGame(ListGame &LG) {
    LG.first = nullptr;
}

adrGame newGame(Game x) {
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
        while (p->next != nullptr)
            p = p->next;
        p->next = G;
    }
}

adrGame findGame(ListGame LG, string idGame) {
    adrGame p = LG.first;
    while (p != nullptr) {
        if (p->info.idGame == idGame)
            return p;
        p = p->next;
    }
    return nullptr;
}

void deleteGame(ListGame &LG, ListRelasi &LR, string idGame) {
    adrGame G = findGame(LG, idGame);
    if (G == nullptr) return;

    adrRelasi r = LR.first;
    while (r != nullptr) {
        adrRelasi nextR = r->next;
        if (r->game == G) {
            deleteRelation(LR, r->game, r->user);
        }
        r = nextR;
    }

    adrGame p = LG.first, prev = nullptr;
    while (p != nullptr && p != G) {
        prev = p;
        p = p->next;
    }

    if (prev == nullptr)
        LG.first = p->next;
    else
        prev->next = p->next;

    delete p;
}

void showAllGames(ListGame LG) {
    if (LG.first == nullptr) {
        cout << "Belum ada data game.\n";
        return;
    }

    cout << "\n=== DAFTAR GAME ===\n";
    cout << "ID\tJudul\tGenre\tHarga\n";
    cout << "--------------------------------\n";

    adrGame p = LG.first;
    while (p != nullptr) {
        cout << p->info.idGame << "\t"
             << p->info.title << "\t"
             << p->info.genre << "\t"
             << p->info.price << endl;
        p = p->next;
    }
}
