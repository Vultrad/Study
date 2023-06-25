#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 1024
int main(){
    char pole [SIZE];
    char ch;
    double line [SIZE];
    memset(line,0,SIZE);
    memset(pole,0,SIZE);
    int i = 0,k = 0,v = 0,o = 0,b = 0,position = 0,cislo = 0;



    while ((ch = getchar()) !=EOF){
        
        pole[k] = ch;
        if (pole[k-1] == '\n' && ch == '\n'){
            break;
        }
        k++;
          }
int space = 0;
    

    for (int lo = 0; lo < k; lo++){
        if(pole[lo] == '\n'){
            cislo++;
            position = cislo;
            space++;
            if(pole[lo+1] == '\n'){
                space++;
                break;
            }
            space = 0;
        }
        if (isalpha(pole[lo])){
            if(isalpha(pole[0])){
                printf ("Nepodarilo sa nacitat zaklad x\n");
                return 0;
            }
            printf ("Nepodarilo sa nacitat polynom na %d mieste.\n",position);
            return 0;
        }
        }

int len = strlen(pole);

char* endptr = NULL;

char* start = pole;

double num = 0;

 while (start < (pole + len)){
    num = strtold(start,&endptr);
     if (num >= 0){
        i++;
        start = endptr +1;
        line[v] = num;
        v++;
        
    }else{
    break;
    }
  

    
} 




double sum = 0;
if (space == 0){
    i++;
}
int p=i-3;

int s = 0;
for (s = 1; s < i-1; s++){
    sum +=line[s]*pow(line[0],p);
    p--;
}
printf("Vysledok je: %0.2lf\n", sum);

    return 0;
}


