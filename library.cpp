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
    int rent[100];
    int nobk;
    int numRent;
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
    void rentbook(int b1)
    {
        rent[numRent] = b1;
        numRent += 1;
    }
    void returnbook(int b1)
    {
        for (int i = 0; i < numRent; i++)
        {
            if (rent[i] == b1)
            {
                for (int j = i; j < numRent - 1; j++)
                {
                    rent[j] = rent[j + 1];
                }
                numRent -= 1;
                break;
            }
        }
    }
    void displaybuy();
    void displayrent();
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
void student::displayrent()
{
    if (numRent > 0)
    {
        cout << "Total book rented = " << numRent << endl;
        cout << "Books rented by the student:-" << endl;
        for (int i = 0; i < numRent; i++)
        {
            cout << "\nBook Sr no = " << rent[i] << endl;
            cout << "Title = " << l[rent[i] - 1].title << endl;
            cout << "Author = " << l[rent[i] - 1].author << endl;
            cout << "Year of publication = " << l[rent[i] - 1].year << endl;
        }
    }
    else
    {
        cout << "No book rented by the student yet." << endl;
    }
}

int n = 1;
int sn = 1;
int shdt = 0;
int shstd = 1;

void saveData();
void loadData();

enum class portal
{
    False,
    True,
    Unknown
};
int wlcm();
portal login();
int abtlib(); // about library
int abtapp(); // about application
int usrgdl(); // user guidlines
int mainmenu1();
int operation1(int);
int mainmenu2();
int operation2(int);
int fnctn1();  // add book
int fnctn2();  // view book
int fnctn3();  // show all book
int fnctn4();  // edit book
int fnctn5();  // delete book
int fnctn6();  // delete all book
int fnctn7();  // add student
int fnctn8();  // edit student
int fnctn9();  // show student
int fnctn10(); // show all student
int fnctn11(); // buy book
int fnctn12(); // rent book
int fnctn13(); // return book
int fnctn14(); // delete student
int fnctn15(); // delete all students

int main()
{
    system("cls");
    loadData();
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
    saveData();
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
    cout << "[4]  Edit Book" << endl;
    cout << "[5]  Delete Book" << endl;
    cout << "[6]  Delete all Book" << endl;
    cout << "[7]  Add student " << endl;
    cout << "[8]  Edit student" << endl;
    cout << "[9]  Show student" << endl;
    cout << "[10] Show all student" << endl;
    cout << "[11] Buy Book " << endl;
    cout << "[12] Rent Book" << endl;
    cout << "[13] Return Book" << endl;
    cout << "[14] Delete student" << endl;
    cout << "[15] Delete all students" << endl;
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
    case 13:
        fnctn13();
        break;
    case 14:
        fnctn14();
        break;
    case 15:
        fnctn15();
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
    cout << "[9] Delete student" << endl;
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
        fnctn7();
        break;
    case 4:
        fnctn8();
        break;
    case 5:
        fnctn9();
        break;
    case 6:
        fnctn11();
        break;
    case 7:
        fnctn12();
        break;
    case 8:
        fnctn13();
        break;
    case 9:
        fnctn14();
        break;
    }
}

void saveData()
{
    ofstream file("library.dat");
    file << sn << "\n" << n << "\n";
    // Save all books
    for (int i = 0; i < sn - 1; i++)
    {
        file << l[i].Srno << "\n";
        file << l[i].title << "\n";
        file << l[i].author << "\n";
        file << l[i].year << "\n";
        file << l[i].units << "\n";
    }

    // Save all students
    for (int i = 0; i < n - 1; i++)
    {
        file << s[i].Rollno << "\n";
        file << s[i].name << "\n";
        file << s[i].age << "\n";
        file << s[i].className << "\n";
        file << s[i].nobk << "\n";
        file << s[i].numRent << "\n";

        for (int j = 0; j < s[i].nobk; j++)
            file << s[i].book[j] << " ";
        file << "\n";

        for (int j = 0; j < s[i].numRent; j++)
            file << s[i].rent[j] << " ";
        file << "\n";
    }
    file.close();
}

void loadData()
{
    ifstream file("library.dat");
    if (!file.is_open())
    {
        return;
    }
    file >> sn >> n;
    // Read all books
    for (int i = 0; i < sn - 1; i++)
    {
        file >> l[i].Srno;
        file.ignore();
        getline(file, l[i].title);
        getline(file, l[i].author);
        file >> l[i].year;
        file >> l[i].units;
    }

    // Read all students
    for (int i = 0; i < n - 1; i++)
    {
        file >> s[i].Rollno;
        file.ignore();
        getline(file, s[i].name);
        file >> s[i].age;
        file.ignore();
        file.getline(s[i].className, 10);
        file >> s[i].nobk >> s[i].numRent;
        // Read bought books
        for (int j = 0; j < s[i].nobk; j++)
            file >> s[i].book[j];
        // Read rented books
        for (int j = 0; j < s[i].numRent; j++)
            file >> s[i].rent[j];
    }
    file.close();
}

int abtlib() // about library
{
    system("cls");
    cout << "===================================" << endl;
    cout << "        ABOUT OUR LIBRARY          " << endl;
    cout << "===================================" << endl;
    cout << "\n1. Comprehensive Book Collection:-" << endl;
    cout << "   We maintain a vast collection of books across multiple" << endl;
    cout << "   subjects and genres for students and teachers." << endl;
    cout << "\n2. Easy Book Management System:-" << endl;
    cout << "   Our digital system makes it easy to track, add, and" << endl;
    cout << "   manage books in the library inventory." << endl;
    cout << "\n3. Student-Friendly Access:-" << endl;
    cout << "   Students can easily search, view, and purchase books" << endl;
    cout << "   according to their academic needs." << endl;
    cout << "\n4. Real-time Inventory Tracking:-" << endl;
    cout << "   We maintain live updates on book availability and units" << endl;
    cout << "   in stock for better resource management." << endl;
    cout << "\n5. Teacher Portal Features:-" << endl;
    cout << "   Teachers have exclusive access to add books, manage" << endl;
    cout << "   students, and oversee library operations." << endl;
    cout << "\n6. Affordable Book Purchasing:-" << endl;
    cout << "   Students can buy books directly through the system at" << endl;
    cout << "   reasonable rates as per library pricing." << endl;
    cout << "\n7. Book Rental Services:-" << endl;
    cout << "   We offer flexible rental options for students who need" << endl;
    cout << "   books temporarily without permanent ownership." << endl;
    cout << "\n8. Student Record Management:-" << endl;
    cout << "   Detailed student profiles help us track who has purchased" << endl;
    cout << "   or rented books and their reading history." << endl;
    cout << "\n9. Organized Book Directory:-" << endl;
    cout << "   All books are cataloged with title, author, year of" << endl;
    cout << "   publication, and available units for quick reference." << endl;
    cout << "\n10. Secure Book Return System:-" << endl;
    cout << "    We maintain a streamlined process for book returns and" << endl;
    cout << "    inventory reconciliation after rental periods." << endl;
    cout << "\n"
         << endl;
    cout << "Press any key to go back to home screen" << endl;
    getch();
}

int abtapp() // about application
{
    system("cls");
    cout << "===================================" << endl;
    cout << "      ABOUT THIS APPLICATION      " << endl;
    cout << "===================================" << endl;
    cout << "\n1. EduAuth Library Management System:-" << endl;
    cout << "   A comprehensive digital solution for managing library" << endl;
    cout << "   operations in educational institutions." << endl;
    cout << "\n2. Dual Portal Access:-" << endl;
    cout << "   Provides separate portals for teachers and students with" << endl;
    cout << "   role-based access and specific functionalities." << endl;
    cout << "\n3. Book Inventory Management:-" << endl;
    cout << "   Complete control over adding, viewing, editing, and" << endl;
    cout << "   deleting books from the library database." << endl;
    cout << "\n4. Student Profile Management:-" << endl;
    cout << "   Create and maintain detailed student records including" << endl;
    cout << "   name, age, class, and purchase/rental history." << endl;
    cout << "\n5. Transaction Tracking:-" << endl;
    cout << "   Automatically tracks all book purchases and rentals" << endl;
    cout << "   with complete transaction history for each student." << endl;
    cout << "\n6. Secure Authentication:-" << endl;
    cout << "   Password-protected login system to ensure only authorized" << endl;
    cout << "   users can access specific portals and features." << endl;
    cout << "\n7. User-Friendly Interface:-" << endl;
    cout << "   Simple menu-driven console interface that makes navigation" << endl;
    cout << "   intuitive for both technical and non-technical users." << endl;
    cout << "\n8. Real-time Data Management:-" << endl;
    cout << "   Instant updates to inventory when books are purchased," << endl;
    cout << "   rented, or returned by students." << endl;
    cout << "\n9. Comprehensive Search Features:-" << endl;
    cout << "   Find books by serial number and view detailed information" << endl;
    cout << "   including title, author, and publication year." << endl;
    cout << "\n10. Educational Support Tool:-" << endl;
    cout << "    Designed specifically to support educational institutions" << endl;
    cout << "    in managing their library resources efficiently." << endl;
    cout << "\n"
         << endl;
    cout << "Press any key to go back to home screen" << endl;
    getch();
}

int usrgdl() // user guidlines
{
    system("cls");
    cout << "===================================" << endl;
    cout << "        USER GUIDELINES            " << endl;
    cout << "===================================" << endl;
    cout << "\n1. Login Credentials:-" << endl;
    cout << "   Teacher: ID 'Teacher', Password 'teacher@lib'" << endl;
    cout << "   Student: ID 'Student', Password 'student@lib'" << endl;
    cout << "\n2. Teacher Portal Operations:-" << endl;
    cout << "   Teachers can add, view, edit, and delete books and" << endl;
    cout << "   student records. Use the menu options to navigate." << endl;
    cout << "\n3. Student Portal Operations:-" << endl;
    cout << "   Students can view books, manage their profiles, and" << endl;
    cout << "   purchase or rent books from the library collection." << endl;
    cout << "\n4. Adding Books:-" << endl;
    cout << "   Enter book details including title, author, year of" << endl;
    cout << "   publication, and available units in the library." << endl;
    cout << "\n5. Student Registration:-" << endl;
    cout << "   Provide student details such as name, age, and class." << endl;
    cout << "   Each student gets a unique roll number automatically." << endl;
    cout << "\n6. Purchasing Books:-" << endl;
    cout << "   Select a book by its serial number and confirm purchase." << endl;
    cout << "   Units available will decrease after successful purchase." << endl;
    cout << "\n7. Viewing Book Information:-" << endl;
    cout << "   Use the 'View Book' option to check title, author, year," << endl;
    cout << "   and units available before making a purchase decision." << endl;
    cout << "\n8. Managing Student Data:-" << endl;
    cout << "   Use 'Edit Student' option to update student information." << endl;
    cout << "   View individual or all student records as needed." << endl;
    cout << "\n9. Stock Management:-" << endl;
    cout << "   The system automatically updates stock when books are" << endl;
    cout << "   purchased. Out of stock books cannot be purchased." << endl;
    cout << "\n10. Returning to Menu:-" << endl;
    cout << "    Enter '0' at any menu prompt to return to the previous" << endl;
    cout << "    menu or home screen. Press ESC to exit the application." << endl;
    cout << "\n"
         << endl;
    cout << "Press any key to go back to home screen" << endl;
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
    cout << "\nPress any key to go back to the main menu" << endl;
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
    cout << "\nPress any key to go back to the main menu" << endl;
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
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
}

int fnctn4() // edit book
{
    system("cls");
    int e1;
    cout << "===================================" << endl;
    cout << "            EDIT BOOK              " << endl;
    cout << "===================================" << endl;
    cout << "\nEnter Book Sr no = ";
    cin >> e1;
    cout << "\nSaved details:-" << endl;
    cout << "Title = " << l[e1 - 1].title << endl;
    cout << "Author = " << l[e1 - 1].author << endl;
    cout << "Year of publication = " << l[e1 - 1].year << endl;
    cout << "Units = " << l[e1 - 1].units << endl;
    cout << "\nEnter new units:-" << endl;
    cout << "Units = ";
    cin >> l[e1 - 1].units;
    cout << "\nBook edited successfully !" << endl;
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
}

int fnctn5() // delete book
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
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
}

int fnctn6() // delete all books
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
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
}

int fnctn7() // add new student
{
    system("cls");
    cout << "===================================" << endl;
    cout << "        ADD NEW STUDENT            " << endl;
    cout << "===================================" << endl;
    cout << "\nStudent roll no=" << n << endl;
    s[n - 1].Rollno = n;
    s[n - 1].nobk = 0;
    s[n - 1].numRent = 0;
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
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
}

int fnctn8() // edit student
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
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
}

int fnctn9() // show student
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
    s[x - 1].displayrent();
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
    system("cls");
}

int fnctn10() // show all student
{
    system("cls");
    system("cls");

    cout << "===================================" << endl;
    cout << "        STUDENT DIRECTORY          " << endl;
    cout << "===================================" << endl;

    if (shstd == 1)
    {
        for (int y = 0; y < n - 1; y++)
        {
            cout << "\nStudent roll no=" << s[y].Rollno << endl;
            cout << "Name = " << s[y].name << endl;
            cout << "Age = " << s[y].age << endl;
            cout << "Class = " << s[y].className << endl;
        }
    }
    else if (shstd == 0)
    {
        cout << "All students are deleted !" << endl;
        cout << "\nPress any key to go back to the main menu" << endl;
    }
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
}

int fnctn11() // buy
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
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
}

int fnctn12() // rent
{
    system("cls");
    cout << "===================================" << endl;
    cout << "             RENT A BOOK           " << endl;
    cout << "===================================" << endl;
    cout << "Enter student roll no=";
    int s1;
    cin >> s1;
    cout << "\nYour name = " << s[s1 - 1].name << endl;
    cout << "Your class = " << s[s1 - 1].className << endl;
    cout << "Your age = " << s[s1 - 1].age << endl;
    cout << "\n\nEnter Book Srno to be rented= ";
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
        cout << "\nBook rented successfully !" << endl;
        s[s1 - 1].rentbook(b1);
    }
    else
    {
        cout << "\nBook is out of stock !" << endl;
    }
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
}

int fnctn13() // return
{
    system("cls");
    cout << "===================================" << endl;
    cout << "             RETURN A BOOK         " << endl;
    cout << "===================================" << endl;
    cout << "Enter student roll no=";
    int s1;
    cin >> s1;
    cout << "\nYour name = " << s[s1 - 1].name << endl;
    cout << "Your class = " << s[s1 - 1].className << endl;
    cout << "Your age = " << s[s1 - 1].age << endl;
 
    cout << endl;
    s[s1 - 1].displayrent();
    cout << "\n\nEnter Book Srno to be returned= ";
    int b1;
    cin >> b1;

    cout << "Title = " << l[b1 - 1].title << endl;
    cout << "Author = " << l[b1 - 1].author << endl;
    cout << "Year of publication = " << l[b1 - 1].year << endl;
    getch();

    l[b1 - 1].units += 1;
    cout << "\nBook returned successfully !" << endl;
    s[s1 - 1].returnbook(b1);
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
}

int fnctn14() // delete student
{
    system("cls");
    int d1;
    cout << "===================================" << endl;
    cout << "            DELETE STUDENT         " << endl;
    cout << "===================================" << endl;
    cout << "\nEnter student Roll no=";
    cin >> d1;
    cout << "\nName = " << s[d1 - 1].name << endl;
    cout << "Age = " << s[d1 - 1].age << endl;
    cout << "Class = " << s[d1 - 1].className << endl;

    s[d1 - 1].name = "deleted";
    s[d1 - 1].age = 00;
    strcpy(s[d1 - 1].className, "deleted");
    s[d1 - 1].nobk = 0;
    s[d1 - 1].numRent = 0;

    cout << "\nStudent deleted successfully !" << endl;
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
}
int fnctn15() // delete all students
{
    system("cls");
    cout << "===================================" << endl;
    cout << "         DELETE ALL STUDENTS       " << endl;
    cout << "===================================" << endl;
    cout << "\nPress any key to delete all students-" << endl;
    getch();
    for (int z = 0; z < n - 1; z++)
    {
        s[z].name = "deleted";
        s[z].age = 00;
        strcpy(s[z].className, "deleted");
        s[z].nobk = 0;
        s[z].numRent = 0;
    }
    n = 1;
    shstd = 1;
    cout << "\nData of all students has been deleted and reset" << endl;
    cout << "\nPress any key to go back to the main menu" << endl;
    getch();
}
