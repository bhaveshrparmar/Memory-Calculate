#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Student
{
private:
    T id;
    string name;

public:
    Student(T id, string name)
    {
        this->id = id;
        this->name = name;
    }

    void display()
    {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    T getId()
    {
        return id;
    }
};

template <typename T>
class StudentManagement
{
private:
    vector<Student<T>> students;

public:
    void addStudent(T id, string name)
    {
        students.push_back(Student<T>(id, name));
    }

    void displayAll()
    {
        cout << "\nStudent List:\n";
        for (auto &student : students)
        {
            student.display();
        }
    }

    void removeStudent(T id)
    {
        for (auto it = students.begin(); it != students.end(); ++it)
        {
            if (it->getId() == id)
            {
                students.erase(it);
                cout << "Student with ID " << id << " removed.\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    void searchStudent(T id)
    {
        for (auto &student : students)
        {
            if (student.getId() == id)
            {
                cout << "Student Found: ";
                student.display();
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }
};

int main()
{
    StudentManagement<int> sm;

    sm.addStudent(15, "Bhavesh");
    sm.addStudent(16, "Raj");
    sm.addStudent(17, "Vraj");

    sm.displayAll();

    sm.searchStudent(102);

    sm.removeStudent(101);
    sm.displayAll();

    return 0;
}