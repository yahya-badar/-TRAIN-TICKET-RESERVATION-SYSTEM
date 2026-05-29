#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<cstdio>
using namespace std;

struct pd
{
    char name[50];
    int train_num;
    int num_of_seats;
    int bogie_num;
    int seat_num;
};

void reservation(void);
void viewdetails(void);
void cancel(void);
void printticket(char name[], int num_of_seats, int train_num, int bogie_num, int seat_num, float charges);
void specifictrain(int);
float charge(int, int);
bool login();
void showAllTickets();
void generateRandomBogieAndSeat(int& bogie_num, int& seat_num);

int main()
{
    system("cls");
    cout << "\t\t=================================================\n";
    cout << "\t\t|                                               |\n";
    cout << "\t\t|        -----------------------------          |\n";
    cout << "\t\t|            TRAIN TICKET SYSTEM                |\n";
    cout << "\t\t|        -----------------------------          |\n";
    cout << "\t\t|                                               |\n";
    cout << "\t\t|                                               |\n";
    cout << "\t\t|                                               |\n";
    cout << "\t\t|                                               |\n";
    cout << "\t\t=================================================\n\n\n";

    cout << " \n Press any key to continue:";
    getch();

    system("cls");
    if (login())
    {
        int menu_choice, choice_return;
    start:
        system("cls");
        cout << "\n=================================\n";
        cout << "        TRAIN TICKET SYSTEM";
        cout << "\n=================================";
        cout << "\n1>> Reserve A Ticket";
        cout << "\n------------------------";
        cout << "\n2>> View All Available Trains";
        cout << "\n------------------------";
        cout << "\n3>> Cancel Reservation";
        cout << "\n------------------------";
        cout << "\n4>> View All Confirmed Tickets";
        cout << "\n------------------------";
        cout << "\n5>> Exit";
        cout << "\n------------------------";
        cout << "\n\n-->";

        cin >> menu_choice;
        switch (menu_choice)
        {
        case 1:
            reservation();
            break;
        case 2:
            viewdetails();
            cout << "\n\nPress any key to go to Main Menu..";
            getch();
            break;
        case 3:
            cancel();
            break;
        case 4:
            showAllTickets();
            break;
        case 5:
            remove("D:\\seats_reserved.txt");
            return 0;
        default:
            cout << "\nInvalid choice";
        }
        goto start;
    }
    else
    {
        cout << " Exiting the program.\n";
    }

    return 0;
}

bool login()
{
    string username, password;
    cout << "\n  =======================  LOGIN FORM  =======================\n  ";
    cout << " \n                       ENTER USERNAME:-";
    cin >> username;
    cout << " \n                       ENTER PASSWORD:-";
    cin >> password;

    if (username == "Taha" && password == "Ibrahim") 
    {
        cout << "  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL";
        cout << "\n\n\n\t\t\t\tPress any key to continue...";
        getch();
        return true;
    }
    else 
    {
        cout << "\n        SORRY !!!!  LOGIN IS UNSUCESSFUL";
        getch();
        return false;
    }
}

void reservation(void)
{
    char confirm;
    int i = 0;
    float charges;
    pd passdetails;
    FILE *fp;
    fp = fopen("D:\\seats_reserved.txt", "a");
    system("cls");

    cout << "\nEnter Your Name:> ";
    cin.ignore();
    cin.getline(passdetails.name, 50);

    cout << "\nEnter Number of seats:> ";
    cin >> passdetails.num_of_seats;
    cout << "\n\n>>Press Enter To View Available Trains<< ";
    getch();
    system("cls");
    viewdetails();
    cout << "\n\nEnter train number:> ";
    start1:
    cin >> passdetails.train_num;
    if (passdetails.train_num >= 1001 && passdetails.train_num <= 1010)
    {
        charges = charge(passdetails.train_num, passdetails.num_of_seats);
        generateRandomBogieAndSeat(passdetails.bogie_num, passdetails.seat_num);

        cout << "\nRandomly Assigned Bogie Number: " << passdetails.bogie_num;
        cout << "\nRandomly Assigned Seat Number: " << passdetails.seat_num;

        printticket(passdetails.name, passdetails.num_of_seats, passdetails.train_num, passdetails.bogie_num, passdetails.seat_num, charges);
    }
    else
    {
        cout << "\nInvalid train Number! Enter again--> ";
        goto start1;
    }

    cout << "\n\nConfirm Ticket (y/n):>";
    start:
    cin >> confirm;
    if (confirm == 'y')
    {
        fprintf(fp, "%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f\n", passdetails.name, passdetails.num_of_seats, passdetails.train_num, passdetails.bogie_num, passdetails.seat_num, charges);
        cout << "==================";
        cout << "\n Reservation Done\n";
        cout << "==================";
        cout << "\nPress any key to go back to Main menu";
        getch();
    }
    else
    {
        if (confirm == 'n') 
        {
            cout << "\nReservation Not Done!\nPress any key to go back to Main menu!";
            getch();
        }
        else
        {
            cout << "\nInvalid choice entered! Enter again-----> ";
            goto start;
        }
    }
    fclose(fp);
}

void viewdetails(void)
{
    system("cls");
    cout << "------------------------------------------------------------------------------------------";
    cout << "\nTr.No\tName\t\t\tDestinations\t\t\tCharges\t\tTime\n";
    cout << "-----------------------------------------------------------------------------";
    cout << "\n1001\tBlue Lines Express\tKarachi to Lahore\t\t5000\t\t9am";
    cout << "\n1002\tBlue Lines Express\tLahore To Karachi\t\t5000\t\t12pm";
    cout << "\n1003\tCity Express\t\tLahore To Islamabad\t\t4500\t\t8am";
    cout << "\n1004\tCity Express\t\tIslamabad To Lahore\t\t4500\t\t11am";
    cout << "\n1005\tPeshawar Express\tPeshawar To Lahore\t\t4000\t\t7am";
    cout << "\n1006\tPeshawar Express\tLahore To Peshawar\t\t4000\t\t9.30am";
    cout << "\n1007\tLala Musa Express\tLala Musa To Sargodha\t\t3500\t\t1pm";
    cout << "\n1008\tLala Musa Express\tSargodha To Lala Musa\t\t3500\t\t4pm";
    cout << "\n1009\tMeteor Express\t\tPeshawar To Karachi\t\t6000\t\t3.35pm";
    cout << "\n1010\tMeteor Express\t\tKarachi To Peshawar\t\t6000\t\t4.15pm";
}

void cancel(void)
{
    system("cls");
    int trainnum;
    cout << "-----------------------\n";
    cout << "Enter the train number: \n";
    cout << "-----------------------\n";
    cin.ignore();
    cin >> trainnum;
    cout << "\n\nCancelled";
    getch();
}

void showAllTickets()
{
    system("cls");
    cout << "-----------------------------------\n";
    cout << "Confirmed Reservations:\n";
    cout << "-----------------------------------\n";

    ifstream file("D:\\seats_reserved.txt");

    if (file.is_open()) 
    {
        string line;
        while (getline(file, line)) 
        {
            cout << line << endl;
        }
        file.close();
    } 
    else 
    {
        cout << "No confirmed reservations found." << endl;
    }
    cout << "\nPress any key to go back to Main menu";
    getch();
}

float charge(int train_num, int num_of_seats)
{
    if (train_num == 1001)
    {
        return (5000.0 * num_of_seats);
    }
    if (train_num == 1002)
    {
        return (5000.0 * num_of_seats);
    }
    if (train_num == 1003)
    {
        return (4500.0 * num_of_seats);
    }
    if (train_num == 1004)
    {
        return (4500.0 * num_of_seats);
    }
    if (train_num == 1005)
    {
        return (4000.0 * num_of_seats);
    }
    if (train_num == 1006)
    {
        return (4000.0 * num_of_seats);
    }
    if (train_num == 1007)
    {
        return (3500.0 * num_of_seats);
    }
    if (train_num == 1008)
    {
        return (3500.0 * num_of_seats);
    }
    if (train_num == 1009)
    {
        return (6000.0 * num_of_seats);
    }
    if (train_num == 1010)
    {
        return (6000.0 * num_of_seats);
    }
}

void generateRandomBogieAndSeat(int& bogie_num, int& seat_num)
{
    srand(time(0));
    bogie_num = rand() % 15 + 1;
    seat_num = rand() % 50 + 1;
}

void printticket(char name[], int num_of_seats, int train_num, int bogie_num, int seat_num, float charges)
{
    system("cls");
    cout << "-------------------\n";
    cout << "\tTICKET\n";
    cout << "-------------------\n\n";
    cout << "Name:\t\t\t" << name;
    cout << "\nNumber Of Seats:\t" << num_of_seats;
    cout << "\nTrain Number:\t\t" << train_num;
    specifictrain(train_num);
    cout << "\nBogie Number:\t\t" << bogie_num;
    cout << "\nSeat Number:\t\t" << seat_num;
    cout << "\nCharges:\t\t" << charges;
}

void specifictrain(int train_num)
{
    if (train_num == 1001)
    {
        cout << "\nTrain:\t\t\tBlue Lines Express";
        cout << "\nDestination:\t\tKarachi to Lahore";
        cout << "\nDeparture:\t\t9am ";
    }
    if (train_num == 1002)
    {
        cout << "\nTrain:\t\t\tBlue Lines Express";
        cout << "\nDestination:\t\tLahore To Karachi";
        cout << "\nDeparture:\t\t12pm";
    }
    if (train_num == 1003)
    {
        cout << "\nTrain:\t\t\tCity Express";
        cout << "\nDestination:\t\tLahore To Islamabad";
        cout << "\nDeparture:\t\t8am";
    }
    if (train_num == 1004)
    {
        cout << "\nTrain:\t\t\tCity Express";
        cout << "\nDestination:\t\tIslamabad To Lahore";
        cout << "\nDeparture:\t\t11am ";
    }
    if (train_num == 1005)
    {
        cout << "\nTrain:\t\t\tPeshawar Express";
        cout << "\nDestination:\t\tPeshawar To Lahore";
        cout << "\nDeparture:\t\t7am";
    }
    if (train_num == 1006)
    {
        cout << "\ntrain:\t\t\tPeshawar Express";
        cout << "\nDestination:\t\tLahore To Peshawar ";
        cout << "\nDeparture:\t\t9.30am ";
    }
    if (train_num == 1007)
    {
        cout << "\ntrain:\t\t\tLala Musa Express";
        cout << "\nDestination:\t\tLala Musa To Sargodha";
        cout << "\nDeparture:\t\t1pm ";
    }
    if (train_num == 1008)
    {
        cout << "\ntrain:\t\t\tLala Musa Express";
        cout << "\n Destination:\t\tSargodha To Lala Musa";
        cout << "\nDeparture:\t\t4pm ";
    }
    if (train_num == 1009)
    {
        cout << "\ntrain:\t\t\tMeteor Express";
        cout << "\nDestination:\t\tPeshawar To Karachi";
        cout << "\nDeparture:\t\t3.35pm ";
    }
    if (train_num == 1010)
    {
        cout << "\ntrain:\t\t\tMeteor Express";
        cout << "\nDestination:\t\tKarachi To Peshawar";
        cout << "\nDeparture:\t\t1.15 ";
    }
}


