#include "User.h"
#include "Relasi.h"

void createListUser(ListUser &LU) {
    LU.first = nullptr;
}

adrUser newUser(const User &x) {
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
        while (p->next != nullptr) p = p->next;
        p->next = U;
    }
}

adrUser findUser(ListUser LU, const string &idUser) {
    adrUser p = LU.first;
    while (p != nullptr) {
        if (p->info.idUser == idUser) return p;
        p = p->next;
    }
    return nullptr;
}

void deleteUserOnly(ListUser &LU, const string &idUser) {
    adrUser p = LU.first;
    adrUser prev = nullptr;
    while (p != nullptr && p->info.idUser != idUser) {
        prev = p;
        p = p->next;
    }

    if (p == nullptr) return;

    if (prev == nullptr) LU.first = p->next;
    else prev->next = p->next;

    p->next = nullptr;
    delete p;
}

void deleteUser(ListUser &LU, ListRelasi &LR, const string &idUser) {
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

    deleteUserOnly(LU, idUser);
}

void showAllUsers(ListUser LU) {
    if (LU.first == nullptr) {
        cout << "Belum ada data user.\n";
        return;
    }
    cout << "=============== DAFTAR USER ===============\n";
    cout << "ID\tUsername\tEmail\t\tLevel\n";
    cout << "-------------------------------------------\n";
    adrUser p = LU.first;
    while (p != nullptr) {
        cout << p->info.idUser << "\t"
             << p->info.username << "\t\t"
             << p->info.email << "\t"
             << p->info.level << "\n";
        p = p->next;
    }
}

int countUserNodes(ListUser LU) {
    int c = 0;
    adrUser p = LU.first;
    while (p != nullptr) { c++; p = p->next; }
    return c;
}
