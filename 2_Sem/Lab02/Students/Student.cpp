#include "Student.h"

Student::Student() {
    surname_ = "";
    groupNumber_ = 0;
}

Student::Student(string surname, int groupNumber, const vector<int> &marks) {
    surname_ = surname;
    groupNumber_ = groupNumber;
    marks_ = vector<int> (marks);
}

Student::Student(const Student &source) {
    surname_ = source.getSurname();
    groupNumber_ = source.getGroupNumber();
    marks_ = vector<int> (source.getMarks());
}

string Student::getSurname() const {
    return surname_;
}

int Student::getGroupNumber() const {
    return groupNumber_;
}

vector<int> Student::getMarks() const {
    return marks_;
}

void Student::setSurname(string surname) {
    surname_ = surname;
}

void Student::setGroupNumber(int groupNumber) {
    groupNumber_ = groupNumber;
}
void Student::setMarks(const vector<int>& marks) {
    marks_ = vector<int> (marks);
}


std::ostream& operator << (std::ostream &stream, const Student& student) {
    stream << student.getSurname() << " " << student.getGroupNumber() << " ";
    for (int i = 0; i < student.getMarks().size(); i++) {
        stream << student.getMarks()[i] << " ";
    }
    cout << endl;
    return stream;
}

Student& Student::operator=(const Student& right) {
    if (this == &right) {
        return *this;
    }
    surname_ = right.getSurname();
    groupNumber_ = right.getGroupNumber();
    marks_ = vector<int> (right.getMarks());
    return *this;
}