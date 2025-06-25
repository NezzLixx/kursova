#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "filter.h"

using namespace std;

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
