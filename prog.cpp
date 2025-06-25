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
    cout << "\n=== Увімкнені фільтри ===\n";
    if (latin) cout << "Латиниця\n";
    if (cyrillic) cout << "Кирилиця\n";
    if (punctuation) cout << "Пунктуація\n";
    if (digits) cout << "Цифри\n";
    if (!latin && !cyrillic && !punctuation && !digits) cout << "Немає\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string infileName = "infile.txt";
    string outfileName = "outfile.txt";

    int choice;

    do {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Увімкнути/вимкнути фільтр латиниці\n";
        cout << "2. Увімкнути/вимкнути фільтр кирилиці\n";
        cout << "3. Увімкнути/вимкнути фільтр пунктуації\n";
        cout << "4. Увімкнути/вимкнути фільтр цифр\n";
        cout << "5. Показати активні фільтри\n";
        cout << "6. Обробити текст з файлу\n";
        cout << "0. Вихід\n";
        cout << "Вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            toggleFilter(choice);
            cout << "Фільтр змінено\n";
            break;
        case 2:
            toggleFilter(choice);
            cout << "Фільтр змінено\n";
            break;
        case 3:
            toggleFilter(choice);
            cout << "Фільтр змінено\n";
            break;
        case 4:
            toggleFilter(choice);
            cout << "Фільтр змінено\n";
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
            cout << "Файл оброблено. Результат у " << outfileName << endl;
            break;
        }
        case 0:
            cout << "Завершення\n";
            break;
        default:
            cout << "Невірний вибір\n";
        }
    } while (choice != 0);

    return 0;
}
