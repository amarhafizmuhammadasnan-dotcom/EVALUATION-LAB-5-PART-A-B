#include "PatientList.h"
using namespace std;

PatientNode* LinkedList::GetNodeAt(int index) const
{
    PatientNode* current = head;
    for (int i = 0; i < index && current != NULL; i++)
    {
        current = current->next;
    }
    return current;
}

void LinkedList::CopyPatientData(PatientNode* a, PatientNode* b)
{
    if (a == NULL || b == NULL) return;
    swap(a->patientID, b->patientID);
    swap(a->name, b->name);
    swap(a->age, b->age);
    swap(a->condition, b->condition);
}

LinkedList::LinkedList()
{
    head = NULL;
    count = 0;
}

void LinkedList::Insert(PatientNode* patient)
{
    if (patient == NULL) return;
    patient->next = head;
    head = patient;
    count++;
}

PatientNode* LinkedList::Remove()
{
    if (IsEmpty()) return NULL;
    PatientNode* patient = head;
    head = head->next;
    patient->next = NULL;
    count--;
    return patient;
}

bool LinkedList::IsEmpty() const { return head == NULL; }
bool LinkedList::IsNotEmpty() const { return head != NULL; }
int LinkedList::GetCount() const { return count; }

bool LinkedList::InsertAt(PatientNode* patient, int index)
{
    if (patient == NULL || index < 0 || index > count) return false;
    if (index == 0) { Insert(patient); return true; }
    PatientNode* previous = GetNodeAt(index - 1);
    if (previous == NULL) return false;
    patient->next = previous->next;
    previous->next = patient;
    count++;
    return true;
}

PatientNode* LinkedList::RemoveAt(int index)
{
    if (index < 0 || index >= count) return NULL;
    if (index == 0) return Remove();
    PatientNode* previous = GetNodeAt(index - 1);
    if (previous == NULL || previous->next == NULL) return NULL;
    PatientNode* patient = previous->next;
    previous->next = patient->next;
    patient->next = NULL;
    count--;
    return patient;
}

bool LinkedList::Swap(int index1, int index2)
{
    if (index1 < 0 || index1 >= count || index2 < 0 || index2 >= count) return false;
    if (index1 == index2) return true;
    PatientNode* first = GetNodeAt(index1);
    PatientNode* second = GetNodeAt(index2);
    if (first == NULL || second == NULL) return false;
    CopyPatientData(first, second);
    return true;
}

void LinkedList::Sort()
{
    for (PatientNode* i = head; i != NULL; i = i->next)
    {
        for (PatientNode* j = i->next; j != NULL; j = j->next)
        {
            if (i->patientID > j->patientID) CopyPatientData(i, j);
        }
    }
}

void LinkedList::Reverse()
{
    PatientNode* previous = NULL;
    PatientNode* current = head;
    PatientNode* next = NULL;
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
    PatientNode* current = head;
    int index = 0;
    cout << "\nIndex\tPatient ID\tName\tAge\tCondition\n";
    cout << "----------------------------------------------------------------\n";
    if (IsEmpty()) cout << "No patients in the list.\n";
    while (current != NULL)
    {
        cout << index << "\t" << current->patientID << "\t\t" << current->name << "\t" << current->age << "\t" << current->condition << "\n";
        current = current->next;
        index++;
    }
    cout << "----------------------------------------------------------------\n";
    cout << "Total patients: " << count << "\n";
}

LinkedList::~LinkedList() { while (!IsEmpty()) delete Remove(); }

PatientNode* CreatePatient(int id, string name, int age, string condition)
{
    PatientNode* patient = new PatientNode;
    patient->patientID = id;
    patient->name = name;
    patient->age = age;
    patient->condition = condition;
    patient->next = NULL;
    return patient;
}
