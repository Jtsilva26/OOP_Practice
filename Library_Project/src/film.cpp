#include <iostream>
#include <string>
#include <iomanip>

#include "Film.h"

bool Film::compare_other(const string &user_other) const
{
    // the same, but looking in description, notes, and years
    if (notes.find(user_other) != string::npos)
    {
        return true;
    }
    else if (year.find(user_other) != string::npos)
    {
        return true;
    }
    return false;
}

void Film::display() const
{
    cout << "==========================" << endl;
    cout << "========== FILM ==========" << endl;
    cout << "==========================" << endl;
    cout << setw(22) << left << "call_number:" << right << call_number << endl;
    cout << setw(22) << left << "title:" << right << title << endl;
    cout << setw(22) << left << "subjects:" << right << subjects << endl;
    cout << setw(22) << left << "director:" << right << director << endl;
    cout << setw(22) << left << "notes:" << right << notes << endl;
    cout << setw(22) << left << "year:" << right << year << endl;
}