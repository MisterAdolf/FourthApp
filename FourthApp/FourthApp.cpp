#include <iostream>
#include <ctime>
using namespace std;

int main() {
    const int num_students = 5;
    const int num_grades = 13;
    int grades[num_students][num_grades];


    srand(time(0));


    for (int i = 0; i < num_students; i++) {
        for (int j = 0; j < num_grades; j++) {
            grades[i][j] = rand() % 12 + 1;
        }
    }


    cout << "students grades:" << endl;
    for (int i = 0; i < num_students; i++) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < num_grades; j++) {
            cout << grades[i][j] << " ";
        }
        cout << endl;
    }


    double average_grades[num_students];
    for (int i = 0; i < num_students; i++) {
        int sum = 0;
        for (int j = 0; j < num_grades; j++) {
            sum += grades[i][j];
        }
        average_grades[i] = sum / (double)num_grades;
        cout << "Average student grade " << i + 1 << ": " << average_grades[i] << endl;


        if (average_grades[i] < 6) {
            cout << "student " << i + 1 << " not certified." << endl;
        }
    }


    int excellent_students = 0;
    for (int i = 0; i < num_students; i++) {
        if (average_grades[i] > 8) {
            excellent_students++;
        }
    }
    if (excellent_students > num_students / 2) {
        cout << "Class - excellent students" << endl;
    }


    for (int i = 0; i < num_students; i++) {
        int high_grades_count = 0;
        cout << "Student " << i + 1 << " grades <9: ";
        for (int j = 0; j < num_grades; j++) {
            if (grades[i][j] > 9) {
                cout << grades[i][j] << " ";
                high_grades_count++;
            }
        }
        if (high_grades_count > num_grades / 2) {
            cout << " - excellent student";
        }
        cout << endl;
    }


    for (int i = 0; i < num_students; i++) {
        for (int j = 0; j < num_grades; j++) {
            if (grades[i][j] < 9) {
                int attempts = 3;
                while (attempts > 0 && grades[i][j] < 9) {
                    cout << "Student " << i + 1 << ", grade for subject " << j + 1 << ": "
                        << grades[i][j] << " - is insufficient. An attempt to fix it." << endl;
                    grades[i][j] = rand() % 12 + 1;
                    attempts--;
                }
                cout << "Final grade for the subject " << j + 1 << ": " << grades[i][j] << endl;
            }
        }
    }


    for (int j = 0; j < num_grades; j++) {
        bool all_below_9 = true;
        for (int i = 0; i < num_students; i++) {
            if (grades[i][j] >= 9) {
                all_below_9 = false;
                break;
            }
        }
        if (all_below_9) {
            cout << "subject " << j + 1 << ": all students have a grade below 9." << endl;
        }
    }

    return 0;
}
