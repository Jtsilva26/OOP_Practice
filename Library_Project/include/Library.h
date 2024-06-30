#ifndef LIBRARY_H
#define LIBRARY_H

#include<string>
#include<vector>

#include"Media.h"
#include"Book.h"
#include"Film.h"
#include"Periodical.h"
#include"Video.h"

using namespace std;

class Library{
    public:
        Library(const Library&)=delete;
        Library& operator=(const Library&)=delete;

        Library(){}

        ~Library();
        vector<Media*> fetch_all_with_cn(const string&);
        vector<Media*> fetch_all_with_title(const string&);
        vector<Media*> fetch_all_with_subjects(const string&);
        vector<Media*> fetch_all_with_other(const string&);

        void readInAll(string);
        void readInOne(string, string);
        void assignData(vector<string>, string);




    private:
        vector<Media*> card_catalog;

};
#endif