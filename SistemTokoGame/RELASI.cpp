#include "Relasi.h"

void createListRelasi(ListRelasi &LR) {
    LR.first = NULL;
}

adrRelasi newRelasi(Purchase x, adrGame G, adrUser U) {
    adrRelasi R = new elmRelasi;
    R->info = x;
    R->game = G;
    R->user = U;
    R->next = NULL;
    return R;
}

void insertLastRelasi(ListRelasi &LR, adrRelasi R) {
    if (LR.first == NULL) {
        LR.first = R;
    } else {
        adrRelasi p = LR.first;
        while (p->next != NULL) p = p->next;
        p->next = R;
    }
}

adrRelasi findRelation(ListRelasi LR, adrGame G, adrUser U) {
    adrRelasi p = LR.first;
    while (p != NULL) {
        if (p->game == G && p->user == U) return p;
        p = p->next;
    }
    return NULL;
}

void deleteRelation(ListRelasi &LR, adrGame G, adrUser U) {
    adrRelasi p = LR.first;

    if (!p) return;

    if (p->game == G && p->user == U) {
        LR.first = p->next;
        delete p;
        return;
    }

    adrRelasi prev = NULL;
    while (p != NULL && !(p->game == G && p->user == U)) {
        prev = p;
        p = p->next;
    }

    if (p != NULL) {
        prev->next = p->next;
        delete p;
    }
}

void showRelations(ListRelasi LR) {
    adrRelasi p = LR.first;
    while (p != NULL) {
        cout << p->user->info.username << " bought "
             << p->game->info.title << " | Playtime: "
             << p->info.playtime << "h\n";
        p = p->next;
    }
}

void showUsersOfGame(ListRelasi LR, adrGame G) {
    adrRelasi p = LR.first;
    while (p != NULL) {
        if (p->game == G) {
            cout << p->user->info.username
                 << " | Date: " << p->info.date << endl;
        }
        p = p->next;
    }
}

void showGamesOfUser(ListRelasi LR, adrUser U) {
    adrRelasi p = LR.first;
    while (p != NULL) {
        if (p->user == U) {
            cout << p->game->info.title
                 << " | Playtime: " << p->info.playtime << endl;
        }
        p = p->next;
    }
}
