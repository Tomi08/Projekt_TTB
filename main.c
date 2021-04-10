#include "functions.h"

int main() {

    int n, a;
    DATA *myMusic = readIn("input.csv", &n);
    //printf("-----%s-----", myMusic[0].artist_name);
//    writeOut(myMusic, n);
//    playRandom(myMusic, 0, 99);
//    remix(myMusic,n);
//    recommended(myMusic,n);
//    byMood(myMusic,n);
    printf("\t\tWelcome to your personal music assistant!\n\t\t\tHow can I help you? ");
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
        printf("\n\t\t\t(11) EXIT :(");
        scanf("%i", &a);

        switch (a) {
            case (1): writeOut(myMusic, n);
                break;
            case (2): recommended(myMusic,n);
                break;
            case (3):playRandom(myMusic, 0, 99);
                break;
            case (4): byMood(myMusic,n);
                break;
            case (5):
                break;
            case (6):remix(myMusic,n);
                break;
            case (7):
                break;
            case (8):
                break;
            case (9):
                break;
            case (10):
                break;

        }
    } while (a != 11);
    return 0;
}
