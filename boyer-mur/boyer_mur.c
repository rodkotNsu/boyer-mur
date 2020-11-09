    #define  _CRT_SECURE_NO_WARNINGS 
    #include <stdio.h>
   
    #include<string.h>
    #include<malloc.h>
 
    #define SIZE_OF_BLOCK 300

    void re_init_arr(char arr[SIZE_OF_BLOCK], int num) {
        for (int i = num; i < SIZE_OF_BLOCK; i++) {
            arr[i - num] = arr[i];
        }
    }
 
    int main()
    {
    
        char line[SIZE_OF_BLOCK];
         char temp[SIZE_OF_BLOCK];
       int alf[256] = { 0 };
       // FILE* file = fopen("file.txt", "r");
            FILE* file = stdin;

        if (!fgets(temp, SIZE_OF_BLOCK, file)) {}
        size_t len_temp = strlen(temp) - 1;

        for (int i = len_temp; i > 1; i--) {
            if (alf[ (unsigned char)temp[len_temp - i]] == 0){
                alf[(unsigned char)temp[len_temp - i]] = i-len_temp-1;
            }
        }
        size_t i = SIZE_OF_BLOCK;
        size_t h = 0;
        while (!feof(file))
        {
            size_t f = fread(&line[SIZE_OF_BLOCK-i], sizeof(char), i, file) ;
            f +=(SIZE_OF_BLOCK - i);
            if (f < len_temp)
                return 0;
            i = 0;
            while (i <= f-len_temp ) {
                if (temp[len_temp -1] != line[i + len_temp-1]) {
                    printf("%llu ", (unsigned long long )(h + i + len_temp));
                    i += (alf[(unsigned char)line[i + len_temp - 1]]+len_temp);
                    continue;
                }
                else {
                    size_t j = len_temp-1 ;
                    while (j >0 && temp[j] == line[i + j])
                    {
                        printf("%llu ", (unsigned long long)( h+i + j + 1));
                        j--;
                    }
                    printf("%llu ", (unsigned long long)(h + i + j + 1));
                    i += (alf[(unsigned char)temp[len_temp - 1]]+len_temp);
                }
            }
            re_init_arr(line, i );
           h+= i;
        }
        fclose(file);
        return 0;
    }
