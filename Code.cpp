#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class student
{
    class
    {
        // Private section
    public:
        // Public Declarations
    protected:
        // Protected Declarations
    };

    string sname, sbranch;
    int sid, nfb;

public:
    student()
    {
        sname = " ";
        sbranch = " ";
        sid = 0;
        nfb = 0;
    }

    int bn[5], d[5], m[5], y[5];
    string bnam[5];
    void getdata()
    {
        cout << "enter the name of student :";
        fflush(stdin);
        getline(cin, sname);
        cout << "enter the id of student :";
        cin >> sid;
        cout << "enter the branch of student :";
        fflush(stdin);
        getline(cin, sbranch);
    }
    void display()
    {
        cout << "STUDENT NAME :" << sname << "   BRANCH : " << sbranch << "   ID: " << sid << "   BOOK ISSUED: " << nfb << endl;
    }
    void showstbooks()
    {
        for (int ih = 0; ih < nfb; ih++)
        {
            cout << ih + 1 << ".  BOOK NAME : " << bnam[ih] << "    BOOK ID " << bn[ih] << "   ISSUE DATE: " << d[ih] << "/" << m[ih] << "/" << y[ih] << endl;
        }
    }
    void addbooks(int start1, int bn1, string bnm, int d1, int m1, int y1)
    {

        for (int s1 = nfb; s1 < (nfb + 1); s1++)
        {
            bnam[s1] = bnm;
            bn[s1] = bn1;
            d[s1] = d1;
            m[s1] = m1;
            y[s1] = y1;
        }
        nfb++;
    }
    int removebooks(int bnr, int dr, int mr, int yr)
    {
        int temp1, temp3, find = 0, temp2, temp, t, fine = 0, pa;
        string str;
        for (int sr = 0; sr < nfb; sr++)
        {
            if (bnr == bn[sr])
            {
                t = sr;
                find = 1;
                cout << "\t\t\t**BOOK FOUND ***" << endl;
                break;
            }
        }
        if (find == 1)
        {

            fine = (((yr - y[t]) * 365) + ((mr - m[t]) * 30) + (dr - (d[t] + 10))) * 2;
            if (fine >= 0)
            {
                cout << "\n\t\t\t** YOUR FINE FOR BOOK LATE RETURN IS :" << fine << endl;
                cout << " \t\t\t****PAY NOW YOUR FINE : ";
                cin >> pa;
            }
            temp = bn[nfb - 1];
            bn[nfb - 1] = bn[t];
            bn[t] = temp;

            temp1 = y[nfb - 1];
            y[nfb - 1] = y[t];
            y[t] = temp1;

            temp2 = m[nfb - 1];
            m[nfb - 1] = m[t];
            m[t] = temp2;

            temp3 = d[nfb - 1];
            d[nfb - 1] = d[t];
            d[t] = temp3;

            str = bnam[nfb - 1];
            bnam[nfb - 1] = bnam[t];
            bnam[t] = str;
            nfb--;
            cout << "\t\t\t***BOOK RETURN SUCESSFULLY ***" << endl;
            return 1;
        }
        else
        {
            cout << "\n\t\t\t**BOOK DOSEN'T FOUND **" << endl;
            return 0;
        }
    }
    void editstprofile()
    {
        cout << "edit name of student :";
        fflush(stdin);
        getline(cin, sname);
        cout << "edit branch of student :";
        fflush(stdin);
        getline(cin, sbranch);
    }
    friend void bookreturn();
    friend void bookissue();
    friend void editstudent();
    friend void removestudent();
};
class book
{
public:
    string bname, bauthor;
    int bid;

public:
    book()
    {
        bname = " ";
        bauthor = " ";
        bid = 0;
    }
    void getdata()
    {
        cout << "enter the name of book :";
        fflush(stdin);
        getline(cin, bname);
        cout << "enter the id of book :";
        cin >> bid;
        cout << "enter the book author's name :";
        fflush(stdin);
        getline(cin, bauthor);
    }
    void display()
    {
        cout << "BOOK NAME: " << bname << "     ID: " << bid << "    BOOK AUTHOR: " << bauthor << endl;
    }

    void editboprofile()
    {
        cout << "edit name of book :";
        fflush(stdin);
        getline(cin, bname);
        cout << "edit book autho's name :";
        fflush(stdin);
        getline(cin, bauthor);
    }
    friend void bookreturn();
    friend void bookissue();
    friend void editbook();
    friend void removebook();
};
student s[30], stemp;
book b[30], btemp;
int x = 0, v = 0, start = 0;
void bookissue()
{
    int bn, sn, sfound = 0, bfound = 0, sindx, d = 0, y = 0, m = 0, bindx;
    string bnm;
    cout << "\n\n\t\t\t**** BOOK ISSUE...***\n"
         << endl;
    cout << "enter the student's ID no. :";
    cin >> sn;
    for (int i1 = 0; i1 < x; i1++)
    {
        if (sn == s[i1].sid)
        {
            sfound = 1;
            sindx = i1;
            start = s[i1].nfb;
            if (start >= 5)
            {
                sfound = 2;
            }
            s[i1].display();
            break;
        }
    }
    if (sfound == 1)
    {

        cout << "enter the id no of book:";
        cin >> bn;
        for (int i2 = 0; i2 < v; i2++)
        {
            if (bn == b[i2].bid)
            {
                bfound = 1;
                cout << "BOOK FOUND SUCESSFULLY" << endl;
                bindx = i2;
                bnm = b[i2].bname;
                b[i2].display();
                break;
            }
        }
        if (bfound == 1)
        {
            cout << "enter the date of issue (DDMMYYYY): ";
            cin >> d >> m >> y;
            
            start++;
            s[sindx].addbooks(start, bn, bnm, d, m, y);
            cout << "\t\t\t*WARNING\n\n\t\t*BOOK MUST RETURN IN 10 DAYS OTHEWISE PERDAY RS=2 FINE INCREASES*" << endl;
            cout << "\t\t\t*BOOK ISSUE SUCESSFULLY*\n"
                 << endl;
        }
        else
        {
            cout << "\t\t\t*** BOOK IS NOT FOUND **" << endl;
            return;
        }
    }
    else if (sfound == 2)
    {
        cout << "\t\t\t**** STUDENT ISSUED MAXIMUM 5 BOOKS ***" << endl;
        s[sindx].showstbooks();
        return;
    }
    else
    {
        cout << "\t\t\t***STUDENT RECORD NOT FOUND ****" << endl;
        return;
    }
}

void bookreturn()
{
    int sn, bn, sidx, bidx, fnd = 0, end = 0, dr = 0, mr = 0, yr = 0;
    cout << "\n\n\t\t\t**** BOOK RETURN....****\n"
         << endl;
    cout << " enter the student id no : ";
    cin >> sn;
    for (int d1 = 0; d1 < x; d1++)
    {
        if (sn == s[d1].sid)
        {
            fnd = 1;
            sidx = d1;
            if (s[d1].nfb == 0)
            {
                fnd = 2;
            }
            s[d1].display();
            s[d1].showstbooks();
        }
    }
    if (fnd == 1)
    {
        cout << "enter the book id no(return book) :";
        cin >> bn;
        cout << "enter the return date of book(ddmmyyyy) : ";
        cin >> dr >> mr >> yr;
        end = s[sidx].removebooks(bn, dr, mr, yr);
        start = start - end;
        s[sidx].display();
        s[sidx].showstbooks();
    }
    else if (fnd == 2)
    {
        cout << "\n\t\t\t***YOU DON'T HAVE ANY LIBRARY BOOK ***" << endl;
        return;
    }
    else
    {
        cout << "\t\t\t**STUDENT RECORD NOT FOUND **" << endl;
        return;
    }
}

void editstudent()
{
    cout << "\n\n\t\t\t*****STUDENT EDIT PROFILE....*****\n"
         << endl;

    int sn, sidxn, fnid = 0;
    cout << " enter the student id no : ";
    cin >> sn;
    for (int e1 = 0; e1 < x; e1++)
    {
        if (sn == s[e1].sid)
        {
            fnid = 1;
            sidxn = e1;
        }
        if (fnid == 1)
        {
            s[sidxn].editstprofile();
            cout << "\n\t\t\t**STUDENT PROFILE EDIT SUCESSFULLY*" << endl;
            s[sidxn].display();
        }
        else
        {
            cout << "\t\t\t**STUDENT RECORD NOT FOUND **" << endl;
            return;
        }
    }
}
void editbook()
{
    cout << "\n\n\t\t\t**** BOOOK EDIT PROFILE....****\n"
         << endl;

    int bn, bidxn, bfnid = 0;
    cout << " enter the book id no : ";
    cin >> bn;
    for (int e2 = 0; e2 < v; e2++)
    {
        if (bn == b[e2].bid)
        {
            bfnid = 1;
            bidxn = e2;
        }
        if (bfnid == 1)
        {
            b[bidxn].editboprofile();
            cout << "\n\t\t\t** BOOK PROFILE EDIT SUCESSFULLY***" << endl;
            b[bidxn].display();
        }
        else
        {
            cout << "\t\t\t**BOOK RECORD NOT FOUND **" << endl;
            return;
        }
    }
}

void removestudent()
{
    cout << "\n\n\t\t\t*****REMOVE STUDENT...*****\n"
         << endl;

    int sn, sidxn, fnid = 0;
    cout << " enter the student id no : ";
    cin >> sn;
    for (int e1 = 0; e1 < x; e1++)
    {
        if (sn == s[e1].sid)
        {
            fnid = 1;
            sidxn = e1;
            break;
        }
    }
    if (fnid == 1)
    {
        stemp = s[x - 1];
        s[x - 1] = s[sidxn];
        s[sidxn] = stemp;
        cout << "\n\t\t\t** STUDENT PROFILE REMOVE SUCESSFULLY***" << endl;
        s[x - 1].display();
        x--;
    }
    else
    {
        cout << "\t\t\t**STUDENT RECORD NOT FOUND **" << endl;
        return;
    }
}
void removebook()
{
    cout << "\n\n\t\t\t*****REMOVE BOOK...*****\n"
         << endl;

    int bn, bidxn, fnid = 0;
    cout << " enter the book id no : ";
    cin >> bn;
    for (int e1 = 0; e1 < v; e1++)
    {
        if (bn == b[e1].bid)
        {
            fnid = 1;
            bidxn = e1;
            break;
        }
    }
    if (fnid == 1)
    {
        btemp = b[v - 1];
        b[v - 1] = b[bidxn];
        b[bidxn] = btemp;
        cout << "\n\t\t\t**BOOK REMOVE SUCESSFULLY*" << endl;
        b[v - 1].display();
        v--;
    }
    else
    {
        cout << "\t\t\t**BOOK RECORD NOT FOUND **" << endl;
        return;
    }
}

int main()
{

    int cha = 0, chs = 0, ch = 0, pass, cpass;
    b[0].bname = "2 STATES";
    b[0].bauthor = "CHETAN BHAGAT";
    b[0].bid = 100;
    b[1].bname = "ONE INDIAN GIRL";
    b[1].bauthor = "CHETAN BHAGAT";
    b[1].bid = 101;
    b[2].bname = "HALF GIRLFRIEND";
    b[2].bauthor = "CHETAN BHAGAT";
    b[2].bid = 102;
    b[3].bname = "THE GIRL IN ROOM 105";
    b[3].bauthor = "CHETAN BHAGAT";
    b[3].bid = 103;
    b[4].bname = "3 MISTAKE OF MY LIFE";
    b[4].bauthor = "CHETAN BHAGAT";
    b[4].bid = 104;
    b[5].bname = " WILL YOU STILL LOVE ME";
    b[5].bauthor = "RAVINDRA SINGH";
    b[5].bid = 105;
    b[6].bname = "THE GIRL IN ROOM 105";
    b[6].bauthor = "CHETAN BHAGAT";
    b[6].bid = 106;
    b[7].bname = "ONE ARRANGED MURDER";
    b[7].bauthor = "CHETAN BHAGAT";
    b[7].bid = 107;

    v = 8;

    cout << " \n\n\t\t\t***** WELCOME TO THE LIBRARY ****\n\n"
         << endl;

    cout << " MAKE ADMISTRATIVE PASSWORD :";
    cin >> pass;
    system("cls");
AD:
    cout << " \n\n\t\t\t***** WELCOME TO THE LIBRARY ****\n\n"
         << endl;
    cout << "\n\n\t\t\t1.ADMISTRATIVE LOGIN\t2.USER\n\t\t\tenter choice:";
    cin >> ch;
    if (ch == 1)
    {
        cout << "Enter admistrative password for login :";
        cin >> cpass;
        if (cpass == pass)
        {
            system("cls");
            cout << " \n\n\t\t\t***** WELCOME TO THE LIBRARY ****\n"
                 << endl;

        A:
            cout << "\t\t\t\t******ADMISTRATIVE SERVICES *****\n\n"
                 << endl;
            cout << " \t\t\t1.REGISTER NEW STUDENT  \t2.REGISTER NEW BOOK\n\t\t\t3.SHOW STUDENT DETAIL \t\t4.SHOW BOOKS\n";
            cout << " \t\t\t5.BOOK ISSUE  \t\t\t6.BOOK RETURN\n\t\t\t7.EDIT STUDENT PROFILE  \t8.EDIT BOOK  \n"
                 << endl;
            cout << " \t\t\t9.REMOVE STUDENT   \t\t10.REMOVE BOOK\n\t\t\t11.EXIT" << endl;

        B:
            cout << "\t\t\tENTER THE CHOICE NO. : ";
            cin >> cha;
            switch (cha)
            {
            case 1:
                for (int j1 = x; j1 < 30; j1++)
                {
                    s[j1].getdata();
                    x++;
                    break;
                }
                break;
            case 2:
                for (int j2 = v; j2 < 30; j2++)
                {
                    b[j2].getdata();
                    v++;
                    break;
                }
                break;
            case 3:
                for (int j3 = 0; j3 < x; j3++)
                {
                    s[j3].display();
                    s[j3].showstbooks();
                }
                break;
            case 4:
                for (int j4 = 0; j4 < v; j4++)
                {
                    b[j4].display();
                }
                break;
            case 5:
                bookissue();
                break;
            case 6:
                bookreturn();
                break;
            case 7:
                editstudent();
                break;
            case 8:
                editbook();
                break;
            case 9:
                removestudent();
                break;
            case 10:
                removebook();
                break;
            case 11:
                goto C;
                break;
            default:
                cout << "\t\t\t***INVALID CHOICES ENTER AGAIN ***" << endl;
                goto B;
                break;
            }
            goto A;
        }
        else
        {
            cout << " \t\t\t*WRONG PASSWORD*" << endl;
            goto AD;
        }
    }
    else
    {
    U:
        cout << "\t\t\t\t***** STUDENT SERVICES ****\n\n"
             << endl;
        cout << " \t\t\t1.REGISTER NEW STUDENT  \t2.ADMISTRATIVE SERVICES \n\t\t\t3.SHOW BOOKS  \t\t\t4.BOOK ISSUE" << endl;
        cout << "\n\t\t\t5.BOOK RETURN  \t\t\t6.EDIT STUDENT PROFILE\n\t\t\t7.EXIT" << endl;
    BS:
        cout << "\t\t\tENTER THE CHOICE : ";
        cin >> chs;
        switch (chs)
        {
        case 1:
            for (int j1 = x; j1 < 30; j1++)
            {
                s[j1].getdata();
                x++;
                break;
            }

            break;
        case 2:
            goto AD;
            break;
        case 3:
            for (int j4 = 0; j4 < v; j4++)
            {
                b[j4].display();
            }
            break;
        case 4:
            bookissue();
            break;
        case 5:
            bookreturn();
            break;
        case 6:
            editstudent();
            break;
        case 7:
            goto C;
            break;
        default:
            cout << "\t\t\t***INVALID CHOICES ENTER AGAIN ***" << endl;
            goto BS;
            break;
        }
        goto U;
    }
C:
    cout << " \n\n\t\t\t***** THANK YOU *****" << endl;
    return 0;
}