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

            // 18 Mins
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
        cout<<"\n\t\t Super Market Billing System";
        cout<<"\t*********************************"<<endl;
        cout<<"\n1. Add Item"<<endl;
        cout<<"\n2. Print Bill"<<endl;
        cout<<"\n3. Exit"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>val; 
    }
}