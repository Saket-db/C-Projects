#include<iostream>
#include<fstream>
#include<conio.h>
// #include<bits/stdc++.h>
#include<windows.h>

using namespace std;


class Bill{
private:
    string item;
    int price, quantity;

public:
Bill(){
    item = "";
    price = 0;
    quantity = 0;
}

// To intialize values, as the above defined are private
void setItem(string  Item){
    item = Item;
}

void setPrice(int Price)
{
    price = Price;
}

void setQuant(int Quant)
{
    quantity = Quant;
}
// get functions to return the values

// Always define return type of get function
string getItem()
{
    return item;
}

int getPrice()
{
    return price;
}

int getQuant()
{
    return quantity;
}

};

void addItem(Bill b)
{
bool close = false; // so that item gets added until user wants to add
    while(!close)
    {
        int choice;
        cout<<"\t1. Add"<<endl;
        cout<<"\t2. Close"<<endl;
        cout<<"\tEnter Choice:"<<endl;
        cin>>choice;

        if(choice == 1)
        {
            system("cls");
            string item;
            int price, quant;

            cout<<"\tEnter Item Name: ";
            cin>>item;
            b.setItem(item);
            cout<<"\tEnter Price: ";
            cin>>price;
            b.setPrice(price);
            cout<<"\tEnter Quantity: ";
            cin>>quant;
            b.setQuant(quant);

            ofstream out("bill.txt", ios::app); // Ofstream is used to save the user provided input in a file and ios::app is used to append the data in the file in such a manner that the data is added at the end of the file and not overwrite the previous data
            if(!out)
            {
                cout<<"\tError Can't be opened"<<endl;
                return;
            }
            else
            {
                out<<b.getItem()<<"\t"<<b.getPrice()<<"\t"<<b.getQuant()<<endl<<endl;
            }
            out.close();
            cout << "\t Item Added Successfully";

            Sleep(3000); // to hold the screen for 3 seconds
        }

        else if(choice == 2)
        {
            system("cls");
            close = true;
            cout << "\tBack to Main Menu" << endl;
            Sleep(3000);
        }
        else
        {
            cout<<"\tInvalid Choice"<<endl;
            Sleep(3000);
        }
    }
}

int main()
{
    Bill b;

    // Options to user

    bool exit = false;
    while(!exit)
    {
        system("cls"); // to clear the screen
        int val;
        cout<<"\n\t\t Super Market Billing System" <<endl;
        cout<<"\t*********************************"<<endl;
        cout<<"\n1. Add Item"<<endl;
        cout<<"\n2. Print Bill"<<endl;
        cout<<"\n3. Exit"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>val; 


        if(val == 1)
        {
            addItem(b);
        }
    }
}