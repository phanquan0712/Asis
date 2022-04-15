#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
    int n; 
    printf("Nhap vao so luong phan tu trong day so: "); scanf("%d", &n);
    int arr[n], cnt[n];
    memset(cnt, 0, sizeof(cnt));
    printf("Nhap vao day so: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        cnt[arr[i]]++;
    }
    int x; printf("Nhap vao so nguyen X: "); scanf("%d", &x);
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            printf("So %d xuat hien %d lan\n", x, cnt[x]);
            return 0;
        }
    }
    printf("Khong tim thay so %d trong day so\n", x);
    return 0;
}