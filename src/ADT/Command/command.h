#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "../Mesinkar/mesin_kar.h"
#include "../Mesinkata/mesin_kata.h"
#include "../Player/player.h"
#include "../Map/map.h"
#include "../../boolean.h"
#include "../Stack/stack.h"


boolean IsSkill(Kata kata); //untuk mengecek apakah inputan kata adalah skill

boolean IsMap(Kata kata); //untuk mengecek apakah inputan kata adalah map

boolean IsBuff(Kata kata); //untuk mengecek apakah inputan kata adalah buff

boolean IsInspect(Kata kata); //untuk mengecek apakah inputan kata adalah inspect

boolean IsRoll(Kata kata); //untuk mengecek apakah inputan kata adalah roll

boolean IsSave(Kata kata); //untuk mengecek apakah inputan kata adalah save

boolean IsEndturn(Kata kata); //untuk mengecek apakah inputan kata adalah endturn

boolean IsUndo(Kata kata); //untuk mengecek apakah inputan kata adalah undo

void command(Map *map, Player *P, int *giliran, int *ronde, Stack *s);
/* I.S. map, P, giliran, ronde, s terdefinisi sembarang */
/* F.S. P, giliran, ronde, dan stack berubah sesuai dengan yang terjadi saat player bermain */
/* Mengubah informasi yang terdapat di dalam P, giliran, ronde, dan stack sesuai
   proses command saat bermain yang dilakukan oleh user */

#endif