#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

const int MAX_SIZE = 1000;

void SET_COLOR(int color)
{
	WORD wColor;
    

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

class NhanVien 
{
private:
    long long maNV;
    float LuongCB;
    float Phucap;
    long long CCCD;
    string HovaTen;
    string DiaChi;
    string GioiTinh;
    string NgaySinh;
    string Email;
    string SoDT;
    float ThucLinh;

public:
    void nhap() 
    {
        cout << "Nhap ma nhan vien: ";  cin >> maNV;            cin.ignore();
        cout << "Nhap luong: ";         cin >> LuongCB;         cin.ignore();
        cout << "Nhap Phu Cap: ";       cin >> Phucap;          cin.ignore();
        cout << "Nhap so CCCD: ";       cin >> CCCD;            cin.ignore();
        cout << "Nhap ho va ten: ";     getline(cin, HovaTen);  
        cout << "Nhap dia chi: ";       getline(cin, DiaChi);   
        cout << "Nhap gioi tinh: ";     getline(cin, GioiTinh); 
        cout << "Nhap ngay sinh: ";     getline(cin, NgaySinh); 
        cout << "Nhap email: ";         getline(cin, Email);    
        cout << "Nhap so dien thoai: "; getline(cin, SoDT);     

        ThucLinh = LuongCB + Phucap;
    }

    void xuat() const 
    {
        cout << setw(10) << maNV << setw(20) << HovaTen << setw(14) << NgaySinh << setw(20) << DiaChi << setw(15) << GioiTinh << setw(25) << Email << setw(18) << SoDT << setw(18) << CCCD << setw(10) << LuongCB << setw(10) << Phucap << setw(10) << ThucLinh << endl;
    }

    long long get_maNV() const 
    {
        return maNV;
    }

    long long get_CCCD() const 
    {
        return CCCD;
    }

    float get_ThucLinh() const 
    {
        return ThucLinh;
    }

    float get_Phucap() const 
    {
        return Phucap;
    }

    string get_HovaTen() const 
    {
        return HovaTen;
    }

    static void readFile(const string& filename, NhanVien employees[], int& size) 
    {
        ifstream file(filename);
        if (!file) 
        {
            cout << "Khong mo duoc file." << endl;
            return;
        }

        string line;
        size = 0;
        while (getline(file, line) && size < MAX_SIZE) 
        {
            istringstream iss(line);
            NhanVien& nv = employees[size];
            iss >> nv.maNV >> nv.LuongCB >> nv.Phucap >> nv.CCCD;
            iss.ignore();
            getline(iss, nv.HovaTen, ',');
            getline(iss, nv.DiaChi, ',');
            getline(iss, nv.GioiTinh, ',');
            getline(iss, nv.NgaySinh, ',');
            getline(iss, nv.Email, ',');
            getline(iss, nv.SoDT, ',');
            nv.ThucLinh = nv.LuongCB + nv.Phucap;
            size++;
        }

        file.close();
    }

    static void writeFile(const string& filename, NhanVien employees[], int size) 
    {
        ofstream file(filename); 
        if (!file) 
        {
            cout << "Khong mo duoc file." << endl;
            return;
        }

        for (int i = 0; i < size; ++i) 
        {
            const NhanVien& nv = employees[i];
            file << nv.maNV << " " << nv.LuongCB << " " << nv.Phucap << " " << nv.CCCD << " " << nv.HovaTen << "," << nv.DiaChi << "," << nv.GioiTinh << "," << nv.NgaySinh << "," << nv.Email << "," << nv.SoDT << "," << endl;
        }

        file.close();
    }
};

void nhapds(NhanVien nv[], int& size) 
{
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    if (n > MAX_SIZE - size) 
    {
        cout << "So luong nhan vien vuot qua kich thuoc toi da!" << endl;
        return;
    }

    for (int i = size; i < size + n; ++i) 
    {
        cout << endl << "Nhan Vien Thu: " << i + 1 << endl;
        nv[i].nhap();
    }

    size += n;
}

void xuatds(NhanVien nv[], int size) 
{
    cout << setw(10) << "MaNV" << setw(20) << "Ho va Ten" << setw(14) << "Ngay Sinh" << setw(20) << "Dia Chi" << setw(15) << "Gioi Tinh" << setw(25) << "Email" << setw(18) << "So DT" << setw(18) << "CCCD" << setw(10) << "LuongCB" << setw(10) << "Phu Cap" << setw(10) << "Thuc Linh" << endl;
    for (int i = 0; i < size; ++i) 
    {
        nv[i].xuat();
    }
}

void TKMaNV(NhanVien nv[], int size) 
{
    long long Ma;
    int count = 0;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> Ma;
    for (int i = 0; i < size; ++i) 
    {
        if (nv[i].get_maNV() == Ma) 
        {
            nv[i].xuat();
            count++;
        }
    }
    if (count == 0)
        cout << "Khong tim thay ma nhan vien can tim." << endl;
}

void TKCCCD(NhanVien nv[], int size) 
{
    long long cccd;
    int count = 0;
    cout << "Nhap CCCD nhan vien can tim: ";
    cin >> cccd;
    for (int i = 0; i < size; ++i) 
    {
        if (nv[i].get_CCCD() == cccd) 
        {
            nv[i].xuat();
            count++;
        }
    }
    if (count == 0)
        cout << "Khong tim thay CCCD nhan vien can tim." << endl;
}

void TKTen(NhanVien nv[], int size) 
{
    string ten;
    int count = 0;
    cout << "Nhap ten nhan vien can tim: ";
    cin.ignore();
    getline(cin, ten);
    for (int i = 0; i < size; ++i) 
    {
        if (nv[i].get_HovaTen() == ten) 
        {
            nv[i].xuat();
            count++;
        }
    }
    if (count == 0)
        cout << "Khong tim thay nhan vien co ten can tim." << endl;
}

void sapxep(NhanVien nv[], int size) 
{
    sort(nv, nv + size, [](const NhanVien& a, const NhanVien& b) 
    {
        return a.get_ThucLinh() < b.get_ThucLinh();
    });
    cout << endl << "Sau khi sap xep: " << endl;
    xuatds(nv, size);
}

void tongLuong(NhanVien nv[], int size) 
{
    double TongLuong = accumulate(nv, nv + size, 0.0, [](double sum, const NhanVien& nvItem) 
    {
        return sum + nvItem.get_ThucLinh();
    });
    cout << "Tong luong cua nhan vien la: " << TongLuong << endl;
}

void thucLinhmax(NhanVien nv[], int size) 
{
    if (size == 0) 
    {
        cout << "Danh sach nhan vien trong." << endl;
        return;
    }
    auto max_nv = max_element(nv, nv + size, [](const NhanVien& a, const NhanVien& b) 
    {
        return a.get_ThucLinh() < b.get_ThucLinh();
    });
    cout << "Nhan vien co thuc linh cao nhat: " << endl;
    max_nv->xuat();
}

void timphucap(NhanVien nv[], int size) 
{
    int count = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (nv[i].get_Phucap() > 100000) 
        {
            nv[i].xuat();
            count++;
        }
    }
    if (count == 0)
        cout << "Khong co nhan vien nao co phu cap > 100000." << endl;
}

void xoa(NhanVien nv[], int& size) 
{
    long long Ma;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> Ma;
    int pos = -1;
    for (int i = 0; i < size; ++i) 
    {
        if (nv[i].get_maNV() == Ma) 
        {
            pos = i;
            break;
        }
    }
    if (pos != -1) 
    {
        for (int i = pos; i < size - 1; ++i) 
        {
            nv[i] = nv[i + 1];
        }
        size--;
        cout << "Da xoa nhan vien co ma " << Ma << endl;
    } 
    else 
    {
        cout << "Khong tim thay ma nhan vien can xoa." << endl;
    }
}

void them(NhanVien nv[], int& size) 
{
    if (size >= MAX_SIZE) 
    {
        cout << "Danh sach nhan vien da day." << endl;
        return;
    }
    nv[size].nhap();
    size++;
}

void sua(NhanVien nv[], int size) 
{
    long long Ma;
    cout << "Nhap ma nhan vien can sua: ";
    cin >> Ma;
    for (int i = 0; i < size; ++i) 
    {
        if (nv[i].get_maNV() == Ma) 
        {
            nv[i].nhap();
            cout << "Sua thong tin thanh cong." << endl;
            return;
        }
    }
    cout << "Khong tim thay ma nhan vien." << endl;
}

void menu(NhanVien nv[], int& size) 
{
    int choice;
    bool backToMenu = false;

    do 
    {
        SET_COLOR('C');
        cout << " _____________________________________________________________________________" << endl;
        cout << "|";

        SET_COLOR(7);
        cout << "*****************************************************************************";

        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|                              ";

        SET_COLOR(4);
        cout << "QUAN LY NHAN VIEN";

        SET_COLOR('C');
        cout << "                              |" << endl;
        cout << "|";

        SET_COLOR(7);
        cout << "_____________________________________________________________________________";

        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR(7);
        cout << "*";
        
        SET_COLOR('C');
        cout << "                                                                           *";
        cout << "|" << endl;
        cout << "|";

        SET_COLOR('A');
        cout << "              ||\\"<<"\\        //|| ||======  ||\\"<<"\\    || ||       ||              ";

        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";
        
        SET_COLOR('A');
        cout << "              || \\"<<"\\      // || ||        || \\"<<"\\   || ||       ||              ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";
        
        SET_COLOR('A');
        cout << "              ||  \\"<<"\\    //  || ||======  ||  \\"<<"\\  || ||       ||              ";

        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";
        
        SET_COLOR('A');
        cout << "              ||   \\"<<"\\  //   || ||        ||   \\"<<"\\ || ||       ||              ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";
        
        SET_COLOR('A');
        cout << "              ||    \\"<<"\\//    || ||======  ||    \\"<<"\\||  \\"<<"\\=====//               ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR(7);
        cout << "_____________________________________________________________________________";

        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|                                                                             |" << endl;
        cout << "|";

        SET_COLOR('E');
        cout << "  1.  Nhap danh sach nhan vien                                               ";

        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR(2);
        cout << "  2.  Hien thi danh sach nhan vien                                           ";

        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";
        
        SET_COLOR(3);
        cout << "  3.  Tim kiem nhan vien theo maNV                                           ";

        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR(4);
        cout << "  4.  Tim kiem nhan vien theo CCCD                                           ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR(5);
        cout << "  5.  Tim kiem nhan vien theo ten                                            ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR(6);
        cout << "  6.  Sap xep luong nhan vien tang dan                                       ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR(7);
        cout << "  7.  Tinh tong luong nhan vien                                              ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR(8);
        cout << "  8.  Tim kiem nhan vien thu nhap cao nhat                                   ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR(9);
        cout << "  9.  Tim kiem nhan vien phu cap > 100.000                                   ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR('B');
        cout << "  10. Xoa nhan vien                                                          ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR('C');
        cout << "  11. Them nhan vien                                                         ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR('D');
        cout << "  12. Sua thong tin mot nhan vien                                            ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR('E');
        cout << "  13. Ghi danh sach nhan vien ra file khac                                   ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR('F');
        cout << "  14. Quay lai menu                                                          ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR('G');
        cout << "  15. Thoat                                                                  ";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|                                                                             |" << endl;
        cout << "|";

        SET_COLOR(7);
        cout << "*___________________________________________________________________________*";
        
        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR(7);
        cout << "_____________________________________________________________________________";

        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR(7);
        cout << "*****************                    ~2TK~                   ****************";

        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";

        SET_COLOR(7);
        cout << "*****************************************************************************";

        SET_COLOR('C');
        cout << "|" << endl;
        cout << "|";
        cout << "_____________________________________________________________________________";
        cout << "|" << endl;

        SET_COLOR(4);
        cout << "Nhap lua chon cua ban [1-15]: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                nhapds(nv, size);
                NhanVien::writeFile("NhanVien.txt", nv, size);
                break;
            case 2:
                xuatds(nv, size);
                break;
            case 3:
                TKMaNV(nv, size);
                break;
            case 4:
                TKCCCD(nv, size);
                break;
            case 5:
                TKTen(nv, size);
                break;
            case 6:
                sapxep(nv, size);
                break;
            case 7:
                tongLuong(nv, size);
                break;
            case 8:
                thucLinhmax(nv, size);
                break;
            case 9:
                timphucap(nv, size);
                break;
            case 10:
                xoa(nv, size);
                NhanVien::writeFile("NhanVien.txt", nv, size);
                break;
            case 11:
                them(nv, size);
                NhanVien::writeFile("NhanVien.txt", nv, size);
                break;
            case 12:
                sua(nv, size);
                NhanVien::writeFile("NhanVien.txt", nv, size);
                break;
            case 13: 
            {
                string newFilename;
                cout << "Nhap ten file moi de luu danh sach: ";
                cin.ignore();
                getline(cin, newFilename);
                NhanVien::writeFile(newFilename, nv, size);
                cout << "Da luu danh sach nhan vien vao file " << newFilename << endl;
                break;
            }
            case 14:
                backToMenu = true;
                break;
            case 15:
                cout << "Thoat chuong trinh." << endl;
                exit(0);
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }

        if (choice != 14 && !backToMenu) 
        {
            
            cout << "Nhan 'ENTER' de tiep tuc..." << endl;
            cin.ignore();
            cin.get();
        }
    } while (choice != 15);
}

int main() 
{
    NhanVien nv[MAX_SIZE];
    int size = 0;
    NhanVien::readFile("NhanVien.txt", nv, size);
    menu(nv, size);
    return 0;
}
