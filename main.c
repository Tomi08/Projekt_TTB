#include "functions.h"

int main() {

    int n;
    DATA *myMusic = readIn("input.csv", &n);
    //printf("-----%s-----", myMusic[0].artist_name);
    writeOut(myMusic, n);
    //playRandom(myMusic, 0, 99);
    remix(myMusic,n);


    return 0;
}
