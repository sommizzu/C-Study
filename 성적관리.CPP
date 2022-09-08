#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

enum SUBJECT {BEG = 0, ITEC = BEG, ELEC, ENGL, MATH, HIST, END, SIZE = END};
std::string SUBJECT_LABEL[] = {"ITEC", "ELEC", "ENGL", "MATH", "HIST"};

struct StudentT {
    int ID = 0;
    double Score[SUBJECT::SIZE] = {0,};
    double Total = 0;
    double Average = 0;
    std::string Grade;

    void calcScore() {
        calcTotal();
        calcAverage();
        setGrade();
    }

    std::string to_string() const {
        std::ostringstream oss;
        oss << ID;
        for (size_t i = 0; i < SUBJECT::SIZE; i++) oss << '\t' << Score[i];
        oss << '\t' << Total << '\t' << Average << '\t' << Grade;
        return oss.str();
    }
private:    
    // calculate total point
    void calcTotal() {
        for (size_t i = 0; i < SUBJECT::SIZE; Total+=Score[i++]);
    }
    // calculate average
    void calcAverage() {
        Average = Total/static_cast<double>(SUBJECT::SIZE);
    }
    // set grade using average
    void setGrade() {
        if (Average >= 97) Grade = "A+";
        else if (Average >= 94) Grade = "A0";
        else if (Average >= 90) Grade = "A-";
        else if (Average >= 87) Grade = "B+";
        else if (Average >= 84) Grade = "B0";
        else if (Average >= 80) Grade = "B-";
        else if (Average >= 77) Grade = "C+";
        else if (Average >= 74) Grade = "C0";
        else if (Average >= 70) Grade = "C-";
        else if (Average >= 67) Grade = "D+";
        else if (Average >= 64) Grade = "D0";
        else if (Average >= 60) Grade = "D-";
        else Grade = "F";
    }
};

std::ostream& operator<<(std::ostream& os, const StudentT& s) {
    os << s.to_string();
    return os;
}

bool operator< (const StudentT& s1, const StudentT& s2) { return s1.Average < s2.Average; }
bool operator>=(const StudentT& s1, const StudentT& s2) { return !(s1.Average < s2.Average); }
bool operator> (const StudentT& s1, const StudentT& s2) { return s1.Average > s2.Average; }
bool operator<=(const StudentT& s1, const StudentT& s2) { return !(s1.Average > s2.Average); }

// type define container of student
using StudentContainerT = std::vector<StudentT>;
void setStudentScore(StudentT& s);
void printSummary(std::ostream& os, const StudentContainerT& StudentContainer);

using namespace std;

int main() {
    try {
        StudentContainerT StudentContainer;
        StudentContainer.resize(20);
        // init score of students
        for (size_t i = 0; i < StudentContainer.size(); i++) {
            StudentContainer[i].ID = i+1;
            setStudentScore(StudentContainer[i]);
        }
        // sort order by average descending
        sort(StudentContainer.begin(), StudentContainer.end(), greater<>());
        // print summary
        printSummary(cout, StudentContainer);
    }
    catch (const exception& ex) {
        cerr << ex.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch (...) {
        cerr << "It has been caught unknown exception." << endl;
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

void setStudentScore(StudentT& s) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::normal_distribution<> d{85, 15};

    for (size_t i = SUBJECT::BEG; i < SUBJECT::END; i++) {
        auto score = round(d(generator));
        if (score > 100) score = 100;
        if (score < 0) score = 0;
        s.Score[i] = score;
    }
    s.calcScore();
}

void printSummary(ostream& os, const StudentContainerT& StudentContainer) {
    string Line(70, '-');
    os << Line << endl;    
    os << "ID";
    for (size_t i = SUBJECT::BEG; i < SUBJECT::END; i++) os << '\t' << SUBJECT_LABEL[i];
    os << "\tTOTAL\tAVG\tGRADE" << endl;
    os << Line << endl;

    StudentT sum, avg;
    for (const auto& e: StudentContainer) {
        os << e << endl;
        for (size_t i = SUBJECT::BEG; i < SUBJECT::END; i++) sum.Score[i] += e.Score[i];
    }

    for (size_t i = SUBJECT::BEG; i < SUBJECT::END; i++) {
        avg.Score[i] = sum.Score[i] / static_cast<double>(StudentContainer.size());
    }
    avg.calcScore();
    os << Line << endl;
    os << avg << endl;
}