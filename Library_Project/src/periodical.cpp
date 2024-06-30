#include <iostream>
#include <string>
#include <iomanip>

#include "Periodical.h"

bool Periodical::compare_other(const string &user_other) const
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
    return false;
}

void Periodical::display() const
{
    cout << "==========================" << endl;
    cout << "======= PERIODICAL =======" << endl;
    cout << "==========================" << endl;
    cout << setw(22) << left << "call_number:" << right << call_number << endl;
    cout << setw(22) << left << "title:" << right << title << endl;
    cout << setw(22) << left << "subjects:" << right << subjects << endl;
    cout << setw(22) << left << "author:" << right << author << endl;
    cout << setw(22) << left << "description:" << right << description << endl;
    cout << setw(22) << left << "publisher:" << right << publisher << endl;
    cout << setw(22) << left << "publishing_history:" << right << publishing_history << endl;
    cout << setw(22) << left << "series:" << right << series << endl;
    cout << setw(22) << left << "notes:" << right << notes << endl;
    cout << setw(22) << left << "related_titles:" << right << related_titles << endl;
    cout << setw(22) << left << "other_forms_of_title:" << right << other_forms_of_title << endl;
    cout << setw(22) << left << "govt_doc_number:" << right << govt_doc_number << endl;
}