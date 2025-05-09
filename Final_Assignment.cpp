#include <iostream>
#include <string>
using namespace std;
//Person
class Person {
protected:
    string name,ID,contact;
    int age;
public:
    Person(string n = "", int a = 18, string id = "", string c = "") {
        setName(n);
        setAge(a);
        ID = id;
        contact = c;
    }
    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << ID << ", Contact: " << contact << endl;
    }
    virtual double calculatePayment(){
        return 0;
    }
    void setName(string n){
        name = n.empty() ? "Unknown" : n;
    }
    void setAge(int a){
        age = (a > 0 && a < 100) ? a : 18;
    }
    string getName(){
        return name; 
    }
    int getAge(){ 
        return age; 
    }
};
// Student
class Student : public Person {
    string program,enrollmentDate;
    float gpa;
public:
    Student(string n = "", int a = 18, string id = "", string c = "",string e = "", string p = "", float g = 0.0f):Person(n, a, id, c), enrollmentDate(e), program(p) {
        setGPA(g);
    }
    void setGPA(float g){
        gpa = (g >= 0.0f && g <= 4.0f) ? g : 0.0f;
    }
    void displayDetails() override {
        Person::displayDetails();
        cout << "Program: " << program << ", GPA: " << gpa << endl;
    }
    double calculatePayment() override{
        return 1000.0; 
    }
};
//Professor
class Professor : public Person {
    string department,specialization,hireDate;
public:
    Professor(string n = "", int a = 30, string id = "", string c = "",string d = "", string s = "", string h = ""):Person(n, a, id, c), department(d), specialization(s), hireDate(h) {}
void displayDetails() override {
    Person::displayDetails();
    cout << "Department: " << department << ", Specialization: " << specialization << endl;
}
    double calculatePayment() override{
        return 5000; 
    }
};
//Course
class Course {
    string code, title, description;
    int credits;
public:
    Course(string c = "", string t = "", int cr = 3, string d = ""):code(c), title(t), description(d) {
        setCredits(cr);
    }
    void setCredits(int c){
        credits = (c > 0) ? c : 1; 
    }
    void display(){
        cout << "Course: " << code << " - " << title << ", Credits: " << credits << endl;
    }
};
//Department
class Department {
    string name, location;
    float budget;
public:
    Department(string n = "", string l = "", float b = 0.0f):name(n), location(l), budget(b) {}
    void display() {
        cout << "Department: " << name << ", Location: " << location << ", Budget: $" << budget << endl;
    }
};
//Gradebook
class GradeBook {
    string studentID[10];
    float grades[10];
    int count = 0;
public:
    void addGrade(string id, float grade) {
        if (count < 10) {
            studentID[count] = id;
            grades[count++] = grade;
        }
    }

    float calculateAverageGrade() {
        float total = 0;
        for (int i = 0; i < count; i++) total += grades[i];
        return count ? total / count : 0.0f;
    }

    float getHighestGrade() {
        float max = 0;
        for (int i = 0; i < count; i++)
            if (grades[i] > max) max = grades[i];
        return max;
    }

    void getFailingStudents() {
        cout << "Failing students (grade < 50):\n";
        for (int i = 0; i < count; i++)
            if (grades[i] < 50)
                cout << studentID[i] << " with grade " << grades[i] << endl;
    }
};

//Enrollment Manager
class EnrollmentManager {
    string course[10], student[10];
    int count = 0;
public:
    void enrollStudent(string c, string s) {
        if (count < 10) {
            course[count] = c;
            student[count++] = s;
        }
    }
    void dropStudent(string s) {
        for (int i = 0; i < count; i++) {
            if (student[i] == s) {
                course[i] = course[count - 1];
                student[i] = student[count - 1];
                count--;
                break;
            }
        }
    }
    int getEnrollmentCount() { return count; }
};
int main() {
    Student s1("Suresh", 20, "S101", "suresh@gmail.com", "2023", "Computer Science", 3.6f);
    Student s2("Ramesh", 21, "S102", "ramesh@gmail.com", "2023", "Electronics", 3.2f);

    Professor p1("Rajesh", 48, "P101", "rajesh@gmail.com", "CS", "Machine Learning", "2008");
    Professor p2("Nilesh", 52, "P102", "nilesh@gmail.com", "Math", "Applied Math", "2005");

    Course c1("CS101", "Intro to Coding", 4, "Learn Coding basics");
    Department d1("Engineering", "Block B", 75000.0f);

    // Display details
    s1.displayDetails();
    s2.displayDetails();
    p1.displayDetails();
    p2.displayDetails();
    c1.display();
    d1.display();

    // GradeBook Testing
    GradeBook gb;
    gb.addGrade("S101", 78);
    gb.addGrade("S102", 44); // Failing
    cout << "Average Grade: " << gb.calculateAverageGrade() << endl;
    cout << "Highest Grade: " << gb.getHighestGrade() << endl;
    gb.getFailingStudents();

    // Enrollment
    EnrollmentManager em;
    em.enrollStudent("CS101", "S101");
    em.enrollStudent("CS101", "S102");
    cout << "Enrolled Students: " << em.getEnrollmentCount() << endl;
    em.dropStudent("S102");
    cout << "After drop: " << em.getEnrollmentCount() << endl;
    // Polymorphism
    Person* people[2] = { &s1, &p1 };
    for (int i = 0; i < 2; i++) {
        people[i]->displayDetails();
        cout << "Calculated Payment: " << people[i]->calculatePayment() << "\n";
    }
    return 0;
}