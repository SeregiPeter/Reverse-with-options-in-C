#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void argCheck(int argumentumSzam, char *elso){
    if(argumentumSzam < 3){
        printf("Usage:\n\trev [SHOW LINE NUMBERS] [MAX LINE LENGTH] files...");
        exit(1);
    }
    if(strcmp(elso, "linenums") != 0 && strcmp(elso, "nolinenums") != 0){
        exit(2);
    }

}