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
    U->prev = nullptr;
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
        U->prev = p;
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
        if (r->user == U)
            deleteRelation(LR, r->game, r->user);
        r = nextR;
    }

    if (U->prev != nullptr)
        U->prev->next = U->next;
    else
        LU.first = U->next;

    if (U->next != nullptr)
        U->next->prev = U->prev;

    delete U;
}

void showAllUsers(ListUser LU) { //ini gw ubah (will)
    if (LU.first == nullptr) {
        cout << "Belum ada data user.\n";
        return;
    }

    cout << "\n=== DAFTAR USER ===\n";

    cout << left
         << setw(10) << "ID"
         << setw(20) << "Username"
         << setw(35) << "Email" << endl;


    adrUser p = LU.first;
    while (p != nullptr) {
        cout << left
             << setw(10) << p->info.idUser
             << setw(20) << p->info.username
             << setw(35) << p->info.email
             << endl;
        p = p->next;
    }

    cout << "Total User: " << countUser(LU) << endl;
}

int countUser(ListUser LU) {
    int total = 0;
    adrUser p = LU.first;
    while (p != nullptr) {
        total++;
        p = p->next;
    }
    return total;
}
