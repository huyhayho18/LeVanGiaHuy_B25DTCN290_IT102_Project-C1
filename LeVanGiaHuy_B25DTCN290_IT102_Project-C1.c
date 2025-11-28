#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Cau truc phong
struct Room {
	char roomId[5];
	int type;
	double price;
	int status;
};
struct Date {
		int day;
		int month;
		int year;
	};

// Cau truc booking
struct Booking {
	char roomId[5];
	char customerName[50];
	int day;
	double totalCost;
	struct Date listdate;
	char bookId[20];
	
};


// Du lieu phong 
struct Room list[100] = {
	{"101",1,400000,1},
	{"102",2,750000,2},
	{"103",1,400000,1},
	{"104",2,750000,0},
	{"105",1,400000,1},
	{"106",2,750000,0},
	{"107",1,400000,1},
	{"201",2,750000,0},
	{"202",1,400000,1},
	{"203",2,750000,0},
	{"204",1,400000,1},
	{"205",2,750000,0},
	{"206",1,400000,1},
	{"207",2,750000,0},
	{"301",1,400000,1},
	{"302",2,750000,0},
	{"303",1,400000,1},
	{"304",2,750000,0},
	{"305",1,400000,1},
	{"306",2,750000,0},
};
int n = 20;

// Du lieu booking
struct Booking listbooking[100] = {
	{"104","Nguyen A", 3, 2250000, {11, 10, 2025}}
};
int size = 1;


// Nguyen mau ham
void display ();
void add_Room ();
void update_Room ();
void lock ();
void show_list ();
void search_room ();
void sort_room ();
void check_in ();
	int check_date (int day, int month, int year);
void history_booking ();

int main () {
	int choice;
	do {
		display();
		printf("Lua chon: ");
	    scanf("%d", &choice);
	    getchar();
		switch (choice) {
			case 1:
				add_Room();
				break;
			case 2:
				update_Room();
				break;
			case 3:
				lock();
				break;
			case 4:
				show_list();
				break;
			case 5:
				search_room ();
				break;
			case 6:
				sort_room ();
				break;
			case 7:
				check_in ();
				break;
			case 8:
				history_booking ();
				break;
			case 9:
				printf ("Thoat chuong trinh\n");
				break;
			default:
				printf ("Vui long nhap chuc nang tu 1 - 9\n");
				break;
		}
	} while ( choice != 9);
	
	
	return 0;
}

// Bang chuc nang
void display () {
	printf("+-----------------------MENU----------------------+\n");
    printf("|1. Them phong moi                                |\n");
    printf("|2. Cap nhat phong                                |\n");
    printf("|3. Bao tri phong                                 |\n");
    printf("|4. Hien thi danh sach phong                      |\n");
    printf("|5. Tim kiem phong                                |\n");
    printf("|6. Sap xep danh sach phong                       |\n");
    printf("|7. Check_in                                      |\n");
    printf("|8. Lich su thue                                  |\n");
    printf("|9. Thoat                                         |\n");
    printf("+-------------------------------------------------+\n");
}
// Them phong moi
void add_Room () {
	while(1) {
		printf ("Moi ban nhap phong muon them: \n\n");
		printf ("Nhap so phong: ");
		fgets (list[n].roomId,sizeof(list[n].roomId),stdin);
		list[n].roomId[strcspn(list[n].roomId, "\n")] = 0;
		if (strlen(list[n].roomId) == 0) {
			printf ("Loi: So phong khong duoc de trong\n");
			continue;
		}
		int valid = 1;
		for (int i = 0; i < n;i++) {
			if (strcmp(list[i].roomId,list[n].roomId) == 0) {
				printf ("Loi: Phong[%s] da ton tai\n",list[i].roomId);
				valid = 0;
			}
		}
		if (valid == 0) {
			continue;
		}
		break;
	}
	while (1) {
		printf ("Nhap loai phong(1:Don, 2:Doi): ");
		scanf ("%d",&list[n].type);
		getchar();
		if (list[n].type != 1 && list[n].type != 2) {
			printf ("Loi: Loai phong chi duoc chon 1(Don) hoac 2(Doi)\n");
			continue;
		}
		break;
	}
	while (1) {
		printf ("Nhap gia phong: ");
		scanf ("%lf",&list[n].price);
		getchar();
		if (list[n].price <= 0) {
			printf ("Loi gia phong lon hon 0!\n");
			continue;
		}
		break;
	}
	list[n].status = 0;
	printf ("Them phong thanh cong! Phong [%s] da duoc tao voi trang thai rong\n",list[n-1].roomId);
	n++;
};
//cap nhat cac thong tin cua phong
void update_Room () {
	char roomId[5];
	int flag = 0;
	while (1) {
		printf ("Nhap so phong can cap nhat: ");
		fgets (roomId,sizeof(roomId),stdin);
		roomId[strcspn(roomId,"\n")] = 0;
		if (strlen(roomId) == 0) {
			printf ("Loi: So phong khong duoc de trong\n");
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (strcmp(list[i].roomId,roomId) == 0) {
				printf ("So phong: %s\n",list[i].roomId);
				printf ("Loai phong(1:Don, 2:Doi): %d\n",list[i].type);
				printf ("Gia Phong: %lf\n",list[i].price);
				printf ("Trang thai(0:Trong, 1:Dang o, 2:Bao tri): %d\n\n",list[i].status);
				flag = 1;
				while (1) {
					printf ("Nhap loai phong moi: ");
					scanf ("%d",&list[i].type);
					getchar();
					if (list[i].type != 1 && list[i].type != 2) {
						printf ("Loi: Loai phong chi duoc chon 1(Don) hoac 2(Doi)\n");
						continue;
					}
					break;
				}
				while (1) {
					printf ("Nhap gia phong moi: ");
					scanf ("%lf",&list[i].price);
					getchar();
					if (list[i].price <= 0) {
						printf ("Loi gia phong lon hon 0!\n");
						continue;
					}
					break;
				}
				printf ("Cap nhat thong tin phong [%s] thanh cong\n",roomId);
				return;
			}
		}
		if (flag == 0) {
			printf ("Loi: Khong tim thay phong [%s]!\n",roomId);
		}
	}
}
// bao tri phong
void lock () {
	char roomId[5];
	int flag = 0;
	while (1) {
		printf ("Nhap so phong can bao tri: ");
		fgets (roomId,sizeof(roomId),stdin);
		roomId[strcspn(roomId,"\n")] = 0;
		if (strlen(roomId) == 0) {
			printf ("Loi: So phong khong duoc de trong\n");
			continue;
		}
		break;
	}
	for (int i = 0; i < n; i ++) {
		if (strcmp(list[i].roomId, roomId) == 0) {
			if (list[i].status != 1) {
				list[i].status = 2;
			} else {
				printf ("Loi: Phong [%s] dang co khach, khong the dua vao bao tri!\n",roomId);
				return;
			}
		flag = 1;
		}
	}
	if (flag == 0) {
		printf ("Loi: Khong tim thay phong [%s]!\n",roomId);
		return;
	}
	printf ("Da dua phong [%s] vao trang thai Bao tri thanh cong!\n",roomId);
}
// hien thi danh sach phong (phan trang)
void show_list () {
	if (n == 0) {
		printf ("Danh sach phong hien tai trong! Vui long them phong truoc");
	} 
	int page_number = 1;
    int page_size = 10;   
	int result = n / page_size; 
	// tong so trang         
    int total_pages = (n % page_size == 0) ? result : result + 1;
    while (1) {
    	printf("Moi ban chon so trang can xem (1-%d) : ", total_pages);
        scanf("%d", &page_number);
        // bat sau va ket thuc
    	int start = (page_number-1)*page_size;
        int end = start + page_size;
    	printf("Trang %d/%d :\n\n", page_number, total_pages);
    	printf("+--------+-------------------------+--------------------+-----------+\n");
		printf("|%-5s|%-25s|%-20s|%-11s|\n", "So phong", "Loai phong","Gia phong","Trang thai");
		printf("+--------+-------------------------+--------------------+-----------+\n");
        for (int i = start; i < end && i < n; i++) {
        	printf("|%8s|%25d|%16.0lf VND|%11d|\n", list[i].roomId, list[i].type, list[i].price, list[i].status);
		}
		printf("+--------+-------------------------+--------------------+-----------+\n");
		getchar();
		printf ("Ban co muon thoat chuong trinh khong (y/n): ");
		char charter = getchar();
		// neu chon y thi thoat chuong trinh
		if (charter == 'y' || charter == 'Y') {
			break;
		}
	}
}
// Tim kiem phong trong
void search_room () {
	int copyType;
	int flag = 0;
	while (copyType != 1 && copyType != 2) {
		printf ("Nhap loai phong muon tim (1:Don, 2:Doi): ");
		scanf ("%d",&copyType);
		getchar();
		if (copyType != 1 && copyType != 2) {
			printf ("Loi: Vui long chon 1:Don hoac 2:Doi!\n");
		}
	}
	for (int i = 0; i < n; i++) {
		if (copyType == list[i].type && list[i].status == 0) {
			flag = 1;
		}
	}
	if (flag == 0) {
		printf ("Hien tai khong co phong trong loai[Don/Doi]\n");
		return;	
	}
	printf("+--------+-------------------------+--------------------+-----------+\n");
	printf("|%-5s|%-25s|%-20s|%-11s|\n", "So phong", "Loai phong","Gia phong","Trang thai");
	printf("+--------+-------------------------+--------------------+-----------+\n");
	for(int i = 0; i < n; i++){
		if(list[i].type == copyType && list[i].status == 0){
			printf("|%-8s|%-25d|%16.0lf VND|%-11d|\n", list[i].roomId, list[i].type, list[i].price, list[i].status);
		}
	}
	printf("+--------+-------------------------+--------------------+-----------+\n");
}
// sap xep gia phong giam dan
void sort_room () {
	if (n == 0) {
		printf ("Danh sach trong khong can sap xep");
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n -i - 1; j++) {
			if (list[j].price < list[j+1].price) {
				// sap xep gia
				int temp01 = list[j].price;
				int temp02 = list[j].status;
				int temp03 = list[j].type;
				char temp04[5];
				strcpy(temp04,list[j].roomId);
				
				list[j].price = list[j+1].price;
				list[j].status = list[j+1].status;
				list[j].type = list[j+1].type;
				strcpy(list[j].roomId,list[j+1].roomId);
				
				list[j+1].price = temp01;
				list[j+1].status = temp02;
				list[j+1].type = temp03;
				strcpy(list[j+1].roomId,temp04) ;
			}
		}
	}
	printf ("Da sap xep danh sach giam dan thanh cong\n");
	show_list ();
}

// Check in phong
void check_in () {
	int flag = 0;
	while (1) {
		int valid = 1;
		flag = 0;
		printf ("Nhap so phong muon dat: ");
		fgets (listbooking[size].roomId, sizeof(listbooking[size].roomId), stdin);
		listbooking[size].roomId[strcspn(listbooking[size].roomId,"\n")] = 0;
		if (strlen(listbooking[size].roomId) == 0) {
			printf ("Loi: So phong khong duoc de trong\n");
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (strcmp(listbooking[size].roomId,list[i].roomId) == 0){
				flag = 1;
				if (list[i].status == 1) {
					printf ("Loi: Phong [%s] da co khach!\n",list[i].roomId);
					valid = 0;
					break;
				}	
				if (list[i].status == 2) {
					printf ("Loi: Phong [%s] dang bao tri!\n",list[i].roomId);
					valid = 0;
					break;
				}
				list[i].status = 1;
				break;	
			}
		}
		if (flag == 0) {
			printf ("Loi: Khong tim thay phong [%s]\n",listbooking[size].roomId);
			valid = 0;
			}
		if (valid == 1) {
			break;
		}
	}
	while (1) {
		printf ("Nhap ten khach hang: ");
		fgets (listbooking[size].customerName, sizeof (listbooking[size].customerName), stdin);
		listbooking[size].customerName[strcspn(listbooking[size].customerName, "\n")] = 0;
		if (strlen(listbooking[size].customerName) == 0) {
			printf ("Loi: So phong khong duoc de trong\n");
			continue;
		}
		break;
	}
	while (1) {
		printf ("Nhap so ngay o: ");
		scanf ("%d",&listbooking[size].day);
		getchar();
		if (listbooking[size].day <= 0) {
			printf ("Loi: So ngay o phai lon hon 0!\n");
			continue;
		}
		break;
	}
	while (1) {
		printf ("Nhap ngay nhan phong (DD/MM/YYYY): ");
		scanf ("%d/%d/%d", &listbooking[size].listdate.day, &listbooking[size].listdate.month, &listbooking[size].listdate.year);
		getchar();
		if (check_date (listbooking[size].listdate.day, listbooking[size].listdate.month, listbooking[size].listdate.year) == 1) {
			break;
		}
	}
	sprintf(listbooking[size].bookId,"%d",rand() % 10000);      //in ra ngau nhien ma phong
	printf ("Check in thanh cong! Ma dat phong [%d]\n",listbooking[size].bookId);
	for (int i = 0; i < n; i++) {
		if (strcmp(listbooking[size].roomId,list[i].roomId) == 0) {
			listbooking[size].totalCost = list[i].price * listbooking[size].day;
		}
	}
	printf ("+----------+-------------------------+------------+----------+---------------+\n"); // 10  25  12  10  15
	printf ("|%-10s|%-25s|%-12s|%-10s|%-15s|\n","So phong","Ten khach hang","Ngay nhan","So ngay","Tong tien");
	printf ("+----------+-------------------------+------------+----------+---------------+\n");
	printf ("|%10s|%25s|%4d/%d/%d|%10d|%11.0lf VND|\n",listbooking[size].roomId,listbooking[size].customerName,listbooking[size].listdate.day,listbooking[size].listdate.month,listbooking[size].listdate.year,listbooking[size].day,listbooking[size].totalCost);
	printf ("+----------+-------------------------+------------+----------+---------------+\n");
	size ++;
}

// kiem tra ngay thang nam cua case 7
int check_date (int day, int month, int year) {
	
	if (year < 2025) {
		printf ("Loi: Ngay nhan phong phai dung dinh dang DD/MM/YYYY!\n");
		return 0;
	}
	if (year = 2025 && month <= 11 && day < 28) {
		printf ("Loi: Ngay nhan phong phai dung dinh dang DD/MM/YYYY!\n");
		return 0;
	}
	if (month < 1 || month > 12) {
		printf ("Loi: Ngay nhan phong phai dung dinh dang DD/MM/YYYY!\n");
		return 0;
	}
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day > 31 || day < 1) {
				printf ("Loi: Ngay nhan phong phai dung dinh dang DD/MM/YYYY!\n");
				return 0;
			}
			break;
		case 4: 
		case 6: 
		case 9: 
		case 11:
			if (day > 30 || day < 1) {
				printf ("Loi: Ngay nhan phong phai dung dinh dang DD/MM/YYYY!\n");
				return 0;
			}
			break;
		case 2:
			if (year % 4 == 0&&year % 100 != 0 || year % 400 == 0) {  // kiem tra nam nhuan
				if (day > 29 || day < 1) {
					printf ("Loi: Ngay nhan phong phai dung dinh dang DD/MM/YYYY!\n");
					return 0;
				}
			} else {
				if (day > 28 || day < 1) {
					printf ("Loi: Ngay nhan phong phai dung dinh dang DD/MM/YYYY!\n");
					return 0;
				}
			}		
			break;
	}
	return 1;
}

// Lich su check in
void history_booking () {
	char roomId[5];
	int flag = 0;
	int found = 0;
	while (1) {
		flag = 0;
		printf ("Nhap so phong muon kiem tra lich su: ");
		fgets (roomId, sizeof(roomId),stdin);
		roomId[strcspn(roomId, "\n")] = 0;
		if (strlen(roomId) == 0) {
			printf ("Loi: So phong khong duoc de trong\n");
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (strcmp(list[i].roomId, roomId) == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			printf ("Loi: Khong tim thay phong [%s]\n",roomId);
			continue;
		}
		for (int j = 0; j < size; j++) {
			if (strcmp(listbooking[j].roomId, roomId) == 0) {
				if (found == 0) {
					printf ("+---+----------+-------------------------+------------+----------+---------------+\n"); // 10  25  12  10  15
					printf ("|%-3s|%-10s|%-25s|%-12s|%-10s|%-15s|\n","STT","So phong","Ten khach hang","Ngay nhan","So ngay","Tong tien");
					printf ("+---+----------+-------------------------+------------+----------+---------------+\n");
				}
				found = 1;
				printf ("|%-3d|%10s|%25s|%4d/%d/%d|%10d|%11.0lf VND|\n",j+1,listbooking[j].roomId,listbooking[j].customerName,listbooking[j].listdate.day,listbooking[j].listdate.month,listbooking[j].listdate.year,listbooking[j].day,listbooking[j].totalCost);
				printf ("+---+----------+-------------------------+------------+----------+---------------+\n");
				break;
			}
		}
		if (found == 0) {
			printf ("Phong [%s] chua tung co khach thue!\n",roomId);
			continue;
		}
		break;
	}
}
