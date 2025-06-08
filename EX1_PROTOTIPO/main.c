#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_combinations(int i,int j, int size, int combinations[][2], int *it) {
    if (i >= size) return;
    if (j >= size) {
        generate_combinations(i+1,0, size, combinations, it);
        return;
    }
    if (i != j) {
        combinations[*it][0] = i;
        combinations[*it][1] = j;
        (*it)++;
    }

    generate_combinations(i, j+1, size,combinations, it);
}



void generate_new_list(int *curr_list, char curr_string_vector[][100], int size, int i1, int i2, int operation_type, int *new_list, char new_string_vector[][100], int i, int k, int flag)
{
    if(i == size) return;
    if((i == i1 || i == i2) && flag == 0)
    {
        char *aux1 = "(";
        char *aux3 = ")";
        char aux2[100];
        char buffer[100];
        if(operation_type == 0)
        {
            new_list[i] = curr_list[i1]*curr_list[i2];
            strcpy(aux2, "*");
        }
        if(operation_type == 1 && curr_list[i1]%curr_list[i2] == 0)
        {
            new_list[i] = curr_list[i1]/curr_list[i2];
            strcpy(aux2, "/");
        }
        if(operation_type == 2)
        {
            new_list[i] = curr_list[i1]+curr_list[i2];
            strcpy(aux2, "+");
        }
        if(operation_type == 3)
        {
            new_list[i] = curr_list[i1]-curr_list[i2];
            strcpy(aux2, "-");
        }
        strcpy(buffer, aux1);
        strcat(buffer, curr_string_vector[i1]);
        strcat(buffer, aux2);
        strcat(buffer, curr_string_vector[i2]);
        strcat(buffer, aux3);
        strcpy(new_string_vector[i], buffer);
        flag = 1;
        generate_new_list(curr_list, curr_string_vector, size, i1, i2, operation_type, new_list, new_string_vector, i+1, k, flag);
    }
    else if(i != i1 && i != i2)
    {
        new_list[i] = curr_list[i+k];
        strcpy(new_string_vector[i], curr_string_vector[i+k]);
        generate_new_list(curr_list, curr_string_vector, size, i1, i2, operation_type, new_list, new_string_vector, i+1, k, flag);
    }
    else if((i == i1 || i == i2) && flag == 1)
    {
        k++;
        new_list[i] = curr_list[i+k];
        strcpy(new_string_vector[i], curr_string_vector[i+k]);
        generate_new_list(curr_list, curr_string_vector, size, i1, i2, operation_type, new_list, new_string_vector, i+1, k, flag);
    }
    return;
}


void find_expression(int size,int curr_list[size], int i, int value, char curr_string_vector[][100], char *ans, int flag, int combinations[][2])
{
    if(size == 0)
    {
        if(curr_list[0] == value && strcmp(ans,"Nao foi possivel formar o valor alvo") == 0)
        {
            strcpy(ans, curr_string_vector[0]); 
        }
         return;
    }
    if(flag == 0)
    {
       int n = (size+1)*(size);
       int new_combinations[n][2];
       int h = 0;
       generate_combinations(0,0,size+1, new_combinations, &h);
       flag = 1;
       find_expression(size,curr_list,0,value,curr_string_vector,ans,flag,new_combinations);
       return;
    }
    int i1 = 0; int i2 = 0;
    i1 = combinations[i][0];
    i2 = combinations[i][1];


    int new_list[size];
    char new_string_vector[size][100] ;

    if(i+1 <= (size+1)*(size) - 1)
    find_expression(size,curr_list,i+1,value,curr_string_vector,ans,1,combinations);

    generate_new_list(curr_list, curr_string_vector, size, i1, i2, 0, new_list, new_string_vector, 0,0,0);
    find_expression(size-1,new_list,0,value,new_string_vector,ans,0,combinations);

    if(curr_list[i2] > 0 && curr_list[i1]%curr_list[i2] == 0)
    {
    generate_new_list(curr_list, curr_string_vector, size, i1, i2, 1, new_list, new_string_vector, 0,0,0);
    find_expression(size-1,new_list,0,value,new_string_vector,ans,0,combinations);
    }
    generate_new_list(curr_list, curr_string_vector, size, i1, i2, 2, new_list, new_string_vector, 0,0,0);
    find_expression(size-1,new_list,0,value,new_string_vector,ans,0,combinations);

    generate_new_list(curr_list, curr_string_vector, size, i1, i2, 3, new_list, new_string_vector, 0,0,0);
    find_expression(size-1,new_list,0,value,new_string_vector,ans,0,combinations);

    return;
}


int main ()
{
    char ans[100] = "Nao foi possivel formar o valor alvo";
    int size;
    int value;

    scanf("%d", &size);
    scanf("%d", &value);

    int list[size];
    char string_vector[size][100];
    int combinations[size*(size-1)][2];

    for(int i = 0 ; i < size; i++)
    {
        scanf("%d", &list[i]);
    }
    for(int i = 0; i < size; i++)
    {
        sprintf(string_vector[i], "%d", list[i]);
    }
    
    find_expression(size - 1,list,0,value,string_vector,ans,0,combinations);
    printf("%s\n", ans);
}