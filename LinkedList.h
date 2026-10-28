#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>
#include <limits>
#include <utility>

struct BookNode
{
    int bookID;
    std::string title;
    BookNode* next;
};

class LinkedList
{
private:
    BookNode* head;
    int count;

    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);

    BookNode* GetNodeAt(int index) const;
    void CopyBookData(BookNode* a, BookNode* b);

public:
    LinkedList();
    void Insert(BookNode* book);
    BookNode* Remove();
    bool IsEmpty() const;
    int GetCount() const;
    bool InsertAt(BookNode* book, int index);
    BookNode* RemoveAt(int index);
    bool Swap(int index1, int index2);
    void Sort();
    void Reverse();
    void Print() const;
    ~LinkedList();
};

BookNode* CreateBook(int id, const std::string& title);
int ReadInteger(const std::string& prompt);
std::string ReadTitle();

#endif