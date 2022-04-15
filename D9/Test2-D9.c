#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
    char ID[50], ho_ten[50], chuc_vu[50], so_dien_thoai[50];
};
typedef struct Employee Employee;

struct Node {
    Employee data;
    struct Node *next;
};
typedef struct Node* node;

node makeNode() {
    Employee ep1;
    printf("Nhap vao ID: "); fflush(stdin); gets(ep1.ID);
    printf("Nhap vao ho ten: "); fflush(stdin); gets(ep1.ho_ten);
    printf("Nhap vao chuc vu: "); fflush(stdin); gets(ep1.chuc_vu);
    printf("Nhap vao so dien thoai: "); fflush(stdin); gets(ep1.so_dien_thoai);
    node tmp = (node)malloc(sizeof(struct Node));
    tmp->data = ep1;
    tmp->next = NULL;
    return tmp;
}

node insertLast(node head) {
    node tmp = makeNode();
    if(head == NULL) {
        head = tmp;
    }
    else {
        node p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
    return head;
}

node creaetListEmployee(node head) {
    int n;
    printf("Nhap vao so luong nhan vien: "); scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("---------Nhap vao thong tin nhan vien thu %d--------------\n", i + 1);
        head = insertLast(head);
    }
    return head;
}

void printListStudent(node head) {
    node p = head;
    printf("-----------------Danh sach nhan vien-----------------\n");
    printf("%5s %35s %20s %20s\n", "ID", "Ho ten", "Chuc vu", "So dien thoai");
    while(p != NULL) {
        printf("%s %35s %20s %20s\n",p->data.ID, p->data.ho_ten, p->data.chuc_vu, p->data.so_dien_thoai);
        p = p->next;
    }
}

node deleteEmployee(node head) {
    char ID[50];
    printf("Nhap vao ID nhan vien can xoa: "); fflush(stdin); gets(ID);
    node prev = NULL, next = head;
    while(next != NULL) {
        if(strcmp(next->data.ID, ID) == 0) {
            if(prev == NULL) {
                head = next->next;
            }
            else {
                prev->next = next->next;
            }
        }
        prev = next;
        next = next->next;
    }
    return head;
}

int main() {
    node head = NULL;
    while(1) {
        printf("-----------------MENU-----------------\n");
        printf("1. Tao danh sach nhan vien\n");
        printf("2. Hien thi danh sach nhan vien\n");
        printf("3. Xoa nhan vien\n");
        printf("4. Ket thuc\n");
        printf("--------------------------------------\n");
        int choose;
        printf("Nhap vao lua chon: "); scanf("%d", &choose);
        switch(choose) {
            case 1: 
                head = creaetListEmployee(head);
                break;
            case 2:
                printListStudent(head);
                break;
            case 3:
                head = deleteEmployee(head);
                printf("----------DANH SACH SAU KHI XOA----------\n");
                printListStudent(head);
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}
