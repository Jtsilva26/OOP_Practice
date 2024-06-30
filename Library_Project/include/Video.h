#ifndef VIDEO_H
#define VIDEO_H

#include "Media.h"
#include <string>

using namespace std;

class Video : public Media
{
public:
    Video(const Video &) = delete;
    Video &operator=(const Video &) = delete;

    Video(const string &call_number, const string &title, const string &subjects, const string &description,
          const string &distributor, const string &notes, const string &series, const string &label)
        : Media(call_number, title, subjects, notes),
          description(description),
          distributor(distributor),
          series(series),
          label(label)
    {
    }

    bool compare_other(const string &) const override;
    virtual void display() const;

private:
    string description;
    string distributor;
    string series;
    string label;
};
#endif