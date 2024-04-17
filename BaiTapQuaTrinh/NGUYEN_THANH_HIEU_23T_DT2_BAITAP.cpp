#include <stdio.h>
#include <math.h>
const int maxN = 100;
int p, q, n, m; //
char c1[maxN], c2[maxN], c3[maxN];  //dat ten file
float tong[maxN][maxN] = {0};
float tich[maxN][maxN] = {0}; 
float d[maxN][maxN] = {0};
float a[maxN][maxN], b[maxN][maxN];
FILE *f1, *f2, *f3;


void nhapA (float a[maxN][maxN], int n, FILE *f1);
void nhapB(float a[maxN][maxN], int n, FILE *f2);


// ÐOC hang cua ma tran A va mt B o file , sau do nhap gia tri cua mt A,B o file vao mang A , B. 
void Input(){
	fscanf(f1, "%d", &n);
	fscanf(f2, "%d", &m);
	nhapA(a, n, f1);
	nhapB(b, n, f2);
}

// Nhap tenfile.txt, sau do mo file co ten la du lieu da nhap. 
void NhapFile(){
	printf("NHAP DUNG DINH DANG TEN FILE: [name].txt\n");
	printf("NHAP TEN FILE INPUT SO 1: "); scanf("%s", c1);
	printf("NHAP TEN FILE INPUT SO 2: "); scanf("%s", c2);
	printf("NHAP TEN FILE OUTPUT: "); scanf("%s", c3);
	f1 = fopen(c1, "r");
	f2 = fopen(c2, "r");
	f3 = fopen(c3, "w"); 
}

// kiem tra xem file can mo co ton tai hay khong  
int check(FILE *f1, FILE *f2, FILE *f3){
	if(f1 == NULL || f2 == NULL || f3 == NULL)
	return 0;
	return 1;
}


// xuat du lieu output ra file f3. 
void xuatFile(float a[][maxN], int n, FILE *f3){
	int i, j;
	for(i = 0; i < n; i++){
	 	for(j = 0; j < n; j++){
	 		fprintf(f3, "%.2f ", a[i][j]);
		 }
		 fprintf(f3, "\n");
	}
	fprintf(f3, "\n");
}

//doc gia tri cua cac phan tu trong ma tran A va gan cho array A  . 
void nhapA (float a[maxN][maxN], int n, FILE *f1){
	int i, j;
	for(i = 0; i < n; i++)
	 	for(j = 0; j < n; j++)
	 		fscanf(f1, "%f", &a[i][j]);
}

//doc gia tri cua cac phan tu trong ma tran B va gan cho array B   . 
void nhapB(float a[maxN][maxN], int n, FILE *f2){
	int i, j;
	for(i = 0; i < n; i++)
	 	for(j = 0; j < n; j++)
	 		fscanf(f2, "%f", &a[i][j]);
}

//cai ten noi len tat ca =) 
void TinhMaTranTichVaTong(float a[maxN][maxN], float b[maxN][maxN], int n){
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			tong[i][j] = a[i][j] + b[i][j];
	int k;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				tich[i][j] += (a[i][k] * b[k][j]);
}

//cai ten noi len tat ca =) (p,q) 
void DoiCot(){
	int i, j, k;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) d[i][j] = tich[i][j];
		
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(j == p - 1){
				float tmp = d[i][j];
				d[i][j] = d[i][q-1];
				d[i][q-1] = tmp;
			}
}

// xuat cac matran ra man hinh  
void xuatMH(float a[][maxN], int n){
	int i, j;
	for(i = 0; i < n; i++){
	 	for(j = 0; j < n; j++){
	 		printf("%.2f ", a[i][j]);
		 }
		 printf("\n");
	}
	printf("\n");
}

//xuat matran tich va matran tong ra man hinh  
void MaTranTichVaTongMH(){
	printf("\nMA TRAN TICH\n");
	xuatMH(tich, n);
	printf("\nMA TRAN TONG\n");
	xuatMH(tong, n);
}

//xuat matran tich va matran tong ra man hinh 
void MaTranTichVaTongFile(){
	fprintf(f3, "\nMA TRAN TICH\n");
	xuatFile(tich, n, f3);
	fprintf(f3, "\nMA TRAN TONG\n");
	xuatFile(tong, n, f3);
}

// in ma tran sau khi da doi cot ra MH  
void DoiCotMH(){
	do{
		printf("NHAP HAI COT P VA Q CAN THAY DOI (1 <= P, Q <= %d)\n", n);
		printf("P = "); scanf("%d", &p);
		printf("Q = "); scanf("%d", &q); printf("\n");
	} while(q > n || p > n || p < 1 || q < 1);
	DoiCot();
	printf("MA TRAN TICH SAU KHI DOI COT %d VA %d\n", p, q);
	xuatMH(d, n);
}

// in ma tran sau khi da doi cot ra File f3  
void DoiCotFile(){
	fprintf(f3, "MA TRAN TICH SAU KHI DOI COT %d VA %d\n", p, q);
	xuatFile(d, n, f3);
}
int main(){
	printf("hello");
	// KHAI BAO FILE
	NhapFile(); 
	
	
	if(check(f1, f2, f3)){ // Check cac file
	
	//INPUT
	Input();
	//
	
	if(m == n){ //Check hang ma tran
	//
	
	
	//Tinh Toan Ma Tran Tich Va Tong
	TinhMaTranTichVaTong(a, b, n);
	
	
	//
 	//XUAT RA MAN HINH
 	printf("MA TRAN A \n");
 	xuatMH(a, n);
 	printf("MA TRAN B \n");
 	xuatMH(b, n);
 	printf("MA TRAN TICH VA MA TRAN TONG CUA A VA B LA \n");
 	MaTranTichVaTongMH();
 	DoiCotMH();
 	//
 	
 	
 	//XUAT RA FILE
	fprintf(f3, "MA TRAN A \n");
 	xuatFile(a, n, f3);
 	fprintf(f3, "MA TRAN B \n");
 	xuatFile(b, n, f3);
 	fprintf(f3, "MA TRAN TICH VA MA TRAN TONG CUA A VA B LA \n");
 	MaTranTichVaTongFile();
 	DoiCotFile();
 	//
 	
 	
 	printf("____________DA THUC HIEN THANH CONG____________\n"); 
 	}
	else 
		printf("____________HAI MA TRAN KHONG CUNG CAP____________\n");
	}
 	else
 		printf("____________LOI MO FILE____________\n");
	 
	
	fclose(f1);
	fclose(f2);
	fclose(f3);
	
 	return 0;
}
