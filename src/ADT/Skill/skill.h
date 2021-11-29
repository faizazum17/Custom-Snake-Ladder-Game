#ifndef SKILL_H
#define SKILL_H

#include "../../boolean.h"
#include "../ListLinier/listlinier.h"
#include <stdlib.h>

#define Nil NULL

int chance (int x);
// Menentukan rentang int yang nantinya akan presentase dari 
// skill yang akan di dapatkan dan mengembalikan int

void getSkill(List *skill);
// I.S. List mungkin kosong dan terdefinisi
// F.S. Jika list kosong dan belum penuh akan diinsert element ke dalam list terakhir, 
// jika list penuh akan mengembalikan warning bahwa list penuh
// Dilakukan randomisasi berdasarkan rentang int yang telah didefinisikan dalam fungsi chance,
// Hasil dari randomisasi akan menentukan skill yang didapatkan oleh pemain.

void displaySkill(List skill);
// I.S. List mungkin kosong dan terdefinisi, serta isi list skill juga terdefinisi
// F.S. Jika list tidak kosong makan akan ditampilkan skill yang sedang dimiliki pemain, dan jika kosong akan mengembalikan warning
// Menampilkan skill yang dimiliki pemain sesuai dengan element yang terdapat pada list

void BuangSkill (List *skill, int count);
// I.S. List mungkin kosong dan terdefinisi, serta isi list skill juga terdefinisi. Menerima input int
// F.S. Jika list tidak kosong makan akan ditampilkan skill yang sedang dimiliki pemain, dan jika kosong akan mengembalikan warning
// Menerima inputs dari pengguna dan akan malukan penghapusan elemet pada list skill sesuai input yang dimasukkan.

void getSkill2(List *skill);
// I.S. List mungkin kosong dan terdefinisi
// F.S. Jika list kosong dan belum penuh akan diinsert element ke dalam list terakhir, 
// jika list penuh akan mengembalikan warning bahwa list penuh
// Dilakukan randomisasi berdasarkan rentang int yang telah didefinisikan dalam fungsi chance,
// Hasil dari randomisasi akan menentukan skill yang didapatkan oleh pemain.

void cerminPengganda(List *skill);
// I.S. List mungkin kosong dan terdefinisi
// F.S. Hasil pengembalian dari getskill2 akan dimasukkan kedalam list
// Menjalankan prosedur getSkill2 dua kali untuk mendapatkan skill 2 kali

#endif

