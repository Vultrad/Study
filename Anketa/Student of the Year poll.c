 #include <stdio.h>
    #include <time.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #define SIZE 100
        struct programma {
            char line[SIZE];
            char name[SIZE];
            int i;
            int size;
            int pik;
            
        }p;
       
       
    struct student {
            char name[SIZE];
            int votes;
        
        }s;

    int cmp(const void * a, const void* b){
            struct student* s1 = (struct student*)a;
            struct student* s2 = (struct student*)b;

            return s2->votes - s1->votes;
        }

    int tmp (const void* a, const void* b) {
            const char* student1 = ((struct student*)a)->name;
            const char* student2 = ((struct  student*)b)->name;
            return strcmp(student1, student2);
        }

    int find_student(struct student* students,int size, const char* name){
        for (int v = 0; v < SIZE; v++){
        
            if(strcmp(students[v].name, name) == 0){
                return v;
                }
            }
    
    return -1;
}


    int main (){
        struct student databaza[SIZE];
        p.i = 0;
        memset(p.line,0,SIZE);
        memset(databaza,0,SIZE*sizeof(struct student));
        p.size = 0;
            for (int ciklus = 0;ciklus < SIZE; ){
                char* r = fgets(p.line,SIZE,stdin);
                        if (isalpha(p.line[1])){
                            p.pik =0;
                    break;
             }else if(isalpha(p.line[0])){
                
                 break;
             }
                    
                    if (r == NULL){
                        break;
                     }
                    if (p.line[0] == '\n'){
                        break;
                     }
        char* end = NULL;
        databaza[ciklus].votes = strtol(p.line,&end,10);
                    if (databaza[ciklus].votes == 0){
                        
                      break;
                    };
        // printf("%d",databaza[ciklus].votes);
    
        memset (p.name,0,SIZE);
        char* zaciatok_mena = end+1;
        int velkost_mena = strlen(zaciatok_mena) - 1;   
            for (int v = 0; v < SIZE;v++){
                if (velkost_mena > 0){
                    memcpy(p.name,zaciatok_mena,velkost_mena);
                }
        }
      
            for (int v = 0; v < SIZE;v++){
            
        }
                int id=find_student(databaza, p.size, p.name);
                    if (id < 0){
                        memcpy(databaza[ciklus].name,p.name,velkost_mena);
                        p.size +=1;
                        ciklus++;
                    }else{
                        databaza[id].votes = databaza[ciklus].votes + databaza[id].votes;
                  
                }
       
        memset(p.name,0,SIZE);
        databaza[ciklus].votes = 0;
            //  printf("%s", databaza[ciklus].name);
            
    } 
   
 
        qsort(databaza,SIZE,sizeof(s),tmp);
        qsort(databaza,SIZE, sizeof(s),cmp);
        if (p.pik == 1){
           
        }
       if (databaza[0].votes != 0 && p.pik != 1){
           printf("Vysledky:\n");
       }else if (databaza[0].votes == 0){
            printf("Nepodarilo nacitat nic\n");
       }

            for(p.i = 0;p.i < SIZE; p.i++){
                if (databaza[p.i].votes == 0){
                     break;
            }
         printf("%d %s\n",databaza[p.i].votes, databaza[p.i].name);
       
      
        }
        
             
        return 0;
    }


