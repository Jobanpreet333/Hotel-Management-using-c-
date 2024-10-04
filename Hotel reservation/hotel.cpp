#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

class Hotel
{

    string user, pass, user1, pass1, name, mob, user2, pass2;

public:
    void staff(void);
    void customer(void);
    // void login(void);
    void account(void);
} obj;

class Book
{
    string user, pass, user1, pass1, name, mob, user2, mobile, pass3, user3, name1, pass2;

    string member;
    const char *filename;
    const char *roomname;
    const char *room2;

public:
    void menu(void);
    int order(void);
    int bill(void);
    void reserve(void);
    void twotv(const char *two);
    void book1(const char *filename);
    void roombook1(const char *roomname);
    void room(void);
    void room1(const char *room2);
    void cancel(void);
    void cancelRoom(void);
    void login(void);
    void reservedTable(void);
    void reservedRoom(void);
    void billData(void);

} obj1;
int main()
{
    char choice, choice1;
    cout << "----------------------------" << endl;
    cout << "1-Staff Member" << endl;
    cout << "2-Customer" << endl;
    cout << "3-Look for the Menu" << endl;
    cout << "----------------------------" << endl;

    cout << "Enter your Choice?" << endl;
    cin >> choice;

    switch (choice)
    {
    case '1':
        obj.staff();
        break;
    case '2':
        obj.customer();
        break;
    case '3':
        obj1.menu();
        break;
    default:
        cout << "Invalid Choice" << endl;
        break;
    }
}

void Hotel ::staff()
{
    ifstream fout;
    fout.open("staff.txt");

    cout << "Enter your Username :: " << endl;
    cin >> user;

    cout << "Enter your Password :: " << endl;
    cin >> pass;

    getline(fout, user1, '*');
    getline(fout, pass1, '\n');

    while (!fout.eof())
    {
        char choice;

        if (user1 == user && pass1 == pass)
        {
            cout << "Login Successfully" << endl;

            cout << "----------------------------------" << endl;
            cout << "1-Show list of Reserved Tables with Username . " << endl;
            cout << "2-Show list of Reserved Rooms with Username . " << endl;
            cout << "3-Show Bill Data ." << endl;
            cout << "----------------------------------" << endl;

            cout << "Enter you choice :: " << endl;
            cin >> choice;
            switch (choice)
            {
            case '1':
                obj1.reservedTable();
                break;
            case '2':
                obj1.reservedRoom();
                break;
            case '3':
                obj1.billData();
                break;

            default:
                cout << "Invalid Choice.........." << endl;
                break;
            }
            break;
        }
        getline(fout, user1, '*');
        getline(fout, pass1, '\n');
    }
    // if (user1 != user && pass1 != pass)
    //     {
    //         cout << "Wrong Username or Password" << endl;
    //     }
}

void Hotel ::customer()
{
    fstream fout;
    fout.open("cust.txt");

    char choice1;
    cout << "***************************" << endl;
    cout << "1-Create New Account" << endl;
    cout << "2-Login" << endl;
    cout << "***************************" << endl;
    cout << "Enter your Choice :: " << endl;
    cin >> choice1;

    switch (choice1)
    {
    case '1':
        obj.account();
        break;
    case '2':
        obj1.login();
        break;

    default:
        cout << "Invalid Choice" << endl;
        break;
    }
}

void Hotel ::account()
{
    cout << "Enter your Name :: " << endl;
    cin >> name;

    cout << "Enter your Mobile Number :: " << endl;
    cin >> mob;

    cout << "Enter your Username :: " << endl;
    cin >> user2;

    cout << "Enter Password :: " << endl;
    cin >> pass2;

    ifstream fin;
    fin.open("cust.txt");
    string name1, mobile, user3, pass3;
    getline(fin, name1, '*');
    getline(fin, mobile, '*');
    getline(fin, user3, '*');
    getline(fin, pass3, '*');
    while (!fin.eof())
    {
        if (mobile == mob || user3 == user2)
        {
            cout << "Account with this Number or username has already been created.Please login into existing account or make new account with another number or username." << endl;
            break;
        }
        getline(fin, name1, '*');
        getline(fin, mobile, '*');
        getline(fin, user3, '*');
        getline(fin, pass3, '*');
    }
    ofstream fout;
    fout.open("cust.txt", ios::app);
    fout << name << '*' << mob << '*' << user2 << '*' << pass2 << endl;
    cout<<"Account created Successfully"<<endl;
    // ofstream fout;
    // fout.open("cust.txt", ios::app);
    // fout << name << '*' << mob << '*' << user2 << '*' << pass2 << endl;
}

void Book ::login()
{

    char choice3;
    ifstream fout;
    fout.open("cust.txt");

    cout << "Enter your Username :: " << endl;
    cin >> user;

    cout << "Enter your Password :: " << endl;
    cin >> pass;

    getline(fout, name, '*');
    getline(fout, mob, '*');
    getline(fout, user1, '*');
    getline(fout, pass1, '\n');

    while (!fout.eof())
    {
        if (user1 == user && pass1 == pass)
        {
            cout << "Login Successfully" << endl;

            cout << "----------------------------" << endl;
            cout << "What would you like to do ? " << endl;
            cout << "1-Look for the Menu " << endl;
            cout << "2-Order Something" << endl;
            cout << "3-Pay Bill" << endl;
            cout << "4-Reserve a Table" << endl;
            cout << "5-Reserve/Book Room" << endl;
            cout << "6-Order Something from Room" << endl;
            cout << "7-Cancel Room Booking" << endl;
            cout << "8-Cancel Table Booking" << endl;
            cout << "----------------------------" << endl;

            cout << "Enter your Choice" << endl;
            cin >> choice3;

            switch (choice3)
            {
            case '1':
                obj1.menu();
                break;
            case '2':
                obj1.menu();
                obj1.order();
                obj1.order();
                obj1.order();
                obj1.order();
                obj1.order();
                obj1.order();
                obj1.order();
                obj1.bill();
                break;
            case '3':
                obj1.bill();

                break;
            case '4':
                obj1.reserve();
                break;
            case '5':
                obj1.room();

                break;
            case '6':
                obj1.menu();
                obj1.order();
                obj1.order();
                obj1.order();
                obj1.order();
                obj1.order();
                obj1.order();
                obj1.order();
                obj1.bill();
                break;
            case '7':
                obj1.cancelRoom();
                break;
            case '8':
                obj1.cancel();
                break;

            default:
                cout << "Invalid Choice" << endl;
                break;
            }
        }

        getline(fout, name, '*');
        getline(fout, mob, '*');
        getline(fout, user1, '*');
        getline(fout, pass1, '\n');
    }
}

void Book ::menu()
{
    ifstream fin;
    fin.open("menu.txt");
    string food, id, price;

    getline(fin, food, '*');
    getline(fin, id, '*');
    getline(fin, price, '\n');

    while (!fin.eof())
    {
        cout << food << "*" << id << endl;
        getline(fin, food, '*');
        getline(fin, id, '*');
        getline(fin, price, '\n');
    }
}

int Book ::order()
{
    ifstream fin;
    fin.open("menu.txt");
    string food, id, id2, id3, id4, id5, id1, price;

    getline(fin, food, '*');
    getline(fin, id, '*');
    getline(fin, price, '\n');

    cout << "Enter the Id of the food you want to Order :: " << endl;
    cin >> id1;

    while (!fin.eof())
    {
        if (id1 == id)
        {
            cout << food << endl;
            break;
            // cout<<price;
        }
        else
        {
            getline(fin, food, '*');
            getline(fin, id, '*');
            getline(fin, price, '\n');
        }
    }
    // cout << price << endl;

    ofstream fout;
    fout.open("bill.txt", ios::app);
    fout << price << '*';
}

int Book ::bill()
{
    ifstream fin;
    fin.open("bill.txt");
    ofstream fout;
    fout.open("bill1.txt", ios::app);
    string price, value, space;
    getline(fin, price, '*');
    int price2 = 0;

    while (!fin.eof())
    {
        int price1;
        price1 = stoi(price);
        fout << price << '*';
        price2 += price1;
        cout << price2 << endl;

        getline(fin, price, '*');
    };
    int price3 = 0;
    price3 += price2;
    cout << "Your Bill is of Amount :: Rs." << price3 << endl;
    fout << user1 << endl;

    getline(fin, value, '\n');
    getline(fin, space, '\n');
    ofstream file;
    file.open("bill2.txt");
    file << space << endl;
    fin.close();
    file.close();
    remove("bill.txt");
    rename("bill2.txt", "bill.txt");
}

void Book ::reserve()
{
    char choice;
    cout << "Enter the number of Members :: " << endl;
    cin >> member;

    cout << "If you want any of the below mentioned facilities :: " << endl;
    cout << "1-In front of Television" << endl;
    cout << "2-AC" << endl;
    cout << "3-Non-AC" << endl;
    cout << "4-Near the Pool" << endl;
    cout << "5-With Music" << endl;
    cout << "6-Pet Friendly" << endl;

    cout << "---------------------------" << endl;
    cout << "Enter your choice :: " << endl;
    cin >> choice;

    switch (choice)
    {
    case '1':
        obj1.twotv("twotv.txt");
        obj1.book1("twotv.txt");
        break;
    case '2':
        obj1.twotv("twoAc.txt");
        obj1.book1("twoAc.txt");

        break;
    case '3':
        obj1.twotv("twoNonAC.txt");
        obj1.book1("twoNonAC.txt");

        break;
    case '4':
        obj1.twotv("twopool.txt");
        obj1.book1("twopool.txt");

        break;
    case '5':
        obj1.twotv("twomusic.txt");
        obj1.book1("twomusic.txt");

        break;
    case '6':
        obj1.twotv("twopet.txt");
        obj1.book1("twopet.txt");

        break;
    default:
        cout << "Invalid Choice........." << endl;
        break;
    }
}

void Book ::twotv(const char *two)
{
    string table, id, date, id1;
    ifstream fin;
    fin.open(two);
    getline(fin, table, '*');
    getline(fin, id, '\n');
    while (!fin.eof())
    {
        cout << table << endl;
        getline(fin, table, '*');
        getline(fin, id, '\n');
    }
}

void Book ::book1(const char *filename)
{

    string id1, date, table, id;
    cout << "Enter the table Number you want to Reserve :: " << endl;
    cin >> id1;
    cout << "On what date you want to reserve ? " << endl;
    cin >> date;

    ifstream fin;
    fin.open(filename);
    ofstream job, fout;
    job.open("reserve.txt", ios::app);
    fout.open("twoAc1.txt");
    getline(fin, table, '*');
    getline(fin, id, '\n');

    while (!fin.eof())
    {
        if (id1 == id)
        {
            cout << "Table No. => " << id << " reserved Successfully" << endl;
            job << table << '*' << id << '*' << user1 << endl;
        }
        else
        {
            fout << table << '*' << id << endl;
        }

        getline(fin, table, '*');
        getline(fin, id, '\n');
    }
    job.close();
    fout.close();
    fin.close();
    remove(filename);
    rename("twoAc1.txt", filename);
    cout << "Bill--->Rs.700" << endl;
    cout << "Pay you Bill within 3 days otherwise your reservation will be automatically cancelled" << endl;
}

void Book ::room()
{

    char choice;

    cout << "-------------------------------------------" << endl;
    cout << "Which Room would you like to reserve ? " << endl;
    cout << "1-For One Person" << endl;
    cout << "2-For Two Persons" << endl;
    cout << "3-For Three Persons" << endl;
    cout << "4-For Four Persons" << endl;
    cout << "-------------------------------------------" << endl;

    cout << "Enter your Choice :: " << endl;
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj1.room1("room1.txt");
        obj1.roombook1("room1.txt");

        break;
    case '2':
        obj1.room1("room2.txt");
        obj1.roombook1("room2.txt");
        break;
    case '3':
        obj1.room1("room3.txt");
        obj1.roombook1("room3.txt");

        break;
    case '4':
        obj1.room1("room4.txt");
        obj1.roombook1("room4.txt");

        break;

    default:
        cout << "Invalid Choice.........." << endl;
        break;
    }
}

void Book ::room1(const char *room2)
{
    ifstream fin;
    fin.open(room2);
    string room, id;
    getline(fin, room, '*');
    getline(fin, id, '\n');

    while (!fin.eof())
    {
        cout << room << endl;
        getline(fin, room, '*');
        getline(fin, id, '\n');
    }
}

void Book ::roombook1(const char *roomname)
{

    string id1, date, table, id;
    cout << "Enter the Room Number you want to Reserve :: " << endl;
    cin >> id1;
    cout << "On what date you want to reserve ? " << endl;
    cin >> date;

    ifstream fin;
    fin.open(roomname);
    ofstream job, fout;
    job.open("reserveroom.txt", ios::app);
    fout.open("twoAc1.txt");
    getline(fin, table, '*');
    getline(fin, id, '\n');

    while (!fin.eof())
    {
        if (id1 == id)
        {
            cout << "Room No. => " << id << " reserved Successfully" << endl;
            job << table << '*' << id << '*' << user1 << endl;
        }
        else
        {
            fout << table << '*' << id << endl;
        }

        getline(fin, table, '*');
        getline(fin, id, '\n');
    }
    job.close();
    fout.close();
    fin.close();
    remove(roomname);
    rename("twoAc1.txt", roomname);
    cout << "Bill--->Rs.700" << endl;
    cout << "Pay you Bill within 3 days otherwise your reservation will be automatically cancelled" << endl;
}

void Book ::cancelRoom()
{
    string room, id, user4, answer;

    ifstream fin;
    fin.open("reserveroom.txt");
    ofstream fout, file;
    // fout.open("twoAc.txt", ios::app);
    file.open("reserve1.txt");
    getline(fin, room, '*');
    getline(fin, id, '*');
    getline(fin, user4, '\n');

    cout << "Are you sure you want to cancel your reservation ? (Yes/No)" << endl;
    cin >> answer;

    while (!fin.eof())
    {
        if (answer == "yes" || "Yes")
        {
            if (user4 == user)
            {
                cout << "Your Reservation of Room No." << id << " has been cancelled " << endl;
                if (stoi(id) >= 101 && stoi(id) <= 120)
                {
                    fout.open("room1.txt", ios::app);
                    fout << room << '*' << id << endl;
                }
                else if (stoi(id) >= 201 && stoi(id) <= 220)
                {
                    fout.open("room2.txt", ios::app);
                    fout << room << '*' << id << endl;
                }
                else if (stoi(id) >= 301 && stoi(id) <= 320)
                {
                    fout.open("room3.txt", ios::app);
                    fout << room << '*' << id << endl;
                }
                else if (stoi(id) >= 401 && stoi(id) <= 420)
                {
                    fout.open("room4.txt", ios::app);
                    fout << room << '*' << id << endl;
                }
            }
            else
            {
                file << room << '*' << id << '*' << user4 << endl;
            }

            getline(fin, room, '*');
            getline(fin, id, '*');
            getline(fin, user4, '\n');
        }
        else
        {
            cout << "No Cancellation" << endl;
            break;
        }
    }

    file.close();
    fin.close();
    fout.close();
    remove("reserveroom.txt");
    rename("reserve1.txt", "reserveroom.txt");
}

void Book ::cancel()
{
    string table, id, user4, answer;

    ifstream fin;
    fin.open("reserve.txt");
    ofstream fout, file;
    fout.open("twoAc.txt", ios::app);
    file.open("reserve1.txt");
    getline(fin, table, '*');
    getline(fin, id, '*');
    getline(fin, user4, '\n');

    cout << "Are you sure you want to cancel your reservation ? (Yes/No)" << endl;
    cin >> answer;

    while (!fin.eof())
    {
        if (answer == "yes" || "Yes")
        {
            if (user4 == user)
            {
                fout << table << '*' << id << endl;
            }
            else
            {
                file << table << '*' << id << '*' << user4 << endl;
            }

            getline(fin, table, '*');
            getline(fin, id, '*');
            getline(fin, user4, '\n');
        }
        else
        {
            cout << "No Cancellation" << endl;
            break;
        }
    }

    file.close();
    fin.close();
    fout.close();
    remove("reserve.txt");
    rename("reserve1.txt", "reserve.txt");
}

void Book ::reservedRoom()
{
    ifstream fin;
    fin.open("reserveroom.txt");
    string room, no, id;
    getline(fin, room, '*');
    getline(fin, no, '*');
    getline(fin, id, '\n');
    while (!fin.eof())
    {
        cout << room << endl;
        cout << "Booked By :: " << id << endl;
        getline(fin, room, '*');
        getline(fin, no, '*');
        getline(fin, id, '\n');
    }
}
void Book ::reservedTable()
{
    ifstream fin;
    fin.open("reserve.txt");
    string table, no, id;
    getline(fin, table, '*');
    getline(fin, no, '*');
    getline(fin, id, '\n');
    while (!fin.eof())
    {
        cout << table << endl;
        cout << "Booked By :: " << id << endl;
        getline(fin, table, '*');
        getline(fin, no, '*');
        getline(fin, id, '\n');
    }
}

void Book ::billData()
{
    ifstream fin;
    fin.open("bill1.txt");
    string table, no, id;
    getline(fin, table, '\n');
    // getline(fin, no, '*');
    // getline(fin, id, '\n');
    while (!fin.eof())
    {
        cout << table << endl;
        // cout << "Booked By :: " << id << endl;
        getline(fin, table, '*');
        // getline(fin, no, '*');
        // getline(fin, id, '\n');
    }
}