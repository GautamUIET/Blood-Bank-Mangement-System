#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

void date_printer()
{
    time_t now = time(0);

    char *nowt = ctime(&now);
    cout << "today's date and time :" << nowt << endl;

    struct tm local = *localtime(&now);
    if (local.tm_mon + 1 + 3 > 12)
    {
        cout << "you can donate blood at or after : " << local.tm_mday << " " << (local.tm_mon + 1 + 3) - 12 << " " << local.tm_year + 1900 + 1 << " " << endl;
    }
    else if (local.tm_mon + 1 + 3 <= 12)
    {
        cout << "\t\t\tyou can donate blood at or after : " << local.tm_mday << "-" << local.tm_mon + 1 + 3 << "-" << local.tm_year + 1900 << "" << endl;
    }
};

void bbprinter()
{
    cout << "\t\t\t\t\033[34m\033[1m@@@   @      @@@@@  @@@@@  @@@@        @@@@  @@@@@  @@    @  @  @\033[0m\033[0m\n";
    cout << "\t\t\t\t\033[34m\033[1m@  @  @      @   @  @   @  @   @       @  @  @   @  @@@   @  @ @\033[0m\033[0m\n";
    cout << "\t\t\t\t\033[34m\033[1m@  @  @      @   @  @   @  @   @       @  @  @   @  @ @@  @  @ @\033[0m\033[0m\n";
    cout << "\t\t\t\t\033[34m\033[1m@@@   @      @   @  @   @  @   @       @@@   @@@@@  @  @  @  @@\033[0m\033[0m\n";
    cout << "\t\t\t\t\033[34m\033[1m@  @  @      @   @  @   @  @   @       @  @  @   @  @  @@ @  @ @\033[0m\033[0m\n";
    cout << "\t\t\t\t\033[34m\033[1m@  @  @      @   @  @   @  @   @       @  @  @   @  @   @@@  @  @\033[0m\033[0m\n";
    cout << "\t\t\t\t\033[34m\033[1m@@@   @@@@@  @@@@@  @@@@@  @@@@        @@@   @   @  @    @@  @   @\033[0m\033[0m\n";
};

class donor
{
public:
    string donor_name;
    string donor_id;
    string blood_group;
    string history;
    string age;
    string wgt;

    donor() {}
    ~donor() {};
};

class tblood
{
public:
    int a_pos;
    int b_pos;
    int o_pos;
    int ab_pos;
    int a_neg;
    int b_neg;
    int o_neg;
    int ab_neg;

    void getdata();
    void save_data();
    void load_data();
    void new_tester(string ninja, tblood qwe);
    friend void data_refresher(tblood &xyx);
    void blood_amount();
    void printdata();
};

void tblood::printdata()
{
    cout << "a pos :" << a_pos << endl;
    cout << "a neg :" << a_neg << endl;
    cout << "b pos:" << b_pos << endl;
    cout << "b neg:" << b_neg << endl;
    cout << "ab pos:" << ab_pos << endl;
    cout << "ab neg:" << ab_neg << endl;
    cout << "o pos:" << o_pos << endl;
    cout << "o neg :" << o_neg << endl;
}

void tblood::getdata()
{
    a_pos = 0;
    b_pos = 0;
    o_pos = 0;
    ab_pos = 0;
    a_neg = 0;
    b_neg = 0;
    o_neg = 0;
    ab_neg = 0;
};

void tblood::save_data()
{
    ofstream outfile("blood_data.txt");
    outfile << a_pos << endl;
    outfile << a_neg << endl;
    outfile << b_pos << endl;
    outfile << b_neg << endl;
    outfile << ab_pos << endl;
    outfile << ab_neg << endl;
    outfile << o_pos << endl;
    outfile << o_neg << endl;
    outfile.close();
}

void tblood::load_data()
{
    ifstream infile("blood_data.txt");
    if (infile.good())
    {
        infile >> a_pos;
        infile >> a_neg;
        infile >> b_pos;
        infile >> b_neg;
        infile >> ab_pos;
        infile >> ab_neg;
        infile >> o_pos;
        infile >> o_neg;
        infile.close();
    }
    else
    {
        // If file doesn't exist, initialize with data from donor list
        data_refresher(*this);
        save_data();
    }
}

void data_refresher(tblood &xyx)
{
    xyx.getdata();
    ifstream opner;
    opner.open("donorlist.txt", ios::in);

    string str280;
    while (getline(opner, str280))
    {
        if (str280 == "a+")
        {
            (xyx.a_pos)++;
        }
        else if (str280 == "a-")
        {
            xyx.a_neg++;
        }
        else if (str280 == "b+")
        {
            xyx.b_pos++;
        }
        else if (str280 == "b-")
        {
            xyx.b_neg++;
        }
        else if (str280 == "ab+")
        {
            xyx.ab_pos++;
        }
        else if (str280 == "ab-")
        {
            xyx.ab_neg++;
        }
        else if (str280 == "o-")
        {
            xyx.o_neg++;
        }
        else if (str280 == "o+")
        {
            xyx.o_pos++;
        }
    };
    opner.close();
};

void h_printer() {};

void certificate()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t\tCERTIFICATE OF APPRECIATION\n\n\n";
    cout << "#1 We appreciate your donation! Your contribution will help us change lives \nliterally! Someone who would have lost their life was spared because you gave us your blood. \nSomeone's quality of life was improved because you gave us your blood.\n\n";
};

void option1()
{
    donor add_donor;
    cout << "enter name of donor" << endl;
    cin >> add_donor.donor_name;
    cout << "enter id of donor" << endl;
    cin >> add_donor.donor_id;
    cout << "enter blood group of donor" << endl;
    cin >> add_donor.blood_group;

    cout << "enter history of donor" << endl;
    cin >> add_donor.history;
    cout << "enter age of donor" << endl;
    cin >> add_donor.age;
    cout << "enter weight of donor" << endl;
    cin >> add_donor.wgt;

    ofstream indata;
    indata.open("donorlist.txt", ios::app);
    indata << add_donor.donor_id << endl;
    indata << add_donor.donor_name << endl;
    indata << add_donor.blood_group << endl;
    indata << add_donor.history << endl;
    indata << add_donor.age << endl;
    indata << add_donor.wgt << endl;
    indata.close();
};

void option2(string dummy)
{
    ifstream outdata;
    outdata.open("donorlist.txt", ios::in);
    string cmpr;
    bool found = false;

    while (getline(outdata, cmpr))
    {
        if (cmpr == dummy)
        {
            found = true;
            cout << "details of donor with id  " << cmpr << " are ::\n";
            getline(outdata, cmpr);
            cout << "name:" << cmpr << endl;
            getline(outdata, cmpr);
            cout << "blood group:" << cmpr << endl;
            getline(outdata, cmpr);
            cout << "history:" << cmpr << endl;
            getline(outdata, cmpr);
            cout << "age:" << cmpr << endl;
            getline(outdata, cmpr);
            cout << "weight:" << cmpr << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Donor with ID " << dummy << " not found." << endl;
    }

    outdata.close();
};

void option3() {};

void loginpage()
{
    ifstream outdata;
    string name;
    cout << "enter username :" << endl;
    cin >> name;
    outdata.open("login_page2.txt", ios::in);
    if (!outdata)
    {
        cout << "Error opening login file!" << endl;
        exit(0);
    }

    string compare;
    bool userFound = false;
    while (getline(outdata, compare))
    {
        if (compare == name)
        {
            userFound = true;
            cout << "username::" << name << endl;
            string passw;
            cout << "enter password :" << endl;
            cin >> passw;
            if (getline(outdata, compare) && compare == passw)
            {
                cout << "access granted" << endl;
                break;
            }
            else
            {
                cout << "access denied" << endl;
                exit(0);
            }
        }
    }

    if (!userFound)
    {
        cout << "User not found!" << endl;
        exit(0);
    }
    outdata.close();
};

vector<donor> read_donors_from_file()
{
    vector<donor> donors;
    ifstream details;
    details.open("donorlist.txt", ios::in);

    string line;
    donor current_donor;
    int line_count = 0;

    while (getline(details, line))
    {
        if (line.empty())
            continue;

        switch (line_count % 6)
        {
        case 0:
            current_donor.donor_id = line;
            break;
        case 1:
            current_donor.donor_name = line;
            break;
        case 2:
            current_donor.blood_group = line;
            break;
        case 3:
            current_donor.history = line;
            break;
        case 4:
            current_donor.age = line;
            break;
        case 5:
            current_donor.wgt = line;
            donors.push_back(current_donor);
            break;
        }
        line_count++;
    }

    // Handle case where file doesn't end with complete record
    if (line_count % 6 != 0 && line_count >= 5)
    {
        donors.push_back(current_donor);
    }

    details.close();
    return donors;
}

void table_printer()
{
    vector<donor> donors = read_donors_from_file();

    cout << setw(15) << "ID" << setw(15) << "Name" << setw(15) << "Blood Group"
         << setw(15) << "History" << setw(15) << "Age" << setw(15) << "Weight" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    for (const auto &d : donors)
    {
        cout << setw(15) << d.donor_id << setw(15) << d.donor_name
             << setw(15) << d.blood_group << setw(15) << d.history
             << setw(15) << d.age << setw(15) << d.wgt << endl;
    }
};

void modifier()
{
    string enter;
    cout << "enter the id of donor to be modified:\n";
    cin >> enter;

    vector<donor> donors = read_donors_from_file();
    bool found = false;
    int index = -1;

    for (int i = 0; i < donors.size(); i++)
    {
        if (donors[i].donor_id == enter)
        {
            found = true;
            index = i;
            break;
        }
    }

    if (!found)
    {
        cout << "Donor with ID " << enter << " not found." << endl;
        return;
    }

    cout << "Current details for donor " << enter << ":" << endl;
    cout << "Name: " << donors[index].donor_name << endl;
    cout << "Blood Group: " << donors[index].blood_group << endl;
    cout << "History: " << donors[index].history << endl;
    cout << "Age: " << donors[index].age << endl;
    cout << "Weight: " << donors[index].wgt << endl;

    cout << "Enter new name (or press enter to keep current): ";
    cin.ignore();
    string newName;
    getline(cin, newName);
    if (!newName.empty())
        donors[index].donor_name = newName;

    cout << "Enter new blood group (or press enter to keep current): ";
    string newBG;
    getline(cin, newBG);
    if (!newBG.empty())
        donors[index].blood_group = newBG;

    cout << "Enter new history (or press enter to keep current): ";
    string newHistory;
    getline(cin, newHistory);
    if (!newHistory.empty())
        donors[index].history = newHistory;

    cout << "Enter new age (or press enter to keep current): ";
    string newAge;
    getline(cin, newAge);
    if (!newAge.empty())
        donors[index].age = newAge;

    cout << "Enter new weight (or press enter to keep current): ";
    string newWeight;
    getline(cin, newWeight);
    if (!newWeight.empty())
        donors[index].wgt = newWeight;

    // Write all donors back to file
    ofstream outfile("donorlist.txt");
    for (const auto &d : donors)
    {
        outfile << d.donor_id << endl;
        outfile << d.donor_name << endl;
        outfile << d.blood_group << endl;
        outfile << d.history << endl;
        outfile << d.age << endl;
        outfile << d.wgt << endl;
    }
    outfile.close();

    cout << "Donor record updated successfully." << endl;
};

void ddeleter()
{
    string enter;
    cout << "enter the id of donor to be deleted:\n";
    cin >> enter;

    vector<donor> donors = read_donors_from_file();
    bool found = false;

    for (int i = 0; i < donors.size(); i++)
    {
        if (donors[i].donor_id == enter)
        {
            found = true;
            donors.erase(donors.begin() + i);
            break;
        }
    }

    if (!found)
    {
        cout << "Donor with ID " << enter << " not found." << endl;
        return;
    }

    // Write remaining donors back to file
    ofstream outfile("donorlist.txt");
    for (const auto &d : donors)
    {
        outfile << d.donor_id << endl;
        outfile << d.donor_name << endl;
        outfile << d.blood_group << endl;
        outfile << d.history << endl;
        outfile << d.age << endl;
        outfile << d.wgt << endl;
    }
    outfile.close();

    cout << "Donor record deleted successfully." << endl;
};

int main()
{
    tblood blood_database;
    blood_database.load_data(); // Load blood data at startup

    int option;
    bbprinter();

    cout << "\n\n\n\t\t\t\t" << endl;
    cout << "\t\t\t\t\033[4mLOGIN\033[0m\n";
    loginpage();
    h_printer();
    cout << "\n\n\n\n\n\t\t\t\t\t\t \033[4m enter 0 to next \033[0m\n";
    int next;
    cin >> next;
    if (next == 0)
    {
        system("cls");
    };

    while (1)
    {
        cout << "\t\t\tSELECT AN OPERATION TO PERFORM::" << endl;
        cout << "\n\n\n\n\t\t\t\t\toptions\n\t\t1.new donor\n\t\t2.search old donor\n\t\t5.buy blood\n\t\t6.exit\n\t\t7.refresh database\n\t\t8.print table\n\t\t9.modify data\n\t\t10.delete donor" << endl;
        cin >> option;
        system("cls");

        switch (option)
        {
        case 1:
        {
            option1();
            certificate();
            cout << "\n\n\n\t\t\t\t";
            date_printer();
            // Update blood database after adding a donor
            data_refresher(blood_database);
            blood_database.save_data();
        };
        break;
        case 2:
        {
            cout << "enter the id of donor to be searched\n ";
            string donor_id;
            cin >> donor_id;
            option2(donor_id);
        }
        break;
        case 5:
        {
            string req_blood;
            cout << "Enter the blood group you want to buy: ";
            cin >> req_blood;

            bool success = false;

            if (req_blood == "a+" && blood_database.a_pos > 0)
            {
                blood_database.a_pos--;
                success = true;
            }
            else if (req_blood == "a-" && blood_database.a_neg > 0)
            {
                blood_database.a_neg--;
                success = true;
            }
            else if (req_blood == "b+" && blood_database.b_pos > 0)
            {
                blood_database.b_pos--;
                success = true;
            }
            else if (req_blood == "b-" && blood_database.b_neg > 0)
            {
                blood_database.b_neg--;
                success = true;
            }
            else if (req_blood == "ab+" && blood_database.ab_pos > 0)
            {
                blood_database.ab_pos--;
                success = true;
            }
            else if (req_blood == "ab-" && blood_database.ab_neg > 0)
            {
                blood_database.ab_neg--;
                success = true;
            }
            else if (req_blood == "o+" && blood_database.o_pos > 0)
            {
                blood_database.o_pos--;
                success = true;
            }
            else if (req_blood == "o-" && blood_database.o_neg > 0)
            {
                blood_database.o_neg--;
                success = true;
            }

            if (success)
            {
                cout << "Blood " << req_blood << " provided successfully.\n";
                blood_database.save_data(); // Save updated blood data
            }
            else
            {
                cout << "Sorry, requested blood group not available in stock.\n";
            }

            cout << "\nUpdated stock:\n";
            blood_database.printdata();
        }
        break;
        case 6:
            blood_database.save_data(); // Save data before exiting
            exit(0);
        case 7:
        {
            data_refresher(blood_database);
            blood_database.save_data();
            blood_database.printdata();
        }
        break;
        case 8:
        {
            table_printer();
        }
        break;
        case 9:
        {
            modifier();
            // Update blood database after modification
            data_refresher(blood_database);
            blood_database.save_data();
        }
        break;
        case 10:
        {
            ddeleter();
            // Update blood database after deletion
            data_refresher(blood_database);
            blood_database.save_data();
        }
        break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        system("cls");
    }
    return 0;
}