#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char user[50], pass[50];
} data[100];
int n = 0;

char* cariPass(char *u) {
    for (int i = 0; i < n; i++)
        if (!strcmp(data[i].user, u)) return data[i].pass;
    return NULL;
}

void tambah() {
    printf("User: "); scanf("%s", data[n].user);
    printf("Pass: "); scanf("%s", data[n++].pass);
}

void hapus() {
    char u[50];
    printf("Hapus user: "); scanf("%s", u);
    for (int i = 0; i < n; i++)
        if (!strcmp(data[i].user, u)) {
            for (int j = i; j < n - 1; j++) data[j] = data[j + 1];
            n--; printf("Berhasil dihapus!\n"); return;
        }
    printf("User tidak ditemukan!\n");
}

void list() {
    printf("\nDaftar Mahasiswa:\n");
    for (int i = 0; i < n; i++) printf("%d. %s\n", i + 1, data[i].user);
    if (n == 0) printf("(Belum ada data)\n");
}

void menu() {
    int c;
    do {
        printf("\n1. Tambah\n2. Hapus\n3. List\n4. Keluar\n> ");
        scanf("%d", &c);
        if (c == 1) tambah();
        else if (c == 2) hapus();
        else if (c == 3) list();
    } while (c != 4);
}

int main() {
    struct Mahasiswa m; 
    printf("=== Daftar Awal ===\n");
    tambah(); 

    for (int i = 0; i < 3; i++) {
        printf("\n// Portal MyITS Mahasiswa //\nUser: ");
        scanf("%s", m.user);
        printf("Pass: "); scanf("%s", m.pass);
        char *pw = cariPass(m.user);
        if (pw && !strcmp(pw, m.pass)) {
            printf("\nLogin berhasil!\n");
            menu();
            return 0;
        } else printf("Login salah (%d/3)\n", i + 1);
    }

    printf("\nAnda diblokir!\n");
}
