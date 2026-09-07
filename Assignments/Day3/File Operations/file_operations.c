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
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        switch (choice) {
            case 1: {
                fp = fopen("assets/asset.txt", "r");
                while(fgets(refer, 1000, fp) != NULL) 
                    printf("[READ]  %s", refer);
                fclose(fp);
                break;
            }
            case 2: { 
                fp = fopen("assets/asset.txt", "a");
                fprintf(fp, "[WRITE]  ");
                printf("Enter your write : ");
                fflush(stdin);
                fgets(refer, 1000, stdin);
                fprintf(fp, refer);
                fclose(fp);
                break;
            }
            case 3: {
                bin = fopen("assets/asset.bin", "rb");
                int ch;
                printf("[READ]  ");
                while((ch = fgetc(bin))!=EOF) {
                    printf("%c", (char)ch);
                    if((char)ch=='\n')  printf("[READ]  ");
                    else continue;
                }
                fclose(bin);
                break;
            }
            case 4 : {
                bin = fopen("assets/asset.bin", "ab+");
                printf("Enter your write : ");
                fflush(stdin);
                struct nameholder {
                    char name[50];
                };
                struct nameholder myname;
                fgets(myname.name, 50, stdin);
                fflush(stdin);
                fwrite(myname.name, sizeof(char), 50, bin);
                fclose(bin);
                break;
            }
            case 5: {
                printf("Exit Successfully");
                break;
            }
            default: {
                printf("Invalid Input\n");
            }
        }
    } while(choice!=5);
    
    return 0;
}
