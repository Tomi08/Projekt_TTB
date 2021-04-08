//
// Created by Iszlai Tamás on 4/7/2021.
//

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void beolvas(ADAT *zene) {
//    FILE *fin;
//    fin = fopen("bemenet.txt", "w+");
//    fputs("Love Harder; Amber Van Day , Oblivion (feat. Amber Van Day) , Oblivion (feat. Amber Van Day) , 00:03:12 , 2019-07-26",
//          fin);
//    fclose(fin);
//    fin = fopen("bemenet.txt", "r");
//    if (fin == NULL) {
//        perror("Error opening file");
//    }
//    char str1[200], str2[200];
//    const char s[2] = ";";
//    char *token;
//    if (fgets(str1, sizeof str1, fin) != NULL) {
//        strcpy(str2, str1);
//        token = strtok(str1, s);
//        puts(token);
//        strcpy(s, ",");
//        strcpy(str2, str2 + strlen(str1 - 2));
//        token = strtok(str2, s);
//        puts(token);
//    }
//
//    create(strlen(str1), &zene->cime);
//    zene->cime = str1;
//    puts(zene->cime);
//
//}


void create(int lenght, char *data){
    data = (char *) malloc(lenght * sizeof(char));
    }

void print(DATA *music){

}


void read(DATA *music) {
    FILE *fin;
    fin = fopen("input.csv", "r");
    if (fin == NULL) {
        perror("Error opening file");
    }

    char buffer[1000];
    int nr_of_line =0;
    while( fgets(buffer, sizeof buffer, fin) ){
        printf("Track NR%i:\n", nr_of_line+1);

        char str[1000];
        strcpy(str, buffer);
        char s[2] = ",";
        char *token;
        int lenght=0;
        token = strtok(str, s);
        create(strlen(str), &music->artist_name);
        music->artist_name = str;
        puts(music->artist_name);
        lenght += strlen(str);

        strcpy(str, buffer+lenght+2);
        token = strtok(str, s);
        create(strlen(str), &music->track_name);
        music->track_name = str;
        puts(music->track_name);
        lenght += strlen(str)+2;

        strcpy(str, buffer+lenght+2);
        token = strtok(str, s);
        create(strlen(str), &music->album_name);
        music->album_name = str;
        puts(music->album_name);
        lenght += strlen(str)+4;
        strcpy(str, buffer+lenght);
        token = strtok(str, s);

        char time[10];
        int number;
        strcpy(time,token);

        sscanf(time, "%i", &number);
        music->lenght.hour=number;

        strcpy(time,token+3);
        sscanf(time, "%i", &number);
        music->lenght.minute=number;

        strcpy(time,token+6);
        sscanf(time, "%i", &number);
        music->lenght.sec=number;

        printf("%i:%i:%i\n", music->lenght.hour, music->lenght.minute, music->lenght.sec);

        lenght+= strlen(str)+2;
        strcpy(str, buffer+lenght);

        char date[10];
        strcpy(time,token);

        sscanf(time, "%i", &number);
        music->realase_date.year=number;

        strcpy(time,token+3);
        sscanf(time, "%i", &number);
        music->realase_date.month=number;

        strcpy(time,token+6);
        sscanf(time, "%i", &number);
        music->realase_date.day=number;

        printf("%i:%i:%i\n", music->realase_date.year, music->realase_date.month, music->realase_date.day);

        printf("\n");

        nr_of_line++;
    }


}



