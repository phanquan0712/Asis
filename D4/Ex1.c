#include<stdio.h>

int main() {
    int n; printf("Nhap so luong day so nguyen: "); scanf("%d", &n);
    int a[n];
    printf("Nhap day so: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int count = 0;
    int sum  = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 ==0 && a[i] > 5) {
            count++;
            sum += a[i];
        }
    }
    count > 0 ?  printf("Trung binh cong: %.2f", (float)sum / count) :  printf("Khong co so nguyen nao trong day tren thoa man dieu kien!");
    return 0;
}