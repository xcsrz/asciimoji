#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pbcopy.h"

int prompt()
{
    int n;
    char *end;
    char buf[10];

    do {
        printf("Pick a number:\n");
         if (!fgets(buf, sizeof buf, stdin))
            break;
         buf[strlen(buf) - 1] = 0;
         n = strtol(buf, &end, 10);
    } while (end != buf + strlen(buf));
    return n;    
}

void usage(char *exe)
{
    printf("\nUsage:\n\t%s [ ID ]\n\t  - ID: optionally specify which emoticon you want\n\n", exe);
}


int main(int argc, char *argv[])
{
    char emots[][40] = {
        "¯\\_(ツ)_/¯",
        "༼ ༎ຶ ෴ ༎ຶ༽",
        "「(°ヘ°)",
        "(╯°□°）╯︵ ┻━┻",
        "༼ つ ◕_◕ ༽つ",
        "(✿◠‿◠)",
        "¯(°_o)/¯",
        "(͡° ͜ʖ ͡°)",
        "(ಠ_ಠ)",
        "(╯_╰)",
        "(─‿‿─)",
        "\\,,/(^_^)\\,,/",
        "(¬､¬)",
        "(ﾉﾟ0ﾟ)ﾉ",
        "(╯°□°)╯︵ ʞooqǝɔɐɟ",
        "(⌐■_■)",
        "╭∩╮（︶︿︶）╭∩╮",
        "c[_]",
        "(ง •̀_•́)ง",
        "(⌐■_■)︻╦╤─ ",
        "(ಡ_ಡ)☞",
        "◕_◕",
        "(눈_눈)",
        "(◔_◔)",
        "\\_(-_-)_/",
        "⊹╰(⌣ʟ⌣)╯⊹"
    };

    int emotCount = sizeof(emots) / sizeof(emots[0]);

    if(argc > 2) {
        usage(argv[0]);
        return 1;
    }

    if(argc == 2) {
        int d = strtol(argv[1], NULL, 10);
        if(d == 0 || d > emotCount) {
            usage(argv[0]);
            return 1;
        }
        copy(emots[d-1]);
        return 0;
    }

    printf("Ascii Emoji\n");
    int i = 0;
    for (i = 0; i < emotCount; i++) {
         printf("\t%d) %s\n", i+1, emots[i]);
    }
 
    int n = 0;

    while (n == 0 || n > emotCount) {
        n = prompt();
    }
    copy(emots[n-1]);
    return 0;
}

