#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LINESIZE 1024
struct pizza{
    char name[LINESIZE];
    double prize;

};
struct cena{
    char cena [LINESIZE];
};
struct name{
    char name [LINESIZE];
};
int main(){
    int i = 0;
    unsigned long int pocet = 0;
    unsigned long int  pocet1 = 0;
    int k = 0;
    int i2 = 0;
    int i3 = 0;
    char line [LINESIZE];
    struct pizza start[LINESIZE];
    struct pizza nulova[LINESIZE];
    struct pizza name[LINESIZE];
    struct pizza cislo[LINESIZE];
    memset(&cislo,0,sizeof(struct pizza));
    memset(line,0,LINESIZE);
    memset(&name,0,sizeof(struct pizza));
    memset(&nulova,0,sizeof(struct pizza));
    memset(&start,0,sizeof (struct pizza));

    while(1) {
        char *r = fgets(line, LINESIZE, stdin);
        if (line[0] == '\n') {
            break;
        }
        if (r == NULL) {
            break;
        }
        if (i == 0){
            strcpy(nulova[0].name,line);
        }
        if (i%2 != 0) {
            strcpy(start[i3].name, line);
            i3++;
        }
        if (i%2 == 0 && i != 0) {
            sscanf(line,"%lf",&start[i2].prize);
            i2++;
        }
        i++;
        memset(line, 0, LINESIZE);
    }
    char *c1 = nulova[0].name;
    for (unsigned long int lig = 0; lig < strlen((const char*)nulova[0].name);lig++){
        switch (c1[lig]){
            case '0': c1[lig] = 'o';break;
            case '1': c1[lig] = 'i';break;
            case '2': c1[lig] = 'z';break;
            case '3': c1[lig] = 'e';break;
            case '4': c1[lig] = 'a';break;
            case '5': c1[lig] = 's';break;
            case '6': c1[lig] = 'b';break;
            case '7': c1[lig] = 't';break;
            case '8': c1[lig] = 'b';break;
            case '9': c1[lig] = 'q';break;

        };
    }
    for (unsigned long int lig = 0; lig < strlen((const char *) nulova[0].name); lig++) {
        c1[lig] = (char) tolower(c1[lig]);

    }



    for(int i4 = 0;i4 < i3;i4++){
        strcpy(name[i4].name,start[i4].name);

    }
    for (int lig = 0; lig < i3;lig++){
        unsigned long int cis = strlen((const char*) name[lig].name);
        char *c2 = name[lig].name;
        for (unsigned long int k1 = 0;k1 < cis;k1++){
            if (isalpha(c2[k1])) {
                c2[k1] = (char) tolower(c2[k1]);
            }
        }
    }
    for (;k < i3;k++){
        char *c = name[k].name;
        unsigned long int cis = strlen((const char*)name[k].name);
        for(unsigned long int k1 = 0; k1 < cis; k1++){
            switch (c[k1]){
                case '0': c[k1] = 'o';break;
                case '1': c[k1] = 'i';break;
                case '2': c[k1] = 'z';break;
                case '3': c[k1] = 'e';break;
                case '4': c[k1] = 'a';break;
                case '5': c[k1] = 's';break;
                case '6': c[k1] = 'b';break;
                case '7': c[k1] = 't';break;
                case '8': c[k1] = 'b';break;
                case '9': c[k1] = 'q';break;

            };
        }
    }
    int i5[LINESIZE];
    int i7 = 0;
    int sas = 0;
    memset(i5,0,LINESIZE);
    char *c10 = nulova[0].name;
    for (k = 0;k < i3;k++){
        char *c = name[k].name;
        int k2 = 0;
        int k3 = 0;
        unsigned long int cis = strlen((const char*)name[k].name)-1;
        unsigned long int cis1 = strlen((const char*)nulova[0].name)-1;
        for (unsigned long int k1 = 0;k1 < cis; k1++){
            if(c10[k2]!=c[k1]){
                k2=0;
                pocet1=0;
            }
            if (c10[k2] == c[k1]) {
                pocet1++;
                k2++;
            }
            if(pocet1==cis1){
                pocet++;

            }
            if (pocet1 == cis1) {
                i5[i7] = k;


                i7++;
                break;
            }


        }
        if (pocet1 == cis1){
            strcpy(cislo[sas].name,start[k].name);
            cislo[sas].prize = start[k].prize;
            sas++;
            pocet1=0;
        }

//        pocet = 0;
//        pocet1= 0;
    }

/*jablko
Ja8lkova P1zza
45
Ja8lkova P1zza
45.00
M4linovo j4blkova
23.1
M4linovo j4blkova
23.10
Hubova pizza
11.2*/



/*    0 <=> o
    1 <=> i
    2 <=> z
    3 <=> e
    4 <=> a
    5 <=> s
    6 <=> b
    7 <=> t
    8 <=> b
    9 <=> q*/
    printf("Zadaj hladanu surovinu:\n");
    printf("Zadaj jedalny listok:\n");

    for (int k2 = 0; k2 < i7; k2++) {
        printf("%s", cislo[k2].name);
        printf("%0.2lf\n",cislo[k2].prize);
    }
    printf("Nacitanych %d poloziek.\n",i3);


    return 0;
}
