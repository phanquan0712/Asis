#include<stdio.h>
#include<stdlib.h>
#include<math.h>



// Cach1: Dung voi so n Lon
long long prime[1000001]; 
void sieve() {
    for(int i = 0; i <= 1000000; i++) {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i = 2; i <= 1000; i++) {
        if(prime[i] == 1) {
            for(int j = i * i; j <= 1000000; j += i) {
                prime[j] = 0;
            }
        }
    }
}

//! Cach2: Dung voi so n nho va vua
int isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return n > 1 ? 1 : 0;
}

int main() {
    int n, count = 0;
    printf("Nhap vao so nguyen duong: "); scanf("%d", &n);
    printf("Cac so nguyen to nho hon %d la: ", n);
    // Cach1 - MAIN
    // sieve();
    // for(int i = 0 ; i < n; i++) {
    //     if(prime[i] == 1) {
    //         count++;
    //         printf("%d ", i);
    //     }
    // }
    // printf("va co %d so nguyen to nho hon %d", count, n);

    // Cach2 - MAIN
    for(int i = 0 ; i < n; i++) {
        if(isPrime(i) == 1) {
            count++;
            printf("%d ", i);
        }
    }
    printf("va co %d so nguyen to nho hon %d", count, n);
    return 0;
}