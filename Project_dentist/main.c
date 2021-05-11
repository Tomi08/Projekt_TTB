#include "BST.h"

int main() {
    struct node *root;
    node *find;
    person *input;
    root = NULL;

    int a, b; //valtozok a switch casekre
    int kod;
    int valasz;
    // char *c_time = (char *) malloc(sizeof(char));
    time_t rawtime;
    struct tm *timeinfo;
    menu:
    printf("\t\tFogaszati rendelo\n");


    do {
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        printf("\t     %s ", asctime(timeinfo));
        printf("\nProgramalasi menu:");
        printf("\n");
        printf("\n(1)Uj programalas ");
        printf("\n(2)Programalasod megtekintese ");
        printf("\n(3)Frissites");
        printf("\n(4)Programalasok listazasa");
        printf("\n(5)Programalas lemondasa");
        printf("\n(6)Nyitvatartas");
        printf("\n(7)Kilepes :(\n");
        a = 7;
        scanf("%i", &a);
        jump:
        fflush(stdin);


        switch (a) {
            case (1):

                printf("Kerem adja meg nevet es az idopontot:\n");

                if (root == NULL) {
                    input = readIn();
                    root = new_node(input);
                    if (root != NULL) {
                        printf("\nA programalasa sikeres volt.\nAzonosito kodja: %d\n\n", input->code);
                    }
                } else {

                    input = readIn();
                    int ok=1;
                    teszteles2(root,input,&ok);
                    if (ok==1) {
                        insert(root, input);
                        printf("\nA programalasa sikeres volt.\nAzonosito kodja: %d\n\n", input->code);
                    } else {
                        printf("A megadott idopont nem megfelelo ,szeretne ujra programalni?\n(1)Igen (0)Nem?");
                        jump2:
                        scanf("%i", &valasz);
                        if (valasz == 1) {
                            inorder(root);
                            goto jump;

                        }
                        else if(valasz!=0) {
                            printf("Helytelen opciot gepelt be ,kerem probalja ujra");
                            goto jump2;
                        }
                    }
                }

                break;
            case (2):
                printf("Adja meg az azonosito kodjat:");
                scanf("%d", &kod);
                fflush(stdin);
                find = search(root, kod);
                if (find) {
                    printf("\n");
                    printf("Az on programalasa: %s %s %d\n\n", find->data.name, find->data.time, find->data.code);
                } else {
                    printf("\n\tNincs programalasa.\n\n");
                }

                break;
            case (3):
                time(&rawtime);
                timeinfo = localtime(&rawtime);
                char *c_time = (char *) malloc(sizeof(char));
                c_time = asctime(timeinfo);
                char *ptr = (char *) malloc(sizeof(char));
                ptr = strtok(c_time, " ");
                for (int i = 0; i < 3; ++i) {
                    ptr = strtok(NULL, " ");
                }
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


//                int x = removeWhat(root,ptr);
//
//                while (x != -1) {
//                    root = delete(root,x);
//                    printf("\n~%d~", x);
//                    x = removeWhat(root,ptr);
//                }

                //root = delete(root,removeWhat(root,ptr));
                //removeFinished(root,ptr);
                //torli azokat a programalasokat amik mar nem relevansak


                //root = delete(root,removeWhat(root,ptr));
                //removeFinished(root,ptr);
                //torli azokat a programalasokat amik mar nem relevansak


                break;

            case (4):
                printf("\nJelenlegi programalasok:\n");
                //frissites
                inorder(root);
                printf("\n");
                //delay(1);
                break;
            case (5):
                printf("Adja meg az azonosito kodjat:\n");
                scanf("%d", &kod);
//                fflush(stdin);
                if (search(root, kod)) {
                    root = delete(root, kod);
                    printf("Sikeresen lemondta a %d azonositoju programalasat\n", kod);
                } else
                    printf("Hiba lepett fel a kerese kozben,helytelen vagy nem letezo kodot adott meg ,kerjuk probalja ujra\n");

                break;
            case (6):
                printf("Hetfo->pentek - 08:00->20:00\n");
                printf("Szombat       - 08:00->18:00\n");
                printf("Vasarnap      - Zarva\n");

                break;
            case (7):
                printf("Viszlat :)");

                return 0;


            default:
                printf("Helytelen opciot valasztott kerjuk probalja ujra.\n");
                printf("Kiszeretnel lepni igen(1)/nem(0)?");
                scanf("%i", &b);
                if (b == 1) { return 0; }
                else goto menu;

        }
    } while (a != 8);


//    node *e = (node *) malloc(sizeof(node));
//    root = new_node(readIn());
//    insert(root, readIn());
//    insert(root, readIn());
//
//    //printf("%s %s %d", root->data.name, root->data.time, root->data.code);
//    inorder(root);
//    e = find_minimum(root);
//    printf("\n%s %s %d\n", e->data.name, e->data.time, e->data.code);
//
//
//    e = search(root, 671);
//    if (e) {
//        printf("\n%s %s %d\n\n", e->data.name, e->data.time, e->data.code);
//    } else
//        printf("ures");
//
//    root = delete(root, 671);
//    printf("\n");
//    inorder(root);

    return 0;
}