#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void rev(FILE* fp, struct parameterek p){
    //memoriafoglalas
    int adottMeret = 8;
    char **sorok;
    sorok = (char **) malloc(sizeof(char *) * adottMeret);
    if(!sorok){
        free(sorok);
        printf("Memory allocation failed!\n");
        exit(3);
    }

    for(int i = 0; i < adottMeret; i++){
        sorok[i] = (char *) malloc(sizeof(char) * (p.masodik+1));
        if(!sorok[i]){
            printf("Memory allocation failed!\n");
            for(int j = 0; j <= i; j++){
                free(sorok[j]);
            }
            free(sorok);
            exit(4);
        }
    }

    //beolvasas
    char buff[500];
    int tombMeret = 0;
    int meret;
    int meddig;
    char idk[p.masodik+1];
    while(fgets(buff, 500, fp)){
        meret = strlen(buff);
        if(buff[strlen(buff) - 1] == '\n'){
            meret--;
        }
        if(p.masodik > meret){
            meddig = meret;
        } else meddig = p.masodik;
        
        for(int i = 0; i < meddig; i++){
            idk[i] = buff[i];
        }
        idk[meddig] = '\0';
        strcpy(sorok[tombMeret], idk);
        tombMeret++;
        if(tombMeret == adottMeret){ //lefoglalt terulet duplazasa
            sorok = (char **) realloc(sorok, sizeof(char *) * adottMeret*2);
            if(!sorok){
                free(sorok);
                printf("Memory allocation failed!\n");
                exit(5);
            }

            for(int i = adottMeret; i < adottMeret*2; i++){
                sorok[i] = (char *) malloc(sizeof(char) * (p.masodik+1));
                if(!sorok[i]){
                    printf("Memory allocation failed!\n");
                    for(int j = adottMeret; j <= i; j++){
                        free(sorok[j]);
                    }
                    free(sorok);
                    exit(6);
                }
            }
            adottMeret = adottMeret * 2;
        }
    }
    //kiiras
    if(strcmp(p.elso, "linenums") == 0){
        for(int i = tombMeret-1; i >= 0; i--){
            printf("%d ", (i+1));
            for(int j = strlen(sorok[i])-1; j >= 0; j--){
                printf("%c", sorok[i][j]);
            }
            printf("\n");
        }
    } else{
       for(int i = tombMeret-1; i >= 0; i--){
            for(int j = strlen(sorok[i])-1; j >= 0; j--){
                printf("%c", sorok[i][j]);
            }
            printf("\n");
        } 
    }
    
    //memoria felszabaditas
    for(int i = 0; i < adottMeret; i++){
        free(sorok[i]);
    }
    free(sorok);
    fclose(fp);

}