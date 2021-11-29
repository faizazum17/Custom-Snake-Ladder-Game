#include <stdio.h>
#include "../Map/map.h"
#include "../Array/array.h"
#include "../Mesinkar/mesin_kar.h"
#include "../Mesinkata/mesin_kata.h"

int teleport(int posisi){
//I.S : posisi terdefinisi (selain petak pertama dan terakhir)
// F.S Mengembalikan posisi dalam int yang nantinya akan menjadi petak keluar teleporter.    
    int idx;
    Map map;
    ConfigureMap(&map);
    boolean check = false;
    for(int i = 1; i <= (NTeleport(map)); i++){
        if(IsTeleport(map).TI[i] == posisi){ 
            idx = i;
            check = true;
        }
    }
    if (check){
        posisi = Teleport(map).TI[IsTeleport(map).TI[idx]];
    }
    return posisi;
}
