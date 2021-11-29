#include "./ADT/Map/map.h"
#include "./ADT/Mesinkata/mesin_kata.h"
#include "./ADT/Mesinkar/mesin_kar.h"
//drivermap juga merupakan driver untuk ADT MESIN KATA dan MESIN KARAKTER
//kalau dari sini gabisa membaca file konfigurasi karena beda folder, jadinya driver map seharusnya diletakkan di folder map. driver map apabila diletakkan di folder yang sama dengan main baru bisa jalan
//jadi, apabila akan melakukan pengecekan, pindahkan dulu DriverMap.c ke folder yang sama dengan main.c agar file konfigurasinya terbaca. ini tidak diletakkan di main supaya rapi.
//cara kompilasi (akan jalan apabila berada di folder yang sama dengan main.c):
//gcc ./src/ADT/Mesinkar/mesin_kar.c ./src/ADT/Mesinkata/mesin_kata.c ./src/ADT/Map/map.c ./src/DriverMap.c -o DriverMap

int main(){
    int i;
    Map map;
    ConfigureMap(&map);
    printf("Panjang dari mapnya : %d\n\n", Length(map));
    printf("Bentuk mapnya : \n");
    for (i=1; i<=Length(map); i++){
        printf("%c", (map).Config.TI[i]);
    }
    printf("\n\nMaksimal rollnya : %d\n\n", MaxRoll(map));
    printf("Jumlah teleporternya : %d\n\n", NTeleport(map));
    i = 1;
    printf("Daftar petak keluaran teleporter : \n");
    while (i<=NTeleport(map)){
        printf("%d\n", Teleport(map).TI[IsTeleport(map).TI[i]]);
        i++;
    }
    printf("\n");
    printf("Daftar petak yang tidak ada teleporter : \n");
    i = 1;
    while (i<=(Length(map) - NTeleport(map))){
        printf("%d\n", IsNotTeleport(map).TI[i]);
        i++;
    }
    printf("\n");
    printf("Daftar penanda seluruh petak, apabila ada teleporter maka akan memberikan output 1, apabila tidak ada teleporter maka akan memberikan output 2.\n");
    printf("Nomor petak terurut sesuai nomor keluaran\n");
    i = 1;
    while (i<=Length(map)){
        printf("%d\n", AllMap(map).TI[i]);
        i++;
    }
    printf("\n");
    printf("Daftar petak yang terdapat teleporter (di sebelah kiri) dan petak keluaran teleporternya(di sebelah kanan).\n");
    i = 1;
    while (i<=NTeleport(map)){
        printf("%d %d\n", IsTeleport(map).TI[i], Teleport(map).TI[IsTeleport(map).TI[i]]); //sama kaya di file konfig tampilannya (kiri, kanan) -> (tempat teleport, keluaran teleport)
        i++;
    }

    Kata testkata;
    testkata.Length = 2;
    testkata.TabKata[1] = '1';
    testkata.TabKata[2] = '9';
    int hasil;
    ConverterCharInt(testkata, &hasil, 10); //angka desimal
    printf("\n%d", hasil);
}