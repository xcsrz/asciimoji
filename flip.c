#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include "pbcopy.h"

struct cheq {
    char from[10];
    char to[10];
};

struct cheq cheqs[200];
int cheqc = -1;

void popcheqs(char *f, char *t)
{
    cheqc++;
    strcpy(cheqs[cheqc].from, f);
    strcpy(cheqs[cheqc].to, t);
}

void init() {
    popcheqs("a", "ɐ");
    popcheqs("b", "q");
    popcheqs("c", "ɔ");
    popcheqs("d", "p");
    popcheqs("e", "ǝ");
    popcheqs("f", "ɟ");
    popcheqs("g", "ƃ");
    popcheqs("h", "ɥ");
    popcheqs("i", "ı");
    popcheqs("j", "ɾ");
    popcheqs("k", "ʞ");
    popcheqs("l", "ʃ");
    popcheqs("m", "ɯ");
    popcheqs("n", "u");
    popcheqs("r", "ɹ");
    popcheqs("t", "ʇ");
    popcheqs("v", "ʌ");
    popcheqs("w", "ʍ");
    popcheqs("y", "ʎ");
    popcheqs(".", "˙");
    popcheqs("?", "¿");
    popcheqs("!", "¡");
    popcheqs("'", ",");
    popcheqs("_", "‾");
    popcheqs("‿", "⁀");
    popcheqs("⁅", "⁆");
    popcheqs("∴", "∵");
}

char* flipchar(char *from)
{
    for (int i = 0; i <= cheqc; ++i)
    {
        if(strcmp(from, cheqs[i].from) == 0)
            return cheqs[i].to;
        if(strcmp(from, cheqs[i].to) == 0)
            return cheqs[i].from;
    }   
    return from;
}


int main(int argc, char *argv[])
{
    init();

    char str[] = "(╯°□°）╯︵ ";
    int i = strlen(str);

    int len = argc + i;
    for (int w = argc-1; w > 0; --w)
    {
        len += strlen(argv[w]);
    }
    // printf("Total length: %d\n", len);
    char result[len];
    strcpy(result, str);

    for (int w = argc-1; w > 0; --w)
    {
        for (int l = strlen(argv[w])-1; l >= 0; --l)
        {
            char let[2] = { argv[w][l], '\0'};
            char *flipped = flipchar(let);
            strcpy(result+i, flipped);
            i += strlen(flipped);
        }
        strcpy(result+i, " ");
        i++;
    }
    copy(result);
}

