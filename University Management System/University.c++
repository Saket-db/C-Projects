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

void searchInfo()
{
    string roll;
    cout<<"\tEnter Registration No to Search: ";
    cin>>roll;

    ifstream in("university.txt");
    if(!in)
    {
        cout<<"\t Error: File Not Found!"<<endl;
    }
    else{
        string line;
        bool found = false;
        while(getline(in, line))
        {
			size_t data = line.find(roll);
            if(data != string::npos)
            {
				cout << "Student Found in the database!"<<endl;
                cout<<"\t"<<line<<endl;
                found = true;
            }
        }
        if(!found)
        {
            cout<<"\t Student Not Found!"<<endl;
        }
        in.close();
    }
}

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

void updateInfo(University u1)
{
    string roll;
    cout<<"\tEnter Registration No to Update: ";
    cin>>roll;

    ifstream in("university.txt");
    ofstream out("temp.txt");

    if(!in || !out)
    {
        cout<<"Error: File can not be opened!"<<endl;
    }

    string line;

    bool found = false;
    while(getline(in, line))
    {
        size_t position = line.find(roll);
        if(position != string::npos)
        {
            string name;
            string dept;
            int age;
            int sem;

            cout<<"\tEnter New Name: ";
            cin>>name;
            u1.setName(name);
            cout<<"\tEnter New Department: ";
            cin>>dept;
            u1.setDepartment(dept);
            cout<<"\tEnter New Age: ";
            cin>>age;
            u1.setAge(age);
            cout<<"\tEnter New Semester: ";
            cin>>sem;
            u1.setSem(sem);

            int newPos = line.find_last_of("endl");
            line.replace(newPos + 4, line.length() - newPos - 4, "\tName: " + u1.getName() + "\n\tDepartment: " + u1.getDepartment() + "\n\tAge: " + to_string(u1.getAge()) + "\n\tSemester: " + to_string(u1.getSem()) + "\n");
            // found = true;
        }
        out<<line<<endl;
        found = true;
    }
    if(!found)
    {
        cout<<"\t Student Not Found!"<<endl;
    }

    in.close();
    out.close();
    remove("university.txt");
    rename("temp.txt", "university.txt");

    cout<<"\t Student Data Updated Successfully!"<<endl;
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

        else if(val == 2)
        {
            system("cls");
            
            searchInfo();
            Sleep(4000);
        }

        else if(val == 3)
        {
            system("cls");
            updateInfo(u1);
            Sleep(4000);
        }

        else if(val == 4)
        {
            exit = true;
            cout<<"\tThank You For Using Our System!"<<endl;
            Sleep(4000);
        }

        else
        {
            cout<<"\tInvalid Input! Please Try Again."<<endl;
            Sleep(4000);
        }
    }
}

