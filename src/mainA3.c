#include "../include/headerA3.h" // header

int main() // main function definition
{
    a3Emp *headLL = NULL, *temp; // all var intialization
    int funChoice = 1, i, whichOne = 0, whichEmpId = 0, pos = 0;
    int fired = 0;
    char whichName[100] = "", doubleCheck = '\0';

    loadEmpData(&headLL, "proFile"); // loadEmpData function to load records from "proFile"

    do // menu loop runs while user entered num is between 1 - 9 and is a digit
    {
        printf("\n1. Add a new employee\n"); // printfs for menu
        printf("2. Print data of all employees\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on their empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all employees in the current LL\n");
        printf("10. Exit\n");
        printf("\nEnter a choice: ");
        scanf("%d", &funChoice);

        switch (funChoice) // switch loop for user entered value
        {
        case 1:
            recruitEmployee(&headLL); // calls function 1 and exits

            break;
        case 2:
            if (headLL == NULL) // checks for empty list first
                printf("No employees to print...\n");
            printAll(headLL); // then prints list if okay and exits

            break;
        case 3:
            if (headLL == NULL) // first checks for empty list
            {
                printf("No employees to print...\n");
                break;
            }

            printf("Enter a position: "); // if not empty list continues and gets user val
            scanf("%d", &whichOne);

            printOne(headLL, whichOne); // calls function with user val

            break;
        case 4:
            if (headLL == NULL) // if head is empty exits
            {
                printf("No employees to search...\n");
                break;
            }

            printf("Enter an employee Id: "); // gets user val
            scanf("%d", &whichEmpId);

            pos = lookOnId(headLL, whichEmpId); // calls function with user val

            if (pos == -1) // if there was an error code print error message
                printf("Couldn't find the given employee ID...\n");
            else
                printOne(headLL, pos); // else print the list

            break;
        case 5:
            if (headLL == NULL) // if empty list exit
            {
                printf("No employees to search...\n");
                break;
            }

            printf("Enter an employee's full name: "); // gets user val for emp full name
            getchar();                                 // getchar to catch a space
            fgets(whichName, 100, stdin);
            whichName[strlen(whichName) - 1] = '\0'; // removes newline

            pos = lookOnFullName(headLL, whichName); // calls func with user input

            if (pos == -1) // if error code print erorr message
                printf("Couldn't find the given employee...\n");
            else
                printOne(headLL, pos); // else print list

            break;
        case 6:
            if (headLL == NULL) // if head is empty exit
            {
                printf("No employees to count...\n");
                break;
            }

            printf("\nTotal number of employees = %d\n", countEmployees(headLL)); // calls function in printf and exits
            break;
        case 7:
            if (headLL == NULL) // if head is null exits
            {
                printf("No employees to sort...\n");
                break;
            }

            printf("After sorting on employee ID, the employees are as follows: \n"); // print message then sorts and prints sorted LL
            sortEmployeesId(headLL);
            printAll(headLL);

            break;
        case 8:
            if (countEmployees(headLL) > 0) // if there is an employee continue else print message and exit
            {
                printf("\nCurrently there are %d employees. \n", countEmployees(headLL));                                 // prints num emps
                printf("Which employee do you wish to fire -- enter a value between 1 and %d: ", countEmployees(headLL)); // asks for user input
                scanf("%d", &fired);

                if (fired < 0 || fired > countEmployees(headLL)) // checks for correct range of user input
                {
                    printf("Value out of range...\n");
                    fired = 0;
                    break;
                }

                fireOne(&headLL, fired); // calls function
                printAll(headLL);        // prints LL
            }
            else
                printf("There are no employees to fire... \n");

            break;
        case 9:
            if (headLL == NULL) // if the headLL is empty exits
            {
                printf("No employees to fire...\n");
                break;
            }

            printf("\nAre you sure you want to fire everyone? "); // double checks before calling (user input)
            getchar();
            scanf("%c", &doubleCheck);

            if (doubleCheck == 'Y' || doubleCheck == 'y') // checks for correct input and calls if correct
                fireAll(&headLL);

            break;
        default:
            break;
        }
    } while (funChoice <= 9 && funChoice >= 1 && !isdigit(funChoice));

    while (headLL != NULL) // frees whole LL before exiting
    {
        temp = headLL->nextEmployee;
        for (i = 0; i < headLL->numDependents; i++)
            free(headLL->dependents[i]);
        free(headLL->dependents);
        free(headLL);
        headLL = temp;
    }

    return 0;
}