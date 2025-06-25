#include <iostream>
#include "filter.h"
#include <cctype>

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
