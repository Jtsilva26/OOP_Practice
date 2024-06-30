#include <iostream>
#include <string>
#include <iomanip>

#include "Video.h"

bool Video::compare_other(const string &user_other) const
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

void Video::display() const
{
    cout << "==========================" << endl;
    cout << "========== VIDEO =========" << endl;
    cout << "==========================" << endl;
    cout << setw(22) << left << "call_number:" << right << call_number << endl;
    cout << setw(22) << left << "title:" << right << title << endl;
    cout << setw(22) << left << "subjects:" << right << subjects << endl;
    cout << setw(22) << left << "description:" << right << description << endl;
    cout << setw(22) << left << "distributor:" << right << distributor << endl;
    cout << setw(22) << left << "notes:" << right << notes << endl;
    cout << setw(22) << left << "series:" << right << series << endl;
    cout << setw(22) << left << "label:" << right << label << endl;
}