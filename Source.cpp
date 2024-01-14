#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<string.h>
#include<cstring>
#include<time.h>
using namespace std;
// global variable for time
clock_t leela = 0;

// cosnt file names which will use use in program 
const char* Customer_File = "customer.bin";
const char* Admin_file = "Admin.bin";
const char* Manager_File = "Manager.bin";
const string Catalog_File = "Catalog.bin";
const string Karachi_Inventory_File = "Karachi_inventory.bin";
const string Lahore_Inventory_File = "Lahore_inventory.bin";
const string Islamabad_Inventory_File = "Islamabad_inventory.bin";
const string Cart_file = "Cart.bin";
const string Feedback_file = "feedback.bin";

class online_shopping;
class payment;


// declaration of catalog class
class product_catalog;
// declaration of menu function

void menu();

// function to check cnic
bool isValidCNIC(string CNIC) {  //Function to check validity of 13 digit NIC
    for (int i = 0; i < 13; i++)
        if (CNIC[i] < '0' or CNIC[i] > '9')
            return false;

    return true;
}

// function  to check password 
bool isValid_password(string password)   //Function to check validity of password
{   // For checking if password length
    // is between 8 and 15
    if (!((password.length() >= 8) &&
        (password.length() <= 15)))
        return false;

    // To check space
    if (password.find(" ") !=
        std::string::npos)
        return false;

    if (true)
    {
        int count = 0;

        // Check digits from 0 to 9
        for (int i = 0; i <= 9; i++)
        {

            // To convert int to string
            string str1 = to_string(i);

            if (password.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return false;
    }

    // For special characters
    if (!((password.find("@") != std::string::npos) ||
        (password.find("#") != std::string::npos) ||
        (password.find("!") != std::string::npos) ||
        (password.find("~") != std::string::npos) ||
        (password.find("$") != std::string::npos) ||
        (password.find("%") != std::string::npos) ||
        (password.find("^") != std::string::npos) ||
        (password.find("&") != std::string::npos) ||
        (password.find("*") != std::string::npos) ||
        (password.find("(") != std::string::npos) ||
        (password.find(")") != std::string::npos) ||
        (password.find("-") != std::string::npos) ||
        (password.find("+") != std::string::npos) ||
        (password.find("/") != std::string::npos) ||
        (password.find(":") != std::string::npos) ||
        (password.find(".") != std::string::npos) ||
        (password.find(",") != std::string::npos) ||
        (password.find("<") != std::string::npos) ||
        (password.find(">") != std::string::npos) ||
        (password.find("?") != std::string::npos) ||
        (password.find("|") != std::string::npos)))
        return false;

    if (true)
    {
        int count = 0;

        // Checking capital letters
        for (int i = 65; i <= 90; i++)
        {

            // Type casting
            char c = (char)i;
            string str1(1, c);

            if (password.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return false;
    }

    if (true)
    {
        int count = 0;

        // Checking small letters
        for (int i = 97; i <= 122; i++)
        {

            // Type casting
            char c = (char)i;
            string str1(1, c);

            if (password.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return false;
    }

    // If all conditions fails
    return true;
}

// some helping function to use in other functios of validation
bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}

// function to check validity of email
bool is_valid_email(string email) { //Function to check validity of email
    // is an alphabet or not

    if (!isChar(email[0])) return 0;
    int At = -1, Dot = -1;

    // Traverse over the email id
    // string to find position of
    // Dot and At
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@')  At = i;
        else if (email[i] == '.') Dot = i;
    }

    // If At or Dot is not present
    if (At == -1 || Dot == -1) return 0;

    // If Dot is present before At
    if (At > Dot) return 0;

    // If Dot is present at the end
    return !(Dot >= (email.length() - 1));

}


// class of user which will inherent in other classses
class User {
public:
    char name[100];
    char cnic[100];
    char password[100];
    char Email[100];
    char gender[100];
    char adress[100];
    char phonenum[100];

    User() {
        for (int i = 0; i < 100; i++)
        {
            name[i] = '\0';
            cnic[i] = '\0';
            password[i] = '\0';
            Email[i] = '\0';
            gender[i] = '\0';
            adress[i] = '\0';
            phonenum[i] = '\0';

        }
    }


};

// product catalog class 
class product_catalog {
public:

    // public attributes for catalog class
    int product_catagory;
    int sub_catagory;
    char product_name[100];
    char product_unit[100];
    float product_price;

    // default constructor 

    product_catalog()
    {
        product_catagory = 0;
        sub_catagory = 0;
        product_price = 0.0;
        for (int i = 0; i < 100; i++)
        {
            product_name[i] = '\0';
            product_unit[i] = '\0';
        }
    }

    // function to add products to product catalog file by admin  
    void add_product()
    {
        int reenter;
        do {
            cout << "Please enter the product catagories :" << endl;
            cout << "You have following options :" << endl;
            cout << " Press 1 for FOOD\n Press 2 for PERSONAL HYGIENE\n Press 3 for HOUSE HOLD CLEANING :" << endl;
            cin >> product_catagory;

            switch (product_catagory)
            {
            case 1:
            {


                cout << "FOOD" << endl;
                cout << "Enter sub catagories :\nYou have following choices :" << endl;
                cout << "Press 1 for PERISHABLE foods\nPress 2 for NON PERISHABLE FOODS :\n" << endl;
                cin >> sub_catagory;

                // taking input for subcatagory
                switch (sub_catagory)
                {
                case 1:
                {
                    cout << "PERICHABLE :" << endl;


                    char inp;
                    cout << "Do you want to enter records :" << endl;
                    cout << "Press y for yes and press n for no:" << endl;
                    cin >> inp;
                    // condition if you want to enter teh names of products
                    if (inp == 'y')
                    {
                        // loop if admin continuesly want to enter the products
                        while (inp == 'y')
                        {
                            cout << "Plese Enter Product Name :" << endl; cin >> product_name;
                            cout << "Please Enter Product Price :" << endl; cin >> product_price;
                            cout << "Plese Enter product unit :" << endl; cin >> product_unit;

                            write_catalog(Catalog_File, *this);
                            cout << "Do you want to enter more records ?\n If yes then press y:" << endl;
                            cin >> inp;
                        }
                    }
                    // if admin dont want to enter other products 
                    else {
                        int x;
                        cout << "\n\nPress 1 for again go to add product\n press 2 if you want go to main menu :" << endl;
                        cin >> x;
                        if (x == 1)
                        {
                            add_product();
                        }
                        else if (x == 2)
                        {
                            menu();
                        }
                        else {
                            cout << "You are again at main menu :\n" << endl;
                            menu();
                        }
                    }



                    break;
                }
                case 2:
                {

                    cout << "NON PERICHABLE GOODS :" << endl;

                    char inp;
                    cout << "Do you want to enter records :" << endl;
                    cout << "Press y for yes and press n for no:" << endl;
                    cin >> inp;
                    // condition if you want to enter teh names of products
                    if (inp == 'y')
                    {
                        // loop if admin continuesly want to enter the products
                        while (inp == 'y')
                        {
                            cout << "Plese Enter Product Name :" << endl; cin >> product_name;
                            cout << "Please Enter Product Price :" << endl; cin >> product_price;
                            cout << "Plese Enter product unit :" << endl; cin >> product_unit;

                            write_catalog(Catalog_File, *this);
                            cout << "Do you want to enter more records ?\n If yes then press y:" << endl;
                            cin >> inp;
                        }
                    }
                    // if admin dont want to enter other products 
                    else {
                        int x;
                        cout << "\n\nPress 1 for again go to add product\n press 2 if you want go to main menu :" << endl;
                        cin >> x;
                        if (x == 1)
                        {
                            add_product();
                        }
                        else if (x == 2)
                        {
                            menu();
                        }
                        else {
                            cout << "You are again at main menu :\n" << endl;
                            menu();
                        }
                    }

                    break;

                }
                default:
                    break;
                }
                break;

            }
            // case for personal hygiene
            case 2:

            {
                cout << "\nPERSONAL HEGIENE" << endl;
                char inp;
                cout << "Do you want to enter records :" << endl;
                cout << "Press y for yes and press n for no:" << endl;
                cin >> inp;
                // condition if you want to enter teh names of products
                if (inp == 'y')
                {
                    // loop if admin continuesly want to enter the products
                    while (inp == 'y')
                    {
                        cout << "Plese Enter Product Name :" << endl; cin >> product_name;
                        cout << "Please Enter Product Price :" << endl; cin >> product_price;
                        cout << "Plese Enter product unit :" << endl; cin >> product_unit;

                        write_catalog(Catalog_File, *this);
                        cout << "Do you want to enter more records ?\n If yes then press y:" << endl;
                        cin >> inp;
                    }
                }
                // if admin dont want to enter other products 
                else {
                    int x;
                    cout << "\n\nPress 1 for again go to add product\n press 2 if you want go to main menu :" << endl;
                    cin >> x;
                    if (x == 1)
                    {
                        add_product();
                    }
                    else if (x == 2)
                    {
                        menu();
                    }
                    else {
                        cout << "You are again at main menu :\n" << endl;
                        menu();
                    }
                }

                break;
            }
            case 3:
            {
                cout << "HOUSE HOLD CLEANING :" << endl;
                char inp;
                cout << "Do you want to enter records :" << endl;
                cout << "Press y for yes and press n for no:" << endl;
                cin >> inp;
                // condition if you want to enter teh names of products
                if (inp == 'y')
                {
                    // loop if admin continuesly want to enter the products
                    while (inp == 'y')
                    {
                        cout << "Plese Enter Product Name :" << endl; cin >> product_name;
                        cout << "Please Enter Product Price :" << endl; cin >> product_price;
                        cout << "Plese Enter product unit :" << endl; cin >> product_unit;

                        write_catalog(Catalog_File, *this);
                        cout << "Do you want to enter more records ?\n If yes then press y:" << endl;
                        cin >> inp;
                    }
                }
                // if admin dont want to enter other products 
                else {
                    int x;
                    cout << "\n\nPress 1 for again go to add product\n press 2 if you want go to main menu :" << endl;
                    cin >> x;
                    if (x == 1)
                    {
                        add_product();
                    }
                    else if (x == 2)
                    {
                        menu();
                    }
                    else {
                        cout << "You are again at main menu :\n" << endl;
                        menu();
                    }
                }
                break;
            }
            default:
                break;
            }
            cout << "Press 1 to again continue and press other key to exit :" << endl; cin >> reenter;
        } while (reenter == 1);
    }


    // function to view the list of catalog 
    void View_catalog()
    {
        // file to read data
        readData_catalog(Catalog_File);
    }
    // function to update the price of a product: 
    void update_product()
    {
        string nam;
        float nawa;
        cout << "Enter the NAME of product you want to update :" << endl;
        cin >> nam;
        cout << "Enter the new amount :" << endl;
        cin >> nawa;
        update_product(Catalog_File, nam, nawa);
    }
    // first function to remove product
    void remove_product()
    {
        string nam;
        cout << "Following are the products avaialable in cattalog :" << endl;
        // reading data from catalog file
        readData_catalog(Catalog_File);
        cout << "Enter the name of the product you want to remove from the database of store :" << endl;
        cin >> nam;
        delete_product(Catalog_File, nam);
    }
    //helping function to delete product from file
    void delete_product(const string fileName, string name) {
        product_catalog temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (name == temp.product_name) {
                temp.Null(name);
                cout << "The product has been deleted!" << endl;
                return;
            }
        }
        cout << "Wrong Credientials!" << endl;
    }
    // another helping function to shift the data to another file and except the spcific product
    void Null(string C) {  //Delete product from data base

        // const string filename = "catalog.bin";
        product_catalog temp;
        fstream myFile(Catalog_File.c_str(), ios::in | ios::out | ios::binary);
        ofstream myFileTemp("temp.bin", ios::app | ios::binary);
        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (temp.product_name != C) {
                myFileTemp.write((char*)&temp, sizeof(temp));
            }
        }
        myFile.close();
        myFileTemp.close();
        remove(Catalog_File.c_str());
        if (rename("temp.bin", Catalog_File.c_str()) == -1)
        {
            cout << "Unsuccess" << endl;
        }
        else {
            cout << "successful";
        }
        //rename("temp.bin", Catalog_File.c_str());

    }

    // function to write data in file 
    void write_catalog(const string fileName, product_catalog obj)
    {
        ofstream myFile(fileName, ios::binary | ios::app);

        if (myFile.write((char*)&obj, sizeof(obj)))

            cout << "Successfully Inserted!\n\n" << endl;

        else
            cout << "Insertion Failed\n\n" << endl;
        myFile.close();
    }

    void update_product(const string fileName, string name, float new_price) {
        product_catalog temp;
        fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);

        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (name == temp.product_name) {
                temp.product_price = new_price;
                int current = myFile.tellg();
                int one_student_obj = sizeof(temp);
                myFile.seekg(current - one_student_obj);
                myFile.write((char*)&temp, sizeof(temp));
                myFile.close();
            }
        }
    }


    // function to read data from the file of catalog and to display it to the main menu 
    void readData_catalog(const string fileName)
    {
        product_catalog temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp))) {
            switch (temp.product_catagory)
            {
            case 1:
            {
                switch (temp.sub_catagory)
                {

                case 1:
                {
                    cout << "Food" << "\n\t" << "PRESICHABLE GOOD :" << "\n\t" << "Name: " << temp.product_name << "\t\t"
                        << "Price: " << temp.product_price << "\t\t" << "Unit: " << temp.product_unit << "\n" << endl;
                    break;
                }
                case 2:
                {
                    cout << "FOOD\n\t" << "NON PERISHABLE GOODS \n\t";
                    cout << "Name: " << temp.product_name << "\t\t" << "Price: " << temp.product_price << "\t\t" << "Unit: " << temp.product_unit << "\n" << endl;
                    break;
                }

                default:
                    break;

                }
                break;
            }


            case 2:
            {
                cout << "PERSONAL HYGIENE:\n\t";
                cout << "Name: " << temp.product_name << "\t\t" << "Price: " << temp.product_price << "\t\t" << "Unit: " << temp.product_unit << "\n" << endl;
                break;
            }
            case 3:
            {
                cout << "HOUSE HOLD CLEANING:\n\t";
                cout << "Name: " << temp.product_name << "\t\t" << "Price: " << temp.product_price << "\t\t" << "Unit: " << temp.product_unit << "\n" << endl;
                break;
            }
            default:
                break;
            }

        }
    }

};



// class of inventory of two branches
class Inventory {
public:
    product_catalog N;
    char product_name_new[100];
    int quantity_new;
    // karachis inventory function

    void Karachi_store()
    {
        int fun;
        do {
            cout << "\nWelcome to KARACHI store:\n" << endl;
            cout << "Now you have 5 choices :" << endl;
            cout << "Press 1: Add products in inventory :" << endl;
            cout << "Press 2: Updte products in inventory :" << endl;
            cout << "Press 3: Remove products from inventory :" << endl;
            cout << "Press 4: To view inventory :" << endl;
            cout << "Press 5: To search in inventory :" << endl;
            cin >> fun;
        } while (fun > 5);
        switch (fun)
        {
        case 1:
        {
            char y;
            do {
                Add_karachi_inventory();
                cout << "Do you want to add more products :" << endl;
                cout << "If yes, Then press y" << endl;

                cin >> y;
            } while (y == 'y');
            break;
        }
        case 2:
        {
            Update_Karachi_products();

            break;
        }
        case 3:
        {
            remove_karachi_inventory();
        }
        case 4:
        {
            int x;
            cout << "Which stores inventory you want to see :\nPress 1:  for karachi\nPress 2:  for lahore\nPress 3:  for islamabad" << endl;
            cin >> x;
            if (x == 1)
            {
                view_karachi_inventory();
            }
            else if (x == 2)
            {
                view_Lahore_inventory();
            }

            else {
                cout << "You are returning to main function " << endl;
                Karachi_store();
            }
            break;

        }
        case 5:
        {
            int x;
            cout << "In which store you want to search item :" << endl;
            cout << "Press 1:  for karachi\nPress 2:  for lahore" << endl;
            cin >> x;
            if (x == 1)
            {
                search_karachi_inventory();
            }
            else if (x == 2)
            {
                search_lahore_inventory();
            }

            else {
                cout << "You are returning to main function " << endl;
                Karachi_store();
            }
            break;
        }


        }
    }
    // function add inventory in karachi inventory file
    bool found_flag; // a bool variable for seeing that the product is in catalog or not 
    void Add_karachi_inventory()
    {

        string nam;
        N.readData_catalog(Catalog_File);
        cout << "\nNow you can add the any product in inventory from the given catalog :" << endl;
        cout << "Enter the name of product :" << endl;
        cin >> nam;
        searh_product_in_catalog(Catalog_File, nam);
        if (found_flag == true)
        {
            cout << "Product found in catalog file:\n" << endl;
            cout << "Now again enter the product name :" << endl;
            cin >> product_name_new;
            cout << "Enter the quantity :" << endl;
            cin >> quantity_new;

            write_Karachi_inventory(Karachi_Inventory_File, *this);
        }
        else if (found_flag == false) {

            int x;
            cout << "This product is not in the catalog :" << endl;
            cout << "Press 1 if you want to add another thing\nPress 2 if you want to go to main menu :" << endl;
            cin >> x;
            if (x == 1)
            {
                Add_karachi_inventory();
            }
            else if (x == 2)
            {
                menu();
            }
            else {
                cout << "You are returning to main menu :" << endl;
                menu();
            }
        }


    }
    // main function to update the inventory in karachi store

    void Update_Karachi_products()
    {
        string nam;
        int nawa;
        cout << "Enter the NAME of product you want to update :" << endl;
        cin >> nam;
        cout << "Enter the new quantity :" << endl;
        cin >> nawa;
        update_product_inventory(Karachi_Inventory_File, nam, nawa); // calling of a function to update product
    }
    // function to write te data of the karachi inventory
    void  remove_karachi_inventory()
    {
        string nam;
        cout << "Following are the products avaialable in cattalog :" << endl;
        // reading data from karachi file
        readData_inventory(Karachi_Inventory_File);
        cout << "Enter the name of the product you want to remove from the database of store :" << endl;
        cin >> nam;
        delete_product(Karachi_Inventory_File, nam);
    }
    // function to see the invetory file of karachi
    void view_karachi_inventory()
    {
        readData_inventory(Karachi_Inventory_File);
    }
    // function to search the product in the file
    bool found_chk;
    void search_karachi_inventory()
    {
        string pro;
        cout << "Enter the product you want to search :" << endl;
        cin >> pro;
        searh_product_in_inventory(Karachi_Inventory_File, pro);
        if (found_chk == true)
        {
            cout << "Your entered product is in the store :" << endl;
            cout << "You are returning to karachi stores main menu" << endl;
            Karachi_store();
        }
        else if (found_chk == false)
        {
            cout << "This product is not avaolable in store" << endl;
            cout << "You are returning to karachi stores main menu" << endl;
            Karachi_store();
        }


    }
    //helping function to delete product from file
    void delete_product(const string fileName, string name) {
        Inventory temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (name == temp.product_name_new) {
                temp.Null(name);
                cout << "The product has been deleted!" << endl;
                return;
            }
        }
        cout << "Wrong Credientials!" << endl;
    }
    // another helping function to shift the data to another file and except the spcific product
    void Null(string C) {  //Delete product from data base

        // const string filename = "catalog.bin";
        Inventory temp;
        fstream myFile(Catalog_File.c_str(), ios::in | ios::out | ios::binary);
        ofstream myFileTemp("temp.bin", ios::app | ios::binary);
        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (temp.product_name_new != C) {
                myFileTemp.write((char*)&temp, sizeof(temp));
            }
        }
        myFile.close();
        myFileTemp.close();
        remove(Karachi_Inventory_File.c_str());
        rename("temp.bin", Karachi_Inventory_File.c_str());



    }
    void write_Karachi_inventory(const string fileName, Inventory obj)
    {
        ofstream myFile(fileName, ios::binary | ios::app);

        if (myFile.write((char*)&obj, sizeof(obj)))

            cout << "Successfully Inserted!\n\n" << endl;

        else
            cout << "Insertion Failed\n\n" << endl;
        myFile.close();
    }
    void searh_product_in_inventory(const string fileName, string name)
    {
        Inventory temp;
        fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);

        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (name == temp.product_name_new) {

                found_chk = true;
                break;
            }
            else if (name != temp.product_name_new) {

                found_chk = false;
            }

        }  myFile.close();
    }





    // lahore store file 
    void Lahore_store()
    {
        int fun;
        do {
            cout << "\nWelcome to Lahori store:\n" << endl;
            cout << "Now you have 5 choices :" << endl;
            cout << "Press 1: Add products in inventory :" << endl;
            cout << "Press 2: Updte products in inventory :" << endl;
            cout << "Press 3: Remove products from inventory :" << endl;
            cout << "Press 4: To view inventory :" << endl;
            cout << "Press 5: To search in inventory :" << endl;
            cin >> fun;
        } while (fun > 5);
        switch (fun)
        {
        case 1:
        {
            char y;
            do {
                Add_Lahore_inventory();
                cout << "Do you want to add more products :" << endl;
                cout << "If yes, Then press y" << endl;

                cin >> y;
            } while (y == 'y');
            break;
        }
        case 2:
        {
            Update_Lahore_products();

            break;
        }
        case 3:
        {
            remove_Lahore_inventory();
        }
        case 4:
        {
            int x;
            cout << "Which stores inventory you want to see :\nPress 1:  for karachi\nPress 2:  for lahore" << endl;
            cin >> x;
            if (x == 1)
            {
                view_karachi_inventory();
            }
            else if (x == 2)
            {
                view_Lahore_inventory();
            }
            else {
                cout << "You are returning to main function " << endl;
                Lahore_store();
            }
            break;

        }
        case 5:
        {
            int x;
            cout << "In which store you want to search item :" << endl;
            cout << "Press 1:  for karachi\nPress 2:  for lahore" << endl;
            cin >> x;
            if (x == 1)
            {
                search_karachi_inventory();
            }
            else if (x == 2)
            {
                search_lahore_inventory();
            }

            else {
                cout << "You are returning to main function " << endl;
                Lahore_store();
            }
            break;
        }


        }
    }

    // function add inventory in karachi inventory file
    //bool found_flag; // a bool variable for seeing that the product is in catalog or not 
    void Add_Lahore_inventory()
    {

        string nam;
        N.readData_catalog(Catalog_File);
        cout << "\nNow you can add the any product in inventory from the given catalog :" << endl;
        cout << "Enter the name of product :" << endl;
        cin >> nam;
        searh_product_in_catalog(Catalog_File, nam);
        if (found_flag == true)
        {
            cout << "Product found in catalog file:\n" << endl;
            cout << "Now again enter the product name :" << endl;
            cin >> product_name_new;
            cout << "Enter the quantity :" << endl;
            cin >> quantity_new;

            write_Lahore_inventory(Lahore_Inventory_File, *this);
        }
        else if (found_flag == false) {

            int x;
            cout << "This product is not in the catalog :" << endl;
            cout << "Press 1 if you want to add another thing\nPress 2 if you want to go to main menu :" << endl;
            cin >> x;
            if (x == 1)
            {
                Add_Lahore_inventory();
            }
            else if (x == 2)
            {
                menu();
            }
            else {
                cout << "You are returning to main menu :" << endl;
                menu();
            }
        }


    }
    // main function to update the inventory in lahore store

    void Update_Lahore_products()
    {
        string nam;
        int nawa;
        cout << "Enter the NAME of product you want to update :" << endl;
        cin >> nam;
        cout << "Enter the new quantity :" << endl;
        cin >> nawa;
        update_product_inventory(Lahore_Inventory_File, nam, nawa); // calling of a function to update product
    }
    // function to write te data of the lahore inventory
    void  remove_Lahore_inventory()
    {
        string nam;
        cout << "Following are the products avaialable in cattalog :" << endl;
        // reading data from lahore file
        readData_inventory(Lahore_Inventory_File);
        cout << "Enter the name of the product you want to remove from the database of store :" << endl;
        cin >> nam;
        delete_product_lah(Lahore_Inventory_File, nam);
    }
    // function to see the invetory file of karachi
    void view_Lahore_inventory()
    {
        readData_inventory(Lahore_Inventory_File);
    }
    // function to search the product in the file
    //bool found_chk;
    void search_lahore_inventory()
    {
        string pro;
        cout << "Enter the product you want to search :" << endl;
        cin >> pro;
        searh_product_in_inventory_lah(Lahore_Inventory_File, pro);
        if (found_chk == true)
        {
            cout << "Your entered product is in the store :" << endl;
            cout << "You are returning to karachi stores main menu" << endl;
            Lahore_store();
        }
        else if (found_chk == false)
        {
            cout << "This product is not avaolable in store" << endl;
            cout << "You are returning to karachi stores main menu" << endl;
            Lahore_store();
        }


    }

    void delete_product_lah(const string fileName, string name) {
        Inventory temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (name == temp.product_name_new) {
                temp.Null_lah(name);
                cout << "The product has been deleted!" << endl;
                return;
            }
        }
        cout << "Wrong Credientials!" << endl;
    }
    // another helping function to shift the data to another file and except the spcific product
    void Null_lah(string C) {  //Delete product from data base

        // const string filename = "catalog.bin";
        Inventory temp;
        fstream myFile(Lahore_Inventory_File.c_str(), ios::in | ios::out | ios::binary);
        ofstream myFileTemp("temp.bin", ios::app | ios::binary);
        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (temp.product_name_new != C) {
                myFileTemp.write((char*)&temp, sizeof(temp));
            }
        }
        myFile.close();
        myFileTemp.close();
        remove(Lahore_Inventory_File.c_str());
        rename("temp.bin", Catalog_File.c_str());
    }
    void write_Lahore_inventory(const string fileName, Inventory obj)
    {
        ofstream myFile(fileName, ios::binary | ios::app);

        if (myFile.write((char*)&obj, sizeof(obj)))

            cout << "Successfully Inserted!\n\n" << endl;

        else
            cout << "Insertion Failed\n\n" << endl;
        myFile.close();
    }
    void searh_product_in_inventory_lah(const string fileName, string name)
    {
        Inventory temp;
        fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);

        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (name == temp.product_name_new) {

                found_chk = true;
                break;
            }
            else if (name != temp.product_name_new) {

                found_chk = false;
            }

        }  myFile.close();
    }




    // common functions for all cities 

    // function to search that the product manager want to add in inventory is in catalog or not 
    void searh_product_in_catalog(const string fileName, string name)
    {
        product_catalog temp;
        fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);

        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (name == temp.product_name) {

                found_flag = true;
                break;
            }
            else if (name != temp.product_name) {

                found_flag = false;
            }

        }  myFile.close();

    }
    // function to update the product quantity in inventory file
    void update_product_inventory(const string fileName, string name, int new_quantity) {
        Inventory temp;
        fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);

        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (name == temp.product_name_new) {
                temp.quantity_new = new_quantity;
                int current = myFile.tellg();
                int one_student_obj = sizeof(temp);
                myFile.seekg(current - one_student_obj);
                myFile.write((char*)&temp, sizeof(temp));
                myFile.close();
            }
        }
    }

    // function to read data from inventory
    void readData_inventory(const string fileName)
    {
        Inventory temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp))) {

            cout << "\nName of the product :\t" << temp.product_name_new << endl;
            cout << "Quantity of product :\t" << temp.quantity_new << endl;

        }
        myFile.close();
    }

};


class manager :public User {
public:
    char username[100];
    manager()
    {
        for (int i = 0; i < 100; i++)
        {
            username[i] = '\0';
            name[i] = '\0';
            cnic[i] = '\0';
            password[i] = '\0';
            Email[i] = '\0';
            gender[i] = '\0';
            adress[i] = '\0';
            phonenum[i] = '\0';
        }
    }

    // function to check wether the username are correct or not

    bool CheckRepeatD(const string fileName, string uname, string pass) {
        manager temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp)))

            if (uname == username && pass == password) {
                cout << "Welcome Manager! \nYou are logged in " << endl;
                return true;
            }
            else {
                return false;
            }
        return false;

    }

    // function to take inputs for inputs manager 
    void register_manager()
    {
        bool chk;
        cout << "Enter your name :" << endl;
        cin >> name;
        cout << "Enter your UserName " << endl;
        cin >> username;
        do {

            cout << "Please enter your Valid CNIC :" << endl;
            cin >> cnic;
            chk = isValidCNIC(cnic);
        } while (chk != true);
        do {
            cout << "Please enter your correct password :" << endl;
            cin >> password;
            chk = isValid_password(password);
        } while (chk != true);
        string pass;
        do {
            cout << "Please re enter your Valid password :" << endl;
            cin >> pass;

        } while (pass != password);

        do {
            cout << "Please enter your email \n Email should be valid :" << endl;
            cin >> Email;
            chk = is_valid_email(Email);
        } while (chk != true);

        cout << "Enter gender :" << endl;
        cin >> gender;
        cout << "Please enter adress :" << endl;
        cin >> adress;
        cout << "Please enter your phone number " << endl;
        cin >> phonenum;



        chk = CheckRepeatD(Manager_File, cnic);
        if (chk == false)
        {
            int x;
            cout << "There is another account of this CNIC " << endl;
            cout << "Press 1 if you want to register again and press 2 if you want to go to main page :" << endl;
            cin >> x;
            switch (x)
            {
            case 1:
            {
                register_manager();
                break;
            }
            case 2:
            {
                menu();
                break;
            }
            }
        }
        else
        {
            cout << "you are registered :" << endl;
        }




    }

    // function to login the manager 
    void login_manager()
    {
        bool chk;
        cout << "Welcome Sir! :" << endl;
        cout << "Enter your UserName :" << endl;
        cin >> username;
        cout << "Enter your correct password" << endl;
        cin >> password;
        chk = CheckRepeatD(Customer_File, username, password);

        if (chk == false)
        {
            int x;

            cout << "You have entered wrong username or password :" << endl;

            do {
                cout << "Enter 1 if you want to re enter and press 2 if you want  to go to main menu :" << endl;
                cin >> x;
            } while (x != 1 && x != 2);
            switch (x)
            {
            case 1:
            {
                login_manager();
                break;
            }
            case 2:
            {
                menu();
                break;
            }
            }
        }
        else if (chk == true)
        {
            cout << "You are logged in sir " << endl;
            cout << "Press 1: if you want to go to invertory system\n Press 2: if you want to go to main menu:" << endl;
            int x;
            do {
                cin >> x;
            } while (x != 1 && x != 2);
            switch (x)
            {
            case 1:
            {
                Inventory I;
                cout << "Enter your city\nYou have the following options:\nPress 1: For KARACHI\nPress 2: For LAHORE " << endl;
                int city;
                cin >> city;
                switch (city)
                {
                    // case for karachi store call
                case 1:
                {
                    cout << "Store in karachi is assigned to you :" << endl;
                    I.Karachi_store();
                    break;
                }
                // case for lahore store call
                case 2:
                {
                    cout << "Store in Lahore is assigned to you :" << endl;
                    I.Lahore_store();
                    break;
                }



                }
                break;
            }
            case 2:
            {
                menu();
                break;
            }
            }
        }
    }

    // function to write data of manager
    void write_manager(const string fileName, manager obj)
    {
        ofstream myFile(fileName, ios::binary);

        if (myFile.write((char*)&obj, sizeof(obj)))

            cout << "Manager Inserted!\n\n" << endl;

        else
            cout << "Manager Insertion Failed\n\n" << endl;
        myFile.close();
    }
    // function to read data from manager 
    void readData_manager(const string fileName)
    {
        manager temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp))) {

            // temp.display();
            cout << "\n\n";
        }
    }
    // function to check if the manager is already registered or not 
    bool CheckRepeatD(const string fileName, string CNIC) {
        manager temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp)))
            if (CNIC == temp.cnic) {
                cout << "This CNIC already exists!" << endl;
                return false;
            }
        return true;
    }



};


// main class for online shopping and feedback,payment
class online_shopping {
public:
    product_catalog P;
    char Feed_back[200];
    char Name_of_customer[100];
    char product_name_shopping[100];
    int quantity;

    float amount = 0;
    float total_bill = 0;
    bool chk;

    void shopping()
    {
        int x;
        cout << "\nPress 1: If you want online shopping\nPress 2: If you want to go to main menu:" << endl;
        cin >> x;
        if (x == 1)
        {
            cout << "Welcome to online shopping\n" << endl;
            cout << "Please enter the name for our records:" << endl;
            cin >> Name_of_customer;
            do {


                cout << "This is the list of items we have on store :\nYou can choose any thing you want :" << endl;
                P.readData_catalog(Catalog_File);


                cout << "\n\nEnter the name of item you want to buy :" << endl;
                cin >> product_name_shopping;
                cout << "Please enter the quantity if the product :" << endl;
                cin >> quantity;
                search_product_catalog_for_shopping(Catalog_File, product_name_shopping, quantity);


                if (chk == true)
                {
                    total_bill += amount;
                    amount = 0;
                    cout << "\nThe product is added to cart for you\n";
                    write_cart(Cart_file, *this);
                    cout << "Press 1: If you want more shoping :\nPress 2: If you want to see your caat and bill :" << endl;
                    cin >> x;

                }


                else if (chk == false)
                {
                    int z;
                    cout << "Sorry Sir.\nThis product is not available :" << endl;
                    cout << "You should try another one :" << endl;
                    cout << "Press 1: To buy again :\nPress 2: to go to main menu :" << endl;
                    cin >> z;

                    if (z == 1)
                    {
                        shopping();
                    }
                    else if (z == 2)
                    {
                        menu();
                    }
                }
            } while (x == 1);
            if (x == 2)
            {

                cout << "\nYou buy the following items :\n" << endl;
                readData(Cart_file);
                cout << "\n\nYour total bill is :  " << total_bill << endl << endl;
                cout << "Press 1: If you want more shopping\nPress 2 if you want to checkout and pay:" << endl;
                int a;
                cin >> a;
                switch (a)
                {
                case 1:
                {
                    shopping();
                    break;
                }
                case 2:
                {
                    checkout();
                    break;
                }
                }
            }
        }
        else if (x == 2)
        {
            menu();

        }

    }


    void checkout()
    {

        cout << "Thankyou for shopping \n" << endl;
        cout << "Here is your Finalized cart :\n" << endl;
        readData(Cart_file);
        cout << "\nHere's your total bill of shopping :" << endl;
        cout << total_bill;

        shopping_payment();

    }

    // function to search data from the catalog file that the dadta is there or not
    void search_product_catalog_for_shopping(const string fileName, string name, int quantity) {
        product_catalog temp;
        fstream myFile(fileName.c_str(), ios::in | ios::out | ios::binary);

        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (name == temp.product_name) {
                chk = true;
                amount = quantity * temp.product_price;
                break;
            }
            else if (name != temp.product_name) {

                chk = false;
            }

        }  myFile.close();

    }
    // function to write the data in cart
    void write_cart(const string fileName, online_shopping obj)
    {
        ofstream myFile(fileName, ios::binary | ios::app);

        if (myFile.write((char*)&obj, sizeof(obj)))
            cout << "Product Registered!\n\n" << endl;

        else
            cout << "Not registered\n\n" << endl;
        myFile.close();
    }
    // function read the data from customer file
    void readData(const string fileName)
    {
        online_shopping temp;
        ifstream myFile(fileName.c_str());

        //cout << "Order name :\t" << temp.Name_of_customer;
        while (myFile.read((char*)&temp, sizeof(temp))) {

            cout << "The product is :\t" << temp.product_name_shopping << endl;
            cout << "Quantity is :\t" << temp.quantity;
            cout << "\n\n";
        }
    }

    // function for payment
    void shopping_payment()
    {

        int mode;
        do {
            cout << "\n\nAs you are done with shopping :\nIts time for payment:\n" << endl;
            cout << "Please tell us which mode of payment is convinient for you :" << endl;
            cout << "There are 3 modes:\n\nPress 1: For Cash On delivery:\nPress 2: For credit card or Debit card Payment:" << endl;
            cout << "Press 3: For Easy Paisa or Jazz cash" << endl;
            cin >> mode;
        } while (mode >= 3);
        switch (mode)
        {
        case 1:
        {
            int city;

            cout << "Please tell if you are in same city or not :\nPress 1 : For Same city:\nPress 2: For Different City" << endl;
            cin >> city;
            switch (city)
            {
            case 1:
            {
                cout << "Extra charges : 30 " << endl;
                total_bill += 30;
                break;
            }
            case 2:

            {
                cout << "Extra charges : 50 " << endl;
                total_bill += 50;
                break;

            }
            }


            break;
        }
        case 2:
        {
            cout << "\nYou are now paying with Credit Card:\n" << endl;
            break;
        }
        case 3:
        {
            cout << "\nYou are now paying with Jazz Cash:\n" << endl;
            break;
        }
        }
        cout << "Your new bill after extr charges is :\t" << total_bill << endl;

        cout << "\nAs you are done with shopping and payment :\nNow you can add your feedback:\nIt will help us to improve service:" << endl;
        Feed_Back();

    }
    // function to store feed back
    void Feed_Back()
    {
        cout << "\nPlease enter you order name:" << endl;
        cin >> Name_of_customer;
        cout << "Please write your FEEDBACK " << endl;
        cin >> Feed_back;

        // calling cart function to write fee back
        write_feedback(Feedback_file, *this);

    }

    void read_feedback(const string fileName, string name)
    {
        online_shopping temp;
        ifstream myFile(fileName.c_str());

        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (name == temp.Name_of_customer)
            {
                cout << temp.Feed_back;
                cout << "\n\n";
            }


        }

    }


    void write_feedback(const string fileName, online_shopping obj)
    {
        ofstream myFile(fileName, ios::binary | ios::app);

        if (myFile.write((char*)&obj, sizeof(obj)))
            cout << "Product Registered!\n\n" << endl;

        else
            cout << "Not registered\n\n" << endl;
        myFile.close();
    }

    // functions to delete feed back
    void delete_feedback(const string fileName, string name) {
        online_shopping temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (name == temp.Name_of_customer) {
                temp.Null_feed(name);
                cout << "The feedback has been deleted!" << endl;
                return;
            }
        }
        cout << "Wrong Credientials!" << endl;
    }
    // another helping function to shift the data to another file and except the spcific product
    void Null_feed(string C) {  //Delete product from data base

        // const string filename = "catalog.bin";
        online_shopping temp;
        fstream myFile(Lahore_Inventory_File.c_str(), ios::in | ios::out | ios::binary);
        ofstream myFileTemp("temp.bin", ios::app | ios::binary);
        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (temp.Name_of_customer != C) {
                myFileTemp.write((char*)&temp, sizeof(temp));
            }
        }
        myFile.close();
        myFileTemp.close();
        remove(Lahore_Inventory_File.c_str());
        rename("temp.bin", Catalog_File.c_str());
    }


};





// admin class
class Admin :public User {
public:

    char username[100];


    Admin(string UName = "Hadeed06", string name = "Hadeed", string cnic = "03211004409", string Pass = "Wisdom123", string gender = "Male", string Adress = "G-13", string Email = "hadeedrauf@gmail.com")
    {

        strcpy_s(this->username, UName.c_str());
        strcpy_s(this->name, name.c_str());
        strcpy_s(this->cnic, cnic.c_str());
        strcpy_s(this->password, Pass.c_str());
        strcpy_s(this->Email, Email.c_str());

        strcpy_s(this->gender, gender.c_str());

        strcpy_s(this->adress, Adress.c_str());
    }

    void display()
    {
        cout << "User name  " << username << endl;
        cout << "Nmae is   :" << name << endl;
        cout << "CNIC is :" << cnic << endl;
        cout << "password is :" << password << endl;
        cout << "Email is " << Email << endl;
        cout << "Gender is " << gender << endl;
        cout << "Phone number is " << gender << endl;

    }
    // function to write  the data of ADMIN
    void write_Admin(const string fileName, Admin obj)
    {
        ofstream myFile(fileName, ios::binary);

        if (myFile.write((char*)&obj, sizeof(obj)))

            cout << "Accountant Successfully Inserted!\n\n" << endl;

        else
            cout << "Accountant Insertion Failed\n\n" << endl;
        myFile.close();
    }

    // function to check that the admin is valid or not 
    bool CheckRepeatD(const string fileName, string uname, string pass) {
        Admin temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp)))

            if (uname == username && pass == password) {
                cout << "Welcome Admin! \n You are logged in " << endl;
                return true;
            }
            else {
                return false;
            }

    }

    // takiing the input for admin login
    void input_admin()
    {
        bool check;
        string un, pa;
        cout << "Enter user name :" << endl;
        cin >> un;
        cout << "Enter password :" << endl;
        cin >> pa;
        check = CheckRepeatD(Admin_file, un, pa);
        if (check == false)
        {
            int z;
            cout << "You entered wrong username or password :" << endl;
            cout << "Press 1 if you want to login again and 2 if you want to go to main menu again :" << endl;
            cin >> z;
            switch (z)
            {
            case 1:
            {
                input_admin();
                break;
            }
            case 2:
            {
                menu();
                break;
            }
            }
        }
        else if (check == true)
        {
            // system to register manager 
            int x;
            cout << "You are logged in \n\n:" << endl;

            online_shopping O;
            cout << "Press 1: To register a manager:\nPress 2: To enter in Product catalog system" << endl;
            cout << "\nFEED_BACK\n\nPress 3: To view any Feed Back\nPress 4: To Delete Feed Back:" << endl;
            cin >> x;

            switch (x)
            {
            case 1:
            {
                manager m;
                m.register_manager();
                m.write_manager(Manager_File, m);
                m.readData_manager(Manager_File);
                break;
            }
            case 2:
            {
                product_catalog  P;
                int y;
                cout << "Welcome to product catalog :\n press1 if you want add product\n press 2 if you want to view catalog\n press 3 if you want to remove product\n press 4 if you want update any product" << endl;
                cin >> y;
                switch (y)
                {
                case 1:
                {
                    P.add_product();
                    break;
                }
                case 2:
                {
                    P.View_catalog();
                    break;

                }
                case 3:
                {
                    P.remove_product();
                    break;
                }
                case 4:
                {
                    P.update_product();
                    break;
                }

                }
                break;
            }
            // case to view feed back
            case 3:
            {
                string name;
                cout << "Please enter Name of Customer:" << endl;
                cin >> name;
                O.read_feedback(Feedback_file, name);
                break;
            }
            // case to delete feed_back
            case 4:
            {
                string nam;
                cout << "Enter Name of customer :" << endl;
                cin >> nam;
                O.delete_feedback(Feedback_file, nam);
                break;
            }

            }
        }
    }

};







class customer :public User {
public:
    char username[100];
    // constructor

    customer() {
        for (int i = 0; i < 100; i++)
        {
            username[i] = '\0';
            name[i] = '\0';
            cnic[i] = '\0';
            password[i] = '\0';
            Email[i] = '\0';
            gender[i] = '\0';
            adress[i] = '\0';
            phonenum[i] = '\0';
        }
    }

    // function to check wether the login info of the customer is correct or not 
    bool CheckRepeatD(const string fileName, string uname, string pass) {
        customer temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp)))

            if (uname == username && pass == password) {
                cout << "Welcome customer! \n You are logged in " << endl;
                return true;
            }
            else {
                return false;
            }
        return false;

    }


    // an input function to take the customers data 
    void input_customer()
    {
        bool chk;
        cout << "Enter your name :";
        cin >> name;
        cout << "Enter your UserName :";
        cin >> username;
        do {

            cout << "Please enter your Valid CNIC :"; cin >> username;

            chk = isValidCNIC(cnic);
           // chk = true;
        } while (chk != true);
        do {
            cout << "Please enter your correct password :";
            cin >> password;
            chk = isValid_password(password);
        } while (chk != true);
        string pass;
        do {
            cout << "Please re enter your Valid password :";
            cin >> pass;

        } while (pass != password);

        do {
            cout << "Please enter your email \n Email should be valid :";
            cin >> Email;
            chk = is_valid_email(Email);
        } while (chk != true);

        cout << "Enter gender :";
        cin >> gender;
        cout << "Please enter adress :";
        cin >> adress;
        cout << "Please enter your phone number ";
        cin >> phonenum;

        chk = CheckRepeatD(Customer_File, cnic);
        if (chk == false)
        {
            int x;
            cout << "There is another account of this CNIC " << endl;
            cout << "Press 1 if you want to register again and press 2 if you want to go to main page :" << endl;
            cin >> x;
            switch (x)
            {
            case 1:
            {
                input_customer();
                break;
            }
            case 2:
            {
                menu();
                break;
            }
            }
        }
        else {
            cout << "you are registered :" << endl;
        }

    }

    // function to login the customer
    void login_customer()
    {
        bool chk;
        cout << "Welcome Sir! :" << endl;
        cout << "Enter your UserName :";
        cin >> username;
        cout << "Enter your correct password";
        cin >> password;
        chk = CheckRepeatD(Customer_File, username, password);

        if (chk == false)
        {
            int x;
            cout << "You have entered wrong username or password :" << endl;
            cout << "Enter 1 if you want to re enter and press 2 if you want  to go to main menu :" << endl;
            cin >> x;
            switch (x)
            {
            case 1:
            {
                login_customer();
                break;
            }
            case 2:
            {
                menu();
                break;
            }
            }
        }
        else if (chk == true)
        {
            online_shopping O;
            cout << "You are logged in sir \n" << endl;

            // now we will impliment onlone shooping things here
            cout << "Press 1:  If you want to go for some online shooping" << endl;
            cout << "press 2:  If you want to go to main menu" << endl;
            int kela;
            cin >> kela;
            if (kela == 1)
            {
                O.shopping();
            }
            if (kela == 2)
            {
                cout << "You are going to main menu\n\n" << endl;
                menu();
            }
        }


    }

    // display function
    void display()
    {
        cout << "Nmae is   :" << name << endl;
        cout << "CNIC is :" << cnic << endl;
        cout << "password is :" << password << endl;
        cout << "Email is " << Email << endl;
        cout << "Gender is " << gender << endl;
        cout << "Phone number is " << gender << endl;
    }
    // function to write the data of customer in the file
    void write_customer(const string fileName, customer obj)
    {
        ofstream myFile(fileName, ios::binary | ios::app);

        if (myFile.write((char*)&obj, sizeof(obj)))

            cout << "Accountant Successfully Inserted!\n\n" << endl;

        else
            cout << "Accountant Insertion Failed\n\n" << endl;
        myFile.close();
    }

    // function read the data from customer file
    void readData(const string fileName)
    {
        customer temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp))) {

            temp.display();
            cout << "\n\n";
        }
    }
    //Function to check if customer is already in the file or not
    bool CheckRepeatD(const string fileName, string CNIC) {
        customer temp;
        ifstream myFile(fileName.c_str());
        while (myFile.read((char*)&temp, sizeof(temp)))
            if (CNIC == temp.cnic) {
                cout << "This CNIC already exists!" << endl;
                return false;
            }
        return true;
    }

};




void menu()
{
    // objects //
    Admin a;
    customer c;
    manager n;
    //        //
    int i;
    cout << "WELCOME TO THE STORE " << endl;
    cout << endl;

    cout << "Press 1: To login as Admin :\nPress 2: To Register as Customer :\nPress 3: To login as customer \nPress 4: To login as Manager \n If you want to register as manager you have to consult with the admin : " << endl;
    cin >> i;

    switch (i)
    {
    case 1:
    {

        a.input_admin();
        a.write_Admin(Admin_file, a);


        break;
    }
    case 2:
    {
        c.input_customer();
        c.write_customer(Customer_File, c);
        c.readData(Customer_File);
        break;

    }
    case 3:
    {
        c.login_customer();
        break;
    }
    case 4:
    {
        n.login_manager();
        break;
    }

    }
}

int main()
{
    menu();
    int x;
    cout << "Press 1: To Run progran again\nPress 0: To EXIT:" << endl;
    cin >> x;
    if (x == 1)
    {
        menu();
    }
    else {
        exit(0);
    }
}