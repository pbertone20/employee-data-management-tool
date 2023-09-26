#include "../include/headerA3.h" // header

int lookOnId(struct employee *headLL, int whichEmpId) // lookOnId
{
    a3Emp *temp = headLL; // intialization
    int pos = 1;

    while (temp != NULL) // runs for whole LL
    {
        if (whichEmpId == temp->empId) // if desired empID is found
        {
            return pos; // return position in LL
        }

        pos++;                     // else increase position
        temp = temp->nextEmployee; // move on to next node
    }

    return -1; // return error code if not found
}