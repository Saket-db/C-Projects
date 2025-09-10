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
setItem(string  Item){
    item = Item;
}

setPrice(int Price)
{
    price = Price;
}

setQuant(int Quant)
{
    quantity = Quant;
}
};