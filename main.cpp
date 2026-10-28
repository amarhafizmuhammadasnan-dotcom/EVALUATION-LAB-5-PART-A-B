#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList library;
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "   LIBRARY BOOK COLLECTION SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert Book at Head\n";
        cout << "3. Remove Book from Head\n";
        cout << "4. Insert Book at Index\n";
        cout << "5. Remove Book at Index\n";
        cout << "6. Swap Books\n";
        cout << "7. Sort Books by ID\n";
        cout << "8. Reverse Book Collection\n";
        cout << "9. Check Collection Status\n";
        cout << "10. Exit\n";
        cout << "========================================\n";

        choice = ReadInteger("Enter your choice: ");

        switch (choice)
        {
            case 1:
                library.Print();
                break;

            case 2:
            {
                int id = ReadInteger("Enter book ID: ");
                string title = ReadTitle();
                library.Insert(CreateBook(id, title));
                cout << "Book inserted at head successfully.\n";
                break;
            }

            case 3:
            {
                BookNode* removed = library.Remove();
                if (removed != NULL)
                {
                    cout << "Removed book: " << removed->bookID << " - " << removed->title << "\n";
                    delete removed;
                }
                else cout << "Collection is empty.\n";
                break;
            }

            case 4:
            {
                int index = ReadInteger("Enter insertion index: ");
                if (index < 0 || index > library.GetCount())
                {
                    cout << "Invalid index. Valid range: 0 to " << library.GetCount() << "\n";
                }
                else
                {
                    int id = ReadInteger("Enter book ID: ");
                    string title = ReadTitle();
                    library.InsertAt(CreateBook(id, title), index);
                    cout << "Book inserted at index " << index << " successfully.\n";
                }
                break;
            }

            case 5:
            {
                int index = ReadInteger("Enter removal index: ");
                BookNode* removed = library.RemoveAt(index);
                if (removed != NULL)
                {
                    cout << "Removed book: " << removed->bookID << " - " << removed->title << "\n";
                    delete removed;
                }
                else cout << "Invalid index or list empty.\n";
                break;
            }

            case 6:
            {
                int idx1 = ReadInteger("Enter first index: ");
                int idx2 = ReadInteger("Enter second index: ");
                if (library.Swap(idx1, idx2)) cout << "Books swapped successfully.\n";
                else cout << "Failed to swap. Check your indexes.\n";
                break;
            }

            case 7:
                library.Sort();
                cout << "Books sorted by ID.\n";
                break;

            case 8:
                library.Reverse();
                cout << "Book collection reversed.\n";
                break;

            case 9:
                if (library.IsEmpty()) cout << "The collection is empty.\n";
                else cout << "Collection contains " << library.GetCount() << " book(s).\n";
                break;

            case 10:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid option. Please choose between 1 and 10.\n";
        }
    } while (choice != 10);

    return 0;
}
