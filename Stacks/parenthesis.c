#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();


struct stack
{
    int d;
    struct stack *next;
};
struct stack *s=NULL;

void push(struct stack **top,char x)
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->d=x;
    if(*top==NULL)
    {
        s->next=NULL;
        *top=s;
    }
    else
    {
        s->next=*top;
        *top=s;
    }
}

char pop(struct stack **top)
{
    if(*top==NULL)
    {
        printf("nothing to pop");
    }
    else
    {
        struct stack *p=*top;
        *top=(*top)->next;
        free(p);
    }
return top;
}
char top(struct stack *top)
{
    if(top==NULL)
        return -1;
    else
        return top->d;
}
// Please store the size of the string array to be returned in result_count pointer. For example,
// char a[2][6] = {"hello", "world"};
// *result_count = 2;
// return a;
char** braces(int values_count, char** values, int* result_count) 
{
    char **r= malloc(values_count * sizeof(char*));
    int i,j;
    for(i=0;i<values_count;i++)
    {
        int flag=1;
        char temp=0;
        for(j=0;j<strlen(values[i]);j++)
        {
            if(values[i][j]=='(' || values[i][j]=='[' || values[i][j]=='{')
                push(&s,values[i][j]);
            if(values[i][j]==')' || values[i][j]==']' || values[i][j]=='}')
                if(top(s)==-1)
                    flag=0;
                else
                {
                temp=pop(&s);
                if(values[i][j]==')' && (temp=='{' || temp=='['))
                    flag=0;
                if(values[i][j]==']' && (temp=='{' || temp=='('))
                    flag=0;
                if(values[i][j]=='}' && (temp=='(' || temp=='['))
                    flag=0;
                }
        }
        if(top(s)>=0)
        flag=0;

        if(flag==1)
            strcpy(r[i],"YES");
        else
            strcpy(r[i],"NO");
    
    }
    *result_count=values_count;
    return r;
}






































int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* values_count_endptr;
    char* values_count_str = readline();
    int values_count = strtol(values_count_str, &values_count_endptr, 10);

    if (values_count_endptr == values_count_str || *values_count_endptr != '\0') { exit(EXIT_FAILURE); }

    char** values = malloc(values_count * sizeof(char*));

    for (int i = 0; i < values_count; i++) {
        char* values_item = readline();

        *(values + i) = values_item;
    }

    int res_count;
    char** res = braces(values_count, values, &res_count);

    for (int i = 0; i < res_count; i++) {
        fprintf(fptr, "%s", *(res + i));

        if (i != res_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

