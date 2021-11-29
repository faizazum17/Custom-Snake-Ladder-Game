#include "command.h"
#include <stdio.h>
#include <string.h>
#include "../Mesinkar/mesin_kar.h"
#include "../Mesinkata/mesin_kata.h"
#include "../../boolean.h"
#include "../Teleporter/teleporter.h"
#include "../Roll/roll.h"
#include "../Map/map.h"
#include "../Player/player.h"
#include "../Skill/skill.h"
#include "../Stack/stack.h"

boolean IsSkill(Kata kata){
    int bener = 0;
    int Length_skill = 5;
    char SKILL[5] = {'S', 'K', 'I', 'L', 'L'};
    char skill[5] = {'s', 'k', 'i', 'l', 'l'};
    for(int i = 1; i <= kata.Length; i++){

        if ((CKata.TabKata[i] == SKILL[i-1]) || (CKata.TabKata[i] == skill[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_skill){
        if (bener == Length_skill){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsMap(Kata kata){
    int bener = 0;
    int Length_map = 3;
    char MAP[3] = {'M', 'A', 'P'};
    char map[3] = {'m', 'a', 'p'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == MAP[i-1]) || (CKata.TabKata[i] == map[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_map){
        if (bener == Length_map){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsBuff(Kata kata){
    int bener = 0;
    int Length_buff = 4;
    char BUFF[4] = {'B', 'U', 'F', 'F'};
    char buff[4] = {'b', 'u', 'f', 'f'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == BUFF[i-1]) || (CKata.TabKata[i] == buff[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_buff){
        if (bener == Length_buff){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsInspect(Kata kata){
    int bener = 0;
    int Length_inspect = 7;
    char INSPECT[7] = {'I', 'N', 'S', 'P', 'E', 'C', 'T'};
    char inspect[7] = {'i', 'n', 's', 'p', 'e', 'c', 't'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == INSPECT[i-1]) || (CKata.TabKata[i] == inspect[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_inspect){
        if (bener == Length_inspect){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsRoll(Kata kata){
    int bener = 0;
    int Length_roll = 4;
    char ROLL[4] = {'R', 'O', 'L', 'L'};
    char roll[4] = {'r', 'o', 'l', 'l'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == ROLL[i-1]) || (CKata.TabKata[i] == roll[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_roll){
        if (bener == Length_roll){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsSave(Kata kata){
    int bener = 0;
    int Length_save = 4;
    char SAVE[4] = {'S', 'A', 'V', 'E'};
    char save[4] = {'s', 'a', 'v', 'e'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == SAVE[i-1]) || (CKata.TabKata[i] == save[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_save){
        if (bener == Length_save){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsEndturn(Kata kata){
    int bener = 0;
    int Length_endturn = 7;
    char ENDTURN[7] = {'E', 'N', 'D', 'T', 'U', 'R', 'N'};
    char endturn[7] = {'e', 'n', 'd', 't', 'u', 'r', 'n'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == ENDTURN[i-1]) || (CKata.TabKata[i] == endturn[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_endturn){
        if (bener == Length_endturn){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

boolean IsUndo(Kata kata){
    int bener = 0;
    int Length_undo = 4;
    char UNDO[4] = {'U', 'N', 'D', 'O'};
    char undo[4] = {'u', 'n', 'd', 'o'};
    for(int i = 1; i <= kata.Length; i++){
        if ((CKata.TabKata[i] == UNDO[i-1]) || (CKata.TabKata[i] == undo[i-1])){
            bener++;
        }
    }
    if (kata.Length == Length_undo){
        if (bener == Length_undo){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void command(Map *map, Player *P, int *giliran, int *ronde, Stack *s){
    boolean endturn = false;
    while (!endturn){ //apabila player belum mengakhiri turnnya atau belum ada case yang menyebabkan terjadinya endturn, maka player akan terus menjalankan command
        printf ("Masukkan command: ");
        STARTforCommand(); // meminta inputan player
        int maxroll = MaxRoll(*map); // membuat variabel maxroll yang berisi MaxRoll yang dibaca dari file konfigurasi agar mudah mengaksesnya
        if (IsSkill(CKata)){ //apabila inputan player berupa skill maka akan masuk ke kondisi ini
            if (NbElmt((*P).TabPlayer[*giliran].skills) == 0){ //apabila element list skillnya = 0 maka akan memunculkan pesan tidak memiliki skill
                printf("Kamu ga punya skill apa apa nih :(\n");
            }else{  //apabila element list skillnya != 0 maka akan masuk ke kondisi ini
                printf("\nKamu memiliki skill: \n");
                displaySkill((*P).TabPlayer[*giliran].skills); // menampilkan skill yang dimiliki player
                printf("\nTekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\n");
                int input;
                printf ("Masukkan skill: ");
                scanf("%d", &input); //asumsi inputan benar
                while (input != 0 && NbElmt((*P).TabPlayer[*giliran].skills) != 0){ //apabila inputannya != 0 dan jumlah skillnya juga != 0 akan selalu menjalankan proses didalam loop ini
                    if (input > 0 && input <= NbElmt((*P).TabPlayer[*giliran].skills))
                    { // apabila inputnya lebih dari 0 dan inputannya kurang dari sama dengan jumlah skill yang dimiliki maka akan masuk ke kondisi ini
                        if (!((*P).TabPlayer[*giliran].isRolled)){ //apabila belum ngeroll maka akan masuk ke kondisi ini
                            useSkill((&(*P)), input, *giliran); // memanggil fungsi untuk mengaktifkan buff dan menggunakan skill

                        }else{//apabila sudah ngeroll maka akan memunculkan pesan di bawah ini
                            printf("Punten, kalo udah ngeroll gabisa make skill lagi gan.\n");
                        }
                    }
                    else if (input < 0 && (input * (-1)) <= NbElmt((*P).TabPlayer[*giliran].skills))
                    { // apabila inputnya kurang dari 0 dan inputannya jika dimutlakkan kurang dari sama dengan jumlah skill yang dimiliki maka akan masuk ke kondisi ini
                        input = input * (-1);
                        printf("\n");
                        showName(&(*P), *giliran);
                        printf(" membuang skill ");
                        ShowSkill((*P).TabPlayer[*giliran].skills, input); 
                        if (!(IsEmptyList((*P).TabPlayer[*giliran].skills))) {
                            DeleteI(&((*P).TabPlayer[*giliran].skills), input);  //membuang skill sesuai inputan
                        }
                        else {
                            printf("Anda tidak mempunyai skill \n");  
                        }
                    }else{ //diluar kondisi di atas maka akan mengeluarkan pesan di bawah ini.
                        printf("Inputan angkamu salah!\n");
                    }
                    if (NbElmt((*P).TabPlayer[*giliran].skills) == 0){ //kondisi jumlah skill = 0
                        printf("Sekarang kamu ga punya skill apa apa nih :(\n");
                    }else{//jika jumlah skill != 0 maka akan menampilkan sisa skill yang dimiliki
                        printf("\n\nKamu memiliki skill: \n");
                        displaySkill((*P).TabPlayer[*giliran].skills); //menampilkan skill yang dimiliki
                    }
                    printf("\nTekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.");
                    printf("\nMasukkan skill: ");
                    scanf("%d", &input); //meminta inputan kembali dan menjalankan loop dari atas lagi
                }
                if (input == 0) //keluar dari command skill apabila input = 0
                {
                    printf("\n");
                    showName(&(*P), *giliran);
                    printf(" keluar dari command SKILL\n");
                }    
            }
        }else if (IsMap(CKata)){ //apabila inputan player berupa map maka akan masuk ke kondisi ini
            int nomorPemain;
            printf("\n========== POSISI SAAT INI ==========\n\n");
            for (nomorPemain = 1; nomorPemain <= jumlah(*P); nomorPemain++){ //melakukan looping dari player pertama sampai terakhir
                printf("%s  : ", (*P).TabPlayer[nomorPemain].pName);
                for (int i=1; i <= Length(*map); i++){ //melakukan looping sampai dengan panjang map
                    if (i != (*P).TabPlayer[nomorPemain].position){ //apabila nomor petak tidak sama dengan posisi player maka akan menampilkan bentuk petak mapnya
                        printf("%c", (*map).Config.TI[i]); //menampilkan isi map
                    }else{//apabila nomor petak sama dengan posisi player maka akan menampilkan bintang yang menandakan posisi player
                        printf("*"); 
                    }
                }
                printf("  %d\n", (*P).TabPlayer[nomorPemain].position); //menampilkan posisi player
            }
            printf("\n====================================\n\n");
        }else if (IsBuff(CKata)){ //apabila inputan player berupa buff maka akan masuk ke kondisi ini
            int Buff = 0; // buff disetting 0
            if ((*P).TabPlayer[*giliran].TabBuff[*giliran].isImmuned){ //apabila buff imunitas player true maka akan melakukan print di bawah ini
                printf("Buff Imunitas Teleport Aktif.\n");
                Buff++; //terjadi penambahan buff
            }
            if ((*P).TabPlayer[*giliran].TabBuff[*giliran].isCerminGanda){ //apabila buff cermin pengganda milik player true maka akan melakukan print di bawah ini
                printf("Buff Cermin Pengganda Aktif.\n");
                Buff++; //terjadi penambahan buff
            }
            if((*P).TabPlayer[*giliran].TabBuff[*giliran].isSenterPembesar){ //apabila buff senter pembesar player true maka akan melakukan print di bawah ini
                printf("Buff Senter Pembesar Hoki Aktif.\n");
                Buff++;//terjadi penambahan buff
            }
            if ((*P).TabPlayer[*giliran].TabBuff[*giliran].isSenterPengecil){ //apabila buff senter pengecil player true maka akan melakukan print di bawah ini
                printf("Buff Senter Pengecil Hoki Aktif. \n");
                Buff++; //terjadi penambahan buff
            }
            if (Buff == 0){ //apabila tidak terjadi penambahan buff sama sekali maka akan menunjukkan pesan bahwa belum ada buff yang aktif
                printf("Belum ada buff yang aktif.\n");
            }
        }
        else if (IsInspect(CKata)){ //apabila inputan player berupa inspect maka akan masuk ke kondisi ini
            int nomorPetak;
            printf("Masukkan petak: "); 
            scanf("%d", &nomorPetak);//meminta inputan petak yang ingin dicek
            if ((*map).Config.TI[nomorPetak] == '#'){ //kalau bentuk isi petak = # maka akan mengatakan bahwa itu adalah petak terlarang
                printf("Petak %d merupakan petak terlarang.\n", nomorPetak);
                printf("\n");
            }else{ //kalau bentuk isi petak = . maka akan masuk ke kondisi ini
                if (teleport(nomorPetak) != nomorPetak){  // jika ada teleporter di petak tersebut maka akan menampilkan bahwa petak tersebut memiliki teleporter dan menunjukkan keluaran teleporternya
                    // kondisi yang menandai bahwa di petak tersebut ada teleporternya adalah, keluaran petak tidak sama dengan nomor petaknya
                    printf("Petak %d memiliki teleporter menuju %d.\n", nomorPetak, teleport(nomorPetak));
                    printf("\n");
                }else{  // jika tidak ada teleporter di petak tersebut maka akan menampilkan bahwa petak tersebut adalah petak kosong
                    printf("Petak %d merupakan petak kosong.\n", nomorPetak);
                    printf("\n");
                }
            }
        }
        else if (IsRoll(CKata)){//apabila inputan player berupa roll maka akan masuk ke kondisi ini
            if (!((*P).TabPlayer[*giliran].isRolled)){ //apabila belum ngeroll maka akan masuk ke kondisi ini
                int hasil_roll; 
                int rollmaju, rollmundur;
                if ((*P).TabPlayer[*giliran].TabBuff[*giliran].isSenterPembesar){ //apabila buff senter pembesar true maka hasil roll akan menyesuaikan
                    hasil_roll = roll(1, maxroll); //randomize roll untuk buff senter pembesar
                    (*P).TabPlayer[*giliran].TabBuff[*giliran].isSenterPembesar = false;
                }else if ((*P).TabPlayer[*giliran].TabBuff[*giliran].isSenterPengecil){ //apabila buff senter pengecil true maka hasil roll akan menyesuaikan
                    hasil_roll = roll(2, maxroll);//randomize roll untuk buff senter pengecil
                    (*P).TabPlayer[*giliran].TabBuff[*giliran].isSenterPengecil = false;
                }else{
                    hasil_roll = roll(3, maxroll);//randomize roll tanpa buff
                }
                rollmaju = ((*P).TabPlayer[*giliran].position) + hasil_roll; //variable rollmaju menyimpan posisi player ditambah hasil randomize roll
                rollmundur = ((*P).TabPlayer[*giliran].position) - hasil_roll; //variable rollmaju menyimpan posisi player dikurang hasil randomize roll
                printRoll();
                showName(&(*P), *giliran);
                printf(" mendapatkan angka %d\n", hasil_roll);
                int move = 0; 
                if ((rollmaju <= Length(*map)) && (rollmundur >= 1) && ((*map).Config.TI[rollmaju] != '#') && ((*map).Config.TI[rollmundur] != '#')){
                // apabila rollmaju dan rollmundur masih di dalam map dan hasil rollmaju dan rollmundur tidak membuat player berada di petak terlarang maka player diminta untuk memilih mau maju atau mundur
                    showName(&(*P), *giliran);
                    printf(" dapat maju dan mundur.\n");
                    printf("Kemana ");
                    showName(&(*P), *giliran);
                    printf(" mau bergerak?\n");
                    printf("1. %d\n", rollmundur);
                    printf("2. %d\n", rollmaju);
                    int choosenMove;
                    printf("Masukkan pilihan : ");
                    scanf("%d", &choosenMove);
                    boolean valid = false;
                    while (!valid){ //akan melakukan looping sampai inputan pilihan player benar
                        if (choosenMove == 2 || choosenMove == 1){
                            valid = true;
                            if (choosenMove == 1){
                                ((*P).TabPlayer[*giliran].position) = rollmundur; //memilih mundur, maka posisi player sekarang sesuai hasil rollmundur
                                showName(&(*P), *giliran);
                                printf(" mundur %d langkah.\n", hasil_roll);
                                showName(&(*P), *giliran);
                                printf(" berada di petak %d.\n", (*P).TabPlayer[*giliran].position);
                            }else{
                                ((*P).TabPlayer[*giliran].position) = rollmaju; //memilih maju, maka posisi player sekarang sesuai hasil rollmaju
                                showName(&(*P), *giliran);
                                printf(" maju %d langkah.\n", hasil_roll);
                                showName(&(*P), *giliran);
                                printf(" berada di petak %d.\n", (*P).TabPlayer[*giliran].position);
                            }
                        }else{
                            printf("Pilihan angka tidak valid\n");
                            printf("Masukkan kembali angka 1 atau 2 sesuai petak yang dipilih : ");
                            scanf("%d", &choosenMove);
                        }
                    }
                    move = 1; //menandakan bahwa player bergerak di kondisi 1
                }else if (((*map).Config.TI[rollmaju] != '#') && (rollmaju <= Length(*map))){
                // apabila rollmaju tidak menyebabkan player berada di petak terlarang dan hasil roll maju kurang dari/sama dengan panjang map maka player otomatis maju
                    (*P).TabPlayer[*giliran].position = rollmaju;
                    showName(&(*P), *giliran);
                    printf(" dapat maju.\n");
                    showName(&(*P), *giliran);
                    printf(" maju %d langkah.\n", hasil_roll);
                    showName(&(*P), *giliran);
                    printf(" berada di petak %d.\n", (*P).TabPlayer[*giliran].position);
                    move = 2; //menandakan bahwa player bergerak di kondisi 2
                }else if(((*map).Config.TI[rollmundur] != '#') && (rollmundur >= 1)){
                // apabila rollmundur tidak menyebabkan player berada di petak terlarang dan hasil roll mundur lebih dari/sama dengan 1 maka player otomatis mundur
                    (*P).TabPlayer[*giliran].position = rollmundur;
                    showName(&(*P), *giliran);
                    printf(" dapat mundur.\n");
                    showName(&(*P), *giliran);
                    printf(" mundur %d langkah.\n", hasil_roll);
                    showName(&(*P), *giliran);
                    printf(" berada di petak %d.\n", (*P).TabPlayer[*giliran].position);
                    move = 3; //menandakan bahwa player bergerak di kondisi 3
                }else{
                //apabila tidak memenuhi semua kondisi di atas maka player tidak dapat bergerak
                    showName(&(*P), *giliran);
                    printf(" tidak dapat bergerak.\n");
                }
                if (move != 0){ //Apabila player bergerak, dalam kondisi berapapun maka akan masuk ke kasus di bawah ini untuk mengecek teleporter
                    if (AllMap(*map).TI[(*P).TabPlayer[*giliran].position] == 2){ //dalam map, angka 2 menandakan tidak ada teleporter. jika posisi player berada di petak bertanda 2 maka tidak akan teleport ke manapun
                        showName(&(*P), *giliran);
                        printf(" tidak menemukan teleporter.\n");
                    }else{ //apabila nilai petak != 2 berarti terdapat teleporter
                        showName(&(*P), *giliran);
                        printf(" menemukan teleporter.\n");
                        if (!((*P).TabPlayer[*giliran].TabBuff[*giliran].isImmuned)){ //apabila buff imunitas teleport player false maka player otomatis keluar di keluaran teleporter petak posisinya
                            showName(&(*P), *giliran);
                            printf(" tidak memiliki imunitas teleport.\n");
                            (*P).TabPlayer[*giliran].position = teleport((*P).TabPlayer[*giliran].position); //posisi player berubah sesuai keluaran teleporter petaknya
                            showName(&(*P), *giliran);
                            printf(" teleport ke petak %d.\n", (*P).TabPlayer[*giliran].position);
                        }else{//apabila buff imunitas teleport player true maka player akan ditanyakan apakah mau teleport atau tidak
                            showName(&(*P), *giliran);
                            printf(" memiliki imunitas teleport.\n");
                            printf("Apakah ");
                            showName(&(*P), *giliran);
                            printf(" ingin teleport (Y/N)?");
                            char tel;
                            scanf(" %c", &tel);
                            boolean valid = false;
                            while (!valid){ //mengecek masukan player sampai valid, yaitu bernilai Y atau N saja
                                if (tel == 'N' || tel == 'Y'){
                                    valid = true;
                                    if (tel == 'N'){ //tidak teleport, maka posisi player tetap di petak tersebut dan tidak berpindah ke keluaran teleporter petaknya
                                        showName(&(*P), *giliran);
                                        printf(" tidak teleport.\n"); 
                                        printf("Buff imunitas teleport hilang.\n"); 
                                        (*P).TabPlayer[*giliran].TabBuff[*giliran].isImmuned = false;
                                    }else{//teleport, maka posisi player berubah sesuai keluaran teleporter petaknya
                                        (*P).TabPlayer[*giliran].position = teleport((*P).TabPlayer[*giliran].position);
                                        showName(&(*P), *giliran);
                                        printf(" teleport ke petak %d.\n", (*P).TabPlayer[*giliran].position);
                                    }
                                }else{ //inputan selain N atau Y akan menampilkan pesan di bawah ini dan meminta inputan kembali
                                    printf("Salah input. Hanya bisa membaca input Y untuk iya dan N untuk tidak.\n");
                                    printf("Masukkan input kembali : ");
                                    scanf("%c", &tel);
                                }
                            }
                        }
                    }
                }
                (*P).TabPlayer[*giliran].isRolled = true; //penanda bahwa player telah melakukan roll
            }else{ //apabila telah melakukan roll maka player tidak bisa roll lagi
                printf("Tidak bisa roll 2 kali.\n");
            }
            if ((*P).TabPlayer[*giliran].position == Length(*map)){ //apabila saat melakukan roll posisi player sudah di ujung maka player langsung menang, kemudian turn akan diakhiri dan game berhenti
                showName(&(*P), *giliran);
                printf(" telah mencapai ujung.\n");
                printf("Pemenang game ini adalah ");
                showName(&(*P), *giliran);
                printf("\n");
                endturn = true;
            }
        }
        else if (IsEndturn(CKata)){ //apabila inputan player berupa endturn maka akan masuk ke kondisi ini
            if ((*P).TabPlayer[*giliran].isRolled){ //kalau sudah ngeroll baru bisa endturn
                endturn = true; // untuk mengakhiri turn
            }else{// kalo belum ngeroll maka akan menampilkan pesan di bawah ini
                printf("Harus roll dulu baru bisa endturn.\n");
            }
        }
        else if (IsUndo(CKata)){//apabila inputan player berupa undo maka akan masuk ke kondisi ini
            if ((*giliran) == 1){ // apabila yang melakukan undo adalah player pertama maka akan ditanyakan apakah ingin undo lagi
                printf("\n");
                Pop(&(*s), &(*P)); //membuang info permainan saat ini dari stack, sehingga topnya adalah info permainan sebelumnya
                printf("Berhasil Undo!\n");
                (*ronde)--;
                char undo;
                boolean valid = false;
                while ((*ronde) >= 1 && !valid) { //memastikan bahwa inputan user benar
                	printf("Apakah ingin melakukan Undo lagi? (Y/N) ");
                    scanf(" %c", &undo);
                	if (undo == 'Y'){
                        Pop(&(*s), &(*P));//membuang info permainan saat ini dari stack, sehingga topnya adalah info permainan sebelumnya
                        printf("\n");
                        printf("Berhasil Undo!\n");
                        (*ronde)--;
                    }
                    else if (undo == 'N'){
                        valid = true;
					}
                    else{
                        printf("Inputan hanya Y untuk ya dan N untuk tidak\n");
                    }
				}
            }else{ // apabila yang melakukan undo bukan player pertama maka hanya bisa melakukan undo sekali, dan yang main lagi adalah player pertama di ronde yang sama
                printf("\n");
                Pop(&(*s), &(*P));//membuang info permainan saat ini dari stack, sehingga topnya adalah info permainan sebelumnya
                printf("Berhasil Undo!\n");
                (*ronde)--;
            }
            endturn = true; //langsung mengakhiri turn apabila melakukan undo
            int nomorPem;
            //mereset buff seluruh pemain
            for (nomorPem = 1; nomorPem <= jumlah(*P); nomorPem++){
                (*P).TabPlayer[nomorPem].isRolled = false;
                (*P).TabPlayer[nomorPem].TabBuff[nomorPem].isSenterPembesar = false;
                (*P).TabPlayer[nomorPem].TabBuff[nomorPem].isSenterPengecil = false;
                (*P).TabPlayer[nomorPem].TabBuff[nomorPem].isCerminGanda = false;
                (*P).TabPlayer[nomorPem].TabBuff[nomorPem].isImmuned = false;
            }
            (*giliran) = 0; //di gameflow giliran akan ditambah 1, maka giliran kembali ke player pertama
        }
        else{ //apabila inputan diluar kata untuk command maka akan menampilkan pesan di bawah ini
            printf("Salah input command, coba lagi.\n");
        }
    }
}

