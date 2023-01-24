#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(int argc, char **argv){
    argCheck(argc, argv[1]);
    struct parameterek p;
    strcpy(p.elso, argv[1]);
    p.masodik = atoi(argv[2]);
    for(int i = 3; i < argc; i++){
        FILE *fp;
        fp = fopen(argv[i], "r");
        if(!fp){
            printf("File opening unsuccessful: %s\n", argv[i]);
            continue;
        }
        rev(fp, p);
    }
    if(argc == 3){
        rev(stdin, p);
    }
}