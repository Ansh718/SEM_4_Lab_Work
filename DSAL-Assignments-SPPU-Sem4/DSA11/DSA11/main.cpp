//
//  main.cpp
//  DSA11
//
//  Created by ANSH BHUTADA on 06/06/23.

#include <iostream>
#include <fstream>
 #include <cstring>
using namespace std;

struct Student
{
    int rollNumber;
    char name[20];
    char division;
    char address[10];
};

// Function to add student information to the file
void addStudent()
{
    ofstream file("test.txt", ios::binary | ios::app);
    if (!file)
    {
        cout << "Error opening file!";
        return;
    }

    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cout << "Enter Name: ";
    cin.ignore(); // Ignore the newline character from previous input
    cin.getline(student.name, 50);
    cout << "Enter Division: ";
    cin >> student.division;
    cout << "Enter Address: ";
    cin.ignore(); // Ignore the newline character from previous input
    cin.getline(student.address, 100);

    file.write(reinterpret_cast<char *>(&student), sizeof(Student));
    file.close();

    cout << "Student information added successfully." << endl;
}

// Function to display student information based on roll number
void displayStudent(int rollNumber)
{
    ifstream file("test.txt", ios::binary);
    if (!file)
    {
        cout << "Error opening file!";
        return;
    }

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        if (student.rollNumber == rollNumber)
        {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Record not found." << endl;
    }

    file.close();
}

// Function to delete student information based on roll number
void deleteStudent(int rollNumber)
{
    ifstream file("test.txt", ios::binary);
    if (!file)
    {
        cout << "Error opening file!";
        return;
    }

    ofstream tempFile("temp.txt", ios::binary);
    if (!tempFile)
    {
        cout << "Error creating temporary file!";
        file.close();
        return;
    }

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        if (student.rollNumber != rollNumber)
        {
            tempFile.write(reinterpret_cast<char *>(&student), sizeof(Student));
        }
        else
        {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove("test.txt");
    rename("temp.txt", "students.dat");

    if (found)
    {
        cout << "Student information deleted successfully." << endl;
    }
    else
    {
        cout << "Record not found ." << endl;
    }
}

void searchStudent(int rollNumber)
{
    ifstream file("test.txt", ios::binary);
    if (!file)
    {
        cout << "Error opening file!";
        return;
    }

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        if (student.rollNumber == rollNumber)
        {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Record not found." << endl;
    }

    file.close();
}

int main()
{
    int choice, rollNumber;

    do
    {
        cout << "\n*** Student Information System ***" << endl;
        cout << "1. Add Student\n2. Display Student\n3. Delete Student\n4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            cout << "Enter Roll Number: ";
            cin >> rollNumber;
            displayStudent(rollNumber);
            break;
        case 3:
            cout << "Enter Roll Number: ";
            cin >> rollNumber;
            deleteStudent(rollNumber);
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice.Enter different choice" << endl;
        }
    } while (choice != 4);

    return 0;
}
