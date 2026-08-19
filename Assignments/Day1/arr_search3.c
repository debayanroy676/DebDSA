#include <stdio.h>
void set() {
	
}
int search(int elem, int n, int *arr) {
	int i;
	for(i=0; i<n; i++)
		if(*(arr+i) == elem)
			return i;
		else
			continue;
	return -1;
}
int main() {
	int i, elem, n, index;
	printf("Enter the size of your array : ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the %d elements :\n", n);
	for(i=0; i<n; i++) {
		printf("Input %d >>> ",(i+1));
		scanf("%d", (arr+i));
	}
	printf("Enter the Element to search : ");
	scanf("%d", &elem);
	index = search(elem, n, arr+0);
	if(index==-1)
		printf("Element not found\n");
	else
		printf("Element %d found at index %d", elem, index);
	return 0;
}
