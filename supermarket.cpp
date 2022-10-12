#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

class shop
{

    int pcode;
    float price;
    float dis;
    string pname;

public:
    void showdata()
    {
        cout << pcode << " " << pname << " " << price << " "
             << " " << dis << "\n";
    }
    int n;
    void login();
    void addnew();
    void print();
    void buyer();
    void workerspage();
    void recipt();
    void recipts();
    void res();
    void add();
    void print2();
    void edit();
    void bill()
    {

        ifstream fin;
        char ch;

        fin.open("data.txt", ios::in | ios::binary);
        if (!fin)
            cout << "File not found";

        else
        {
            ch = fin.get();

            while (!fin.eof())
            {

                cout << ch;

                ch = fin.get();
            }
            fin.close();
        }

        cout << "press any key to go back ";
        getch();
        workerspage();
    }

    //void res();

    void who()
    {
        system("cls");
        cout << "-------------SAMDARIYA MALL--------------------\n";
        cout << "----------------------------------------------\n";
        cout << "----------------WELCOME--------------------  " << endl;
        cout << "if you are custmer press 1\n  if you are worker press 2" << endl;
        cout << "--------------------------------------------------\n";
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "welcome to our store\n";
            buyer();
            break;
        case 2:
            cout << "please login first\n ";
            login();
            break;

        default:
            cout << "please enter correct number \n";
            shop();
            break;
        }
    }
};

void shop ::login()
{
    string email;
    string password;
    cout << "enter email id" << endl;
    cin >> email;
    cout << "enter password" << endl;
    cin >> password;

    if (email == "project@gmail.com" && password == "hii@123")
    {
        cout << "...................welcome to the workers page.........................\n";
        workerspage();
    }
    else
    {
        cout << "please enter correct email and password \n";
        login();
    }
}
void shop ::buyer()
{
    system("cls");
    int no;
    cout << "   .....WELCOME TO THE COSTUMERS PAGE.......                                   \n\n\n";
    cout << "                                                    \n";
    cout << "1. buy product" << endl;

    cout << "2. go back" << endl;
    cout << "3. check recipt\n";
    cout << "enter your choice" << endl;
    cin >> no;
    char c = ' ';

    switch (no)
    {
    case 1:
      /* ofstream fout;
      fout.open("database.txt" , ios::out);
      fout<<c;
      fout.close(); */

        recipts();
        break;
    case 2:
        who();
        break;

    case 3:
      
        print2();
        break;

    default:
        cout << "error please enter correct number";
        getch();
        buyer();
        break;
    }
}

void shop ::workerspage()
{
    system("cls");
    int what;
    cout << "------------------------------------------------------------------------\n";
    cout << "|                    welcome to the workers page                       |\n";
    cout << "|                     1.     ADD PRODUCT                               |\n";
    cout << "|                     2.     edit product                              |\n";
    cout << "|                     3.    delete the product                         |\n";
    cout << "|                     4.     go to the main menu                       |\n";
    cout << "|                     5.     view your bill                            |\n";
    cout << "|                     6.      print bill                               |\n";
    cout << "------------------------------------------------------------------------\n";

    cout << "enter the number for what you want \n";
    cin >> what;

    switch (what)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        cout << " ";
        break;
    case 3:
        res();
        break;
    case 4:
        who();
        break;
    case 5:
        bill();
        break;
    case 6:
        print();
        break;

    default:
        cout << "error enter the correct number";
        getch();
        workerspage();
        break;
    }
}
void shop::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t  modify the record ";
    cout << "\n\t\t\t product code : ";
    cin >> pkey;

    data.open("data.txt", ios::in);
    if (!data)
    {
        cout << "\n \n file doesn't exit! ";
        getch();
        workerspage();
    }
    else
    {

        data1.open("data1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t product new code  : ";
                cin >> c;
                cout << "\n\t\t name of the product : ";
                cin >> n;
                cout << "\n\t\t price : ";
                cin >> p;
                cout << "\n\t\t discount : ";
                cin >> d;

                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t record inserted ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
                
               
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("data.txt");
        rename("data1.txt", "data.txt");

         getch();
                workerspage();

        if (token == 0)
        {
            cout << "record not found";
            getch();
            workerspage();
        }
    }
}


void shop::res()
{
    fstream data,data1;
    int pkey;
    int token = 0;
    cout<<"\n\t\t delete product ";
    cout<<"\n\t\t product code ";
    cin>>pkey;

    data.open("data.txt",ios::in);
    if(!data)
    {
        cout<<"file doesn't exist";
        getch();
        workerspage();
    }
    else{
        data1.open("data1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode == pkey)
            {
                cout<<"\n\t\t product deleted successfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("data.txt");
        rename("data1.txt","data.txt");

        getch();
        workerspage();

        if(token == 0)
        {
            cout<<"data not inserted ";

        }
    }
}
void shop ::add()
{
    int n;
    ofstream data;

    cout << "\n\n\t\t\t  add new product ";
    cout << "\n\n\t product code of the product ";
    cin >> pcode;
    cout << "\n\n\t name of the product ";
    cin >> pname;
    cout << "price of the product ";
    cin >> price;
    cout << "\n\n\t discount on the product ";
    cin >> dis;

    data.open("data.txt", ios::out | ios ::trunc);
    {
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";

        data.close();

        cout << "want to add new product press 1  print recipt press 2 for go back to 3." << endl;
        cin >> n;

        switch (n)
        {
        case 1:
            addnew();
            break;

        case 2:
            recipt();
            break;
        case 3:
            workerspage();
            break;
        default:
            cout << "ERROR PLEASE ENTER CORRECT CHOICE";
            getch();
            data.close();

            break;
        }
    }
}

void shop ::recipt()
{
    system("cls");
    int n;
    cout << "-----------------------------------\n";
    cout << "           RECIPT            \n\n";
    cout << "------------------------------------\n";
    cout << "        TOTAL PRODUCTS ARE     \n\n";
    cout << "-------------------------------------\n";
    ifstream fin;
    char ch;
    fin.open("data.txt", ios::in);

    while (!fin.eof())
    {
        cout << ch;
        ch = fin.get();
    }
    fin.close();
    cout << "if you want to print recipt press 1 . press  key 2 to go back to main menu";
    cin >> n;

    switch (n)
    {
    case 1:
        print();
        break;
    case 2:
        who();
        break;
    default:
        cout << "enter right key ";
        recipt();
        break;
    }
}
void shop ::addnew()
{
    int n;
    ofstream data;

    cout << "\n\n\t\t\t  add new product ";
    cout << "\n\n\t product code of the product ";
    cin >> pcode;
    cout << "\n\n\t name of the product ";
    cin >> pname;
    cout << "price of the product ";
    cin >> price;
    cout << "\n\n\t discount on the product ";
    cin >> dis;

    data.open("data.txt", ios ::app | ios::out);
    {
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";

        data.close();

        cout << "eant to add new product press 1 for go back to print recipt press 2  3. go back " << endl;
        cin >> n;

        switch (n)
        {
        case 1:
            addnew();
            break;

        case 2:
            recipt();
            break;
        case 3:
            workerspage();
            break;
        default:
            cout << "ERROR PLEASE ENTER CORRECT CHOICE";
            getch();
            shop();
            break;
        }
    }
}
void shop ::print()
{
    cout << "printing recipt please wait .....................................";
    getch();
    system("cls");
    cout<<"\n\t\t\tcollect your bill from counter\n";
    cout<<"\n\t\t\tthanks for shooping";
    getch();

    who();
}
void shop::print2()
{
    system("cls");

    ifstream fin;
    char ch;
    fin.open("database.txt", ios::in | ios::binary);

    if(!fin)
    {
        cout<<"file not found";
        
    }

    ch = fin.get();
    while (!fin.eof())
    {
        cout << ch;
        ch = fin.get();
    }
    fin.close();

    ofstream fout;
    fout.open("database.txt" , ios::out);
    fout<<" ";
    fout.close();

    int g;

    cout << "1. print recipt \n";
    cout << "2.  go back \n";
    cin >> g;

    switch (g)
    {
    case 1:
        print();
        break;
    case 2:
        buyer();
        break;

    default:

        cout << "error please try again later ";
        getch();
        print2();
        break;
    }
}

void shop ::recipts()
{
    

    system("cls");
    int s;
    cout << "-------------------------------------------------\n";
    cout << "                     menu                      \n\n";
    cout << "      s.no           name             price    \n";
    cout << "       1.            shoes             699      \n";
    cout << "       2.            medicine          1000      \n";
    cout << "       3.            jeans              1299     \n";
    cout << "-------------------------------------------------------\n";
    cout << "if go back press 4\n";

    cout << "enter your choice ";
    cin >> s;
    string c;
   
     ofstream fout;
    fout.open("database.txt", ios::app | ios::out);
    

    switch (s)
    {
    case 1:
        c = "shoes";
        fout<<c<<"   "<<endl;
        fout.close();
        getch();
        recipts();
        break;

    case 2:
        c = "medicines";
        fout<<c<<"   "<<endl;
        fout.close();
        getch();
        recipts();
        break;

    case 3:
        c = "jeans";
        fout<<c<<"   "<<endl;
        fout.close();
        getch();
        recipts();
        break;

    case 4:
    cout<<"press any key to go back";
    fout.close();
        buyer();

        break;

    default:
        cout << "error!!!!";
        getch();
        recipts();
        break;
    }
}

int main()
{
    shop s;
    s.who();

    getch();
}
