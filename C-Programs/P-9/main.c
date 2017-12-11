//
//  main.c
//  ContactManager
//
//  Created by clfbbn on 11/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//

#include "main.h"
#include <stdlib.h>
#include <ctype.h>
#include <TargetConditionals.h>

int PrintMenu(void) {
    int choise = 0;
    printf("-------- Contact Manager --------\n\n");
    
    printf("1. Add a person to your contact.\n");
    printf("2. Show all people in your contacts.\n");
    printf("3. Change a person's information. \n");
    printf("4. Search for a person's information. \n\n");
    printf("5. Save and quit. \n");
    printf("6. Recover the contacts from file... \n");
    printf("7. exit directory \n");
    printf("-----------------------------------\n\n");
    printf("Please choose a number: ");
    scanf("%d", &choise);
    system("clear");
    return choise;
}

int main(int argc, const char * argv[]) {
    
    int choise;
    pPerson found;
    pPerson contact = NewPerson();
    system("clear");
#if TARGET_OS_MAC == 1
    char* defaultname = "Contact";
    int re = system("ls Contact");
    system("clear");
    if (re == 0) {                //  Check if a file Contact exist
        printf("Using Contact file to build a tree ? (y, n)");
        char c;
        scanf("%c", &c);
        if (toupper(c) == 'Y') {
            MakeTree(defaultname, contact);
        } else {
            printf("Delete it? (y/n)");
            scanf("\n%c", &c);
            if (toupper(c) == 'Y') {
                system("rm Contact&&clear");
            }
        }
    }
#endif
    while ((choise = PrintMenu())) {
        switch (choise) {
            case 1:
                // 1. Add a person to your contact.
                MakePerson(contact);
                break;
            case 2:
                // 2. Show all people in your contacts.
                PrintPeople(contact);
                break;
            case 3:
                // 3. Change a person's information.
                found = SearchPerson(contact);
                ChangeInformation(found);
                break;
            case 4:
                // 4. Search for a person's information.
                found = SearchPerson(contact);
                printf("Here is his Profile: \n");
                PrintPerson(found);
                break;
            case 5:
                // 5. Save and quit.
                SaveContact(contact);
                FreeContact(contact);
                exit(0);
                break;
            case 6:
                // 6. Recover the contacts from file...
                ReadContact(contact);
                break;
            case 7:
                exit(0);
            default:
                printf("Error no match!\n");
                exit(1);
                break;
        }
        printf("Press Any key to continue ...");
        getchar();
        getchar();
        system("clear");
    }
    return 0;
}
