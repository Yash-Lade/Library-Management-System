📚 Library Management System (C++ | OOP)

A console-based Library Management System implemented in C++ using Object-Oriented Programming (OOP) principles.
This project demonstrates class design, object coordination, and basic data management using STL containers.

Features

- Add books to the library
- Register users (library members)
- Issue books to users
- Return issued books
- View all books with their availability status

Menu-driven console interface

🧠 OOP Concepts Used

```Encapsulation```
- Data members of classes (Book, User, Library) are kept private and accessed via public methods.

```Abstraction```
- Users interact with the system through high-level operations (issue, return, add) without knowing internal details.

```Object Responsibility Separation```

- Book → Manages book-specific state (issued / available)
- User → Tracks books issued to a user
- Library → Controls and coordinates all operations

🏗️ Class Structure
Book
Represents a single book in the library.
 |-Attributes
 |-bookId
 |-title
 |-author
 |-issued


User
Represents a library member.
|-Attributes

|-userId

|-name

|-List of issued book IDs

Responsibilities
- Track issued books
- Return books
- View issued books

Library
Acts as the central controller.
 |-Attributes

Collection of books (unordered_map)
Collection of users (unordered_map)

Responsibilities

Add books and users

Issue and return books

Enforce rules (availability, valid users, etc.)

🛠️ Technologies & Tools

Language: C++

Concepts: OOP, STL

Containers Used:

unordered_map

vector

Compiler: GCC / G++

▶️ How to Run

Clone the repository:

git clone https://github.com/your-username/library-management-system-cpp.git


Navigate to the project directory:

cd library-management-system-cpp


Compile the program:

g++ main.cpp -o library


Run the program:

./library

📌 Sample Menu
===== Library Management System =====
1. Add Book
2. Register User
3. Issue Book
4. Return Book
5. View All Books
6. Exit
