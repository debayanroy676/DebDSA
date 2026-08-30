#include <stdio.h>
#include <string.h>
int main() {
    FILE *fp, *bin;
    char refer[1000], p;
    int choice, i;
    do {
        printf("\n*************** MENU ***************\n");
        printf("1. for reading a normal file\n");
        printf("2. for writing into a normal file\n");
        printf("3. for reading binary files\n");
        printf("4. for writing binary files\n");
        printf("5. for exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                fp = fopen("assets/asset.txt", "r");
                while(!feof(fp)) {
                    fgets(refer, 1000, fp);
                    printf("[READ]  %s", refer);
                }
                break;
            case 2: 
                fp = fopen("assets/asset.txt", "a");
                fprintf(fp, "[WRITE]  ");
                printf("Enter your write : ");
                fflush(stdin);
                fgets(refer, 1000, stdin);
                fprintf(fp, refer);
                break;
            case 3:
                bin = fopen("assets/asset.bin", "rb+");
                int ch;
                printf("[READ]  ");
                while((ch = fgetc(bin))!=EOF) {
                    printf("%c", (char)ch);
                    if((char)ch=='\n')  printf("[READ]  ");
                    else continue;
                }
                break;
            case 4 :
                i=0;
                bin = fopen("assets/asset.bin", "ab");
                printf("Enter your write : ");
                fgets(refer, 1000, stdin);
                char* write = refer;
                fwrite(write, sizeof(char), strlen(write), bin);
                break;
            case 5:
                printf("Exit Successfully");
                fclose(fp);
                fclose(bin);
                break;
            default:
                printf("Invalid Input\n");
        }
    } while(choice!=5);
    
    return 0;
}