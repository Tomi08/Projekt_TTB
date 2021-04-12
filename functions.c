
#include "functions.h"

DATA *create(int dimension) {
    DATA *myMusic = (DATA *) malloc(dimension * sizeof(DATA));

    return myMusic;
}

DATA *readIn(const char *fname, int *dimension) {
    FILE *fptr = fopen(fname, "r");
    if (fptr == NULL) {
        perror("Error ");
        return 0;
    }

    fscanf(fptr, "%i\n", dimension);
    DATA *myMusic = create(*dimension);

    char *token;
    char buffer[500];

    for (int i = 0; i < *dimension; ++i) {
        fscanf(fptr, "%[^\n]\n", buffer);
        myMusic[i].ID = i;

        token = strtok(buffer, ",");
        myMusic[i].artist_name = (char *) malloc((strlen(token) + 1) * sizeof(char));
        strcpy(myMusic[i].artist_name, token);
        token = strtok(NULL, ",");
        myMusic[i].track_name = (char *) malloc((strlen(token) + 1) * sizeof(char));
        strcpy(myMusic[i].track_name, token);
        token = strtok(NULL, ",");
        myMusic[i].album_name = (char *) malloc((strlen(token) + 1) * sizeof(char));
        strcpy(myMusic[i].album_name, token);
        myMusic[i].mood = (char *) malloc(WORD * sizeof(char));
        myMusic[i].style = (char *) malloc(WORD * sizeof(char));

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

    fclose(fptr);
    return myMusic;
}

void writeOut(DATA *myMusic, int dimension) {
    for (int i = 0; i < dimension; ++i) {
        printf("[%d]", i);
        printf("%s ", myMusic[i].artist_name);
        printf("%s ", myMusic[i].track_name);
        printf("%s ", myMusic[i].album_name);

        printf(" [%d", myMusic[i].length.hour);
        printf(":%d", myMusic[i].length.minute);
        printf(":%d] ", myMusic[i].length.sec);

        printf(" [%d", myMusic[i].realase_date.year);
        printf("-%d", myMusic[i].realase_date.month);
        printf("-%d]\n", myMusic[i].realase_date.day);
    }
}

int freeVec(vector *v) {
    int status = UNDEFINE;
    if (v) {
        //freeMyMusic(v->items, v->size);
        free(v);
        status = SUCCESS;
    }
    return status;
}

int freeMyMusic(DATA *myMusic, int dimension) {
    int status = UNDEFINE;
    if (myMusic) {
        for (int i = 0; i < dimension; ++i) {
            free(myMusic[i].artist_name);
            free(myMusic[i].track_name);
            free(myMusic[i].album_name);
        }
        free(myMusic);
        status = SUCCESS;
    }
    return status;
}

int vectorAdd(vector *v, DATA *item) {
    int status = UNDEFINE;
    if (v->size == v->count) {
        vectorResize(v, v->size * 2);
        v->items[v->count++] = *item;
        status = SUCCESS;
        printf("XXX%d %d \n", v->count, v->size);
    } else {
        v->items[v->count++] = *item;
        status = SUCCESS;
        printf("%d \n", v->count);
    }

    return status;
}

int vectorResize(vector *v, int size) {
    int status = UNDEFINE;

    if (v) {
        v->items = realloc(v->items, size * sizeof(DATA));
        v->size = size;
        status = SUCCESS;
    }

    return status;
}

int vectorDelete(vector *v, int index) {
    int status = UNDEFINE;
    int i = 0;
    if (v) {
        if ((index < 0) || (index >= v->count))
            return status;
        for (i = index; (i < v->count - 1); ++i) {
            v->items[i] = v->items[i + 1];
            //v->items[i + 1] = empty;
        }
        v->count--;
        printf("YYY%d %d \n", v->count, v->size);
        if ((v->count > 0) && ((v->count) == (v->size / 2))) {
            vectorResize(v, v->size / 2);
        }
        status = SUCCESS;
    }
    return status;
}

vector *vector_init() {
    vector *v = malloc(sizeof(vector));
    v->size = 1;
    v->count = 0;
    v->items = create(v->size);
    return v;
}

int returnRandom(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void playRandom(DATA *myMusic, int dimension) {
    int a;
    a = returnRandom(0, dimension - 1);

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
    int mood, style;

    for (int i = 0; i < dimension; ++i) {
        myMusic[i].views = returnRandom(0, MAX);
        myMusic[i].likes = returnRandom(0, myMusic->views);
        myMusic[i].dislikes = returnRandom(0, myMusic->views);

        mood = returnRandom(1, 5);
        if (mood == 1) strcpy(myMusic[i].mood, "Happy");
        else if (mood == 2) strcpy(myMusic[i].mood, "Sad");
        else if (mood == 3) myMusic[i].mood = "Spicy";
        else if (mood == 4) myMusic[i].mood = "Energetic";
        else if (mood == 5) myMusic[i].mood = "Chill";
        style = returnRandom(1, 5);
        if (style == 1) strcpy(myMusic[i].style, "Rock");
        else if (style == 2) strcpy(myMusic[i].style, "Pop");
        else if (style == 3) myMusic[i].style = "Hip Hop";
        else if (style == 4) myMusic[i].style = "Techno";
        else if (style == 5) myMusic[i].style = "Clasical music";
    }
}

void remix(DATA *myMusic, int dimension) {
    //int j = 0;
    //char remix[100];
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
    char mood[10];
    int x;
//    printf("Type in one from the available moods(Happy,Sad,Energetic,Spicy,Chill)\n");
//    fgets(mood, sizeof mood, stdin);
//    printf("%s",mood);
    printf("Choose one from the available moods (1)Happy, (2)Sad, Energetic(3),Spicy(4),Chill(5)\n");
    scanf("%i", &x);
    if (x == 1)strcpy(mood, "Happy");
    else if (x == 2)strcpy(mood, "Sad");
    else if (x == 3)strcpy(mood, "Energetic");
    else if (x == 4)strcpy(mood, "Spicy");
    else if (x == 5)strcpy(mood, "Chill");
    printf("By the selected mood here is the list of the music by your mood: \n");
    for (int i = 0; i < dimension; ++i) {
        if (strcmp(myMusic[i].mood, mood) == 0) {
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

int comparator(const void *p1, const void *p2) {
    const DATA *q1 = (const DATA *) p1;
    const DATA *q2 = (const DATA *) p2;
    if (q2->likes > q1->likes) {
        return -1;
    } else return 1;
}

void byLikes(DATA *myMusic, int dimension) {
    qsort((void *) myMusic, dimension, sizeof(DATA), comparator);
    printf("\nSorted by likes:\n");
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
        printf("Views %d", myMusic[i].views);
        printf("\tLikes %d\n", myMusic[i].likes);
    }
}

int comparator2(const void *p1, const void *p2) {
    const DATA *q1 = (const DATA *) p1;
    const DATA *q2 = (const DATA *) p2;
    if (q2->views > q1->views) {
        return -1;
    } else return 1;
}

void byViews(DATA *myMusic, int dimension) {
    qsort((void *) myMusic, dimension, sizeof(DATA), comparator2);
    printf("\nSorted by Views:\n");
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
        printf("Views %d", myMusic[i].views);
        printf("\tLikes %d\n", myMusic[i].likes);
    }
}


