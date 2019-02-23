#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <map>

#include "FileLib.h"

using namespace std;

struct Student {
    char name[20];
    int group;
    double mark;

    friend std::ostream& operator << (std::ostream &stream, const Student& student) {
        cout << student.name;
        return stream;
    }
};

Student& parseStudentString(string line, Student& student) {
    char name[20];
    int group;
    double mark;

    stringstream ss;
    ss << line;
    ss >> name >> group >> mark;
    strcpy(student.name, name);
    student.group = group;
    student.mark = mark;
    return student;
}

void printCountOfStudentsWithGivenMark(vector<Student>& students) {
    double mark;
    cout << "Enter mark: ";
    cin >> mark;
    cout << "Number of students with mark '" << mark << "': ";
    cout << count_if(students.begin(), students.end(), [mark](Student& student) {
        return student.mark == mark;
    });
    cout << endl;
}

void printStudentsWithGivenGroup(vector<Student>& students) {
    int group;
    cout << "Enter group: ";
    cin >> group;
    cout << "Students from group '" << group << "': ";
    copy_if(students.begin(), students.end(),
            std::ostream_iterator<Student>(std::cout, " "), [group](Student& student) {
        return student.group == group;
    });
    cout << endl;
}

vector<Student>& showStudents(vector<Student>& students) {
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].name << ' ' << students[i].group << ' ' << students[i].mark << endl;
    }
    return students;
}

int main()
{
    vector<Student> students;
    vector<Student> studentsReverse;
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
        cout << "All students: " << endl;
        showStudents(students);
        cout << endl;

        //# of students with given mark
        printCountOfStudentsWithGivenMark(students);
        cout << endl;

        //students with given group
        printStudentsWithGivenGroup(students);
        cout << endl;

        //reverse
        studentsReverse.resize(students.size());
        copy(students.begin(), students.end(), studentsReverse.begin());
        reverse(studentsReverse.begin(), studentsReverse.end());
        cout << "Reversed students: " << endl;
        showStudents(studentsReverse);
        cout << endl;

        //sort by name
        sort(students.begin(), students.end(), [](const Student& st1, const Student& st2) {
            bool a = strcmp(st1.name, st2.name);
            return lexicographical_compare(st1.name, st1.name+20, st2.name, st2.name+20);
        });
        cout << "Students sorted by name: " << endl;
        showStudents(students);
        cout << endl;

        //sort by group and name
        sort(students.begin(), students.end(), [](const Student& st1, const Student& st2) {
            return st1.group != st2.group ? st1.group > st2.group : lexicographical_compare(st1.name, st1.name+20, st2.name, st2.name+20);
        });
        cout << "Students sorted by group and name: " << endl;
        showStudents(students);
        cout << endl;

        //sort by mark
        sort(students.begin(), students.end(), [](const Student& st1, const Student& st2) {
            return st1.mark > st2.mark;
        });
        cout << "Students sorted by mark: " << endl;
        showStudents(students);
        cout << endl;

    } else {
        cout << error << endl;
    }

    fin.close();
    return 0;
}