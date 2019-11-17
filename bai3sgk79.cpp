#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct sinhvien
{
    char mssv[10];
	char ten[40];
	float tb;   
};
 
 
struct Datasinhvien 
{
	sinhvien data;
	struct Datasinhvien *next;
};
typedef struct Datasinhvien *list;


list khoitao(list head)
{
	head = NULL;
	return head;
}


list CreateSV(sinhvien sv){
	//cap phat 1 sv 
    list temp = new Datasinhvien;
//    temp = (list)malloc(sizeof(struct Datasinhvien)); //malloc cap phat vung nho
    temp->next = NULL;
    temp->data = sv; 
    return temp;
    
}


list themcuoi(list &head, sinhvien sv){
    list a;
    list temp = CreateSV(sv);
    if(head == NULL){
        head = temp;     
    }
    else{
        a  = head;
        while(a->next != NULL){
            a = a->next;
        }
        a->next = temp;
    }
    return head;
}


void nhap(sinhvien &sv)
{
		
	fflush(stdin);
	printf("nhap mssv: ");
	gets(sv.mssv);
	
	fflush(stdin);	
	printf("nhap ho ten: ");
	gets(sv.ten);
	
	fflush(stdin);
	printf("\nnhap diem tb: ");
	scanf("%f",&sv.tb);
	
}


list nhapsv(list &head)
{
	sinhvien sv;
	int n;
	printf("\nnhap SL:");
	scanf("%d",&n);
	
	for (int i=0;i<n;i++)
	{
	printf("\nnhap sv thu %d\n",i);
	nhap(sv);
	head = themcuoi(head, sv);
	}
	
	
}


void xuatsv(sinhvien sv)
{
	printf("\n");
	printf("thong tin sv la: \n");
	printf("mssv la: ");
	puts(sv.mssv);
	printf("ho ten la: ");
	puts(sv.ten);
}

void xuat(list head){
    printf("\n");
    for(list a = head; a != NULL; a = a->next){
        printf("%5d", a->data);
    }
}
 



//
//void xuatsvdtblonhon5(Datasinhvien head)
//{
//	for(Datasinhvien i = head; i != NULL; i = i->next)
//	{
//		if(sv.tb > 5)
//		{
//			printf("\nmssv la: ");
//			puts(sv.mssv);
//			printf("\nho ten la: ");
//			puts(sv.ten);
//			printf("\ndtb la: %f",sv.tb);
//		}
//	}
//}


main()
{
	printf("\tTao 1 danh sach SV:\n");
	sinhvien sv;
	list head;
	head = khoitao(head);
	head = nhapsv(head);
	xuat(head);
}












