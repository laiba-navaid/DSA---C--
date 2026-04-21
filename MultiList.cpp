#include <iostream>
using namespace std;

// STRUCTS 
struct SNode {
    int SNO;       // Student Seat Number
    SNode* SNext;  // Pointer to next student
};

struct CNode {
    int CNO;       // Course Number
    SNode* StuList; // Pointer to student list
    CNode* CNext;   // Pointer to next course
};

CNode* CList = NULL; // Start of course list

// COURSE FUNCTIONS

// Add a course
void addCourse(int cno) {
    CNode* tmp = new CNode;
    tmp->CNO = cno;
    tmp->StuList = NULL;
    tmp->CNext = NULL;

    if (CList == NULL)
        CList = tmp;
    else {
        CNode* cur = CList;
        while (cur->CNext != NULL)
            cur = cur->CNext;
        cur->CNext = tmp;
    }
    cout << "Course " << cno << " added.\n";
}

// Update a course number
void updateCourse(int oldCno, int newCno) {
    CNode* course = CList;
    while (course != NULL) {
        if (course->CNO == oldCno) {
            course->CNO = newCno;
            cout << "Course " << oldCno << " updated to " << newCno << ".\n";
            return;
        }
        course = course->CNext;
    }
    cout << "Course " << oldCno << " not found.\n";
}

// Delete a course and all its students
void deleteCourse(int cno) {
    if (CList == NULL) {
        cout << "No courses to delete.\n";
        return;
    }

    CNode* cur = CList;
    CNode* prev = NULL;

    while (cur != NULL && cur->CNO != cno) {
        prev = cur;
        cur = cur->CNext;
    }

    if (cur == NULL) {
        cout << "Course not found.\n";
        return;
    }

    // Delete all students in this course
    SNode* sCur = cur->StuList;
    while (sCur != NULL) {
        SNode* del = sCur;
        sCur = sCur->SNext;
        delete del;
    }

    // Remove course from list
    if (prev == NULL)
        CList = cur->CNext;
    else
        prev->CNext = cur->CNext;

    delete cur;
    cout << "Course " << cno << " deleted successfully.\n";
}

// Search a course
CNode* searchCourse(int cno) {
    CNode* cur = CList;
    while (cur != NULL) {
        if (cur->CNO == cno)
            return cur;
        cur = cur->CNext;
    }
    return NULL;
}

// Display all course numbers
void displayCourses() {
    if (CList == NULL) {
        cout << "No courses available.\n";
        return;
    }
    cout << "Courses: ";
    CNode* cur = CList;
    while (cur != NULL) {
        cout << cur->CNO << " ";
        cur = cur->CNext;
    }
    cout << endl;
}

//  STUDENT FUNCTIONS

// Add student to a course
void addStudent(int cno, int sno) {
    CNode* course = searchCourse(cno);
    if (!course) {
        cout << "Course not found.\n";
        return;
    }

    SNode* tmp = new SNode;
    tmp->SNO = sno;
    tmp->SNext = NULL;

    if (course->StuList == NULL)
        course->StuList = tmp;
    else {
        SNode* cur = course->StuList;
        while (cur->SNext != NULL)
            cur = cur->SNext;
        cur->SNext = tmp;
    }
    cout << "Student " << sno << " added to course " << cno << ".\n";
}

// Delete student from a course
void deleteStudentFromCourse(int cno, int sno) {
    CNode* course = searchCourse(cno);
    if (!course) {
        cout << "Course not found.\n";
        return;
    }

    SNode* cur = course->StuList;
    SNode* prev = NULL;

    while (cur != NULL && cur->SNO != sno) {
        prev = cur;
        cur = cur->SNext;
    }

    if (!cur) {
        cout << "Student not found in course.\n";
        return;
    }

    if (!prev)
        course->StuList = cur->SNext;
    else
        prev->SNext = cur->SNext;

    delete cur;
    cout << "Student " << sno << " deleted from course " << cno << ".\n";
}

// Delete student from all courses
void deleteStudentEverywhere(int sno) {
    CNode* ccur = CList;
    bool found = false;

    while (ccur != NULL) {
        SNode* cur = ccur->StuList;
        SNode* prev = NULL;

        while (cur != NULL) {
            if (cur->SNO == sno) {
                if (!prev)
                    ccur->StuList = cur->SNext;
                else
                    prev->SNext = cur->SNext;

                SNode* del = cur;
                cur = cur->SNext;
                delete del;
                found = true;
            } else {
                prev = cur;
                cur = cur->SNext;
            }
        }
        ccur = ccur->CNext;
    }

    if (found)
        cout << "Student " << sno << " deleted from all courses.\n";
    else
        cout << "Student not found.\n";
}

// Search student in a specific course
void searchStudentInCourse(int cno, int sno) {
    CNode* course = searchCourse(cno);
    if (!course) {
        cout << "Course not found.\n";
        return;
    }

    SNode* cur = course->StuList;
    while (cur != NULL) {
        if (cur->SNO == sno) {
            cout << "Student " << sno << " found in course " << cno << ".\n";
            return;
        }
        cur = cur->SNext;
    }

    cout << "Student not found in this course.\n";
}

// Search student anywhere
void searchStudentEverywhere(int sno) {
    CNode* ccur = CList;
    bool found = false;

    while (ccur != NULL) {
        SNode* cur = ccur->StuList;
        while (cur != NULL) {
            if (cur->SNO == sno) {
                cout << "Student " << sno << " found in course " << ccur->CNO << ".\n";
                found = true;
            }
            cur = cur->SNext;
        }
        ccur = ccur->CNext;
    }

    if (!found)
        cout << "Student not found in any course.\n";
}

// Display student list of a course
void displayStudentsOfCourse(int cno) {
    CNode* course = searchCourse(cno);
    if (!course) {
        cout << "Course not found.\n";
        return;
    }

    if (!course->StuList) {
        cout << "No students in course " << cno << ".\n";
        return;
    }

    cout << "Students in course " << cno << ": ";
    SNode* cur = course->StuList;
    while (cur != NULL) {
        cout << cur->SNO << " ";
        cur = cur->SNext;
    }
    cout << endl;
}

// Display all courses and students
void displayAll() {
    if (!CList) {
        cout << "No courses available.\n";
        return;
    }

    CNode* ccur = CList;
    while (ccur != NULL) {
        cout << "Course " << ccur->CNO << ": ";
        SNode* scur = ccur->StuList;
        if (!scur)
            cout << "No students";
        while (scur != NULL) {
            cout << scur->SNO << " ";
            scur = scur->SNext;
        }
        cout << endl;
        ccur = ccur->CNext;
    }
}

// ---------------- MAIN MENU ----------------
int main() {
    int choice, cno, sno, newCno;

    do {
        cout << "\n====== Course Management Menu ======\n";
        cout << "1- Add a course\n";
        cout << "2- Delete a course\n";
        cout << "3- Search a course\n";
        cout << "4- Display list of courses\n";
        cout << "5- Add a student to a course\n";
        cout << "6- Delete a student from a course\n";
        cout << "7- Delete a student from everywhere\n";
        cout << "8- Search a student in a course\n";
        cout << "9- Search a student (Seat No)\n";
        cout << "10- Display student list of a course\n";
        cout << "11- Display all courses and students\n";
        cout << "12- Update a course number\n";
        cout << "13- Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter course number: "; cin >> cno;
                addCourse(cno);
                break;
            case 2:
                cout << "Enter course number to delete: "; cin >> cno;
                deleteCourse(cno);
                break;
            case 3:
                cout << "Enter course number to search: "; cin >> cno;
                if (searchCourse(cno)) cout << "Course " << cno << " found.\n";
                else cout << "Course not found.\n";
                break;
            case 4:
                displayCourses();
                break;
            case 5:
                cout << "Enter course number: "; cin >> cno;
                cout << "Enter student seat number: "; cin >> sno;
                addStudent(cno, sno);
                break;
            case 6:
                cout << "Enter course number: "; cin >> cno;
                cout << "Enter student seat number: "; cin >> sno;
                deleteStudentFromCourse(cno, sno);
                break;
            case 7:
                cout << "Enter student seat number: "; cin >> sno;
                deleteStudentEverywhere(sno);
                break;
            case 8:
                cout << "Enter course number: "; cin >> cno;
                cout << "Enter student seat number: "; cin >> sno;
                searchStudentInCourse(cno, sno);
                break;
            case 9:
                cout << "Enter student seat number: "; cin >> sno;
                searchStudentEverywhere(sno);
                break;
            case 10:
                cout << "Enter course number: "; cin >> cno;
                displayStudentsOfCourse(cno);
                break;
            case 11:
                displayAll();
                break;
            case 12:
                cout << "Enter current course number: "; cin >> cno;
                cout << "Enter new course number: "; cin >> newCno;
                updateCourse(cno, newCno);
                break;
            case 13:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 13);

    return 0;
}


// #include <iostream>
// #include <cstdlib>
// using namespace std;

// struct SNode 
// {
//     int SNo;
//     SNode* SNext;
// };

// struct CNode
// {
//     int CNo;
//     CNode* CNext;
//     SNode* Stu_List;
// };

// CNode* C_List = NULL;

// void insert_Course(int CNo)
// {
//     CNode* tmp;
//     tmp = (CNode*) malloc(sizeof(CNode));
//     tmp->CNo = CNo;
//     tmp->CNext = NULL;
//     tmp->Stu_List = NULL;

//     if(C_List == NULL)
//     {
//         C_List = tmp;
//     } else 
//     {
//         CNode* Ccurrent = C_List;
//         while(Ccurrent->CNext != NULL) 
//         {
//             Ccurrent = Ccurrent->CNext;
//         }

//         Ccurrent->CNext = tmp;
//     } 
// }

// void insert_Student(int SNo, int CNo) 
// {
//     CNode* Ccurrent = C_List;
//     while(Ccurrent != NULL) 
//     {
//         if(CNo == Ccurrent->CNo) 
//         {
//             SNode* tmp;
//             tmp = (SNode*) malloc(sizeof(SNode));
//             tmp->SNo = SNo;
//             tmp->SNext = NULL;
//             if(Ccurrent->Stu_List == NULL) 
//             {
//                 Ccurrent->Stu_List =tmp;
//                 // return;
//             } else 
//             {
//                 SNode* Scurrent;
//                 Scurrent = Ccurrent->Stu_List;
//                 while(Scurrent->SNext != NULL) {
//                     Scurrent = Scurrent->SNext;
//                 }
//                 Scurrent->SNext = tmp;
//             }
//             return;
//         }

//         Ccurrent = Ccurrent->CNext;
//     }

//     cout<< "Course number not found" << endl;
// }

// void displayAll() {
//     if(C_List == NULL) {
//         cout << "No courses available!";
//         return;
//     }
//     CNode* Ccurrent = C_List;
//     while(Ccurrent != NULL) {
//         cout << "Course " << Ccurrent->CNo << "->" << endl;

//         SNode* Scurrent = Ccurrent->Stu_List;

//         if(Scurrent == NULL) {
//             cout << "No students enrolled\n";
            
//         } else 
//         {
//             cout << "Students: ";
//             while(Scurrent != NULL) {
//                 cout << Scurrent->SNo << endl;
//                 Scurrent = Scurrent-> SNext;
//             }
//         }
//         Ccurrent = Ccurrent->CNext;
//     }
// }

// int main() {
//     int choice, CNo, SNo;

//     do {
//         cout<< "==== MENU ====" << endl;
//         cout<< "1- Insert a course" << endl;
//         cout << "2- Insert a student to a course" << endl;
//         cout << "3- Display all" << endl;

//         cout<< "Enter a choice: ";
//         cin >> choice;

//         switch(choice) {
//             case 1: 
//             cout<< "Enter your course Number: ";
//             cin >> CNo;
//             insert_Course(CNo);
//             break;

//             case 2:
//             cout<< "Enter your Seat Number: ";
//             cin >> SNo;
//             cout<< "Enter your desired course number: ";
//             cin>> CNo;
//             insert_Student(SNo, CNo);
//             break;

//             case 3: 
//             displayAll();
//             break;

//             default:
//             cout<< "Invalid Choice!";
//         } 
//     } while (choice != 3);

//     return 0;
// }

