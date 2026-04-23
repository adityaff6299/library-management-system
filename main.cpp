#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book Class
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        isIssued = false;
    }
};

// Member Class
class Member {
public:
    int id;
    string name;

    Member(int i, string n) {
        id = i;
        name = n;
    }
};

// Library Class
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void addMember() {
        int id;
        string name;

        cout << "Enter Member ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        members.push_back(Member(id, name));
        cout << "Member added successfully!\n";
    }

    void displayBooks() {
        cout << "\n--- Book List ---\n";
        for (auto &b : books) {
            cout << "ID: " << b.id
                 << " | Title: " << b.title
                 << " | Author: " << b.author
                 << " | Status: " << (b.isIssued ? "Issued" : "Available") << endl;
        }
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;

        for (auto &b : books) {
            if (b.id == id && !b.isIssued) {
                b.isIssued = true;
                cout << "Book issued successfully!\n";
                return;
            }
        }
        cout << "Book not available!\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;

        for (auto &b : books) {
            if (b.id == id && b.isIssued) {
                b.isIssued = false;
                cout << "Book returned successfully!\n";
                return;
            }
        }
        cout << "Invalid return!\n";
    }

    void searchBook() {
        string keyword;
        cin.ignore();
        cout << "Enter title or author: ";
        getline(cin, keyword);

        for (auto &b : books) {
            if (b.title.find(keyword) != string::npos ||
                b.author.find(keyword) != string::npos) {
                cout << "Found -> " << b.title << " by " << b.author << endl;
            }
        }
    }
};

// Main Function
int main() {
    Library lib;
    int choice;

    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Display Books\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Search Book\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.addMember(); break;
            case 3: lib.displayBooks(); break;
            case 4: lib.issueBook(); break;
            case 5: lib.returnBook(); break;
            case 6: lib.searchBook(); break;
        }

    } while (choice != 0);

    return 0;
}
