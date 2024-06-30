#include <iostream>
#include <string>

#include "Library.h"
#include "Media.h"

using namespace std;

int main()
{
    Library cards;
    cards.readInAll("01");
    vector<Media *> returnValues;
    // Book bk ("one","two","three", "BOOK object","","six","seven","eight","nine","ten");
    int key;
    string phrase;
    while (1)
    {
        cout << "1) call_number" << endl;
        cout << "2) title" << endl;
        cout << "3) subject" << endl;
        cout << "4) other" << endl;
        cout << "5) exit" << endl;
        cin >> key;
        if (key == 1)
        {
            cout << "Enter keyphrase: ";
            cout << endl;
            cin >> phrase;
            returnValues = cards.fetch_all_with_cn(phrase);
        }
        if (key == 2)
        {
            cout << "Enter keyphrase: ";
            cout << endl;
            cin >> phrase;
            returnValues = cards.fetch_all_with_title(phrase);
        }
        if (key == 3)
        {
            cout << "Enter keyphrase: ";
            cout << endl;
            cin >> phrase;
            returnValues = cards.fetch_all_with_subjects(phrase);
        }
        if (key == 4)
        {
            cout << "Enter keyphrase: ";
            cout << endl;
            cin >> phrase;
            returnValues = cards.fetch_all_with_other(phrase);
        }
        if (key == 5)
        {
            exit(1);
        }
        for (auto &m : returnValues)
        {
            m->display();
        }
    }

    // test
    //  Book bk("11", "thetitle", "fdsfds", "joe", "hello", "mama", "chico", "100", "4", "gg");
    //      bk.display();
    //  Book bk2("11", "", "fdsfds", "joe", "hello", "mama", "chico", "100", "4", "gg");
    //      bk2.display();
    //  cout << bk.compare_cn("11") << endl;
    //  cout << bk.compare_title("the") << endl;
    //  cout << bk.compare_title(" ") << endl;
}
