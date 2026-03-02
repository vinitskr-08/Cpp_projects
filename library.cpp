#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <fstream>
using namespace std;

class library
{
public:
    long int units;
    long int Srno;
    string title;
    string author;
    int year;
    void toUpper()
    {
        for (char &c : title)
        {
            c = toupper(c);
        }
        for (char &c : author)
        {
            c = toupper(c);
        }
    }
};

class student : public library
{
public:
    int Rollno;
    string name;
    char className[10];
    int age;
    int book[100];
    int nobk;
    void toUpper()
    {
        for (char &c : name)
        {
            c = toupper(c);
        }
    }
    void bookbuy(int b1)
    {
        book[nobk] = b1;
        nobk += 1;
    }
    void displaybuy();
};

// Global arrays
library l[1000];
student s[1000];

void student::displaybuy()
{
    if (nobk > 0)
    {
        cout << "Total book bought = " << nobk << endl;
        cout << "Books bought by the student:-" << endl;
        for (int i = 0; i < nobk; i++)
        {
            cout << "\nBook Sr no = " << book[i] << endl;
            cout << "Title = " << l[book[i] - 1].title << endl;
            cout << "Author = " << l[book[i] - 1].author << endl;
            cout << "Year of publication = " << l[book[i] - 1].year << endl;
        }
    }
    else
    {
        cout << "No book bought by the student yet." << endl;
    }
}

int n = 1;
int sn = 1;
int shdt = 0;

int saveData();
int loadData();

enum class portal
{
    False,
    True,
    Unknown
};
int wlcm();
portal login();
int abtlib();
int abtapp();
int usrgdl();
int mainmenu1();
int operation1(int);
int mainmenu2();
int operation2(int);
int fnctn1();  // add book
int fnctn2();  // view book
int fnctn3();  // show all book
int fnctn4();  // delete book
int fnctn5();  // delete all book
int fnctn6();  // add student
int fnctn7();  // edit student
int fnctn8();  // show student
int fnctn9();  // show all student
int fnctn10(); // buy book
int fnctn11(); // rent book
int fnctn12(); // return book

int main()
{
    system("cls");
    int main1 = wlcm();
    do
    {
        if (main1 != 0)
        {
            switch (main1)
            {
            case 1:
                main1 == 1;
                {
                    system("cls");
                    portal ans = login();
                    if (ans == portal::True)
                    {
                        cout << "\nAccess granted to Teacher Portal\nPress any key to continue" << endl;
                        getch();
                        system("cls");
                        int menu1 = mainmenu1();
                        do
                        {
                            if (menu1 != 0)
                            {
                                operation1(menu1);
                            }
                            menu1 = mainmenu1();
                        } while (menu1 != 0);
                        cout << "\n\nPress any key to go back to home screen" << endl;
                        getch();
                    }
                    else if (ans == portal::False)
                    {
                        cout << "\nAccess granted to Student Portal\nPress any key to continue" << endl;
                        getch();
                        system("cls");
                        int menu2 = mainmenu2();
                        do
                        {
                            if (menu2 != 0)
                            {
                                operation2(menu2);
                            }
                            menu2 = mainmenu2();
                        } while (menu2 != 0);
                        cout << "Press any key to go back to home screen" << endl;
                        getch();
                    }
                    else
                    {
                        cout << "\nInvalid ID and Password\nAccess Denied\n\n";
                        cout << "Press any key to go back to home screen" << endl;
                        getch();
                    }
                    main1 = wlcm();
                    break;
                }

            case 2:
                main1 == 2;
                abtlib();
                main1 = wlcm();
                break;

            case 3:
                main1 == 3;
                abtapp();
                main1 = wlcm();
                break;

            case 4:
                main1 == 4;
                usrgdl();
                main1 = wlcm();
                break;
            }
        }

    } while (main1 != 0);
    system("cls");
    cout << "Thank you for using the applicaion!!";
    cout << "\n\nPress any key to exit";
    getch();
    system("cls");
}

int wlcm()
{
    system("cls");
    int w1;
    cout << "====================================" << endl;
    cout << "     Welcome to EduAuth Library     " << endl;
    cout << "====================================" << endl;
    cout << "[1] Login" << endl;
    cout << "[2] About Library" << endl;
    cout << "[3] About Application" << endl;
    cout << "[4] User Guidlines" << endl;
    cout << "[0] Exit the program" << endl;
    cout << "====================================" << endl;
    cout << "\nEnter your choice = ";
    cin >> w1;
    return w1;
}

portal login()
{
    string id, pass;
    system("cls");
    cout << "====================================" << endl;
    cout << "             Login page             " << endl;
    cout << "====================================" << endl;
    cout << endl;
    cout << "Enter your login details:-" << endl;
    cout << "Login id = ";
    cin >> id;
    cout << "Password = ";
    cin >> pass;
    if (id == "Teacher" && pass == "teacher@lib")
    {
        return portal::True;
    }
    else if (id == "Student" && pass == "student@lib")
    {
        return portal::False;
    }
    else
        return portal::Unknown;
}

int mainmenu1()
{
    system("cls");
    int m1;
    cout << "===================================" << endl;
    cout << "            MAIN MENU              " << endl;
    cout << "===================================" << endl;
    cout << "[1]  Add a new Book" << endl;
    cout << "[2]  View Book" << endl;
    cout << "[3]  Show all Books" << endl;
    cout << "[4]  Delete Book" << endl;
    cout << "[5]  Delete all Book" << endl;
    cout << "[6]  Add student " << endl;
    cout << "[7]  Edit student" << endl;
    cout << "[8]  Show student" << endl;
    cout << "[9]  Show all student" << endl;
    cout << "[10] Buy Book " << endl;
    cout << "[11] Rent Book" << endl;
    cout << "[12] Return Book" << endl;
    cout << "[0]  Go back to home screen" << endl;
    cout << "===================================" << endl;
    cout << "\nEnter your choice = ";
    cin >> m1;
    return m1;
}

int operation1(int menu1)
{
    switch (menu1)
    {
    case 1:
        fnctn1();
        break;
    case 2:
        fnctn2();
        break;
    case 3:
        fnctn3();
        break;
    case 4:
        fnctn4();
        break;
    case 5:
        fnctn5();
        break;
    case 6:
        fnctn6();
        break;
    case 7:
        fnctn7();
        break;
    case 8:
        fnctn8();
        break;
    case 9:
        fnctn9();
        break;
    case 10:
        fnctn10();
        break;
    case 11:
        fnctn11();
        break;
    case 12:
        fnctn12();
        break;
    }
}

int mainmenu2()
{
    system("cls");
    int m2;
    cout << "===================================" << endl;
    cout << "            MAIN MENU              " << endl;
    cout << "===================================" << endl;
    cout << "[1] View Book" << endl;
    cout << "[2] Show all Books" << endl;
    cout << "[3] Add student " << endl;
    cout << "[4] Edit student" << endl;
    cout << "[5] Show student" << endl;
    cout << "[6] Buy Book " << endl;
    cout << "[7] Rent Book" << endl;
    cout << "[8] Return Book" << endl;
    cout << "[0] Go back to home screen" << endl;
    cout << "===================================" << endl;
    cout << "\nEnter your choice = ";
    cin >> m2;
    return m2;
}

int operation2(int menu2)
{
    switch (menu2)
    {
    case 1:
        fnctn2();
        break;
    case 2:
        fnctn3();
        break;
    case 3:
        fnctn6();
        break;
    case 4:
        fnctn7();
        break;
    case 5:
        fnctn8();
        break;
    case 6:
        fnctn10();
        break;
    case 7:
        fnctn11();
        break;
    case 8:
        fnctn12();
        break;
    }
}

int abtlib()
{
    system("cls");
    cout << "In section about library";
    getch();
}

int abtapp()
{
    system("cls");
    cout << "In section about application";
    getch();
}

int usrgdl()
{
    system("cls");
    cout << "In section user guidlines ";
    getch();
}

int fnctn1() // add book
{
    system("cls");
    cout << "===================================" << endl;
    cout << "            ADD NEW BOOK           " << endl;
    cout << "===================================" << endl;
    cout << "\nBook Srno = " << sn << endl;
    l[sn - 1].Srno = sn;
    cout << "Title = ";
    cin.ignore();
    getline(cin, l[sn - 1].title);
    cout << "Author = ";
    getline(cin, l[sn - 1].author);
    cout << "Year of publicaton = ";
    cin >> l[sn - 1].year;
    cout << "Units = ";
    cin >> l[sn - 1].units;
    l[sn - 1].toUpper();
    cout << "\nNew book added successfully !" << endl;
    sn += 1;
    shdt = 0;
    getch();
}

int fnctn2() // view book
{
    system("cls");
    int x;
    cout << "===================================" << endl;
    cout << "         VIEW BOOK DETAILS         " << endl;
    cout << "===================================" << endl;
    cout << "\nEnter Book Sr no = ";
    cin >> x;
    cout << "Title = " << l[x - 1].title << endl;
    cout << "Author = " << l[x - 1].author << endl;
    cout << "Year of publication = " << l[x - 1].year << endl;
    cout << "Units = " << l[x - 1].units << endl;
    getch();
}

int fnctn3() // show all books
{
    system("cls");
    if (shdt == 0)
    {
        cout << "===================================" << endl;
        cout << "           BOOK DIRECTORY          " << endl;
        cout << "===================================" << endl;
        for (int a = 0; a < sn - 1; a++)
        {
            cout << "\nBook Sr no = " << l[a].Srno << endl;
            cout << "Titile = " << l[a].title << endl;
            cout << "Author = " << l[a].author << endl;
            cout << "Year of publication = " << l[a].year << endl;
            cout << "Units = " << l[a].units << endl;
            cout << endl;
        }
    }
    else if (shdt == 1)
    {
        cout << "===================================" << endl;
        cout << "           BOOK DIRECTORY          " << endl;
        cout << "===================================" << endl;
        cout << "All Books are deleted !" << endl;
        cout << "\nPress any key to go back to the main menu" << endl;
    }
    getch();
}

int fnctn4() // delete book
{
    system("cls");
    int d1;
    cout << "===================================" << endl;
    cout << "            DELETE BOOK            " << endl;
    cout << "===================================" << endl;
    cout << "Enter Book Sr no = ";
    cin >> d1;
    cout << "Title = " << l[d1 - 1].title << endl;
    cout << "Author = " << l[d1 - 1].author << endl;
    cout << "Year of publication = " << l[d1 - 1].year << endl;
    cout << "Units = " << l[d1 - 1].units << endl;

    l[d1 - 1].title = "deleted";
    l[d1 - 1].author = "deleted";
    l[d1 - 1].year = 00;
    l[d1 - 1].units = 00;

    cout << "Book deleted successfully !" << endl;
    getch();
}

int fnctn5() // delete all books
{
    system("cls");
    cout << "===================================" << endl;
    cout << "         DELETE ALL BOOKS          " << endl;
    cout << "===================================" << endl;
    cout << "\nPress any key to delete all students-" << endl;
    getch();
    for (int z = 0; z < sn - 1; z++)
    {
        l[z].title = "deleted";
        l[z].author = "deleted";
        l[z].year = 00;
        l[z].units = 00;
    }
    sn = 1;
    shdt = 1;
    cout << "\nData of all book has been deleted and reset" << endl;
    getch();
}

int fnctn6() // add new student
{
    system("cls");
    cout << "===================================" << endl;
    cout << "        ADD NEW STUDENT            " << endl;
    cout << "===================================" << endl;
    cout << "\nStudent roll no=" << n << endl;
    s[n - 1].Rollno = n;
    cout << "Name = ";
    cin.ignore();
    getline(cin, s[n - 1].name);
    cout << "Age = ";
    cin >> s[n - 1].age;
    cout << "Class = ";
    cin >> s[n - 1].className;
    strupr(s[n - 1].className);
    s[n - 1].toUpper();
    cout << "\nNew student added successfully !" << endl;
    n += 1;
    getch();
}

int fnctn7() // edit student
{
    system("cls");
    cout << "===================================" << endl;
    cout << "         EDIT STUDENT              " << endl;
    cout << "===================================" << endl;
    int e1;
    cout << "\nEnter student Roll no=";
    cin >> e1;

    cout << "\nEarlier saved details:-" << endl;
    cout << "Name = " << s[e1 - 1].name << endl;
    cout << "Age = " << s[e1 - 1].age << endl;
    cout << "Class = " << s[e1 - 1].className << endl;

    cout << "\nEnter new details:-" << endl;
    cout << "Name = ";
    cin.ignore();
    getline(cin, s[e1 - 1].name);
    cout << "Age = ";
    cin >> s[e1 - 1].age;
    cout << "Class = ";
    cin >> s[e1 - 1].className;

    strupr(s[e1 - 1].className);
    s[e1 - 1].toUpper();

    cout << "\nStudent edited successfully !" << endl;
    getch();
}

int fnctn8() // show student
{
    int x;
    system("cls");
    cout << "===================================" << endl;
    cout << "       VIEW STUDENT DETAILS        " << endl;
    cout << "===================================" << endl;
    cout << "\nEnter student roll no=";
    cin >> x;
    cout << "\nName = " << s[x - 1].name << endl;
    cout << "Age = " << s[x - 1].age << endl;
    cout << "Class = " << s[x - 1].className << endl;
    cout << endl;
    s[x - 1].displaybuy();
    getch();
    system("cls");
}

int fnctn9() // show all student
{
    system("cls");
    system("cls");

    cout << "===================================" << endl;
    cout << "        STUDENT DIRECTORY          " << endl;
    cout << "===================================" << endl;
    for (int y = 0; y < n - 1; y++)
    {
        cout << "\nStudent roll no=" << s[y].Rollno << endl;
        cout << "Name = " << s[y].name << endl;
        cout << "Age = " << s[y].age << endl;
        cout << "Class = " << s[y].className << endl;
        cout << endl;
    }
    getch();
}

int fnctn10() // buy
{
    system("cls");
    cout << "===================================" << endl;
    cout << "             BUY A BOOK            " << endl;
    cout << "===================================" << endl;
    cout << "\nEnter student roll no=";
    int s1;
    cin >> s1;
    cout << "\nYour name = " << s[s1 - 1].name << endl;
    cout << "Your class = " << s[s1 - 1].className << endl;
    cout << "Your age = " << s[s1 - 1].age << endl;
    cout << "\nEnter Book Srno to be purchased= ";
    int b1;
    cin >> b1;
    cout << "Title = " << l[b1 - 1].title << endl;
    cout << "Author = " << l[b1 - 1].author << endl;
    cout << "Year of publication = " << l[b1 - 1].year << endl;
    cout << "Units available = " << l[b1 - 1].units << endl;
    getch();
    if (l[b1 - 1].units > 0)
    {
        l[b1 - 1].units -= 1;
        cout << "\nBook bought successfully !" << endl;
        s[s1 - 1].bookbuy(b1);
    }
    else
    {
        cout << "\nBook is out of stock !" << endl;
    }
    getch();
}

int fnctn11() // rent
{
    system("cls");
    cout << "In section fnctn11 ";
    getch();
}

int fnctn12() // return
{
    system("cls");
    cout << "In section fnctn12 ";
    getch();
}
