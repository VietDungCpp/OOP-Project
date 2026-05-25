#include "book.h"
#include <iostream>
#include <string>

using namespace std;

Book::Book() : m_id(0), m_title(""), m_author(""), m_available(true) {}

Book::Book(int id, string title, string author) : m_id(id), m_title(title), m_author(author), m_available(true) {}

void Book::input()
{
    cout << "Enter ID: ";
    cin >> m_id;

    cin.ignore();

    cout << "Enter title: ";
    getline(cin, m_title);

    cout << "Enter author: ";
    getline(cin, m_author);

    m_available = true;
}

void Book::display() const
{
    cout << "ID: " << m_id << '\n';
    cout << "Title: " << m_title << '\n';
    cout << "Author: " << m_author << '\n';
    cout << "Status: " << (m_available ? "Available" : "Borrowed") << '\n';
}

int Book::getID() const
{
    return m_id;
}

string Book::getTitle() const
{
    return m_title;
}

bool Book::isAvailable() const
{
    return m_available;
}

void Book::borrowBook()
{
    m_available = false;
}

void Book::returnBook()
{
    m_available = true;
}