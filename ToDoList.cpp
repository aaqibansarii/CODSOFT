#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    static Date today() {
        // You should implement a way to get the current date.
        // For simplicity, we'll return a fixed date here.
        return Date(1, 1, 2023);
    }

    // You should also implement a method to calculate the difference between two dates.
    // For simplicity, we'll leave it as a placeholder.
    int days() {
        return 0;
    }
};

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool available;

    Book(string title, string author, string ISBN, bool available) {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
        this->available = available;
    }
};

class Borrower {
public:
    int id;
    string name;
    string address;
    string contact;

    Borrower(int id, string name, string address, string contact) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->contact = contact;
    }
};

class Transaction {
public:
    int id;
    Book book;
    Borrower borrower;
    Date checkoutDate;
    Date dueDate;
    Date returnDate;
    bool overdue;

    Transaction(int id, Book book, Borrower borrower, Date checkoutDate, Date dueDate, Date returnDate, bool overdue) 
    {
        this->id = id;
        this->book = book;
        this->borrower = borrower;
        this->checkoutDate = checkoutDate;
        this->dueDate = dueDate;
        this->returnDate = returnDate;
        this->overdue = overdue;
    }
};

class LibraryManagementSystem {
public:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;

    LibraryManagementSystem() {}

    // Add a book to the library
    void addBook(Book book) {
        books.push_back(book);
    }

    // Add a borrower to the library
    void addBorrower(Borrower borrower) {
        borrowers.push_back(borrower);
    }

    // Search for a book by title
    Book searchBookByTitle(string title) {
        for (Book book : books) {
            if (book.title == title) {
                return book;
            }
        }

        // Handle the case where the book is not found.
        return Book("", "", "", false);
    }

    // Search for a book by author
    Book searchBookByAuthor(string author) {
        for (Book book : books) {
            if (book.author == author) {
                return book;
            }
        }

        // Handle the case where the book is not found.
        return Book("", "", "", false);
    }

    // Search for a book by ISBN
    Book searchBookByISBN(string ISBN) {
        for (Book book : books) {
            if (book.ISBN == ISBN) {
                return book;
            }
        }

        // Handle the case where the book is not found.
        return Book("", "", "", false);
    }

    // Check out a book to a borrower
    void checkoutBook(Book book, Borrower borrower) {
        Transaction transaction = Transaction(0, book, borrower, Date::today(), Date::today() + 7, Date(), false);
        transactions.push_back(transaction);

        book.available = false;
    }

    // Return a book
    void returnBook(Book book) {
        for (Transaction& transaction : transactions) {
            if (transaction.book == book) {
                transaction.returnDate = Date::today();
                transaction.overdue = (transaction.returnDate > transaction.dueDate);

                book.available = true;
                return; // Exit the loop once the book is found.
            }
        }

        // Handle the case where the book is not found in transactions.
    }

    // Calculate fine for an overdue book
    float calculateFine(Book book) {
        float fine = 0;

        for (Transaction transaction : transactions) {
            if (transaction.book == book && transaction.overdue) {
                fine += transaction.dueDate.days() - transaction.returnDate.days() * 0.1;
            }
        }

        return fine;
    }

    // Display all books in the library
    void displayAllBooks() {
        cout << "All books in the library:" << endl;

        for (Book book : books) {
            cout << book.title << " by " << book.author << endl;
        }
    }

    // Display all borrowers in the library
    void displayAllBorrowers() {
        cout << "All borrowers in the library:" << endl;

        for (Borrower borrower : borrowers) {
            cout << borrower.name << endl;
        }
    }
};

int main() {
    // You can test your LibraryManagementSystem here.
    return 0;
}
