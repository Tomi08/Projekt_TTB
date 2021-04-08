//
// Created by Iszlai Tamás on 4/7/2021.
//

#ifndef PROJEKT_TTB_FUNCTIONS_H
#define PROJEKT_TTB_FUNCTIONS_H
typedef struct {
    int hour;
    int minute;
    int sec;
}TIME;
typedef struct {
    int year;
    int month;
    int day;
}DATE;
typedef struct {
    char *artist_name;
    char *track_name;
    char *album_name;
    TIME lenght;
    DATE realase_date;

    int views;
    int likes;
    int ID;

    char *remixes;
    char *mood;
    char *style;


}DATA;

void read(DATA *music);
void create(int lenght, char *data);
void print(DATA *music);




#endif //PROJEKT_TTB_FUNCTIONS_H