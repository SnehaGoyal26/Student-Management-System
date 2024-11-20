#include<iostream>
#include<vector>
using namespace std;

// Class to represent a student
class Student {
public:
    string name;
    string rollNo;
    string course;
    string className;
    string contact;

    // Constructor to initialize student details
    Student(string name, string rollNo, string course, string className, string contact) {
        this->name = name;
        this->rollNo = rollNo;
        this->course = course;
        this->className = className;
        this->contact = contact;
    }

    // Function to display student details
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Course: " << course << endl;
        cout << "Class: " << className << endl;
        cout << "Contact: " << contact << endl;
    }
};

// Class to manage the collection of students
class StudentManager {
private:
    vector<Student> students;

public:
    // Function to add a student
    void addStudent() {
        string name, rollNo, course, className, contact;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Course: ";
        cin >> course;
        cout << "Enter Class: ";
        cin >> className;
        cout << "Enter Contact: ";
        cin >> contact;

        students.push_back(Student(name, rollNo, course, className, contact));
    }

    // Function to display all students
    void displayAll() {
        if (students.empty()) {
            cout << "No data entered." << endl;
            return;
        }

        for (int i = 0; i < students.size(); i++) {
            cout << "\nStudent " << i + 1 << endl;
            students[i].displayDetails();
        }
    }

    // Function to search a student by roll number
    void searchStudent(string rollNo) {
        for (auto &student : students) {
            if (student.rollNo == rollNo) {
                student.displayDetails();
                return;
            }
        }
        cout << "Student with roll number " << rollNo << " not found." << endl;
    }

    // Function to update student data
    void updateStudent(string rollNo) {
        for (auto &student : students) {
            if (student.rollNo == rollNo) {
                cout << "Enter new details for " << rollNo << endl;
                cout << "Enter name: ";
                cin >> student.name;
                cout << "Enter Roll No: ";
                cin >> student.rollNo;
                cout << "Enter Course: ";
                cin >> student.course;
                cout << "Enter Class: ";
                cin >> student.className;
                cout << "Enter Contact: ";
                cin >> student.contact;
                return;
            }
        }
        cout << "Student with roll number " << rollNo << " not found." << endl;
    }

    // Function to delete a student record
    void deleteStudent(string rollNo) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->rollNo == rollNo) {
                students.erase(it);
                cout << "Record deleted successfully." << endl;
                return;
            }
        }
        cout << "Student with roll number " << rollNo << " not found." << endl;
    }

    // Function to delete all student records
    void deleteAll() {
        students.clear();
        cout << "All records deleted." << endl;
    }
};

int main() {
    StudentManager manager;
    int choice;
    string rollNo;

    while (true) {
        cout << "\n1. Add Student\n2. Display All Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Delete All Records\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.displayAll();
                break;
            case 3:
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                manager.searchStudent(rollNo);
                break;
            case 4:
                cout << "Enter Roll No to update: ";
                cin >> rollNo;
                manager.updateStudent(rollNo);
                break;
            case 5:
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                manager.deleteStudent(rollNo);
                break;
            case 6:
                manager.deleteAll();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

 
