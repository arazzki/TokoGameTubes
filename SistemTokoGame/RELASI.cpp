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

void showAllRelations(ListRelasi LR) {
    if (LR.first == nullptr) {
        cout << "Belum ada transaksi.\n";
        return;
    }

    cout << "\n=== DAFTAR PURCHASE ===\n";
    cout << "User\tGame\tTanggal\tPlaytime\n";
    cout << "--------------------------------------\n";

    adrRelasi p = LR.first;
    while (p != nullptr) {
        cout << p->user->info.username << "\t"
             << p->game->info.title << "\t"
             << p->info.date << "\t"
             << p->info.playtime << endl;
        p = p->next;
    }
}
