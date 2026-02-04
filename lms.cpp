#include<iostream> 
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

// this is for a single book
class Book{
    private:
    int bookId;
    string title, author;
    bool issued;

    public:
    Book() {} // for unordered map
    Book(int id, const string t, const string a) : bookId(id), title(t), author(a), issued(false){}
    
    int getBookId(){
        return bookId;
    }
    
    bool isIssued(){
        return issued;
    }
    void issue(){
        if(issued){
            cout<<"The book is already issued !";
            return ;
        }
        issued = true;
        cout<<"You have successfully issued the book !";
    }
    
    void giveBack(){
        if(!issued){
            cout<<"The book wasn't issued !";
            return ;
        }
        issued = false;
        cout<<"The book has succesfuly been returned !";
    }
    
    void display(){
        cout<<"Book Id : "<<bookId
        << " | Title: " << title
        << " | Author: " << author
        << " | Status: " << (issued ? "Issued" : "Available") << endl;
    }
};

// this is for the member of library i.e. student or borrower
class User{
    private:
    int userId;
    string name;
    vector<int> allIssuedBooks;
    
    public:
    User() {} // for unordered map
    User(int id, const string& n) : userId(id), name(n){}
    
    int getUserId() const {
        return userId;
    }
    
    void issueBook(int bookId){
        allIssuedBooks.push_back(bookId);
        cout<<"The book successfully issued !!";
    }
    
    bool returnBook(int bookId){
        
        for(auto i = allIssuedBooks.begin(); i != allIssuedBooks.end(); i++){
            if (*i == bookId) {
                allIssuedBooks.erase(i);
                cout << "Book returned by user.\n";
                return true;
            }
        }
        cout << "This user does not have that book.\n";
        }
    void viewIssuedBooks(){
        if(allIssuedBooks.empty()){
            cout<<"No book has been issued.";
            return;
        }
        cout << "Issued books: ";
        for(auto book : allIssuedBooks){
                cout<<book<<" ";
            }
        cout<<endl;
    }
        
};

// this is library controlled by librarian 

class Library {
    private:
    unordered_map<int, Book> books;
    unordered_map<int, User> users;

    public:
    void addBook(int id, const string& title, const string& author) {
        books[id] = Book(id, title, author);
        cout << "Book added successfully.\n";
    }

    void addUser(int id, const string& name) {
        users[id] = User(id, name);
        cout << "User registered successfully.\n";
    }

    bool issueBook(int bookId, int userId) {
        auto bookIt = books.find(bookId);
        if (bookIt == books.end()) {
            cout << "Book does not exist.\n";
            return false;
        }

        auto userIt = users.find(userId);
        if (userIt == users.end()) {
            cout << "User does not exist.\n";
            return false;
        }

        Book& book = bookIt->second;
        User& user = userIt->second;

        if (book.isIssued()) {
            cout << "Book already issued.\n";
            return false;
        }

        book.issue();
        user.issueBook(bookId);

        cout << "Book issued successfully.\n";
        return true;
    }

    bool returnBook(int bookId, int userId) {
        auto bookIt = books.find(bookId);
        auto userIt = users.find(userId);

        if (bookIt == books.end() || userIt == users.end()) {
            cout << "Invalid book or user.\n";
            return false;
        }

        Book& book = bookIt->second;
        User& user = userIt->second;

        if (!book.isIssued()) {
            cout << "Book was not issued.\n";
            return false;
        }

        if (!user.returnBook(bookId)) {
            cout << "User does not have this book.\n";
            return false;
        }

        book.giveBack();
        cout << "Book returned successfully.\n";
        return true;
    }

    void showAllBooks() const {
        if (books.empty()) {
            cout << "No books in library.\n";
            return;
        }
        for (const auto& pair : books) {
            pair.second.display();
        }
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Register User\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. View All Books\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int id, userId;
        string title, author, name;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;

                cout << "Enter Title: ";
                cin>> title;
                cout << "Enter Author: ";
                cin>> author;
                library.addBook(id, title, author);
                break;

            case 2:
                cout << "Enter User ID: ";
                cin >> userId;

                cout << "Enter Name: ";
                cin>>name;
                library.addUser(userId, name);
                break;

            case 3:
                cout << "Enter Book ID: ";
                cin >> id;
                cout << "Enter User ID: ";
                cin >> userId;
                library.issueBook(id, userId);
                break;

            case 4:
                cout << "Enter Book ID: ";
                cin >> id;
                cout << "Enter User ID: ";
                cin >> userId;
                library.returnBook(id, userId);
                break;

            case 5:
                library.showAllBooks();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default: cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}