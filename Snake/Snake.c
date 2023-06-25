#include "snake.h"
#include <stdlib.h>
struct snake* add_snake(struct snake* snake,int x,int y){

    if (x < 0 || y < 0) 
        return	0;
    struct snake* head = calloc(1,sizeof(struct snake));
    head->x = x;    
    head->y = y;
    head->next = snake;
    snake = head;
    return head;
}

struct snake* remove_snake(struct snake* snake){

    struct snake* this = snake;
    while (this != NULL){
        // Niečo môžme s prvkom this spraviť
        this= this->next;
    }
    free(this);
    return NULL;
}

void free_snake(struct snake* sn){
    struct snake* tmp;
    while (sn != NULL)
    {
       tmp = sn;
       sn = sn->next;
       free(tmp);
    }
    
}

int is_snake(struct snake* snake,int x,int y){
    return 0;
}

int step_state(struct state* st){
	int nx = (st->snake->x + st->sx);
    int ny = (st->snake->y + st->sy);
    return END_CONTINUE;
}
