#include <iostream>
#include "User.h"
#include "Relasi.h"

void createListUser(ListUser &LU) {
    LU.first = nullptr;
}

adrUser newUser(User x) {
    adrUser U = new elmUser;
    U->info = x;
    U->next = nullptr;
    return U;
}

void insertLastUser(ListUser &LU, adrUser U) {
    if (LU.first == nullptr) {
        LU.first = U;
    } else {
        adrUser p = LU.first;
        while (p->next != nullptr)
            p = p->next;
        p->next = U;
    }
}

adrUser findUser(ListUser LU, string idUser) {
    adrUser p = LU.first;
    while (p != nullptr) {
        if (p->info.idUser == idUser)
            return p;
        p = p->next;
    }
    return nullptr;
}

void deleteUser(ListUser &LU, ListRelasi &LR, string idUser) {
    adrUser U = findUser(LU, idUser);
    if (U == nullptr) return;

    adrRelasi r = LR.first;
    while (r != nullptr) {
        adrRelasi nextR = r->next;
        if (r->user == U) {
            deleteRelation(LR, r->game, r->user);
        }
        r = nextR;
    }

    adrUser p = LU.first, prev = nullptr;
    while (p != nullptr && p != U) {
        prev = p;
        p = p->next;
    }

    if (prev == nullptr)
        LU.first = p->next;
    else
        prev->next = p->next;

    delete p;
}

void showAllUsers(ListUser LU) {
    if (LU.first == nullptr) {
        cout << "Belum ada data user.\n";
        return;
    }

    cout << "\n=== DAFTAR USER ===\n";
    cout << "ID\tUsername\tEmail\n";
    cout << "--------------------------------\n";

    adrUser p = LU.first;
    while (p != nullptr) {
        cout << p->info.idUser << "\t"
             << p->info.username << "\t\t"
             << p->info.email << endl;
        p = p->next;
    }
}
