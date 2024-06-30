#ifndef BOOK_H
#define BOOK_H

#include "Media.h"
#include <string>

using namespace std;

class Book : public Media
{
public:
    Book(const Book &) = delete;
    Book &operator=(const Book &) = delete;

    Book(const string &call_number, const string &title, const string &subjects, const string &author,
         const string &description, const string &publisher, const string &city, const string &year, const string &series, const string &notes)
        : Media(call_number, title, subjects, notes),
          publisher(publisher),
          city(city),
          year(year),
          series(series),
          author(author),
          description(description) {}

    bool compare_other(const string &) const override;
    virtual void display() const;

private:
    string publisher;
    string city;
    string year;
    string series;
    string author;
    string description;
};
#endif