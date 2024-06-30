#include <iostream>
#include <fstream>
#include <string>
#include <fstream>

#include "Library.h"

using namespace std;

Library::~Library()
{
  // iterate through vard catalog
  for (long unsigned int i = 0; i < card_catalog.size(); i++)
  {
    delete card_catalog.at(i);
  }
}

void Library::readInAll(string testing_suite)
{
  vector<string> textFiles{"book.txt", "film.txt", "video.txt", "periodic.txt"};
  for (long unsigned int i = 0; i < textFiles.size(); i++)
  {
    readInOne(textFiles[i], testing_suite);
  }
}

void Library::readInOne(string file, string testing_suite)
{
  vector<string> all_text;
  string text;
  string filepath = "testing_suite/" + testing_suite + "/" + file;
  ifstream setFile(filepath);
  // ss << "testing_suite" << testing_suite << '/' << file;
  while (getline(setFile, text, '|'))
  {
    if (text.find('\n') != string::npos)
    {
      size_t newLinePos = text.find('\n');
      all_text.push_back(text.substr(0, newLinePos));
      all_text.push_back(text.substr(newLinePos + 1));
    }
    else
    {
      all_text.push_back(text);
    }
  }
  all_text.pop_back();
  assignData(all_text, file);
}

void Library::assignData(vector<string> all_text, string file)
{
  if (file == "book.txt")
  {
    for (long unsigned int i = 0; i < all_text.size(); i += 10)
    {
      card_catalog.push_back(new Book(all_text[i], all_text[i + 1], all_text[i + 2], all_text[i + 3], all_text[i + 4],
                                      all_text[i + 5], all_text[i + 6], all_text[i + 7], all_text[i + 8], all_text[i + 9]));
    }
  }

  else if (file == "film.txt")
  {
    for (long unsigned int i = 0; i < all_text.size(); i += 6)
    {
      card_catalog.push_back(new Film(all_text[i], all_text[i + 1], all_text[i + 2], all_text[i + 3], all_text[i + 4],
                                      all_text[i + 5]));
    }
  }

  else if (file == "periodic.txt")
  {
    for (long unsigned int i = 0; i < all_text.size(); i += 12)
    {
      card_catalog.push_back(new Periodical(all_text[i], all_text[i + 1], all_text[i + 2], all_text[i + 3], all_text[i + 4],
                                            all_text[i + 5], all_text[i + 6], all_text[i + 7], all_text[i + 8], all_text[i + 9], all_text[i + 10], all_text[i + 11]));
    }
  }
  else if (file == "video.txt")
  {
    for (long unsigned int i = 0; i < all_text.size(); i += 8)
    {
      card_catalog.push_back(new Video(all_text[i], all_text[i + 1], all_text[i + 2], all_text[i + 3], all_text[i + 4],
                                       all_text[i + 5], all_text[i + 6], all_text[i + 7]));
    }
  }
}

vector<Media *> Library::fetch_all_with_cn(const string &user_call_number)
{
  vector<Media *> matches;
  Media *item;
  for (long unsigned int i = 0; i < card_catalog.size(); i++)
  {
    item = card_catalog.at(i);
    bool does_contain = item->compare_cn(user_call_number);
    if (does_contain)
    {
      matches.push_back(item);
    }
  }
  return matches;
}

vector<Media *> Library::fetch_all_with_title(const string &user_title)
{
  vector<Media *> matches;
  Media *item;
  for (long unsigned int i = 0; i < card_catalog.size(); i++)
  {
    item = card_catalog.at(i);
    bool does_contain = item->compare_title(user_title);
    if (does_contain)
    {
      matches.push_back(item);
    }
  }
  return matches;
}

vector<Media *> Library::fetch_all_with_subjects(const string &user_subjects)
{
  vector<Media *> matches;
  Media *item;
  for (long unsigned int i = 0; i < card_catalog.size(); i++)
  {
    item = card_catalog.at(i);
    bool does_contain = item->compare_subjects(user_subjects);
    if (does_contain)
    {
      matches.push_back(item);
    }
  }
  return matches;
}

vector<Media *> Library::fetch_all_with_other(const string &user_other)
{
  vector<Media *> matches;
  Media *item;
  for (long unsigned int i = 0; i < card_catalog.size(); i++)
  {
    item = card_catalog.at(i);
    bool does_contain = item->compare_other(user_other);
    if (does_contain)
    {
      matches.push_back(item);
    }
  }
  return matches;
}
