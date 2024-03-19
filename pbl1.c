#include <stdio.h>
#include <stdlib.h>
#define max_length 100
struct Item{
	char code[max_length], name[max_length], unit[max_length];
	int price, total_price, day, quantity; 
};
struct Item_list{
	struct Item item;
	struct Item_list *next;
};

typedef struct Item_list* list;

list Create_New_Item(){
//	fgets(i.name, 100, stdin);
	struct Item i;
	printf("--------------------------------------\n");
	printf("Nhap thong tin hang hoa!\n");
	printf("Nhap ma hang hoa: "); scanf("%s", &i.code);
	printf("Nhap ten hang hoa: "); scanf("%s", &i.name);
	printf("Nhap ngay nhap thong tin hang hoa trong thang: "); scanf("%d", &i.day);
	printf("Nhap so luong hang hoa: "); scanf("%d", &i.quantity);
	printf("Nhap don vi hang hoa: "); scanf("%s", &i.unit);
	printf("Nhap don gia hang hoa: "); scanf("%d", &i.price);
//	printf("Nhap thanh tien: ") Cai nay phai lam ham tinh'
	list tmp = malloc(sizeof(struct Item_list));
	tmp -> item = i;
	tmp -> next = NULL;
	return tmp; 
}
void insertLast(list *head){
	list tmp = Create_New_Item();
	if(*head == NULL) *head = tmp;
	else{
		list p = *head;
		while(p -> next != NULL) p = p -> next;
		p -> next = tmp;
	}
}

void print(struct Item i){
	printf("---------------------------------------\n");
	printf("Ma hang hoa: %s\n", i.code);
	printf("Ten hang hoa: %s\n", i.name);
	printf("Ngay nhap thong tin: %d\n", i.day);
	printf("So luong hang hoa: %d\n", i.quantity);
	printf("Don vi hang hoa: %s\n", i.unit);
	printf("Don gia hang hoa: %d\n", i.price);
	printf("---------------------------------------\n");
}
void print_list(list head){
	printf("Danh sach hang hoa\n");
	while(head != NULL){
		print(head -> item);
		head = head -> next;
	}
	printf("\n------------------------------------\n");
}
int main(){
	list head = NULL;
	while(1){
		printf("-----------------MENU-----------------\n");
		printf("1.Nhap thong tin hang hoa moi! \n");
		printf("2.Xuat thong tin hang hoa!\n");
		printf("--------------------------------------\n");
		int select;
		scanf("%d", &select);
		if(select == 1){
			insertLast(&head); 
		}
		else
		if(select == 2){
			print_list(head);
		}
	}
} 
