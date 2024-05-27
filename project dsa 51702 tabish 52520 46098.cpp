#include <iostream>
#include <ctime>
#include <iomanip>
#define max 100

#define MAX_ROOMS 100
using namespace std;

class Signup {
protected:
    string username;
    string email;
    string password;
    string phone;

public:
    virtual void displayMenu() = 0; // Pure virtual function to make Signup an abstract class
};

class ReservationSystem {
    int* arr;
    int front;
    int back;
    int capacity;

public:
    ReservationSystem(int size) {
        arr = new int[size];
        capacity = size;
        front = -1;
        back = -1;
    }

    ~ReservationSystem() {
        delete[] arr;
    }

    void reservation(int x) {
        if (back == capacity - 1) {
            cout << "Rooms are full, cannot book more rooms." << endl;
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1) {
            front = 0;
        }
        cout << "Room booked with ID: " << x << endl;
    }

    void cancellation() {
        if (front == -1 || front > back) {
            cout << "No rooms to cancel." << endl;
            return;
        }
        cout << "Room canceled with ID: " << arr[front] << endl;
        front++;
        if (front > back) {
            front = -1;
            back = -1;
        }
    }

    int confirmation() {
        if (front == -1 || front > back) {
            cout << "No rooms for confirmation." << endl;
            return -1;
        }
        cout << "Next room for confirmation: " << arr[front] << endl;
        return arr[front];
    }
};

class RoomManagement {
private:
    int arr[max];
    int top;

public:
    RoomManagement() {
        top = -1;
    }

    void roomType(int x) {
        if (top == max - 1) {
            cout << "Room is full." << endl;
            return;
        }
        top++;
        arr[top] = x;
        cout << "Room type added." << endl;
    }

    void empty() {
        if (top == -1) {
            cout << "Hotel is empty, no rooms available." << endl;
            return;
        }
        top--;
        cout << "Room removed." << endl;
    }

    int peek() {
        if (top == -1) {
            cout << "No rooms available." << endl;
            return -1;
        }
        return arr[top];
    }
};

class CheckInQueue {
private:
    int arr[max];
    int front;
    int rear;

public:
    CheckInQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == max - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Hotel is full. Cannot check in." << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = x;
        cout << "Customer checked in." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Hotel is empty. Cannot check out." << endl;
            return;
        }
        front++;
    }

    void displayInformation() {
        string name, idCardNumber, fatherName;
        int phoneNumber, dateOfBirth, checkInDate, checkInTime;

        cout << "Enter the name of the customer for check-in: ";
        cin >> name;
        cout << "Enter the ID card number: ";
        cin >> idCardNumber;
        cout << "Enter the phone number of the customer: ";
        cin >> phoneNumber;
        cout << "Enter the date of birth: ";
        cin >> dateOfBirth;
        cout << "Enter the father's name of the customer: ";
        cin >> fatherName;
        cout << "Enter the date for the check-in: ";
        cin >> checkInDate;
        cout << "Enter the time for check-in: ";
        cin >> checkInTime;

        cout << "Customer details:" << endl;
        cout << "Name: " << name << endl;
        cout << "ID Card Number: " << idCardNumber << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Father's Name: " << fatherName << endl;
        cout << "Check-in Date: " << checkInDate << endl;
        cout << "Check-in Time: " << checkInTime << endl;
    }
};

class CheckoutQueue {
private:
    int arr[max];
    int front;
    int rear;

public:
    CheckoutQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == max - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Hotel is full. Cannot enqueue." << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = x;
        cout << "Customer checked in." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Hotel is empty. Cannot dequeue." << endl;
            return;
        }
        front++;
    }

    void displayInformation() {
        string name, idCardNumber, fatherName;
        int phoneNumber, dateOfBirth, checkOutDate, checkOutTime;

        cout << "Enter the name of the customer for check-out: ";
        cin >> name;
        cout << "Enter the ID card number: ";
        cin >> idCardNumber;
        cout << "Enter the phone number of the customer: ";
        cin >> phoneNumber;
        cout << "Enter the date of birth: ";
        cin >> dateOfBirth;
        cout << "Enter the father's name of the customer: ";
        cin >> fatherName;
        cout << "Enter the date for the check-out: ";
        cin >> checkOutDate;
        cout << "Enter the time for check-out: ";
        cin >> checkOutTime;

        cout << "Customer details:" << endl;
        cout << "Name: " << name << endl;
        cout << "ID Card Number: " << idCardNumber << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Father's Name: " << fatherName << endl;
        cout << "Check-out Date: " << checkOutDate << endl;
        cout << "Check-out Time: " << checkOutTime << endl;
    }
};

class Customer : public Signup {
public:
    void displayMenu() override {
        int choice;
        ReservationSystem reservation(10); // Example capacity
        RoomManagement roomManagement;
        CheckInQueue checkInQueue;
        CheckoutQueue checkoutQueue;

        do {
            cout << "*Main Menu" << endl;
            cout << "Press 1 for Reservation" << endl;
            cout << "Press 2 for Room Management" << endl;
            cout << "Press 3 for Check-in" << endl;
            cout << "Press 4 for Check-out" << endl;
            cout << "Press 5 for Logout" << endl;
            cout << "Press 6 for Exit" << endl;
            cout << "Please enter a valid choice (1-6): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "You selected reservation." << endl;
                    int roomId;
                    cout << "Enter the room ID to book: ";
                    cin >> roomId;
                    reservation.reservation(roomId);
                    break;
                case 2:
                    cout << "You selected room management." << endl;
                    int roomType;
                    cout << "Enter the room type to add: ";
                    cin >> roomType;
                    roomManagement.roomType(roomType);
                    break;
                case 3:
                    cout << "You selected check-in." << endl;
                    checkInQueue.displayInformation();
                    break;
                case 4:
                    cout << "You selected check-out." << endl;
                    checkoutQueue.displayInformation();
                    break;
                case 5:
                    cout << "Logging out..." << endl;
                    return; // Exit the menu on logout
                case 6:
                    cout << "Exiting..." << endl;
                    exit(0); // Exit the program
                default:
                    cout << "Invalid choice. Please enter again." << endl;
                    break;
            }
        } while (choice != 6);
    }

    void signup() {
        cout << "Customer Signup" << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter phone: ";
        cin >> phone;
        cout << "Customer signup successful!" << endl;
    }

    void login() {
        cout << "Customer Login" << endl;
        string enteredUsername, enteredPassword;
                cout << "Enter your username: ";
        cin >> enteredUsername;
        cout << "Enter your password: ";
        cin >> enteredPassword;

        if (username == enteredUsername && password == enteredPassword) {
            cout << "Welcome to the customer main menu" << endl;
            displayMenu();
        } else if (username != enteredUsername && password == enteredPassword) {
            cout << "Incorrect username." << endl;
        } else if (username == enteredUsername && password != enteredPassword) {
            cout << "Incorrect password." << endl;
        } else {
            cout << "Incorrect username and password." << endl;
        }
    }
};

class Admin : public Signup {
public:
    void displayMenu() override {
        int choice;
        ReservationSystem reservation(10); // Example capacity
        RoomManagement roomManagement;
        CheckInQueue checkInQueue;
        CheckoutQueue checkoutQueue;

        do {
            cout << "*Main Menu" << endl;
            cout << "Press 1 for Reservation" << endl;
            cout << "Press 2 for Room Management" << endl;
            cout << "Press 3 for Check-in" << endl;
            cout << "Press 4 for Check-out" << endl;
            cout << "Press 5 for Logout" << endl;
            cout << "Press 6 for Exit" << endl;
            cout << "Please enter a valid choice (1-6): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "You selected reservation." << endl;
                    int roomId;
                    cout << "Enter the room ID to book: ";
                    cin >> roomId;
                    reservation.reservation(roomId);
                    break;
                case 2:
                    cout << "You selected room management." << endl;
                    int roomType;
                    cout << "Enter the room type to add: ";
                    cin >> roomType;
                    roomManagement.roomType(roomType);
                    break;
                case 3:
                    cout << "You selected check-in." << endl;
                    checkInQueue.displayInformation();
                    break;
                case 4:
                    cout << "You selected check-out." << endl;
                    checkoutQueue.displayInformation();
                    break;
                case 5:
                    cout << "Logging out..." << endl;
                    return; // Exit the menu on logout
                case 6:
                    cout << "Exiting..." << endl;
                    exit(0); // Exit the program
                default:
                    cout << "Invalid choice. Please enter again." << endl;
                    break;
            }
        } while (choice != 6);
    }

    void signup() {
        cout << "Admin Signup" << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter phone: ";
        cin >> phone;
        cout << "Admin signup successful!" << endl;
    }

    void login() {
        cout << "Admin Login" << endl;
        string enteredUsername, enteredPassword;
        cout << "Enter your username: ";
        cin >> enteredUsername;
        cout << "Enter your password: ";
        cin >> enteredPassword;

        if (username == enteredUsername && password == enteredPassword) {
            cout << "Welcome to the admin main menu" << endl;
            displayMenu();
        } else if (username != enteredUsername && password == enteredPassword) {
            cout << "Incorrect username." << endl;
        } else if (username == enteredUsername && password != enteredPassword) {
            cout << "Incorrect password." << endl;
        } else {
            cout << "Incorrect username and password." << endl;
        }
    }
};

int main() {
	time_t now = time(0);
    tm *tm = localtime(&now);

    
    cout << "\n\n\n\n\n\n\n\t\t\t\t  PROJECT NAME:              Hotel Management System**" << endl;
    cout << "\n\n\n\t\t\t\t  PRESENTED BY:              Tabish Nazir  Muhammad Rafay  Fahad Rasheed**" << endl;
    cout << "\n\n\t\t\t\t  This program allows users to perform various hotel management operations." << endl;
    
    cout << "\n\n\n\t\t\t\t  Press Enter to continue" << endl;
    cin.get();

    int choice;
    do {
        cout << "\nPlease enter your choice:" << endl;
        cout << "1. Customer" << endl;
        cout << "2. Admin" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Customer customer;
                int subChoice;
                do {
                    cout << "\nCustomer Menu:" << endl;
                    cout << "1. Signup" << endl;
                    cout << "2. Login" << endl;
                    cout << "3. Back" << endl;
                    cout << "Choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            customer.signup();
                            break;
                        case 2:
                            customer.login();
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Invalid choice. Please enter again." << endl;
                            break;
                    }
                } while (subChoice != 3);
                break;
            }
            case 2: {
                Admin admin;
                int subChoice;
                do {
                    cout << "\nAdmin Menu:" << endl;
                    cout << "1. Signup" << endl;
                    cout << "2. Login" << endl;
                    cout << "3. Back" << endl;
                    cout << "Choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            admin.signup();
                            break;
                        case 2:
                            admin.login();
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Invalid choice. Please enter again." << endl;
                            break;
                    }
                } while (subChoice != 3);
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
