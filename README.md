# C++ OOP Topics and Library Simulation
### Table of Contents
* Introduction
* Topics Covered
  * Polymorphism
  * C++ Stack
  * Const Reference Initialization
  * Function Pointers
  * Function Pointers Using Struct
* Library Simulation Project

#### Introduction
This repository contains examples and explanations of various Object-Oriented Programming (OOP) concepts in C++, along with a project that simulates a library system. The purpose of this repository is to serve as a learning resource for understanding and applying OOP principles in C++.

### Topics Covered
#### Polymorphism
Polymorphism allows objects of different classes to be treated as objects of a common base class. This section includes examples of:

* Compile-time polymorphism (function overloading and operator overloading)
* Runtime polymorphism (virtual functions and abstract classes)

#### C++ Stack
The C++ Standard Template Library (STL) provides a stack class that is a container adaptor. This section includes:

* Basic stack operations (push, pop, top)
* Implementation details and use cases

#### Const Reference Initialization
Using const references is a common practice in C++ to avoid unnecessary copying of objects. This section covers:

* Initialization of const references
* Benefits and best practices

#### Function Pointers
Function pointers allow functions to be passed as arguments to other functions. This section includes:

* Declaration and initialization of function pointers
* Usage examples and scenarios

#### Function Pointers Using Struct
Combining function pointers with structs can be useful in various scenarios, such as implementing callback mechanisms. This section includes:

* Structs with function pointers
* Example implementations and use cases

## Library Simulation Project

### Classes and Attributes
##### Media
```
class Media {
public:
    Media(const std::string& call_number, const std::string& title, const std::string& subjects, const std::string& notes)
        : call_number(call_number), title(title), subjects(subjects), notes(notes) {}
private:
    std::string call_number;
    std::string title;
    std::string subjects;
    std::string notes;
};
```
##### Book
```
class Book : public Media {
public:
    Book(const std::string &call_number, const std::string &title, const std::string &subjects, const std::string &author,
         const std::string &description, const std::string &publisher, const std::string &city, const std::string &year, 
         const std::string &series, const std::string &notes)
        : Media(call_number, title, subjects, notes),
          author(author), description(description), publisher(publisher), city(city), year(year), series(series) {}
private:
    std::string author;
    std::string description;
    std::string publisher;
    std::string city;
    std::string year;
    std::string series;
};
```
##### Film
```
class Film : public Media {
public:
    Film(const std::string &call_number, const std::string &title, const std::string &subjects, const std::string &director, 
         const std::string &notes, const std::string &year)
        : Media(call_number, title, subjects, notes), director(director), year(year) {}
private:
    std::string director;
    std::string year;
};
```
##### Periodical
```
class Periodical : public Media {
public:
    Periodical(const std::string &call_number, const std::string &title, const std::string &subjects, const std::string &author, 
               const std::string &description, const std::string &publisher, const std::string &publishing_history, 
               const std::string &series, const std::string &notes, const std::string &related_titles, 
               const std::string &other_forms_of_title, const std::string &govt_doc_number)
        : Media(call_number, title, subjects, notes), author(author), description(description), publisher(publisher), 
          publishing_history(publishing_history), series(series), related_titles(related_titles), 
          other_forms_of_title(other_forms_of_title), govt_doc_number(govt_doc_number) {}
private:
    std::string author;
    std::string description;
    std::string publisher;
    std::string publishing_history;
    std::string series;
    std::string related_titles;
    std::string other_forms_of_title;
    std::string govt_doc_number;
};
```
##### Video
```
class Video : public Media {
public:
    Video(const std::string &call_number, const std::string &title, const std::string &subjects, const std::string &description, 
          const std::string &distributor, const std::string &notes, const std::string &series, const std::string &label)
        : Media(call_number, title, subjects, notes), description(description), distributor(distributor), series(series), label(label) {}
private:
    std::string description;
    std::string distributor;
    std::string series;
    std::string label;
};
```
