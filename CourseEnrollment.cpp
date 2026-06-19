//
// Name: Afraaz Virani
// Date: 6/15/26
// Course: COSC 1437 C++ Programming Fundamentals II
// Desc: Chapter 7 Lab - Student Course Enrollment System
//
 
#include <iostream>
#include <string>
#include <iomanip>
 
using namespace std;
 
// PART 4: Namespace definition
// Place your enum, typedefs, and function prototypes inside here
namespace EnrollmentSystem
{
    // PART 1: Define the courseType enum here.
    // Also declare a variable currentCourse of type courseType in the same statement.
    // TODO: enum courseType { ... } currentCourse;
    enum courseType { ENGLISH, MATH, HISTORY, CPP, BIOLOGY, ART } currentCourse;


    // PART 2: typedef aliases
    // TODO: typedef int StudentID;
    // TODO: typedef double CreditHours;
    typedef int StudentID;
    typedef double CreditHours;

    // Function prototypes (fill in parameter types)
    // TODO: void printCourse(...);
    // TODO: courseType readCourse();
    // TODO: double calcTuition(...);
    // TODO: void printStudentInfo(...);
    void printCourse(courseType c);
    courseType readCourse();
    double calcTuition(CreditHours credits);
    void printStudentInfo(string fullName, string email, courseType course, StudentID id, CreditHours credits);    
}
 
using namespace EnrollmentSystem;
 
// PART 1b: printCourse
void EnrollmentSystem::printCourse(courseType c)
{
    // TODO: Use a switch statement. 
    // Each case should output the matching course name string.
    switch (c)
    {
        case ENGLISH:
            cout << "English Composition";
            break;
        case MATH:
            cout << "College Algebra";
            break;
        case HISTORY:
            cout << "U.S. History";
            break;
        case CPP:
            cout << "C++ Programming";
            break;
        case BIOLOGY:
            cout << "General Biology";
            break;
        case ART:
            cout << "Art Appreciation";
            break;
        default:
            cout << "Unknown Course";
    }
}
 
// PART 1c: readCourse
EnrollmentSystem::courseType EnrollmentSystem::readCourse()
{
    // TODO: Use if/else if to compare input to each course name and return matching courseType.
    // If no match, print an error and return ENGLISH as default.
    string input;

    cout << endl;
    cout << "Enter course (english/math/history/cpp/biology/art): ";
    cin >> input;

    if (input == "english")
        return ENGLISH;

    else if (input == "math")
        return MATH;

    else if (input == "history")
        return HISTORY;

    else if (input == "cpp")
        return CPP;

    else if (input == "biology")
        return BIOLOGY;

    else if (input == "art")
        return ART;

    else
    {
        cout << "Invalid course entered." << endl;
        return ENGLISH;
    }
}
 
// PART 2: calcTuition
double EnrollmentSystem::calcTuition(CreditHours credits)
{
    // TODO: return credits * 150.0;
    return credits * 150.0;
}
 
// PART 3b: printStudentInfo
void EnrollmentSystem::printStudentInfo(string fullName, string email, courseType course, StudentID id, CreditHours credits)
{
    cout << endl << "--- Enrollment Summary ---" << endl;
    // TODO: Print fullName, id, email, course (via printCourse), credits, and tuition (via calcTuition).
    // Use setprecision(2) and fixed for dollar amounts.
    cout << "Student Name: " << fullName << endl;
    cout << "Student ID: " << id << endl;
    cout << "Email: " << email << endl;

    cout << "Course: ";
    printCourse(course);
    cout << endl;

    cout << "Credit Hours: " << credits << endl;

    cout << fixed << setprecision(2);
    cout << "Tuition: $" << calcTuition(credits) << endl;
}
 
int main()
{
    // --- Welcome banner (use string concatenation) ---
    string line = "================================================";
    
    // TODO: Build and print a welcome banner using + operator.
    cout << line + "\nWelcome to the Student Course Enrollment System\n" + line << endl;
 
    // --- PART 3: String operations ---
    string firstName, lastName, fullName;
    string emailUser, email;
 
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
 
    // TODO 1: Concatenate firstName + " " + lastName into fullName.
    // TODO 2: Output fullName.length() with a label.
    // TODO 3: Use substr to extract and print the first name only (hint: use find to locate space).
    // TODO 4: Use at(0) or [0] to print the first initial.
    // TODO 5: Use find(' ') to find and print the space position.
    cout << endl;
    fullName = firstName + " " + lastName;

    cout << "Full name: " << fullName << endl;

    cout << "Number of characters in full name: " << fullName.length() << endl;

    int spacePosition = fullName.find(" ");
    cout << "Space position: " << spacePosition << endl;  //added print for space position

    cout << "First name only using substr: " << fullName.substr(0, spacePosition) << endl;

    cout << "First initial using at(): " << fullName.at(0) << endl;
 
    cout << endl;
    cout << "Enter email username (e.g. jsmith): ";
    cin >> emailUser;
 
    // TODO 6: Check empty() on emailUser before proceeding.
    // TODO 7: Use insert to append "@sanjac.edu" at the end. Store result in email.
    // TODO 8: Use replace to fix a demo typo (e.g., replace "sanjac" with "SanJac").
    // TODO 9: Use erase to strip trailing punctuation if present.
    cout << endl;
    if (emailUser.empty())
    {
        cout << "Email username is empty." << endl;
    }
    else
    {
        cout << "Email username is not empty." << endl;
    }

    email = emailUser;

    email.insert(email.length(), "@sanjac.edu");
    cout << "Email after insert: " << email << endl;

    email.replace(email.find("sanjac"), 6, "SanJac");
    cout << "Email after replace: " << email << endl;

    email.insert(email.length(), ".");
    cout << "Email with unwanted punctuation: " << email << endl;

    email.erase(email.length() - 1, 1);
    cout << "Email after erase: " << email << endl;
    
    // TODO 10: Declare a second string lastName2 = "Smith" and use compare() to print alphabetical order.
    string lastName2 = "Smith";

    int result = lastName.compare(lastName2);

    cout << endl;
    if (result < 0)
    {
        cout << lastName << " comes before " << lastName2 << " alphabetically." << endl;
    }
    
    else if (result > 0)
    {
        cout << lastName << " comes after " << lastName2 << " alphabetically." << endl;
    }
    
    else
    {
        cout << lastName << " and " << lastName2 << " are the same." << endl;
    }

    // --- PART 1: Enum operations ---
    EnrollmentSystem::currentCourse = readCourse();
    courseType selectedCourse = currentCourse;    //added so even if course is progressed later, we still have the user selected course stored in a seperate variable.

    cout << "You selected: ";
    printCourse(selectedCourse);
    cout << endl;
 
    // TODO: Advance currentCourse by one using static_cast (check that it is not already ART first).
    // Print the next course name.
    currentCourse = MATH;

    if (currentCourse != ART)  //added the (currentCourse != ART) guard
{
    currentCourse = static_cast<courseType>(static_cast<int>(currentCourse) + 1);    //current course is progressed

    cout << "Course after advancing by one: ";
    printCourse(currentCourse);
    cout << endl;
}

else
{
    cout << "Current course is already Art Appreciation. Cannot advance." << endl;
}
 
    // TODO: for loop print all courses using printCourse.
    cout << endl << "All available courses:" << endl;

    for (int i = ENGLISH; i <= ART; i = i + 1)
    {
        printCourse(static_cast<courseType>(i));
        cout << endl;
    }
    
    // TODO: Declare two courseType variables, compare with <, and print which comes later.
    courseType course1 = CPP;
    courseType course2 = BIOLOGY;

    cout << endl << "Course comparison: ";

    if (course1 < course2)
    {
        printCourse(course2);
        cout << " comes later than ";
        printCourse(course1);
        cout << "." << endl;
    }
    
    else
    {
        printCourse(course1);
        cout << " comes later than ";
        printCourse(course2);
        cout << "." << endl;
    }
 
    // --- PART 2: Tuition ---
    CreditHours hours;
    StudentID sid = 10045; // demo student ID
    cout << "\nEnter credit hours: ";
    cin >> hours;
    // TODO: Call calcTuition(hours) and print result.
    cout << fixed << setprecision(2);
    cout << "Student ID: " << sid << endl;
    cout << "Total tuition: $" << calcTuition(hours) << endl;
 
    // --- Summary ---
    // TODO: Call printStudentInfo with the correct arguments.
    printStudentInfo(fullName, email, selectedCourse, sid, hours);

    // PART 4 DEMO: Access one namespace member with full prefix
    cout << "Namespace demo course: ";
    EnrollmentSystem::printCourse(EnrollmentSystem::ART);
    cout << endl;
 
    return 0;
}