#include "../include/headerA3.h" // header

void fireAll(a3Emp **headLL) // definition
{
    a3Emp *temp;
    int i;

    while (*headLL != NULL) // runs for whole list
    {
        temp = (*headLL)->nextEmployee;                // intialize a temp to the next so we can move on after freeing head
        for (i = 0; i < (*headLL)->numDependents; i++) // loop to free dependents
            free((*headLL)->dependents[i]);
        free((*headLL)->dependents); // free whole var now
        free(*headLL);               // free the whole head after
        *headLL = temp;              // move on to next emp
    }

    return; // returns
}