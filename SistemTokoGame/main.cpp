#include <iostream>
#include "Game.h"
#include "User.h"
#include "Relasi.h"
using namespace std;

int inputInt() {
    int x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Masukkan angka: ";
    }
    return x;
}

void menu() {
    cout << "\n=== MENU STEAM STORE (MLL) ===\n";
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
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}

int main() {
    ListGame LG;
    ListUser LU;
    ListRelasi LR;

    createListGame(LG);
    createListUser(LU);
    createListRelasi(LR);

    int pilih;
    do {
        menu();
        pilih = inputInt();

        if (pilih == 1) {
            Game g;
            cout << "ID Game: ";
            cin >> g.idGame;

            if (findGame(LG, g.idGame) != nullptr) {
                cout << "ID Game sudah digunakan.\n";
            } else {
                cout << "Judul: ";
                cin >> g.title;
                cout << "Genre: ";
                cin >> g.genre;
                cout << "Harga: ";
                g.price = inputInt();
                insertLastGame(LG, newGame(g));
                cout << "Game berhasil ditambahkan.\n";
            }
        }
        else if (pilih == 2) {
            User u;
            cout << "ID User: ";
            cin >> u.idUser;

            if (findUser(LU, u.idUser) != nullptr) {
                cout << "ID User sudah digunakan.\n";
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
            } else {
                Purchase p;
                cout << "Tanggal: ";
                cin >> p.date;
                cout << "Playtime: ";
                p.playtime = inputInt();
                insertLastRelasi(LR, newRelasi(p, G, U));
                cout << "Purchase berhasil ditambahkan.\n";
            }
        }
        else if (pilih == 4) showAllGames(LG);
        else if (pilih == 5) showAllUsers(LU);
        else if (pilih == 6) showAllRelations(LR);

        else if (pilih == 7) {
            string id;
            cout << "ID Game: ";
            cin >> id;
            if (findGame(LG, id) == nullptr)
                cout << "ID Game tidak ditemukan.\n";
            else {
                deleteGame(LG, LR, id);
                cout << "Game berhasil dihapus.\n";
            }
        }
        else if (pilih == 8) {
            string id;
            cout << "ID User: ";
            cin >> id;
            if (findUser(LU, id) == nullptr)
                cout << "ID User tidak ditemukan.\n";
            else {
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

            if (G == nullptr || U == nullptr)
                cout << "Game atau User tidak ditemukan.\n";
            else if (findRelation(LR, G, U) == nullptr)
                cout << "Purchase tidak ditemukan.\n";
            else {
                deleteRelation(LR, G, U);
                cout << "Purchase berhasil dihapus.\n";
            }
        }
        else if (pilih == 10) {
            string id;
            cout << "ID Game: ";
            cin >> id;
            adrGame G = findGame(LG, id);
            if (G == nullptr)
                cout << "ID Game tidak ditemukan.\n";
            else
                cout << "Judul: " << G->info.title
                     << ", Genre: " << G->info.genre
                     << ", Harga: " << G->info.price << endl;
        }
        else if (pilih == 11) {
            string id;
            cout << "ID User: ";
            cin >> id;
            adrUser U = findUser(LU, id);
            if (U == nullptr)
                cout << "ID User tidak ditemukan.\n";
            else
                cout << "Username: " << U->info.username
                     << ", Email: " << U->info.email << endl;
        }

    } while (pilih != 0);

    cout << "Program selesai.\n";
    return 0;
}
