#include <iostream>
#include <fstream>   // File handling
#include <sstream>   // String parsing
#include <vector>
#include <unordered_map>  // Hash table for course storage

using namespace std;

// Course class
class Course {
public:
    string courseID;
    string courseName;
    vector<string> prerequisites;

    Course() {}  // Default constructor

    Course(string id, string name, vector<string> prereqs)
        : courseID(id), courseName(name), prerequisites(prereqs) {}
};

// Course Planner class
class CoursePlanner {
private:
    unordered_map<string, Course> courseCatalog;  // Hash table to store courses

public:
    void loadCourses(const string& filename);
    void printCourseList();
    void printCourseInfo(const string& courseID);
};

// Function to load courses from CSV file
void CoursePlanner::loadCourses(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Cannot open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseID, courseName, prereq;
        vector<string> prerequisites;

        getline(ss, courseID, ',');
        getline(ss, courseName, ',');

        while (getline(ss, prereq, ',')) {
            prerequisites.push_back(prereq);
        }

        Course newCourse(courseID, courseName, prerequisites);
        courseCatalog[courseID] = newCourse;
    }

    cout << "Data successfully loaded.\n";
}

// Function to print the sorted list of courses
void CoursePlanner::printCourseList() {
    cout << "Here is a sorted course list:\n";
    for (const auto& pair : courseCatalog) {
        cout << pair.first << ": " << pair.second.courseName << endl;
    }
}

// Function to print course details and prerequisites
void CoursePlanner::printCourseInfo(const string& courseID) {
    if (courseCatalog.find(courseID) != courseCatalog.end()) {
        Course c = courseCatalog[courseID];
        cout << c.courseID << ": " << c.courseName << endl;
        cout << "Prerequisites: ";
        if (c.prerequisites.empty()) {
            cout << "None";
        }
        else {
            for (const string& prereq : c.prerequisites) {
                cout << prereq << " ";
            }
        }
        cout << endl;
    }
    else {
        cout << "Course not found.\n";
    }
}

// Function to display the main menu
void displayMenu() {
    cout << "\nCourse Planner Menu:\n";
    cout << "1. Load Data Structure\n";
    cout << "2. Print Course List\n";
    cout << "3. Print Course Information\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    CoursePlanner planner;
    int choice;
    string courseID;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();  // Prevent input issues

        switch (choice) {
        case 1:
            planner.loadCourses("CS 300 ABCU_Advising_Program_Input.csv");
            break;
        case 2:
            planner.printCourseList();
            break;
        case 3:
            cout << "Enter course ID (e.g., CSCI400): ";
            cin >> courseID;
            planner.printCourseInfo(courseID);
            break;
        case 9:
            cout << "Thank you for using the Course Planner. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
