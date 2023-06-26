include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 1024
struct calculator {
    double values[SIZE];
    int size;
};

void push_calculator(struct calculator* stack, double value);
double pop_calculator(struct calculator* stack);
void print_calculator(struct calculator* stack);

int main(){
   struct calculator polska;
   int error = 0;
   double number = 0;
   double number1 = 0;
   char line[SIZE];
    double result = 0;
    memset(&polska,0,sizeof (struct calculator));
    while(true){
        char *r = fgets(line,SIZE,stdin);
      if(line[0] == '\n' || r == NULL){
          break;
      }
      if(ispunct(line[0]) && line[0] != '-' && line[0] != '+' && line[0] != '*' && line[0] != '/'){
          printf("bad input\n");
          return 0;
      }
      if (isalpha(line[0])){
          error++;
          break;
      }
        for (unsigned long int i = 0; i < strlen(line);i++){
            if (!isdigit(line[i])) {
                switch (line[i]) {
                    case '+':
                        break;
                    case '-':
                        break;
                    case '*':
                        break;
                    case '/':
                        break;
                    case ' ':
                        break;
                    case '\n':
                        break;
                    case '.':
                        break;
                    default:
                        error++;
                }
                break;
            }
        }
        bool check = strlen(line) == 2;
        bool check_size = polska.size<2;
        if(check){
            number = 0;
            number1 = 0;
            switch(line[0]){
                case '+':
                    if(check_size){
                        printf("not enough operands\n");
                        return 0;
                    }
                    number = pop_calculator(&polska);
                    number1 = pop_calculator(&polska);
                    result = number + number1;
                    push_calculator(&polska,result);
                    break;
                case '-':
                    if(check_size){
                        printf("not enough operands\n");
                        return 0;
                    }
                    number = pop_calculator(&polska);
                    number1 = pop_calculator(&polska);
                    result = number1 - number;
                    push_calculator(&polska,result);
                    break;
                case '*':

                    number = pop_calculator(&polska);
                    number1 = pop_calculator(&polska);
                    if (number == 0 || number1 == 0){
                        printf("division by zero\n");
                        return 0;
                    }
                    result = number1 * number;
                    push_calculator(&polska,result);
                    break;
                case '/':
                    if(check_size){
                        printf("not enough operands\n");
                        return 0;
                    }
                    number = pop_calculator(&polska);
                    number1 = pop_calculator(&polska);
                    if (number == 0 || number1 == 0){
                        printf("division by zero\n");
                        return 0;
                    }
                    result = number1 / number;
                    push_calculator(&polska,result);
                    break;
            }
        }
        bool check_cislo = isdigit(line[0]);
        if(check_cislo){
            char *start = line;
            char *endptr = NULL;
            push_calculator(&polska,strtold(start, &endptr));
            if(polska.size > 10){
                printf("full stack\n");
                return 0;
            }
        }
        print_calculator(&polska);
    }

    bool chyba = error ==0;
    if (chyba){
        printf("no input\n");
    }
    if(!chyba){
        printf("bad input\n");
    }
    return 0;
}

void push_calculator(struct calculator* stack, double value){
    if (stack->size < SIZE) {
        stack->values[stack->size] = value;
        stack->size++;
    }
};
double pop_calculator(struct calculator* stack){
    if (stack->size > 0) {
        stack->size--;
        return stack->values[stack->size];
    }
    return 0;
};
void print_calculator(struct calculator* stack){
    for (int i = 0; i < stack->size; i++) {
        printf("%0.2lf ", stack->values[i]);
    }
    printf("\n");
};
