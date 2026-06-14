#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Contact {
    string name, phone, email;
};

int main() {
    int choice;
    Contact c;
    string searchName;
    bool found;

    do {
        cout << "\n===== CONTACT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Contact";
        cout << "\n2. View Contacts";
        cout << "\n3. Search Contact";
        cout << "\n4. Delete All Contacts";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
        case 1: {
            ofstream file("contacts.txt", ios::app);

            cout << "Enter Name: ";
            getline(cin, c.name);

            cout << "Enter Phone: ";
            getline(cin, c.phone);

            cout << "Enter Email: ";
            getline(cin, c.email);

            file << c.name << endl;
            file << c.phone << endl;
            file << c.email << endl;

            file.close();
            cout << "Contact Added Successfully!\n";
            break;
        }

        case 2: {
            ifstream file("contacts.txt");

            cout << "\n--- Contact List ---\n";

            while(getline(file, c.name)) {
                getline(file, c.phone);
                getline(file, c.email);

                cout << "Name : " << c.name << endl;
                cout << "Phone: " << c.phone << endl;
                cout << "Email: " << c.email << endl;
                cout << "---------------------\n";
            }

            file.close();
            break;
        }

        case 3: {
            ifstream file("contacts.txt");
            found = false;

            cout << "Enter Name to Search: ";
            getline(cin, searchName);

            while(getline(file, c.name)) {
                getline(file, c.phone);
                getline(file, c.email);

                if(c.name == searchName) {
                    cout << "\nContact Found\n";
                    cout << "Name : " << c.name << endl;
                    cout << "Phone: " << c.phone << endl;
                    cout << "Email: " << c.email << endl;
                    found = true;
                }
            }

            if(!found)
                cout << "Contact Not Found!\n";

            file.close();
            break;
        }

        case 4:
            remove("contacts.txt");
            cout << "All Contacts Deleted!\n";
            break;

        case 5:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}