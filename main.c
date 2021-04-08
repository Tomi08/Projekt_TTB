#include <stdio.h>
#include "functions.h"


int main() {
    DATA *music;
    beolvas(&music);
    puts(music->track_name);
    return 0;
}
