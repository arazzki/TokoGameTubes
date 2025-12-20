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

void deleteGame(ListGame &LG, ListRelasi &LR, string idGame) { //ini gw ganti (will)
    adrGame p = LG.first, prev = nullptr;

    while (p != nullptr && p->info.idGame != idGame) {
        prev = p;
        p = p->next;
    }

    if (p == nullptr) return; // game tidak ditemukan
}

void showAllGames(ListGame LG) { //ini gw ganti (will)
    if (LG.first == nullptr) {
        cout << "Belum ada data game.\n";
        return;
    }

    cout << "\n=== DAFTAR GAME ===\n";
    cout << left
         << setw(10) << "ID"
         << setw(25) << "Judul"
         << setw(15) << "Genre"
         << setw(10) << "Harga" << endl;

    adrGame p = LG.first;
    while (p != nullptr) {
        cout << left
             << setw(10) << p->info.idGame
             << setw(25) << p->info.title
             << setw(15) << p->info.genre
             << setw(10) << p->info.price
             << endl;
        p = p->next;
    }

    cout << "Total Game: " << countGame(LG) << endl;
}

int countGame(ListGame LG) {
    int total = 0;
    adrGame p = LG.first;
    while (p != nullptr) {
        total++;
        p = p->next;
    }
    return total;
}
