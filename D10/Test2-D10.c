#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void enterTwoArray(int arr1[], int arr2[], int *n, int *m) {
    int n1, m1;
    printf("Nhap vao so phan tu cua day so 1: "); scanf("%d", &n1); *n = n1;
    printf("Nhap vao day so 1: ");
    for(int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("\n");
    printf("Nhap vao so phan tu cua day so 2: "); scanf("%d", &m1); *m = m1;
    printf("Nhap vao day so 2: ");
    for(int i = 0; i < m1; i++) {
        scanf("%d", &arr2[i]);
    }
}


void concatTwoArray(int arr1[], int arr2[], int arr3[], int n, int m) {
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) {
            arr3[i + j] = arr1[i]; i++;
        }
        else {
            arr3[i + j] = arr2[j]; j++;
        }
    }
    while(i < n) {
        arr3[i + j] = arr1[i]; i++;
    }
    while(j < m) {
        arr3[i + j] = arr2[j]; j++;
    }
}

void printThreeArray(int arr1[], int arr2[], int arr3[], int n, int m) {
    printf("Day so 1: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nDay so 2: ");
    for(int i = 0; i < m; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\nDay so 3: ");
    for(int i = 0; i < n + m; i++) {
        printf("%d ", arr3[i]);
    }
}

int main() {
    int n, m;
    int arr1[50], arr2[50], arr3[100];
    while(1) {
        printf("-------------------MENU-------------------\n");
        printf("1. Nhap vao 2 day so\n");
        printf("2. Ghep hai day so\n");
        printf("3. In 3 day so\n");
        printf("4. Thoat\n");
        int choose;
        printf("Nhap vao lua chon: "); scanf("%d", &choose);
        switch(choose) {
            case 1: 
                enterTwoArray(arr1, arr2, &n, &m);
                break;
            case 2:
                concatTwoArray(arr1, arr2, arr3, n, m);
                break;
            case 3:
                printThreeArray(arr1, arr2, arr3, n, m);
                break;
            case 4:
                return 0;
            default: 
                printf("Lua chon khong hop le!\n");
        }
    }
    return 0;
}