 #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include <assert.h>
    #include <ctype.h>
    #include <stdlib.h>
    #define SIZE 1024
    struct baza {
        char name[SIZE];
    };


    int cmp_by_name(const void* p1, const void* p2) {
            const char* s1 = ((struct baza*)p1)->name;
            const char* s2 = ((struct baza*)p2)->name;

            return strcmp(s1, s2);
    }
    int find_student(struct baza* student,int size,const char* name ){
        for (int v = 0; v < SIZE; v++){
            if (strcmp(student[v].name, name) == 0){
            return v;
            }   
        }
       return -1; 
    }

    int main(){
        struct baza databaza[SIZE];
        char name[SIZE];
        char name2[SIZE];
        char line[SIZE];
        int size = 0;
        int number;
        int i = 0;
        int res = -1;
        memset(name,0,SIZE);
        memset(name2,0,SIZE);
        memset(line,0,SIZE);
        memset(databaza,0,SIZE*sizeof(struct baza));
        scanf("%d", &number);
        if (number <= 0){
            puts("Nespravny vstup");
            return 0;
        }
        int a = 0;
    while (fgets(line,SIZE,stdin)){
            if (line[0] == '\n'){
                a++;
                if (a == 2){
                    if (i == 0) {
                        puts("Ziadne prihlasky");
                        return 0;
                    }
                    break;
                }
                
                continue;
            }
            if (sscanf(line, "%s %s", name, name2) == 0){
                break;
            }
            if (name2[0] != 0){
                strcat(name, " ");
                strcat(name, name2);
            } 
            int id = find_student(databaza,size,name);
            if (id < 0){
            strcpy(databaza[i].name, name);
            size += 1;
            i++;
            }
            else{
                continue;
            }
            memset(name2,0,SIZE);
            memset(line,0,SIZE);
            memset(name,0,SIZE);
        
        a=0;
        }
        qsort(databaza, i, sizeof(struct baza), cmp_by_name);
        puts("Prijati studenti:");
        int b = 0;
        for (int ok = 0;ok < i;ok++){
            if (ok >= number){
            b++;
        }
            if(b == 1) {
            puts("Neprijati studenti:");
            b++;
        }
          

            printf("%s\n",databaza[ok].name);
        }
        return 0;
    }
