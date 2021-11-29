#ifndef __ROLL_H__
#define __ROLL_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../Map/map.h"
#include "../Mesinkata/mesin_kata.h"
#include "../Mesinkar/mesin_kar.h"
#include "../Array/array.h"

int randomize(time_t t, int Max);
// Fungsi ini akan melakukan randomisasi int berdasarkan masukkan Max  

int roll(int buffSkill, int maxRoll);
// Fungsi ini akan melakukan roll sehingga pemain akan mendapatkan angka dari mulai 1 hingga maxRoll sesuai file konfigurasi
// Fungsi ini akan mereturn int

void printRoll();

#endif