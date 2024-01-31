#include <iostream>
#include <fstream>
#include <string.h>
#include <cctype>/* to check the given input is of numeric or alpha*/
#include <ctime>
#include <cstdlib> /*to exit from function*/
#include <regex>   /*to get required format data*/
using namespace std;
void login();
void registration();
bool check_username(string userid);    // Prototype for check_username
bool check_phoneno(string contact_no); // Prototype for check_phoneno

void programs();
bool check_gmail(string gmail);

class person
{
public:
    string name;
    string address;
    string gmail;
    string contact_no;
    int intermedi_obt_marks;
    int matric_obt_marks;

public:
    void get_data()
    {

        bool valid_name = false;
        while (!valid_name)
        {
            cout << "PLEASE ENTER STUDENT NAME =";
            cin.ignore();
            getline(cin, name);
            valid_name = check_username(name);
            if (!valid_name)
            {
                system("cls");
                cout << "INVALID NAME...." << endl;
            }
        }
        while (true)
        {
            cout << "Enter your intermediate obtained marks= ";
            cin >> intermedi_obt_marks;

            if (intermedi_obt_marks >= 900 && intermedi_obt_marks <= 1100)
            {
                string str_marks = to_string(intermedi_obt_marks);
                bool allnumerics = true;

                for (char c : str_marks)
                {
                    if (!isdigit(c))
                    {
                        allnumerics = false;
                        cout << "Invalid Numbers.\n";
                        break;
                    }
                }

                if (allnumerics)
                {
                    break;
                }
            }
            else
            {
                cout << "Invalid..Try Again.\n";
            }
        }
        while (true)
        {
            cout << "Enter your Matric obtained marks= ";
            cin >> matric_obt_marks;

            if (matric_obt_marks >= 900 && matric_obt_marks <= 1100)
            {
                string str_marks = to_string(matric_obt_marks);
                bool allnum = true;

                for (char c : str_marks)
                {
                    if (!isdigit(c))
                    {
                        allnum = false;
                        cout << "Invalid Numbers.\n";
                        break;
                    }
                }

                if (allnum)
                {
                    break;
                }
            }
            else
            {
                cout << "Invalid..Try Again.\n";
            }
        }
        cin.ignore();
        cout << "PLEASE ENTER YOUR FULL ADDRESS =";
        getline(cin, address);
        bool valid_gmail = false;
        while (!valid_gmail) /*used to execute till valid gmail is entered*/
        {
            
            cout << "PLEASE ENTER G-mail =";
            getline(cin, gmail);
            valid_gmail = check_gmail(gmail);
            if (!valid_gmail)
            {
                cout << "INVALID G-mail.PLEASE TRY AGAIN" << endl;
            }
        }

        bool valid_contact = false;
        while (!valid_contact) /*used to execute till valid contact no is entered*/
        {
            cout << "PLEASE ENTER CONTACT NO =";
            getline(cin, contact_no);
            valid_contact = check_phoneno(contact_no);
            if (!valid_contact)
            {

                cout << "INVALID CONTACT NO.PLEASE TRY AGAIN" << endl;
            }
        }

        string filename = name + ".txt";
        ofstream r1(filename); /*opened in append mode for new registration*/
        if (r1.is_open())
        {
            r1 << name << endl; /*saving user's id in file*/
            r1 << intermedi_obt_marks << endl;
            r1 << matric_obt_marks << endl;
            r1 << address << endl;
            r1 << gmail << endl;
            r1 << contact_no << endl;
            
            r1.close(); /* to close opened file*/
        }
    }
};

class student : public person
{
    string registration_number;
    string department;
    int previous_study_year;
    string course;
    int admision_status;

public:
    void get_data()
    {

        person ::get_data();
        cout << "ENTER PREVIOUS DEGREE REGISTRATION NUMBER =";
        cin >> registration_number;
        cin.ignore();
        bool valid_department = false;
        while (!valid_department)
        {
            cout << "PLEASE ENTER YOUR DEPARTMENT NAME =";
            cin.ignore();
            getline(cin, department);
            valid_department = check_username(department);
            if (!valid_department)
            {
                system("cls");
                cout << "INVALID DEPARTMENT NAME...." << endl;
            }
        }
        cout << "ENTER PREVIOUS STUDIED YEAR(You can only apply if your prevoius degree is in between 2020_2023 ) =";
        cin >> previous_study_year;
        if (!(previous_study_year >= 2020 && previous_study_year <= 2023)) /*& both condition should be true*/
        {
            cout << " YOU ARE UNCAPABLE FOR THIS DEGREE..." << endl;
            exit(0); /*to exit from function */
        }
        cout << "ENTER THE NAME OF COURSE =";
        cin.ignore();
        getline(cin, course);

        while (true)
        {
            cout << "ENTER THE ADMISSION STATUS(1 FOR ON MERIT AND 2 FOR ON QUOTE) =";
            cin >> admision_status;
            if (admision_status == 1 || admision_status == 2) /*|| to check any of condition to be true*/
                break;
            else
                cout << "INVALID STATUS..." << endl;
        }
        string filename = name + ".txt";
        ofstream r1(filename, ios ::app);
        if (r1.is_open())
        {
            r1 << registration_number << endl; /*saving user's id in file*/
            r1 << department << endl;
            r1 << previous_study_year << endl;
            r1 << course << endl;
            r1 << admision_status << endl;
            r1.close(); /* to close opened file*/
        }
    }
};
class admission_form : public student
{ /*personal info*/
    string CNIC_NO;
    string father_name;
    string father_occupation;
    string father_CNIC;
    string monthly_income;
    char hafiz_e_quran;
    int gender;
    string datebirth;
    string city;
    string country;

public:
    void get_data()
    {
        student::get_data();
        while (true)
        {
            cout << "Enter your CNIC (numeric form only): ";
            cin >> CNIC_NO;
            if (CNIC_NO.length() == 13)
            {
                bool alldigits = true;
                for (char c : CNIC_NO)
                {
                    if (!isdigit(c))
                    {
                        alldigits = false;
                        cout << "Invalid CNIC. Please enter only digits.\n";
                        break;
                    }
                }
                if (alldigits)
                {
                    alldigits = true;
                    break;
                }
            }
            else
            {
                cout << "Invalid CNIC. Please enter exactly 13 digits.\n";
            }
        }
        bool valid_fathername = false;
        while (!valid_fathername)
        {
            cin.ignore();
            cout << "ENTER YOUR FATHER NAME =";
            getline(cin, father_name);
            valid_fathername = check_username(father_name);
            if (!valid_fathername)
            {
                cout << "PLEASE ENTER VALID NAME..." << endl;
            }
        }
        bool valid_fatheroccup = false;
        while (!valid_fatheroccup)
        {
            cout << "ENTER YOUR FATHER's OCCUPATION =";
            getline(cin, father_occupation);
            valid_fatheroccup = check_username(father_occupation);
            if (!valid_fatheroccup)
            {
                cout << "PLEASE ENTER VALID OCCUPATION..." << endl;
            }
        }
        cout << "PLEASE ENTER FATHER'S ICOME = ";
        cin >> monthly_income;

        bool valid_data = false;
        string hafiz;
        while (!valid_data)
        {

            cout << "ARE YOU HAFIZ E QURAN?(Press y for Yes and n for No) = ";
            cin >> hafiz_e_quran;
            if (hafiz_e_quran == 'y' || hafiz_e_quran == 'Y' || hafiz_e_quran == 'n' || hafiz_e_quran == 'N')
            {
                if (hafiz_e_quran == 'Y' || hafiz_e_quran == 'y')
                {
                    hafiz = "Yes";
                }
                else if (hafiz_e_quran == 'N' || hafiz_e_quran == 'n')
                {
                    hafiz = "No";
                }
                valid_data = true;
            }
            else
            {
                cout << "Enter a valid answer in form of y or n (as yes or no)" << endl;
            }
        }

        bool valid_gender = false;
        string gender_str; /* have use this because i have faced the problem to save
                                            1 as male in func as it was not compatible from moving int to string */
        while (!valid_gender)
        {
            cout << "ENTER YOUR GENDER" << endl;
            cout << "1-Male" << endl;
            cout << "2-Female" << endl;
            cout << "3-Transgender" << endl;
            cin >> gender;
            if (gender >= 1 && gender <= 3)
            {
                if (gender == 1)
                {
                    gender_str = "Male";
                }
                else if (gender == 2)
                {
                    gender_str = "Female";
                }
                else if (gender == 3)
                {
                    gender_str = "Transgender";
                }
                valid_gender = true;
            }
            else
            {
                cout << "Please enter from above 3 options...." << endl;
            }
        }
        int date, month, year;
        bool valid_dateofbirth = false;
        while (!valid_dateofbirth)
        {
            cout << "Enter your date of birth (DD -- ----): ";
            cin >> date;
            cout << "Enter your month of birth (-- MM ----): ";
            cin >> month;
            cout << "Enter your year of birth (-- -- YYYY): ";
            cin >> year;

            if (year < 2000 || year > 2008 || month < 1 || month > 12 || date < 1 || date > 31)
            {
                cout << "Invalid date of birth. Please enter a valid date of birth within the specified ranges." << endl;
                valid_dateofbirth = false;
            }
            else
            {
                valid_dateofbirth = true;
            }
        }
        bool valid_city = false;
        while (!valid_city)
        {
            cin.ignore();
            cout << "Enter your City name ="; /*error*/
            getline(cin, city);
            valid_city = check_username(father_name);
            if (!valid_fathername)
            {
                cout << "PLEASE ENTER VALID CITY NAME..." << endl;
            }
        }
        bool valid_country = false;
        while (!valid_country)
        {
            cout << "ENTER YOUR COUNTRY MNAME =";
            getline(cin, country);
            valid_country = check_username(country);
            if (!valid_country)
            {
                cout << "PLEASE ENTER VALID COUNTRY..." << endl;
            }
        }

        string filename = name + ".txt";
        ofstream r1(filename, ios ::app);
        if (r1.is_open())
        {
            r1 << CNIC_NO << endl;
            r1 << father_name << endl;
            r1 << father_occupation << endl;
            r1 << monthly_income << endl;
            r1 << hafiz_e_quran << endl;
            r1 << gender << endl;
            r1 << city << endl;
            r1 << country << endl;

            r1.close(); /* to close opened file*/
        }
    }
};
void merit_list(string filename);
int main()
{
    
    int c;
    cout << "\t\t\t\t_____________________WELCOME TO PUNJAB UNIVERSITY ADMISSION FORM______________________" << endl;
    cout << "                                                                                      " << endl;
    cout << "PRESS 1 to LOGIN" << endl;
    cout << "PRESS 2 to REGISTER ACCOUNT " << endl;
     cout<<"PRESS 3 TO CHECK MERIT LIST"<<endl;
    cin >> c;
    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
         case 3:
        merit_list("arsla.txt");
        merit_list("ali.txt");
        merit_list("azha.txt");
        break;
    default:
        system("cls");
        cout << "PLEASE ENTER FROM THE GIVEN OPTIONS" << endl;
        main();
    }
}
void login()
{
    int count = 0, n = 0;
    string userid, password; /*user id and password taken as inputs from user */
    string file_id, file_pass;
    cin.ignore();
    cout << "PLEASE ENTER USER ID" << endl;
    getline(cin, userid); /* error*/
    cout << "PLEASE ENTER PASSWORD" << endl;
    getline(cin, password);
    ifstream l1("person1.txt"); /*opening file for reading*/
    if (l1.is_open())
    {                                      /*to check if the file is open*/
        while (l1 >> file_id >> file_pass) /*reading line from file*/
        {
            if (file_id == userid && file_pass == password)
            {
                count = 1;
                break;
            }
        }
        l1.close();
    }
    if (count == 1)
    {
        system("cls");
        cout << " YOU ARE LOGIN IN" << endl;
        cout << "PRESS 1 TO CHECK THE PROGRAMS AVAILABLE...." << endl; /*error to go to main funcation*/
        cin >> n;

        if (n == 1)
        {
            system("cls");
            programs();
        }
    }
    else
    {
        system("cls");
        cout << "LOGGING ERROR" << endl;

        main();
    }
}
void registration()
{
    int n;
    int count;
    string gmail, contact_no;
    string userid, password;
    string file_id, file_password;
    bool valid_name = false;
    while (!valid_name)
    {
        cout << "PLEASE ENTER USER ID =";
        cin.ignore();
        getline(cin, userid);
        valid_name = check_username(userid);
        if (!valid_name)
        {
            system("cls");
            cout << "INVALID NAME...." << endl;
        }
    }

    cout << "PLEASE ENTER PASSWORD =";
    getline(cin, password);
    bool valid_gmail = false;
    while (!valid_gmail) /*used to execute till valid gmail is entered*/
    {
        cout << "PLEASE ENTER YOUR Personal G-mail =";
        getline(cin, gmail);
        valid_gmail = check_gmail(gmail);
        if (!valid_gmail)
        {
            cout << "INVALID G-mail.PLEASE TRY AGAIN" << endl;
        }
    }

    bool valid_contact = false;
    while (!valid_contact) /*used to execute till valid contact no is entered*/
    {
        cout << "PLEASE ENTER CONTACT NO = ";
        getline(cin, contact_no);
        valid_contact = check_phoneno(contact_no);
        if (!valid_contact)
        {

            cout << "INVALID CONTACT NO.PLEASE TRY AGAIN" << endl;
        }
    }
    ofstream r1("person1.txt", ios ::app); /*opened in append mode for new registration*/
    if (r1.is_open())
    {
        r1 << userid << endl; /*saving user's id in file*/
        r1 << password << endl;
        r1 << gmail << endl;
        r1 << contact_no << endl;
        r1.close(); /* to close opened file*/
        cout << "REGISTRATION SUCCESSFULL!" << endl;
        cout << "PRESS 1 TO CHECK THE PROGRAMS AVAILABLE..." << endl; /*error to go to main funcation*/
        cin >> n;

        if (n == 1)
        {
            system("cls");
            programs();
        }
    }
    else
    {
        cout << "PLEASE ENTER FROM GIVEN NO's TO MOVE TO ADMISSION FORM" << endl;
    }
}
bool check_phoneno(string contact_no)
{
    if (contact_no.length() == 11)
    {
        for (char c : contact_no)
        {
            if (!isdigit(c))
            {
                cout << "Please enter valid numeric phone_no = ";
                return false;
            }

            if (isdigit(c))
            {

                return true;
            }
        }

        return true;
    }
    else
    {
        cout << "Please enter 11 numeric number including 03..." << endl;
    }
    return false;
}
bool check_username(string userid)
{
    for (char a : userid)
    {
        if (!isalpha(a))
        {
            cout << "PLEASE ENTER A VALID NAME USING ONLY ALPHABATES" << endl;
            return false;
        }
        if (isalpha(a))
        {
            return true;
        }
    }
    return true;
}

void programs()
{
    int n;
    cout << "Here is the list of Available programs in university" << endl;
    cout << "\t\t BS PROGRAMS( 4 Year Degree)" << endl;
    cout << "\tPRESS 3 FOR TAKING ADMISSION IN ANY OF FOLLOWING PROGRAMS" << endl;
    cout << "1-B.Sc. Chemical Engineering (Regular)" << endl;
    cout << "2-B.S. Applied Geology (Regular)" << endl;
    cout << "3-Bachelor of Fine Arts (Regular)" << endl;
    cout << "4-Bachelor of Medical Laboratory Technology (4-Years) B.Sc. MLT (Hons.) (Regular)" << endl;
    cout << "5-B.S. Home Economics" << endl;
    cout << "6-Bachelor in Bussiness and Information Technology(BBIT)" << endl;
    cout << "7-Bachelor in Business Administration" << endl;
    cout << "\t\tENGINEERING PROGRAMS" << endl;

    cout << "1-Material Engineering" << endl;
    cout << "2-Chemical Engineering" << endl;
    cout << "3-Metallurgy Engineering" << endl;
    cout << "4-Software Engineering" << endl;
    cout << "5-Mechatronics Engineering" << endl;
    cout << "\t\tM.Phill PROGRAMS" << endl;

    cout << "1-Masters in Chemistry " << endl;
    cout << "2-Masters in physics" << endl;
    cout << "3-Masters in Maths " << endl;
    cout << "4-Masters in Business Administration" << endl;
    cout << "5-Masters in Information Technology" << endl;

    cout << "ENTER YOUR CHOICE" << endl;
    cin >> n;
    if (n == 3)
    {
        system("cls");
        admission_form a1;
        a1.get_data();
    }
    else
    {
        cout << "Enter valid choice" << endl;
        programs();
    }
}
bool check_gmail(string gmail)
{
    regex gmail_pattern("^[a-zA-Z0-9._-]+@gmail.com$");
    return regex_match(gmail, gmail_pattern); /*regex_match is a function that checks that the user
                                                 enterd gmail matches the pattern of gmailregex*/
}

struct studentdata
{
    string name;
    int intermedi_obt_marks;
    int matric_obt_marks;
    float merit;
};

void merit_list(string filename)
{
    {
       ifstream file(filename);

        if (file.is_open())
        {
            vector<studentdata> students;

            string line;
            int numLines = 0;

            while (getline(file, line) && numLines < 3)
            {
                studentdata student;
                student.name = line;
                if (getline(file, line))//getting data from first line
                {
                    student.intermedi_obt_marks = stoi(line);
                }
                if (getline(file, line))//getting data from second line
                {
                    student.matric_obt_marks = stoi(line);
                }

                // Calculate merit score with 30% weight on data2 and 70% on data3
                student.merit =100*( (0.3 * student.matric_obt_marks)/1100 +( 0.7 * student.intermedi_obt_marks)/1100);

                students.push_back(student);

                numLines++;
            
            cout << "NAME = " << student.name << "    The merit is = " << student.merit << endl;
            file.close();
        }
    }
}
}