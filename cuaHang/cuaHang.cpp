/*
 * File: cuaHang.c
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: Manage tables and menus in a restaurant
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;


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

Dish::Dish (int id, string name, int price) {
    this->ID = id;
    this->NAME = name;
    this->PRICE = price;
}

/* Description: Class Manager is created to manage the number of tables and set up the menu */
class Manager {
    private:
        int TABLENUMBER;
        vector<Dish> databaseDish;
    public:
        void setManager();
        void addDish();
        int getIdDish(int index);
        string getNameDish(int index);
        int getPriceDish(int index);
        int getSizeDatabase();
        void setTableNumberInit();
        void setTableNumber();
        int getTableNumber();

        /* Input vector<Dis> to use different databases */
        void editDish(vector<Dish> *database);
        void eraseDish(vector<Dish> *database);
        void getListDish(vector<Dish> *database);

        /* print lish dish from the main menu */
        void getListDish();
};

void Manager::setManager () {
    int keyBoard = 0;
    do
    {
        cout << "\nSelect function !!!\n--------------------\n"
             << "1: Addtion dishes\n2: Editing dishes\n3: Erase dishes\n4: Print Menu\n"
             << "5: Set up the number of tables\n0: Come back\n--------------------\nSelect key: ";
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
            getListDish(&databaseDish);
            break;    
        case 5:
            setTableNumber();
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

/* Description: addDish is created to add food from the keyboard */
void Manager::addDish () {
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
        
        cout << "\nSuccessful addition of dishes!";
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
 * Function getListDish() 
 * Description: Print a list of dishes with different vector<Dish> declare input types
 * Input: 
 *     vector<Dish> *database
 */
void Manager::getListDish (vector<Dish> *database) {

    cout << "\nList of dish:\n---------------------------------------------------------------------------------\n"
         << "|\tID" << "\t|\t\t" << "Name" << "\t\t|\t\t" << "Price\t\t|\n"
         << "---------------------------------------------------------------------------------\n";

    for (int i = 0; i < database->size() ; i++) {
        cout << "|\t" << (*database)[i].getId() << "\t|\t\t" 
             << (*database)[i].getName() << "\t\t|\t\t"
             << (*database)[i].getPrice() << "\t\t|\t\t\n"
             << "---------------------------------------------------------------------------------\n";
    }
}

/* Description: Print a list of dishes form the main menu*/
void Manager::getListDish () {
    getListDish(&databaseDish);
}

/*
 * Function: editDish()
 * Description: Edit the dishes from database according to the input
 * Input:
 *     vector<Dish> *database
 */
void Manager::editDish (vector<Dish> *database) {

    int keyBoard = 0;
    int id;
    string name;
    int price;

    /* Check if database is empty */
    if (database->size() == 0) {
        cout <<"\nMenu empty!. Please add to the menu";
        return;
    }

    do
    { 
        int checkId = 0;
        cout << "\n";
        getListDish(database);

        /* Check if input Id is valid */
        againEnterId:
        cout << "\nEnter the dish ID to edit: "; cin >> id;
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
 * Description: Delete the dishes from database according to the input
 * Input:
 *     vector<Dish> *database 
 */
void Manager::eraseDish (vector<Dish> *database) {

    int id = 0;
    int keyBoard = 0;
    do
    {
        int checkId = 0;

        /* Check if database is empty */
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
        cout << "\nDelete dish successfully";
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

int Manager::getIdDish (int index) {
    return databaseDish[index].getId();
}

string Manager::getNameDish (int index) {
    return databaseDish[index].getName();
}

int Manager::getPriceDish (int index) {
    return databaseDish[index].getPrice();
}

int Manager::getSizeDatabase () {
    return databaseDish.size();
}

int Manager::getTableNumber () {
    return TABLENUMBER;
}

void Manager::setTableNumberInit () {
    this->TABLENUMBER = 0;
}

/* Description: setTableNumber() is created to set the number of tables */ 
void Manager::setTableNumber () {

    int tableNumber = 0;
    int keyBoard = 0;
    do
    {
        cout << "\nEnter the number of tables: "; cin >> tableNumber;
        TABLENUMBER = tableNumber;
        cout << "Enter the number of tables successfully: " << TABLENUMBER;

        againKeyBoard:
        cout << "\n1: Enter again\n0: Exit\nSelect key: "; cin >> keyBoard;
        if(keyBoard == 0) return;
        else if(keyBoard != 1) {
            cout << "\nWARNING!!!: Invalid input key. Select key again\n";
            goto againKeyBoard;
        }
    } while (keyBoard == 1);
    
}

/*
 * Description: Class Table is inherited from public Manager 
 * it is created to encapsulate information at tables
 */
class Table:public Manager {
    private:
        vector<Dish> databaseDishOnTable;
        int LOCATION;
        string STATUS;
    public:
        Table(int location = 0, string status = 0);
        void setStatus(string status);
        int getLocation();
        string getStatus();
        vector<Dish> getDatabaseDishOnTable();
        void addDishOnTable(Dish dish);
        void editDishOnTable(int tableNumber);
        void eraseDishOnTable(int tableNumber);
        void payDishOnTable(int tableNumber);
        void getLishDishOnTable(int tableNumber);
};

Table::Table (int location, string status) {
    this->LOCATION = location;
    this->STATUS = status;
}

vector<Dish> Table::getDatabaseDishOnTable () {
    return databaseDishOnTable;
}

void Table::eraseDishOnTable (int tableNumber) {
    cout << "\nTable " << tableNumber <<":";
    eraseDish(&databaseDishOnTable);
}

void Table::editDishOnTable (int tableNumber) {
    cout << "\nTable " << tableNumber << ":";
    editDish(&databaseDishOnTable);
}

void Table::getLishDishOnTable (int tableNumber) {
    cout << "List of dishes at table " << tableNumber << ":";
    getListDish(&databaseDishOnTable);
}

/* 
 * Function: payDishOnTable
 * Description: To pay for the dishes from the input table 
 * Input:
 *     int tableNumber
 * Output:
 *     int fee
 */
void Table::payDishOnTable (int tableNumber) {

    if(databaseDishOnTable.size() == 0) {
        cout << "\nWARNING!!!: Table " << tableNumber << " has no dishes!";
        return;
    }
    int fee = 0;
    for(int i = 0; i < databaseDishOnTable.size(); i++) {
        fee = databaseDishOnTable[i].getPrice() + fee; 
    }
    cout << "\nTotal cost of the table " << tableNumber << " to pay: " << fee << " dong";
    databaseDishOnTable.clear();

}

void Table::addDishOnTable (Dish dish) {
    databaseDishOnTable.push_back(dish);
}

void Table::setStatus (string status) {
    STATUS = status;
}

int Table::getLocation () {
    return LOCATION;
}

string Table::getStatus () {
    return STATUS;
}

/*
 * Description: Class Staff is inherited from public Manager 
 * it is created manage dishes at different tables
 */
class Staff: public Manager {
    private:
        vector<Table> databaseTable;
    public:
        void setDatabaseTable();
        void getListTable();
        void selectTable();
        void setTable(int tableNumber);
        void addDishOnTable(int tableNumber);
        void editDishOnTable(int tableNumber);
        void eraseDishOnTable(int tableNumber);
        void payDishOnTable(int tableNumber);

};


void Staff::setDatabaseTable () {

    if(getTableNumber() == 0) {
        cout << "\nWARNING!!!: Please set up the number of tables\n";
        return;
    }
    
    /* Set up tables for the first time*/
    static int checkInitTable = 0;
    if(checkInitTable == 0) {
        for (int i = 0; i < getTableNumber(); i++) {
            Table table(i + 1, " ");
            databaseTable.push_back(table);
        }
        checkInitTable = getTableNumber();
    }
    
    /* set up tables from 2nd update onwards */
    if(checkInitTable < getTableNumber()) {
        for (int i = checkInitTable; i < getTableNumber(); i++) {
            Table table(i + 1, " ");
            databaseTable.push_back(table);         
        }
        checkInitTable = getTableNumber();
        
    }
    else if(checkInitTable > getTableNumber()) {
        for (int i = checkInitTable; i > getTableNumber(); i--) {
            databaseTable.erase(databaseTable.begin() + (i - 1));
        }
        checkInitTable = getTableNumber();
    }
        
    
    int keyBoard = 0;
    do
    {   
        getListTable();
        againKeyBoard:
        cout << "\n1: Editting of the tables\n0: Come back\nSelect key: "; cin >> keyBoard;
        if(keyBoard == 1) selectTable();
        else if(keyBoard == 0) return;
        else {
            cout << "\nWARNING!!!: Invalid input. Select key again";
            goto againKeyBoard;
        }
        
    } while (keyBoard);
}

void Staff::getListTable () {
    
    cout << "\n Table|  ";
    for(int i = 0; i < databaseTable.size(); i++) {
        cout << databaseTable[i].getLocation() << "  |  ";     
    }
    cout << "\n"
         << "Status|  ";
    for(int i = 0; i < databaseTable.size(); i++) {
        if(i >= 9) cout <<" ";
        cout << databaseTable[i].getStatus() << "  |  ";
    }
}

/* Description: Select the table number which is needed manage from the keyborad */
void Staff::selectTable () {

    int tableNumber = 0;
 
    againInputKey:
    cout << "Select table: "; cin >> tableNumber;

    for(int i = 0; i < getTableNumber(); i++) {
        if(tableNumber == i + 1) {
            setTable(tableNumber);
            break;
        }
    }

    if(tableNumber == 0 || tableNumber > getTableNumber()) {
        cout << "\nWARNING!!!: Invalid input. Select key again\n";
        goto againInputKey;
    }
}

/* Function: setTable()
 * Description: Select features from selected table
 * Input: 
 *     int tableNumber
 */
void Staff::setTable (int tableNumber) {

    int keyboard = 0;
    againKeyBoard:
    cout << "\n1: Addtion dishes\n2: Editing dishes \n3: Erase dishes\n4: Payment for the dining table\n5: Print the ordered dishes\n"
         << "0: Come back\n\nSelect key: ";
    cin >> keyboard;
    switch (keyboard)
    {
    case 0:
        return;
    case 1:
        addDishOnTable(tableNumber);
        break;
    case 2:
        editDishOnTable(tableNumber);
        break;
    case 3:
        eraseDishOnTable(tableNumber);
        break;
    case 4:
        payDishOnTable(tableNumber);
        break;
    case 5:
        /* print lish of the dishes form the table with corresponding table Number */
        databaseTable[tableNumber - 1].getLishDishOnTable(tableNumber);
        goto againKeyBoard;
    default:
        cout << "\nWARNING!!!: Invalid input key. Select key again";
        goto againKeyBoard;
        break;
    }
    
}

void Staff::payDishOnTable (int tableNumber) {
    /* payDishOnTable() below is payDishOnTable() initialized at class Table */
    databaseTable[tableNumber - 1].payDishOnTable(tableNumber);
    /* Update to original state */
    databaseTable[tableNumber - 1].setStatus(" ");
}

void Staff::eraseDishOnTable (int tableNumber) {
    /* eraseDishOnTable() below is eraseDishOnTable() initialized at class Table */
    databaseTable[tableNumber - 1].eraseDishOnTable(tableNumber);
}

void Staff::editDishOnTable (int tableNumber) {
    /* editDishOnTable() below is editDishOnTable() initialized at class Table */
    databaseTable[tableNumber - 1].editDishOnTable(tableNumber);
}

/* 
 * Function: addDishOnTable
 * Description: addDishOnTable() is created to add dishes to corresponding table Number
 * Input:
 *     int tableNumber
 */
void Staff::addDishOnTable (int tableNumber) {

    /* Check dishes from the main menu*/
    if(getSizeDatabase() == 0) {
        cout << "\nWARNING !!!: Main menu is empty, please add dishes to main menu: ";
        return;
    }
    
    getListDish();
    static int id = 0;
    int keyboard = 0;
    int checkId = 0;
    do { 

        againEnterId:
        cout << "\nPlease enter the dish id\n";
        cout << "Enter id: "; cin >> id;
        
        for (int i = 0; i < getSizeDatabase(); i++)
        {
            if(getIdDish(i) == id) {
                checkId++;
                /* Add dishes to table Number with corresponding ID */
                string name = getNameDish(i);
                int price = getPriceDish(i);
                Dish dish(id, name, price);
                databaseTable[tableNumber - 1].addDishOnTable(dish);
                break;
            }
            
        }
        
        if(checkId == 0) {
            cout << "WARNING!!!: Invalid input key. Select key again";
            goto againEnterId;
        }
 
        cout << "\n1: Keep adding\n0: Exit\nSelect key: "; cin >> keyboard;
        if(keyboard == 0) {
            cout << "\nThe dish added successfully\n";
            databaseTable[tableNumber - 1].getLishDishOnTable(tableNumber);
            /* Update the status of someone sitting */
            databaseTable[tableNumber - 1].setStatus("x");
            return;
        }
        
    } while(keyboard == 1);
}

/* Discription: Class Position is created to lead to the corresponding positions*/
class Position: public Staff {
    public:
        Position();

};

Position::Position () {
    
    int key = 0;
    /* Set the initial table number to be able to access staff permissions */
    setTableNumberInit();
    do
    {
        cout << "Select position!!!\n--------------------\n"
             << "1: Manager\n2: Staff\n0: Exit\n--------------------\n"
             << "Select key: ";
        cin >> key;
        
        /* Go to manager functions */
        if(key == 1) setManager();
        /* Go to staff functions */
        else if(key == 2) setDatabaseTable(); 
        else if(key == 0) return;
        else cout << "\n\t\tWARNING: Invalid input key. Please re-enter!\n\n";

    } while(key);
}

int main() {

    Position position;
    return 0;

}