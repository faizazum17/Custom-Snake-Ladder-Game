#include <stdlib.h>
#include <stdio.h>
#include "roll.h"

int main(){
    START();
    Map map;
    ConfigureMap(&map);
    int maxroll = MaxRoll(map);
    printf("%d\n", roll(3, maxroll));
}