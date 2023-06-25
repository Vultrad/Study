#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
 


int main(){
int i = 0,v=0,m=0,k=0,count=0,l=0;
int pole [50]; 
memset (pole,0,50);// обнуление массива 
int max = pole[0];

while (scanf ("%d",&pole[i]) != EOF){ //это проверка на еоф, что бы цикл завершался, когда еоф был введен
i++;
}

   
for (int v = 0; v < i; v++){ // тут написано в меньше и, i это количество сколько раз было введено число, что бы оно не привышалось

if (pole[v] < 1 && v!=0 ){
              break;}
                  if(pole[0]<1){
            printf("Chyba: Málo platných hodnôt.\n");
             return 0;
         }
    if (pole[v] > max){//тут нахождение именно числа, поэтому пишем поле а не просто в, в это количество итераций 
        max = pole[v];
      }
    
           
}

for (int v=0;v<i; ++v){
if (pole[v] == max){
++count;
}
}


int array [count];
memset(array,0,count * sizeof(int));
        if(count == 0){
            printf("Chyba: Málo platných hodnôt.\n");
             return 0;
         }

int s=0;
while (v<i){
 
 if(pole[v]==max){
     array[s]=v+1;
     s++;
     v++;
 }
 else{
v++;

 }

}



while (k < i){
    if (pole[k] < 1 && k!=0 ){
              break;}
printf("Súťažiaci č. %d vypil %d pohárov.\n",k+1,pole[k]); 
k++;}  

for(s = 0; s<count; s++){
        if (pole[s] < 1 && s!=0 ){
              break;}
printf("Výherca je súťažiaci %d ktorý vypil %d pohárov.\n",array[s],max);
}     
return 0;
}



