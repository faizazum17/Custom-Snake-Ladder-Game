#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../ListLinier/listlinier.h"
#include "../Skill/skill.h"
#include "../Roll/roll.h"
#include "../Player/player.h"

int chance (int x){
// Menentukan rentang int yang nantinya akan presentase dari 
// skill yang akan di dapatkan dan mengembalikan int
    if ((x >= 1) && (x <= 20)){
        return 1;
    }
    else if((x >= 21) && (x <= 30)){
        return 2;
    }
    else if((x >= 30) && (x <= 45)){
        return 3;
    }
    else if((x >= 46) && (x <= 60)){
        return 4;
    }
    else if((x >= 61) && (x <= 70)){
        return 5;
    }
    else{
        return 0;
    }
}

void getSkill(List *skill){
// I.S. List mungkin kosong dan terdefinisi
// F.S. Jika list kosong dan belum penuh akan diinsert element ke dalam list terakhir, 
// jika list penuh akan mengembalikan warning bahwa list penuh
// Dilakukan randomisasi berdasarkan rentang int yang telah didefinisikan dalam fungsi chance,
// Hasil dari randomisasi akan menentukan skill yang didapatkan oleh pemain.
    int x;
    time_t t;
    
    srand(time(0));
    x = rand();
    x = chance((x) % 100 + 1);
    if (x == 1){
        printf("Pintu Ga Ke Mana-Mana\n");
    }
    else if (x == 2){ 
        printf("Cermin Pengganda\n");
    }
    else if (x == 3){ 
        printf("Senter Pembesar Hoki\n");
    }
    else if (x == 4){ 
        printf("Senter Pengecil Hoki\n");
    }  
    else if (x == 5){ 
        printf("Mesin Penukar Posisi\n");
    }else{
        printf("Teknologi Gagal.\n");
    }

    if (x != 0 && NbElmt(*skill) <= 9){
        // Jika skill yang didapat bukan Teknologi gagal dan Jumlah skill kurang dari 10
        InsVLast(skill, x);
        printf("Skill ");
        printf("%d", x);
        printf(" berhasil dimasukkan\n");
        printf("\n");
    } 
    else if (x == 0 ){
        // Jika skill yang didapatkan Teknologi gagal
        printf("Punten, kamu tidak mendapat skill \n");
        printf("\n");
    }

    else if (NbElmt(*skill) >= 10){
        // Jika jumlah skill yang dimiliki lebih dari sama dengan s10
        printf("Punten, Jumlah skill udah penuh euy. Gabisa nambahin skill ini jadinya.\n");
        printf("\n");
    }
}

void displaySkill(List skill){
// I.S. List mungkin kosong dan terdefinisi, serta isi list skill juga terdefinisi
// F.S. Jika list tidak kosong makan akan ditampilkan skill yang sedang dimiliki pemain, dan jika kosong akan mengembalikan warning
// Menampilkan skill yang dimiliki pemain sesuai dengan element yang terdapat pada list
    address p;
    int count = 1;
    char listSkill[][25] = {
        "",
        "Pintu Ga Ke Mana Mana",
        "Cermin Pengganda",
        "Senter Pembesar Hoki",
        "Senter Pengecil Hoki",
        "Mesin Penukar Posisi"
    };

    p = First(skill);
    while(p != Nil){
        printf("%d. %s\n", count, listSkill[Info(p)]);
        count++;
        p = Next(p);
    }  
}

void BuangSkill (List *skill, int count){
// I.S. List mungkin kosong dan terdefinisi, serta isi list skill juga terdefinisi. Menerima input int
// F.S. Jika list tidak kosong makan akan ditampilkan skill yang sedang dimiliki pemain, dan jika kosong akan mengembalikan warning
// Menerima inputs dari pengguna dan akan malukan penghapusan elemet pada list skill sesuai input yang dimasukkan.
    address p;
    char listSkill[][25] = {
        "",
        "Pintu Ga Ke Mana Mana",
        "Cermin Pengganda",
        "Senter Pembesar Hoki",
        "Senter Pengecil Hoki",
        "Mesin Penukar Posisi"
    };

    if (!(IsEmptyList(*skill))) {
        count = count * (-1);
        DeleteI(skill, count); 
    }
    else {
        printf("Anda tidak mempunyai skill \n");  
    }
};

void getSkill2(List *skill){
// I.S. List mungkin kosong dan terdefinisi
// F.S. Jika list kosong dan belum penuh akan diinsert element ke dalam list terakhir, 
// jika list penuh akan mengembalikan warning bahwa list penuh
// Dilakukan randomisasi berdasarkan rentang int yang telah didefinisikan dalam fungsi chance,
// Hasil dari randomisasi akan menentukan skill yang didapatkan oleh pemain.
    int x;
    
    x = rand();
    x = chance((x) % 100 + 1);

    if (x == 1){
        printf("Pintu Ga Ke Mana-Mana\n");
    }
    else if (x == 2){ 
        printf("Cermin Pengganda\n");
    }
    else if (x == 3){ 
        printf("Senter Pembesar Hoki\n");
    }
    else if (x == 4){ 
        printf("Senter Pengecil Hoki\n");
    }  
    else if (x == 5){ 
        printf("Mesin Penukar Posisi\n");
    }else{
        printf("Teknologi Gagal.\n");
    }

    if (x != 0 && NbElmt(*skill) <= 9){
        InsVLast(skill, x);
        printf("Skill ");
        printf("%d", x);
        printf(" berhasil dimasukkan\n");
        printf("\n");
    } 
    else if (x == 0){
        printf("Punten, kamu tidak mendapat skill \n");
        printf("\n");
    }
    else if (NbElmt(*skill) >= 10){
        printf("Punten, Jumlah skill udah penuh euy. Gabisa nambahin skill ini jadinya.\n");
        printf("\n");
    }
}

void cerminPengganda(List *skill){
// I.S. List mungkin kosong dan terdefinisi
// F.S. Hasil pengembalian dari getskill2 akan dimasukkan kedalam list
// Menjalankan prosedur getSkill2 dua kali untuk mendapatkan skill 2 kali
    getSkill2(&(*skill));
    getSkill2(&(*skill)); 
}
