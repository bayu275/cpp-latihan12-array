#include <iostream>
#include <iomanip>
#include <limits> // Diperlukan untuk menggunakan numeric_limits
using namespace std;

int main(int argc, char const *argv[])
{
    int jumlahMahasiswa;
    string namaMahasiswa[20];
    int nilaiTugas[20],nilaiQuis[20],nilaiMid[20],nilaiUas[20],nilaiAkhir[20];
    char nilaiHuruf[2], dataMahasiswa;
    bool isDataMahasiswa = true;

    int column_width = 15; // Lebar kolom utama
    int numeric_width = 12; // Lebar kolom nilai numerik

    cout << "------------------------------" << endl;
    cout << "PROGRAM DAFTAR NILAI MAHASISWA" << endl;
    cout << "UNIVERSITAS MUHAMMADIYAH RIAU" << endl;
    cout << "------------------------------" << endl;

    cout << "Total Mahasiswa : ", cin >> jumlahMahasiswa;
    // Membersihkan newline (\n) yang tersisa di buffer setelah operasi cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (isDataMahasiswa)
    {

        for (int i = 0; i < jumlahMahasiswa; i++)
        {
            cout << "Mahasiswa ke-" << i+1 << ":" << endl;
            cout << "Masukkan nama mahasiswa : ", getline(cin, namaMahasiswa[i]);
            cout << "Masukkan nilai tugas: ", cin >> nilaiTugas[i];
            cout << "Masukkan nilai quis: ", cin >> nilaiQuis[i];
            cout << "Masukkan nilai mid: ", cin >> nilaiMid[i];
            cout << "Masukkan nilai uas: ", cin >> nilaiUas[i];
            cout << endl;

            nilaiAkhir[i] = (0.1*nilaiTugas[i]) + (0.1*nilaiQuis[i]) + (0.4*nilaiMid[i]) + (0.4*nilaiUas[i]);

            if (nilaiAkhir[i] > 80 && nilaiAkhir[i] <= 100)
            {
                nilaiHuruf[i] = 'A';
            }
            else if (nilaiAkhir[i] > 65 && nilaiAkhir[i] <= 80)
            {
                nilaiHuruf[i] = 'B';
            }
            else if (nilaiAkhir[i] > 55 && nilaiAkhir[i] <= 65)
            {
                nilaiHuruf[i] = 'C';
            }
            else if (nilaiAkhir[i] > 45 && nilaiAkhir[i] <= 55)
            {
                nilaiHuruf[i] = 'D';
            }
            else {
                nilaiHuruf[i] = 'E';
            }
            cout << "Apakah masih ada data yang ingin anda masukkan (y/n) ? ", cin >> dataMahasiswa;
            
            while (dataMahasiswa != 'y' && dataMahasiswa != 'Y' && dataMahasiswa != 'n' && dataMahasiswa != 'N') {
                cout << "Pilihan salah! Masukkan y atau n: ", cin >> dataMahasiswa;
            }
            
            if (dataMahasiswa == 'y' || dataMahasiswa == 'Y') {
                isDataMahasiswa = true;
                jumlahMahasiswa++;
            } else if (dataMahasiswa == 'n' || dataMahasiswa == 'N') {
                isDataMahasiswa = false;
            }
            // Membersihkan newline (\n) yang tersisa di buffer setelah operasi cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        system("cls");
        cout << "Berikut table data nilai mahasiswa yang sudah anda inputkan :" << endl;

        // Garis pembatas atas
        cout << setfill('-') << setw(127) << "" << endl;
        // Header
        cout << setfill(' ') << "| " 
            << left << setw(column_width) << "No" << " | " 
            << setw(column_width) << "Nama Mahasiswa" << " | " 
            << setw(numeric_width) << "Nilai Tugas" << " | " 
            << setw(numeric_width) << "Nilai Quis" << " | " 
            << setw(numeric_width) << "Nilai Mid" << " | "
            << setw(numeric_width) << "Nilai UAS" << " | "
            << setw(numeric_width) << "Nilai Akhir" << " | " 
            << setw(numeric_width) << "Nilai Huruf" << " |" << endl;
        // Garis pembatas tengah
        cout << setfill('-') << setw(127) << "" << endl;

        for (int i = 0; i < jumlahMahasiswa; ++i) {
            // Data
            cout << setfill(' ') << "| " 
                << setw(column_width) << left << i+1 << " | " 
                << setw(column_width) << left << namaMahasiswa[i] << " | " 
                << setw(numeric_width) << right << nilaiTugas[i] << " | " 
                << setw(numeric_width) << right << nilaiQuis[i] << " | " 
                << setw(numeric_width) << right << nilaiMid[i] << " | " 
                << setw(numeric_width) << right << nilaiUas[i] << " | " 
                << setw(numeric_width) << right << nilaiAkhir[i] << " | " 
                << setw(numeric_width) << right << nilaiHuruf[i] << " |" << endl;
        }
        // Garis pembatas bawah
        cout << setfill('-') << setw(127) << "" << endl;
    }
    cout << "Terimakasih" << endl;
    return 0;
}
