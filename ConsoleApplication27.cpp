#include "library.h"

int main() {
    int size = 0;
    Book* library = nullptr;
    int choice;

    while (true) {
        cout << "\t [1] - fill db; \n\t [2] - print db; \n\t [3] - add source; \n\t [4] - delete source; \n\t [5] - sort sources; \n\t [6] - search book; \n\t [7] - search magazine; \n\t [8] - count books by genre; \n\t [9] - remove newspapers by year; \n\t [10] - exit; \n\t\t Enter :: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            fillDB();
            break;
        }
        case 2: {
            library = readAll(size);
            if (library == nullptr) {
                cout << "File not found !!! " << endl;
            }
            else {
                printAllSource(library, size);
            }
            break;
        }
        case 3: {
            Book tmp;
            editSource(tmp);
            saveSource(tmp);
            break;
        }
        case 4: {
            deleteSource(library, size);
            break;
        }
        case 5: {
            sortSources(library, size);
            break;
        }
        case 6: {
            searchBook(library, size);
            break;
        }
        case 7: {
            searchMagazine(library, size);
            break;
        }
        case 8: {
            countBooksByGenre(library, size);
            break;
        }
        case 9: {
            removeNewspapersByYear(library, size);
            break;
        }
        case 10: {
            delete[] library;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

}