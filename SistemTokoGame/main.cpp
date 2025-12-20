#include <iostream>
#include <limits>
#include "Game.h"
#include "User.h"
#include "Relasi.h"
using namespace std;

int inputInt() {
    int x;
    while (true) {
        cin >> x;
        if (!cin.fail()) {
            cin.ignore(1000, '\n'); // bersihkan sisa input
            return x;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input harus angka. Masukkan lagi: ";
    }
}

double inputDouble() { //input harga, gw tambah (will)
    double x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input harus angka desimal. Masukkan lagi: ";
    }
    return x;
}

void menu() {
    cout << "\n====== MENU STEAM STORE (MLL) ======\n";
    cout << "1. Tambah Game\n";
    cout << "2. Tambah User\n";
    cout << "3. Tambah Purchase\n";
    cout << "4. Tampilkan Game\n";
    cout << "5. Tampilkan User\n";
    cout << "6. Tampilkan Purchase\n";
    cout << "7. Hapus Game\n";
    cout << "8. Hapus User\n";
    cout << "9. Hapus Purchase\n";
    cout << "10. Cari Game\n";
    cout << "11. Cari User\n";
    cout << "12. Count Game\n";
    cout << "13. Count User\n";
    cout << "14. Count Purchase\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}
//ini gw tambah dummy (will)
void initDummy(ListGame &LG, ListUser &LU, ListRelasi &LR) {
    // dummy game
    insertLastGame(LG, newGame({"001", "Dota 2", "MOBA", 10.99}));
    insertLastGame(LG, newGame({"002", "Red Dead Redemption 2", "Action", 7.50}));
    insertLastGame(LG, newGame({"003", "GTA V", "OpenWorld", 1.99}));
    insertLastGame(LG, newGame({"004", "The Last Of Us 2", "Story", 7.99}));
    insertLastGame(LG, newGame({"005", "The Last Of Us", "Story", 6.99}));

    //dummy user
    insertLastUser(LU, newUser({"084", "william", "william@haha.com"}));
    insertLastUser(LU, newUser({"138", "ariq", "ariq@yahuu.id"}));
    insertLastUser(LU, newUser({"068", "rakha", "rak4@mozilla.fox"}));

    //dummy relasi
    Purchase p;

    p = {"1983-12-04", "Credit Card"};
    insertLastRelasi(LR, newRelasi(
        p,
        findGame(LG, "005"),
        findUser(LU, "084")
    ));

    p = {"1987-12-04", "Credit Card"};
    insertLastRelasi(LR, newRelasi(
        p,
        findGame(LG, "004"),
        findUser(LU, "084")
    ));

    p = {"2001-06-06", "Cash"};
    insertLastRelasi(LR, newRelasi(
        p,
        findGame(LG, "001"),
        findUser(LU, "138")
    ));

    p = {"2012-01-01", "Gift"};
    insertLastRelasi(LR, newRelasi(
        p,
        findGame(LG, "002"),
        findUser(LU, "068")
    ));
}

int main() {
    ListGame LG;
    ListUser LU;
    ListRelasi LR;

    createListGame(LG);
    createListUser(LU);
    createListRelasi(LR);

    initDummy(LG, LU, LR);

    int pilih;
    do {
        menu();
        cin.clear();
        pilih = inputInt();

        if (pilih == 1) {
            Game g;
            cout << "ID Game: ";
            cin >> g.idGame;

            if (findGame(LG, g.idGame) != nullptr) {
                cout << "ID Game sudah digunakan. Tolong gunakan ID Game berbeda\n";
            } else {
                cout << "Judul: ";
                cin >> g.title;
                cout << "Genre: ";
                cin >> g.genre;
                cout << "Harga (USD): ";
                g.price = inputDouble();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                insertLastGame(LG, newGame(g));
                cout << "Game berhasil ditambahkan.\n";
            }
        }

        else if (pilih == 2) {
            User u;
            cout << "ID User: ";
            cin >> u.idUser;

            if (findUser(LU, u.idUser) != nullptr) {
                cout << "ID User sudah digunakan. Tolong gunakan ID User berbeda\n";
            } else {
                cout << "Username: ";
                cin >> u.username;
                cout << "Email: ";
                cin >> u.email;
                insertLastUser(LU, newUser(u));
                cout << "User berhasil ditambahkan.\n";
            }
        }

        else if (pilih == 3) {
            string gid, uid;
            cout << "ID Game: ";
            cin >> gid;
            cout << "ID User: ";
            cin >> uid;

            adrGame G = findGame(LG, gid);
            adrUser U = findUser(LU, uid);

            if (G == nullptr || U == nullptr) {
                cout << "Game atau User tidak ditemukan.\n";
            } else if (findRelation(LR, G, U) != nullptr) {
                cout << "Purchase sudah ada.\n";
            } else { //ini gw ganti (will)
                Purchase p;
                cout << "Tanggal (YYYY-MM-DD): ";
                cin >> p.date;
                cout << "Metode Pembelian: ";
                cin >> p.method;

                insertLastRelasi(LR, newRelasi(p, G, U));
                cout << "Purchase berhasil ditambahkan.\n";
            }
        }

        else if (pilih == 4) {
            showAllGames(LG);
        }

        else if (pilih == 5) {
            showAllUsers(LU);
        }

        else if (pilih == 6) {
            showAllRelations(LR);
        }

        else if (pilih == 7) {
            string id;
            cout << "ID Game: ";
            cin >> id;

            if (findGame(LG, id) == nullptr) {
                cout << "ID Game tidak ditemukan.\n";
            } else {
                deleteGame(LG, LR, id);
                cout << "Game berhasil dihapus.\n";
            }
        }

        else if (pilih == 8) {
            string id;
            cout << "ID User: ";
            cin >> id;

            if (findUser(LU, id) == nullptr) {
                cout << "ID User tidak ditemukan.\n";
            } else {
                deleteUser(LU, LR, id);
                cout << "User berhasil dihapus.\n";
            }
        }

        else if (pilih == 9) {
            string gid, uid;
            cout << "ID Game: ";
            cin >> gid;
            cout << "ID User: ";
            cin >> uid;

            adrGame G = findGame(LG, gid);
            adrUser U = findUser(LU, uid);

            if (G == nullptr || U == nullptr) {
                cout << "Game atau User tidak ditemukan.\n";
            } else if (findRelation(LR, G, U) == nullptr) {
                cout << "Purchase tidak ditemukan.\n";
            } else {
                deleteRelation(LR, G, U);
                cout << "Purchase berhasil dihapus.\n";
            }
        }

        else if (pilih == 10) {
            string id;
            cout << "ID Game: ";
            cin >> id;

            adrGame G = findGame(LG, id);
            if (G == nullptr) {
                cout << "ID Game tidak ditemukan.\n";
            } else {
                cout << "Judul : " << G->info.title << endl;
                cout << "Genre : " << G->info.genre << endl;
                cout << "Harga : " << G->info.price << endl;
            }
        }

        else if (pilih == 11) {
            string id;
            cout << "ID User: ";
            cin >> id;

            adrUser U = findUser(LU, id);
            if (U == nullptr) {
                cout << "ID User tidak ditemukan.\n";
            } else {
                cout << "Username : " << U->info.username << endl;
                cout << "Email    : " << U->info.email << endl;
            }
        }

        else if (pilih == 12) {
            cout << "Total Game: " << countGame(LG) << endl;
        }

        else if (pilih == 13) {
            cout << "Total User: " << countUser(LU) << endl;
        }

        else if (pilih == 14) {
            cout << "Total Purchase: " << countRelation(LR) << endl;
        }

        else if (pilih != 0) {
            cout << "Pilihan menu tidak tersedia.\n";
        }

    } while (pilih != 0);

    cout << "Program selesai.\n";
    return 0;
}
