#include <stdio.h>
#include "map.h"
#include "../Array/array.h"


void ConfigureMap (Map *map){
    int panjang;
    int i = 1;
    STARTKATA(); //mulai membaca yang ada di map
    ConverterCharInt(CKata, &panjang, 10); // membaca panjang map
    Length(*map) = panjang;

    IgnoreBlank();
    while (i < (panjang + 1)){ // memasukkan info tiap kotak sampai panjang dari map dengan isi kotak berupa karakter '.' atau '#'
        (*map).Config.TI[i] = CC;
        ADV();
        i++;
    }

    ADVKATA();
    int x;
    ConverterCharInt(CKata, &x, 10); // membaca nilai maksimum yang dapat dihasilkan dadu
    MaxRoll(*map) = x;

    ADVKATA();
    int NTel;
    ConverterCharInt(CKata, &NTel, 10); // membaca banyaknya teleport
    NTeleport(*map) = NTel;

    int awal;
    int keluar;
    i = 1;
    Teleport(*map).Neff = (NTel+1);
    while (i < (Teleport(*map).Neff)){ //melakukan looping untuk membaca petak yang berisi teleporter
        ADVKATA();
        ConverterCharInt(CKata, &awal, 10); //membaca petak yang berisi teleporter
        IsTeleport(*map).TI[i] = awal;
        AllMap(*map).TI[awal] = 1; //petak tersebut akan diberi nilai 1 untuk menandakan bahwa petak tersebut berisi teleporter
        ADVKATA();
        ConverterCharInt(CKata, &keluar, 10); //membaca petak keluaran dari petak teleporter tersebut
        (Teleport(*map).TI[awal] = keluar); 
        i++;
    }

    IsNotTeleport(*map).Neff = Length(*map) +1;
    int b = 1;
    for (int p = 1; p < IdxMax; p++){ //untuk memasukkan informasi petak yang tidak berisi teleporter
        int flag = 0;
        for (int i = 1; i < (Teleport(*map).Neff); i++){
            if (p == IsTeleport(*map).TI[i]){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            IsNotTeleport(*map).TI[b] = p;
            AllMap(*map).TI[p] = 2; //petak tersebut akan diberi nilai 2 untuk menandakan bahwa petak tersebut tidak berisi teleporter
            b++;
        }
    }
}

int ConverterCharInt (Kata CKata, int *hasilConvert, int Kelipatan){ 
    int panjang = CKata.Length;
    int i = panjang -1;
    (*hasilConvert) = ((int) CKata.TabKata[panjang] - 48); //Ascii number char 0 = dec 48, jadi kalo ada karakter 1 (yaitu 49) - 48 menghasilkan integer 1
    int Kelipatannya = Kelipatan;
    while (i >= 1){
        (*hasilConvert) = (*hasilConvert) + Kelipatannya*((int) CKata.TabKata[i] - 48);
        Kelipatannya *= Kelipatan;
        i--;
    }
}
