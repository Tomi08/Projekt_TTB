#include "functions.h"

int main() {
    srand(time(0));
    int n, a, b, id, nr;
    DATA *myMusic = readIn("input.csv", &n);
    vector *myPlaylist = vector_init();
    //printf("-----%s-----", myMusic[0].artist_name);
//    writeOut(myMusic, n);
//    playRandom(myMusic, 0, 99);
//    remix(myMusic,n);
//    recommended(myMusic,n);
//    byMood(myMusic,n);
    printf("\t\tWelcome to your personal music assistant!\n\t\t\tHow can I help you? ");
    main:
    do {
        printf("\n");
        printf("(1)Available music list");
        printf("\n(2)What do you recommend today");
        printf("\n(3)One random music");
        printf("\n(4)Music by your mood");
        printf("\n(5)Your own playlist");
        printf("\n(6)Some good remix from OG songs");
        printf("\n(7)Daily top songs");
        printf("\n(8)Weekly top songs");
        printf("\n(9)Sorted by likes");
        printf("\n(10)Sorted by views");
        printf("\n\t\t\t(11) EXIT :(  \n" );
        scanf("%i", &a);

        switch (a) {
            case (1):
                writeOut(myMusic, n);
                break;
            case (2):
                recommended(myMusic, n);
                break;
            case (3):
                playRandom(myMusic, n);
                break;
            case (4):
                byMood(myMusic, n);
                break;
            case (5):
            menu1:
                printf("\nChoose one from the following options: \n");
                printf("(1)Your songs \n");
                printf("(2)Add song \n");
                printf("(3)Remove song \n");
                printf("(4)Back \n");
                scanf("%i", &b);
                if (b == 1) {
                    printf("~MY PLAYLIST~\n");
                    if(myPlaylist->count == 0) {
                        printf(" ---empty---");
                        goto menu1;
                    }
                    writeOut(myPlaylist->items, myPlaylist->count);
                    goto menu1;
                }
                if (b == 2) {
                    printf("Type the ID of the song which you want to add to your list (0-99): ");
                    scanf("%i", &id);
                    if(id < 0 || id > 99) {
                        printf("Error: try again.");
                        goto menu1;
                    }
                    vectorAdd(myPlaylist, &myMusic[id]);
                    goto menu1;
                }
                if (b == 3) {
                    printf("Type the ID of the song which you want to remove from your list (0-%d): ", myPlaylist->count - 1);
                    scanf("%i", &nr);
                    if(nr < 0 || nr > myPlaylist->count - 1) {
                        printf("Error: try again.");
                        goto menu1;
                    }
                    vectorDelete(myPlaylist, nr);
                    goto menu1;
                }
                if (b == 4)goto main;


                break;
            case (6):
                remix(myMusic, n);
                break;
            case (7):
                dts(myMusic, n);
                break;
            case (8):
                wts(myMusic, n);
                break;
            case (9):
                byLikes(myMusic, n);
                break;
            case (10):
                byViews(myMusic, n);
                break;

        }
    } while (a != 11);
    freeVec(myPlaylist);
    freeMyMusic(myMusic, n);
    return 0;
}


//int main() {
//    srand(time(0));
//
//    int n;
//    DATA *myMusic = readIn("input.csv", &n);
//    //printf("-----%s-----", myMusic[0].artist_name);
//    writeOut(myMusic,n);
//
//    vector *myPlaylist = vector_init();
//  printf("~%d\n", vectorAdd(myPlaylist,&myMusic[0]));
//    printf("~%d\n", vectorAdd(myPlaylist,&myMusic[1]));
//    printf("~%d\n", vectorAdd(myPlaylist,&myMusic[2]));
//    printf("~%d\n", vectorAdd(myPlaylist,&myMusic[0]));
//    printf("~%d\n", vectorAdd(myPlaylist,&myMusic[3]));
//    writeOut(myPlaylist->items,myPlaylist->count);
//    printf("YX %d XY\n", vectorDelete(myPlaylist,4));
//    printf("YX %d XY\n", vectorDelete(myPlaylist,0));
//    printf("YX %d XY\n", vectorDelete(myPlaylist,2));
//    printf("YX %d XY\n", vectorDelete(myPlaylist,1));
//    printf("~MY PLAYLIST~\n");
//    writeOut(myPlaylist->items,myPlaylist->count);
//
//    printf("%d \n", myPlaylist->count);
//    printf("%s \n", myPlaylist->items[1].artist_name);
//
//    playRandom(myMusic,n);
//
//    remix(myMusic,n);
//
//    recommended(myMusic,n);
//
//    byMood(myMusic,n);
//    byMood(myMusic,n);
//    byMood(myMusic,n);
//
//
//    freeVec(myPlaylist);
//    freeMyMusic(myMusic,n);
//    return 0;
//}



/*int main()

{
    system("explorer https://youtu.be/cQkcSV81VfY");

    return 0;
}

}*/