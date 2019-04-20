#ifndef Database_h
#define Database_h

#include <map>
#include <set>
#include <string>
#include <fstream>

using namespace std;

class Database {
private:
    ifstream fin_;
    ofstream fout_;
    string resultFile_;
    map<string, int> scores_;
    
    Database(string resultFile);
    Database(const Database& database) = delete;
    Database& operator =(const Database&) = delete;
public:
    static Database& getInstance(string resultFile);
    Database& readScores();
    Database& writeScores();
    void setResultFile(string resultFile);
    string getResultFile() const;
    Database& addPoint(string name);
};

Database& Database::getInstance(string resultFile) {
    static Database database (resultFile);
    return database;
}

Database::Database(string resultFile) {
    resultFile_ = resultFile;
}

Database& Database::readScores() {
    fin_.open(resultFile_);
    
    string name;
    int score;
    
    while(fin_ >> name >> score) {
        scores_[name] = score;
    }
    
    fin_.close();
    return *this;
}

Database& Database::writeScores() {
    fout_.open(resultFile_, std::ofstream::out | std::ofstream::trunc);
    multimap<int, string> orderedScores;
    
    for (std::map<string, int>::iterator it = scores_.begin(); it != scores_.end(); it++) {
        orderedScores.insert( std::pair<int, string>((*it).second, (*it).first) );
    }
    for (std::map<int, string>::reverse_iterator it = orderedScores.rbegin(); it != orderedScores.rend(); it++) {
        fout_ << (*it).second << " " << (*it).first << endl;
    }
    fout_.close();
    return *this;
}

void Database::setResultFile(string resultFile) {
    resultFile_ = resultFile;
}

string Database::getResultFile() const {
    return resultFile_;
}

Database& Database::addPoint(string name) {
    std::map<string, int>::iterator it = scores_.find(name);
    if (it != scores_.end()) {
        scores_[name]++;
    } else {
        scores_[name] = 1;
    }
    return *this;
}

#endif /* Database_h */
