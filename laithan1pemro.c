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

int main() {

    Menu menu_01;
    Menu menu_02;
    Pegawai pegawai_01;

    menu_01.kode_menu = 1;
    strcpy(menu_01.nama_menu, "Nasi Goreng");
    strcpy(menu_01.kategori, "Makanan");
    menu_01.harga = 25000;

    menu_02.kode_menu = 2;
    strcpy(menu_02.nama_menu, "Es Teh Manis");
    strcpy(menu_02.kategori, "Minuman");
    menu_02.harga = 8000;

    pegawai_01.id_pegawai = 101;
    strcpy(pegawai_01.nama_pegawai, "Budi Santoso");
    strcpy(pegawai_01.jabatan, "Koki");
    pegawai_01.gaji = 4500000;

    printf("=== DATA MENU ===\n");
    tampilMenu(menu_01);
    tampilMenu(menu_02);

    printf("\n=== DATA PEGAWAI ===\n");
    tampilPegawai(pegawai_01);

    return 0;
}

void tampilMenu(Menu m) {
    printf("Kode     : %d\n", m.kode_menu);
    printf("Nama     : %s\n", m.nama_menu);
    printf("Kategori : %s\n", m.kategori);
    printf("Harga    : Rp %.0f\n\n", m.harga);
}

void tampilPegawai(Pegawai p) {
    printf("ID       : %d\n", p.id_pegawai);
    printf("Nama     : %s\n", p.nama_pegawai);
    printf("Jabatan  : %s\n", p.jabatan);
    printf("Gaji     : Rp %.0f\n", p.gaji);
}