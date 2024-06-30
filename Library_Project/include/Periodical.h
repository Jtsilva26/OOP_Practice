#ifndef PERIODICAL_H
#define PERIODICAL_H

#include "Media.h"
#include <string>

using namespace std;

class Periodical : public Media
{
public:
    Periodical(const Periodical &) = delete;
    Periodical &operator=(const Periodical &) = delete;

    Periodical(const string &call_number, const string &title, const string &subjects, const string &author, const string &description, const string &publisher, const string &publishing_history, const string &series, const string &notes,
               const string &related_titles, const string &other_forms_of_title, const string &govt_doc_number)
        : Media(call_number, title, subjects, notes),
          author(author),
          description(description),
          publisher(publisher),
          publishing_history(publishing_history),
          series(series),
          related_titles(related_titles),
          other_forms_of_title(other_forms_of_title),
          govt_doc_number(govt_doc_number) {}

    bool compare_other(const string &) const override;
    virtual void display() const;

private:
    string author;
    string description;
    string publisher;
    string publishing_history;
    string series;
    string related_titles;
    string other_forms_of_title;
    string govt_doc_number;
};
#endif