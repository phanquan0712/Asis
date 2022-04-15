#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    char so_bao_danh[50], ho_ten[50];
    float diem_toan, diem_ly, diem_tieng_anh, tong_diem;
};
typedef struct Student STUDENT;

struct Node {
    STUDENT data;
    struct Node *next;
};
typedef struct Node* node;

node makeNode() {
    STUDENT s1;
    printf("Nhap vao so bao danh: "); fflush(stdin); gets(s1.so_bao_danh);
    printf("Nhap vao ho ten: "); fflush(stdin); gets(s1.ho_ten);
    printf("Nhap vao diem toan: "); scanf("%f", &s1.diem_toan);
    printf("Nhap vao diem ly: "); scanf("%f", &s1.diem_ly);
    printf("Nhap vao diem tieng anh: "); scanf("%f", &s1.diem_tieng_anh);
    s1.tong_diem = s1.diem_toan + s1.diem_ly + s1.diem_tieng_anh;
    node p = (node)malloc(sizeof(struct Node));
    p->data = s1;
    p->next = NULL;
    return p;
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


node createListStudent(node head) {
    int n;
    printf("Nhap vao so luong thi sinh: "); scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Nhap vao thong tin thi sinh thu %d: \n", i + 1);
        head = insertLast(head);
    }
    return head;
}

void printListStudent(node head) {
    node p = head;
    printf("%s %20s %30s %20s %20s %30s %20s\n", "STT", "SBD", "Ho ten", "Diem toan", "Diem ly", "Diem tieng anh", "Tong diem");
    int STT  = 1;
    while(p != NULL) {
        printf("%3d %20s %30s %20.2f %20.2f %30.2f %20.2f\n", STT, p->data.so_bao_danh, p->data.ho_ten, p->data.diem_toan, p->data.diem_ly, p->data.diem_tieng_anh, p->data.tong_diem);
        STT++;
        p = p->next;
    }
    printf("\n");
}

node arrangeByDiemToan(node head) {
    for(node a = head; a != NULL; a = a->next)
    {
        for(node b = a->next; b != NULL; b = b->next)
        {
            if(a->data.diem_toan > b->data.diem_toan)
            {
                STUDENT tmp = a->data;
                a->data = b->data;
                b->data = tmp;
            }
        }
    }
    return head;
}

node arrangeByDiemLy(node head) {
    for(node a = head; a != NULL; a = a->next)
    {
        for(node b = a->next; b != NULL; b = b->next)
        {
            if(a->data.diem_ly > b->data.diem_ly)
            {
                STUDENT tmp = a->data;
                a->data = b->data;
                b->data = tmp;
            }
        }
    }
    return head;
}

node arrangeByDiemTiengAnh(node head) {
    for(node a = head; a != NULL; a = a->next)
    {
        for(node b = a->next; b != NULL; b = b->next)
        {
            if(a->data.diem_tieng_anh > b->data.diem_tieng_anh)
            {
                STUDENT tmp = a->data;
                a->data = b->data;
                b->data = tmp;
            }
        }
    }
    return head;
}

node arrangeByDiemTongDiem(node head) {
    for(node a = head; a != NULL; a = a->next)
    {
        for(node b = a->next; b != NULL; b = b->next)
        {
            if(a->data.tong_diem > b->data.tong_diem)
            {
                STUDENT tmp = a->data;
                a->data = b->data;
                b->data = tmp;
            }
        }
    }
    return head;
}

// edit Student by SBD
node editStudentBySBD(node head) {
    char sbd[50];
    printf("Nhap vao so bao danh can sua: "); fflush(stdin); gets(sbd);
    node p = head;
    while(p != NULL) {
        if(strcmp(p->data.so_bao_danh, sbd) == 0) {
            printf("Nhap vao ho ten moi: "); fflush(stdin); gets(p->data.ho_ten);
            printf("Nhap vao diem toan moi: "); scanf("%f", &p->data.diem_toan);
            printf("Nhap vao diem ly moi: "); scanf("%f", &p->data.diem_ly);
            printf("Nhap vao diem tieng anh moi: "); scanf("%f", &p->data.diem_tieng_anh);
            p->data.tong_diem = p->data.diem_toan + p->data.diem_ly + p->data.diem_tieng_anh;
            break;
        }
        p = p->next;
    }
    return head;
}

// delete Student by SBD 
node deleteStudentBySBD(node head) {
    char sbd[50];
    printf("Nhap vao so bao danh can xoa: "); fflush(stdin); gets(sbd);
    node p = head;
    while(p != NULL) {
        if(strcmp(p->data.so_bao_danh, sbd) == 0) {
            if(p == head) {
                head = p->next;
            }
            else {
                node q = head;
                while(q->next != p) {
                    q = q->next;
                }
                q->next = p->next;
            }
            free(p);
            break;
        }
        p = p->next;
    }
    return head;
}

int main() {
    node head = NULL;
    while(1) {
        Quan:
        printf("--------------------MENU--------------------\n");
        printf("1. Tao danh sach thi sinh\n");
        printf("2. Hien thi danh sach thi sinh\n");
        printf("3. Sap xep diem thi\n");
        printf("4. Sua thong tin thi sinh(SBD)\n");
        printf("5. Xoa thi sinh(SBD)\n");
        printf("6. Ket thuc\n");
        printf("---------------------------------------------\n");
        int choose;
        printf("Nhap vao lua chon: "); scanf("%d", &choose);
        switch(choose) {
            case 1 :
                head = createListStudent(head);
                break;
            case 2 :
                printf("--------------DANH SACH THI SINH----------------\n");
                printListStudent(head);
                printf("-----------------------------------------------\n");
                break;
            case 3 :
                while(1) {
                printf("-----------SAP XEP HOC SINH----------------\n");
                printf("1. Sap xep theo diem toan\n");
                printf("2. Sap xep theo diem ly\n");
                printf("3. Sap xep theo diem tieng anh\n");
                printf("4. Sap xep theo tong diem\n");
                printf("5. Quay lai\n");
                printf("6. Ket thuc\n");
                printf("---------------------------------------------\n");
                int choose1;
                printf("Nhap vao lua chon: "); scanf("%d", &choose1);
                switch(choose1) {
                    case 1 :
                        head = arrangeByDiemToan(head);
                        printf("--------------DANH SACH THI SINH SAP XEP THEO DIEM TOAN----------------\n");
                        printListStudent(head);
                        printf("-----------------------------------------------------------------------\n");
                        break;
                    case 2 :
                        head = arrangeByDiemLy(head);
                        printf("--------------DANH SACH THI SINH SAP XEP THEO DIEM LY----------------\n");
                        printListStudent(head);
                        printf("-----------------------------------------------------------------------\n");
                        break;
                    case 3 :
                        head = arrangeByDiemTiengAnh(head);
                        printf("--------------DANH SACH THI SINH SAP XEP THEO DIEM TIENG ANH----------------\n");
                        printListStudent(head);
                        printf("-----------------------------------------------------------------------\n");
                        break;
                    case 4 :
                        head = arrangeByDiemTongDiem(head);
                        printf("--------------DANH SACH THI SINH SAP XEP THEO DIEM TONG DIEM----------------\n");
                        printListStudent(head);
                        printf("-----------------------------------------------------------------------\n");
                        break;
                    case 5 :
                        goto Quan;
                        break;
                    case 6 :
                        return 0;
                }
                }
            case 4: 
                head = editStudentBySBD(head);
                printf("--------------DANH SACH THI SINH SAU KHI SUA----------------\n");
                printListStudent(head);
                break;
            case 5: 
                head = deleteStudentBySBD(head);
                printf("--------------DANH SACH THI SINH SAU KHI XOA----------------\n");
                printListStudent(head);
                break;
            case 6 :
                return 0;
            default :
                printf("Lua chon khong hop le!\n");
                break;
        }
    }
    return 0;
}