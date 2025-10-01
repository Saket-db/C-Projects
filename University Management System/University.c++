#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>

using namespace std;

class University
{
    private:
        string Regno;
        string Name;
        string Department;
        int Age;
        int Semester;

    public:
        University()
        {
            Regno = "" ;
            Name = "";
            Department = "";
            Age = 0;
            Semester = 0;
        }

        void setRegno(string roll)
        {
            Regno = roll;
        }

        void setName(string name)
        {
            Name = name;
        }

        void setDepartment(string dept)
        {
            Department = dept;
        }
        void setAge(int a)
        {
            Age = a;
        }

        void setSem(int s)
        {
            Semester = s;
        }

        string getRegno()
        {
            return Regno;
        }

         string getName()
        {
            return Name;
        }

        string getDepartment()
        {
            return Department;
        }

        int getAge()
        {
            return Age;
        }

        int getSem()
        {
            return Semester;
        }

};

void addStudent(University u1)
{
    string roll,name,dept;
    int age,sem;

    cout << "\tEnter Registration No: ";
    cin>>roll;
    u1.setRegno(roll);

    cout<<"Enter Name: ";
    cin>>name;
    u1.setName(name);

    cout<<"Enter Department: ";
    cin>>dept;
    u1.setDepartment(dept);

    cout<<"Enter Age: ";
    cin>>age;   
    u1.setAge(age);

    cout<<"Enter Semester: ";
    cin>>sem;   
    u1.setSem(sem);

    ofstream out("university.txt", ios::app);

    if(!out)
    {
        cout<<"\t Error: File Not Found!"<<endl;
    }
    else{
        out<<"\t"<<"Registration No:"<< u1.getRegno()<<endl;
        out<<"\t"<<"Name:"<< u1.getName()<<endl;
        out<<"\t"<<"Department:"<< u1.getDepartment()<<endl;
        out<<"\t"<<"Age:"<< u1.getAge()<<endl;
        out<<"\t"<<"Semester:"<< u1.getSem()<<endl;
    }
    out.close();
    cout<<"\t Student Added Successfully!"<<endl;
}
int main()
{
    University u1;
    bool exit = false;

    while(!exit)
    {
        system("cls");

        int val;
        cout << "\tWelcome To University Management System" << endl;
        cout <<"\t*****************************************" << endl;
        cout << "\t1.Add Student" << endl;
        cout << "\t2.Search Student" << endl;
        cout << "\t3.Update Data Of Student" << endl;
        cout << "\t4.Exit" << endl;
        cout << "\tEnter Your Choice: ";

        cin>>val;


        if(val == 1)
        {
            system("cls");
            addStudent(u1);

            Sleep(4000);
        }
    }
}
