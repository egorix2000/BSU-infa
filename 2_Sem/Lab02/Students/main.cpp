#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include "Student.h"
#include "FileLib.h"

using namespace std;

Student& parseStudentString(string line, Student& student) {
    string surname;
    int groupNumber;
    vector<int> marks;
    int mark;

    stringstream ss;
    ss << line;
    ss >> surname >> groupNumber;
    student.setSurname(surname);
    student.setGroupNumber(groupNumber);
    while (ss >> mark) {
        marks.push_back(mark);
    }
    student.setMarks(marks);
    return student;
}

vector<Student>& deleteStudent(vector<Student>& students) {
    string surname;
    cout << "Delete student. Enter surname: ";
    cin >> surname;
    students.erase(remove_if(students.begin(), students.end(), [surname](Student& student){
        return student.getSurname() == surname;
    }), students.end());

    cout << "Done! Student " << surname << " has been deleted." << endl;
    return students;
}

vector<Student>& showStudents(vector<Student>& students) {
    for (int i = 0; i < students.size(); i++) {
        cout << students[i];
    }
    return students;
}

int main()
{
    vector<Student> students;
    map<string, Student> studentsMap;
    map<string, Student> failStudents;

    Student student;
    string error;
    string line;
    ifstream fin;

    fin.open("input.txt");

    if(validateFile(fin, error)){

        while (getline(fin, line)){
            parseStudentString(line, student);
            students.push_back(student);
        }

        //sort by surname ASC
        sort(students.begin(), students.end(), [](Student& student1, Student& student2) {
            return student1.getSurname() < student2.getSurname();
        });
        cout << "Sorted students:" << endl;
        showStudents(students);

        //delete student by name
        deleteStudent(students);
        cout << "Surviving students:" << endl;
        showStudents(students);

        //generate map
        for (int i = 0; i < students.size(); i++) {
            studentsMap[students[i].getSurname()] = students[i];
        }

        //find students failed exams
        bool doesFail;
        copy_if(studentsMap.begin(), studentsMap.end(),inserter(failStudents, failStudents.begin()),
                [doesFail](const pair<string, Student>& studentP) mutable -> bool {
                    doesFail = false;
                    for (int i = 0; i < studentP.second.getMarks().size(); i++) {
                        if (studentP.second.getMarks()[i] < 4) {
                            doesFail = true;
                            break;
                        }
                    }
                    return doesFail;
        });
        cout << "Students who failed exams:" << endl;
        for (map<string, Student>::iterator it = failStudents.begin(); it != failStudents.end(); it++) {
            cout << (*it).first << endl;
        }

        //find the best student
        cout << "Best student: ";
        cout << (*max_element(studentsMap.begin(), studentsMap.end(), [](const pair<string, Student>& studentP1, const pair<string, Student>& studentP2){
            return accumulate(studentP1.second.getMarks().begin(), studentP1.second.getMarks().end(), 0) <
                    accumulate(studentP2.second.getMarks().begin(), studentP2.second.getMarks().end(), 0);
        })).first;
    } else {
        cout << error << endl;
    }

    fin.close();
    return 0;
}