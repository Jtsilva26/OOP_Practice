#include <iostream>
#include <string>

#include "Media.h"

using namespace std;

bool Media::compare_cn(const string& user_call_number) const{
    if(call_number.find(user_call_number) == string::npos){
        return false;
    }
    return true;
}

bool Media::compare_title(const string& user_title) const{
    if(title.find(user_title) == string::npos){
        return false;
    }
    return true;
}

bool Media::compare_subjects(const string& user_subjects) const{
    if(subjects.find(user_subjects) == string::npos){
        return false;
    }
    return true;
}