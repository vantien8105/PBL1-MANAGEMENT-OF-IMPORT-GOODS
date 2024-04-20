#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element
{
    char mahang[100], tenhang[100], dvtinh[100];
	int soluong, dongia, thanhtien, ngay;
};

struct List{
    struct Element item;
    struct List *next;
    struct List *pre;
};

typedef struct List *list;

list make_list();
void insert(list head, struct Element e);
void print_list(list head);
void docfile(list main_list); 
int main(){
	list main_list = make_list();
	int i, toggle_stop = 1;
	while(toggle_stop){
        printf("\n\n\t\t     QUAN LY HANG NHAP TRONG THANG\n");
        printf("+");
		for(i=0;i<71;i++) printf("-");printf("+\n");
			printf("| %-70s|\n","1. Them thong tin hang nhap kho vao danh sach");
			printf("| %-70s|\n","2. Lay du lieu hang nhap kho tu file");
			printf("| %-70s|\n","3. Sap xep (theo so luong/ theo gia thanh)");
			printf("| %-70s|\n","4. Tim kiem (theo ma hang/ gia thanh/ ten mat hang)");
			printf("| %-70s|\n","5. Them/ bot so luong");
			printf("| %-70s|\n","6. Tinh thanh tien cua 1 ngay (chi phi tiet kiem)");
			printf("| %-70s|\n","7. Tinh thanh tien cua ca thang (chi phi tiet kiem)");
			printf("| %-70s|\n","8. Xoa mat hang ra khoi danh sach (theo ma hang/ ten hang/ theo ngay)");
			printf("| %-70s|\n","9. In danh sach cac mat hang");
			printf("| %-70s|\n","0. Thoat chuong trinh");
			printf("+");
			for(i=0;i<71;i++) printf("-");printf("+\n\n");
		int select;
		printf("Moi ban nhap lua chon: "); scanf("%d", &select);
		switch(select){
			case 1:
				{
				struct Element item;
				printf("+"); for(i=0;i<71;i++) printf("-");printf("+\n");
				printf("Hay nhap ma hang: "); fflush(stdin); gets(item.mahang);
				printf("Hay ban nhap ten hang: "); fflush(stdin); gets(item.tenhang);
				printf("Hay ban nhap don vi hang: "); fflush(stdin); gets(item.dvtinh);
				printf("Hay ban nhap so luong: "); scanf("%d", &item.soluong);
				printf("Hay ban nhap don gia: "); scanf("%d", &item.dongia);
				printf("Hay ban nhap thanh tien: "); scanf("%d", &item.thanhtien);
				printf("Hay ban nhap ngay nhap: "); scanf("%d", &item.ngay);
				printf("+"); for(i=0;i<71;i++) printf("-");printf("+\n");
				insert(main_list, item);
			}
				break;
			case 2:
				docfile(main_list);
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:
				
				break;
			case 7:
				
				break;
			case 8:
				
				break;
			case 9:
				print_list(main_list);
				break;
			case 0:
				toggle_stop = 0;
				printf("Ban da thoat chuong trinh thanh cong!\n");
				break;
			default:
				printf("Lua chon cua ban khong hop le! Moi ban nhap lai\n");
				continue;
		}
	}
	
	return 0;
}
void docfile(list main_list){
	FILE *fi;
	int j, file_size = 0;
	struct Element i[100];
	char c1[100];
	do{
	printf("Moi nhap ten file du lieu: "); scanf("%s", c1);
	fi = fopen(c1, "r");
	if(fi == NULL) printf("File khong ton tai! Vui long nhap lai ten file\n");
	}while(fi == NULL);
	printf("Truy cap file %s thanh cong\n", c1);
	while(fscanf(fi, "%s%s%s%d%d%d%d", &i[j].mahang, &i[j].tenhang, &i[j].dvtinh, &i[j].soluong, &i[j].dongia, &i[j].thanhtien, &i[j].ngay) != EOF){
		file_size++;
		j++;
	}
	printf("Da doc du lieu cua %d mat hang\n", file_size);
	for(j = 0; j < file_size; j++){
		insert(main_list, i[j]);
	}
	
} 
list make_list(){
    list head = malloc(sizeof(struct List));
    head -> next = NULL;
}
void insert(list head, struct Element item){
	list tmp = make_list();
	tmp -> item = item;
	if(head -> next == NULL){
		head -> next = tmp;
		tmp -> pre = head;
	}
	else{
		while(head -> next != NULL) head = head -> next;
		head -> next = tmp;
		tmp -> pre = head;
	}
}	
void print_list(list head){
	printf("Danh Sach Hang Hoa\n");
	printf( "+--------------------+-------------------------+---------------+---------------+---------------+---------------+---------------+\n");
    printf("|%-20s|%-25s|%-15s|%-15s|%-15s|%-15s|%-15s|\n","MA HANG","TEN HANG","DON VI HANG","SO LUONG","DON GIA", "THANH TIEN", "NGAY NHAP");
    list tmp = head -> next;
	head = head -> next;
	while(head != NULL){
		printf( "|--------------------|-------------------------|---------------|---------------|---------------|---------------|---------------|\n");
    	printf("|%-20s|%-25s|%-15s|%-15d|%-15d|%-15d|%-15d|\n",head -> item.mahang ,head -> item.tenhang ,head -> item.dvtinh,
		head -> item.soluong,tmp -> item.dongia, tmp -> item.thanhtien, tmp -> item.ngay);
		head = head -> next;
	}
	printf( "+--------------------+-------------------------+---------------+---------------+---------------+---------------+---------------+\n");	
}
