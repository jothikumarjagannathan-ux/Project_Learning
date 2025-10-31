#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    float marks[3];  // marks in 3 subjects

public:
    void input() {
        cout << "\nEnter student name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter roll number: ";
        cin >> rollNo;

        cout << "Enter marks for 3 subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }

    float average() {
        float sum = 0;
        for (int i = 0; i < 3; i++)
            sum += marks[i];
        return sum / 3;
    }

    char grade() {
        float avg = average();
        if (avg >= 90) return 'A';
        else if (avg >= 75) return 'B';
        else if (avg >= 50) return 'C';
        else return 'F';
    }

    void display() {
        cout << "\nStudent Name : " << name;
        cout << "\nRoll Number  : " << rollNo;
        cout << "\nAverage Marks: " << fixed << setprecision(2) << average();
        cout << "\nGrade        : " << grade() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[n];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter details for student " << i + 1 << " ---";
        s[i].input();
    }

    cout << "\n--- Student Report Cards ---";
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    return 0;
}
