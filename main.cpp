#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Produk {
    int id;
    string nama;
    string kategori;
    double berat;
    string status_kualitas; // "Baik" atau "Rusak"
};

class SistemPengawasan {
private:
    vector<Produk> daftarProduk;

public:
    void tambahProduk(int id, const string& nama, const string& kategori, double berat, const string& status_kualitas) {
        Produk produk = {id, nama, kategori, berat, status_kualitas};
        daftarProduk.push_back(produk);
        cout << "Produk dengan ID " << id << " berhasil ditambahkan." << endl;
    }

    void tampilkanProduk() {
        if (daftarProduk.empty()) {
            cout << "Tidak ada data produk." << endl;
            return;
        }

        cout << "\nDaftar Produk:\n";
        cout << "ID\tNama\tKategori\tBerat(kg)\tStatus\n";
        cout << "---------------------------------------------\n";
        for (const auto& produk : daftarProduk) {
            cout << produk.id << "\t" << produk.nama << "\t" << produk.kategori << "\t" << produk.berat << "\t" << produk.status_kualitas << endl;
        }
    }

    void cekKualitas(int id) {
        for (auto& produk : daftarProduk) {
            if (produk.id == id) {
                cout << "Produk ID: " << id << " memiliki status kualitas: " << produk.status_kualitas << endl;
                return;
            }
        }
        cout << "Produk dengan ID " << id << " tidak ditemukan." << endl;
    }
};

int main() {
    SistemPengawasan sistem;
    int pilihan;

    do {
        cout << "\nSistem Pengawasan Produk\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Tampilkan Semua Produk\n";
        cout << "3. Cek Kualitas Produk\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int id;
                string nama, kategori, status_kualitas;
                double berat;

                cout << "Masukkan ID Produk: ";
                cin >> id;
                cin.ignore();
                cout << "Masukkan Nama Produk: ";
                getline(cin, nama);
                cout << "Masukkan Kategori Produk: ";
                getline(cin, kategori);
                cout << "Masukkan Berat Produk (kg): ";
                cin >> berat;
                cin.ignore();
                cout << "Masukkan Status Kualitas (Baik/Rusak): ";
                getline(cin, status_kualitas);

                sistem.tambahProduk(id, nama, kategori, berat, status_kualitas);
                break;
            }
            case 2:
                sistem.tampilkanProduk();
                break;
            case 3: {
                int id;
                cout << "Masukkan ID Produk untuk diperiksa: ";
                cin >> id;
                sistem.cekKualitas(id);
                break;
            }
            case 4:
                cout << "Keluar dari sistem." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
