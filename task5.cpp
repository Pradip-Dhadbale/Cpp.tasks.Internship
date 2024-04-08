/* Develop a system to manage books , borrowers
     and transactions in library.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BORROWERS 50
#define MAX_TRANSACTIONS 100

struct Book {
    int bookId;
    char title[100];
    char author[50];
    int availableCopies;
};

struct Borrower {
    int memberId;
    char name[50];
};

struct Transaction {
    int transactionId;
    int bookId;
    int memberId;
};

struct Book books[MAX_BOOKS];
struct Borrower borrowers[MAX_BORROWERS];
struct Transaction transactions[MAX_TRANSACTIONS];

int numBooks = 0;
int numBorrowers = 0;
int numTransactions = 0;

void addBook(int bookId, const char *title, const char *author, int copies) {
    if (numBooks >= MAX_BOOKS) {
        printf("Error: Book limit reached.\n");
        return;
    }

    books[numBooks].bookId = bookId;
    strcpy(books[numBooks].title, title);
    strcpy(books[numBooks].author, author);
    books[numBooks].availableCopies = copies;
    numBooks++;
    printf("Book added successfully.\n");
}

void addBorrower(int memberId, const char *name) {
    if (numBorrowers >= MAX_BORROWERS) {
        printf("Error: Borrower limit reached.\n");
        return;
    }

    borrowers[numBorrowers].memberId = memberId;
    strcpy(borrowers[numBorrowers].name, name);
    numBorrowers++;
    printf("Borrower added successfully.\n");
}

void issueBook(int bookId, int memberId) {
    if (numTransactions >= MAX_TRANSACTIONS) {
        printf("Error: Transaction limit reached.\n");
        return;
    }

    int bookIndex = -1;
    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookId == bookId) {
            bookIndex = i;
            break;
        }
    }
    if (bookIndex == -1) {
        printf("Error: Book not found.\n");
        return;
    }

    int borrowerIndex = -1;
    for (int i = 0; i < numBorrowers; i++) {
        if (borrowers[i].memberId == memberId) {
            borrowerIndex = i;
            break;
        }
    }
    if (borrowerIndex == -1) {
        printf("Error: Borrower not found.\n");
        return;
    }

    if (books[bookIndex].availableCopies <= 0) {
        printf("Error: Book not available for borrowing.\n");
        return;
    }

    books[bookIndex].availableCopies--;

    transactions[numTransactions].transactionId = numTransactions + 1;
    transactions[numTransactions].bookId = bookId;
    transactions[numTransactions].memberId = memberId;
    numTransactions++;
    printf("Book issued successfully.\n");
}

void displayBooks() {
    if (numBooks == 0) {
        printf("No books available.\n");
        return;
    }

    printf("Books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("ID: %d, Title: %s, Author: %s, Copies: %d\n", books[i].bookId, books[i].title, books[i].author, books[i].availableCopies);
    }
}

void displayBorrowers() {
    if (numBorrowers == 0) {
        printf("No borrowers available.\n");
        return;
    }

    printf("Borrowers:\n");
    for (int i = 0; i < numBorrowers; i++) {
        printf("ID: %d, Name: %s\n", borrowers[i].memberId, borrowers[i].name);
    }
}

void displayTransactions() {
    if (numTransactions == 0) {
        printf("No transactions available.\n");
        return;
    }

    printf("Transactions:\n");
    for (int i = 0; i < numTransactions; i++) {
        printf("Transaction ID: %d, Book ID: %d, Member ID: %d\n", transactions[i].transactionId, transactions[i].bookId, transactions[i].memberId);
    }
}

int main() {
    int choice, bookId, copies, memberId;
    char title[100], author[50], name[50];

    while (1) {
        printf("\n1. Add Book\n2. Add Borrower\n3. Issue Book\n4. Display Books\n5. Display Borrowers\n6. Display Transactions\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &bookId);
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter author: ");
                scanf("%s", author);
                printf("Enter number of copies: ");
                scanf("%d", &copies);
                addBook(bookId, title, author, copies);
                break;
            case 2:
                printf("Enter member ID: ");
                scanf("%d", &memberId);
                printf("Enter name: ");
                scanf("%s", name);
                addBorrower(memberId, name);
                break;
            case 3:
                printf("Enter book ID: ");
                scanf("%d", &bookId);
                printf("Enter member ID: ");
                scanf("%d", &memberId);
                issueBook(bookId, memberId);
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                displayBorrowers();
                break;
            case 6:
                displayTransactions();
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}