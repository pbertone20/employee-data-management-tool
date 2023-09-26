#include "../include/headerA3.h" // header

void recruitEmployee(a3Emp **headLL) // function definition
{
    srand(time(NULL)); // for rand()

    a3Emp *newEmp = calloc(1, sizeof(a3Emp)), *temp; // var intialization
    char nextDep = 'y';
    int i, safeVal = -1, randNeeded = 0, noSwap = 1;

    printf("\nEnter the first name of the employee: "); // scanf for fname
    scanf("%s", newEmp->fname);

    printf("Enter the last name of the employee: "); // scanf for lname
    scanf("%s", newEmp->lname);

    for (i = 0; i < strlen(newEmp->fname); i++) // rand emp generator, ascii of chars of fname plus length of lname
    {
        newEmp->empId = newEmp->empId + (int)(newEmp->fname[i]);
    }
    newEmp->empId = newEmp->empId + strlen(newEmp->lname);

    while ((nextDep == 'y' || nextDep == 'Y') && isalpha(nextDep)) // while user input is correct
    {
        (newEmp->numDependents)++;                                                                // increases number of dependents for each iteration
        newEmp->dependents = realloc(newEmp->dependents, sizeof(char *) * newEmp->numDependents); // realloc for new dependent
        newEmp->dependents[(newEmp->numDependents) - 1] = malloc(sizeof(char) * MAX_LENGTH + 1);  // malloc of each char
        newEmp->dependents[(newEmp->numDependents) - 1][0] = '\0';                                // make null

        printf("Enter name of dependent #%d: ", newEmp->numDependents); // scanf for name
        scanf("%s", newEmp->dependents[(newEmp->numDependents) - 1]);
        newEmp->dependents[newEmp->numDependents - 1][strlen(newEmp->dependents[newEmp->numDependents - 1])] = '\0'; // add null char to str

        getchar();                                   // getchar for previous scanf
        printf("Do you have any more dependents? "); // scanf for if the loop should continue
        scanf("%c", &nextDep);
    }

    newEmp->nextEmployee = NULL; // make next emp = NULL bc its new end of list

    if ((*headLL) == NULL) // if head is empty it is now head
    {
        (*headLL) = newEmp;
    }
    else // if not empty
    {

        a3Emp *last = *headLL; // temp a3Emp for looping

        while (last->nextEmployee != NULL) // loops to last node
        {
            last = last->nextEmployee;
        }
        last->nextEmployee = newEmp; // makes next emp of last node new node

        while (safeVal < 0) // while safe val flag is false
        {
            temp = (*headLL); // make temp of head

            while (temp->nextEmployee != NULL) // runs until last node
            {
                if (temp->empId != newEmp->empId) // if empIDs are not the same
                {
                    noSwap = 0;                // update var for exit purposes
                    temp = temp->nextEmployee; // move on to next emp
                }
                else // if same empID found
                {
                    newEmp->empId = rand() % 1000 + 1; // generate random id between 1-1000
                    last->nextEmployee = newEmp;       // update node with new rand ID
                    randNeeded++;                      // increase rand counter
                    noSwap = 1;                        // update noSwap var bc rand needed and swap made
                }
            }

            if (noSwap == 0) // exit if there were no swaps
                safeVal = 1;
        }
    }
}
