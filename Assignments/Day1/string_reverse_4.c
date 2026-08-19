/*
 * string_reverse_4.c
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
int len_(char *str) {
	int i=0, len = 0;
	while(*(str+ ++i)!='\n') 
		len++;
	return len;
}
int main()
{
	char str[100];
	printf("Enter your String : ");
	fgets(str, 100, stdin);
	int i, length = len_(str);
	char str_rev[length];
	for(i=0; i<=length; i++)
		*(str_rev+i) = *(str+(length-i));
	printf("The reversed String is \"%s\"\n",str_rev);
	return 0;
}

