#ifndef LAB_STUDENT_H
#define LAB_STUDENT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Student {
private:
    string surname_;
    int groupNumber_;
    vector<int> marks_;
public:
    Student();
    Student(string surname, int groupNumber, const vector<int>& marks);
    Student(const Student& source);
    string getSurname() const;
    int getGroupNumber() const;
    vector<int> getMarks() const;
    void setSurname(string surname);
    void setGroupNumber(int groupNumber);
    void setMarks(const vector<int>& marks);
    friend std::ostream& operator << (std::ostream &stream, const Student& student);
    Student& operator=(const Student& right);
};

#endif //LAB_STUDENT_H
