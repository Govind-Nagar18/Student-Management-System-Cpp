#ifndef STUDENT_MANAGEMENT_SYSTEM_H
#define STUDENT_MANAGEMENT_SYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Student {
private:
    int studentID;
    string name;
    int age;
    string address;
    string phoneNumber;
    map<int, double> courseGrades; 

public:
    Student(int id, string name, int age, string address, string phoneNumber);

    void addCourseGrade(int courseID, double grade);
    void updateInfo(string newAddress, string newPhoneNumber);
    void displayStudentInfo() const;
    double calculateGPA() const;
    int getStudentID() const;
};

class Course {
private:
    int courseID;
    string courseName;
    int credits;

public:
    Course(int id, string name, int credits);
    void displayCourseInfo() const;
    int getCourseID() const;
    string getCourseName() const;
};

void addStudent(vector<Student>& students);
void addCourse(vector<Course>& courses);
void enrollStudentInCourse(vector<Student>& students, vector<Course>& courses);
void addStudentGrades(vector<Student>& students, vector<Course>& courses);
void viewStudentDetails(const vector<Student>& students);
void displayMenu();

#endif

Student::Student(int id, string name, int age, string address, string phoneNumber)
    : studentID(id), name(name), age(age), address(address), phoneNumber(phoneNumber) {}

void Student::addCourseGrade(int courseID, double grade) {
    courseGrades[courseID] = grade;
}

void Student::updateInfo(string newAddress, string newPhoneNumber) {
    address = newAddress;
    phoneNumber = newPhoneNumber;
}

void Student::displayStudentInfo() const {
    cout << "Student ID: " << studentID << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Grades: " << endl;
    for (const auto& courseGrade : courseGrades) {
        cout << "Course ID: " << courseGrade.first << " - Grade: " << courseGrade.second << endl;
    }
    cout << "GPA: " << calculateGPA() << endl;
}

double Student::calculateGPA() const {
    if (courseGrades.empty()) return 0.0;
    double total = 0.0;
    for (const auto& courseGrade : courseGrades) {
        total += courseGrade.second;
    }
    return total / courseGrades.size();
}

int Student::getStudentID() const {
    return studentID;
}

Course::Course(int id, string name, int credits)
    : courseID(id), courseName(name), credits(credits) {}

void Course::displayCourseInfo() const {
    cout << "Course ID: " << courseID << endl;
    cout << "Course Name: " << courseName << endl;
    cout << "Credits: " << credits << endl;
}

int Course::getCourseID() const {
    return courseID;
}

string Course::getCourseName() const {
    return courseName;
}

void addStudent(vector<Student>& students) {
    int id, age;
    string name, address, phone;

    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter address: ";
    getline(cin, address);

    cout << "Enter phone number: ";
    getline(cin, phone);

    students.emplace_back(id, name, age, address, phone);
    cout << "Student added successfully!" << endl;
}

void addCourse(vector<Course>& courses) {
    int id, credits;
    string name;

    cout << "Enter course ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter course name: ";
    getline(cin, name);

    cout << "Enter credits: ";
    cin >> credits;

    courses.emplace_back(id, name, credits);
    cout << "Course added successfully!" << endl;
}

void enrollStudentInCourse(vector<Student>& students, vector<Course>& courses) {
    int studentID, courseID;
    cout << "Enter student ID to enroll: ";
    cin >> studentID;

    cout << "Enter course ID: ";
    cin >> courseID;

    for (auto& student : students) {
        if (student.getStudentID() == studentID) {
            student.addCourseGrade(courseID, 0);
            cout << "Student enrolled in course successfully!" << endl;
            return;
        }
    }
    cout << "Student or Course not found!" << endl;
}

void addStudentGrades(vector<Student>& students, vector<Course>& courses) {
    int studentID, courseID;
    double grade;

    cout << "Enter student ID: ";
    cin >> studentID;

    cout << "Enter course ID: ";
    cin >> courseID;

    cout << "Enter grade: ";
    cin >> grade;

    for (auto& student : students) {
        if (student.getStudentID() == studentID) {
            student.addCourseGrade(courseID, grade);
            cout << "Grade added successfully!" << endl;
            return;
        }
    }
    cout << "Student or Course not found!" << endl;
}

void viewStudentDetails(const vector<Student>& students) {
    int studentID;
    cout << "Enter student ID: ";
    cin >> studentID;

    for (const auto& student : students) {
        if (student.getStudentID() == studentID) {
            student.displayStudentInfo();
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void displayMenu() {
    cout << "\n--- Student Management System ---" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Add Course" << endl;
    cout << "3. Enroll Student in Course" << endl;
    cout << "4. Add Student Grades" << endl;
    cout << "5. View Student Details" << endl;
    cout << "6. Exit" << endl;
}

int main() {
    vector<Student> students;
    vector<Course> courses;

    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students);
            break;
        case 2:
            addCourse(courses);
            break;
        case 3:
            enrollStudentInCourse(students, courses);
            break;
        case 4:
            addStudentGrades(students, courses);
            break;
        case 5:
            viewStudentDetails(students);
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}

