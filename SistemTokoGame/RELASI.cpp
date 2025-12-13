#include "Relasi.h"
#include <iostream>

void createListRelasi(ListRelasi &LR) {
    LR.first = nullptr;
}

adrRelasi newRelasi(const Purchase &x, adrGame G, adrUser U) {
    adrRelasi R = new elmRelasi;
    R->info = x;
    R->game = G;
    R->user = U;
    R->next = nullptr;
    return R;
}

void insertLastRelasi(ListRelasi &LR, adrRelasi R) {
    if (LR.first == nullptr) LR.first = R;
    else {
        adrRelasi p = LR.first;
        while (p->next != nullptr) p = p->next;
        p->next = R;
    }
}

adrRelasi findRelation(ListRelasi LR, adrGame G, adrUser U) {
    adrRelasi p = LR.first;
    while (p != nullptr) {
        if (p->game == G && p->user == U) return p;
        p = p->next;
    }
    return nullptr;
}

void deleteRelation(ListRelasi &LR, adrGame G, adrUser U) {
    adrRelasi p = LR.first;
    adrRelasi prev = nullptr;

    while (p != nullptr) {
        if (p->game == G && p->user == U) {
            if (prev == nullptr) LR.first = p->next;
            else prev->next = p->next;
            p->next = nullptr;
            delete p;
            return;
        }
        prev = p;
        p = p->next;
    }
}

void showRelations(ListRelasi LR) {
    if (LR.first == nullptr) {
        cout << "Belum ada transaksi.\n";
        return;
    }
    cout << "============ DAFTAR TRANSAKSI ============\n";
    cout << "User\tGame\t\tTanggal\t\tPlaytime\n";
    cout << "-------------------------------------------\n";
    adrRelasi p = LR.first;
    while (p != nullptr) {
        string gtitle = (p->game ? p->game->info.title : "(deleted game)");
        string uname = (p->user ? p->user->info.username : "(deleted user)");
        cout << uname << "\t" << gtitle << "\t"
             << p->info.date << "\t" << p->info.playtime << " jam\n";
        p = p->next;
    }
}

void showUsersOfGame(ListRelasi LR, adrGame G) {
    if (G == nullptr) { cout << "Game NULL\n"; return; }
    adrRelasi p = LR.first;
    bool found = false;
    cout << "Buyers of " << G->info.title << ":\n";
    while (p != nullptr) {
        if (p->game == G) {
            found = true;
            cout << "- " << p->user->info.username
                 << " | Date: " << p->info.date
                 << " | Playtime: " << p->info.playtime << " jam\n";
        }
        p = p->next;
    }
    if (!found) cout << "(belum ada pembeli)\n";
}

void showGamesOfUser(ListRelasi LR, adrUser U) {
    if (U == nullptr) { cout << "User NULL\n"; return; }
    adrRelasi p = LR.first;
    bool found = false;
    cout << "Games owned by " << U->info.username << ":\n";
    while (p != nullptr) {
        if (p->user == U) {
            found = true;
            cout << "- " << p->game->info.title
                 << " | Date: " << p->info.date
                 << " | Playtime: " << p->info.playtime << " jam\n";
        }
        p = p->next;
    }
    if (!found) cout << "(belum ada game)\n";
}

int countUsersOfGame(ListRelasi LR, adrGame G) {
    int c = 0;
    adrRelasi p = LR.first;
    while (p != nullptr) {
        if (p->game == G) c++;
        p = p->next;
    }
    return c;
}

int countGamesOfUser(ListRelasi LR, adrUser U) {
    int c = 0;
    adrRelasi p = LR.first;
    while (p != nullptr) {
        if (p->user == U) c++;
        p = p->next;
    }
    return c;
}

int countGameWithoutUser(ListGame LG, ListRelasi &LR) {
    int c = 0;
    adrGame g = LG.first;
    while (g != nullptr) {
        if (countUsersOfGame(LR, g) == 0) c++;
        g = g->next;
    }
    return c;
}

int countUserWithoutGame(ListUser LU, ListRelasi &LR) {
    int c = 0;
    adrUser u = LU.first;
    while (u != nullptr) {
        if (countGamesOfUser(LR, u) == 0) c++;
        u = u->next;
    }
    return c;
}

void editRelation(ListRelasi &LR, adrGame oldG, adrUser oldU, adrGame newG, adrUser newU) {
    adrRelasi p = LR.first;
    while (p != nullptr) {
        if (p->game == oldG && p->user == oldU) {
            p->game = newG;
            p->user = newU;
            return;
        }
        p = p->next;
    }
}
