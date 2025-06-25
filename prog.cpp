#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <Windows.h>

using namespace std;

bool latin = false;
bool cyrillic = false;
bool digits = false;
bool punctuation = false;

bool isLatin(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isCyrillic(char ch) {
    return (ch >= char(-64) && ch <= char(-1)) || ch == char(-88) || ch == char(-72);
}

void applyFilters(string& text) {
    for (char& ch : text) {
        if ((latin && isLatin(ch)) ||
            (cyrillic && isCyrillic(ch)) ||
            (digits && isdigit((unsigned char)ch)) ||
            (punctuation && ispunct((unsigned char)ch))) {
            ch = '*';
        }
    }
}

void toggleFilter(int choice) {
    switch (choice) {
        case 1: 
            latin = !latin; break;
        case 2: 
            cyrillic = !cyrillic; break;
        case 3: 
            punctuation = !punctuation; break;
        case 4: 
            digits = !digits; break;
    }
}

void showFilters() {
    cout << "\n=== ������� ������� ===\n";
    if (latin) cout << "��������\n";
    if (cyrillic) cout << "��������\n";
    if (punctuation) cout << "����������\n";
    if (digits) cout << "�����\n";
    if (!latin && !cyrillic && !punctuation && !digits) cout << "����\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string infileName = "infile.txt";
    string outfileName = "outfile.txt";

    int choice;

    do {
        cout << "\n=== ���� ===\n";
        cout << "1. ��������/�������� ������ ��������\n";
        cout << "2. ��������/�������� ������ ��������\n";
        cout << "3. ��������/�������� ������ ����������\n";
        cout << "4. ��������/�������� ������ ����\n";
        cout << "5. �������� ������ �������\n";
        cout << "6. �������� ����� � �����\n";
        cout << "0. �����\n";
        cout << "����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            toggleFilter(choice);
            cout << "Գ���� ������\n";
            break;
        case 2:
            toggleFilter(choice);
            cout << "Գ���� ������\n";
            break;
        case 3:
            toggleFilter(choice);
            cout << "Գ���� ������\n";
            break;
        case 4:
            toggleFilter(choice);
            cout << "Գ���� ������\n";
            break;
        case 5:
            showFilters();
            break;
        case 6: {
            ifstream infile(infileName);
            ofstream outfile(outfileName);
            string line;

            while (getline(infile, line)) {
                applyFilters(line);
                outfile << line << endl;
            }

            infile.close();
            outfile.close();
            cout << "���� ���������. ��������� � " << outfileName << endl;
            break;
        }
        case 0:
            cout << "����������\n";
            break;
        default:
            cout << "������� ����\n";
        }
    } while (choice != 0);

    return 0;
}
