#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

int main() {
    DATA *music;
    music = (DATA*)malloc(100*sizeof(DATA));
    read(music);
    print(music);

    return 0;
}
