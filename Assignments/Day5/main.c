/*
 * creation
 * display
 * linear search
 * binary search
 * insertion
 * deletion by given position
 * deletion by given item
 * */

#include <stdio.h>
void display(int* arr, int length) {
  int i=0;
  printf("[");
  for(; i<length-1; i++)
    printf("%d, ", *(arr+i));
  printf("%d]\n", *(arr+i));
  printf("length of the array is %d\n\n",length);
}
void insertion(int elem, int* arr, int* length, int index, int N) {
  if(*length == N) {
    printf("Overflow Situation, Insertion failed\n");
    return;
  }
  if(index < 0 || index > *length) { 
    printf("Invalid Index\nKindly enter an index in the range [0, length)\n");
    return;
  } 
  *length = *length + 1;
  for(int i=*length-1; i>index; i--) 
    *(arr+i) = *(arr+(i-1));
  *(arr+index) = elem;
  printf("Insertion was Successful\n\n");
}
void deletion1(int index, int* arr, int* length) {
  //deletion by position
  if(*length-1<0) {
    printf("Underflow Situation, Deletion not possible\n");
    return;
  }
  if(index<0 || index>=*length) {
    printf("Invalid Index\nKindly enter an index in the range [0, length)\n");
    return;
  }
  for(int i=index; i<*length-1; i++) 
    *(arr+i) = *(arr+(i+1));
  *length = *length - 1;
  printf("Deletion was successful\n\n");
}
void deletion2(int elem, int* arr, int* length) {
  for(int i=0; i<*length; i++) 
    if(*(arr+i)==elem) {
      deletion1(i, arr, length);
      *length--;
    }
}
void linear_search(int elem, int* arr, int length) {
  int i=0;
  for(; i<length; i++)
    if(*(arr+i)==elem) {
      printf("Element found at index %d\n\n", i);
      return;
    }
  printf("Element not found inside the array\n\n");
}
int is_sorted(int* arr, int length) {
  for(int i=0; i<length-1; i++)  
    if(*(arr+i) > *(arr+(i+1)))
      return 0;
  
  return 1;
}
void binary_search(int elem, int* arr, int length, int start, int end) {
  if(!is_sorted(arr, length)) {
    printf("The Array is unsorted\nCan not perform Binary Search\n\n");
    return;
  }
  if(start>end) {
    printf("Element not found in the array\n\n");
    return;
  }
  int mid = (start+end)/2;
  if(*(arr+mid)==elem) {
    printf("Element found at index %d\n\n",mid);
    return;
  }
  else {
    if(*(arr+mid) < elem) binary_search(elem, arr, length, mid+1, end);
    else binary_search(elem, arr, length, start, mid-1);
  }
}
int main() {
  int N, flag=1, length=0;
  printf("Enter the size of the array : ");
  scanf("%d", &N);
  int arr[N]; //creating an array of static size N
  int arr_[N]; //creating a necessary copy placeholder for call by referrence
  do {
    int choice;
    printf("************** MENU ****************\n");
    printf("Enter 1. for insertion\n");
    printf("Enter 2. for deletion by given position\n");
    printf("Enter 3. for deletion by given item\n");
    printf("Enter 4. for linear search\n");
    printf("Enter 5. for binary search\n");
    printf("Enter 6. for display\n");
    printf("Enter anything else to exit MENU\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    while(getchar()!='\n');
    switch(choice) {
      case 1 : {
        /*insertion*/;
        int elem, index;
        printf("Enter the element to enter : ");
        scanf("%d", &elem);
        printf("Enter the index where the element should be entered : ");
        scanf("%d", &index);
        insertion(elem, arr, &length, index, N);
        break;
      }
      case 2 : {
        /*deletion by given position*/
        int index;
        printf("Enter the index of deletion : ");
        scanf("%d", &index);
        deletion1(index, arr, &length);
        break;
      }
      case 3 : {
        /*deletion by given item*/
        int elem;
        printf("Enter the element to be deleted : ");
        scanf("%d", &elem);
        deletion2(elem, arr, &length);
        break;
      }
      case 4 : {
        /*linear search*/
        int elem;
        printf("enter the element to search : ");
        scanf("%d", &elem);
        linear_search(elem, arr, length);
        break;
      }
      case 5 : {
        /*binary search*/
        int elem;
        printf("enter the element to search : ");
        scanf("%d", &elem);
        binary_search(elem, arr, length, 0, N);
        break;
      }
      case 6 : {
        /*display*/
        display(arr, length);
        break;
      }
      default : {
        /*exit panel*/
        flag = 0;
        printf("Exit from MENU\nHave a nice day\n");
      }
    } 
  } while(flag!=0);
  return 0;
}
