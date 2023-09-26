#include "../include/headerA3.h" // header

void printAll(struct employee *headLL) // definition
{
    a3Emp *temp = headLL;
    int count = 0;

    while (temp != NULL) // goes through whole LL
    {
        printf("\nEmployee #%d\n", count + 1); // prints information from node
        printf("\t%s %s\n\tID: %d\n", temp->fname, temp->lname, temp->empId);
        printf("\tDependents [%d]: ", temp->numDependents);
        for (int i = 0; i < temp->numDependents; i++)
            i == temp->numDependents - 1 ? printf("%s \n", temp->dependents[i]) : printf("%s, ", temp->dependents[i]);
        temp = temp->nextEmployee; // moves on to next node in LL
        count++;                   // increases a counter for num of emp
    }
}