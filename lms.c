#include <stdio.h>
#include <string.h>

#define key 2004
#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_CUSTOMERS 100

struct Book {
    int bookId;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float cost;
    int isBorrowed;
};
struct CPD
{
    char custName[60];
    int custmobNo;
    char custAddress[250];
};
    

struct Customer {
    char customerId[25];
    int borrowedBookId;
};

struct Review {
    int bookId;
    int feedback;
};

struct Book books[MAX_BOOKS];
struct Customer customers[MAX_CUSTOMERS];
struct Review reviews[MAX_BOOKS]; // You can change this value based on your needs

int bookCount = 0;
int customerCount = 0;
int reviewCount = 0;

// Function declarations
void saveBooksToFile();
void loadBooksFromFile();
void addBook();
void displayBooks();
void searchBooks();
void borrowBook();
void returnBook();
void collectFeedback();


int main() {
    loadBooksFromFile();
    
   int choice1,choice2,c,pass;
   label:
   printf("* * * * * * * * * \n");
        printf(" Welcome to the\n"
               "             Library Management System\n");
        printf("* * * * * * * * * \n");
   printf("1.Customer Login\n"); 
   printf("2. Admin Login\n");
   printf("Please enter your desired choice: \n");
   scanf("%d",&c);
   if(c==2){
   printf("You've initiated the Admin login.\n"); 
   printf("Enter Authentication Code to gain access: \n");
    scanf("%d",&pass);
if(key==pass){
    do { printf("Welcome Admin.\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Books\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. Library Feedback\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);
        getchar(); // Consume newline

        switch (choice1) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBooks();
                break;
            case 4:
                borrowBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                collectFeedback();
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        saveBooksToFile();

    } while (choice1 != 7);
}
else 
printf("password is wrong!!!!"); 
printf("\n");
goto label;
}
else { 
    printf("Customer Login opted.");
    printf("\n");
   
    do {
        printf("\nWelcome Customer.");
        printf("\n");
        printf("1. Display Books\n");
        printf("2. Search Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Library Feedback\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice2);
        getchar(); // Consume newline

        switch (choice2) {
            
            case 1:
                displayBooks();
                break;
            case 2:
                searchBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                collectFeedback();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        saveBooksToFile();

    } while (choice2 != 6);

}

    return 0;
}

void saveBooksToFile() {
    FILE *file = fopen("books.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "|   %d   |   %s   |   %s  |  %.2f  |  %d  |\n", books[i].bookId, books[i].title, books[i].author, books[i].cost, books[i].isBorrowed);
        fprintf(file,"-----------------------------------------------------------------------------------------------------------\n");
    }

    fclose(file);
}

void loadBooksFromFile() {
    FILE *file = fopen("books.dat", "rb");
    if (file == NULL) {
        return;
    }

    while (fscanf(file, "%d,%99[^,],%99[^,],%f,%d\n", &books[bookCount].bookId,
                  books[bookCount].title, books[bookCount].author, &books[bookCount].cost,
                  &books[bookCount].isBorrowed) == 5) {
        bookCount++;
    }

    fclose(file);
}

void addBook() {

    if (bookCount >= MAX_BOOKS) {
        printf("Cannot add more books. Maximum capacity reached.\n");
        return;
    }
    int i,n;
    struct Book newBook;
    printf("Enter the number of books to add: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    printf("Enter Book ID: ");
    scanf("%d", &newBook.bookId);
    getchar();  // Consume newline

    for (int i = 0; i < bookCount; i++) {
        if (newBook.bookId == books[i].bookId) {
            printf("Error: Book with the same ID already exists.\n");
            return;
        }
    }
    printf("Enter Book title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';

    printf("Enter book author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    printf("Enter Book cost: ");
    scanf("%f", &newBook.cost);
    newBook.isBorrowed = 0;

    books[bookCount] = newBook;
    bookCount++;
    
    saveBooksToFile();
    
    printf("\n");
    }
    printf("Book details added successfully!\n");

}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }

    printf("List of Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book ID: %d\n", books[i].bookId);
        printf("Book Title: %s\n", books[i].title);
        printf("Book Author: %s\n", books[i].author);
        printf("Book Cost: ₹ %.2f\n", books[i].cost);
        printf("Borrowed: %s\n", books[i].isBorrowed ? "Yes" : "No");
    
        printf("\n");
    }
}

void searchBooks() {
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }
 

    int choice;
    printf("Search by:\n");
    printf("1. Title\n");
    printf("2. Author\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume newline

    switch (choice) {
        case 1: {
            char searchTitle[100];
            printf("Enter book title to search: ");
            fgets(searchTitle, sizeof(searchTitle), stdin);
            searchTitle[strcspn(searchTitle, "\n")] = '\0';

            int found = 0;
            for (int i = 0; i < bookCount; i++) {
                if (strcmp(searchTitle, books[i].title) == 0) {
                    printf("Book found:\n");
                    printf("Book ID: %d\n", books[i].bookId);
                    printf("Book Title: %s\n", books[i].title);
                    printf("Book Author: %s\n", books[i].author);
                    printf("Book Cost: %.2f\n", books[i].cost);
                    printf("Borrowed: %s\n\n", books[i].isBorrowed ? "Yes" : "No");
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Book not found.\n");
            }
            break;
        }
        case 2: {
            char searchAuthor[100];
            printf("Enter author name to search: ");
            fgets(searchAuthor, sizeof(searchAuthor), stdin);
            searchAuthor[strcspn(searchAuthor, "\n")] = '\0';

            int found = 0;
            for (int i = 0; i < bookCount; i++) {
                if (strcmp(searchAuthor, books[i].author) == 0) {
                    printf("Book found:\n");
                    printf("Book ID: %d\n", books[i].bookId);
                    printf("Book Title: %s\n", books[i].title);
                    printf("Book Author: %s\n", books[i].author);
                    printf("Book Cost: %.2f\n", books[i].cost);
                    printf("Borrowed: %s\n\n", books[i].isBorrowed ? "Yes" : "No");
                    found = 1;
                }
            }

            if (!found) {
                printf("No books found for the given author.\n");
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
    }
}

void borrowBook() {
    if (bookCount == 0) {
        printf("No books available for borrowing.\n");
        return;
    }

    struct CPD C;  // Define a variable for customer details
    char customerId[25];
    int bookId;

    printf("Enter customer ID: ");
    scanf("%s", customerId);

    printf("Enter book ID to borrow: ");
    scanf("%d", &bookId);
    getchar(); // Consume newline

    int bookIndex = -1;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].bookId == bookId) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        printf("Book not found.\n");
        return;
    }

    if (books[bookIndex].isBorrowed) {
        printf("Book is already borrowed.\n");
    } else {
        // Update the customer details
        FILE *fp = fopen("Cust_details.txt", "a");
        if (fp == NULL) {
            printf("Error opening file for writing.\n");
            return;
        }

        printf("Enter Customer Name: ");
        fgets(C.custName, sizeof(C.custName), stdin);
        printf("Enter Customer Mobile Number: ");
        scanf("%d", &C.custmobNo);
        getchar(); // Consume newline
        printf("Enter Customer Address: ");
        fgets(C.custAddress, sizeof(C.custAddress), stdin);

        fprintf(fp, "1.Customer ID: %s\n", customerId);
        fprintf(fp, "2.Customer Name: %s", C.custName);
        fprintf(fp, "3.Customer Mobile Number: %d\n", C.custmobNo);
        fprintf(fp, "4.Customer Address: %s", C.custAddress);
        fprintf(fp, "Book Borrowed: %d\n", bookId);
        fprintf(fp, "------------------------\n");
        
        fclose(fp);

        books[bookIndex].isBorrowed = 1;
        strcpy(customers[customerCount].customerId, customerId);
        customers[customerCount].borrowedBookId = bookId;
        customerCount++;

        printf("Book borrowed successfully!\n");
        saveBooksToFile();
    }
}



    
void returnBook() {
    if (customerCount == 0) {
        printf("No books have been borrowed.\n");
        return;
    }

    char customerId[20]; // Change customer ID to string
    int bookId;

    printf("Enter customer ID: ");
    scanf("%s",customerId);

    printf("Enter book ID to return: ");
    scanf("%d", &bookId);
    getchar();  // Consume newline

    int customerIndex = -1;
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].customerId, customerId) == 0 && customers[i].borrowedBookId == bookId) {
            customerIndex = i;
            break;
        }
    }

    if (customerIndex == -1) {
        printf("No record found for the provided customer and book combination.\n");
        return;
 }

    int bookIndex = -1;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].bookId == bookId) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        printf("Book not found.\n");
        return;
    }

    books[bookIndex].isBorrowed = 0;
    for (int i = customerIndex; i < customerCount - 1; i++) {
        customers[i] = customers[i + 1];
    }
    customerCount--;

    printf("Book returned successfully!\n");
    saveBooksToFile(); 
}



void collectFeedback() {
    char customerId[25]; // Change customer ID to string
    int feedbackChoice;
    char customerName[50];
FILE *file = fopen("feedback.txt", "wb");
    printf("Enter customer ID: ");
    scanf("%s", customerId);
    getchar();
    printf("Enter customer name: ");
    fgets(customerName,50,stdin);
    

    printf("\n\nThank you for using our Library services, %s. Please provide feedback for our services:\n", customerName);
    printf("\n");
    
    
    printf("1. Excellent\n");
    printf("2. Very Good\n");
    printf("3. Good\n");
    printf("4. Satisfactory\n");
    printf("\n");
    printf("Enter feedback choice: ");
    scanf("%d", &feedbackChoice);

    if (feedbackChoice >= 1 && feedbackChoice <= 4) {
        printf("\n\nThank you for your feedback, %s. Please visit again. ", customerName);
        printf("\n");
     
        
        // Save feedback to a file
        
        if (file == NULL) {
            printf("Error opening file for writing.\n");
            return;
        }
        fprintf(file,"Customer Name: ");
        fwrite(customerName,1,strlen(customerName),file);
        fprintf(file, "Customer Id: %s\nCustomer Feedback: %d\n",customerId, feedbackChoice); 
        fprintf(file,"----------------------------------------------------------------------\n");
        // Write feedback to the file
        fclose(file);
    } else {
        printf("Invalid feedback choice.\n");
    }
}