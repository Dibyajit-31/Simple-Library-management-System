# 📚 Library Management System

A simple **Library Management System built in C** using file handling to store and manage book records.

This is a console-based project created to practice fundamental concepts of C programming such as structures, file handling, strings, loops, conditional statements, and switch-case.

## ✨ Features

- 📖 **Add New Book**
  - Add one or multiple books to the library.
  - Store book ID, title, author, and available stock.

- 📚 **View All Books**
  - Display all books currently stored in the library.

- 🔍 **Search Book**
  - Search for a book using:
    - Book ID
    - Book Title

- 📤 **Issue a Book**
  - Issue an available book to a person.
  - Automatically decreases the available stock.
  - Stores the issue record separately.

- 📥 **Return a Book**
  - Return an issued book.
  - Automatically increases the available stock.
  - Removes the corresponding issue record.

- 🚪 **Exit**
  - Exit the application.

## 🛠️ Technologies Used

- **Language:** C
- **Compiler:** GCC / Any standard C compiler

### Concepts Used

- Structures
- File Handling
- `struct`
- `FILE`
- `fopen()`
- `fscanf()`
- `fprintf()`
- `fclose()`
- `remove()`
- `rename()`
- String handling
- Loops
- Conditional statements
- Switch-case

## 📁 Project Structure

```text
Library-Management-System/
│
├── main.c
├── Books.txt
├── Issued.txt
└── README.md
```

## File	Description
main.c	Main C source code

Books.txt	Stores book records

Issued.txt	Stores issued-book records

README.md	Project documentation
## ▶️ How to Run
1. Clone the Repository
git clone https://github.com/your-username/Library-Management-System.git
2. Navigate to the Project Directory
cd Library-Management-System
3. Compile the Program

Using GCC:

gcc main.c -o library
4. Run the Program

Windows:

library.exe

Linux/macOS:

./library
## 🖥️ Program Menu
--------------------Menu-------------------
1. Add New Book
2. View All Books
3. Search Book (By ID or Title)
4. Issue a Book
5. Return a Book
6. Exit
💾 Data Storage

This project uses text files for data storage instead of a database.

Books.txt

Stores information such as:

Book ID
Book Title
Author
Available Stock
Issued.txt

Stores information about books that have been issued, including the book details and the name of the person who received the book.

## 🎯 Learning Objectives

This project helped me practice:

Working with structures in C
Reading and writing files
Storing persistent data using text files
Searching records
Updating stored records
Using temporary files to modify existing records
Building a menu-driven console application
## 🚀 Future Improvements
 Add a continuous menu loop
 Improve input validation
 Support book titles and author names containing spaces
 Add a delete-book option
 Add member/student records
 Add issue and return dates
 Improve the console interface
 Replace text-file storage with a database
 Add an admin/login system
## 👨‍💻 Author
Dibyajit

A beginner-friendly C project created to practice programming fundamentals and file handling.

⭐ If you found this project useful, consider giving the repository a star!
