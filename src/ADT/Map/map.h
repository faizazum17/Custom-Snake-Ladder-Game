#ifndef __MAP_H__
#define __MAP_H__

#include "../Mesinkata/mesin_kata.h"
#include "../Mesinkar/mesin_kar.h"
#include "../Array/array.h"
#include <stdio.h>


typedef struct{ //membuat ADT MAP
    int Length; //menyimpan informasi panjang map
    int MaxRoll; //menyimpan informasi maximal roll
    int NTeleport; //menyimpan informasi jumlah teleporter
    TabInt Config; //menyimpan informasi setiap petak dari map yang dibaca melalui file konfigurasi
    TabInt Teleport; //menyimpan informasi petak keluaran dari teleporter
    TabInt IsTeleport; // menyimpan informasi petak yang memiliki teleporter
    TabInt IsNotTeleport; // menyimpan informasi petak yang tidak memiliki teleporter
    TabInt AllMap; // menyimpan penanda di setiap map apakah merupakan teleporter atau bukan
} Map;

#define Length(Map) (Map).Length
#define MaxRoll(Map) (Map).MaxRoll
#define NTeleport(Map) (Map).NTeleport
#define Config(Map) (Map).Config
#define Teleport(Map) (Map).Teleport
#define IsTeleport(Map) (Map).IsTeleport
#define IsNotTeleport(Map) (Map).IsNotTeleport
#define AllMap(Map) (Map).AllMap


void ConfigureMap (Map *map);
/*membaca file konfigurasi menjadi peta*/

int ConverterCharInt (Kata CKata, int *hasilConvert, int Kelipatan);
/*fungsi untuk mengubah karakter menjadi integer*/

#endif
