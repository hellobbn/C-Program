//
//  main.c
//  C-Programs
//
//  Created by clfbbn on 2017/10/26.
//  Copyright © 2017年 clfbbn. All rights reserved.
//
//  Table Lookup
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

struct clist {
    struct clist *next;
    char *name;
    char *defn;
};
static struct clist *hashtab[HASHSIZE];

unsigned hash(char *s) {
    unsigned hashval;
    
    for (hashval = 0; *s != '\0'; ++s) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

struct clist *lookup(char *s) {
    struct clist *np;
    
    for (np = hashtab[hash(s)]; np != NULL; np = np -> next) {
        if (strcmp(np->name, s) == 0) {
            return np;
        }
    }
    return NULL;
}

struct clist *install(char *name, char *defn) {
    struct clist *np;
    unsigned hashval;
    
    if ((np = lookup(name)) == NULL) {
        np = (struct clist *) malloc(sizeof(*np));
        if (np == NULL || (np -> name = strdup(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np -> next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free((void *) np->defn);
    }
    if ((np -> defn = strdup(defn)) == NULL) {
        return NULL;
    }
    return np;
}


    
