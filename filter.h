#pragma once
#include <string>
using namespace std;

extern bool latin;
extern bool cyrillic;
extern bool digits;
extern bool punctuation;

bool isLatin(char ch);
bool isCyrillic(char ch);
void applyFilters(string& text);
void toggleFilter(int choice);
void showFilters();
