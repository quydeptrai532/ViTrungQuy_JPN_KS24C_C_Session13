#include <stdio.h>

#define MAX 100

int laSoNguyenTo(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void nhapMang(int n, int m, int mang[MAX][MAX]) {
    printf("Nhap gia tri cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("mang[%d][%d] = ", i, j);
            scanf("%d", &mang[i][j]);
        }
    }
}

void inMang(int n, int m, int mang[MAX][MAX]) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mang[i][j]);
        }
        printf("\n");
    }
}

void inGoc(int n, int m, int mang[MAX][MAX]) {
    printf("Cac phan tu o goc:\n");
    printf("%d %d\n", mang[0][0], mang[0][m - 1]);
    printf("%d %d\n", mang[n - 1][0], mang[n - 1][m - 1]);
}

void inDuongBien(int n, int m, int mang[MAX][MAX]) {
    printf("Cac phan tu nam tren duong bien:\n");
    for (int j = 0; j < m; j++) printf("%d ", mang[0][j]);
    for (int i = 1; i < n - 1; i++) {
        printf("%d %d ", mang[i][0], mang[i][m - 1]);
    }
    for (int j = 0; j < m; j++) printf("%d ", mang[n - 1][j]);
    printf("\n");
}

void inCheo(int n, int m, int mang[MAX][MAX]) {
    printf("Cac phan tu tren duong cheo chinh va cheo phu:\n");
    if (n == m) {
        for (int i = 0; i < n; i++) {
            printf("%d ", mang[i][i]);
            if (i != n - 1 - i) {
                printf("%d ", mang[i][n - 1 - i]);
            }
        }
        printf("\n");
    } else {
        printf("Ma tran khong vuong, khong co duong cheo hop le.\n");
    }
}

void inSoNguyenTo(int n, int m, int mang[MAX][MAX]) {
    printf("Cac phan tu la so nguyen to:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (laSoNguyenTo(mang[i][j])) {
                printf("%d ", mang[i][j]);
            }
        }
    }
    printf("\n");
}

void inMenu() {
    printf("\nMENU\n");
    printf("1. Nhap gia tri cac phan tu cua mang\n");
    printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
    printf("3. In ra cac phan tu o goc theo ma tran\n");
    printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
    printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
    printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
    printf("7. Thoat\n");
}

int main() {
    int n, m;
    int mang[MAX][MAX];

    do {
        printf("Nhap so hang n (1 <= n <= %d): ", MAX);
        scanf("%d", &n);
    } while (n <= 0 || n > MAX);

    do {
        printf("Nhap so cot m (1 <= m <= %d): ", MAX);
        scanf("%d", &m);
    } while (m <= 0 || m > MAX);

    int luaChon;

    do {
        inMenu();
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(n, m, mang);
                break;
            case 2:
                inMang(n, m, mang);
                break;
            case 3:
                inGoc(n, m, mang);
                break;
            case 4:
                inDuongBien(n, m, mang);
                break;
            case 5:
                inCheo(n, m, mang);
                break;
            case 6:
                inSoNguyenTo(n, m, mang);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (luaChon != 7);

    return 0;
}

