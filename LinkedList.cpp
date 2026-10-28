#include "LinkedList.h"
using namespace std;

BookNode* LinkedList::GetNodeAt(int index) const
{
    BookNode* current = head;
    for (int i = 0; i < index && current != NULL; i++)
    {
        current = current->next;
    }
    return current;
}

void LinkedList::CopyBookData(BookNode* a, BookNode* b)
{
    if (a == NULL || b == NULL) return;
    swap(a->bookID, b->bookID);
    swap(a->title, b->title);
}

LinkedList::LinkedList()
{
    head = NULL;
    count = 0;
}

void LinkedList::Insert(BookNode* book)
{
    if (book == NULL) return;
    book->next = head;
    head = book;
    count++;
}

BookNode* LinkedList::Remove()
{
    if (IsEmpty()) return NULL;
    BookNode* book = head;
    head = head->next;
    book->next = NULL;
    count--;
    return book;
}

bool LinkedList::IsEmpty() const { return head == NULL; }
int LinkedList::GetCount() const { return count; }

bool LinkedList::InsertAt(BookNode* book, int index)
{
    if (book == NULL || index < 0 || index > count) return false;
    if (index == 0) { Insert(book); return true; }
    BookNode* previous = GetNodeAt(index - 1);
    if (previous == NULL) return false;
    book->next = previous->next;
    previous->next = book;
    count++;
    return true;
}

BookNode* LinkedList::RemoveAt(int index)
{
    if (index < 0 || index >= count) return NULL;
    if (index == 0) return Remove();
    BookNode* previous = GetNodeAt(index - 1);
    if (previous == NULL || previous->next == NULL) return NULL;
    BookNode* book = previous->next;
    previous->next = book->next;
    book->next = NULL;
    count--;
    return book;
}

bool LinkedList::Swap(int index1, int index2)
{
    if (index1 < 0 || index1 >= count || index2 < 0 || index2 >= count) return false;
    if (index1 == index2) return true;
    BookNode* first = GetNodeAt(index1);
    BookNode* second = GetNodeAt(index2);
    if (first == NULL || second == NULL) return false;
    CopyBookData(first, second);
    return true;
}

void LinkedList::Sort()
{
    for (BookNode* i = head; i != NULL; i = i->next)
    {
        for (BookNode* j = i->next; j != NULL; j = j->next)
        {
            if (i->bookID > j->bookID) CopyBookData(i, j);
        }
    }
}

void LinkedList::Reverse()
{
    BookNode* previous = NULL;
    BookNode* current = head;
    BookNode* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

void LinkedList::Print() const
{
    BookNode* current = head;
    int index = 0;
    cout << "\nIndex\tBook ID\tTitle\n----------------------------------------\n";
    if (head == NULL) cout << "No books in the collection.\n";
    while (current != NULL)
    {
        cout << index << "\t" << current->bookID << "\t" << current->title << "\n";
        current = current->next;
        index++;
    }
    cout << "----------------------------------------\nTotal books: " << count << "\n";
}

LinkedList::~LinkedList() { while (!IsEmpty()) delete Remove(); }

BookNode* CreateBook(int id, const string& title)
{
    BookNode* book = new BookNode;
    book->bookID = id;
    book->title = title;
    book->next = NULL;
    return book;
}

int ReadInteger(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input. Enter a valid integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string ReadTitle()
{
    string title;
    while (true)
    {
        cout << "Enter book title: ";
        getline(cin, title);
        if (title.find_first_not_of(" \t\r\n") != string::npos) return title;
        cout << "Title cannot be empty. Try again.\n";
    }
}
