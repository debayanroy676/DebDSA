/*/*
 * solution2.c
 * 
 * Copyright 2026 root <root@localhost>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <math.h>

int check_prime(int n) {
	int flag = 0, i;
	if(n<2) return flag;
	for(i=2; i<n; i++) {
		if(n%i==0) {
			flag = 1;
			break;
		}
		else
			continue;
	}
	return flag;
}

int find_max(int a, int b) {
	int diff = (a-b);
	diff = (diff<0)?-diff:diff;
	int max_int = (a+b+diff)/2;
	return max_int;
}

int menu() {
	int choice;
	printf("********* MENU **********\n");
	printf("Kindly choose one of the following options :\n");
	printf("1. Check for Prime Number\n");
	printf("2. Check for Armstrong Number\n");
	printf("3. Largest among 3 Numbers\n");
	printf("4. Exit\n");
	printf("Enter your choice : ");
	scanf("%d", &choice);
	switch(choice) {
		case 1: {
			int num, flag;
			printf("Enter your Number : ");
			scanf("%d", &num);
			flag = check_prime(num);
			if(flag != 1) 
				printf("%d is a Prime Number\n", num);
			else
				printf("%d is not a Prime Number\n", num);
			break;
		}
		case 2: {
			int num, sum=0, len, i;
			printf("Enter your number : ");
			scanf("%d", &num);
			if(num<=0) {
				printf("Kindly Enter a number > 0\n");
				break;
			}
			len = (int)log10(num) + 1;
			printf("%d\n", len);
			for(i=1; i<=len; i++) {
				sum = sum + (int) pow((num % (int)pow(10,i)/ (int)pow(10,i-1)), len);
				//printf("%d     %d\n", (num % (int)pow(10,i)/ (int)pow(10,i-1)), len);
				//printf("%d\n", sum);
			}
			if(num==sum)
				printf("%d is an Armstrong Number\n",num);
			else
				printf("%d is not an Armstrong Number\n",num);
			break;
		}
		case 3: {
			int a, b, c, max_int;
			printf("Enter the first number : ");
			scanf("%d", &a);
			printf("Enter the second number : ");
			scanf("%d", &b);
			printf("Enter the third number : ");
			scanf("%d", &c);
			max_int = find_max(find_max(a,b), c);
			printf("The Greatest Number = %d\n", max_int);
			break;
		}
		case 4 : {
			printf("Have a nice day\n");
			break;
		}
		default : 
			printf("Invalid Input\n");
	}
	return choice;
}

int main()
{
	while(menu()!=4);
	return 0;
}



