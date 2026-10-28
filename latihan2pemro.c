#include <stdio.h>
#include <string.h>

typedef struct {
    int kode_menu;
    char nama_menu[50];
    char kategori[20];
    float harga;
} Menu;

typedef struct {
    int id_pegawai;
    char nama_pegawai[50];
    char jabatan[30];
    float gaji;
} Pegawai;

void tampilMenu(Menu m);
void tampilPegawai(Pegawai p);
void updateMenu(Menu *m, char nama[], float harga);
void updatePegawai(Pegawai *p, char nama[], char jabatan[], float gaji);

int main() {

    // 5 makanan + 3 minuman
    Menu daftar_menu[8] = {
        {1, "Nasi Goreng", "Makanan", 25000},
        {2, "Mie Ayam", "Makanan", 20000},
        {3, "Sate Ayam", "Makanan", 30000},
        {4, "Ayam Bakar", "Makanan", 35000},
        {5, "Soto Betawi", "Makanan", 28000},
        {6, "Es Teh Manis", "Minuman", 8000},
        {7, "Jus Jeruk", "Minuman", 15000},
        {8, "Kopi Susu", "Minuman", 18000}
    };

    // 2 pegawai
    Pegawai daftar_pegawai[2] = {
        {101, "Budi Santoso", "Koki", 4500000},
        {102, "Siti Rahma", "Kasir", 3800000}
    };

    int pilihan, nomor;
    char nama[50], jabatan[30];
    float harga, gaji;

    do {
        printf("\n=== APLIKASI RESTORAN ===\n");
        printf("1. Tampilkan menu\n");
        printf("2. Tampilkan pegawai\n");
        printf("3. Ubah menu\n");
        printf("4. Ubah pegawai\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            for (int i = 0; i < 8; i++) {
                tampilMenu(daftar_menu[i]);
            }
        }
        else if (pilihan == 2) {
            for (int i = 0; i < 2; i++) {
                tampilPegawai(daftar_pegawai[i]);
            }
        }
        else if (pilihan == 3) {
            printf("Nomor menu yang diubah (1-8): ");
            scanf("%d", &nomor);
            getchar();  // membuang Enter setelah input angka

            if (nomor < 1 || nomor > 8) {
                printf("Nomor menu tidak tersedia.\n");
            }
            else {
                printf("Nama baru : ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                printf("Harga baru: ");
                scanf("%f", &harga);

                updateMenu(&daftar_menu[nomor - 1], nama, harga);
                printf("Menu berhasil diubah.\n");
            }
        }
        else if (pilihan == 4) {
            printf("Nomor pegawai yang diubah (1-2): ");
            scanf("%d", &nomor);
            getchar();  // membuang Enter setelah input angka

            if (nomor < 1 || nomor > 2) {
                printf("Nomor pegawai tidak tersedia.\n");
            }
            else {
                printf("Nama baru   : ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                printf("Jabatan baru: ");
                fgets(jabatan, sizeof(jabatan), stdin);
                jabatan[strcspn(jabatan, "\n")] = 0;
                printf("Gaji baru   : ");
                scanf("%f", &gaji);

                updatePegawai(&daftar_pegawai[nomor - 1], nama, jabatan, gaji);
                printf("Data pegawai berhasil diubah.\n");
            }
        }
        else if (pilihan != 0) {
            printf("Pilihan tidak tersedia.\n");
        }
    } while (pilihan != 0);

    printf("Program selesai.\n");
    return 0;
}

// Pass by value: hanya menampilkan
void tampilMenu(Menu m) {
    printf("%d. %-15s %-8s Rp %.0f\n", m.kode_menu, m.nama_menu, m.kategori, m.harga);
}

void tampilPegawai(Pegawai p) {
    printf("%d. %-15s %-8s Rp %.0f\n", p.id_pegawai, p.nama_pegawai, p.jabatan, p.gaji);
}

// Pass by reference: mengubah data asli
void updateMenu(Menu *m, char nama[], float harga) {
    strcpy(m->nama_menu, nama);
    m->harga = harga;
}

void updatePegawai(Pegawai *p, char nama[], char jabatan[], float gaji) {
    strcpy(p->nama_pegawai, nama);
    strcpy(p->jabatan, jabatan);
    p->gaji = gaji;
}