#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ios_base;

const short SIZE = 50;

enum Type {
    BOOK = 1,
    NEWSPAPER,
    MAGAZINE
};

struct Book {
    Type type;
    char name[SIZE]{};
    int year;
    char genre[SIZE]{};
    char author[SIZE]{};
};

void fillDB();
void editSource(Book& source);
void saveSource(const Book& source, const string& fname = "data.dat");
void printSource(const Book& source);
void printAllSource(Book* library, int size);
Book* readAll(int& size, const string& fname = "data.dat");
void deleteSource(Book*& library, int& size);
void sortSources(Book* library, int size);
void searchBook(Book* library, int size);
void searchMagazine(Book* library, int size);
void countBooksByGenre(Book* library, int size);
void removeNewspapersByYear(Book* library,int& size);
