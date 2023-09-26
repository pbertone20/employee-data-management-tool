#include "../include/headerA3.h" // header

void fireOne(a3Emp **headLL, int whichOne) // definition
{
    a3Emp *temp = *headLL, *previous = NULL; // intialize temp to null and previous var to null
    int i;

    if (whichOne == 1) // checks if looking for first node
    {
        *headLL = (*headLL)->nextEmployee; // moves the head over one

        for (i = 0; i < temp->numDependents; i++) // frees dependents
            free(temp->dependents[i]);
        free(temp->dependents); // frees whole dependent var
        free(temp);             // frees the head
        return;                 // exits
    }

    while (--whichOne) // runs to get to the correct employee in the LL, and saves previous employee
    {
        previous = temp;           // saves previous node
        temp = temp->nextEmployee; // moves this node over one
    }
    previous->nextEmployee = temp->nextEmployee; // erasing the index of whichOne in the LL by making the previousNode->next = currentNode->next
    for (i = 0; i < temp->numDependents; i++)    // frees dependents of erased node
        free(temp->dependents[i]);
    free(temp->dependents); // frees whole var
    free(temp);             // frees whole node

    return; // returns
}