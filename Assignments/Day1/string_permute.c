/* This code is still incomplete, figuring out next steps
would like NO HELP HERE, i trust that i have a brain */





#include <stdio.h>
#include <string.h>
void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(int left, int i, char str[100]) {
    /*printf("[DEBUG]  %d    %d     length=%d\n", left, i, strlen(str));*/
    if(i>=strlen(str) && left!=strlen(str)) permute(left+1, left+1, str);
    else if(left>=strlen(str) && i>=strlen(str)) return;
    else {
        swap(&str[left], &str[i]);
        printf("left = %d,   i = %d  ---------> %s\n", left, i, str);
        /*swap(&str[left], &str[i]);*/
        permute(left, i+1, str);
    }
}
int main() {
    char str[100];
    printf("Enter your String : ");
    fgets(str, 100, stdin);
    if(str[strlen(str)-1] == '\n')
        str[strlen(str)-1] = '\0';
    /*printf("%s, length = %d\n", str, strlen(str));*/
    permute(0, 0, str);
    return 0;
}