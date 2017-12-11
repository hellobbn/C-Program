//
//  main.h
//  ContactManager
//
//  Created by clfbbn on 11/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//

typedef struct person* pPerson;

struct person {
    char name[100];
    char number[100];
    pPerson next;
};

#ifndef main_h
#define main_h

#include <stdio.h>

pPerson NewPerson(void);

void MakePerson(pPerson head);
void AddPerson(pPerson person, pPerson head);

void PrintPeople(pPerson head);

pPerson SearchPerson(pPerson head);
pPerson Search(char* way, pPerson head, char* words);

void ChangeInformation(pPerson position);
void PrintPerson(pPerson position);

void SaveContact(pPerson head);
void FreeContact(pPerson head);

void ReadContact(pPerson head);
void MakeTree(char* filename, pPerson head);

void ReadContext(char* arr);
#endif /* main_h */

