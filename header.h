#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct parameterek{
    char elso[30];
    int masodik;
};

void argCheck(int argumentumSzam, char *elso);
void rev(FILE* fp, struct parameterek p);



#endif