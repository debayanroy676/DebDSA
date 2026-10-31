// DSA Assignment 6 
#include <stdio.h>
void display(int* arr, int N) {
	int i=0;
	printf("[");
	for(; i<N-1; i++)
		printf("%d, ", *(arr+i));
	printf("%d]\n", *(arr+i));
}
void copy(int* arr, int* arr_, int N) {
	for(int i=0; i<N; i++)
		*(arr_ + i) = *(arr + i);
}
void selection_sort(int* arr, int N) {
	for(int i=0; i<N-1; i++) {
		for(int j=i+1; j<N; j++) {
			if(*(arr+i)>*(arr+j)) {
				int temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp;
			}
		}
	}
	display(arr, N);
}
void bubble_sort1(int*arr, int N) {
	int i, j;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if(*(arr+i)>*(arr+j)) {
				int temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp;
			}
		}
	}
	display(arr, N);
}
void bubble_sort2(int*arr, int N) {
	int i, j;
	for(i=0; i<N; i++) {
		for(j=0; j<N-i; j++) {
			if(*(arr+i)>*(arr+j)) {
				int temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp;
			}
		}
	}
	display(arr, N);
}
void insertion_sort(int*arr, int N) {
	int p, i, j;
	for(i=1; i<N; i++) {
		p = *(arr+i);
		j = i-1;
		while(j>=0 && p<*(arr+j)) {
			*(arr+j+1) = *(arr+j);
			j--;
		}
		*(arr+j+1) = p;
	}
	display(arr, N);
}
int main() {
	int i, N, flag = 1;
	printf("Enter the length of the array : ");
	scanf("%d", &N);
	int arr[N]; //creation
	for(i=0; i<N; i++) { //insertion
		printf("Input %d >>> ", (i+1));
		scanf("%d", &arr[i]);
	}
	display(&arr[0], N);
	// Menu
	do {
		int ch;
		printf("*********** MENU *************\n");
		printf("1. for selection sort\n");
		printf("2. for bubble sort\n");
		printf("3. for insertion sort\n");
		printf("Any other selection will exit\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: {
				int arr_[N];
				copy(arr, arr_, N);
				selection_sort(arr_, N);
				break;
			}
			case 2: {
				int ch_;
				printf("*********** BUBBLE SORT ***********\n");
				printf("Select 1 for Traditional Bubble Sort\n");
				printf("Select 2 for improved Bubble Sort\n");
				printf("Enter any other number for exit\n");
				printf("Enter your choice : ");
				scanf("%d",&ch_);
				switch (ch_){
					case 1: {
						int arr_[N];
						copy(arr, arr_, N);
						bubble_sort1(arr_, N);
						break;
					}
					case 2: {
						int arr_[N];
						copy(arr, arr_, N);
						bubble_sort2(arr_, N);
						break;
					}
					default :
					printf("Exit for Bubble Sort Menu\n");
				}
			}
			case 3: {
				int arr_[N];
				copy(arr, arr_, N);
				insertion_sort(arr_, N);
				break;
			}
			default: {
				printf("Exiting Application");
				flag = 0;
			}	
		}
	} while(flag!=0);
	return 0;
}






