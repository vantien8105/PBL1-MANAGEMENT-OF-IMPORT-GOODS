<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element
{
    char mahang[100], tenhang[100], dvtinh[100];
	int soluong, ngay;
	float dongia, thanhtien; 
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
void SapXep(list main_list, int type);
void TimKiem(list main_list, int type); 
void swap(list tmp1, list tmp2);
int is_empty(list main_list);
int main(){
	list main_list = make_list();
	int i, toggle_stop = 1;
	while(toggle_stop){
        printf("\n\n\t\t     QUAN LY HANG NHAP TRONG THANG\n");
        printf("+");
		for(i=0;i<71;i++) printf("-");printf("+\n");
			printf("| %-70s|\n","1. Them thong tin hang nhap kho vao danh sach"); //done
			printf("| %-70s|\n","2. Lay du lieu hang nhap kho tu file"); // done
			printf("| %-70s|\n","3. Sap xep (theo so luong/ theo gia thanh)"); //done
			printf("| %-70s|\n","4. Tim kiem (theo ma hang/ gia thanh/ ten mat hang)"); //done
			printf("| %-70s|\n","5. Them/ bot so luong");
			printf("| %-70s|\n","6. Tinh thanh tien cua 1 ngay (chi phi tiet kiem)");
			printf("| %-70s|\n","7. Tinh thanh tien cua ca thang (chi phi tiet kiem)");
			printf("| %-70s|\n","8. Xoa mat hang ra khoi danh sach (theo ma hang/ ten hang/ theo ngay)");
			printf("| %-70s|\n","9. In danh sach cac mat hang"); //done
			printf("| %-70s|\n","0. Thoat chuong trinh");// done
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
				printf("Hay ban nhap don gia: "); scanf("%f", &item.dongia);
				printf("Hay ban nhap thanh tien: "); scanf("%f", &item.thanhtien);
				printf("Hay ban nhap ngay nhap: "); scanf("%d", &item.ngay);
				printf("+"); for(i=0;i<71;i++) printf("-");printf("+\n");
				insert(main_list, item);
			}
				break;
			case 2:
				docfile(main_list);
				break;
			case 3:
				{
					printf("Ban hay chon cach sap xep!\n1: Theo so luong\n2: Theo don gia\n3: Theo thanh tien\n4: Theo ngay nhap\n");
					int type;
					do{
					printf("Lua chon: "); 
					scanf("%d", &type);
					if(type < 1 || type > 4) printf("Lua chon cua ban khong hop le! Moi ban nhap lai!\n");
					}
					while(type < 1 || type > 4);
					SapXep(main_list, type); 
				}
				break;
			case 4:
				{
					printf("Ban hay chon cach tim kiem!\n1: Theo ma hang\n2: Theo ten hang\n3 :Theo ngay nhap\n"); 
					int type;
					do{
					printf("Lua chon: "); 
					scanf("%d", &type);
					if(type < 1 || type > 3) printf("Lua chon cua ban khong hop le! Moi ban nhap lai!\n");
					}
					while(type < 1 || type > 3);
					TimKiem(main_list, type); 
				}
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
	int j = 0, file_size = 0;
	struct Element i[100];
	char c1[100];
	do{
	printf("Moi nhap ten file du lieu: "); 
	fflush(stdin); 
	gets(c1);
	fi = fopen(c1, "r");
	if(fi == NULL) printf("File khong ton tai! Vui long nhap lai ten file\n");
	}while(fi == NULL);
	printf("Truy cap file %s thanh cong\n", c1);
	while (fgets(i[j].mahang, sizeof(i[j].mahang), fi) != NULL &&
	       fgets(i[j].tenhang, sizeof(i[j].tenhang), fi) != NULL &&
	       fgets(i[j].dvtinh, sizeof(i[j].dvtinh), fi) != NULL)
	{
    i[j].mahang[strcspn(i[j].mahang, "\n")] = '\0';
    i[j].tenhang[strcspn(i[j].tenhang, "\n")] = '\0';
    i[j].dvtinh[strcspn(i[j].dvtinh, "\n")] = '\0';

    fscanf(fi, "%d%f%f%d", &i[j].soluong, &i[j].dongia, &i[j].thanhtien, &i[j].ngay);
    fgetc(fi);
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
		head = head -> next;
		while(head -> next != NULL && head -> item.ngay <= item.ngay) head = head -> next;
		if(head -> next == NULL && head -> item.ngay <= item.ngay){
			head -> next = tmp;
			tmp -> pre = head;
		}
		else{
			tmp -> next = head;
			tmp -> pre = head -> pre;
			head -> pre -> next = tmp;
			head -> pre = tmp;
		}
	}
}
void SapXep(list main_list, int type){
	if(is_empty(main_list)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	switch(type){
		case 1:
			{
				main_list = main_list -> next;
				list tmp1, tmp2;
				for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
					for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
						if(tmp1 -> item.soluong > tmp2 -> item.soluong){
							swap(tmp1, tmp2);
						}
					}
				}
				printf("Da hoan thanh sap xep du lieu theo so luong!\n");
			}
			break; 
		case 2:
			{
				main_list = main_list -> next;
				list tmp1, tmp2;
				for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
					for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
						if(tmp1 -> item.dongia > tmp2 -> item.dongia){
							swap(tmp1, tmp2);
						}
					}
				}
				printf("Da hoan thanh sap xep du lieu theo don gia!\n");
			}
			break; 
		case 3:
			{
				main_list = main_list -> next;
				list tmp1, tmp2;
				for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
					for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
						if(tmp1 -> item.thanhtien > tmp2 -> item.thanhtien){
							swap(tmp1, tmp2);
						}
					}
				}
				printf("Da hoan thanh sap xep du lieu theo thanh tien!\n");
			}
			break; 
		case 4:
		{
			main_list = main_list -> next;
				list tmp1, tmp2;
				for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
					for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
						if(tmp1 -> item.ngay > tmp2 -> item.ngay){
							swap(tmp1, tmp2);
						}
					}
				}
				printf("Da hoan thanh sap xep du lieu theo ngay nhap!\n");
		}
		break;
		default:
		break; 
	}
}
void TimKiem(list main_list, int type){
	if(is_empty(main_list)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	switch(type){
		case 1:{
			main_list = main_list -> next;
			list tmp = main_list;
			list print = make_list();
			char mh[100]; int is_exist = 0;
			printf("Nhap ma hang can tim kiem: ");
			fflush(stdin);
			gets(mh);
			while(tmp != NULL){
				if(strcmp(mh, tmp -> item.mahang) == 0){
					is_exist = 1;
					insert(print, tmp -> item);
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay ma hang %s!\n", mh);
			}
			else{
				print_list(print);
			}
			break;
		}
		case 2:{
			main_list = main_list -> next;
			list tmp = main_list;
			list print = make_list();
			char th[100]; int is_exist = 0;
			printf("Nhap ten hang can tim kiem: ");
			fflush(stdin);
			gets(th);
			while(tmp != NULL){
				if(strcmp(th, tmp -> item.tenhang) == 0){
					is_exist = 1;
					insert(print, tmp -> item);
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay ten hang %s!\n", th);
			}
			else{
				print_list(print);
			}
			break;
		}
		case 3:{
			main_list = main_list -> next;
			list tmp = main_list;
			list print = make_list();
			int day; int is_exist = 0;
			printf("Nhap ngay nhap hang can tim kiem: "); scanf("%d", &day);
			while(tmp != NULL){
				if(day == tmp -> item.ngay){
					is_exist = 1;
					insert(print, tmp -> item);
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay ngay nhap hang %d!\n", day);
			}
			else{
				print_list(print);
			}
			break;
		}
	}
} 
void swap(list tmp1, list tmp2){
	struct Element i;
	i = tmp1 -> item; 
	tmp1 -> item = tmp2 -> item;
	tmp2 -> item = i; 
}
int is_empty(list main_list){
	if(main_list -> next == NULL) return 1;
	return 0;
}
void print_list(list head){
	if(is_empty(head)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	printf("Danh Sach Hang Hoa\n");
	printf( "+--------------------+-------------------------+---------------+---------------+---------------+---------------+---------------+\n");
    printf("|%-20s|%-25s|%-15s|%-15s|%-15s|%-15s|%-15s|\n","MA HANG","TEN HANG","DON VI HANG","SO LUONG","DON GIA", "THANH TIEN", "NGAY NHAP");
	head = head -> next;
	while(head != NULL){
		printf( "|--------------------|-------------------------|---------------|---------------|---------------|---------------|---------------|\n");
    	printf("|%-20s|%-25s|%-15s|%-15d|%-15.2f|%-15.2f|%-15d|\n",head -> item.mahang ,head -> item.tenhang ,head -> item.dvtinh,
		head -> item.soluong,head -> item.dongia, head -> item.thanhtien, head -> item.ngay);
		head = head -> next;
	}
	printf( "+--------------------+-------------------------+---------------+---------------+---------------+---------------+---------------+\n");	
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element
{
    char mahang[100], tenhang[100], dvtinh[100];
	int soluong, ngay;
	float dongia, thanhtien; 
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
void SapXep(list main_list, int type);
void TimKiem(list main_list, int type); 
void swap(list tmp1, list tmp2);
int is_empty(list main_list);
int main(){
	list main_list = make_list();
	int i, toggle_stop = 1;
	while(toggle_stop){
        printf("\n\n\t\t     QUAN LY HANG NHAP TRONG THANG\n");
        printf("+");
		for(i=0;i<71;i++) printf("-");printf("+\n");
			printf("| %-70s|\n","1. Them thong tin hang nhap kho vao danh sach"); //done
			printf("| %-70s|\n","2. Lay du lieu hang nhap kho tu file"); // done
			printf("| %-70s|\n","3. Sap xep (theo so luong/ theo gia thanh)"); //done
			printf("| %-70s|\n","4. Tim kiem (theo ma hang/ gia thanh/ ten mat hang)"); //done
			printf("| %-70s|\n","5. Them/ bot so luong");
			printf("| %-70s|\n","6. Tinh thanh tien cua 1 ngay (chi phi tiet kiem)");
			printf("| %-70s|\n","7. Tinh thanh tien cua ca thang (chi phi tiet kiem)");
			printf("| %-70s|\n","8. Xoa mat hang ra khoi danh sach (theo ma hang/ ten hang/ theo ngay)");
			printf("| %-70s|\n","9. In danh sach cac mat hang"); //done
			printf("| %-70s|\n","0. Thoat chuong trinh");// done
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
				printf("Hay ban nhap don gia: "); scanf("%f", &item.dongia);
				printf("Hay ban nhap thanh tien: "); scanf("%f", &item.thanhtien);
				printf("Hay ban nhap ngay nhap: "); scanf("%d", &item.ngay);
				printf("+"); for(i=0;i<71;i++) printf("-");printf("+\n");
				insert(main_list, item);
			}
				break;
			case 2:
				docfile(main_list);
				break;
			case 3:
				{
					printf("Ban hay chon cach sap xep!\n1: Theo so luong\n2: Theo don gia\n3: Theo thanh tien\n4: Theo ngay nhap\n");
					int type;
					do{
					printf("Lua chon: "); 
					scanf("%d", &type);
					if(type < 1 || type > 4) printf("Lua chon cua ban khong hop le! Moi ban nhap lai!\n");
					}
					while(type < 1 || type > 4);
					SapXep(main_list, type); 
				}
				break;
			case 4:
				{
					printf("Ban hay chon cach tim kiem!\n1: Theo ma hang\n2: Theo ten hang\n3 :Theo ngay nhap\n"); 
					int type;
					do{
					printf("Lua chon: "); 
					scanf("%d", &type);
					if(type < 1 || type > 3) printf("Lua chon cua ban khong hop le! Moi ban nhap lai!\n");
					}
					while(type < 1 || type > 3);
					TimKiem(main_list, type); 
				}
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
	int j = 0, file_size = 0;
	struct Element i[100];
	char c1[100];
	do{
	printf("Moi nhap ten file du lieu: ");
	fflush(stdin); 
	gets(c1);
	fi = fopen(c1, "r");
	if(fi == NULL) printf("File khong ton tai! Vui long nhap lai ten file\n");
	}while(fi == NULL);
	printf("Truy cap file %s thanh cong\n", c1);
	while (fgets(i[j].mahang, sizeof(i[j].mahang), fi) != NULL &&
	       fgets(i[j].tenhang, sizeof(i[j].tenhang), fi) != NULL &&
	       fgets(i[j].dvtinh, sizeof(i[j].dvtinh), fi) != NULL)
	{
    i[j].mahang[strcspn(i[j].mahang, "\n")] = '\0';
    i[j].tenhang[strcspn(i[j].tenhang, "\n")] = '\0';
    i[j].dvtinh[strcspn(i[j].dvtinh, "\n")] = '\0';

    fscanf(fi, "%d%f%f%d", &i[j].soluong, &i[j].dongia, &i[j].thanhtien, &i[j].ngay);
    fgetc(fi);
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
		head = head -> next;
		while(head -> next != NULL && head -> item.ngay <= item.ngay) head = head -> next;
		if(head -> next == NULL && head -> item.ngay <= item.ngay){
			head -> next = tmp;
			tmp -> pre = head;
		}
		else{
			tmp -> next = head;
			tmp -> pre = head -> pre;
			head -> pre -> next = tmp;
			head -> pre = tmp;
		}
	}
}
void SapXep(list main_list, int type){
	if(is_empty(main_list)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	switch(type){
		case 1:
			{
				main_list = main_list -> next;
				list tmp1, tmp2;
				for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
					for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
						if(tmp1 -> item.soluong > tmp2 -> item.soluong){
							swap(tmp1, tmp2);
						}
					}
				}
				printf("Da hoan thanh sap xep du lieu theo so luong!\n");
			}
			break; 
		case 2:
			{
				main_list = main_list -> next;
				list tmp1, tmp2;
				for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
					for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
						if(tmp1 -> item.dongia > tmp2 -> item.dongia){
							swap(tmp1, tmp2);
						}
					}
				}
				printf("Da hoan thanh sap xep du lieu theo don gia!\n");
			}
			break; 
		case 3:
			{
				main_list = main_list -> next;
				list tmp1, tmp2;
				for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
					for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
						if(tmp1 -> item.thanhtien > tmp2 -> item.thanhtien){
							swap(tmp1, tmp2);
						}
					}
				}
				printf("Da hoan thanh sap xep du lieu theo thanh tien!\n");
			}
			break; 
		case 4:
		{
			main_list = main_list -> next;
				list tmp1, tmp2;
				for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
					for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
						if(tmp1 -> item.ngay > tmp2 -> item.ngay){
							swap(tmp1, tmp2);
						}
					}
				}
				printf("Da hoan thanh sap xep du lieu theo ngay nhap!\n");
		}
		break;
		default:
		break; 
	}
}
void TimKiem(list main_list, int type){
	if(is_empty(main_list)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	switch(type){
		case 1:{
			main_list = main_list -> next;
			list tmp = main_list;
			list print = make_list();
			char mh[100]; int is_exist = 0;
			printf("Nhap ma hang can tim kiem: ");
			fflush(stdin);
			gets(mh);
			while(tmp != NULL){
				if(strcmp(mh, tmp -> item.mahang) == 0){
					is_exist = 1;
					insert(print, tmp -> item);
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay ma hang %s!\n", mh);
			}
			else{
				print_list(print);
			}
			break;
		}
		case 2:{
			main_list = main_list -> next;
			list tmp = main_list;
			list print = make_list();
			char th[100]; int is_exist = 0;
			printf("Nhap ten hang can tim kiem: ");
			fflush(stdin);
			gets(th);
			while(tmp != NULL){
				if(strcmp(th, tmp -> item.tenhang) == 0){
					is_exist = 1;
					insert(print, tmp -> item);
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay ten hang %s!\n", th);
			}
			else{
				print_list(print);
			}
			break;
		}
		case 3:{
			main_list = main_list -> next;
			list tmp = main_list;
			list print = make_list();
			int day; int is_exist = 0;
			printf("Nhap ngay nhap hang can tim kiem: "); scanf("%d", &day);
			while(tmp != NULL){
				if(day == tmp -> item.ngay){
					is_exist = 1;
					insert(print, tmp -> item);
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay ngay nhap hang %d!\n", day);
			}
			else{
				print_list(print);
			}
			break;
		}
	}
} 
void swap(list tmp1, list tmp2){
	struct Element i;
	i = tmp1 -> item; 
	tmp1 -> item = tmp2 -> item;
	tmp2 -> item = i; 
}
int is_empty(list main_list){
	if(main_list -> next == NULL) return 1;
	return 0;
}
void print_list(list head){
	if(is_empty(head)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	printf("Danh Sach Hang Hoa\n");
	printf( "+--------------------+-------------------------+---------------+---------------+---------------+---------------+---------------+\n");
    printf("|%-20s|%-25s|%-15s|%-15s|%-15s|%-15s|%-15s|\n","MA HANG","TEN HANG","DON VI HANG","SO LUONG","DON GIA", "THANH TIEN", "NGAY NHAP");
	head = head -> next;
	while(head != NULL){
		printf( "|--------------------|-------------------------|---------------|---------------|---------------|---------------|---------------|\n");
    	printf("|%-20s|%-25s|%-15s|%-15d|%-15.2f|%-15.2f|%-15d|\n",head -> item.mahang ,head -> item.tenhang ,head -> item.dvtinh,
		head -> item.soluong,head -> item.dongia, head -> item.thanhtien, head -> item.ngay);
		head = head -> next;
	}
	printf( "+--------------------+-------------------------+---------------+---------------+---------------+---------------+---------------+\n");	
}

>>>>>>> 64bc7d6 (testing)
