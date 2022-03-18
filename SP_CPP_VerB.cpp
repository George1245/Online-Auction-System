#include <iostream>
using namespace std;
int buyer = 0, seller = 0, account_num_sell, account__num_buy;
//this char to know account type s(seller) or b(buyer)
char sb;
//////////////
struct Data
{
    int day;
    int month;
    int year;
};
struct Items
{
    double number;
    string category = "none";
    int start_price;
    Data start_date;
    Data end_date;

    int number_bought = 0;
};
struct member
{
    double iD;
    string email;
    string name;
    string password;
    string address;
    double  phone_number;
    int points = 0;
    Items list_of_items;
    string feed_back;
}account_buyer[300], account_seller[300], account;

///////////////
void creat_account()
{
    //to save data
    cout << "To create a new account please follow the instructions" << endl;
    cout << "Enter your Id: ";
    cin >> account.iD;
    cout << "Enter your e_mail: ";
    cin >> account.email;
    cout << "Enter your name: ";
    cin >> account.name;
    cout << "Enter your password: ";
    cin >> account.password;
    cout << "Enter your address: ";
    cin >> account.address;
    cout << "Enter your phone number: ";
    cin >> account.phone_number;


    //to save data in struct
   //if account is buyer
    if (sb == 'b')
    {

        account_buyer[buyer].iD = account.iD;
        account_buyer[buyer].name = account.name;
        account_buyer[buyer].address = account.address;
        account_buyer[buyer].phone_number = account.phone_number;
        account_buyer[buyer].list_of_items = account.list_of_items;
        account_buyer[buyer].email = account.email;
        account_buyer[buyer].password = account.password;
        buyer++;
        account__num_buy = buyer;

    }
    //if account is seller
    else if (sb == 's')
    {

        account_seller[seller].iD = account.iD;
        account_seller[seller].name = account.name;
        account_seller[seller].address = account.address;
        account_seller[seller].phone_number = account.phone_number;
        account_seller[seller].list_of_items = account.list_of_items;
        account_seller[seller].email = account.email;
        account_seller[seller].password = account.password;
        seller++;
        account_num_sell = seller;

    }



}
//check account is true or false
void login()
{
    bool x = false;
    string user, pass;

    while (true) {

        cout << "enter your e_mail: ";
        cin >> user;
        cout << "enter your password: ";
        cin >> pass;

        //if account is buyer
        if (sb == 'b')
        {
            for (int i = 0; i < buyer; i++)
            {
                if (user == account_buyer[i].email && pass == account_buyer[i].password)
                {
                    x = true;
                    account__num_buy = i;
                    break;
                }
            }
        }
       //if account is seller
        else if (sb == 's')
        {
            for (int i = 0; i < seller; i++)
            {
                if (user == account_seller[i].email && pass == account_seller[i].password)
                {
                    x = true;
                    account_num_sell = i;
                    break;
                }
            }
        }
        if (x == true) {
            cout << "UserName and password are correct" << endl;
            break;
        }
        else if (x == false) {
            cout << "UserName or password are wrong" << endl;
            continue;
        }
    }
}

void sign_up()
{
    string choose_yn;
    while (1) {
        cout << "sign up:Do you have an e-mail or not(y/n)::  ";
        cin >> choose_yn;
        //login by your account
        if (choose_yn == "y")
        {
            login();
            break;
        }
        //create new account to login
        else if (choose_yn == "n")
        {
            creat_account();
            break;
        }
        else {
            cout << "wrong answer" << endl;
        }
    }
}

void sell_thing_data()
{

    cout << endl << "number of items: ";
    cin >> account_seller[account_num_sell].list_of_items.number;
    cout << "category of items: ";
    cin >> account_seller[account_num_sell].list_of_items.category;
    cout << "start price of items: ";
    cin >> account_seller[account_num_sell].list_of_items.start_price;
    cout << "start date of items(day/month/year): " << endl;
    cout << "day: ";
    cin >> account_seller[account_num_sell].list_of_items.start_date.day;
    cout << "month: ";
    cin >> account_seller[account_num_sell].list_of_items.start_date.month;
    cout << "year: ";
    cin >> account_seller[account_num_sell].list_of_items.start_date.year;
    cout << "end date of items(day/month/year): " << endl;
    cout << "day: ";
    cin >> account_seller[account_num_sell].list_of_items.end_date.day;
    cout << "month: ";
    cin >> account_seller[account_num_sell].list_of_items.end_date.month;
    cout << "year: ";
    cin >> account_seller[account_num_sell].list_of_items.end_date.year;

}


bool search_something()
{
    string category;
    int price = 999999;
    bool x;
    char yn;
//search by category
    cout<<endl;
    cout << "search by category: ";
    cin >> category;
    for (int i = 0; i <= seller; i++)
    {
        if (account_seller[i].list_of_items.category == category)

        {
            cout << endl << category << " is available" << endl;
            x = true;
            break;
        }
    }
    if (x == false) { cout << endl << category << " is not available" << endl; }
//if item is available
    else if (x == true)
    {
        //search by price
        cout << "Do you want to search by price too?(y/n): ";
        cin >> yn;
        if (yn == 'y')
        {
            cout << "Enter price: ";
            cin >> price;

        }
        //check prise
        for (int i = 0; i <= seller; i++)
        {
            if (account_seller[i].list_of_items.category == category
                && price >= account_seller[i].list_of_items.start_price)
            {

                cout << "number of product is:" << account_seller[i].list_of_items.number;
                cout << "  price is " << account_seller[i].list_of_items.start_price << endl;
                cout << endl;

            }
        }


    }
    return x;
}

void report()
{

    for (int i = 0; i <= buyer; i++)
    {
        if (account_buyer[i].list_of_items.category != "none")
        {
            cout << account_buyer[i].list_of_items.number_bought << " copies have been bought";
            cout << " from product " << account_buyer[i].list_of_items.category << endl;
        }
    }
}

void buy_thing()
{
    bool check=false;
    string choose_yn;
    int point;
    int choose, number, suggest_price;

    cout << "1)buy/2)suggest offer: ";
    cin >> choose;

    if (choose == 1)
    {
        cout << "Enter the number of product: ";
        cin >> number;
        //check if number is true
        for (int i = 0; i <= seller; i++)
        {
            if (number == account_seller[i].list_of_items.number)
            {
            account_num_sell = i;
            suggest_price = account_seller[i].list_of_items.start_price;
            check=true;
            break;
            }
        }
    }

    else if (choose == 2)
    {
       while(true){
        cout << "Enter the suggested price: ";
        cin >> suggest_price;
        cout << "Enter the number of product: " << endl;
        cin >> number;

        for (int i = 0; i <= seller; i++)
        {
            if (number == account_seller[i].list_of_items.number)
            {
                account_num_sell = i;
                check=true;

                break;
            }
        }
        if(check==false)
           {
            cout<<"item is not found";
                continue;
           }
        if(check==true){break;}
       }
        cout << "One of the auction terms is that the seller agrees to the price: " << endl;
        cout << "This part is for the seller: " << endl;
       cout<<"if you agree to sell your item by "<<suggest_price<<"(y/n)";

       cin>>choose_yn;
       if(choose_yn=="y")
        {
        sb = 's';
        login();
        cout << "seller is accept" << endl;


if(check==true)
{

    cout << "The purchase is complete" << endl << endl;
    account_buyer[account__num_buy].list_of_items.category = account_seller[account_num_sell].list_of_items.category;
    account_buyer[account__num_buy].list_of_items.number = account_seller[account_num_sell].list_of_items.number;
    account_buyer[account__num_buy].list_of_items.start_price = suggest_price;
    account_buyer[account__num_buy].list_of_items.number_bought++;
    cout << "Do you want to give a point to seller(y/n): " << endl;
    cin >> choose_yn;
    while (true)
        {
        if (choose_yn == "y")
        {
            cout << "from 1 to 5 : ";
            cin >> point;
            if (point >= 3 && point <= 5) {
                account_seller[account_num_sell].points++;
            }
            else if (point >= 1 && point < 3)
            {
                if (account_seller[account_num_sell].points > 0)
                {
                    account_seller[account_num_sell].points--;
                }
            }
            else { cout << "wrong answer" << endl; }
            break;
        }
        else if (choose_yn == "n")
        {
            break;
        }
        else {
            cout << "wrong answer" << endl;
        }
    }
    cout << "write feed back" << endl;
    cin.ignore();
    getline(cin, account_seller[account_num_sell].feed_back);
 }


}
    }
     if(choose_yn=="n")
    {
        cout<<"seller not accept"<<endl;
    }
    else { cout << "wrong answer" << endl; }

}

int main()
{
    int choose;
    //loop to  repeat the menu more than once
    while (true)
    {
        //main menu to choose what do you want?
        cout << "----------------------------------" << endl;
        cout << "1)Do you want to sell something?" << endl;
        cout << "2)Do you want to buy something?" << endl;
        cout << "3)Do you want to see report?" << endl;

        while (true)
        {
            cin >> choose;
            //sell something
            if (choose == 1)
            {
                //to knew the account is seller
                sb = 's';
                //login or create account
                sign_up();
                //save data from user
                sell_thing_data();
                break;
            }
             //buy something
            else if (choose == 2)
            {
                //to knew the account is buyer
                sb = 'b';
                //login or create account
                sign_up();
                //search if item x is available or not
                if (search_something() == true) {
                        //buy directly or suggest price
                    buy_thing();
                }
                break;
            }
            //print report
            else if (choose == 3)
            {
                cout << endl;
                report();
                break;
            }
            //if user choose any thing another 1,2,3
            else
            {
                cout << "wrong choice" << endl;
            }
        }

    }
    return 0;
}
