#include <iostream>
#include <vector>
using namespace std;

struct Peralatan {
  string nama;
  vector<string> ukuran;
  vector<long> harga;
};

vector<Peralatan> daftarPeralatan{
  {
    "Tenda",
    {"Kecil", "Sedang", "Besar"},
    {25000, 35000,45000},
  },
  {
    "Tas Cerier",
    {"Kecil", "Sedang", "Besar"},
    {15000,20000, 25000},
  },
  {
    "Flysheet",
    {"Kecil", "Sedang", "Besar"},
    {10000, 15000,20000},
  },
};

void tampilkanDetailPeralatan(Peralatan peralatan) {
  int ukuranBarang, jumlahBarang;

  cout << "==== Detail Barang ====\n\n";
  cout << "Nama barang\t:\t" << peralatan.nama << "\n";
  cout << "Ukuran & harga\t: ";
  for (int i = 0; i < peralatan.ukuran.size(); i++) {
    cout << (i == 0 ? "\t" : "\t\t\t") << i + 1 << ". " << peralatan.ukuran[i] << " : " << peralatan.harga[i] <<"\n";
  }

  cout << "Pilih ukuran : ";
  cin >> ukuranBarang;

  if (ukuranBarang > 0  && ukuranBarang <= peralatan.ukuran.size()) {
    cout << "Masukkan jumlah : ";
    cin >> jumlahBarang;

    if (jumlahBarang > 0) {
      cout << "Total harga : Rp " << jumlahBarang * peralatan.harga[ukuranBarang - 1];
    } else {
      cout << "Masukkan jumlah barang dengan benar!";
    }
  } else {
    cout << "Tidak ada pilihan ukuran barang!";
  }
};

int main() {
  int NomorBarang;

  cout << "================ Sewa Peralatan Outdoor ================\n\n";
  for (int i = 0; i < daftarPeralatan.size() ; ++i) {
    cout << i + 1 << ". " << daftarPeralatan[i].nama << "\n";
  }

  cout << "\n\nPilih barang (1 - " << daftarPeralatan.size() << ") : ";
  cin >> NomorBarang;

  system("cls");

  if (NomorBarang > 0  && NomorBarang <= daftarPeralatan.size()) {
    tampilkanDetailPeralatan(daftarPeralatan[NomorBarang - 1]);
  } else {
    cout << "Tidak ada pilihan barang!";
  }
}