# TUGAS BESAR IF2111 (CUSTOM SNAKE AND LADDER GAME)

## DESKRIPSI PROGRAM

Program yang dibuat bernama MobiTangga yang merupakan sebuah permainan yang konsepnya serupa dengan board game ular tangga namun digitalisasi dan diberi tambahan beberapa modifikasi yang dapat menguntungkan pemainnya seperti pada permainan ini pemain akan memiliki fitur skill yang beragam dan dengan efek yang berbeda-beda, selain itu juga ada beberapa fitur lainnya yang menjadikan playstyle masing-masing pemain menjadi beragam dan menambah keseruan dari permainan. Saat program dimulai, pemain akan disambut oleh banner dari permainan dan pemain juga dihadapkan oleh main menu yang menyediakan opsi untuk memulai permainan dan keluar dari permainan. Sebelum memulai permainan, pemain akan diminta untuk memberi masukkan seperti berapa jumlah orang yang akan bermain dan nama dari pemain. Kemudian, program akan membaca file konfigurasi yang telah dibuat dengan tujuan untuk memetakan arena bermainnya dari mulai panjang permainan, jumlah maksimal roll sampai letak teleportasi. Setiap giliran pemain akan memulai permainan dengan diberikan satu skill secara acak. Setelah itu, program akan diberi input yang berupa command oleh pemain dan program akan menjalankan bagian yang sesuai dengan masukan dari pemain tersebut. Program ini dijalankan dengan menggunakan command prompt yang secara garis besar dapat melakukan perintah seperti SKILL, MAP, ROLL, INSPECT, ENDTURN, dan UNDO. Permainan akan berakhir apabila sudah ada pemain yang sampai ke petak N sesuai konfigurasi yang telah ditentukan. 

Permainan Mobitangga diimplementasikan dengan memakai bahasa C berbasis text melalui command line(CLI) dan memanfaatkan ADT yang telah dipelajari pada mata kuliah IF2111 - Algoritma dan Struktur Data. Namun juga terdapat beberapa ADT tambahan yang dibuat tersendiri untuk mendukung keberjalanan program ini. 


## CARA KOMPILASI PROGRAM

gcc ./src/ADT/Command/command.c ./src/ADT/Mesinkar/mesin_kar.c ./src/ADT/Mesinkata/mesin_kata.c ./src/ADT/Teleporter/teleporter.c ./src/ADT/Roll/roll.c ./src/ADT/Map/map.c ./src/ADT/Player/player.c ./src/ADT/ListLinier/listlinier.c ./src/ADT/Skill/skill.c ./src/ADT/Stack/stack.c ./src/banner.c ./src/console.c ./src/main.c -o main

## CARA KOMPILASI PROGRAM
Run main.exe
