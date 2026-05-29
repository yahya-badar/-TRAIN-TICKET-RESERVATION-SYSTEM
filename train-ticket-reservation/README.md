# 🚂 Train Ticket Reservation System

> A console-based C++ application for train ticket reservation, cancellation, fare calculation, and passenger management — built using file handling, structs, and modular functions.

![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows-0078D4?style=for-the-badge&logo=windows&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

---

## 📋 About The Project

**Train Ticket Reservation System** is a C++ console application that simulates a real railway ticketing system. It allows authenticated users to browse available trains, reserve seats with automatic bogie and seat assignment, view confirmed bookings, and cancel reservations — all with persistent file-based storage.

Built as a semester project for **Programming Fundamentals / Object-Oriented Programming**.

---

## ✨ Features

| Feature | Description |
|---|---|
| 🔐 User Login | Credential-based authentication before system access |
| 🚆 View Trains | Lists all 10 available trains with routes, fares, and departure times |
| 🎫 Reserve Ticket | Books seats with automatic random bogie (1–15) and seat (1–50) assignment |
| 🧾 Print Ticket | Displays formatted ticket with all passenger and journey details |
| ❌ Cancel Reservation | Cancels a booking by train number |
| 📋 View All Tickets | Reads and displays all confirmed reservations from file |
| 💰 Fare Calculation | Computes total fare based on train route and number of seats |

---

## 🚆 Available Trains

| Train No | Train Name | Route | Fare/Seat | Departure |
|---|---|---|---|---|
| 1001 | Blue Lines Express | Karachi → Lahore | Rs. 5,000 | 9:00 AM |
| 1002 | Blue Lines Express | Lahore → Karachi | Rs. 5,000 | 12:00 PM |
| 1003 | City Express | Lahore → Islamabad | Rs. 4,500 | 8:00 AM |
| 1004 | City Express | Islamabad → Lahore | Rs. 4,500 | 11:00 AM |
| 1005 | Peshawar Express | Peshawar → Lahore | Rs. 4,000 | 7:00 AM |
| 1006 | Peshawar Express | Lahore → Peshawar | Rs. 4,000 | 9:30 AM |
| 1007 | Lala Musa Express | Lala Musa → Sargodha | Rs. 3,500 | 1:00 PM |
| 1008 | Lala Musa Express | Sargodha → Lala Musa | Rs. 3,500 | 4:00 PM |
| 1009 | Meteor Express | Peshawar → Karachi | Rs. 6,000 | 3:35 PM |
| 1010 | Meteor Express | Karachi → Peshawar | Rs. 6,000 | 4:15 PM |

---

## 🏗️ Code Structure

```
train-ticket-reservation/
│
├── main.cpp                  ← Complete application (single-file)
│   │
│   ├── struct pd             ← Passenger details (name, train, seats, bogie, seat)
│   ├── main()                ← Entry point — splash screen + menu loop
│   ├── login()               ← Credential authentication
│   ├── viewdetails()         ← Displays all available trains
│   ├── reservation()         ← Ticket booking with file write
│   ├── cancel()              ← Cancels reservation by train number
│   ├── showAllTickets()      ← Reads and displays seats_reserved.txt
│   ├── printticket()         ← Formats and prints ticket to console
│   ├── specifictrain()       ← Prints train-specific details on ticket
│   ├── charge()              ← Calculates total fare
│   └── generateRandomBogieAndSeat() ← Random seat allocation
│
└── README.md
```

---

## ⚙️ How to Compile & Run

### Requirements
- Windows OS (uses `<conio.h>` and `system("cls")`)
- Any C++ compiler: **MinGW (g++)**, **MSVC**, or **Code::Blocks**

### Using g++ (MinGW / Command Prompt)
```bash
g++ main.cpp -o train_system.exe
train_system.exe
```

### Using Code::Blocks
1. Open Code::Blocks → New Project → Console Application → C++
2. Replace the auto-generated `main.cpp` with this project's `main.cpp`
3. Press **F9** to Build and Run

---

## 🔐 Login Credentials

> For demo/testing purposes only.

| Username | Password |
|---|---|
| `Taha` | `Ibrahim` |

---

## 📂 File Storage

Confirmed reservations are saved to `seats_reserved.txt` in the following format:

```
PassengerName    NumSeats    TrainNo    BogieNo    SeatNo    TotalFare
Ali Khan         2           1003       7          34        9000.00
Sara Ahmed       1           1009       3          12        6000.00
```

The file is automatically deleted when the user selects **Exit** from the main menu.

> **Note:** The file path is currently hardcoded to `D:\seats_reserved.txt`. Change this in `reservation()` and `showAllTickets()` to a relative path like `seats_reserved.txt` for portability.

---

## ⚠️ Known Limitations & Improvements

| Current Limitation | Suggested Improvement |
|---|---|
| Hardcoded login credentials | Implement a user database with hashed passwords |
| File path hardcoded to `D:\` | Use relative path `./seats_reserved.txt` |
| Uses `goto` statements | Refactor to `while` loops |
| No actual seat tracking | Add a seat availability data structure |
| Single-user system | Extend to multi-user with role-based access |

---

## 👥 Team

**Course:** Programming Fundamentals / Introduction to Programming
**University:** University of Wah

---

## 📄 License

This project is licensed under the MIT License.
