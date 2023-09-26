#include "../include/headerA3.h" // header

int lookOnFullName(struct employee *headLL, char whichName[100]) // definition
{
    a3Emp *temp = headLL; // var initialization
    char *fullname = calloc(((strlen(temp->fname) + strlen(temp->lname))) + 2, sizeof(char));
    int pos = 1;

    while (temp != NULL) // runs through whole linked LL
    {
        fullname = realloc(fullname, sizeof(char) * (strlen(temp->fname) + strlen(temp->lname)) + 2); // reallocs for new names
        strcpy(fullname, temp->fname);                                                                // copies fname
        strcat(fullname, " ");                                                                        // concats a space
        strcat(fullname, temp->lname);                                                                // concats lname

        if (strcmp(fullname, whichName) == 0) // if the comparison is true free the var and return
        {
            free(fullname);
            return pos;
        }

        pos++; // else increase counter for position and move on to next node
        temp = temp->nextEmployee;
    }

    free(fullname); // if unsuccessful free var and return error code

    return -1;
}
