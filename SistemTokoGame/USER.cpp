#include "User.h"

void createListUser(ListUser &LU) {
    LU.first = NULL;
}

adrUser newUser(User x) {
    adrUser U = new elmUser;
    U->info = x;
    U->next = NULL;
    return U;
}

void insertLastUser(ListUser &LU, adrUser U) {
    if (LU.first == NULL) {
        LU.first = U;
    } else {
        adrUser p = LU.first;
        while (p->next != NULL) p = p->next;
        p->next = U;
    }
}

adrUser findUser(ListUser LU, string idUser) {
    adrUser p = LU.first;
    while (p != NULL) {
        if (p->info.idUser == idUser) return p;
        p = p->next;
    }
    return NULL;
}

void deleteUserOnly(ListUser &LU, string idUser) {
    adrUser p = LU.first;

    if (!p) return;

    if (p->info.idUser == idUser) {
        LU.first = p->next;
        delete p;
        return;
    }

    adrUser prev = NULL;
    while (p != NULL && p->info.idUser != idUser) {
        prev = p;
        p = p->next;
    }

    if (p != NULL) {
        prev->next = p->next;
        delete p;
    }
}

void showAllUsers(ListUser LU) {
    if (LU.first == NULL) {
        cout << "Belum ada data user.\n";
        return;
    }

    cout << "=============== DAFTAR USER ===============\n";
    cout << "ID\tUsername\tEmail\t\tLevel\n";
    cout << "-------------------------------------------\n";

    adrUser p = LU.first;
    while (p != NULL) {
        cout << p->info.idUser << "\t"
             << p->info.username << "\t\t"
             << p->info.email << "\t"
             << p->info.level << endl;
        p = p->next;
    }
}

