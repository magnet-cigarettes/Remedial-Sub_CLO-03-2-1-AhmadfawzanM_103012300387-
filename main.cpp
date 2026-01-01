#include <iostream>
#include "header.h"

using namespace std;

int main() {
    Stack S_Aksi, S_Redo;
    create_stack(S_Aksi);
    create_stack(S_Redo);

    cout << "--- Simulasi Game Pertarungan ---" << endl;

    // Menambah aksi pemain
    cout << "Pemain melakukan: ATTACK, ATTACK, DEFENSE" << endl;
    manageAction(S_Aksi, S_Redo, "ATTACK");
    manageAction(S_Aksi, S_Redo, "ATTACK");
    manageAction(S_Aksi, S_Redo, "DEFENSE");

    // Simulasi UNDO
    cout << "Pemain menekan: UNDO" << endl;
    manageAction(S_Aksi, S_Redo, "UNDO"); // DEFENSE pindah ke S_Redo

    // Simulasi REDO
    cout << "Pemain menekan: REDO" << endl;
    manageAction(S_Aksi, S_Redo, "REDO"); // DEFENSE kembali ke S_Aksi

    // Menambah aksi baru setelah Redo
    cout << "Pemain melakukan: ATTACK" << endl;
    manageAction(S_Aksi, S_Redo, "ATTACK");

    // Hitung Total Damage
    cout << "\nMenghitung Total Damage..." << endl;
    int damage = totalDamage(S_Aksi); // S_Aksi akan menjadi kosong [cite: 157]

    cout << "Total Damage yang dihasilkan: " << damage << endl;
    cout << "Status Stack Aksi sekarang kosong: " << (is_Empty(S_Aksi) ? "Ya" : "Tidak") << endl;

    return 0;

}
