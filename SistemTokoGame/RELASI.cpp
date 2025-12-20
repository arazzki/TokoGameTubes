#include <iostream>
#include "Relasi.h"

void createListRelasi(ListRelasi &LR) {
    LR.first = nullptr;
}

adrRelasi newRelasi(Purchase x, adrGame G, adrUser U) {
    adrRelasi R = new elmRelasi;
    R->info = x;
    R->game = G;
    R->user = U;
    R->next = nullptr;
    return R;
}

void insertLastRelasi(ListRelasi &LR, adrRelasi R) {
    if (LR.first == nullptr) {
        LR.first = R;
    } else {
        adrRelasi p = LR.first;
        while (p->next != nullptr)
            p = p->next;
        p->next = R;
    }
}

adrRelasi findRelation(ListRelasi LR, adrGame G, adrUser U) {
    adrRelasi p = LR.first;
    while (p != nullptr) {
        if (p->game == G && p->user == U)
            return p;
        p = p->next;
    }
    return nullptr;
}

void deleteRelation(ListRelasi &LR, adrGame G, adrUser U) {
    adrRelasi p = LR.first, prev = nullptr;
    while (p != nullptr) {
        if (p->game == G && p->user == U) {
            if (prev == nullptr)
                LR.first = p->next;
            else
                prev->next = p->next;
            delete p;
            return;
        }
        prev = p;
        p = p->next;
    }
}

void showAllRelations(ListRelasi LR) { //ini gw ubah (will)
    if (LR.first == nullptr) {
        cout << "Belum ada transaksi.\n";
        return;
    }

    cout << "\n=== DAFTAR PURCHASE ===\n";

    cout << left
         << setw(20) << "User"
         << setw(30) << "Game"
         << setw(15) << "Tanggal"
         << setw(10) << "Metode" << endl;


    adrRelasi p = LR.first;
    while (p != nullptr) {
        cout << left
             << setw(20) << p->user->info.username
             << setw(30) << p->game->info.title
             << setw(15) << p->info.date
             << setw(10) << p->info.method
             << endl;
        p = p->next;
    }

    cout << "Total Purchase: " << countRelation(LR) << endl;
}

int countRelation(ListRelasi LR) {
    int total = 0;
    adrRelasi p = LR.first;
    while (p != nullptr) {
        total++;
        p = p->next;
    }
    return total;
}
