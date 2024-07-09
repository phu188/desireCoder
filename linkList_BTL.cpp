#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <stdbool.h>
#include <conio.h>
#define yearnow 2024
// Khởi tao struct phi hành gia
typedef struct date{
	int day;
	int month;
	int year;
}d;

typedef struct astronaut{
	char id[30];
	char name[30];
	d age;
	char sex[10];
	char nationality[20];
	int salary;
}phg;	
//Khởi tạo các cấu trúc cần thiết cho danh sách liên kết
struct Node{
	phg data;
	Node *next;
};
struct list{
	Node *head;
	Node *tail;
};
Node *createNode(phg init_data){
	Node *node=new Node;
	node->data=init_data;
	node->next=NULL;
	return node;
}
void createList(list &l){
	l.head=NULL;
	l.tail=NULL;
}
void addTail(list &l,Node *node){
	if(l.head==NULL){
		l.head=node;
		l.tail=node;
	}
	else{
		l.tail->next=node;
		l.tail=node;
	}
}
bool check(list &l,char id[30]){
	for(Node *p=l.head;p!=NULL;p=p->next){
		if(!strcmp(p->data.id,id)){
				return false;
		}
	}
	return true;
}


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int maxDay;
    switch (month) {
        case 2:
            maxDay = isLeapYear(year) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxDay = 30;
            break;
        default:
            maxDay = 31;
            break;
    }
    if((2024-year)<18){
    	return false;
	}
    return day <= maxDay;
}
bool xuliTen(char ten[30]){
	for(int i=0;i<30;++i){
		if(ten[i] >='0' && ten[i]<='9' ){
			return false;
		}
	}
	return true;
}
//Hàm nhập thông tin 
void input(list &l,int &n){
	system("cls");//Trình bày
	do {
        printf("Nhap so luong phi hanh gia (lon hon hoac bang 1): ");
        if (scanf("%d", &n) != 1 || n < 1) {
        		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			    SetConsoleTextAttribute(hConsole, 14); 
				printf("So luong khong hop le! Moi nhap lai!\n");
			    SetConsoleTextAttribute(hConsole, 7);
            	while (getchar() != '\n');
        }
    } while (n < 1);
	fflush(stdin);
	for(int i=0;i<n;++i){
		printf("PHI HANH GIA %d\n",i+1);
		phg store;
		do{
			printf("Nhap ID : "); gets(store.id); 
			if(!check(l,store.id)){
			    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			    SetConsoleTextAttribute(hConsole, 14); 
				printf("ID da ton tai! Moi nhap lai !\n");
			    SetConsoleTextAttribute(hConsole, 7);
				
			}
		}
		while(!check(l,store.id) );
		fflush(stdin);
		do
		{
			printf("Nhap ten :"); 	gets(store.name); strupr(store.name);
			if(!xuliTen(store.name)){
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			    SetConsoleTextAttribute(hConsole, 14); 
				printf("Ten chua ki tu so! Moi nhap lai!\n");
			    SetConsoleTextAttribute(hConsole, 7);
			}
		}
		while(!xuliTen(store.name));
		do{
				printf("Nhap Ngay / Thang / Nam sinh: \n");
				printf("\tNhap Ngay :"); scanf("%d",&store.age.day); 
				printf("\tNhap Thang :"); scanf("%d",&store.age.month); 
				printf("\tNhap Nam :"); scanf("%d",&store.age.year); 
				if(!isValidDate(store.age.day,store.age.month,store.age.year)){
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				    SetConsoleTextAttribute(hConsole, 14); 
					printf("Nhap Ngay Thang Nam sinh khong hop le! Moi nhap lai!\n");
				    SetConsoleTextAttribute(hConsole, 7);
				}
		}
		while(!isValidDate(store.age.day,store.age.month,store.age.year));
		fflush(stdin);
		do{
			printf("Gioi tinh(NAM/NU) :");   scanf("%s",&store.sex); strupr(store.sex); 
			if((strcmp("NAM",store.sex)) != 0 && (strcmp("NU",store.sex)) !=0){
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				    SetConsoleTextAttribute(hConsole, 14); 
					printf("Gioi tinh khong dung moi nhap lai!\n");
				    SetConsoleTextAttribute(hConsole, 7);
				
			}
		}
		while((strcmp("NAM",store.sex)) != 0 && (strcmp("NU",store.sex)) !=0);
		fflush(stdin);
		printf("Nhap Quoc tich :");   gets(store.nationality); strupr(store.nationality);
		int check=1;
		do {
	        printf("Nhap Luong thang ($):");	
	        if (scanf("%d",&store.salary) ==0 ) {
	        		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				    SetConsoleTextAttribute(hConsole, 14); 
					printf("Luong khong hop le! Moi nhap lai!\n");
				    SetConsoleTextAttribute(hConsole, 7);
	            	while (getchar() != '\n');
	        }
	        else{
	        	check=0;
			}
	    } 
		while (check);
		fflush(stdin);
		Node *node=new Node;
		node=createNode(store);
		addTail(l,node);
		system("cls");//Trình bày
	}
	fflush(stdin);
}
//Hàm xuất thông tin
void output(list &l){
	Node *p=l.head;
	if(p==NULL){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				    SetConsoleTextAttribute(hConsole, 14); 
					printf("Danh Sach rong. Vui long nhap them thong tin!\n");
				    SetConsoleTextAttribute(hConsole, 7);
		return;
	}
	int cnt=1;
	for(;p!=NULL;p=p->next){
		printf("|============================================|PHI HANH GIA %d|===========================================|\n",cnt++);
		printf("|\tID  \t   TEN   \t  BIRTHDAY\tGIOI TINH\t QUOC TICH \t LUONG THANG \t\t|\n");
		printf("|\t%s\t%s\t %d/%d/%d   \t   %s\t\t %s \t %d ($) \t \t|\n",p->data.id,p->data.name,p->data.age.day,p->data.age.month,p->data.age.year,p->data.sex,p->data.nationality,p->data.salary);
		printf("|=======================================================================================================|\n\n");
	}
}
//Hàm đếm số lượng phi hành gia nam và nữ
void dem(list &l){
	char s[10]="NAM";
	int cnt=0,cntNam=0;
	
	for(Node*p=l.head;p!=NULL;p=p->next){
		cnt++;
		if(!(strcmp(s,p->data.sex))){
			cntNam++;
		}
	}
	printf("|====================================Dem theo gioi tinh Phi hanh gia=============================|\n");
	printf("|\t\t\t\tNam\t\t\t\tNu\t\t\t\t |\n");
	printf("|\t\t\t\t%d\t\t\t\t%d\t\t\t\t |\n",cntNam,(cnt-cntNam));
	printf("|================================================================================================|\n\n");
}
//Hàm tìm thông tin các phi hành gia có lương cao nhất
int findMaxSalary(list &l){
	int Max=0;
	for(Node*p=l.head;p!=NULL;p=p->next){
			if(p->data.salary>Max){
				Max=p->data.salary;
			}
	}
	return Max;
}
//Hàm sắp xếp danh sách theo thứ tự lương tăng dần
void sortList(list &l){
	Node *p,*q;
	for(p=l.head;p!=l.tail;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(p->data.salary > q->data.salary){
				phg x = p->data;
                p->data = q->data;
                q->data = x; 
			}
		}
	}
}

//Hàm tìm thông tin Phi hành gia theo ID
Node* find(list &l,char sign[30]){	
		Node *p=l.head;
		while ((p!=NULL) && (strcmp(p->data.id,sign)!=0)){
     		p=p->next;
    	}
    	return p;
}

//Hàm xóa thông tin của 1 phi hành gia theo ID
void deleter(list &l,char sign[30]){
	Node *check=l.head;
	if(!strcmp(check->data.id,sign)!=0){
			if (l.head != NULL)
			{
				Node* node = l.head;
			
				l.head = node->next;
				delete node;         
				if (l.head == NULL){
					l.tail = NULL;
				}
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
					    printf("Da xoa thanh cong!\n");
					    SetConsoleTextAttribute(hConsole, 7);
				return;
			}
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
					    printf("!DANH SACH RONG!\n");
					    SetConsoleTextAttribute(hConsole, 7);		
		
		return;
	}	
	else{
		while(check->next!=NULL && strcmp(check->next->data.id,sign)!=0){
			check=check->next;
		}
		if(check!=NULL){
			Node *tam=check->next;
			if(tam!=NULL){
				if (l.tail == tam){
					l.tail = check;
				}
				check->next = tam->next;
				delete tam;
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
					    printf("Da xoa thanh cong!\n");
					    SetConsoleTextAttribute(hConsole, 7);
				
				return;
				
			}
		}
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
					  	printf("ID khong hop le!\n");
					    SetConsoleTextAttribute(hConsole, 7);
		return;
	}
}
//Hàm xử lý MENU cho việc sửa chửa thông tin của 1 phi hành gia
void implementFix(list &l,Node *p,int select){
	switch(select){
			case 1:
			{
				fflush(stdin);
				char id[30];
				do{
					printf("Nhap ID moi: "); gets(id); 
					if(!check(l,id)){
					    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("ID da ton tai! Moi nhap lai !\n");
					    SetConsoleTextAttribute(hConsole, 7);
						
					}
				}
				while(!check(l,id) );
				strcpy(p->data.id,id);
				break;	
			}
			case 2:
			{
				
//				char name[30];
				do
				{
					fflush(stdin);
					printf("Nhap ten moi:"); 	gets(p->data.name); strupr(p->data.name);
					if(!xuliTen(p->data.name)){
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("Ten chua ki tu so! Moi nhap lai!\n");
					    SetConsoleTextAttribute(hConsole, 7);
					}
				}
				while(!xuliTen(p->data.name));
//				strcpy(p->data.name,name);
				break;
			}
			case 3:
			{
				fflush(stdin);
				d age;
				do{
						printf("Nhap Ngay / Thang / Nam sinh moi: \n");
						printf("\tNhap Ngay :"); scanf("%d",&age.day); 
						printf("\tNhap Thang :"); scanf("%d",&age.month); 
						printf("\tNhap Nam :"); scanf("%d",&age.year); 
						if(!isValidDate(age.day,age.month,age.year)){
							HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						    SetConsoleTextAttribute(hConsole, 14); 
							printf("Nhap Ngay Thang Nam sinh khong hop le! Moi nhap lai!\n");
						    SetConsoleTextAttribute(hConsole, 7);
						}
				}
				while(!isValidDate(age.day,age.month,age.year));
				
				p->data.age=age;
				fflush(stdin);
				break;
			}	
			case 4:
			{
				fflush(stdin);
				char Sex[10];
				printf("\nNhap gioi tinh moi: "); 
				do{
					printf("Gioi tinh(NAM/NU) :");   scanf("%s",&Sex); strupr(Sex); 
					if((strcmp("NAM",Sex)) != 0 && (strcmp("NU",Sex)) !=0){
							HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						    SetConsoleTextAttribute(hConsole, 14); 
							printf("Gioi tinh khong dung moi nhap lai!\n");
						    SetConsoleTextAttribute(hConsole, 7);	
					}
				}
				while((strcmp("NAM",Sex)) != 0 && (strcmp("NU",Sex)));
				strcpy(p->data.sex,Sex);
				fflush(stdin);
				break;
			}
			case 5:
			{
				fflush(stdin);
				char Nationality[20];
				printf("\nNhap Quoc Tich moi: "); 
				gets(Nationality); strupr(Nationality);
				strcpy(p->data.nationality,Nationality);
				break;
			}
			case 6:
			{
				fflush(stdin);
				int Salary;
				do {
			        printf("Nhap Luong thang moi($): ");	
			        if (scanf("%d",&Salary) != 1 || Salary< 1) {
			        		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						    SetConsoleTextAttribute(hConsole, 14); 
							printf("Luong khong hop le! Moi nhap lai!\n");
						    SetConsoleTextAttribute(hConsole, 7);
			            	while (getchar() != '\n');
			        }
			    } 
				while ( Salary< 1);
				p->data.salary=Salary;
					fflush(stdin);
				break;		
			}
			
	}
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						    SetConsoleTextAttribute(hConsole, 14); 
							printf("\nTHAY DOI THANH CONG !\n");
						    SetConsoleTextAttribute(hConsole, 7);
}
//Hàm MENU cho việc sửa chửa thông tin của 1 phi hành gia
void fix(list &l,Node *p){
		printf("|=======================================|Thong tin nguoi can sua|=======================================|\n");
		printf("|\tID  \t   TEN   \t  BIRTHDAY\tGIOI TINH\t QUOC TICH \t LUONG THANG \t\t|\n");
		printf("|\t%s\t%s\t %d/%d/%d   \t   %s\t\t %s \t %d ($) \t \t|\n",p->data.id,p->data.name,p->data.age.day,p->data.age.month,p->data.age.year,p->data.sex,p->data.nationality,p->data.salary);
		printf("|=======================================================================================================|\n\n");
	bool switchOn=1;
	int selection;
	while(switchOn==1)	
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12); 
	
		printf("\n|====================================DANH SACH THONG TIN CAN SUA=================================|\n");
		printf("|\t\t\t\t1.ID                           \t\t\t\t\t |\n");
		printf("|\t\t\t\t2.TEN                          \t\t\t\t\t |\n");
		printf("|\t\t\t\t3.NGAY/THANG/NAM SINH          \t\t\t\t\t |\n");
		printf("|\t\t\t\t4.GIOI TINH                    \t\t\t\t\t |\n");
		printf("|\t\t\t\t5.QUOC TICH                    \t\t\t\t\t |\n");
		printf("|\t\t\t\t6.LUONG                     	\t\t\t\t |\n");
		printf("|\t\t\t\t7.Thoat(Exit) \t\t\t\t\t\t\t |\n");
		printf("|================================================================================================|\n");
		SetConsoleTextAttribute(hConsole, 7);
		printf("\t\t\t\tMoi nhap lua chon :"); scanf("%d",&selection);
		printf("\n\n");
		if(selection==7){
			
			break;
		}
		implementFix(l,p,selection);
	}	
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14); 
			printf("|==================================|Thong tin phi hanh gia sau khi sua|=================================|\n");
		printf("|\tID  \t   TEN   \t  BIRTHDAY\tGIOI TINH\t QUOC TICH \t LUONG THANG \t\t|\n");
		printf("|\t%s\t%s\t %d/%d/%d   \t   %s\t\t %s \t %d ($) \t \t|\n",p->data.id,p->data.name,p->data.age.day,p->data.age.month,p->data.age.year,p->data.sex,p->data.nationality,p->data.salary);
		printf("|=======================================================================================================|\n\n");						
	SetConsoleTextAttribute(hConsole, 7);

	
}
//Hàm thống kê độ tuổi của các phi hành gia
void statictic(list &l){
	int cnttre=0,cnt=0;
	for(Node*p=l.head;p!=NULL;p=p->next){
		cnt++;
		if( yearnow-(p->data.age.year)<=30){
			cnttre++;
		}
	}
	printf("|====================================Thong ke do tuoi phi hanh gia===============================|\n");
	printf("|\t\tTHANH NIEN\t\t\t\t\t\tTRUNG NIEN\t\t |\n");
	printf("|\t\t     %d\t\t\t\t\t\t\t     %d\t\t\t |\n",cnttre,(cnt-cnttre));
	printf("|================================================================================================|\n\n");
	
}
//Hàm tính lương trung bình của các phi hành gia
float averageSalary(list &l){
	int sum=0;
	int cnt=0;
	for(Node*p=l.head;p!=NULL;p=p->next){
		cnt++;
		sum+=p->data.salary;
	}
	return sum/cnt;
	
}
//Hàm xử lý File
void xoaxuongdong(char x[]){ 
	size_t len=strlen(x);
	if (x[len-1]=='\n'){
		x[len-1]='0';
	}
}
//Hàm Ghi thông tin INPUT vào File
void OutputToFile(list &l) {  
    char Ten_File[100];
    printf("Nhap Ten File de ghi: ");
    fflush(stdin);
    fgets(Ten_File, sizeof(Ten_File), stdin);
    xoaxuongdong(Ten_File);
    FILE *f;
    f = fopen(Ten_File, "wb");
    if (f == NULL) {
        		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
					    printf("ERROR! Khong mo duoc file de doc.\n");
					    SetConsoleTextAttribute(hConsole, 7);
        return;
    }
    int count = 0;
    Node *current = l.head;
    // Đếm số lượng nút trong danh sách liên kết
    while (current != NULL) {
        count++;
        current = current->next;
    }
    // Ghi số lượng nút vào file
    fwrite(&count, sizeof(count), 1, f);
    // Duyệt qua từng nút và ghi thông tin vào file
    current = l.head;
    while (current != NULL) {
        fwrite(&(current->data), sizeof(phg), 1, f);
        current = current->next;
    }
    fclose(f);
    					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
					    printf("Ghi thong tin vao FILE thanh cong!\n");
					    SetConsoleTextAttribute(hConsole, 7);
   	
}
//Hàm nhập thông tin INPUT từ FILE
void InputFromFile(list &l) { 
    char Ten_File[100];
    printf("Nhap Ten File de xuat: ");
    fflush(stdin);
    fgets(Ten_File, sizeof(Ten_File), stdin);
    xoaxuongdong(Ten_File);
    FILE *f;
    f = fopen(Ten_File, "rb");
    if (f == NULL) {
    					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
					    printf("ERROR! Khong mo duoc file de doc.\n");
					    SetConsoleTextAttribute(hConsole, 7);
        return;
    }
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("Nhap thong tin tu FILE thanh cong!\n");
					    SetConsoleTextAttribute(hConsole, 7);

	
    int count;
    // Đọc số lượng nút từ file
    fread(&count, sizeof(count), 1, f);
    phg data;
    // Duyệt qua từng nút được lưu trong file và thêm vào danh sách liên kết
    for (int i = 0; i < count; i++) {
        fread(&data, sizeof(phg), 1, f);
        Node *newNode = createNode(data);
        if (l.head == NULL) {
            l.head = newNode;
            l.tail = newNode;
        } else {
            l.tail->next = newNode;
            l.tail = newNode;
        }
    }
    fclose(f);
}
//Hàm xử lý MENU tổng
void implement(list &l,int select){
	switch(select){
			case 1:
			{
				output(l);
				break;	
			}
			case 2:
			{
				if(l.head==NULL){
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("Danh sach rong! Vui long nhap thong tin !\n");
					    SetConsoleTextAttribute(hConsole, 7);
						break;
				}
				dem(l);
				break;
			}
			case 3:
			{
				if(l.head==NULL){
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("Danh sach rong! Vui long nhap thong tin !\n");
					    SetConsoleTextAttribute(hConsole, 7);
						break;
				}
				int key=findMaxSalary(l);
				for(Node*p=l.head;p!=NULL;p=p->next){
					if(p->data.salary==key){
						printf("|============================================|---MAX SALARY---|=========================================|\n");
						printf("|\tID  \t   TEN   \t  BIRTHDAY\tGIOI TINH\t QUOC TICH \t LUONG THANG \t\t|\n");
						printf("|\t%s\t%s\t %d/%d/%d   \t   %s\t\t %s \t %d ($) \t \t|\n",p->data.id,p->data.name,p->data.age.day,p->data.age.month,p->data.age.year,p->data.sex,p->data.nationality,p->data.salary);
						printf("|=======================================================================================================|\n\n");
					}
				}
				break;
			}	
			case 4:
			{
				if(l.head==NULL){
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("Danh sach rong! Vui long nhap thong tin !\n");
					    SetConsoleTextAttribute(hConsole, 7);
						break;
				}
				sortList(l);
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("Danh sach sau khi sap xep tang dan :\n");
					    SetConsoleTextAttribute(hConsole, 7);

				output(l);
				break;
			}
			case 5:
			{
				if(l.head==NULL){
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("Danh sach rong! Vui long nhap thong tin !\n");
					    SetConsoleTextAttribute(hConsole, 7);
						break;
				}
				char sign[30];	
				printf("Nhap ID can tim :"); scanf("%s",&sign);
				Node* p=new Node;
				p=find(l,sign);
				if(p==NULL){
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("\nKhong tim thay!\n");
					    SetConsoleTextAttribute(hConsole, 7);
				}
				else{
						printf("|============================================|---HAVE FOUND---|=========================================|\n");
						printf("|\tID  \t   TEN   \t  BIRTHDAY\tGIOI TINH\t QUOC TICH \t LUONG THANG \t\t|\n");
						printf("|\t%s\t%s\t %d/%d/%d   \t   %s\t\t %s \t %d ($) \t \t|\n",p->data.id,p->data.name,p->data.age.day,p->data.age.month,p->data.age.year,p->data.sex,p->data.nationality,p->data.salary);
						printf("|=======================================================================================================|\n\n");
				}
				break;
			}
			case 6:
			{
				fflush(stdin);
				printf("Nhap thong tin phi hanh gia muon them :\n");
				phg store;
				do{
					printf("Nhap ID : "); gets(store.id); 
					if(!check(l,store.id)){
					    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("ID da ton tai! Moi nhap lai !\n");
					    SetConsoleTextAttribute(hConsole, 7);
						
					}
				}
				while(!check(l,store.id) );
					fflush(stdin);
					printf("Nhap ten :"); 	gets(store.name); strupr(store.name);
					if(!xuliTen(store.name)){
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("Ten chua ki tu so! Moi nhap lai\n");
					    SetConsoleTextAttribute(hConsole, 7);
					}
				do{
						printf("Nhap Ngay / Thang / Nam sinh: \n");
						printf("\tNhap Ngay :"); scanf("%d",&store.age.day); 
						printf("\tNhap Thang :"); scanf("%d",&store.age.month); 
						printf("\tNhap Nam :"); scanf("%d",&store.age.year); 
						if(!isValidDate(store.age.day,store.age.month,store.age.year)){
							HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						    SetConsoleTextAttribute(hConsole, 14); 
							printf("Nhap Ngay Thang Nam sinh khong hop le! Moi nhap lai!\n");
						    SetConsoleTextAttribute(hConsole, 7);
						}
				}
				while(!isValidDate(store.age.day,store.age.month,store.age.year));
				fflush(stdin);
				do{
					printf("Gioi tinh(NAM/NU) :");   scanf("%s",&store.sex); strupr(store.sex); 
					if((strcmp("NAM",store.sex)) != 0 && (strcmp("NU",store.sex)) !=0){
							HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						    SetConsoleTextAttribute(hConsole, 14); 
							printf("Gioi tinh khong dung moi nhap lai!\n");
						    SetConsoleTextAttribute(hConsole, 7);
						
					}
				}
				while((strcmp("NAM",store.sex)) != 0 && (strcmp("NU",store.sex)));
				fflush(stdin);
				printf("Nhap Quoc tich :");   gets(store.nationality); strupr(store.nationality);
				do {
			        printf("Nhap Luong thang ($):");	
			        if (scanf("%d",&store.salary) != 1 || store.salary< 1) {
			        		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						    SetConsoleTextAttribute(hConsole, 14); 
							printf("Luong khong hop le! Moi nhap lai!\n");
						    SetConsoleTextAttribute(hConsole, 7);
			            	while (getchar() != '\n');
			        }
			    } 
				while (store.salary < 1);
				fflush(stdin);
				Node *node=new Node;
				node=createNode(store);
				addTail(l,node);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						    SetConsoleTextAttribute(hConsole, 14); 
							printf("\nThem thong tin Thanh cong!\n");
						    SetConsoleTextAttribute(hConsole, 7);
				break;		
			}     	
			case 7:
			{
				char ID[30];
				if(l.head==NULL){
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("Danh sach rong! Vui long nhap thong tin !\n");
					    SetConsoleTextAttribute(hConsole, 7);
						break;
				}
				printf("Nhap Id cua phi hanh gia muon xoa: "); scanf("%s",&ID);
				deleter(l,ID);	
				break;
			}
			case 8:
			{
				char ID[30];
				if(l.head==NULL){
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("Danh sach rong! Vui long nhap thong tin !\n");
					    SetConsoleTextAttribute(hConsole, 7);
						break;
				}
				printf("Nhap ID phi hanh gia muon sua doi thong tin:"); scanf("%s",&ID);
				Node *p=l.head;
				while(p!=NULL){
					if(!strcmp(p->data.id,ID)){
						break;
					}
					p=p->next;
				}
				if(p==NULL){	
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("ID khong hop le!\n");	
					    SetConsoleTextAttribute(hConsole, 7);
				}
				else{
					fix(l,p);
				}
				break;
			}
			case 9:
			{
				if(l.head==NULL){
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("Danh sach rong! Vui long nhap thong tin !\n");
					    SetConsoleTextAttribute(hConsole, 7);
						break;
				}
				statictic(l);
				break;
			}
			case 10:
			{
				if(l.head==NULL){
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					    SetConsoleTextAttribute(hConsole, 14); 
						printf("Danh sach rong! Vui long nhap thong tin !\n");
					    SetConsoleTextAttribute(hConsole, 7);
						break;
				}
				printf("\nLuong Trung binh cua cac phi hanh gia la: %.2f ($)\n",averageSalary(l));
				break;
			}
			case 11:
			{
				
				OutputToFile(l);
				break;
			}
			case 12:
			{
				InputFromFile(l);
				
				break;
			}	
	}
}
//Hàm MENU tổng
void funtion(list &l,int &n){
	//	MENU INPUT
	bool switchOn1=1;
	int selectionn;
	while(switchOn1==1)	
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 10); 					
		fflush(stdin);		  
		printf("\n|=========================================INPUT SELECTION========================================|\n");
		printf("|\t\t\t\t1.Nhap thong tin tu ban phim            \t\t\t |\n");
		printf("|\t\t\t\t2.Nhap thong tin tu File                \t\t\t |\n");
		printf("|\t\t\t\t3.Chuyen den MENU              		 \t\t\t |\n");
		printf("|================================================================================================|\n");
		SetConsoleTextAttribute(hConsole, 7);
		printf("\t\t\t\tMoi nhap lua chon :"); scanf("%d",&selectionn);
		system("cls");
		fflush(stdin);
		printf("\n\n");
		if(selectionn==3){
			break;
		}
		switch(selectionn){
			case 1:
			{
				input(l,n);
				break;
			}
			case 2:
			{
				InputFromFile(l);
				break;
			}
		}
		break;
		
	}
	
	bool switchOn=1;
	int selection;
	while(switchOn==1)	
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12); 
		
		printf("\n|==============================DANH SACH CHUC NANG QUAN LY PHI HANH GIA==========================|\n");
		printf("|\t\t\t\t1.Xuat Danh Sach Phi Hanh Gia  \t\t\t\t\t |\n");
		printf("|\t\t\t\t2.Dem so phi hanh gia nam va nu\t\t\t\t\t |\n");
		printf("|\t\t\t\t3.Tim phi hanh gia co luong thang cao nhat\t\t\t |\n");
		printf("|\t\t\t\t4.Sap xep danh sach theo thu tu luong thang tang dan\t\t |\n");
		printf("|\t\t\t\t5.Tim thong tin cua phi hanh gia theo id\t\t\t |\n");
		printf("|\t\t\t\t6.Them thong tin cua mot phi hanh gia       \t\t\t |\n");
		printf("|\t\t\t\t7.Xoa thong tin mot phi hanh gia theo id\t\t\t |\n");
		printf("|\t\t\t\t8.Tim va sua thong tin cua phi hanh gia theo id     \t\t |\n");
		printf("|\t\t\t\t9.Thong ke do tuoi trung binh cua cac phi hanh gia  \t\t |\n");
		printf("|\t\t\t\t10.Tinh luong thang trung binh cua cac phi hanh gia \t\t |\n");
		printf("|\t\t\t\t11.Xuat du lieu vao FILE                            \t\t |\n");
		printf("|\t\t\t\t12.Nhap du lieu vao FILE                            \t\t |\n");
		printf("|\t\t\t\t13.Thoat(Exit)\t\t\t\t\t\t\t |\n");
		printf("|================================================================================================|\n");
		SetConsoleTextAttribute(hConsole, 7);
		printf("\t\t\t\tMoi nhap lua chon :"); scanf("%d",&selection);
		system("cls");
		printf("\n\n");
		if(selection==13){
			break;
		}
		implement(l,selection);
	}
		char space_x[] = 
        "\t\t\t\t\t  888888888   888888888       8        88888888   888888888               8       8               \n"
        "\t\t\t\t\t  8           8       8      8 8      8           8                        8     8                \n"
        "\t\t\t\t\t  8           8       8     8   8     8           8                         8   8                 \n"
        "\t\t\t\t\t  888888888   888888888    8888888    8           888888888   888888888      888                  \n"
        "\t\t\t\t\t          8   8           8       8   8           8                         8   8                 \n"
        "\t\t\t\t\t          8   8           8       8   8           8                        8     8                \n"
        "\t\t\t\t\t  888888888   8           8       8    88888888   888888888               8       8               \n\n\n";
        int delay=1000;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    while (!kbhit()) {
       
        printf("%s",space_x);
        printf("\n\n\t\t\t\t\t==================================CAM ON QUY KHACH=====================================");	
        Sleep(delay);
        system("cls");
        Sleep(100);
		
    }
   	SetConsoleTextAttribute(hConsole, 7);
	
}
//Hàm chính
int main(){

	char space_x[] = 
        "\t\t\t\t\t  888888888   888888888       8        88888888   888888888               8       8               \n"
        "\t\t\t\t\t  8           8       8      8 8      8           8                        8     8                \n"
        "\t\t\t\t\t  8           8       8     8   8     8           8                         8   8                 \n"
        "\t\t\t\t\t  888888888   888888888    8888888    8           888888888   888888888      888                  \n"
        "\t\t\t\t\t          8   8           8       8   8           8                         8   8                 \n"
        "\t\t\t\t\t          8   8           8       8   8           8                        8     8                \n"
        "\t\t\t\t\t  888888888   8           8       8    88888888   888888888               8       8               \n";
        int delay=1000,tam=5;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	while (!kbhit() && tam) {
        tam--;
        system("cls");
        printf("\t\t\t\t\t\t\t\t\t    BAI TAP LON\n");
		printf("\t\t\t\t\t\t    QUAN LY DANH SACH CAC PHI HANH GIA CUA HANG HANG KHONG VU TRU\n\n\n\n\n ");
		printf("%s",space_x);
        Sleep(delay);
        
        Sleep(100);
		
    }
    fflush(stdin);
    while (!kbhit()) {
		
    }
   	SetConsoleTextAttribute(hConsole, 7);
	int n;
	list l;
	createList(l);//Tao linklist
    
	system("cls");//Trình bày
	funtion(l,n);
	return 0;
}