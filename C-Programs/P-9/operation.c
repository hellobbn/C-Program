//
//  operation.c
//  ContactManager
//
//  Created by clfbbn on 11/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//

#include "main.h"
#include <stdlib.h>

void MakePerson(pPerson head) {
    int n;
    printf("How many poeple do you want to add? ");
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i) {
        pPerson person = NewPerson();
        printf("Adding the %d%s person to your contact: \n",
               i+1 , i+1 == 1?"st":i+1 == 2?"nd":i+1 == 3?"rd":"th");
        printf("Enter his name: ");
        scanf("%s", person->name);
        printf("Enter his number: ");
        scanf("%s", person->number);
        printf("\n");
        AddPerson(person, head);
    }
}

void PrintPeople(pPerson head) {
    pPerson current = head->next;
    int i = 0;
    printf("\n");
    while (current) {
        ++i;
        printf("--- The %d%s Person ---\n", i, i == 1?"st":(i == 2?"nd":(i == 3?"rd":"th")));
        PrintPerson(current);
        current = current->next;
    }
}

pPerson SearchPerson(pPerson head) {
    char c = '1';
    pPerson searchd = NULL;
    char* words = malloc(sizeof(char)* 100);
    printf("Do you want to search by name(1) or by number(2)? (Default: Name) \n");
    printf("Enter the number please: ");
    getchar();
    c = getchar();
    printf("Enter the %s: ",c == '1'?"name":"number");
    scanf("%s", words);
    switch (c) {
        case '1':
            searchd = Search("name", head, words);
            break;
        case '2':
            searchd = Search("number", head, words);
        default:
            printf("Not recognized. Searching by name...\n");
            searchd = Search("name", head, words);
            break;
    }
    return searchd;
}

void ChangeInformation(pPerson position) {
    printf("Origin Information: \n");
    PrintPerson(position);
    printf("Enter new name here: (Default: Change nothing) ");
    ReadContext(position->name);
    printf("Enter new number here: (Default: Change nothing) ");
    ReadContext(position->number);
    
    printf("Current information: \n");
    PrintPerson(position);
}

void SaveContact(pPerson head) {
    pPerson position = head->next;
    printf("Where do you want to save it? (Default: ./Contact)");
    char filename[100] = "Contact";
    ReadContext(filename);
    FILE* fp = fopen(filename, "w+");
    while (position) {
        fprintf(fp, "%s %s\n", position->name, position->number);
        position = position->next;
    }
    fclose(fp);
}

void ReadContact(pPerson head) {
    char filename[100] = "Contact";
    printf("Enter the backup filename: (Default: ./Contact)");
    ReadContext(filename);
    MakeTree(filename, head);
}
