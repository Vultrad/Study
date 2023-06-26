#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define LINESIZE 1024
typedef struct pizza {
    double cena;
    char name[LINESIZE];
}p;
p *array = NULL;
int cmp(const void *a, const void *b)
{
    struct pizza *s1 = (struct pizza *)a;
    struct pizza *s2 = (struct pizza *)b;
    return s1->cena > s2->cena ;
}
int tmp (const void * a, const void * b) {
    const char * pizza1 = ((struct pizza *)a)->name;
    const char * pizza2 = ((struct pizza *)b)->name;
    return strcmp(pizza1, pizza2);
}

int main(){
    int k = 0;
    int i = 0;
    int i1 = 0;
    char line[LINESIZE];
    struct pizza pizza_name[LINESIZE];
    struct pizza pizza_copy[LINESIZE];
    memset(pizza_name,0,sizeof (struct pizza)*LINESIZE);
    memset(pizza_name,0,sizeof(struct pizza)*LINESIZE);
    memset(pizza_copy,0,sizeof(struct pizza)*LINESIZE);
    while(true){
        char *r = fgets(line,LINESIZE,stdin);
        if (line[0] == '\n'|| r == NULL){
            break;
        }
        if (k%2 == 0){
            strcpy(pizza_name[i].name,line);
            i++;

        }
        if (k%2 != 0){
            sscanf(line, "%lf",&pizza_name[i1].cena);
                if(pizza_name[i1].cena == 0){
                    i--;
                memset(pizza_name[i].name,0,LINESIZE);
                break;
            }
            i1++;
        }
        k++;
    }
    qsort(pizza_name,i,sizeof(struct pizza),tmp);
    qsort(pizza_name,i1,sizeof(struct pizza),cmp);
    int a = 0;
    for(;a < i;a++){
        printf("%s",pizza_name[a].name);
        printf("%lf\n",pizza_name[a].cena);
    }

    return 0;
}
