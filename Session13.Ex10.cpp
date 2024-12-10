#include <stdio.h>

#define MAX 100

void nhapMang(int *mang, int *n) {
    printf("Nhap so phan tu can quan ly: ");
    scanf("%d", n);
    if (*n > MAX || *n < 1) {
        printf("So phan tu khong hop le. Vui long nhap lai.\n");
        *n = 0;
        return;
    }
    printf("Nhap gia tri cac phan tu:\n");
    for (int i = 0; i < *n; i++) {
        printf("mang[%d] = ", i);
        scanf("%d", &mang[i]);
    }
}

void inMang(int *mang, int n) {
    if (n == 0) {
        printf("Mang rong.\n");
        return;
    }
    printf("Cac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
}

void themPhanTu(int *mang, int *n) {
    if (*n >= MAX) {
        printf("Mang da day, khong the them phan tu moi.\n");
        return;
    }
    int viTri, giaTri;
    printf("Nhap vi tri can them (0 <= vi tri <= %d): ", *n);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri > *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap gia tri can them: ");
    scanf("%d", &giaTri);
    for (int i = *n; i > viTri; i--) {
        mang[i] = mang[i - 1];
    }
    mang[viTri] = giaTri;
    (*n)++;
    printf("Da them thanh cong.\n");
}

void suaPhanTu(int *mang, int n) {
    int viTri, giaTri;
    printf("Nhap vi tri can sua (0 <= vi tri < %d): ", n);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri >= n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap gia tri moi: ");
    scanf("%d", &giaTri);
    mang[viTri] = giaTri;
    printf("Da sua thanh cong.\n");
}

void xoaPhanTu(int *mang, int *n) {
    if (*n == 0) {
        printf("Mang rong, khong the xoa.\n");
        return;
    }
    int viTri;
    printf("Nhap vi tri can xoa (0 <= vi tri < %d): ", *n);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri >= *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = viTri; i < *n - 1; i++) {
        mang[i] = mang[i + 1];
    }
    (*n)--;
    printf("Da xoa thanh cong.\n");
}

void sapXepMang(int *mang, int n, int tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && mang[i] > mang[j]) || (!tangDan && mang[i] < mang[j])) {
                int temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
    printf("Da sap xep thanh cong.\n");
}

void timKiemTuyenTinh(int *mang, int n) {
    int giaTri, found = 0;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &giaTri);
    for (int i = 0; i < n; i++) {
        if (mang[i] == giaTri) {
            printf("Tim thay tai vi tri: %d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay gia tri trong mang.\n");
    }
}

void timKiemNhiPhan(int *mang, int n) {
    int giaTri;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &giaTri);
    int left = 0, right = n - 1, found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (mang[mid] == giaTri) {
            printf("Tim thay tai vi tri: %d\n", mid);
            found = 1;
            break;
        } else if (mang[mid] < giaTri) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("Khong tim thay gia tri trong mang.\n");
    }
}

void menuSapXep(int *mang, int n) {
    char luaChon;
    printf("a. Sap xep giam dan\n");
    printf("b. Sap xep tang dan\n");
    printf("Nhap lua chon: ");
    scanf(" %c", &luaChon);
    if (luaChon == 'a') {
        sapXepMang(mang, n, 0);
    } else if (luaChon == 'b') {
        sapXepMang(mang, n, 1);
    } else {
        printf("Lua chon khong hop le.\n");
    }
}

void menuTimKiem(int *mang, int n) {
    char luaChon;
    printf("a. Tim kiem tuyen tinh\n");
    printf("b. Tim kiem nhi phan\n");
    printf("Nhap lua chon: ");
    scanf(" %c", &luaChon);
    if (luaChon == 'a') {
        timKiemTuyenTinh(mang, n);
    } else if (luaChon == 'b') {
        timKiemNhiPhan(mang, n);
    } else {
        printf("Lua chon khong hop le.\n");
    }
}

int main() {
    int mang[MAX], n = 0, luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(mang, &n);
                break;
            case 2:
                inMang(mang, n);
                break;
            case 3:
                themPhanTu(mang, &n);
                break;
            case 4:
                suaPhanTu(mang, n);
                break;
            case 5:
                xoaPhanTu(mang, &n);
                break;
            case 6:
                menuSapXep(mang, n);
                break;
            case 7:
                menuTimKiem(mang, n);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 8);

    return 0;
}

