#include "library.h"

void fillDB() {
    int num;
    cout << "Enter number of sources --> ";
    cin >> num;
    Book tmp;

    for (size_t i = 0; i < num; i++) {
        editSource(tmp);
        saveSource(tmp);
    }
}

void editSource(Book& source) {
    cout << "\n\tEnter type source ([1] - BOOK; [2] - NEWSPAPER; [3] - MAGAZINE) --> ";
    int tmp;
    cin >> tmp;
    source.type = (Type)tmp;
    cout << "\tEnter year -- > ";
    cin >> source.year;
    cout << "\tEnter name -- > ";
    cin.getline(source.name, SIZE);
    if (source.type == Type::BOOK) {
        cout << "\tEnter genre -- > ";
        cin.getline(source.genre, SIZE);
        cout << "\tEnter author -- > ";
        cin.getline(source.author, SIZE);
    }
}

void saveSource(Book source, string fname) {
    ofstream file(fname, ios_base::app | ios_base::binary);
    if (!file.is_open()) {
        cout << "Error" << endl;
        return;
    }

    file.write((char*)&source, sizeof(Book));
    file.close();
}

void printSource(const Book& source) {
    cout << "\n\t=================================== "
        << (source.type == BOOK ? "BOOK" : (source.type == MAGAZINE ? "MAGAZINE" : "NEWSPAPER"))
        << " ===================================\n";
    cout << "\t\tName   :: " << source.name << endl;

    if (source.type == BOOK) {
        cout << "\t\tAuthor :: " << source.author << endl;
        cout << "\t\tGenre  :: " << source.genre << endl;
    }

    cout << "\t\tYear   :: " << source.year << endl;
}

void printAllSource(Book* library, int size) {
    for (size_t i = 0; i < size; i++)
    {
        printSource(library[i]);
    }
}

Book* readAll(int& size, string fname) {
    ifstream file(fname);
    if (!file.is_open()) {
        cout << "Error" << endl;
        return nullptr;
    }
    file.seekg(0, ios_base::end);
    if (file.tellg() == 0)
        return nullptr;

    size = file.tellg() / sizeof(Book);
    file.seekg(0);

    Book* tmp = new Book[size];
    for (size_t i = 0; i < size; i++)
    {
        file.read((char*)&tmp[i], sizeof(Book));
    }
    file.close();
    return tmp;
}

void deleteSource(Book*& library, int& size) {
    char name[SIZE];
    cout << "Enter the name of the source to delete: ";
    cin.getline(name, SIZE);
    for (size_t i = 0; i < size; i++) {
        if (strcmp(library[i].name, name) == 0) {
            for (size_t j = i; j < size - 1; j++)
            {
                library[j] = library[j + 1];
            }
            size--;
            library[size] = {};
            cout << "Sources are deteat";
            return;
        }
    }

}

void sortSources(Book* library, int size) {
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (library[i].type > library[j].type ||
                (library[i].type == library[j].type &&
                    strcmp(library[i].name, library[j].name) > 0))
            {
                Book temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }
    cout << "Sources sorted";
}

void searchBook(Book* library, int size) {
    char name[SIZE], author[SIZE];
    cout << "Enter book name: ";
    cin.getline(name, SIZE);
    cout << "Enter author name: ";
    cin.getline(author, SIZE);

    for (size_t i = 0; i < size; i++)
    {
        if (library[i].type == BOOK &&
            strcmp(library[i].name, name) == 0 &&
            strcmp(library[i].author, author) == 0) {
            cout << "Book found:";
            printSource(library[i]);
            return;
        }
    }
    cout << "Book not found";
}

void searchMagazine(Book* library, int size) {
    char name[SIZE];
    cout << "Enter magazine name: ";
    cin.getline(name, SIZE);

    for (size_t i = 0; i < size; i++)
    {
        if (library[i].type == MAGAZINE &&
            strcmp(library[i].name, name) == 0) {
            cout << "Magazine found:";
            printSource(library[i]);
            return;
        }
    }
    cout << "Magazine not found";
}

void countBooksByGenre(Book* library, int size) {
    char genre[SIZE];
    cout << "Enter genre to count: ";
    cin.getline(genre, SIZE);

    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (library[i].type == BOOK &&
            strcmp(library[i].genre, genre) == 0) {
            count++;
        }
    }
    cout << "Number of books in genre : " << count << endl;
}

void removeNewspapersByYear(Book*& library, int& size) {
    int year;
    cout << "Enter year to delete newspapers: ";
    cin >> year;
    for (int i = 0; i < size; i++)
    {
        if (library[i].type == NEWSPAPER &&
            library[i].year == year) {
            for (size_t j = i; j < size - 1; j++)
            {
                library[j] = library[j + 1];
            }
            size--;
            library[size] = {};
            i--;
        }
    }
    cout << "Newspapers from year " << year << " deleted";
}