/*
 * File: hotelModel.cpp
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: Hotel manager with 2 positions of manager and staff
 */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

/* class dish with basic information */
class Dish {
    private:
        int ID;
        string NAME;
        int PRICE;
    public:
        Dish(int id = 0, string name = NULL, int price = 0);
        void setName(string name);
        void setPrice(int price);
        int getId();
        string getName();
        int getPrice();

};

Dish::Dish (int id, string name, int price) {
    this->ID = id;
    this->NAME = name;
    this->PRICE = price;
}

void Dish::setName (string name) {
    NAME = name;
}

void Dish::setPrice (int price) {
    PRICE = price;
}

string Dish::getName () {
    return NAME;
}

int Dish::getPrice () {
    return PRICE;
}

int Dish::getId () {
    return ID;
}

/* Desciption: Service about managing dishes in the menu */
class Service {
    private:
        vector<Dish> databaseDish;
    public:
        void setService();
        vector<Dish> getDatabaseDish();
        void addDish();

        /* Input vector<Dis> to use different databases */
        void eraseDish(vector<Dish> *database);
        void editDish(vector<Dish> *database);
        void getListDish(vector<Dish> *database);

};

/* 
 * Function: Service::setService()
 * Description: Set to go to the function of the Service class
 */
void Service::setService () {
    int keyBoard = 0;
    do
    {
        cout << "\nService:\n--------------------\n"
             << "1: Addtion dishes\n2: Editing dishes\n3: Erase dishes\n4: Print Menu\n"
             << "0: Come back\n--------------------\nSelect key: ";
        cin >> keyBoard;
        switch (keyBoard)
        {
        case 1:
            addDish();
            break;
        case 2:
            editDish(&databaseDish);
            break;
        case 3:
            eraseDish(&databaseDish);
            break;
        case 4:
            cout << "\n";
            getListDish(&databaseDish);
            cout << "Select any number key to go back\nSelect any number key: ";
            cin >> keyBoard;
            cout << "\n\n";
            break;    
        case 0:
            cout << "\n\n";
            return;
        default:
            cout << "\nWARNING: Invalid input key. Please re-enter!\n";
            break;
        }
    } while (keyBoard); 
}

vector<Dish> Service:: getDatabaseDish() {
    return databaseDish;
}

/* 
 * Function: Service::setService()
 * Description: Add food to databaseDish from keyboard
 */
void Service::addDish () {
    static int id = 100;
    string name;
    int price;
    int keyBoard = 0;
    do { 
        cout << "\nPlease enter information\n";
        cin.ignore();
        cout << "Enter name: "; getline(cin, name);
        cout << "Enter price: "; cin >> price;

        /*Create a new Dish and add it to databaseDish*/
        Dish dish(id, name, price);
        databaseDish.push_back(dish);
        
        cout << "\nSuccessful addition of dishes!\n";
        getListDish(&databaseDish);
        id++;
        againKeyBoard:
        cout << "1: Keep adding\n0: Come back\nSelect key: ";
        cin >> keyBoard;
  
        if(keyBoard == 0) return;
        else if(keyBoard != 1) {
            cout << "\nWARNING: Invalid input key. Please re-enter!\n";
            goto againKeyBoard;
        } 

    } while(keyBoard == 1);
}

/* 
 * Function: Service::setService()
 * Description: Edit the dish corresponding to the database parameter
 * Input:
 *     vector<Dish> *database
 */
void Service::editDish (vector<Dish> *database) {

    int keyBoard = 0;
    int id;
    string name;
    int price;

    /* Check if database is empty */
    if (database->size() == 0) {
        cout <<"\nMenu empty!. Please add dish";
        return;
    }

    do
    { 
        int checkId = 0;
        cout << "\n";
        getListDish(database);

        /* Check if input Id is valid */
        againEnterId:
        cout << "Enter the dish ID to edit: "; cin >> id;
        for(int i = 0; i < database->size(); i++) {
            if((*database)[i].getId() == id) {
                checkId++;
                id = i;
                break;
            }
        }
        if(checkId == 0) {
            cout << "\nWARNING !!!: Invalid input ID. Please re-enter!\n";
            goto againEnterId;
        }
        
        /* Edit the dishes from the keyboard */
        againEnterKey:
        cout << "-----------------------\n" 
             << "1: Edition name\n2: Edition price\n0: Come back\n"
             << "-----------------------\nSelect key: ";
        cin >> keyBoard;
        if(keyBoard == 1) {
            cout << "Enter name again: "; cin >> name;
            (*database)[id].setName(name);
        }
        else if(keyBoard == 2) {
            cout << "Enter price again: "; cin >> price;
            (*database)[id].setPrice(price);
        }
        else if(keyBoard == 0) return;
        else {
            cout << "Invalid input key. Please re-enter!\n";
            goto againEnterKey;
        }
        cout << "\nEditing is successful!";
        getListDish(database);


        againEnterKey2:
        cout << "1: Keep edition\n0: Come back\nSelect key: "; cin >> keyBoard;
        if(keyBoard == 0) return;
        else if(keyBoard != 1) {
            cout << "Invalid input key. Please re-enter!\n";
            goto againEnterKey2;
        } 
    }while(keyBoard == 1);
}

/*
 * Function eraseDish()
 * Description: Delete the corresponding dish of the database parameter
 * Input:
 *     vector<Dish> *database 
 */
void Service::eraseDish (vector<Dish> *database) {

    int id = 0;
    int keyBoard = 0;
    do
    {
        int checkId = 0;

        /* Check if database is empty */
        cout << "\n";
        getListDish(database);
        if(database->size() == 0) {
            cout << "\t\t\t\tWARNING: No dishes!\n";
            return;
        }

        againEnterId:

        /* Check if input Id is valid */
        cout << "Enter the ID to delete\nEnter ID: "; cin >> id;
        for(int i = 0; i < database->size(); i++) {
            if((*database)[i].getId() == id) {
                checkId++;
                id = i;
            }
        }
        if(checkId == 0) {
            cout << "\nWARNING !!!: Invalid input ID . Enter ID again\n";
            goto againEnterId;
        }
        
        /* Erase the dishes*/
        database->erase(database->begin() + id);
        cout << "\nDelete dish successfully\n";
        getListDish(database);
        
        againKeyBoard:
        cout << "1: Keep delete\n0: Exit\nSelect key: "; cin >> keyBoard;
        if(keyBoard == 0) return;
        else if(keyBoard != 1) {
            cout << "\nWARNING !!!: Invalid input key. Select key agian\n\n";
            goto againKeyBoard;
        }

    } while (keyBoard == 1);
}

void Service::getListDish (vector<Dish> *database) {

    cout << "List of dish:\n---------------------------------------------------------------------------------\n"
         << "|\tID" << "\t|\t\t" << "Name" << "\t\t|\t\t" << "Price\t\t|\n"
         << "---------------------------------------------------------------------------------\n";

    for (int i = 0; i < database->size() ; i++) {
        cout << "|\t" << (*database)[i].getId() << "\t|\t\t" 
             << (*database)[i].getName() << "\t\t|\t\t"
             << (*database)[i].getPrice() << "\t\t|\t\t\n"
             << "---------------------------------------------------------------------------------\n";
    }
}

/* Description: Create class time with basic information */
class Time {
    private:
        int mMinute;
        int mHour;
        int mDay;
        int mMonth;
    public:
        void setMinute(int minute);
        void setHour(int hour);
        void setDay(int day);
        void setMonth(int month);
        int getMinute();
        int getHour();
        int getDay();
        int getMonth();
};

void Time::setMinute (int minute) {
    this->mMinute = minute;
}

void Time::setHour (int hour) {
    this->mHour = hour;
}

void Time::setDay (int day) {
    this->mDay = day;
}

void Time::setMonth (int month) {
    this->mMonth = month;
}

int Time::getMinute () {
    return mMinute;
}

int Time::getHour () {
    return mHour;
}

int Time::getDay () {
    return mDay;
}

int Time::getMonth () {
    return mMonth;
}

/* create class room with functions related to room */
class Room: public Service {
    private:
        Time mTime;/* Data of dish in room */
        vector<Dish> databaseDishInRoom;
        int mLocation;
        string mStatus;
    public:
        Room(int location = 0, string status = 0);
        void setStatus(string status);
        int getLocation();
        string getStatus();
        Time getTime();
        int getDishCost();

        void setRoom(vector<Dish> databaseDishOnMenu, int hourCost, int dayCost);
        void setRegisterTime();
        void setService(vector<Dish> databaseDishOnMenu);
        void addDishInRoom(vector<Dish> databaseDishOnMenu);
        void payRoom(int hourCost, int dayCost);

};

Room::Room (int location, string status) {
    this->mLocation = location;
    this->mStatus = status;
}

void Room::setStatus (string status) {
    mStatus = status;
}

int Room::getLocation () {
    return mLocation;
}

string Room::getStatus () {
    return mStatus;
}

/*
 * Function: Room::setRoom()
 * Description: Setting to go to selected functions
 * Input:
 *     vector<Dish> databaseDishOnMenu
 *     int hourCost
 *     int dayCost
 */
void Room::setRoom (vector<Dish> databaseDishOnMenu, int hourCost, int dayCost) {
    
    int keyBoard = 0;
    do
    {
        cout << "Select function !!!\n--------------------\n"
             << "1: New rental\n2: Services\n3: Pay for room\n0: Come back\n--------------------\nSelect key: ";
        cin >> keyBoard;
        cout << "\n";
        switch (keyBoard)
        {
        case 1:
            setRegisterTime();
            break;
        case 2:
            setService(databaseDishOnMenu);
            break;
        case 3:
            payRoom(hourCost, dayCost);           
            break;
        case 0:
            cout << "\n\n";
            return;
        default:
            cout << "\nWARNING: Invalid input key. Please re-enter!\n";
            break;
        }
    } while (keyBoard); 
}

Time Room::getTime () {
    return mTime;
}

/*
 * Function: Room::setService()
 * Description: Setting to go to the functions in the class service
 * Input:
 *     vector<Dish> databaseDishOnMenu
 */
void Room::setService (vector<Dish> databaseDishOnMenu) {

    string checkStatus = getStatus();
    if (checkStatus.compare("x") != 0) {
        cout << "\nRoom is not yet rented, please rent a room\n";
        return;
    }

    int keyboard = 0;

    do
    {
    againKeyBoard:
    cout << "\nService:\n--------------------------\n";
    cout << "1: Addtion dishes\n2: Editing dishes \n3: Erase dishes\n4: Print the ordered dishes\n"
         << "0: Come back\n--------------------------\nSelect key: ";
    cin >> keyboard;
    cout << "\n\n";
    switch (keyboard)
    {
    case 0:
        return;
    case 1:
        addDishInRoom(databaseDishOnMenu); 
        break;
    case 2:
        editDish(&databaseDishInRoom);
        break;
    case 3:
        eraseDish(&databaseDishInRoom);
        break;
    case 4:
        /* print lish of the dishes form the room with corresponding room Number */
        getListDish(&databaseDishInRoom);
        cout << "Select any number key to go back\nSelect any number key: ";
        int comeBack;
        cin >> comeBack;
        break;
    default:
        cout << "\nWARNING!!!: Invalid input key. Select key again";
        goto againKeyBoard;
        break;
    }
        /* code */
    } while (keyboard);
    
}

/*
 * Function: Room::setRegisterTime()
 * Description: Set up the rental registration periode
 */
void Room::setRegisterTime () {
    
    /* Check if the room has been rented before or not */
    string checkStatus = getStatus();
    if (checkStatus.compare("x") == 0) {
        cout << "This room is already occupied, please pay to renew";
        return;
    }
    
    int minute = 0;
    int hour = 0;
    int day = 0;
    int month = 0;
    int keyBoard = 0;

    againKeyBoard:
    cout << "New rental:\n--------------------\n";
    cout << "1: Rent by the hour\n2: Rent by the day\n0: Comback\n--------------------\nSelect key: ";
    cin >> keyBoard;
    cout << "\n\n";

    if(keyBoard == 1) {
        cout << "Enter rental start time: ";
        cout << "\nEnter minute: "; cin >> minute;
        cout << "Enter hour: "; cin >> hour; 
        cout << "Enter day: "; cin >> day;
        cout << "Enter month: "; cin >> month;

        this->mTime.setMinute(minute);
        this->mTime.setHour(hour);
        this->mTime.setDay(day);
        this->mTime.setMonth(month);

        /* Set up a rented room */
        setStatus("x");
    }
    else if(keyBoard == 2) {
        cout << "Enter rental start time: ";
        minute = -1;
        cout << "\nEnter hour: "; cin >> hour; 
        cout << "Enter day: "; cin >> day;
        cout << "Enter month: "; cin >> month;

        this->mTime.setMinute(minute);
        this->mTime.setHour(hour);
        this->mTime.setDay(day);
        this->mTime.setMonth(month);

        setStatus("x");
    }
    else if(keyBoard == 0) return;
    else {
        cout << "Invalid key input, re-enter\n";
        goto againKeyBoard;
    }
    cout << "Successfully entered rental\n\n";
}

/*
 * Function: Room::getDishCost()
 * Description: Calculate the cost of food in the corresponding room
 * Output:
 *     cost
 */
int Room::getDishCost () {

    int cost = 0;
    for (int i = 0; i < databaseDishInRoom.size(); i++) {
        cost = databaseDishInRoom[i].getPrice() + cost;
    }
    return cost;
}

/*
 * Function: Room::payRoom()
 * Description: Set up the rental registration periode
 */
void Room::payRoom(int hourCost, int dayCost) {
    
    /* Check if the room is already rented */
    string checkStatus = getStatus();
    if (checkStatus.compare("x") != 0) {
        cout << "\nRoom is not yet rented, please rent a room\n";
        return;
    }

    int currentMinute = 0;
    int currentHour = 0;
    int currentDay = 0;
    int currentMonth = 0;
    int keyBoard = 0;
    int cost = 0;

    againEnter:
    cout << "Enter check-out time: ";
    cout << "\nEnter minute: "; cin >> currentMinute;
    cout << "Enter hour: "; cin >> currentHour; 
    cout << "Enter day: "; cin >> currentDay;
    cout << "Enter month: "; cin >> currentMonth;
    
    /* Calculate rental cost by day */
    if (getTime().getMinute() == -1) {
        if (currentMonth = getTime().getMonth()) {
            if (currentDay = getTime().getDay()) {
                cost = dayCost;
            } else if (currentDay > getTime().getDay()){
                if (currentHour <= getTime().getHour()) {
                    cost = dayCost * (currentDay - getTime().getDay());
                } else cost = dayCost * (currentDay - getTime().getDay() + 1); 
            }
        } else if (currentMonth - getTime().getMonth() == 1) {
            if (currentDay = getTime().getDay()) {
                if (currentHour <= getTime().getHour()) {
                    cost = dayCost * 30;
                } else cost = dayCost * 31;
            } else if (currentDay > getTime().getDay()) {
                if (currentHour <= getTime().getHour()) {
                    cost = dayCost * (30 + (currentDay - getTime().getDay()));
                } else {
                    cost = dayCost * (30 + (currentDay - getTime().getDay()) + 1);
                }
            } else {
                if (currentHour <= getTime().getHour()) {
                    cost = dayCost * (30 - (getTime().getDay() - currentDay));
                } else {
                    cost = dayCost * (30 - (getTime().getDay() - currentDay) + 1);
                }
            } 
        }

    /* Calculate rental cost by hour */
    } else {
        if (currentDay == getTime().getDay()) {
            if (currentHour = getTime().getHour()) {
                cost = hourCost;
            } else if (currentHour > getTime().getHour()) {
                if (currentMinute <= getTime().getMinute()) {
                    cost = hourCost * (currentHour - getTime().getHour());
                } else {
                    cost = hourCost * (currentHour - getTime().getHour() + 1);
                }
            }
        } else if (currentDay > getTime().getDay()) {
            if (currentHour == getTime().getHour()) {
                if (currentMinute <= getTime().getMinute()) {
                    cost = hourCost * 24;
                } else cost = hourCost * 25;
            } else if (currentHour < getTime().getHour()) {
                if (currentMinute <= getTime().getMinute())
                {
                    cost = hourCost * (24 - (getTime().getHour() - currentHour));
                } else cost = hourCost * (24 - (getTime().getHour() - currentHour) + 1);
            } else if (currentHour > getTime().getHour()) {
                if (currentMinute <= getTime().getMinute())
                {
                    cost = hourCost * (24 + (getTime().getHour() - currentHour));
                } else cost = hourCost * (24 + (getTime().getHour() - currentHour) + 1);
            }
        }
    }
    
    cout << "\n\nRoom bill " << getLocation() << ":\n";
    getListDish(&databaseDishInRoom);
    cout << "Cost lish:\n-----------------------------------------\n"
        << "|\tHour\t|\t" << hourCost << "\t\t|\n"
        << "-----------------------------------------\n"
        << "|\tDay\t|\t" << dayCost << "\t\t|\n"
        << "-----------------------------------------\n";

    if (getTime().getMinute() != -1) {
        cout << "Rent time: " << getTime().getHour() << ":" << getTime().getMinute()
        << "   " << getTime().getDay() << "/" << getTime().getMonth() << "\n";
    } else {
        cout << "Rent time: " << getTime().getHour() << "h "
        << "   " << getTime().getDay() << "/" << getTime().getMonth() << "\n";
    }
    cout << "Real time: " << currentHour << ":" << currentMinute
        << "   " << currentDay << "/" << currentMonth;
    
    cout << "\nTotal cost of room " << getLocation() <<": " << cost + getDishCost() << " dong\n\n";
    cout << "Enter any key to back\nSelect key: "; cin >> keyBoard;
    cout << "\n\n";
    setStatus(" ");
}

/*
 * Function: Room::addDishInRoom()
 * Description: Add food to the selected room
 */
void Room::addDishInRoom (vector<Dish> databaseDishOnMenu) {

    /* Check dishes from the main menu*/
    if(databaseDishOnMenu.size() == 0) {
        cout << "\nWARNING !!!: Main menu is empty, please add dishes to main menu:\n";
        return;
    }


    static int id = 0;
    int keyboard = 0;
    int checkId = 0;
    do { 
        
        getListDish(&databaseDishOnMenu);
        againEnterId:
        cout << "Please enter the dish id\n";
        cout << "Enter id: "; cin >> id;
        
        for (int i = 0; i < databaseDishOnMenu.size(); i++)
        {
            if(databaseDishOnMenu[i].getId() == id) {
                checkId++;
                /* Add dishes to room Number with corresponding ID */
                string name = databaseDishOnMenu[i].getName();
                int price = databaseDishOnMenu[i].getPrice();
                Dish dish(id, name, price);
                databaseDishInRoom.push_back(dish);
                break;
            }
            
        }
        
        if(checkId == 0) {
            cout << "WARNING!!!: Invalid input key. Select key again";
            goto againEnterId;
        }
 
        cout << "\n1: Keep adding\n0: Exit\nSelect key: "; cin >> keyboard;
        cout << "\n\n";
        if(keyboard == 0) {
            cout << "The dish added successfully\n";
            /* Update the status of room */
            getListDish(&databaseDishInRoom);
            cout << "Enter any key to back\nSelect key: ";
            cin >> keyboard;
            cout << "\n\n";
            return;
        }
        
    } while(keyboard == 1);
}


class Manager: public Service {
    private:
        int mHourCost;
        int mDayCost;
        int mNumberOfRoom;
    public:
        void setFistValue();
        int getHourCost();
        int getDayCost();
        int getNumberOfRoom();
        void setManager();
        void setRentCost();
        void getListRentCost();
        void setNumberOfRoom();
};

void Manager::setFistValue () {
    this->mHourCost = 0;
    this->mDayCost = 0;
    this->mNumberOfRoom = 0;
}

int Manager::getHourCost () {
    return mHourCost;
}

int Manager::getDayCost () {
    return mDayCost;
}

int Manager::getNumberOfRoom () {
    return mNumberOfRoom;
}

void Manager::setManager() {
    int keyBoard = 0;
    do
    {
        cout << "Select function !!!\n--------------------\n"
             << "1: Set room cost\n2: Services\n3: Set the number of room\n0: Come back\n--------------------\nSelect key: ";
        cin >> keyBoard;
        cout << "\n\n";
        switch (keyBoard)
        {
        case 1:
            setRentCost();
            break;
        case 2:
            setService();
            break;
        case 3:
            setNumberOfRoom();           
            break;
        case 0:
            cout << "\n\n";
            return;
        default:
            cout << "WARNING: Invalid input key. Please re-enter!\n";
            break;
        }
    } while (keyBoard); 

}

/*
 * Function: Manager::setRentCost ()
 * Description: Set the rent for the room
 */
void Manager::setRentCost () {

    
    int dayCost = 0;
    int hourCost = 0;
    int keyBoard = 0;

    coutinueSetUp:
    againKeyBoard:
    cout << "Set up cost\n--------------------\n";
    cout << "1: Cost hour\n2: Cost day\n0: Com back\n--------------------\n"
        << "Select key: "; cin >> keyBoard;

    if(keyBoard == 1) {
        cout << "Enter cost hour: "; cin >> hourCost;
        this->mHourCost = hourCost;
    }
    else if(keyBoard == 2) {
        cout << "Enter cost day: "; cin >> dayCost;
        this->mDayCost = dayCost;
    }
    else if(keyBoard == 0) {
        cout << "\n\n";
        return;
    }
    else {
        cout << "Invalid input key. Please re-enter";
        goto againKeyBoard;
    }
    cout << "\n\nSet up successfully\n";
    getListRentCost();
    againKeyBoard2:
    cout << "1: Continue set up cost\n0: Comback\nSelect key: "; cin >> keyBoard;
    cout << "\n\n";
    if(keyBoard == 1) {
        goto coutinueSetUp;
    } else if(keyBoard == 0) return;
    else{
        cout << "Invalid input key. Please re-enter";
        goto againKeyBoard2;
    }
    
}

/*
 * Function: Manager::getListRentCost()
 * Description: Print out a list of rental costs by day and by hour
 */
void Manager::getListRentCost () {
    cout << "Cost lish:\n-----------------------------------------\n"
        << "|\tHour\t|\t" << getHourCost() << "\t\t|\n"
        << "-----------------------------------------\n"
        << "|\tDay\t|\t" << getDayCost() << "\t\t|\n"
        << "-----------------------------------------\n";
}

/*
 * Function: Manager::setNumberOfRoom()
 * Description: Set the number of rooms for the hotel
 */
void Manager::setNumberOfRoom () {

    int numberOfRoom = 0;
    int keyBoard = 0;
    do
    {
        cout << "Enter the number of room: "; cin >> numberOfRoom;
        mNumberOfRoom = numberOfRoom;
        cout << "Enter the number of tables successfully: " << mNumberOfRoom;

        againKeyBoard:
        cout << "\n1: Enter again\n0: Exit\nSelect key: "; cin >> keyBoard;
        cout << "\n\n";
        if(keyBoard == 0) return;
        else if(keyBoard != 1) {
            cout << "\nWARNING!!!: Invalid input key. Select key again\n";
            goto againKeyBoard;
        }
    } while (keyBoard == 1);
    
}

class Staff: public Manager {
    private:
        vector<Room> databaseRoom;
    public:
        void setStaff();
        void getLishRoom();
        void selectRoom();

};

void Staff::setStaff () {

    if(getNumberOfRoom() == 0) {
        cout << "WARNING!!!: Please set up the number of room\n";
        return;
    }
    
    if(getHourCost() == 0) {
        cout << "WARNING!!!: Please set the hourly rental cost";
        return;
    }

    if(getDayCost() == 0) {
        cout << "WARNING!!!: Please set the rental cost by day";
        return;
    }
    
    /* Set up room number and status for the first time*/
    static int checkInitRoom = 0;
    if(checkInitRoom == 0) {
        for (int i = 0; i < getNumberOfRoom(); i++) {
            Room room(i + 1, " ");
            databaseRoom.push_back(room);
        }
        checkInitRoom = getNumberOfRoom();
    }
    
    /* set up room number and status from 2nd update onwards */
    if(checkInitRoom < getNumberOfRoom()) {
        for (int i = checkInitRoom; i < getNumberOfRoom(); i++) {
            Room room(i + 1, " ");
            databaseRoom.push_back(room);
        }
        checkInitRoom = getNumberOfRoom();
        
    }
    else if(checkInitRoom > getNumberOfRoom()) {
        for (int i = checkInitRoom; i > getNumberOfRoom(); i--) {
            databaseRoom.erase(databaseRoom.begin() + (i - 1));
        }
        checkInitRoom = getNumberOfRoom();
    }
        
    
    int keyBoard = 0;
    do
    {   
        againKeyBoard:
        getLishRoom();
        cout << "\n1: Editting of the room\n0: Come back\nSelect key: "; cin >> keyBoard;
        if(keyBoard == 1) selectRoom();
        else if(keyBoard == 0) return;
        else {
            cout << "\nWARNING!!!: Invalid input. Select key again";

            goto againKeyBoard;
        }
        
    } while (keyBoard);
}

/*
 * Function: Staff::getLishRoom()
 * Description: Print a list of rooms and their respective states
 */
void Staff::getLishRoom () {
    
    cout << "Room list:\n";
    cout << "  Room|  ";
    for(int i = 0; i < databaseRoom.size(); i++) {
        cout << databaseRoom[i].getLocation() << "  |  ";     
    }
    cout << "\n"
         << "Status|  ";
    for(int i = 0; i < databaseRoom.size(); i++) {
        if(i >= 9) cout <<" ";
        cout << databaseRoom[i].getStatus() << "  |  ";
    }
}

/*
 * Function: Staff::selectRoom()
 * Description: Select the required room from the keyboard
 */
void Staff::selectRoom () {

    int roomNumber = 0;
    againInputKey:
    cout << "Select room: "; cin >> roomNumber;
    cout <<"\n\n";

    for(int i = 0; i < getNumberOfRoom(); i++) {
        if(roomNumber == i + 1) {

            /* go to function set up the room with index order of i already stored in the database */
            databaseRoom[i].setRoom(getDatabaseDish(), getHourCost(), getDayCost());
        }
    }

    if(roomNumber == 0 || roomNumber > getNumberOfRoom()) {
        cout << "\nWARNING!!!: Invalid input. Select key again\n";
        getLishRoom();
        cout << "\n";
        goto againInputKey;
    }
}

class Program: public Staff {
    public:
        Program();
};

/*
 * Function: Program::Program()
 * Description: Position selection program
 */
Program::Program () {
    
    int key = 0;

    /* Set the value in class manager, the condition needed to get to setStaff fuction */
    setFistValue();
    cout << "-------------------------------------------------"
        << "\n|\tWelcome to the hotel management app\t|"
        << "\n-------------------------------------------------\n\n";

    do
    {
        cout << "Choose a position\n--------------------\n"
             << "1: Manager\n2: Staff\n0: Exit\n--------------------\n"
             << "Select key: ";
        cin >> key;
        cout << "\n\n";
        
        /* Go to manager functions */
        if(key == 1) setManager();
        /* Go to staff functions */
        else if(key == 2) setStaff(); 
        else if(key == 0) return;
        else cout << "\n\t\tWARNING: Invalid input key. Please re-enter!\n";

    } while(key);
}

int main() {
    Program program;
}
