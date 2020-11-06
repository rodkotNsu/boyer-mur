#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <locale.h>
#include<string.h>
#include<malloc.h>
#include <stdbool.h>
#define SIZE_OF_BLOCK 100
typedef   unsigned long long big_int;
 
bool is_matching(char* str, char* template, int len) {
    if (str == NULL || template == NULL || strlen(str) == strlen(template)) return false;
    for (int i = 0; i < len; i++) {
        if (str[i] != template[i])
            return false;

    }
    return true;
}

 
int main()
{
    setlocale(LC_ALL, "Russian");

    
     
   unsigned  char line[SIZE_OF_BLOCK] = { 0 };
   unsigned  char temp[SIZE_OF_BLOCK] = { 0 };


    FILE* file = fopen("file.txt", "r");

    fgets(temp, SIZE_OF_BLOCK, file);
    int len_temp = strlen(temp) - 1;
    unsigned int alf[256] ;
    for (int i = 0; i < 256; i++)
        alf[i] = len_temp;
    for (int i = len_temp; i > 1; i--) {
        if (alf[ temp[len_temp - i]] == len_temp){
            alf[temp[len_temp - i]] = i-1;
        }
    }

    size_t f = fread(&line, sizeof(char), SIZE_OF_BLOCK, file);
    size_t i = 0;
    while (i <=f - len_temp) {
        if (temp[len_temp - 1] != line[i + len_temp - 1]) {
            i += alf[line[i + len_temp - 1]];
            continue;
        }
        else {
            size_t j = len_temp-1;
            while (j>0 && temp[j]==line[i + j])

            {
                printf("%d ", i + j);
                j--;

            }
           
            i += alf[temp[len_temp - 1]];
            


        }





        
 }
     
   
    fclose(file);
    return 0;
}