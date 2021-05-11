//
// Created by David on 05/06/2021.
//

#include "BST.h"
#include "person.h"

typedef struct rawtime rawtime;

person *readIn() {
//    char* temp_name;
//    char* temp_time;
    person *ptr = (person *) malloc(sizeof(person));
    //char *text = (char )malloc(sizeof (char));
    ptr->name = (char *) malloc(30 * sizeof(char));
    ptr->time = (char *) malloc(30 * sizeof(char));
    printf("Nev:");
    gets(ptr->name);
    printf("Ido [hh:mm]:");
    gets(ptr->time);
//    scanf("%[^\n]%*c", ptr->name);
//    scanf("%[^\n]%*c", ptr->time);
    while (!teszteles(ptr->time)) {
        printf("Helytelen idot gepelt be kerem probalja ujra\n");
        scanf("%[^\n]%*c", ptr->time);
    }

    ptr->code = encode(ptr->time);
    return ptr;
}

bool teszteles(char *c) {
    if ((c[2] == ':' || c[1] == ':') && c[1] != c[2]) {
        char *buffer = (char *) malloc(30 * sizeof(char *));
        char *token;
        strcpy(buffer, c);
        int hour;
        int minute;
        token = strtok(buffer, ":");
        sscanf(token, "%i", &hour);
        token = strtok(NULL, ":");
        sscanf(token, "%i", &minute);
        //printf("%i %i\n", hour, minute);
        if (minute >= 0 && minute < 60 && teszteles3(hour))return true;
        else return false;

    } else return false;


}

void teszteles2(struct node *root,person *input, int *ok) {
    int k = 25;
    if (root != NULL) {


        if (abs(root->data.code - input->code) < k){

            *ok =0;

        } else {
           teszteles2(root->left_child, input, ok);
           teszteles2(root->right_child, input, ok);
        }
    }
}




bool teszteles3(int hour) {
    struct tm *timeinfo;
    time_t rawtime;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char dayinfo[10];
    //a dayinfo megkapja a mai nap megnevezését pl: Mon(hetfő)
    strcpy(dayinfo, strtok(asctime(timeinfo), " "));
    //printf("%s\n", dayinfo);
    char days[5][10] = {"Mon", "Tue", "Wed", "Thu", "Fri"};
    for (int i = 0; i < 5; ++i) {
        if (!strcmp(dayinfo, days[i]) && (hour >= 8 && hour < 20)) {
            return true;
        }

    }
    if (!strcmp(dayinfo, "Sat") && (hour >= 8 && hour < 18)) {
        return true;
    }

    if (!strcmp(dayinfo, "Sun")) {
        printf("Vasarnap zarva vagyunk\n");
    }

    return false;

}

void removeWhat(struct node *root, char *ptr, int *x) {
    if (root != NULL) {


        if (strcmp(root->data.time, ptr) < 0) {

            *x = root->data.code;

        } else {
            removeWhat(root->left_child, ptr, x);
            removeWhat(root->right_child, ptr, x);
        }
    }
}

void removeFinished(struct node *root, char *ptr) {

    int x = 0;
    removeWhat(root, ptr, &x);

    //printf(" [kint2:%d] ", x);
    while (x) {
        root = delete(root, x);
        x = 0;
        printf("\n");
        inorder(root);
        printf("\n");
        //printf(" [kint:%d] ", x);
        removeWhat(root, ptr, &x);
    }
}

int encode(char *c) {
    char *ptr ;
    char *cc = (char *) malloc(30 * sizeof(char *));
    strcpy(cc, c);
    int code = 0;
    int minutes = 0;

    ptr = strtok(cc, ":");
    sscanf(ptr, "%i", &code);
    code *= 60;
    ptr = strtok(NULL, ":");
    sscanf(ptr, "%i", &minutes);
    code += minutes;

    return code;
}

char *decode(int x) {
    int h, m;
    h = x / 60;
    m = x % 60;

    char *hour = (char *) malloc(sizeof(char *));
    char *minutes = (char *) malloc(sizeof(char *));

    snprintf(hour, 5, "%d", h);
    snprintf(minutes, 5, "%d", m);

    strcat(hour, ":");
    strcat(hour, minutes);
}