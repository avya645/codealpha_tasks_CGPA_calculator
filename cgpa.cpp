#include<iostream>
#include<vector>
using namespace std;
class subject{
    public:
    string subjectname;
    int credit;
    float gradepoint;
    //constructor
    subject(string name, int cr, float gp)
    {
        subjectname = name;
        credit = cr;
        gradepoint = gp;
    }
};
class student{
    public:
    string name;
    vector<subject>subjects;
   // constructor
   student(string studentName)
   {
    name = studentName;
   }
   void addSubject(string subjectName,int credit,float gradepoint)
   {
    subject newSubject(subjectName,credit,gradepoint);
    subjects.push_back(newSubject);
   }
   float calculatecgpa()
   {
    int totalcredit=0;
    float weightgradepoint=0;
    for(const subject& sub : subjects)
    {
            totalcredit += sub.credit;
            weightgradepoint += sub.credit * sub.gradepoint;
    }
    return (totalcredit > 0) ? (weightgradepoint/totalcredit) : 0;
   }
   void displaycgpa()
   {
    std::cout << "Student name: " << name << std::endl;
    float cgpa = calculatecgpa();
    std::cout << "CGPA: " << cgpa << std::endl;
   }
};

int main()
{
    string studentname;
    int numsub;
    std::cout << "Enter student name: ";
    std::getline(std::cin, studentname);

    std::cout << "Enter the number of subjects: ";
    std::cin >> numsub;
    cin.ignore(); // Clear the newline from the buffer
    student s(studentname);

    for(int i = 0; i < numsub; i++)
    {
        string subjectname;
        int credit;
        float gradepoint;
        std::cout << "Enter the subject name: ";
        std::getline(std::cin, subjectname);

        std::cout << "Enter the credits for this subject: ";
        std::cin >> credit;
        std::cout << "Enter the grade point: ";
        std::cin >> gradepoint;
        cin.ignore(); // Clear the newline for the next iteration
        
        s.addSubject(subjectname, credit, gradepoint);
    }
    s.displaycgpa();
        return 0;
}