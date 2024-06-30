#include <iostream>
#include <string>
#include <iomanip>

#include "Book.h"

bool Book::compare_other(const string &user_other) const
{
    // the same, but looking in description, notes, and year
    if (description.find(user_other) != string::npos)
    {
        return true;
    }
    else if (notes.find(user_other) != string::npos)
    {
        return true;
    }
    else if (year.find(user_other) != string::npos)
    {
        return true;
    }
    return false;
}

void Book::display() const
{
    cout << "==========================" << endl;
    cout << "========== BOOK ==========" << endl;
    cout << "==========================" << endl;
    cout << setw(22) << left << "call_number:" << right << call_number << endl;
    cout << setw(22) << left << "title:" << right << title << endl;
    cout << setw(22) << left << "subjects:" << right << subjects << endl;
    cout << setw(22) << left << "author:" << right << author << endl;
    cout << setw(22) << left << "description:" << right << description << endl;
    cout << setw(22) << left << "publisher:" << right << publisher << endl;
    cout << setw(22) << left << "city:" << right << city << endl;
    cout << setw(22) << left << "year:" << right << year << endl;
    cout << setw(22) << left << "series:" << right << series << endl;
    cout << setw(22) << left << "notes:" << right << notes << endl;
}
