//
//  main.c
//  C-Programs
//
//  Created by clfbbn on 2017/10/21.
//  Copyright © 2017年 clfbbn. All rights reserved.
//
//  Count C KeyWords
//  Version: 1.0
//  Updated: 2017/10/21
//

#include <stdio.h>
#include <string.h>

#define NKEYS (sizeof keytab / sizeof (struct key))

struct key {
    char* keys;
    int count;
};

struct key keytab[ ] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    /*******/
    "include", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

int isWord(char s) {
    if (s >= 'A' && s <= 'z') {
        return 1;
    } else {
        return 0;
    }
}
int getword(char* s, int max_char) {
    char c;
    int i = 0;
    while ((c = getchar()) == ' ') ;            //  Skip Space
    if (isWord(c)) {
        *(s + i++) = c;
    }
    while (((c = getchar()) != EOF) && isWord(c) ) {
        if (i == max_char) {
            printf("Error stack full in function %s", __func__);
            i = -1;
            break;
        }
        *(s + i++) = c;
    }
    *(s + i) = '\0';
    return i > 0 ? i : EOF;
}

int main( ) {
    char word[100];
    if (getword(word, 100) != EOF) {
        for (int i = 0; i < NKEYS; ++i) {
            if (strcmp(keytab[i].keys, word) == 0) {
                keytab[i].count ++;
            }
        }
    }
    for (int i = 0; i < NKEYS; ++i) {
        printf("\n%s\t%d", (keytab + i)->keys, (keytab + i) -> count);
    }
}

