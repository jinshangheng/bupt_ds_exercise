#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    char data;
    struct node * next;
}node, * Stack;

typedef struct fnode{
    float data;
    struct fnode * next;
}fnode, * fStack;

void init_stack(Stack &s);
bool empty_stack(Stack s);
char pop_stack(Stack &s);
void push_stack(Stack &s, char e);
char top_stack(Stack s);
//stack functions

void f_init_stack(fStack &s);
float f_pop_stack(fStack &s);
void f_push_stack(fStack &s, float e);
float top_stack(fStack s);
//float stack functions

int get_prior(char ch);
char * get_post(char * str);
//from pre to post

float calc(char * str);
//calculate from post expression

int main(){
    char * temp = (char *) malloc(sizeof(char)*100);
    scanf("%s", temp);
    temp = get_post(temp);
    printf("%.2f\n", calc(temp));
    for(int i = 0; i < strlen(temp); i++){
        printf("%c ", temp[i]);
    }
}

void init_stack(Stack &s){
    s = (Stack)malloc(sizeof(Stack));
    s -> next = NULL;
    //init s
}

bool empty_stack(Stack s){
    return (s -> next == NULL);
}

void push_stack(Stack &s, char e){
    Stack p = (Stack)malloc(sizeof(node));
    p -> data = e;
    p -> next = s -> next;
    s -> next = p;
    //insert
}

char pop_stack(Stack &s){
    char ret = s -> next -> data;
    //save return value

    Stack p = s -> next;
    s -> next = p -> next;
    free(p);
    //delete

    return ret;
}

char top_stack(Stack s){
    return s -> next -> data;
}

int get_prior(char ch){
    if(ch == '('){
        return 1;
    } else if(ch == '+' || ch == '-'){
        return 2;
    } else if(ch == '*' || ch == '/'){
        return 3;
    } else{
        return 4;
    }
}



void f_init_stack(fStack &s){
    s = (fStack)malloc(sizeof(fnode));
    s -> next = NULL;
    //init s
}

void f_push_stack(fStack &s, float e){
    fStack p = (fStack)malloc(sizeof(fnode));
    p -> data = e;
    p -> next = s -> next;
    s -> next = p;
    //insert
}

float f_pop_stack(fStack &s){
    float ret = s -> next -> data;
    //save return value

    fStack p = s -> next;
    s -> next = p -> next;
    free(p);
    //delete

    return ret;
}

float f_top_stack(fStack s){
    return s -> next -> data;
}

char * get_post(char * str){
    Stack s;
    init_stack(s);
    //init stack s

    int size = strlen(str);
    int i = 0;
    int j = 0;
    //indexs

    char temp;
    char * res = (char *)malloc(sizeof(char) * 100);
    //some variables

    while(i < size){
        if(str[i] >= '0' && str[i] <= '9'){
            res[j] = str[i];
            j++;
        } else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            if(empty_stack(s)){
                push_stack(s, str[i]);
            } else{
                while(!empty_stack(s)){
                    temp = top_stack(s);
                    if(get_prior(temp) >= get_prior(str[i])){
                        res[j] = temp;
                        j++;
                        pop_stack(s);
                    } else{
                        break;
                    }
                }
                push_stack(s, str[i]);
            }
        } else{
            if(str[i] == '('){
                push_stack(s, str[i]);
            } else{
                while(top_stack(s) != '('){
                    temp = top_stack(s);
                    res[j] = temp;
                    j++;
                    pop_stack(s);
                }
                pop_stack(s);
            }
        }
        i++;
    }

    while(!empty_stack(s)){
        temp = top_stack(s);
        res[j] = temp;
        j++;
        pop_stack(s);
    }
    return res;
}

float calc(char * str){
    fStack s;
    f_init_stack(s);
    //init stack s;

    int size = strlen(str);
    //condition

    float n1, n2, n3;
    //temp

    for (int i = 0; i < size; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            switch (str[i])
            {
                case '0': f_push_stack(s, 0.0F); break;
                case '1': f_push_stack(s, 1.0F); break;
                case '2': f_push_stack(s, 2.0F); break;
                case '3': f_push_stack(s, 3.0F); break;
                case '4': f_push_stack(s, 4.0F); break;
                case '5': f_push_stack(s, 5.0F); break;
                case '6': f_push_stack(s, 6.0F); break;
                case '7': f_push_stack(s, 7.0F); break;
                case '8': f_push_stack(s, 8.0F); break;
                case '9': f_push_stack(s, 9.0F); break;
                default: break;
            }
        }
        else {
            n2 = f_top_stack(s);
            f_pop_stack(s);
            n1 = f_top_stack(s);
            f_pop_stack(s);
            if (str[i] == '+') {
                n3 = n1 + n2;
            }
            else if (str[i] == '-') {
                n3 = n1 - n2;
            }
            else if (str[i] == '*') {
                n3 = n1 * n2;
            }
            else if (str[i] == '/') {
                n3 = n1 / n2;
            }
            f_push_stack(s, n3);
        }
    }
    return f_top_stack(s);
}