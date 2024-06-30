#ifndef MEDIA_H
#define MEDIA_H

#include <string>

using namespace std;

class Media{
    public:
        Media(const Media&)=delete; //Copy Constructor
        Media& operator=(const Media&)=delete; //Assignment Operator
        
        //Constructors for Media
        // Media(const string& call_numbers){}
        // Media(const string& title){}
        // Media(const string& subjects){}
        // Media(const string& notes){}

        Media(const string& call_number, const string& title, const string& subjects, const string& notes):
        call_number(call_number),
        title(title),
        subjects(subjects),
        notes(notes){}

        virtual ~Media() {}
        bool compare_cn(const string&) const;
        bool compare_title(const string&) const;
        bool compare_subjects(const string&) const;
        virtual bool compare_other(const string&) const = 0;
        virtual void display() const = 0;

    protected:
    string call_number;
    string title;
    string subjects;
    string notes;

};
#endif