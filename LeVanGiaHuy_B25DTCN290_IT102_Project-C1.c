#include <stdio.h>
#include <string.h>

// Cau truc phong
struct Room {
	char roomId[5];
	int type;
	double price;
	int status;
};

// Cau truc booking
struct Booking {
	char bookId[20];
	char roomId[5];
	char customerName[50];
	int day;
	double totalCost;
};

// Du lieu phong 
struct Room list[100] = {
	{"101",1,400000,1},
	{"102",2,750000,1},
	{"103",1,400000,1},
	{"104",2,750000,0},
	{"105",1,400000,1},
	{"106",2,750000,1},
	{"107",1,400000,1},
	{"201",2,750000,0},
	{"202",1,400000,1},
	{"203",2,750000,1},
	{"204",1,400000,1},
	{"205",2,750000,0},
	{"206",1,400000,1},
	{"207",2,750000,1},
	{"301",1,400000,1},
	{"302",2,750000,0},
	{"303",1,400000,1},
	{"304",2,750000,1},
	{"305",1,400000,1},
	{"306",2,750000,0},
};
int n = 20;

void display ();
void add_Room ();
void update_Room ();
void lock ();
void show_list (int n);

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
				show_list(n);
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
				printf ("Thoat chuong trinh");
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
    printf("+-------------------------------------------------+\n");
}

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

void update_Room () {
	char roomId[5];
	int flag = 0;
	while (1) {
		printf ("Nhap so phong can cap nhat: ");
		fgets (roomId,sizeof(roomId),stdin);
		roomId[strcspn(roomId,"\n")] = 0;
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

void lock () {
	char roomId[5];
	int flag = 0;
	printf ("Nhap so phong can cap nhat: ");
	fgets (roomId,sizeof(roomId),stdin);
	roomId[strcspn(roomId,"\n")] = 0;
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

void show_list (int n) {
	int page_number = 1;
    int page_size = 10;             
    int total_pages = (n + page_size - 1) / page_size;
    while (1) {
    	int start = (page_number-1)*page_size;
        int end = start + page_size;
        if (end > n) {
			end = n;
		}
    	printf("Trang %d/%d :\n\n", page_number, total_pages);
    	printf("+--------+---------+----------+----------+\n");
        printf("|%-8s|%-9s|%-10s|%-10s|\n", "So phong", "Loai phong","Gia phong","Trang thai");
        printf("+--------+---------+----------+----------+\n");
        for (int i = start; i < end ; i++) {
        	printf("|%-8s|%-9d|%-10.2lf|%-10d|\n", list[i].roomId, list[i].type, list[i].price, list[i].status);
		}
		printf("+--------+---------+----------+----------+\n");
		fflush(stdin);
		printf ("Ban co muon thoat chuong trinh khong (y/n): ");
		char charter = getchar();
		if (charter == 'y' || charter == 'Y') {
			break;
		}
	}
}

