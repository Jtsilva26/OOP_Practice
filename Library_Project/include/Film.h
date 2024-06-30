#ifndef FILM_H
#define FILM_H

#include "Media.h"
#include <string>

using namespace std;

class Film : public Media
{
public:
    Film(const Film &) = delete;
    Film &operator=(const Film &) = delete;

    Film(const string &call_number, const string &title, const string &subjects, const string &director, const string &notes, const string &year)
        : Media(call_number, title, subjects, notes),
          director(director),
          year(year)
    {
    }

    bool compare_other(const string &) const override;
    virtual void display() const;

private:
    string director;
    string year;
};
#endif