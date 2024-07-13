#include <bits/stdc++.h>
using namespace std;

class Book
{
    string bookId;
    string name;
    int isAvailable;

public:
    Book(string id, string name) : name(name), bookId(id), isAvailable(true) {}

    string getBookId()
    {
        return bookId;
    }
    string getName()
    {
        return name;
    }
    int getIsAvailable()
    {
        return isAvailable;
    }
    void setIsAvailable(int isAvailable)
    {
        this->isAvailable = isAvailable;
    }
};

class Person
{
    string personId;
    string name;
    string number;
    vector<Book *> borrowedBook;

public:
    Person(string id, string name, string number) : personId(id), name(name), number(number) {}

    string getPersonId()
    {
        return personId;
    }
    string getName()
    {
        return name;
    }
    string getNumber()
    {
        return number;
    }
    void addBorrowedBook(Book *book)
    {
        borrowedBook.push_back(book);
    }
    void notify()
    {
        cout << "You have not yet given your book " << name << "\n";
    }
};

class BorrowedBook
{
    int dateBorrowed;
    string borrowedByPersonId;
    int borrowedForHowMuchTime;
    Book *book;

public:
    BorrowedBook(int date, string borrowedByPersonId, int time, Book *book)
    {
        this->book = book;
        this->dateBorrowed = date;
        this->borrowedForHowMuchTime = time;
        this->borrowedByPersonId = borrowedByPersonId;
    }

    int getDateBorrowed()
    {
        return dateBorrowed;
    }
    int getBorrowedForHowMuchTime()
    {
        return borrowedForHowMuchTime;
    }
    string getPersonId()
    {
        return borrowedByPersonId;
    }
};

class Library
{
    unordered_map<string, Person *> person;

    unordered_map<string, Book *> books;

    vector<string> personBorrowed;
    vector<BorrowedBook *> borrowedBook;

public:
    Library()
    {
    }

    void registerPerson(string id, string name, string number)
    {
        if (person.find(id) != person.end())
        {
            cout << "already registerd with same id\n";
        }
        else
        {
            person[id] = new Person(id, name, number);
        }
    }

    void addBooks(string name, string id)
    {
        if (books.find(id) != books.end())
        {
            cout << "already registerd book with same id\n";
        }
        else
        {
            books[id] = new Book(id, name);
        }
    }

    void borrowBook(string personId, string bookId, int dateBorrowed, int time)
    {
        if (person.find(personId) == person.end())
        {
            cout << "Cannot borrow book person not registered\n";
            return;
        }
        Person *p = person[personId];
        Book *b = books[bookId];
        if (!b->getIsAvailable())
        {
            cout << p->getName() << " Cannot borrow book already borrowed\n";
            return;
        }
        person[personId]->addBorrowedBook(b);
        books[bookId]->setIsAvailable(false);

        borrowedBook.push_back(new BorrowedBook(dateBorrowed, personId, time, b));
        personBorrowed.push_back(personId);
    }

    void notifyPerson(int currTime)
    {
        for (auto &b : borrowedBook)
        {
            if (currTime - b->getDateBorrowed() >= b->getBorrowedForHowMuchTime())
            {
                person[b->getPersonId()]->notify();
            }
        }
    }
};

int main()
{
    Library *library = new Library();
    library->addBooks("A", "1");
    library->addBooks("B", "2");
    library->addBooks("C", "3");
    library->addBooks("D", "4");
    library->addBooks("E", "5");
    library->addBooks("F", "6");
    library->addBooks("G", "7");
    library->addBooks("H", "8");
    library->addBooks("I", "9");
    library->addBooks("J", "1");

    library->registerPerson("1", "A", "123");
    library->registerPerson("2", "B", "123");
    library->registerPerson("3", "C", "123");
    library->registerPerson("4", "D", "123");
    library->registerPerson("5", "E", "123");
    library->registerPerson("6", "F", "123");
    library->registerPerson("7", "G", "123");
    library->registerPerson("8", "H", "123");
    library->registerPerson("8", "I", "123");

    library->borrowBook("1", "6", 1, 3);
    library->borrowBook("2", "6", 1, 4);
    library->borrowBook("2", "1", 1, 6);
    library->borrowBook("3", "2", 1, 1);
    library->borrowBook("3", "4", 1, 7);

    cout << endl;
    cout << endl;
    cout << endl;

    library->notifyPerson(30);
}