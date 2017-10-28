//
//  main.c
//  C-Programs
//
//  Created by clfbbn on 2017/10/28.
//  Copyright © 2017年 clfbbn. All rights reserved.
//

#include <stdio.h>

#define version 1.0
void pfile(FILE *, FILE *);
int main(int argc, char *argv[]) {
    FILE *fp;       //  Pointer to a file
    int i = 1;
    char *file_name;
    if (argc == 1) {
        printf("BBN's cat program:\n");
        printf("\tVersion:%.2f", version);
        return 1;
    } else {
        while (--argc > 0) {
            file_name = argv[i++];
            if ((fp = fopen(file_name, "r")) == NULL) {
                printf("cat: file %s not found\n", file_name);
                printf("In function: %s", __FUNCTION__);
                return 2;
            } else {
                pfile(fp, stdout);
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
