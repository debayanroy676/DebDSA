/*
 * fibo_1.c
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
void fibo_for(int n) {
	if(n<1) {
		printf("Please Enter a Series Limit >= 1\n");
		return;
	}
	printf("*** Printing Fibo using for loop ***\n");
	int i, sum=0, a=0, b=1;
	for(i=1; i<n; i++) {
		printf("%d, ",a);
		sum = a+b;
		a=b;
		b=sum;
	}
	sum = a+b;
	printf("%d.\n",a);
}

void fibo_while(int n) {
	if(n<1) {
		printf("Please Enter a Series Limit >= 1\n");
		return;
	}
	printf("*** Printing Fibo using for loop ***\n");
	int a=0, b=1, sum, i=1;
	while(i<n) {
		printf("%d, ",a);
		sum = a+b;
		a=b;
		b=sum;
		i++;
	}
	printf("%d.\n",a);
}

void fibo_do_while(int n) {
	if(n<1) {
		printf("Please Enter a Series Limit >= 1\n");
		return;
	}
	printf("*** Printing Fibo using do-while loop ***\n");
	int a=0, b=1, sum, i=1;
	do {
		printf("%d, ",a);
		sum = a+b;
		a=b;
		b=sum;
		i++;
	} while(i<n);
	printf("%d.\n",a);
}

int main()
{
	int n;
	printf("Enter the series limit : ");
	scanf("%d", &n);
	fibo_for(n);
	fibo_while(n);
	fibo_do_while(n);
	return 0;
}

