//
// Created by Iszlai Tamás on 4/7/2021.
//

#include "functions.h"

DATA *create(int dimension) {
    DATA *myMusic = (DATA *) malloc(dimension * sizeof(DATA));

    return myMusic;
}

DATA *readIn(const char *fname, int *dimension) {
    FILE *fptr = fopen(fname, "r");
    if (fptr == NULL) {
        perror("Error opening file");
    }
    fscanf(fptr, "%i\n", dimension);
    //DATA *myMusic = (DATA*)malloc((*dimension) * sizeof(DATA));
    DATA *myMusic = create(*dimension);
    char *token;
    char buffer[500];
    for (int i = 0; i < *dimension; ++i) {
        fscanf(fptr, "%[^\n]\n", buffer);
        //printf("%s\n", buffer);
        myMusic[i].ID = i;

        token = strtok(buffer, ",");
        myMusic[i].artist_name = (char *) malloc((strlen(token) + 1) * sizeof(char));
        strcpy(myMusic[i].artist_name, token);
        //printf("token~~~%i~~~~~\n", strlen(token));
        //printf("~~~%s~~~~~\n", myMusic[i].artist_name);
        token = strtok(NULL, ",");
        myMusic[i].track_name = (char *) malloc((strlen(token) + 1) * sizeof(char));
        strcpy(myMusic[i].track_name, token);
        token = strtok(NULL, ",");
        myMusic[i].album_name = (char *) malloc((strlen(token) + 1) * sizeof(char));
        strcpy(myMusic[i].album_name, token);
        myMusic[i].mood = (char *) malloc(*dimension * sizeof(char));
        myMusic[i].style = (char *) malloc(*dimension * sizeof(char));

        token = strtok(NULL, ":");
        sscanf(token, "%i", &myMusic[i].length.hour);
        token = strtok(NULL, ":");
        sscanf(token, "%i", &myMusic[i].length.minute);
        token = strtok(NULL, ",");
        sscanf(token, "%i", &myMusic[i].length.sec);

        token = strtok(NULL, "-");
        sscanf(token, "%d", &myMusic[i].realase_date.year);
        token = strtok(NULL, "-");
        sscanf(token, "%d", &myMusic[i].realase_date.month);
        token = strtok(NULL, "");
        sscanf(token, "%d", &myMusic[i].realase_date.day);
        //fscanf(fptr, "\n");
    }

    generate(myMusic, *dimension);

    return myMusic;
}

void writeOut(DATA *myMusic, int dimension) {
    for (int i = 0; i < dimension; ++i) {
        printf("[%i] ", myMusic[i].ID);
        printf("%s ", myMusic[i].artist_name);
        printf("%s ", myMusic[i].track_name);
        printf("%s ", myMusic[i].album_name);

        printf(" [%d", myMusic[i].length.hour);
        printf(":%d", myMusic[i].length.minute);
        printf(":%d] ", myMusic[i].length.sec);

        printf(" [%d", myMusic[i].realase_date.year);
        printf("-%d", myMusic[i].realase_date.month);
        printf("-%d]\n", myMusic[i].realase_date.day);
        printf("\tViews %d", myMusic[i].views);
        printf("\tLikes %d", myMusic[i].likes);
        printf("\tDislikes %d ", myMusic[i].dislikes);
        printf("\tMood %s ", myMusic[i].mood);
        printf("\tStyle %s \n\n", myMusic[i].style);

    }
}

void playRandom(DATA *myMusic, int lower, int upper) {
    srand(time(0));
    int a;
    a = (rand() % (upper - lower + 1)) + lower;
    printf("The random music which you asked: \n");
    printf("[%i] ", myMusic[a].ID);
    printf("%s ", myMusic[a].artist_name);
    printf("%s ", myMusic[a].track_name);
    printf("%s ", myMusic[a].album_name);

    printf(" [%d", myMusic[a].length.hour);
    printf(":%d", myMusic[a].length.minute);
    printf(":%d] ", myMusic[a].length.sec);

    printf(" [%d", myMusic[a].realase_date.year);
    printf("-%d", myMusic[a].realase_date.month);
    printf("-%d]\n\n", myMusic[a].realase_date.day);
}

void generate(DATA *myMusic, int dimension) {
    srand(time(0));
    int mood, style;

    for (int i = 0; i < dimension; ++i) {
        myMusic[i].views = (rand() % (10000000 - 0 + 1)) + 0;
        myMusic[i].likes = (rand() % (myMusic[i].views - 0 + 1) + 0);
        myMusic[i].dislikes = (rand() % ((myMusic[i].views - myMusic[i].likes) - 0 + 1) + 0);
//    if (strstr(myMusic[i].track_name, needle)!=0) {
//        int j = 0;
//        //snprintf(myMusic[i].remixes, sizeof(myMusic[i].remixes), "%s %s %s ", myMusic[i].artist_name,myMusic[i].track_name, myMusic[i].album_name);
//        strcat(myMusic[i].remixes,myMusic[i].artist_name);
//        strcat(myMusic[i].remixes,myMusic[i].track_name);
//        strcat(myMusic[i].remixes,myMusic[i].album_name);
//        ++j;
//    }
        mood = (rand() % (5 - 1 + 1)) + 1;
        if (mood == 1) strcpy(myMusic[i].mood, "Happy");
        else if (mood == 2) strcpy(myMusic[i].mood, "Sad");
        else if (mood == 3) myMusic[i].mood = "Spicy";
        else if (mood == 4) myMusic[i].mood = "Energetic";
        else if (mood == 5) myMusic[i].mood = "Chill";
        style = (rand() % (5 - 1 + 1)) + 1;
        if (style == 1) strcpy(myMusic[i].style, "Rock");
        else if (style == 2) strcpy(myMusic[i].style, "Pop");
        else if (style == 3) myMusic[i].style = "Hip Hop";
        else if (style == 4) myMusic[i].style = "Techno";
        else if (style == 5) myMusic[i].style = "Clasical music";


    }

}

void remix(DATA *myMusic, int dimension) {
    //int j = 0;
    char remix[100];
    char needle[10] = "Remix";
    printf("\nRemixes: \n");
    for (int i = 0; i < dimension; ++i) {
        if (strstr(myMusic[i].track_name, needle) != 0) {
            //snprintf(myMusic[i].remixes, sizeof(myMusic[i].remixes), "%s %s %s ", myMusic[i].artist_name,myMusic[i].track_name, myMusic[i].album_name);
//            strncat(remix, myMusic[i].artist_name,sizeof(remix));
//            strncat(remix, myMusic[i].track_name,sizeof(remix));
//            strncat(remix, myMusic[i].album_name,sizeof(remix));
            printf("[%i] ", myMusic[i].ID);
            printf("%s ", myMusic[i].artist_name);
            printf("%s ", myMusic[i].track_name);
            printf("%s ", myMusic[i].album_name);

            printf(" [%d", myMusic[i].length.hour);
            printf(":%d", myMusic[i].length.minute);
            printf(":%d] ", myMusic[i].length.sec);

            printf(" [%d", myMusic[i].realase_date.year);
            printf("-%d", myMusic[i].realase_date.month);
            printf("-%d]\n\n", myMusic[i].realase_date.day);

        }
    }

}

void recommended(DATA *myMusic, int dimension) {
    qsort(myMusic, dimension, sizeof(DATA), cmp);
    printf("\nToday's best offer\n");
    printf("[%i] ", myMusic[0].ID);
    printf("%s ", myMusic[0].artist_name);
    printf("%s ", myMusic[0].track_name);
    printf("%s ", myMusic[0].album_name);

    printf(" [%d", myMusic[0].length.hour);
    printf(":%d", myMusic[0].length.minute);
    printf(":%d] ", myMusic[0].length.sec);

    printf(" [%d", myMusic[0].realase_date.year);
    printf("-%d", myMusic[0].realase_date.month);
    printf("-%d]\n", myMusic[0].realase_date.day);
    printf("Views %d", myMusic[0].views);
    printf("\tLikes %d\n", myMusic[0].likes);

}

void byMood(DATA *myMusic, int dimension) {
    char mood[10];int x;
//    printf("Type in one from the available moods(Happy,Sad,Energetic,Spicy,Chill)\n");
//    fgets(mood, sizeof mood, stdin);
//    printf("%s",mood);
    printf("Choose one from the available moods (1)Happy, (2)Sad, Energetic(3),Spicy(4),Chill(5)\n");
    scanf("%i",&x);
    if(x==1)strcpy(mood,"Happy");
    else if(x==2)strcpy(mood,"Sad");
    else if(x==3)strcpy(mood,"Energetic");
    else if(x==4)strcpy(mood,"Spicy");
    else if(x==5)strcpy(mood,"Chill");
    printf("By the selected mood here is the list of the music by your mood: \n");
    for (int i = 0; i < dimension; ++i) {
        if (strcmp(myMusic[i].mood, mood)==0) {
            printf("%s ", myMusic[i].artist_name);
            printf("%s ", myMusic[i].track_name);
            printf(" [%d", myMusic[i].length.hour);
            printf(":%d", myMusic[i].length.minute);
            printf(":%d] ", myMusic[i].length.sec);
            printf("Mood %s \n", myMusic[i].mood);
        }

    }

}

int cmp(const void *p1, const void *p2) {
    const DATA *q1 = (const DATA *) p1;
    const DATA *q2 = (const DATA *) p2;
    if (q2->likes < q1->likes) {
        return -1;
    } else if (q1->likes < q2->likes) {
        return 1;
    } else {
        return (q1->views < q2->views) - (q2->views < q1->views);
    }
}

/*
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


void create(int lenght, char *data) {
    data = (char *) malloc(lenght * sizeof(char));
    }

//void print(DATA *music){
//
//}


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
        create(strlen(str), music->artist_name);
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

        strcpy(time,token+5);
        sscanf(time, "%i", &number);
        music->realase_date.month=number;

        strcpy(time,token+8);
        sscanf(time, "%i", &number);
        music->realase_date.day=number;

        printf("%i:%i:%i\n", music->realase_date.year, music->realase_date.month, music->realase_date.day);

        printf("\n");

        nr_of_line++;
    }


}
*/



