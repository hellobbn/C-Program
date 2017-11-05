//
//  main.c
//  C-Programs
//
//  Created by clfbbn on 2017/10/28.
//  Copyright © 2017年 clfbbn. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define version "1.2"
void pfile(FILE *, FILE *);
int main(int argc, char *argv[]) {
    FILE *fp;       //  Pointer to a file
    char* var;
    char *prog = argv[0];

    if (argc == 1) {
        printf("usage: cat [file]\n");
        printf("Error input format! Quiting...\n");
        return 1;
    } else if (argc == 2 && **++argv == '-' && *((*argv)+1) == '-') {
        var = (*argv) + 2;
        if (strcmp(var, "version") == 0) {
            printf("bbn's versio of cat, version ");
            printf(version"\n");
            return 0;
        }
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't find file %s", prog, *argv);
                return 2;
            } else {
                pfile(fp, stdout);
                fclose(fp);                         //  inverse of fopen();
            }
        }
    }
}
void pfile(FILE *infile, FILE *outfile) {
    int i;
    while ((i = getc(infile)) != EOF) {
        putc(i, outfile);
    }
    
}
