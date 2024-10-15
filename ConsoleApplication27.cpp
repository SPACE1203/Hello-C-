#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int SIZE = 50;

struct Book {
    char name[SIZE]{};
    char author[SIZE]{};
    char publisher[SIZE]{};
    char genre[SIZE]{};
    int year;
};

void compareBooks(const Book& a, const Book& b, bool& result) {
    int genreCompare = strcmp(a.genre, b.genre);
    if (genreCompare != 0) {
        result = genreCompare > 0;
    }
    else {
        result = strcmp(a.name, b.name) > 0;
    }
}


void countBooksByCategory(Book library[], int count, const char* category) {
    int categoryCount = 0;
    for (size_t i = 0; i < count; i++) {
        if (strcmp(library[i].genre, category) == 0) {
            categoryCount++;
        }
    }
    cout << "Number of books in category '" << category << "': " << categoryCount << endl;
}

void removeBooksByYear(Book library[], int& count, int yearToDelete) {
    bool found = false;
    for (size_t i = 0; i < count; i++) {
        if (strcmp(library[i].genre, "Newspaper") == 0 && library[i].year == yearToDelete) {
            found = true;
            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1]; 
            }
            count--;  
            i--;  
        }
    }

    if (!found) {
        cout << "No newspapers found for year " << yearToDelete << ".\n";
    }
}

void findBooksByAuthor(Book library[], int count, const char* author) {
    cout << "Books by author '" << author << "':\n";
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].author, author) == 0) {
            cout << "\n======================== " << library[i].name << " ========================\n";
            cout << "\t\tAuthor    :: " << library[i].author << endl;
            cout << "\t\tPublisher :: " << library[i].publisher << endl;
            cout << "\t\tGenre     :: " << library[i].genre << endl;
            cout << "\t\tYear      :: " << library[i].year << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No books found by author '" << author << "'.\n";
    }
}

void findBooksByCategory(Book library[], int count, const char* category) {
    cout << "Books in category '" << category << "':\n";
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].genre, category) == 0) {
            cout << "\n======================== " << library[i].name << " ========================\n";
            cout << "\t\tAuthor    :: " << library[i].author << endl;
            cout << "\t\tPublisher :: " << library[i].publisher << endl;
            cout << "\t\tYear      :: " << library[i].year << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No books found in category '" << category << "'.\n";
    }
}


void displayLibrary(Book library[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "\n\n ========================= " << library[i].name << " ============================\n";
        cout << "\t\t Author    :: " << library[i].author << endl;
        cout << "\t\t Publisher :: " << library[i].publisher << endl;
        cout << "\t\t Genre     :: " << library[i].genre << endl;
        cout << "\t\t Year      :: " << library[i].year << endl;
    }
}

int main() {
    int size = 7;
    Book library[] = {
        { "Sales Techniques", "Maria Petrenko", "Business Book", "Book", 2021 },
        { "News of Ukraine", "Editorial Team", "Today Newspaper", "Newspaper", 2020 },
        { "Young Scientist", "Editorial Team", "Scientific World", "Magazine", 2022 },
        { "Culinary Recipes of the World", "Sophia Gryshchenko", "Culinary Press", "Magazine", 2019 },
        { "Technologies of the Future", "Vladislav Kovalenko", "TechnoTeka", "Magazine", 2023 },
        { "Fashion Life", "Editorial Team", "Fashion Magazine", "Magazine",2018 },
        { "Introduction to Programming", "Alexander Ivanenko", "Education Publishing", "Book", 2020 }
    };

    cout << "Library sorted by genre and name:\n";
    displayLibrary(library, size);

    char category[SIZE];
    cout << "Enter the category to count (Book, Magazine,): ";
    cin.getline(category, SIZE);
    countBooksByCategory(library, size, category);

    int year;
    cout << "Enter the year to delete newspapers: ";
    cin >> year;
    removeBooksByYear(library, size, year);
    cout << "Updated Library:\n";
    displayLibrary(library, size);

    cin.ignore();
    cout << "Enter author name to search: ";
    cin.getline(category, SIZE);
    findBooksByAuthor(library, size, category);

    cout << "Enter category to search (e.g., Book, Magazine): ";
    cin.getline(category, SIZE);
    findBooksByCategory(library, size, category);

    char magazineName[SIZE];
    cout << "Enter magazine name to search: ";
    cin.getline(magazineName, SIZE);

    return 0;
}