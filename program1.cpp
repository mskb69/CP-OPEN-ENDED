#include <iostream>
#include <string>

using namespace std;

const int NUM_BOOKS = 6;

struct Book {
    string title;
    string author;
    int publicationYear;
    string genre;
};

void inputBookDetails(Book books[NUM_BOOKS]) {
    for (int i = 0; i < NUM_BOOKS; ++i) {
        cout << "Enter details for Book " << i + 1 << ":\n";
        cout << "Title: ";
        getline(cin, books[i].title);

        cout << "Author: ";
        getline(cin, books[i].author);

        cout << "Publication Year: ";
        cin >> books[i].publicationYear;
        cin.ignore();

        cout << "Genre: ";
        getline(cin, books[i].genre);

        cout << "\n";
    }
}

void categorizeBooks(const Book books[NUM_BOOKS], Book fiction[NUM_BOOKS], Book nonFiction[NUM_BOOKS], int& fictionCount, int& nonFictionCount) {
    fictionCount = 0;
    nonFictionCount = 0;

    for (int i = 0; i < NUM_BOOKS; ++i) {
        if (books[i].genre == "Fiction") {
            fiction[fictionCount++] = books[i];
        }
        else if (books[i].genre == "Non fiction") {
            nonFiction[nonFictionCount++] = books[i];
        }
    }
}

Book findEarliestBook(const Book books[], int numBooks) {
    Book earliestBook = books[0];

    for (int i = 1; i < numBooks; ++i) {
        if (books[i].publicationYear < earliestBook.publicationYear) {
            earliestBook = books[i];
        }
    }

    return earliestBook;
}

void displayBookDetails(const Book fiction[], const Book nonFiction[], int fictionCount, int nonFictionCount,
    const Book earliestFiction, const Book earliestNonFiction) {
    cout << "\n\nFiction Books:\n";
    for (int i = 0; i < fictionCount; ++i) {
        cout << "Title: " << fiction[i].title << ", Author: " << fiction[i].author
            << ", Publication Year: " << fiction[i].publicationYear << ", Genre: " << fiction[i].genre << "\n";
    }

    cout << "\nNon-Fiction Books:\n";
    for (int i = 0; i < nonFictionCount; ++i) {
        cout << "Title: " << nonFiction[i].title << ", Author: " << nonFiction[i].author
            << ", Publication Year: " << nonFiction[i].publicationYear << ", Genre: " << nonFiction[i].genre << "\n";
    }

    cout << "\nEarliest Fiction Book:\n";
    cout << "Title: " << earliestFiction.title << ", Author: " << earliestFiction.author
        << ", Publication Year: " << earliestFiction.publicationYear << ", Genre: " << earliestFiction.genre << "\n";

    cout << "\nEarliest Non-Fiction Book:\n";
    cout << "Title: " << earliestNonFiction.title << ", Author: " << earliestNonFiction.author
        << ", Publication Year: " << earliestNonFiction.publicationYear << ", Genre: " << earliestNonFiction.genre << "\n";
}

int main() {

    Book books[NUM_BOOKS];
    Book fiction[NUM_BOOKS];
    Book nonFiction[NUM_BOOKS];
    int fictionCount = 0;
    int nonFictionCount = 0;

    inputBookDetails(books);

    categorizeBooks(books, fiction, nonFiction, fictionCount, nonFictionCount);

    Book earliestFiction = findEarliestBook(fiction, fictionCount);
    Book earliestNonFiction = findEarliestBook(nonFiction, nonFictionCount);

    displayBookDetails(fiction, nonFiction, fictionCount, nonFictionCount, earliestFiction, earliestNonFiction);

    return 0;
}