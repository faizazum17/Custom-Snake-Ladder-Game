#include <stdio.h>
#include "skill.h"

int main(){
    List skill;
    getSkill(&skill);
    displaySkill(skill);
    BuangSkill(&skill, -1);
    displaySkill(skill);
    getSkill2(&skill);
    displaySkill(skill);
    cerminPengganda(&skill);   
    displaySkill(skill);
    return 0;
}