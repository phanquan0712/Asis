#include<stdio.h>
#include<string.h>

struct Student {
    char maSV[50], ho_ten[50], nam_sinh[50];
};
typedef struct Student SV;

void saveInforListStudentToFile(SV listStudent[], int n) {
    FILE* fp = fopen("List_SV.c", "wb");
    fwrite(&n, sizeof(n), 1, fp);
    for(int i = 0; i < n; i++) {
        fwrite(&listStudent[i], sizeof(SV), 1, fp);
    }
    fclose(fp);
}

SV enterInforStudent() {
    SV a;
    printf("Nhap ma SV: "); fflush(stdin); gets(a.maSV);
    printf("Nhap ho ten: "); fflush(stdin); gets(a.ho_ten);
    printf("Nhap nam sinh: "); fflush(stdin); gets(a.nam_sinh);
    return a;
}

void createListStudent(SV listStudent[]) {
    int n;
    printf("Nhap so luong sinh vien: "); scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("------------------Nhap vao thong tin sinh vien thu %d------------------\n", i + 1);
        listStudent[i] = enterInforStudent();
    }
    saveInforListStudentToFile(listStudent, n);
}

int readInforListStudentFromFile(SV listStudent[]) {
    FILE* fp = fopen("List_SV.c", "rb");
    int n;
    fread(&n, sizeof(n), 1, fp);
    for(int i = 0; i < n; i++) {
        fread(&listStudent[i], sizeof(SV), 1, fp);
    }
    fclose(fp);
    return n;
}

void printListStudent(SV listStudent[]) {
    int n = readInforListStudentFromFile(listStudent);
    printf("---------DANH SACH SINH VIEN---------\n");
    printf("%5s %35s %20s %20s\n", "STT", "Ma SV", "Ho ten", "Nam sinh");
    for(int i = 0; i < n; i++) {
        printf("%5d %35s %20s %20s\n", i + 1, listStudent[i].maSV, listStudent[i].ho_ten, listStudent[i].nam_sinh);
    }
}


void editInforStudentBySBD(SV listStudent[]) {
    char editMaSv[50];
    printf("Nhap ma SV can sua: ");  fflush(stdin); gets(editMaSv);
    int n = readInforListStudentFromFile(listStudent);
    for(int i = 0; i < n; i++) {
        if(strcmp(editMaSv, listStudent[i].maSV) == 0) {
            printf("Nhap vao thong tin moi cua sinh vien: \n");
            listStudent[i] = enterInforStudent();
        }
    }
    saveInforListStudentToFile(listStudent, n);
    printListStudent(listStudent);
}

int main() {
    SV listStudent[100];
    while(1) {
        printf("-------------------MENU-------------------\n");
        printf("1. Tao danh sach sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Sua thong tin sinh vien theo ma sinh vien\n");
        printf("4. Ket thuc\n");
        printf("--------------------------------------------\n");
        int choose;
        printf("Nhap lua chon: "); scanf("%d", &choose);
        switch(choose) {
            case 1: 
                createListStudent(listStudent);
                break;
            case 2:
                printListStudent(listStudent);
                break;
            case 3:
                editInforStudentBySBD(listStudent);
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}