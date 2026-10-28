#ifndef PATIENT_LIST_H
#define PATIENT_LIST_H

#include <iostream>
#include <string>
#include <utility>

struct PatientNode
{
    int patientID;
    std::string name;
    int age;
    std::string condition;
    PatientNode* next;
};

class LinkedList
{
private:
    PatientNode* head;
    int count;

    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);

    PatientNode* GetNodeAt(int index) const;
    void CopyPatientData(PatientNode* a, PatientNode* b);

public:
    LinkedList();
    void Insert(PatientNode* patient);
    PatientNode* Remove();
    bool IsEmpty() const;
    bool IsNotify() const; // Maps to your IsNotEmpty check
    bool IsNotEmpty() const;
    int GetCount() const;
    bool InsertAt(PatientNode* patient, int index);
    PatientNode* RemoveAt(int index);
    bool Swap(int index1, int index2);
    void Sort();
    void Reverse();
    void Print() const;
    ~LinkedList();
};

PatientNode* CreatePatient(int id, std::string name, int age, std::string condition);

#endif
