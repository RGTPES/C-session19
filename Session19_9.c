#include <stdio.h>
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} SinhVien;

void hienThiDanhSach(SinhVien arr[], int n) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("%d, %s, %d, %s\n", arr[i].id, arr[i].name, arr[i].age, arr[i].phoneNumber);
    }
}
void themSinhVien(SinhVien arr[], int *n) {
    SinhVien sv;
    printf("\nNhap ID: ");
    scanf("%d", &sv.id);
    printf("Nhap ten: ");
    getchar(); 
    fgets(sv.name, 50, stdin);
    printf("Nhap tuoi: ");
    scanf("%d", &sv.age);
    printf("Nhap so dien thoai: ");
    scanf("%s", sv.phoneNumber);
    arr[(*n)++] = sv;
    printf("\nDa them sinh vien thanh cong!\n");
}
void suaSinhVien(SinhVien arr[], int n) {
    int id;
    printf("\nNhap ID sinh vien can sua: ");
    scanf("%d", &id);
    for (int i = 0; i < n; i++) {
        if (arr[i].id == id) {
            printf("Nhap ten moi: ");
            getchar();
            fgets(arr[i].name, 50, stdin);
            arr[i].name[strcspn(arr[i].name, "\n")] = '\0';
            printf("Nhap tuoi moi: ");
            scanf("%d", &arr[i].age);
            printf("Nhap so dien thoai moi: ");
            scanf("%s", arr[i].phoneNumber);
            printf("\nDa cap nhat thong tin sinh vien!\n");
            return;
        }
    }
    printf("\nKhong tim thay sinh vien voi ID da nhap!\n");
}
void xoaSinhVien(SinhVien arr[], int *n) {
    int id;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    for (int i = 0; i < *n; i++) {
        if (arr[i].id == id) {
            for (int j = i; j < *n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*n)--;
            printf("\nDa xoa sinh vien thanh cong!\n");
            return;
        }
    }
    printf("\nKhong tim thay sinh vien voi ID da nhap!\n");
}
void timKiemSinhVien(SinhVien arr[], int n) {
    int id;
    printf("\nNhap ID sinh vien can tim: ");
    scanf("%d", &id);
    for (int i = 0; i < n; i++) {
        if (arr[i].id == id) {
            printf("\nThong tin sinh vien:\n");
            printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", arr[i].id, arr[i].name, arr[i].age, arr[i].phoneNumber);
            return;
        }
    }
    printf("\nKhong tim thay sinh vien voi ID da nhap!\n");
}
void sapXepSinhVienTheoTen(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i].name, arr[j].name) > 0) {
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nDanh sach da duoc sap xep theo ten!\n");
}

int main() {
	SinhVien sv[5]={
	{
		1, "Nguyen Van a", 18, "0332200001"
	}, 
	{
		2, "Nguyen Van b", 19, "0332200002"
	},
	{
		3, "Nguyen Van c", 20, "0332200003"
	},
	{
		4, "Nguyen Van d", 21, "0332200004"
	},
	{
		5, "Nguyen Van e", 22, "0332200005"
	},
	
	};
    int soLuong = 5;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                hienThiDanhSach(sv, soLuong);
                break;
            case 2:
                themSinhVien(sv, &soLuong);
                break;
            case 3:
                suaSinhVien(sv, soLuong);
                break;
            case 4:
                xoaSinhVien(sv, &soLuong);
                break;
            case 5:
                timKiemSinhVien(sv, soLuong);
                break;
            case 6:
                sapXepSinhVienTheoTen(sv, soLuong);
                break;
            case 7:
                
                break;
            default:
                printf("\nLua chon khong hop le. Vui long thu lai!\n");
        }
    } while (luaChon != 7);

    return 0;
}
