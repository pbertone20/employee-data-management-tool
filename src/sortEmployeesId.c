#include "../include/headerA3.h" // header

void sortEmployeesId(struct employee *headLL) // definition
{
    a3Emp *curNode, *unSorted; // nodes for loops
    int tempId;                // var initialization for names, and dependents
    char tempFname[MAX_LENGTH];
    char tempLname[MAX_LENGTH];
    int tempNumDependents;
    char **tempDependents;

    for (curNode = headLL; curNode != NULL; curNode = curNode->nextEmployee) // for loop runs for loop LL and moves to next node after every iteration
    {
        for (unSorted = curNode->nextEmployee; unSorted != NULL; unSorted = unSorted->nextEmployee) // for loop runs starting at the next employee of the previous loop employee, and runs for whole LL
        {
            if (curNode->empId > unSorted->empId) // swaps nodes if the previous node from outter loop is greater than current inner loop node
            {
                tempId = curNode->empId; // saves previous node's data
                strcpy(tempFname, curNode->fname);
                strcpy(tempLname, curNode->lname);
                tempNumDependents = curNode->numDependents;
                tempDependents = curNode->dependents;

                curNode->empId = unSorted->empId; // updates previous node with the new node's data
                strcpy(curNode->fname, unSorted->fname);
                strcpy(curNode->lname, unSorted->lname);
                curNode->numDependents = unSorted->numDependents;
                curNode->dependents = unSorted->dependents;

                unSorted->empId = tempId; // updates other node with saved temp data
                strcpy(unSorted->fname, tempFname);
                strcpy(unSorted->lname, tempLname);
                unSorted->numDependents = tempNumDependents;
                unSorted->dependents = tempDependents;
            }
        }
    }
}