#include "../include/headerA3.h" // header

int countEmployees(a3Emp *headLL) // definition
{
    a3Emp *temp = headLL; // intialize a temp a3Emp to the headLL
    int count = 0;

    while (temp != NULL) // loop through the whole LL and count each employee
    {
        count++;                   // increase
        temp = temp->nextEmployee; // go to next emp
    }

    return count; // return
}