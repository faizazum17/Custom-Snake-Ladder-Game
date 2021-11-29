#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "../Map/map.h"
#include "../Mesinkata/mesin_kata.h"
#include "../Mesinkar/mesin_kar.h"
#include "../Array/array.h"

int randomize(time_t t, int Max){
// Fungsi ini akan melakukan randomisasi int berdasarkan masukkan Max  
    return rand() % Max;
}

int roll(int buffSkill, int maxRoll){
// Fungsi ini akan melakukan roll sehingga pemain akan mendapatkan angka dari mulai 1 hingga maxRoll sesuai file konfigurasi
// Fungsi ini akan mereturn int
    time_t t;
    srand((unsigned) (time(&t)));
    int Max;
    int angkaAtas, angkaBawah;
    if (buffSkill == 1){ // skill 1 = senter pembesar hoki
        // Buff ini berfungsi untuk mempersempit rentang angka yang dapat didapatkan oleh pemain
        // Buff ini akan mengatur batas bawah menjadi maxRoll/2 dan batas atas menjadi maxRoll sesuai file konfigurasi
        angkaAtas = maxRoll;
        angkaBawah = maxRoll/2;
    }else if (buffSkill == 2){ // skill 2 = senter pengecil hoki
        // Buff ini berfungsi untuk mempersempit rentang angka yang dapat didapatkan oleh pemain
        // Buff ini akan mengatur batas bawah menjadi 1 dan batas atas menjadi maxRoll/2 sesuai file konfigurasi
        angkaAtas = maxRoll/2;
        angkaBawah = 1;
    }else{
        angkaAtas = maxRoll;
        angkaBawah = 1;
    }
    Max = (angkaAtas - angkaBawah + 1);
    return (randomize(t, Max) + angkaBawah);
}

void printRoll(){
    const int trigger = 500; // ms
    const int numDots = 4;
    const char prompt[] = "Rolling";

    for (int i= 0; i < 1; i++) {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
        fflush(stdout);

        // Print numDots number of dots, one every trigger milliseconds.
        for (int i = 0; i < numDots; i++) {
            usleep(trigger * 1000);
            fputc('.', stdout);
            fflush(stdout);
        }
    }
    printf("\n");
}
