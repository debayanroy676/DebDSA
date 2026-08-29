#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _USE_MATH_DEFINES

void drawCircle(); void drawRectangle(); 
void drawTriangle(); void shapeSelectorMenu(); 
void operationMenu(); void mainMenu();



void drawCircle(int scale, int angle) {
    cleardevice();
    int radius=100, x=350, y=250, x_=0, y_=0, x_rot, y_rot;
    if(angle!=0 && scale==1) {
        printf("Enter the referrence point coordinates\n");
        printf("X' = "); scanf("%d", &x_);
        printf("Y' = "); scanf("%d", &y_);
        x = x - x_;
        y = y - y_;
    }
    x_rot = x*cos(angle) + y*sin(angle);
    y_rot = -x*sin(angle) + y*cos(angle);
    x = x_rot + x_;
    y = y_rot + y_;
    circle(x, y, radius*scale);
    getch();
}

void drawRectangle(int scale, float angle) {
    cleardevice();
    int x1 = 350, y1 = 100, x2 = 100, y2 = 100, x3 = 100, y3 = 70, x4 = 350, y4 = 70;
    int x_ = 0, y_ = 0;
    int x1_rot, y1_rot, x2_rot, y2_rot, x3_rot, y3_rot, x4_rot, y4_rot;
    if(angle!=0) {
        // REFERRENCE COORDINATES (ARBITRARY)
        x_ = 100, y_ = 70;
        x1 = x1 - x_; y1 = y1 - y_;
        x2 = x2 - x_; y2 = y2 - y_;
        x3 = x3 - x_; y3 = y3 - y_;
        x4 = x4 - x_; y4 = y4 - y_;

        x1_rot = x1*cos(angle) + y1*sin(angle); y1_rot = -x1*sin(angle) + y1*cos(angle);
        x2_rot = x2*cos(angle) + y2*sin(angle); y2_rot = -x2*sin(angle) + y2*cos(angle);
        x3_rot = x3*cos(angle) + y3*sin(angle); y3_rot = -x3*sin(angle) + y3*cos(angle);
        x4_rot = x4*cos(angle) + y4*sin(angle); y4_rot = -x4*sin(angle) + y4*cos(angle);
        
        
        x1 = x1_rot + x_; y1 = y1_rot + y_;
        x2 = x2_rot + x_; y2 = y2_rot + y_;
        x3 = x3_rot + x_; y3 = y3_rot + y_;
        x4 = x4_rot + x_; y4 = y4_rot + y_;
    }
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);
    //rectangle(x1, y1, (x2*scale)+300 ,(y2*scale)+300);
    getch();
}

void drawTriangle(int scale, float angle) {
    cleardevice();
    scale = scale -1;
    int x1 = 200, y1 = 200, x2 = 300, y2 = 200, x3 = 300, y3 = 100, x_ = 0, y_ = 0;
    if(angle!=0) {
        x_ = 300, y_ = 100;

        x1 = x1 - x_; y1 = y1 - y_;
        x2 = x2 - x_; y2 = y2 - y_;
        x3 = x3 - x_; y3 = y3 - y_;

        x1 = x1*cos(angle) + y1*sin(angle) + x_; y1 = -x1*sin(angle) + y1*cos(angle) + y_;
        x2 = x2*cos(angle) + y2*sin(angle) + x_; y2 = -x2*sin(angle) + y2*cos(angle) + y_;
        x3 = x3*cos(angle) + y3*sin(angle) + x_; y1 = -x3*sin(angle) + y3*cos(angle) + y_;
    }
    line(x1, y1, x2+(scale*50), y2);
    line(x2+(scale*50), y2, x3+(scale*50), y3+(scale*50));
    line(x3+(scale*50), y3+(scale*50), x1, y1);
    getch();
}

void operationMenu(int choice) {
    int choice_, f=1;
    const float PI = 3.1415;
    float angle;
    do {
        printf("************* OPERATIONS MENU *************\n");
        printf("Enter 1 for translation\n");
        printf("Enter 2 for rotation\n");
        printf("Enter 3 for scaling\n");
        printf("Enter 4 for exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice_);
        switch(choice_) {
            case 1:
                shapeSelectorMenu();
                break;
            case 2: {
                printf("Enter the rotation angle : ");
                scanf("%f", &angle);
                angle = PI*angle/180;
                switch(choice) {
                    case 1 : drawCircle(f, angle); break;
                    case 2 : drawRectangle(f, angle); break;
                    case 3 : drawTriangle(f, angle); break;
                }
                break;
            }
            case 3: {
                printf("Enter the scaling Factor : ");
                scanf("%d", &f);
                switch(choice) {
                    case 1 : drawCircle(f, angle); break;
                    case 2 : drawRectangle(f, angle); break;
                    case 3 : drawTriangle(f, angle); break;
                }
                break;
            } 
            case 4:
                printf("Exit Operation Menu !\n");
                shapeSelectorMenu();
                break;
            default:
                printf("Invalid Input\n"); 
        }
    } while(choice_ != 4);
}


void shapeSelectorMenu() {
    int choice;
    do {
        printf("************* SHAPE SELECTOR MENU ***************\n");
        printf("Enter 1 for Circle\n");
        printf("Enter 2 for Rectangle\n");
        printf("Enter 3 for Triangle\n");
        printf("Enter 4 for exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1 :
                drawCircle(1, 0);
                operationMenu(choice);
                break;
            case 2 :
                drawRectangle(1, 0);
                operationMenu(choice);
                break;
            case 3 :
                drawTriangle(1, 0);
                operationMenu(choice);
                break;
            case 4 :
                printf("Exit Shape Selector Menu!\n");
                closegraph();
                mainMenu();
                break;
            default :
                printf("Invalid Input\n");
        }
    } while(choice != 4);
}

void mainMenu() {
    int choice;
    do {
        printf("************* MAIN MENU ***************\n");
        printf("Select 1 for starting the program\n");
        printf("Select 0 for exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 0 :
                abort();
                break;
            case 1 :
                shapeSelectorMenu();
                break;
            default :
                printf("Invalid Input\n");
        }
    } while (choice != 0);
}
int main() { 
    int gd=DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    mainMenu();
    closegraph();
    return 0;
}