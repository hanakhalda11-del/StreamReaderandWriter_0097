#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// CLASS TOKO ELEKTRONIK (OOP)
class TokoElektronik
{
private:
    array<string, 3> etalase;

public:
    // Constructor isi otomatis
    TokoElektronik()
    {
        etalase[0] = "Laptop";
        etalase[1] = "Smartphone";
        etalase[2] = "Headset";
    }

    // Method mengambil produk
    string ambilProduk(size_t nomorRak)
    {
        try
        {
            return etalase.at(nomorRak);
        }
        catch (out_of_range&)
        {
            throw runtime_error(
                "Gagal Mengambil Barang : Rak nomor "
                + to_string(nomorRak)
                + " kosong atau tidak tersedia!"
            );
        }
    }
};

// FILE CRUD
string namaFile = "gudang.txt";

// READ
void tampilkanBarang()
{
    ifstream file(namaFile);

    cout << "\n===== DATA GUDANG =====\n";

    if (!file)
    {
        cout << "File belum tersedia.\n";
        return;
    }

    string data;
    int nomor = 1;

    while (getline(file, data))
    {
        cout << nomor++ << ". " << data << endl;
    }

    file.close();
}

// CREATE
void tambahBarang()
{
    ofstream file(namaFile, ios::app);

    string barang;

    cin.ignore();

    cout << "Masukkan nama barang: ";
    getline(cin, barang);

    file << barang << endl;

    file.close();

    cout << "Barang berhasil ditambahkan.\n";
}

// UPDATE
void updateBarang()
{
    ifstream file(namaFile);

    vector<string> data;
    string baris;

    while (getline(file, baris))
    {
        data.push_back(baris);
    }

    file.close();

    if (data.empty())
    {
        cout << "Data kosong.\n";
        return;
    }

    tampilkanBarang();

    int indeks;

    cout << "\nPilih nomor barang: ";
    cin >> indeks;

    if (indeks < 1 || indeks > data.size())
    {
        cout << "Data tidak ditemukan.\n";
        return;
    }

    cin.ignore();

    cout << "Masukkan data baru: ";

    getline(cin, data[indeks - 1]);

    ofstream simpan(namaFile);

    for (string x : data)
    {
        simpan << x << endl;
    }

    simpan.close();

    cout << "Data berhasil diperbarui.\n";
}

// DELETE
void hapusBarang()
{
    ifstream file(namaFile);

    vector<string> data;

    string baris;

    while (getline(file, baris))
    {
        data.push_back(baris);
    }

    file.close();

    if (data.empty())
    {
        cout << "Data kosong.\n";
        return;
    }

    tampilkanBarang();

    int indeks;

    cout << "\nPilih nomor barang yang dihapus: ";
    cin >> indeks;

    if (indeks < 1 || indeks > data.size())
    {
        cout << "Data tidak ditemukan.\n";
        return;
    }

    data.erase(data.begin() + indeks - 1);

    ofstream simpan(namaFile);

    for (string x : data)
    {
        simpan << x << endl;
    }

    simpan.close();

    cout << "Data berhasil dihapus.\n";
}

// SIMULASI ETALASE
void simulasiEtalase()
{
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";

    try
    {
        cout << "\nSkenario 1 (Rak 1)\n";

        cout << "Barang: "
             << toko.ambilProduk(1)
             << endl;
    }

    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    try
    {
        cout << "\nSkenario 2 (Rak 5)\n";

        cout << "Barang: "
             << toko.ambilProduk(5)
             << endl;
    }

    catch (exception& e)
    {
        cout << e.what() << endl;
    }
}

