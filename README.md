# Library Management System in C
## Documentation

This is a simple **Library Management System** built using C, designed to manage a collection of books in a library. The system allows users to perform various operations such as adding books, borrowing and returning books, searching for books, and saving the library data to a file for future use.

## Features
- **Add New Books**: Easily add books to the system by providing details like title, author, and availability.
- **Display Available Books**: View a list of all available books with relevant information.
- **Search Books**: Search for books by title, author, or other parameters.
- **Borrow and Return Books**: Borrow books and update their availability status, and return books when done.
- **Save and Load Books from File**: Persist book data between program runs by saving to and loading from a file.
- **Collect User Feedback**: Gather feedback from users regarding the library or system.

## Prerequisites
Before running the program, ensure that you have the following text files created in the same directory as the program:

- `books.txt` – Stores the list of books.
- `Cust_details.txt` – Stores the details of customers who borrow books.
- `feedback.txt` – Stores user feedback.

These files are required for proper functioning of the system, as the program reads and writes data to them.

## How to Run

1. Clone this repository to your local machine:
    ```bash
    git clone https://github.com/yourusername/library-management-system.git
    ```

2. Compile the C program:
    ```bash
    gcc library_management.c -o library_management
    ```

3. Run the executable:
    ```bash
    ./library_management
    ```

## How It Works

1. **Load Books from File**: At startup, the program loads book data from `books.txt`.
2. **Add, Borrow, Return, and Search**: You can perform operations like adding books, borrowing, returning, or searching the library’s collection.
3. **Save Data**: The book data is saved to `books.txt` when changes are made.
4. **Customer Details and Feedback**: The customer details are stored in `Cust_details.txt`, and user feedback is saved to `feedback.txt`.

## Contributing

Feel free to contribute by opening issues or submitting pull requests!

