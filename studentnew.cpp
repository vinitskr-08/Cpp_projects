#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <fstream>
using namespace std;

class Student
{
public:
    int Rollno;
    char name[10];
    int age;
    char className[10];
};

Student s[100];
int shdt = 0;
int n = 1;

// Function declarations
int mainmenu();
void operations(int);
void fnctn1(int &);
void fnctn2(int);
void fnctn3();
void fnctn4();
void fnctn5();
void fnctn6(int &);
void fnctn7();
void fnctn8();
void saveData(int);
void loadData(int &);

// Save all students to file (text mode)
void saveData(int n)
{
    ofstream outFile("students.dat"); // text mode
    outFile << n << endl;             // save count
    for (int i = 0; i < n - 1; i++)
    {
        outFile << s[i].Rollno << " ";
        outFile << s[i].name << " ";
        outFile << s[i].age << " ";
        outFile << s[i].className << endl;
    }
    outFile.close();
}

// Load students from file (text mode)
void loadData(int &n)
{
    ifstream inFile("students.dat"); // text mode
    if (!inFile)
        return; // file doesn’t exist yet
    inFile >> n;
    for (int i = 0; i < n - 1; i++)
    {
        inFile >> s[i].Rollno >> s[i].name >> s[i].age >> s[i].className;
    }
    inFile.close();
}

int main()
{
    int menu1;
    loadData(n); // load saved students when program starts
    do
    {
        menu1 = mainmenu();
        if (menu1 != 0)
        {
            operations(menu1);
        }
    } while (menu1 != 0);

    saveData(n); // save before exiting
    system("cls");
    cout << "Thank you for using the application !" << endl;
    cout << "Press any key to exit" << endl;
    getch();
    system("cls");
}

int mainmenu()
{
    int m1;
    system("cls");
    cout << "===================================" << endl;
    cout << "            MAIN MENU              " << endl;
    cout << "===================================" << endl;
    cout << "[1] Add a new student" << endl;
    cout << "[2] Show all student" << endl;
    cout << "[3] Show student" << endl;
    cout << "[4] Edit student" << endl;
    cout << "[5] Delete student" << endl;
    cout << "[6] Delete all student" << endl;
    cout << "[7] User guidelines" << endl;
    cout << "[8] About us" << endl;
    cout << "[0] Exit the program" << endl;
    cout << "===================================" << endl;
    cout << "\nEnter your choice = ";
    cin >> m1;
    return m1;
}

void operations(int menu1)
{
    switch (menu1)
    {
    case 1:
        fnctn1(n);
        break;
    case 2:
        fnctn2(n);
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
        fnctn6(n);
        break;
    case 7:
        fnctn7();
        break;
    case 8:
        fnctn8();
        break;
    }
}

void fnctn1(int &n)
{
    system("cls");
    cout << "===================================" << endl;
    cout << "        ADD NEW STUDENT            " << endl;
    cout << "===================================" << endl;
    cout << "\nStudent roll no=" << n << endl;
    s[n - 1].Rollno = n;
    cout << "Name=";
    cin >> s[n - 1].name;
    cout << "Age=";
    cin >> s[n - 1].age;
    cout << "Class=";
    cin >> s[n - 1].className;
    strupr(s[n - 1].className);
    strupr(s[n - 1].name);
    cout << "\nNew student added successfully !" << endl;
    getch();
    shdt = 0;
    n += 1;
    saveData(n); // save after adding
    system("cls");
}

void fnctn2(int n)
{
    system("cls");
    if (shdt == 0)
    {
        cout << "===================================" << endl;
        cout << "        STUDENT DIRECTORY          " << endl;
        cout << "===================================" << endl;
        for (int y = 0; y < n - 1; y++)
        {
            cout << "\nStudent roll no=" << s[y].Rollno << endl;
            cout << "Name=" << s[y].name << endl;
            cout << "Age=" << s[y].age << endl;
            cout << "Class=" << s[y].className << endl;
            cout << endl;
        }
    }
    else if (shdt == 1)
    {
        cout << "===================================" << endl;
        cout << "        STUDENT DIRECTORY          " << endl;
        cout << "===================================" << endl;
        cout << "All students data is deleted !" << endl;
        cout << "\nPress any key to go back to the main menu" << endl;
    }
    getch();
    system("cls");
}

void fnctn3()
{
    int x;
    system("cls");
    cout << "===================================" << endl;
    cout << "       VIEW STUDENT DETAILS        " << endl;
    cout << "===================================" << endl;
    cout << "\nEnter student roll no=";
    cin >> x;
    cout << "\nName=" << s[x - 1].name << endl;
    cout << "Age=" << s[x - 1].age << endl;
    cout << "Class=" << s[x - 1].className << endl;
    getch();
    system("cls");
}

void fnctn4()
{
    system("cls");
    cout << "===================================" << endl;
    cout << "         EDIT STUDENT              " << endl;
    cout << "===================================" << endl;
    int e1;
    cout << "\nEnter student Roll no=";
    cin >> e1;

    cout << "\nEarlier saved details:-" << endl;
    cout << "Name=" << s[e1 - 1].name << endl;
    cout << "Age=" << s[e1 - 1].age << endl;
    cout << "Class=" << s[e1 - 1].className << endl;

    cout << "\nEnter new details:-" << endl;
    cout << "Name=";
    cin >> s[e1 - 1].name;
    cout << "Age=";
    cin >> s[e1 - 1].age;
    cout << "Class=";
    cin >> s[e1 - 1].className;

    strupr(s[e1 - 1].className);
    strupr(s[e1 - 1].name);

    cout << "\nStudent edited successfully !" << endl;
    saveData(n); // save after editing
    getch();
    system("cls");
}

void fnctn5()
{
    system("cls");
    int d1;
    cout << "===================================" << endl;
    cout << "         DELETE STUDENT            " << endl;
    cout << "===================================" << endl;
    cout << "Enter student roll number=";
    cin >> d1;
    cout << "Name=" << s[d1 - 1].name << endl;
    cout << "Age=" << s[d1 - 1].age << endl;
    cout << "Class=" << s[d1 - 1].className << endl;

    strcpy(s[d1 - 1].name, "DELETED");
    s[d1 - 1].age = 0;
    strcpy(s[d1 - 1].className, "DELETED");

    cout << "\nStudent deleted successfully !" << endl;
    saveData(n); // save after deleting
    getch();
    system("cls");
}

void fnctn6(int &n)
{
    system("cls");
    cout << "===================================" << endl;
    cout << "      DELETE ALL STUDENT DATA      " << endl;
    cout << "===================================" << endl;
    cout << "\nPress any key to delete all students-" << endl;
    getch();

    // Reset all student entries
    for (int z = 0; z < n - 1; z++)
    {
        strcpy(s[z].name, "DELETED");
        s[z].age = 0;
        strcpy(s[z].className, "DELETED");
    }

    // Reset counters
    n = 1;
    shdt = 1;

    // Overwrite file with empty data
    ofstream outFile("students.dat"); // text mode
    outFile.close();

    cout << "\nAll student data has been deleted and reset!" << endl;
    getch();
    system("cls");
}
void fnctn7()
{
    system("cls");
    cout << "===================================" << endl;
    cout << "         USER GUIDELINES           " << endl;
    cout << "===================================" << endl;
    cout << "1) Enter roll numbers sequentially — the system auto-assigns them starting from 1." << endl;
    cout << "2 Use alphabetic characters for names and class names, avoid special symbols." << endl;
    cout << "3) Enter valid age values — preferably between 5 and 25 years." << endl;
    cout << "4) Add student data before accessing view, edit, or delete options." << endl;
    cout << "5) Avoid duplicate entries — each roll number corresponds to one student only." << endl;
    cout << "6) Use \"Delete All Students\" carefully — it permanently clears all data." << endl;
    cout << "7) To view a specific student, ensure the roll number exists." << endl;
    cout << "8) Editing a student updates their information, not their roll number." << endl;
    cout << "9) Deleted student entries will show placeholder text like \"DELETED\"." << endl;
    cout << "10) Exiting the program saves data to file — so your records persist." << endl;
    cout << "11) No undo feature — once deleted, student data cannot be restored." << endl;
    cout << "12) Follow prompts closely and press keys only when instructed." << endl;
    cout << "13) Use keyboard inputs only — mouse interactions aren't supported." << endl;
    cout << "14) Keep class names consistent for better filtering in future updates." << endl;
    cout << "15) Reach out to developers for bugs, suggestions, or improvements." << endl;
    getch();
    system("cls");
}

void fnctn8()
{
    system("cls");
    cout << "===================================" << endl;
    cout << "             ABOUT US              " << endl;
    cout << "===================================" << endl;
    cout << "\n1) Welcome to the Student Record Manager." << endl;
    cout << "2) Built for managing student data with ease." << endl;
    cout << "3) Designed with structured menus for clarity." << endl;
    cout << "4) Powered by the C++ programming language." << endl;
    cout << "5) Ideal for learners and classroom use." << endl;
    cout << "6) Each student record is treated with care." << endl;
    cout << "7) Simple interface for editing and viewing." << endl;
    cout << "8) Future-ready for enhancements and updates." << endl;
    cout << "9) User suggestions are always appreciated." << endl;
    cout << "10) Built in C++ with love, logic, and lots of debugging!" << endl;
    cout << "\n- This program was proudly crafted by Vinit Sonkar." << endl;
    cout << "\nThank you for using our system. Stay curious, keep coding!" << endl;
    cout << "\nPress any key to return to the main menu." << endl;
    getch();
    system("cls");
}