#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


// Represents a student.
//
struct Student {
    string firstName;
    string lastName;
    string id;
    double currentGrade;
};


// Represents a collection of students.
//
struct Roster {
    Student *students;
    int studentCount;
};


// Loads the student information from the specified file and returns a roster. The specified file should have the
// following format: Each line should contain four values
// 
//    studentId firstName lastName currentGrade
//
// where studentId is a string of numbers (without spaces), firstName is a string (without spaces), lastName is a
// string (without spaces), and currentGrade is a floating point value.
//
Roster* loadRoster(string filepath);


// Sorts the students in the roster in descending order (highest GPA first).
//
void sortStudentsByGPA(const Roster *roster);


// Writes the information from the first count number of students in the roster to the specified file. Each student
// will be displayed in the following format:
//
//     id :: lastName, firstName :: gpa
//
void exportRoster(string filepath, const Roster *roster, const int count);




int main() {
    cout<<"loading.";
    Roster *roster = loadRoster("studentData.txt");
    cout<<"loading.";
    sortStudentsByGPA(roster);
    cout<<"loading.";
    exportRoster("sortedStudentData.txt", roster, 15);
    cout<<"loading.";
    return 0;

}



// See declaration for description.
//
Roster* loadRoster(string filepath) {

    ifstream inFile;
    inFile.open(filepath);
    Roster *result = new Roster;
    int i =0;
    const int STEP =10;

    result->students= new Student [STEP];

    while(!inFile.eof())
    {
        inFile >> result->students[i].id;
        inFile >> result->students[i].firstName;
        inFile >> result->students[i].lastName;
        inFile >> result->students[i].currentGrade;

        if(i%STEP ==0)
        {
            Student *temp = new Student[i +STEP];

            for(int j=0; j< i; ++j)
            {
                temp[j].id = result->students[j].id;
                temp[j].firstName = result->students[j].firstName;
                temp[j].lastName = result->students[j].lastName;
                temp[j].currentGrade = result->students[j].currentGrade;

            }

            delete [] result->students;

            result->students = temp;
        }
        ++i;
    }
    result->studentCount =i;

    return result;

}


// See declaration for description.
//
void sortStudentsByGPA(const Roster *roster) {

    bool isSwap =true;
    while(isSwap)
    {
        for(int i =0; i<roster->studentCount; ++i)
        {
            for(int j =0; j<roster->studentCount; ++j)
            {
                if(roster->students[i].currentGrade > roster->students[j].currentGrade)
                {
                    double temp = roster->students[j].currentGrade;
                    roster->students[j].currentGrade = roster->students[i].currentGrade;
                    roster->students[i].currentGrade = temp;
                    isSwap =true;
                }
            }
        }
    }
}


// See declaration for description.
//
void exportRoster(string filepath, const Roster *roster, const int count=25) {
    ofstream outFile;
    outFile.open(filepath);

    for(int i =0; i < count; ++i)
    {
        outFile << roster->students[i].id 
        << " :: " 
        << roster->students[i].lastName 
        <<", "
        << roster->students[i].firstName 
        << " :: "
        << roster->students[i].currentGrade<<endl;
    }
}

