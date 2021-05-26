#include <stdio.h>
#include <time.h>
#include "Array.h"
#include "List.h"
#include "BinarySearchTree.h"
#include "Heap.h"
#include "HashTable.h"


int main() {
    int a, b, c, d, n;
    clock_t start, end;
    double elapsed;
    char szo[20], k1[20], k2[20], input[20];
    n = 5;
    root *fa;
    LISTA *list = NULL;
    //fa=NULL;
    fa = createbst("");
    list = createl("");
    heap *heap = createHeap(25);
    Hash **T = createht(n);

    do {
        printf("\nMenu:");
        printf("\n(1)Array");
        printf("\n(2)List");
        printf("\n(3)BST");
        printf("\n(4)Heap");
        printf("\n(5)HashTable");
        printf("\n(6)Exit\n");
        scanf("%i", &a);
        printf("%i", a);
        switch (a) {
            case (1):
                printf("\n(1)Insert");
                printf("\n(2)Search");
                printf("\n(3Remove");
                printf("\n(4)Acces\n");
                scanf("%i", &b);
                if (b == 1) {}
                if (b == 2) {}
                if (b == 3) {}
                if (b == 4) {}
                break;
            case (2):
                printf("\n(1)Insert");
                printf("\n(2)Search");
                printf("\n(3Remove");
                printf("\n(4)Acces\n");
                scanf("%i", &b);
                if (b == 1) {
                    fflush(stdin);
                    gets(szo);
                    start = clock();
                    push(list, szo);
                    end = clock();
                    elapsed = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    printf("\nInsert time %.2lf ms", elapsed);
                }
                if (b == 2) {}
                if (b == 3) {
                    scanf("%i", &c);
                    start = clock();
                    remove_by_index(&list, c);
                    end = clock();
                    elapsed = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    printf("\nDelete time %.2lf ms", elapsed);
                }
                if (b == 4) {
                    start = clock();
                    print_list(list);
                    end = clock();
                    elapsed = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    printf("\nAcces time %.2lf ms", elapsed);
                }
                break;
            case (3):
                printf("\n(1)Insert");
                printf("\n(2)Search");
                printf("\n(3Remove");
                printf("\n(4)Acces\n");
                scanf("%i", &b);
                if (b == 1) {
                    fflush(stdin);
                    gets(szo);
                    printf("%s", szo);
                    start = clock();
                    insertbst(fa, szo);
                    end = clock();
                    elapsed = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    printf("\nInsert time %.2lf ms", elapsed);
                }
                if (b == 2) {
                    fflush(stdin);
                    gets(szo);
                    start = clock();
                    printf("\n");
                    if (Find(fa, szo)) printf("Megvan");
                    else printf("Nincs meg");
                    printf("\n");
                    end = clock();
                    elapsed = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    printf("\nSearch time %.2lf ms", elapsed);
                }
                if (b == 3) {
                    fflush(stdin);
                    gets(szo);
                    start = clock();
                    Delete(&fa, szo);
                    end = clock();
                    elapsed = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    printf("\nDelete time %.2lf ms", elapsed);
                }
                if (b == 4) {
                    start = clock();
                    inorder(fa);
                    end = clock();
                    elapsed = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    printf("\nAcces time %.2lf ms", elapsed);
                }
                break;
            case (4):
                printf("\n(1)Insert");
                printf("\n(2)Search");
                printf("\n(3Remove");
                printf("\n(4)Acces\n");
                scanf("%i", &b);
                if (b == 1) {
                    fflush(stdin);
                    gets(szo);
                    start = clock();
                    inserth(heap, szo);
                    end = clock();
                    elapsed = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    printf("\nInsert time %.2lf ms", elapsed);
                }
                if (b == 2) {}
                if (b == 3) {}
                if (b == 4) {}
                break;
            case (5):
                printf("\n(1)Insert");
                printf("\n(2)Search");
                printf("\n(3Remove");
                printf("\n(4)Acces\n");
                scanf("%i", &b);
                if (b == 1) {
                    fflush(stdin);
                    gets(k2);
                    start = clock();
                    beszur(k2, k2, T, n);
                    end = clock();
                    elapsed = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    printf("\nInsert time %.2lf ms", elapsed);
                }
                if (b == 2) {
                    scanf("%s", input);
                    start = clock();
                    if (keres(T, n, input) != -1) {
                        printf("%s\n", T[keres(T, n, input)]->szo);
                    } else printf("A keresett szo nincs benne a szotarban");
                    end = clock();
                    elapsed = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    printf("\nSearch time %.2lf ms", elapsed);
                }
                if (b == 3) {
                    start = clock();
                    torol(T, &n);
                    end = clock();
                    elapsed = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    printf("\nDelete time %.2lf ms", elapsed);
                }
                if (b == 4) {
                    start = clock();
                    kiir(T, n);
                    end = clock();
                    elapsed = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
                    printf("\nAcces time %.2lf ms", elapsed);
                }
                break;

        }
    } while (a != 6);
    return 0;
}
