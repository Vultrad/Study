 #include <stdio.h>
    #include <time.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #define SIZE 2048
    typedef int celoe;
    typedef double neceloe;
    typedef char bukva;

    int main (){
    char ch;
    int dd = 0,mm = 0,yy = 0,days = 0,days2 = 0,mounth = 0,rok = 0;
    char b1 ,b2 ;
    char pole[SIZE];
    int line [SIZE];
    memset (pole,0,SIZE);
    memset (line,0,SIZE);
    int cisl = 0;
    int v = 0;
    int i = 0;
    int logion = 0;
    int enters = 0;
    int tocka = 0;
    int minus = 0;
    int chyba = 0;

    while ((ch = getchar ()) != EOF ){
        
        pole[cisl] = ch;
        cisl++;
        if (pole[0] == '\n'){
            
            break;
        }
       
        if (isalpha(ch)){
           logion = 1;

        }
        if (ch == '.'){
            tocka = 1;
        }
        if (ch == '-'){
            minus = 1;
        }
        if (ch == ','){
            chyba = 1;
        }
         
    if (ch == '\n'){
        enters++;
    int len = strlen(pole);

    char* endptr = NULL;

    char* start = pole;

    int num = 0;


    while (start < (pole + len)){
        num = strtol(start,&endptr,10);
        if (num >= 0){
            i++;
            start = endptr +1;
            line[v] = num;
        //  printf ("som nacital %d" ,num);
            v++;
            
        }else{
        break;
        }
    

        
    }
    dd = line[0];
    mm = line[1];
    yy = line[2];
    // printf("\n%d\n",yy % 4);
    if (dd > 31 || mm > 12 ){
        chyba = 1;
    }
     
    if ( (yy % 4 == 0 || yy % 4 != 0) && logion == 0 && tocka == 1 && line[0] != 0 && minus == 0 && line[2] != 0 && line[2] > 1850 && line[2] < 2230 && chyba == 0 ){
        days = dd + 7;
        if(days > 31 && ( mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 ) ){
            days2 = days % 31;
            mounth = mm + 1;
            rok = yy;
            
            
        }
        if ( days > 31 && mm == 12){
            days2 = days % 31;
            mounth = 1;
            rok = yy +1;
        }
        if (days > 30 && ( mm == 4 || mm == 6 || mm == 9 || mm == 11 ) ){
            days2 = days %30 ;
            mounth = mm+1;
            rok = yy;
        }
        if (days > 29 &&  mm == 2 && yy % 4 == 0){
            days2 = days %29;
            mounth = mm+1;
            rok = yy;
        }else if(days > 29 && mm == 2 && yy % 4 >= 1){
            chyba = 1;
            
        }
      
        if (days >= 1 && days <= 31 && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)){
            days2 = dd + 7;
            mounth = mm;
            rok = yy;
        }
        if ( days >=1 && days <= 30 && (mm == 4 || mm == 6 || mm == 9 || mm == 11)){
            days2 = dd + 7;
            mounth = mm;
            rok = yy;
        }
        if ( days >=1 && days <= 29 && mm == 2){
            days2 = dd + 7;
            mounth = mm;
            rok = yy;
        }
    if (chyba == 0){
 printf ("%d.%d.%d\n\n",days2,mounth,rok);
    }
    }
    
   if (logion != 0 || tocka == 0 || line[0] == 0 || minus == 1 || line[2] == 0 || line[2] < 1850 || chyba == 1 || line[2] > 2230 ){
       printf("Neplatny datum.\n");
   }
    dd = 0,mm = 0,yy = 0,days = 0,days2 = 0,mounth = 0,rok = 0;
    memset (pole,0,SIZE);
    memset (line,0,SIZE);
    cisl = 0, v = 0, i = 0;
    logion = 0;
    tocka = 0;
    minus = 0;
    chyba = 0;



    }
    }






        return 0;
    }
