#include <stdio.h> 

void copy(char *emot)
{
    FILE *pipe;
    if ( ( pipe = popen("pbcopy", "w" ) ) == NULL)
    {
        printf("ERROR: Unable to copy to clipboard\n\n\t%s\n\n", emot);
        return;
    }
    fputs(emot, pipe);
    pclose(pipe);
    printf("Copied %s to your clipboard.\n", emot);
}
