#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* ptr;
    ptr = fopen("Input.txt", "r");
    char ch;
    do{
        ch = fgetc(ptr);
        printf("%c\n", ch);
    }while(ch != EOF);

    return 0;
}