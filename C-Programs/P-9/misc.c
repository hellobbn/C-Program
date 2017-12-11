//
//  misc.c
//  ContactManager
//
//  Created by clfbbn on 11/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//

#include "main.h"
#include <stdlib.h>
#include <string.h>
pPerson NewPerson(void) {
    pPerson p = malloc(sizeof(struct person));
    p->next = NULL;
    return p;
}

void AddPerson(pPerson person, pPerson head) {
    //  Add person to head->next
    person->next = head->next;
    head->next = person;
}

pPerson Search(char* way, pPerson head, char* words) {
    pPerson position = head->next;
    if (strcmp(way, "name") == 0) {
        while (position) {
            if (strcmp(position->name, words)) {
                break;
            }
            position = position->next;
        }
    } else if(strcmp(way, "number")) {
        while (position) {
            if (strcmp(position->number, words)) {
                break;
            }
            position = position->next;
        }
    }
    return position;
}

void PrintPerson(pPerson position) {
    printf("Name: %s\n", position->name);
    printf("Number: %s\n", position->number);
    printf("\n\n");
}

void FreeContact(pPerson head) {
    pPerson position = head->next;
    pPerson temp;
    while (position) {
        temp = position->next;
        free(position);
        position = temp;
    }
    free(head);
}

void ReadContext(char* arr) {
    char c;
    int input = 0;
    getchar();
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            if (input == 0) {
                break;
            } else {
                c = '\0';
            }
        }
        arr[input++] = c;
    }
}

void MakeTree(char* filename, pPerson head) {
    FILE* fp = fopen(filename, "r+");
    while (!feof(fp)) {
        pPerson node = NewPerson();
        fscanf(fp, "%s %s\n", node->name, node->number);
        AddPerson(node, head);
    }
}
