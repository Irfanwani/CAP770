#include <iostream>
using namespace std;

class StudentNode {
    public:
    string name;
    int rollno;
    float percentage;
    StudentNode* next;

    StudentNode(string name, int rollno, float percentage): name(name), rollno(rollno), percentage(percentage) {};
    ~StudentNode() {
        free(next);
    }
};

class LinkedList {
    StudentNode* head;

    public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        free(head);
    }

    void append(string name, int rollno, float percentage) {
        StudentNode* newNode = new StudentNode(name, rollno, percentage);
        if(head == nullptr) {
            head = newNode;
            return;
        }

        StudentNode* current = head;
        while(current->next) {
            current = current->next;
        }

        current->next = newNode;
    }

    void search(int rollno) {
        StudentNode* current = head;
        int i = 1;
        while(current) {
            if(current->rollno == rollno) {
                cout << "Position of student: " << i << endl;
                cout << "Details of student are: " << endl;
                cout << "Roll No: "<< current->rollno << endl;
                cout << "Name: "<< current->name << endl;
                cout << "Percentage: "<< current->percentage << endl;
                return;
            }
            i++;
            current = current->next;
        }

        cout << "Student details not found" << endl;
    }

};

int main() {
    LinkedList l;
    string name;
    float percentage;
    int n, rollno;
    cout << "Enter the number of students: ";
    cin >> n;
    cout << "Enter the details of the students (name, roll no, percentage): "<< endl;
    for(int i = 0; i < n; i++) {
        cin >> name;
        cin >> rollno;
        cin >> percentage;
        l.append(name, rollno, percentage);
    }

    cout << "Enter the student roll no to search" << endl;
    cin >> rollno;
    l.search(rollno);
    return 0;
}