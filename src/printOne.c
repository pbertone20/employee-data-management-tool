#include "../include/headerA3.h" // header

void printOne(struct employee *headLL, int whichOne) // definition
{
    a3Emp *temp = headLL; // intialization
    int count = 1;

    if (whichOne >= 1) // if whichOne is not 0 or negative
    {
        while (temp != NULL) // runs through whole LL
        {
            if (count == whichOne) // if the counter is same as desired node index
            {
                printf("\nEmployee #%d\n", count); // prints off info from node
                printf("\t%s %s\n\tID: %d\n", temp->fname, temp->lname, temp->empId);
                printf("\tDependents [%d]: ", temp->numDependents);
                for (int i = 0; i < temp->numDependents; i++)
                    i == temp->numDependents - 1 ? printf("%s \n", temp->dependents[i]) : printf("%s, ", temp->dependents[i]);

                return; // exits function
            }

            count++;                   // else increases counter
            temp = temp->nextEmployee; // moves node over to next employee
        }

        if (whichOne >= count - 1) // if the desired node is out of range print erorr message
            printf("Position does not exist!\n\n");
    }
    else
        printf("Position does not exist!\n\n"); // error message for negative or 0 val

    return; // exits
}