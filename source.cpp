#include <iostream>
#include <string>
#include "header.h"
using namespace std;


void create_stack(Stack &S) {
    S.top = -1; // [cite: 115, 117]
}

bool is_Empty(Stack S) {
    return S.top == -1; // [cite: 119, 122]
}

bool is_full(Stack S) {
    return S.top == N_STACK - 1; // [cite: 124, 126]
}

// a. Prosedur Push [cite: 128, 129, 130]
void push(Stack &S, infotypeStack x) {
    if (!is_full(S)) {
        S.top++;
        S.info[S.top] = x; // Menambahkan elemen ke posisi teratas [cite: 130]
    }
}

// b. Fungsi Pop [cite: 133, 134, 136, 137]
infotypeStack pop(Stack &S) {
   if (!is_Empty(S)) {
        infotypeStack x = S.info[S.top];
        S.top--; // Mengurangi indeks top [cite: 136]
        return x;
    }
    return ""; // Mengembalikan string kosong jika stack kosong [cite: 137]
}

// c. Prosedur manageAction (Undo/Redo) [cite: 141, 142, 143, 145, 146, 147]
void manageAction(Stack &S_Aksi, Stack &S_Redo, infotypeStack aksi) {
    if (aksi == "UNDO") {
        infotypeStack temp = pop(S_Aksi); // Hapus dari Aksi [cite: 145]
        if (temp != "") {
            push(S_Redo, temp); // Pindahkan ke Redo [cite: 145]
        }
    } else if (aksi == "REDO") {
        infotypeStack temp = pop(S_Redo); // Hapus dari Redo [cite: 146]
        if (temp != "") {
            push(S_Aksi, temp); // Pindahkan kembali ke Aksi [cite: 146]
        }
    } else {
        push(S_Aksi, aksi); // Tambahkan aksi baru [cite: 147]
        create_stack(S_Redo); // S_Redo dikosongkan [cite: 147]
    }
}

// d. Fungsi totalDamage [cite: 154, 155, 157]
int totalDamage(Stack &S) {
    int total = 0;
    while (!is_Empty(S)) {
        infotypeStack aksi = pop(S); // Membaca dan mengeluarkan aksi [cite: 154]
        if (aksi == "ATTACK") {
            total += 30; // Damage ATTACK = 30 [cite: 102]
        } else if (aksi == "DEFENSE") {
            total += 5; // Damage DEFENSE = 5 [cite: 102]
        }
    }
    return total; // Mengembalikan total damage [cite: 157]
}
