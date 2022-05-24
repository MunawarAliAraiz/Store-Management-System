#include<iostream>
#include<conio.h>
#include<iomanip>
#include<sstream>
#include<string>
#include<string.h>
#include<fstream>

using namespace std;

/*                                      ||------------ALL FUNCTIONS DECLARATION-----------||                      */

//For Stoping and Clearing Screen
void hault();

//To convert Name to Uppercase
void convert(string& name);

//Menu Functions Declarations
int MainMenu();
int AdminMenu();
int ManagerMenu();
int SalesmanMenu();
int StorekeeperMenu();

//Initialization Functions Declaration
void initializeManager(string Mandata[][10], string ManNamesList[], int ManAgeList[], int ManExpList[], string ManQualList[], string ManMobNoList[] , string ManIDList[], int ManSalaryList[], string ManUsernameList[], string ManPasswordList[], string ManRegNoList[], int MAX_Manager);
void initializeSalesman(string SalManData[][12], string SalManNamesList[], int SalManAgeList[], int SalManExpList[], string SalManQualList[], string SalMobNoList[] , string SalManIDList[], int SalManSalaryList[], int SalManBonusList[], string SalManUsernameList[], string SalManPasswordList[], string SalManRegNoList[], int SalManSales[], int MAX_Salesman);
void initializeStorekeeper(string StrkprData[][11], string StrkprNamesList[], int StrkprAgeList[], int StrkprExpList[], string StrkprQualList[], string StrkprMobNoList[] , string StrkprIDList[], int StrkprSalaryList[], int StrkprBonusList[], string StrkprUsernameList[], string StrkprPasswordList[], string StrkprRegNoList[], int StrkprSales[], int MAX_Storekeeper);
void initializeProducts(string PdData[][6], string PdNamesList[], string PdIDList[], int PdPriceList[], int PdQtyList[], int PDSale[], int PDSaleQty[], int MAX_Products);

//Validation Functions For All
bool isValidIDCardNumber(string ID);
bool isValidName(string name);
bool isValidMobNo(string MobNo);
bool isValidUsername(string Username);
bool isValidPassword(string Password);

//Validation Functions of Manager
bool isValidManAge(int Age);
bool isValidManExp(int Exp);
bool isValidManQual(string Qual);
bool isValidManRegNo(string RegNo);
bool validateManData(string Name, int Age, int Exp, string Qual, string MobNo, string ID);

//Validation Functions of Salesman
bool isValidSalManAge(int Age);
bool isValidSalManExp(int Exp);
bool isValidSalManQual(string Qual);
bool isValidSalManRegNo(string RegNo);
bool validateSalManData(string Name, int Age, int Exp, string Qual, string MobNo, string ID);

//Validation Functions of Storekeeper
bool isValidStrkprAge(int Age);
bool isValidStrkprQual(string Qual);
bool isValidStrkprRegNo(string RegNo);
bool validateStrkprData(string Name, int Age, string Qual, string MobNo, string ID);

//Validation Function of Products
bool isValidProductID(string PdID);
bool validatePdData(string Name, string PdID);

//LOGIN FUNCTIONS
bool UserExist(string UsernameList[], string PasswordList[], int size);
bool UserLogin(string UsernameList[], string PasswordList[], string Username, string Password, int size);
int UserIndex(string UsernameList[], string PasswordList[], string Username, string Password, int size);
bool ProductExist(string PdnamesList[], string PdIDList[], int size);

//Fuction For Index Finder
int searchID(string IDList[], int size, string ID);
int searchRegNo(string RegNoList[], int size, string RegNo);
void StrRegNo(string IDList[], int size, string ID, string RegNoList[]);
int highest_score(int UserManSale[], int size);
int lowest_score(int UserSale[], int size);

//DATA FUNCTIONS
void ManagerData(string ManData[][10],string ManNamesList[], int ManAgeList[], int ManExpList[], string ManQualList[], string ManMobNoList[], int ManSalaryList[], string ManIDList[], string ManRegNoList[], string ManUsernameList[] , string ManPasswordList[], int size);
void SalesmanData(string SalManData[][12] ,string SalManNamesList[], int SalManAgeList[], int SalManExpList[], string SalManQualList[], string SalManMobNoList[], string SalManIDList[], int SalManSalaryList[], string SalManRegNoList[], int SalManBonusList[], string SalManUsernameList[] , string SalManPasswordList[], int SalManSales[],int size);
void StorekeeperData(string StrkprData[][11] ,string StrkprNamesList[], int StrkprAgeList[], string StrkprQualList[], string StrkprMobNoList[], string StrkprIDList[], int StrkprSalaryList[], string StrkprRegNoList[], int StrkprBonusList[], string StrkprUsernameList[] , string StrkprPasswordList[], int StrkprSales[],int size);
void ProductsData(string PdData[][6],string PdNamesList[], string PdIDList[], int PdPriceList[] ,int PdQtyList[], int PDSale[], int PDSaleQty[], int size);

//MANAGEMENT FUNCTIONS
bool AddManager(string ManNamesList[], int ManAgeList[], int ManExpList[], string ManQualList[], string ManMobNoList[] , string ManIDList[], int ManSalaryList[], string ManUsernameList[] , string ManPasswordList[] , string Name, int Age, int Exp, string Qual,  string MobNo , string ID, int Salary, string Username, string Password, int size);
bool RemoveManager(string ManData[][10], string ManNamesList[], int ManAgeList[], int ManExpList[], string ManQualList[], string ManMobNoList[], string ManIDList[], int ManSalaryList[], string ManUsernameList[], string ManPasswordList[], string ManRegNoList[], string RegNo, int size);
bool AddSalesman(string SalManNamesList[], int SalManAgeList[], int SalManExpList[], string SalManQualList[], string SalManMobNoList[] , string SalManIDList[],  int SalManSalaryList[], string SalManUsernameList[] , string SalManPasswordList[], int SalManBonusList[], int SalManSales[] ,string Name, int Age, int Exp, string Qual,  string MobNo , string ID, int Salary, string Username, string Password, int size);
bool RemoveSalesman(string SalManData[][12], string SalManNamesList[], int SalManAgeList[], int SalManExpList[], string SalManQualList[], string SalManMobNoList[], string SalManIDList[], int SalManSalaryList[], string SalManUsernameList[], string SalManPasswordList[], string SalManRegNoList[], int SalManBonusList[], string RegNo, int SalManSales[], int size);
bool AddStorekeeper(string StrkprNamesList[], int StrkprAgeList[], string StrkprQualList[], string StrkprMobNoList[] , string StrkprIDList[],  int StrkprSalaryList[], string StrkprUsernameList[] , string StrkprPasswordList[] , int StrkprBonusList[], int StrkprSales[] ,string Name, int Age, string Qual,  string MobNo , string ID, int Salary, string Username, string Password, int size);
bool RemoveStorekeeper(string StrkprData[][11], string StrkprNamesList[], int StrkprAgeList[], string StrkprQualList[], string StrkprMobNoList[], string StrkprIDList[], int StrkprSalaryList[], string StrkprUsernameList[], string StrkprPasswordList[], string StrkprRegNoList[], int StrkprBonusList[], string RegNo, int StrkprSales[] ,int size);
bool StrSalaryUpdate(string Salary[][11], int SalaryList[],string RegNoList[],string RegNo, int size);
bool ManSalaryUpdate(string Salary[][10], int SalaryList[],string RegNoList[],string RegNo, int size);
bool SalSalaryUpdate(string Salary[][12] ,int SalaryList[],string RegNoList[],string RegNo, int size);
void totalSales(string SalManData[][12],int SalManSales[],int size);
void SalemanSales(string SalManData[][12], string SalManRegNoList[],int size);
bool SalGiveBonus(string bonus[][12], int BonusList[], string RegNoList[],string RegNo, int size);
bool StrGiveBonus(string bonus[][11], int BonusList[], string RegNoList[],string RegNo, int size);
void MaxSale(string PdData[][6], string PdIDList[], string PdID, int PdPriceList[], int PdQty, int size, int PDSale[], int PDSaleQty[]);

//BILL FUNCTION
int bill(string PdNamesList[],string PdIDList[], string PdID, int PdPriceList[], int PdSaleQty, int size);

//PRODUCT FUNCTIONS
bool AddProduct(string PdNamesList[], string PdIDList[], int PdPriceList[], int PdQtyList[] ,int PdQty, string PdName, string PdID, int PdPrice, int MAX_Products);
bool RemoveProduct(string PdData[][6], string PdNamesList[], string PdIDList[], int PdPriceList[], int PdQtyList[], string PdID, int size);
bool ProductUpdate(string PdData[][6], int PdPriceList[],string PdIDList[],string PdID, int MAX_Products);
bool SaleProduct(string PdData[][6], string PdNamesList[], string PdIDList[] , int PdQtyList[], string PdID, int PdQty, int size);
bool ReturnProduct(string PdData[][6], string PdNamesList[], string PdIDList[] , int PdQtyList[], string PdID, int PdQty, int size);

//ALL VIEW FUNCTIONS
void viewAllProducts(string PdData[][6], string PdIDList[], int size);
void ViewManager(string ManData[][10], string ManRegNoList[], int size);
void ViewSalesman(string SalManData[][12], string SalManRegNoList[], int size);
void ViewStorekeeper(string StrkprData[][11], string StrkprRegNoList[], int size);
void ViewLoginDetails(string ManData[][10],string SalManData[][12],string Strkpr[][11], int size1, int size2, int size3);

//USERNAME & PASSWORD CHANGE
void changeUserPass(string UsernameList[], string PasswordList[], string RegNoList[], string Username, string Password ,string RegNo, int size);

//SAVE & LOAD FUNCTIONS
bool SaveManager(string ManData[][10], string ManRegNoList[], int size);
bool SaveSalesman(string SalManData[][12], string SalManRegNoList[], int size);
bool SaveStorekeeper(string StrkprData[][11], string StrkprRegNoList[], int size);
bool SaveProducts(string PdData[][6], string PdIDList[], int size);
bool loadUser(string& auser, string& apass);
bool loadManager(string ManData[][10],string ManNamesList[], int ManAgeList[], int ManExpList[], string ManQualList[], string ManMobNoList[], int ManSalaryList[], string ManIDList[], string ManRegNoList[], string ManUsernameList[] , string ManPasswordList[], int size);
bool loadSalesman(string SalManData[][12] ,string SalManNamesList[], int SalManAgeList[], int SalManExpList[], string SalManQualList[], string SalManMobNoList[], string SalManIDList[], int SalManSalaryList[], string SalManRegNoList[], int SalManBonusList[], string SalManUsernameList[] , string SalManPasswordList[], int SalManSales[], int size);
bool loadStorekeeper(string StrkprData[][11] ,string StrkprNamesList[], int StrkprAgeList[], string StrkprQualList[], string StrkprMobNoList[], string StrkprIDList[], int StrkprSalaryList[], string StrkprRegNoList[], int StrkprBonusList[], string StrkprUsernameList[] , string StrkprPasswordList[], int StrkprSales[],int size);
bool loadProducts(string PdData[][6],string PdNamesList[], string PdIDList[], int PdPriceList[] ,int PdQtyList[], int PDSale[], int PDSaleQty[], int size);


int main()
{
    //Max Size of All Arrays
    int MAX_Manager = 3;
    int MAX_Salesman = 10;
    int MAX_Storekeeper = 8;
    int MAX_Products = 30;

    //Declaration of All Variables
    string Name;
    string Qual;
    string ID;
    string MobNo;
    string Username;
    string Password;
    string RegNo;
    string PdName;
    string PdID;
    string auser;
    string apass;
    int Age;
    int Exp;
    int Salary;
    int PdPrice;
    int PdQty;

    //Declaration of All Arrays of Manager
    string ManData[MAX_Manager][10], ManNamesList[MAX_Manager], ManQualList[MAX_Manager], ManIDList[MAX_Manager], ManMobNoList[MAX_Manager] ,ManUsernameList[MAX_Manager], ManPasswordList[MAX_Manager], ManRegNoList[MAX_Manager];
    int  ManAgeList[MAX_Manager], ManExpList[MAX_Manager], ManSalaryList[MAX_Manager];

    //Declaration of All Arrays of Salesman
    string SalManData[MAX_Salesman][12], SalManNamesList[MAX_Salesman], SalManQualList[MAX_Salesman], SalManIDList[MAX_Salesman], SalManMobNoList[MAX_Salesman] , SalManUsernameList[MAX_Salesman], SalManPasswordList[MAX_Salesman], SalManRegNoList[MAX_Salesman];
    int  SalManAgeList[MAX_Salesman], SalManExpList[MAX_Salesman], SalManSalaryList[MAX_Salesman], SalManBonusList[MAX_Salesman], SalManSales[MAX_Salesman];

    //Declaration of All Arrays of Storekeeper
    string StrkprData[MAX_Storekeeper][11], StrkprNamesList[MAX_Storekeeper], StrkprQualList[MAX_Storekeeper], StrkprIDList[MAX_Storekeeper], StrkprMobNoList[MAX_Storekeeper] , StrkprUsernameList[MAX_Storekeeper], StrkprPasswordList[MAX_Storekeeper], StrkprRegNoList[MAX_Storekeeper];
    int  StrkprAgeList[MAX_Storekeeper], StrkprExpList[MAX_Storekeeper], StrkprSalaryList[MAX_Storekeeper], StrkprBonusList[MAX_Storekeeper], StrkprSales[MAX_Storekeeper];

    //Declaration of All Arrays of Products
    string PdData[MAX_Products][6], PdNamesList[MAX_Products], PdIDList[MAX_Products];
    int PdPriceList[MAX_Products], PdQtyList[MAX_Products], PDSale[MAX_Products], PDSaleQty[MAX_Products];

    //Initialize All Arrays
    initializeManager(ManData, ManNamesList, ManAgeList, ManExpList, ManQualList, ManMobNoList, ManIDList, ManSalaryList, ManUsernameList, ManPasswordList, ManRegNoList,MAX_Manager);
    initializeSalesman(SalManData, SalManNamesList, SalManAgeList, SalManExpList, SalManQualList, SalManMobNoList, SalManIDList, SalManSalaryList, SalManBonusList, SalManUsernameList, SalManPasswordList, SalManRegNoList, SalManSales, MAX_Salesman);
    initializeStorekeeper(StrkprData, StrkprNamesList, StrkprAgeList, StrkprExpList, StrkprQualList, StrkprMobNoList, StrkprIDList, StrkprSalaryList, StrkprBonusList, StrkprUsernameList, StrkprPasswordList, StrkprRegNoList, StrkprSales, MAX_Storekeeper);
    initializeProducts(PdData, PdNamesList, PdIDList, PdPriceList, PdQtyList, PDSale, PDSaleQty, MAX_Products);

    //Load ALL DATA
    loadManager(ManData ,ManNamesList, ManAgeList, ManExpList, ManQualList, ManMobNoList, ManSalaryList, ManIDList, ManRegNoList, ManUsernameList, ManPasswordList, MAX_Manager);
    loadSalesman(SalManData ,SalManNamesList, SalManAgeList, SalManExpList, SalManQualList, SalManMobNoList, SalManIDList, SalManSalaryList, SalManRegNoList, SalManBonusList, SalManUsernameList, SalManPasswordList, SalManSales, MAX_Salesman);
    loadStorekeeper(StrkprData , StrkprNamesList, StrkprAgeList, StrkprQualList, StrkprMobNoList, StrkprIDList, StrkprSalaryList, StrkprRegNoList, StrkprBonusList, StrkprUsernameList, StrkprPasswordList, StrkprSales, MAX_Storekeeper);
    loadProducts(PdData, PdNamesList, PdIDList, PdPriceList, PdQtyList, PDSale, PDSaleQty, MAX_Products);
    if(loadUser(auser, apass)==false)
    {
        return 1;
    }
    start:
    int x;
    x = MainMenu();
    if(x==1)
    {
        string username = " ",password = " ";
        int admin;
        char a;
        while(username != auser || password != apass)
        {
            system("CLS");
            cout << "\t\t\t||***__ENTER YOUR CREDENTIALS__***||\n\n";
            cout << "\t\t\tENTER USERNAME: ";
            cin >> username;
            cout << "\t\t\tENTER PASSWORD: ";
            cin >> password;
            if(username != auser || password != apass)
            {
                cout << "\n\t\t\tINVALID DETAILS\n";
                cout << "\n\t\t\tDO YOU WANT TO GO BACK TO MAIN MENU (Y/N): ";
                cin >> a;
                if(a == 'Y' || a == 'y')
                {
                    goto start;
                }
                hault();
            }
        }
        do
        {
            admin=AdminMenu();
            switch (admin)
            {
            case 1:
                system("CLS");
                cout << "\t\t||***-Enter details of the Manager--***||\n\n";
                cout << "\t\tEnter Manager Name: ";
                cin.ignore();
                getline(cin,Name);
                convert(Name);
                cout << "\n\t\tEnter Age of Manager: ";
                cin >> Age;
                cout << "\n\t\tEnter Years of Experience: ";
                cin >> Exp;
                cout << "\n\t\tEnter Your Qualification['MAT'  (FOR MATRICULATION)\t'UG'  (For UnderGraduate)\t'GA'  (For Graduate)\t'PG'  (For Post Graduate)]: ";
                cin >> Qual;
                convert(Qual);
                cout << "\n\t\tEnter National ID card No. of Manager With Dashes: ";
                cin >> ID;
                cout << "\n\t\tEnter Mobile Number of Manager (e.g 0321-0000000): ";
                cin >> MobNo;
                if(validateManData(Name, Age, Exp, Qual, MobNo, ID))
                {
                    cout << "\n\n\t\tALL THE DETAILS YOU ENTERED IS VALID\n";
                    cout << "\t\tAdd Salary for Manager\n\t\tRS.";
                    cin >> Salary;
                    cout << "\n\t\tADD USERNAME AND PASSWORD FOR THIS MANAGER ACCOUNT TO LOGIN VIA MANAGER\n";
                    short stop;
                    do
                    {
                        stop = 0;
                        cout << "\t\tEnter Username:";
                        cin.ignore();
                        getline(cin,Username);
                        cout << "\n\t\tEnter password:";
                        cin.ignore();
                        getline(cin,Password);
                        if(isValidUsername(Username) && isValidPassword(Password))
                        {
                            stop = 1;
                            hault();
                        }
                    } while (stop == 0);
                    
                    if(AddManager(ManNamesList, ManAgeList, ManExpList, ManQualList, ManMobNoList, ManIDList, ManSalaryList, ManUsernameList, ManPasswordList, Name, Age, Exp, Qual, MobNo, ID, Salary, Username, Password, MAX_Manager))
                    {
                        cout << "\t\tManager Successfully added\n" << endl;
                        StrRegNo(ManIDList, MAX_Manager, ID, ManRegNoList);
                        hault();
                        ManagerData(ManData, ManNamesList, ManAgeList, ManExpList, ManQualList, ManMobNoList, ManSalaryList, ManIDList, ManRegNoList, ManUsernameList , ManPasswordList, MAX_Manager);
                    }
                    else
                    {
                        cout << "\t\t\tSorry No space to add new Manager\n" << endl;
                        hault();
                    }
                }
                else
                {
                    //If any validity is false it will not add the Manager
                    cout << "\t\tINVALID DETAILS\n" << endl;
                    hault();
                }
                break;
            case 2:
               cout << "\n\t\tEnter Store Registration Number of Manager To Remove: ";
                cin >> RegNo;
                 if (isValidManRegNo(RegNo))
                {
                    //call function to Remove the Manager detail which has same Registration Number as user enter
                    if (RemoveManager(ManData, ManNamesList, ManAgeList, ManExpList, ManQualList, ManMobNoList, ManIDList, ManSalaryList, ManUsernameList, ManPasswordList, ManRegNoList, RegNo, MAX_Manager))
                    {
                        cout << "\t\tManager Removed Successfully \n" << endl;
                        hault();
                    }
                    else
                    {
                        cout << "\t\tSorry No Manager found\n " << endl;
                        hault();
                    }
                }
                else
                {
                    //if Store Registration no. is invalid then this message will show
                    cout << "\t\tINVALID STORE REGISTARTION NUMBER\n" << endl;
                    hault();
                }
                break;
            case 3:
                cout << "\t\tEnter Store Registration Number of Manager To Update Salary: ";
                cin >> RegNo;
                 if (isValidManRegNo(RegNo))
                {
                    //call function to update the Manager salary which has same Registration Number as user enter
                    if (ManSalaryUpdate(ManData,ManSalaryList, ManRegNoList, RegNo, MAX_Manager))
                    {
                        cout << "\n\t\tManager Salary Updated Successfully\n " << endl;
                        hault();
                    }
                    else
                    {
                        cout << "\n\t\tSorry No Manager found " << endl;
                        hault();
                    }
                }
                else
                {
                    //if Store Registration no. is invalid then this message will show
                    cout << "\t\tINVALID STORE REGISTARTION NUMBER\n" << endl;
                    hault();
                }
                break;
            case 4:
                system("CLS");
                cout << "\t\t||***-Enter details of the Salesman--***||\n\n";
                cout << "\t\tEnter Salesman Name: ";
                cin.ignore();
                getline(cin,Name);
                convert(Name);
                cout << "\n\t\tEnter Age of Salesman: ";
                cin >> Age;
                cout << "\n\t\tEnter Years of Experience: ";
                cin >> Exp;
                cout << "\n\t\tEnter Your Qualification['MAT'  (FOR MATRICULATION)\t'UG'  (For UnderGraduate)\t'GA'  (For Graduate)\t'PG'  (For Post Graduate)]: ";
                cin >> Qual;
                convert(Qual);
                cout << "\n\t\tEnter National ID card No. of Salesman With Dashes: ";
                cin >> ID;
                cout << "\n\t\tEnter Mobile Number of Salesman (e.g 0321-0000000): ";
                cin >> MobNo;
                if(validateSalManData(Name, Age, Exp, Qual, MobNo, ID))
                {
                    cout << "\n\t\t\tALL THE DETAILS YOU ENTERED IS VALID\n\n";
                    cout << "\t\tAdd Salary for Salesman\n\t\tRS.";
                    cin >> Salary;
                    cout << "\n\t\tADD USERNAME AND PASSWORD FOR THIS SALESMAN ACCOUNT TO LOGIN VIA SALESMAN\n";
                    short stop;
                    do
                    {
                        stop = 0;
                        cout << "\t\tEnter Username:";
                        cin.ignore();
                        getline(cin,Username);
                        cout << "\n\t\tEnter password:";
                        cin.ignore();
                        getline(cin,Password);
                        if(isValidUsername(Username) && isValidPassword(Password))
                        {
                            stop = 1;
                            hault();
                        }
                    } while (stop == 0);

                        if(AddSalesman(SalManNamesList, SalManAgeList, SalManExpList, SalManQualList, SalManMobNoList, SalManIDList, SalManSalaryList, SalManUsernameList, SalManPasswordList, SalManBonusList, SalManSales, Name, Age, Exp, Qual, MobNo, ID, Salary, Username, Password, MAX_Salesman))
                        {
                            cout << "\t\t\tSalesman Successfully added\n" << endl;
                            StrRegNo(SalManIDList, MAX_Salesman, ID, SalManRegNoList);
                            hault();
                            SalesmanData(SalManData, SalManNamesList, SalManAgeList, SalManExpList, SalManQualList, SalManMobNoList, SalManIDList, SalManSalaryList, SalManRegNoList, SalManBonusList, SalManUsernameList , SalManPasswordList, SalManSales, MAX_Salesman);
                        }
                        else
                        {
                            cout << "\t\t\tSorry No space to add new Salesman\n" << endl;
                            hault();
                        }
                }
                else
                {
                    //If any validity is false it will not add the salesman
                    cout << "\n\t\t\tInvalid details\n" << endl;
                    hault();
                }
                break;
            case 5:
                system("CLS");
                cout << "\t\t||***-Enter details of the Storekeeper--***||\n\n";
                cout << "\t\tEnter Storekeeper Name: ";
                cin.ignore();
                getline(cin,Name);
                convert(Name);
                cout << "\n\t\tEnter Age of Manager: ";
                cin >> Age;
                cout << "\n\t\tEnter Your Qualification['MAT'  (FOR MATRICULATION)\t'UG'  (For UnderGraduate)\t'GA'  (For Graduate)\t'PG'  (For Post Graduate)]: ";
                cin >> Qual;
                convert(Qual);
                cout << "\n\t\tEnter National ID card No. of Storekeeper With Dashes: ";
                cin >> ID;
                cout << "\n\t\tEnter Mobile Number of Storekeeper (e.g 0321-0000000): ";
                cin >> MobNo;
                if(validateStrkprData(Name, Age, Qual, MobNo, ID))
                {
                    cout << "\n\n\t\tALL THE DETAILS YOU ENTERED IS VALID\n\n";
                    cout << "\t\tAdd Salary for Storekeeper\n\t\tRS.";
                    cin >> Salary;
                    short stop;
                    do
                    {
                        stop = 0;
                        cout << "\t\tEnter Username:";
                        cin.ignore();
                        getline(cin,Username);
                        cout << "\n\t\tEnter password:";
                        cin.ignore();
                        getline(cin,Password);
                        if(isValidUsername(Username) && isValidPassword(Password))
                        {
                            stop = 1;
                            hault();
                        }
                    }while (stop == 0);

                        if(AddStorekeeper(StrkprNamesList, StrkprAgeList, StrkprQualList, StrkprMobNoList, StrkprIDList, StrkprSalaryList, StrkprUsernameList, StrkprPasswordList, StrkprBonusList , StrkprSales , Name, Age, Qual, MobNo, ID, Salary, Username, Password, MAX_Storekeeper))
                        {
                            cout << "\t\tStorekeeper Successfully added\n" << endl;
                            StrRegNo(StrkprIDList, MAX_Storekeeper, ID, StrkprRegNoList);
                            hault();
                            StorekeeperData(StrkprData, StrkprNamesList, StrkprAgeList, StrkprQualList, StrkprMobNoList, StrkprIDList, StrkprSalaryList, StrkprRegNoList, StrkprBonusList, StrkprUsernameList , StrkprPasswordList, StrkprSales, MAX_Storekeeper);
                        }
                        else
                        {
                            cout << "\t\tSorry No space to add new Storekeeper\n" << endl;
                            hault();
                        }
                    
                }
                else
                {
                    //If any validity is false it will not add the storekeeper
                    cout << "\n\t\tInvalid details\n" << endl;
                    hault();
                }
                break;
            case 6:
                
                SalemanSales(SalManData, SalManRegNoList,MAX_Salesman);
                hault();

            break;
            case 7:
                
                totalSales(SalManData,SalManSales,MAX_Salesman);
                hault();

                break;
            case 8:
                if(UserExist(SalManUsernameList, SalManPasswordList, MAX_Salesman))
                {
                    ViewSalesman(SalManData, SalManRegNoList, MAX_Salesman);
                }
                else
                {
                    cout << "\n\t\t\tNO SALESMAN FOUND";
                }
                hault();

                break;
            case 9:
                if(UserExist(StrkprUsernameList, StrkprPasswordList, MAX_Storekeeper))
                {
                    ViewStorekeeper(StrkprData, StrkprRegNoList, MAX_Storekeeper);
                }
                else
                {
                    cout << "\n\t\t\tNO STOREKEEPER FOUND";
                }
                hault();

                break;
            case 10:

                if(UserExist(ManUsernameList, ManPasswordList, MAX_Manager))
                {
                    ViewManager(ManData, ManRegNoList, MAX_Manager);
                }
                else
                {
                    cout << "\n\t\t\tNO MANAGERS FOUND";
                }
                hault();

                break;
            case 11:

                ViewLoginDetails(ManData, SalManData, StrkprData, MAX_Manager, MAX_Salesman, MAX_Storekeeper);
                hault();

                break;
            case 12:
                    if(ProductExist(PdNamesList,PdIDList,MAX_Products) == true)
                    {
                        viewAllProducts(PdData,PdIDList, MAX_Products);
                    }
                    else
                    {
                        cout << "\n\t\t\tNO PRODUCT HAVE BEEN ADDED";
                    }
                    
                    hault();
                break;

            case 13:
                if(UserExist(SalManUsernameList, SalManPasswordList, MAX_Salesman) == true)
                {
                int highestIndex;
                highestIndex = highest_score(SalManSales, MAX_Salesman);
                cout << endl;
                cout<<"\n\t\t\tHIGHEST Sale is "<< SalManSales[highestIndex]<<" and is of "<<SalManNamesList[highestIndex];

                int lowestIndex;
                lowestIndex = lowest_score(SalManSales, MAX_Salesman);
                cout << endl;
                cout<<"\n\t\t\tLOWEST Sale is "<< SalManSales[lowestIndex]<<" and is of "<<SalManNamesList[lowestIndex];
                hault();
                }
                else
                {
                    cout << "\n\t\t\tNO SALESMAN HAVE BEEN ADDED";
                    hault();
                }

                break;

            case 14:

                if(ProductExist(PdNamesList, PdIDList, MAX_Products) == true)
                {
                int highestIndex;
                highestIndex = highest_score(PDSale, MAX_Products);
                cout << endl;
                cout <<"\n\t\t\t\t||***--- HIGHEST SALE ---***||\n";
                cout <<"\n\t\t\tPRODUCT NAME --> "<< PdNamesList[highestIndex];
                cout <<"\n\t\t\tNO OF PRODUCT SOLD  --> "<< PDSaleQty[highestIndex];
                cout <<"\n\t\t\tPRODUCT PRICE --> "<< PdPriceList[highestIndex];
                cout <<"\n\t\t\tTOTAL SALE --> "<< PDSale[highestIndex];

                int lowestIndex;
                lowestIndex = lowest_score(PDSale, MAX_Products);
                cout << endl;
                cout <<"\n\t\t\t\t||***--- LOWEST SALE ---***||\n";
                cout <<"\n\t\t\tPRODUCT NAME --> "<< PdNamesList[lowestIndex];
                cout <<"\n\t\t\tNO OF PRODUCT SOLD  --> "<< PDSaleQty[lowestIndex];
                cout <<"\n\t\t\tPRODUCT PRICE --> "<< PdPriceList[lowestIndex];
                cout <<"\n\t\t\tTOTAL SALE --> "<< PDSale[lowestIndex];
                hault();
                }
                else
                {
                    cout << "\n\t\t\tNO PRODUCT HAVE BEEN ADDED";
                    hault();
                }

                break;
            case 15:
                goto start;
                break;
            case 16:
                cout << "\t\t\t\tTHANK YOU! FOR USING THE PROGRAM";
                if (SaveManager(ManData, ManRegNoList, MAX_Manager) && SaveSalesman(SalManData, SalManRegNoList, MAX_Salesman) && SaveStorekeeper(StrkprData, StrkprRegNoList, MAX_Storekeeper) && SaveProducts(PdData,PdIDList, MAX_Products))
                {
                    cout << "\n\n\t\t\tAll Data Saved successfully" << endl;
                }
                else
                {
                    cout << "\n\n\t\t\tAll data you entered is lost due to some error" << endl;
                }
                cout << "\n\n\t\t\t\t||****--- PROGRAM CLOSED ---****|| ";
                hault();
                break;
        
            default:
                cout << "\t\t\tINVALID CHOICE\n";
                hault();
                break;
            }
        }while(admin!=16);
    }
    else if(x==2)
    {
        ManStart:
        int manager;
        string username,password;
        char a;
        system("CLS");
        if(UserExist(ManUsernameList,ManPasswordList,MAX_Manager) != true)
        {
            cout << "\n\t\tNO MANAGERS FOUND!\n";
            cout << "\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            getch();
            goto start;
        }
        cout << "\t\t\t||***__ENTER YOUR CREDENTIALS__***||\n\n";
        cout << "\t\t\tENTER USERNAME: ";
        cin >> username;
        cout << "\t\t\tENTER PASSWORD: ";
        cin >> password;
        while (UserLogin(ManUsernameList,ManPasswordList,username,password,MAX_Manager) != true)
        {
            cout << "\n\t\t\tINVALID DETAILS\n";
            cout << "\n\t\t\tDO YOU WANT TO GO BACK TO MAIN MENU (Y/N): ";
            cin >> a;
            if(a == 'Y' || a == 'y')
            {
                goto start;
            }
            hault();
            goto ManStart;
        }
        
        do
        {
            manager=ManagerMenu();
            switch (manager)
            {
            case 1:
            
                cout << "\t\tEnter Store Registration Number of Salesman To Give Bonus: ";
                cin >> RegNo;
                 if (isValidSalManRegNo(RegNo))
                {
                    //call function to Remove the Manager detail which has same Registration Number as user enter
                    if (SalGiveBonus(SalManData, SalManBonusList, SalManRegNoList, RegNo, MAX_Salesman))
                    {
                        cout << "\n\t\tBonus is given to Salesman Successfully \n" << endl;
                        hault();
                    }
                    else
                    {
                        cout << "\n\t\tSorry No Salesman found " << endl;
                        hault();
                    }
                }
                else
                {
                    //if Store Registration no. is invalid then this message will show
                    cout << "\n\t\tINVALID STORE REGISTARTION NUMBER\n" << endl;
                    hault();
                }
                
                break;
            case 2:
                cout << "\t\tEnter Store Registration Number of Salesman To Remove: ";
                cin >> RegNo;
                 if (isValidSalManRegNo(RegNo))
                {
                    //call function to Remove the Manager detail which has same Registration Number as user enter
                    if (RemoveSalesman(SalManData, SalManNamesList, SalManAgeList, SalManExpList, SalManQualList, SalManMobNoList, SalManIDList, SalManSalaryList, SalManUsernameList, SalManPasswordList, SalManRegNoList, SalManBonusList, RegNo, SalManSales, MAX_Salesman))
                    {
                        cout << "\n\t\tSalesman Removed Successfully \n" << endl;
                        hault();
                    }
                    else
                    {
                        cout << "\n\t\tSorry No Salesman found " << endl;
                        hault();
                    }
                }
                else
                {
                    //if Store Registration no. is invalid then this message will show
                    cout << "\n\t\tINVALID STORE REGISTARTION NUMBER\n" << endl;
                    hault();
                }
                break;
            case 3:
                
                cout << "\t\tEnter Store Registration Number of Storekeeper To Give Bonus: ";
                cin >> RegNo;
                 if (isValidStrkprRegNo(RegNo))
                {
                    //call function to Remove the Manager detail which has same Registration Number as user enter
                    if (StrGiveBonus(StrkprData, StrkprBonusList,StrkprRegNoList, RegNo, MAX_Storekeeper))
                    {
                        cout << "\n\t\tBonus is given to Storekeeper Successfully \n" << endl;
                        hault();
                    }
                    else
                    {
                        cout << "\n\t\tSorry No Storekeeper found " << endl;
                        hault();
                    }
                }
                else
                {
                    //if Store Registration no. is invalid then this message will show
                    cout << "\n\t\tINVALID STORE REGISTARTION NUMBER\n" << endl;
                    hault();
                }

                break;
            case 4:
                cout << "\t\tEnter Store Registration Number of Storekeeper To Remove: ";
                cin >> RegNo;
                 if (isValidStrkprRegNo(RegNo))
                {
                    //call function to Remove the Manager detail which has same Registration Number as user enter
                    if (RemoveStorekeeper(StrkprData,StrkprNamesList, StrkprAgeList, StrkprQualList, StrkprMobNoList, StrkprIDList, StrkprSalaryList, StrkprUsernameList, StrkprPasswordList, StrkprRegNoList, StrkprBonusList, RegNo, StrkprSales,MAX_Storekeeper))
                    {
                        cout << "\n\t\tStorekeeper Removed Successfully " << endl;
                        hault();
                    }
                    else
                    {
                        cout << "\n\t\tSorry No Storekeeper found " << endl;
                        hault();
                    }
                }
                else
                {
                    //if Store Registration no. is invalid then this message will show
                    cout << "\n\t\tINVALID STORE REGISTARTION NUMBER\n" << endl;
                    hault();
                }
                break;
            case 5:
                cout << "\n\t\tEnter Store Registration Number of Salesman To Update Salary: ";
                cin >> RegNo;
                 if (isValidSalManRegNo(RegNo))
                {
                    //call function to update the Salesman salary which has same Registration Number as user enter
                    if (SalSalaryUpdate(SalManData, SalManSalaryList, SalManRegNoList, RegNo, MAX_Salesman))
                    {
                        cout << "\n\t\tSalesman Salary Updated Successfully " << endl;
                        hault();
                    }
                    else
                    {
                        cout << "\n\t\tSorry No Salesman found " << endl;
                        hault();
                    }
                }
                else
                {
                    //if Store Registration no. is invalid then this message will show
                    cout << "\n\t\tINVALID STORE REGISTARTION NUMBER\n" << endl;
                    hault();
                }
                break;
            case 6:
                cout << "\n\t\tEnter Store Registration Number of Storekeeper To Update Salary: ";
                cin >> RegNo;
                 if (isValidStrkprRegNo(RegNo))
                {
                    //call function to update the Manager salary which has same Registration Number as user enter
                    if (StrSalaryUpdate(StrkprData, StrkprSalaryList, StrkprRegNoList, RegNo, MAX_Storekeeper))
                    {
                        cout << "\n\t\tStorekeeper Salary Updated Successfully " << endl;
                        hault();
                    }
                    else
                    {
                        cout << "\n\t\tSorry No Storekeeper found " << endl;
                        hault();
                    }
                }
                else
                {
                    //if Store Registration no. is invalid then this message will show
                    cout << "\n\t\tINVALID STORE REGISTARTION NUMBER\n" << endl;
                    hault();
                }
                break;
            case 7:
                
                SalemanSales(SalManData, SalManRegNoList,MAX_Salesman);
                hault();

                break;
            case 8:
                
                totalSales(SalManData,SalManSales,MAX_Salesman);
                hault();

                break;
            case 9:
                ViewSalesman(SalManData, SalManRegNoList, MAX_Salesman);
                hault();
                break;
            case 10:
                ViewStorekeeper(StrkprData, StrkprRegNoList, MAX_Storekeeper);
                hault();
                break;
            case 11:
                    viewAllProducts(PdData, PdIDList, MAX_Products);
                    hault();
                break;
            case 12:

                if(UserExist(StrkprUsernameList, StrkprPasswordList, MAX_Storekeeper) == true)
                {
                int highestIndex;
                highestIndex = highest_score(SalManSales, MAX_Salesman);
                cout << endl;
                cout<<"\n\t\tHIGHEST Sale is "<< SalManSales[highestIndex]<<" and is of "<<SalManNamesList[highestIndex]<<".\n";

                int lowestIndex;
                lowestIndex = lowest_score(SalManSales, MAX_Salesman);
                cout << endl;
                cout<<"\n\t\tLOWEST Sale is "<< SalManSales[lowestIndex]<<" and is of "<<SalManNamesList[lowestIndex]<<".\n";
                hault();
                }
                else
                {
                    cout << "\n\t\tNO SALESMAN HAVE BEEN ADDED";
                    hault();
                }
                break;

            case 13:

                if(ProductExist(PdNamesList, PdIDList, MAX_Products) == true)
                {
                int highestIndex;
                highestIndex = highest_score(PDSale, MAX_Products);
                cout << endl;
                cout <<"\n\t\t\t\t||***--- HIGHEST SALE ---***||\n";
                cout <<"\n\t\tPRODUCT NAME --> "<< PdNamesList[highestIndex] <<endl;
                cout <<"\n\t\tNO OF PRODUCT SOLD  --> "<< PDSaleQty[highestIndex] <<endl;
                cout <<"\n\t\tPRODUCT PRICE --> "<< PdPriceList[highestIndex] <<endl;
                cout <<"\n\t\tTOTAL SALE --> "<< PDSale[highestIndex] <<endl;

                int lowestIndex;
                lowestIndex = lowest_score(PDSale, MAX_Products);
                cout << endl;
                cout <<"\n\t\t\t\t||***--- LOWEST SALE ---***||\n";
                cout <<"\n\t\tPRODUCT NAME --> "<< PdNamesList[lowestIndex] <<endl;
                cout <<"\n\t\tNO OF PRODUCT SOLD  --> "<< PDSaleQty[lowestIndex] <<endl;
                cout <<"\n\t\tPRODUCT PRICE --> "<< PdPriceList[lowestIndex] <<endl;
                cout <<"\n\t\tTOTAL SALE --> "<< PDSale[lowestIndex] <<endl;
                hault();
                }
                else
                {
                    cout << "\n\t\tNO PRODUCT HAVE BEEN ADDED";
                    hault();
                }

            break;

            case 14:
        
                cout << "\n\t\tEnter your Registration Number To Change Username & Password: ";
                cin >> RegNo;
                if(isValidManRegNo(RegNo))
                {
                    if(searchRegNo(ManRegNoList , MAX_Manager, RegNo) != -1)
                    {
                        cout << "\n\t\tENTER YOUR USERNAME & PASSWORD TO VERIFY\n";
                        cout << "\t\tENTER YOUR OLD USERNAME: ";
                        cin >> Username;
                        cout << "\t\tENTER YOUR OLD PASSWORD: ";
                        cin >> Password;
                        changeUserPass(ManUsernameList, ManPasswordList, ManRegNoList, Username, Password, RegNo, MAX_Manager);
                    }
                    else
                    {
                        cout << "\n\t\tNO USER FOUND\n";
                        hault();
                    }
                    
                }
                else
                {
                    cout << "\n\t\tINVALID STORE REGISTRATION NUMBER\n";
                    hault();
                }
                
                break;

            case 15:

                goto start;
                break;

            case 16:

                cout << "\t\t\t\tTHANK YOU! FOR USING THE PROGRAM";
                if (SaveManager(ManData, ManRegNoList, MAX_Manager) && SaveSalesman(SalManData, SalManRegNoList, MAX_Salesman) && SaveStorekeeper(StrkprData, StrkprRegNoList, MAX_Storekeeper) && SaveProducts(PdData,PdIDList, MAX_Products))
                {
                    cout << "\n\n\t\t\tAll Data Saved successfully" << endl;
                }
                else
                {
                    cout << "\n\n\t\t\tAll data you entered is lost due to some error" << endl;
                }
                cout << "\n\n\t\t\t\t||****--- PROGRAM CLOSED ---****|| ";
                hault();

            default:

                cout << "\t\t\t\tINVALID CHOICE\n";
                break;

            }
        } while (manager!=16);
        
    }
    else if(x==3)
    {
        
        SalesmanStart:
        int salesman;
        string username,password;
        char a;
        system("CLS");
        if(UserExist(SalManUsernameList, SalManPasswordList, MAX_Salesman) != true)
        {
            cout << "\n\t\tNO SALESMAN FOUND! \n";
            cout << "\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            getch();
            goto start;
        }
        cout << "\t\t\t||***__ENTER YOUR CREDENTIALS__***||\n\n";
        cout << "\t\t\tENTER USERNAME: ";
        cin >> username;
        cout << "\t\t\tENTER PASSWORD: ";
        cin >> password;
        while (UserLogin(SalManUsernameList, SalManPasswordList, username, password, MAX_Salesman) != true)
        {
            cout << "\n\t\t\tINVALID DETAILS\n";
            cout << "\n\t\t\tDO YOU WANT TO GO BACK TO MAIN MENU (Y/N): ";
            cin >> a;
            if(a == 'Y' || a == 'y')
            {
                goto start;
            }
            hault();
            goto SalesmanStart;
        }

        int index = UserIndex(SalManUsernameList, SalManPasswordList, username, password, MAX_Salesman) ;

        do
        {
            PdStart:
            salesman=SalesmanMenu();
             switch (salesman)
            {
            case 1:
                if(ProductExist(PdNamesList, PdIDList, MAX_Products) != true)
                {
                    cout << "\n\t\tNO PRODUCT FOUND! \n";
                    cout << "\t\tPRESS ANY KEY TO GO BACK TO PREVIOUS MENU\n";
                    getch();
                    goto PdStart;
                }
                viewAllProducts(PdData,PdIDList, MAX_Products);
                int salebill;
                cout << "\t\tENTER THE PRODUCT ID OF PRODUCT TO SELL: ";
                cin >> PdID;
                if(isValidProductID(PdID))
                {
                    cout << "\t\tENTER THE QUANTITY OF PRODUCT: ";
                    cin >> PdQty;
                    if(SaleProduct(PdData,PdNamesList, PdIDList, PdQtyList, PdID, PdQty, MAX_Products))
                    {
                        stringstream SS;
                        MaxSale(PdData,PdIDList, PdID, PdPriceList,PdQty,MAX_Products, PDSale ,PDSaleQty);
                        salebill = bill(PdNamesList,PdIDList, PdID, PdPriceList, PdQty, MAX_Products);
                        SalManSales[index] = SalManSales[index] + salebill;
                        SS << SalManSales[index];
                        SalManData[index][11] = SS.str();
                        hault();
                    }
                }
                else
                {
                    cout << "\n\t\tINVALID PRODUCT ID\n";
                    hault();
                }
                break;

            case 2:
                if(UserExist(PdNamesList, PdIDList, MAX_Products) != true)
                {
                    cout << "\n\t\tNO PRODUCT FOUND! \n";
                    cout << "\t\tPRESS ANY KEY TO GO BACK TO PREVIOUS MENU\n";
                    getch();
                    goto PdStart;
                }
                 viewAllProducts(PdData, PdIDList, MAX_Products);
                int salebills;
                cout << "\t\tENTER THE PRODUCT ID OF PRODUCT TO RETURN: ";
                cin >> PdID;
                if(isValidProductID(PdID))
                {
                    cout << "\t\tENTER THE QUANTITY OF PRODUCT TO RETURN: ";
                    cin >> PdQty;
                    if(ReturnProduct(PdData,PdNamesList, PdIDList, PdQtyList, PdID, PdQty, MAX_Products))
                    {
                        salebills = bill(PdNamesList, PdIDList, PdID, PdPriceList, PdQty, MAX_Products);
                        cout << "\n\n\t\t***---PRODUCT HAS BEEN RETURNED---***\n\t\tYOUR RETURNED PRICE IS " << salebills << endl;
                        hault();
                    }
                }
                else
                {
                    cout << "\n\t\tINVALID PRODUCT ID\n";
                }

                break;
            case 3:
                if(UserExist(PdNamesList, PdIDList, MAX_Products) != true)
                {
                    cout << "\n\t\tNO PRODUCT FOUND! \n";
                    cout << "\t\tPRESS ANY KEY TO GO BACK TO PREVIOUS MENU\n";
                    getch();
                    goto PdStart;
                }
                viewAllProducts(PdData, PdIDList, MAX_Products);
                hault();

                break;
            case 4:
                
                cout << "\n\t\tYOUR TOTAL SALES TILL NOW IS" << SalManSales[index] << endl;
                hault();

                break;
            case 5:
                
                cout << "\n\t\tYOUR BONUS IS " << SalManBonusList[index] << endl;
                hault();

                break;
            case 6:
                
                cout << "\n\t\tEnter your Registration Number To Change Username & Password: ";
                cin >> RegNo;
                if(isValidSalManRegNo(RegNo))
                {
                    if(searchRegNo(SalManRegNoList , MAX_Salesman, RegNo) != -1)
                    {
                        cout << "\n\t\tENTER YOUR USERNAME & PASSWORD TO VERIFY\n";
                        cout << "\t\tENTER YOUR OLD USERNAME: ";
                        cin >> Username;
                        cout << "\t\tENTER YOUR OLD PASSWORD: ";
                        cin >> Password;
                        changeUserPass(SalManUsernameList, SalManPasswordList, SalManRegNoList, Username, Password, RegNo, MAX_Salesman);
                    }
                    else
                    {
                        cout << "\n\t\t\tNO USER FOUND\n";
                        hault();
                    }
                    
                }
                else
                {
                    cout << "\n\t\t\tINVALID STORE REGISTRATION NUMBER\n";
                    hault();
                }

                break;
            case 7:

                goto start;
                break;

            case 8:

                cout << "\t\t\t\tTHANK YOU! FOR USING THE PROGRAM";
                if (SaveManager(ManData, ManRegNoList, MAX_Manager) && SaveSalesman(SalManData, SalManRegNoList, MAX_Salesman) && SaveStorekeeper(StrkprData, StrkprRegNoList, MAX_Storekeeper) && SaveProducts(PdData,PdIDList, MAX_Products))
                {
                    cout << "\n\n\t\t\tAll Data Saved successfully" << endl;
                }
                else
                {
                    cout << "\n\n\t\t\tAll data you entered is lost due to some error" << endl;
                }
                cout << "\n\n\t\t\t\t||****--- PROGRAM CLOSED ---****|| ";
                hault();
                break;
        
            default:

                cout << "\t\t\tINVALID CHOICE\n";
                hault();
                break;

            }
        } while (salesman!=8);
        
    }
    else if(x==4)
    {
        StorekeeperStart:
        int stockman;
        string username,password;
        char a;
        system("CLS");
        if(UserExist(StrkprUsernameList, StrkprPasswordList, MAX_Storekeeper) != true)
        {
            cout << "\n\t\tNO STOREKEEPER FOUND!\n";
            cout << "\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            getch();
            goto start;
        }
        cout << "\t\t\t||***__ENTER YOUR CREDENTIALS__***||\n\n";
        cout << "\t\t\tENTER USERNAME: ";
        cin >> username;
        cout << "\t\t\tENTER PASSWORD: ";
        cin >> password;
        while (UserLogin(StrkprUsernameList, StrkprPasswordList, username, password, MAX_Storekeeper) != true)
        {
            cout << "\n\t\t\tINVALID DETAILS\n";
            cout << "\n\t\t\tDO YOU WANT TO GO BACK TO MAIN MENU (Y/N): ";
            cin >> a;
            if(a == 'Y' || a == 'y')
            {
                goto start;
            }
            hault();
            goto StorekeeperStart;
        }

        int index = UserIndex(StrkprUsernameList, StrkprPasswordList, username, password, MAX_Storekeeper) ;
        do
        {
            stockman=StorekeeperMenu();

            switch (stockman)
            {
            //Case for Product Add
            case 1:

                cout << "\n\t\tEnter Product Name: ";
                cin.ignore();
                getline(cin,PdName);
                convert(PdName);
                cout << "\t\tEnter Product ID(3 capital character & 2 integers) :";
                cin >> PdID;
                cout << "\t\tEnter Product Price: ";
                cin >> PdPrice;
                cout << "\t\tEnter Product Quantity: ";
                cin >> PdQty;
                //Check validity of all inputs
                if(validatePdData(PdName, PdID))
                {
                    //Call AddProduct function
                    if(AddProduct(PdNamesList, PdIDList, PdPriceList, PdQtyList, PdQty, PdName, PdID, PdPrice, MAX_Products))
                    {
                        cout <<"\n\t\tProduct Added Sucessfuly\n";
                        ProductsData(PdData, PdNamesList, PdIDList, PdPriceList , PdQtyList, PDSale, PDSaleQty, MAX_Products);
                        stringstream ss;
                        StrkprSales[index] = StrkprSales[index] + 1;
                        ss << StrkprSales[index];
                        StrkprData[index][10] = ss.str();
                        hault();
                    }
                    else
                    {
                        cout << "\n\t\t\tNo space to Add new Product\n";
                        hault();
                    } 
                }
                else
                {
                    //If any validity is false it will not add the Product
                    cout << "\n\t\t\tInvalid details\n";
                    hault();
                }
                
                break;

            case 2:

                 cout << "\n\t\tEnter the Product ID Number To Remove: ";
                 cin >> PdID;
                 if (isValidProductID(PdID))
                {
                    //call function to Remove the Product detail which has same Product ID Number as user enter
                    if (RemoveProduct(PdData,PdNamesList, PdIDList, PdPriceList, PdQtyList, PdID, MAX_Products))
                    {
                        cout << "\n\t\t\tProduct Removed Successfully \n" << endl;
                        hault();
                    }
                    else
                    {
                        cout << "\n\t\t\tSorry No Product found \n" << endl;
                        hault();
                    }
                }
                else
                {
                    //if Product ID no. is invalid then this message will show
                    cout << "\n\t\t\tINVALID STORE PRODUCT ID NUMBER\n" << endl;
                    hault();
                }
                break;

            case 3:

                    viewAllProducts(PdData, PdIDList, MAX_Products);
                    hault();
                    break;

            case 4:
                
                cout << "\n\t\t\tTHE NUMBER OF PRODUCTS YOU ENTERED ARE " << StrkprSales[index] << endl;
                hault();

                break;
            case 5:
                
                cout << "\n\t\t\tYOUR BONUS IS " << StrkprBonusList[index] << endl;
                hault();

                break;
            case 6:

                cout << "\n\t\t\tEnter ID Number of Product To Update Product Price: ";
                cin >> PdID;
                 if (isValidProductID(PdID))
                {
                    //call function to update the Manager salary which has same Registration Number as user enter
                    if (ProductUpdate(PdData,PdPriceList, PdIDList, PdID, MAX_Products))
                    {
                        cout << "\n\t\t\tProduct Price Updated Successfully " << endl;
                        hault();
                    }
                    else
                    {
                        cout << "\n\t\t\tSorry No Product found " << endl;
                        hault();
                    }
                }
                else
                {
                    //if Store Registration no. is invalid then this message will show
                    cout << "\n\t\t\tINVALID STORE REGISTARTION NUMBER\n" << endl;
                    hault();
                }
            break;

            case 7:
                
                cout << "\n\t\t\tEnter your Registration Number To Change Username & Password: ";
                cin >> RegNo;
                if(isValidStrkprRegNo(RegNo))
                {
                    if(searchRegNo(StrkprRegNoList , MAX_Storekeeper, RegNo) != -1)
                    {
                        cout << "\n\t\t\tENTER YOUR USERNAME & PASSWORD TO VERIFY\n";
                        cout << "\t\t\tENTER YOUR OLD USERNAME: ";
                        cin >> Username;
                        cout << "\t\t\tENTER YOUR OLD PASSWORD: ";
                        cin >> Password;
                        changeUserPass(StrkprUsernameList, StrkprPasswordList, StrkprRegNoList, Username, Password, RegNo, MAX_Storekeeper);
                    }
                    else
                    {
                        cout << "\n\t\t\tNO USER FOUND\n";
                        hault();
                    }
                    
                }
                else
                {
                    cout << "\n\t\t\tINVALID STORE REGISTRATION NUMBER\n";
                    hault();
                }

            break;
            case 8:

                goto start;
                break;

            case 9:
                
                cout << "\t\t\t\tTHANK YOU! FOR USING THE PROGRAM";
                if (SaveManager(ManData, ManRegNoList, MAX_Manager) && SaveSalesman(SalManData, SalManRegNoList, MAX_Salesman) && SaveStorekeeper(StrkprData, StrkprRegNoList, MAX_Storekeeper) && SaveProducts(PdData,PdIDList, MAX_Products))
                {
                    cout << "\n\n\t\t\tAll Data Saved successfully" << endl;
                }
                else
                {
                    cout << "\n\n\t\t\tAll data you entered is lost due to some error" << endl;
                }
                cout << "\n\n\t\t\t\t||****--- PROGRAM CLOSED ---****|| ";
                hault();

            default:

                cout << "\t\t\tINVALID CHOICE\n";
                hault();
                break;
            }
        } while (stockman!=9);
        
    }
    else if (x == 5)
    {
        if (SaveManager(ManData, ManRegNoList, MAX_Manager) && SaveSalesman(SalManData, SalManRegNoList, MAX_Salesman) && SaveStorekeeper(StrkprData, StrkprRegNoList, MAX_Storekeeper) && SaveProducts(PdData,PdIDList, MAX_Products))
        {
            cout << "\n\n\t\t\t\tAll Data Saved successfully" << endl;
        }
        else
        {
            cout << "\n\n\t\t\t\tAll data you entered is lost due to some error" << endl;
        }
        hault();
        goto start;
    }
    
    else if(x == 0)
    {
        cout << "\t\t\t\tTHANK YOU! FOR USING THE PROGRAM";
        if (SaveManager(ManData, ManRegNoList, MAX_Manager) && SaveSalesman(SalManData, SalManRegNoList, MAX_Salesman) && SaveStorekeeper(StrkprData, StrkprRegNoList, MAX_Storekeeper) && SaveProducts(PdData,PdIDList, MAX_Products))
        {
            cout << "\n\n\t\t\t\tAll Data Saved successfully" << endl;
        }
        else
        {
            cout << "\n\n\t\t\t\tAll data you entered is lost due to some error" << endl;
        }
        cout << "\n\n\t\t\t\t||****--- PROGRAM CLOSED ---****|| ";
        hault();
    }
    else
    {
        cout << "\n\n\t\t\tINVALID CHOICE!";
        hault();
        goto start;
    }
    
  return 0;
}

/*                                      ||------------ALL FUNCTIONS DEFINATIONS-----------||                      */

//Function for Clearing Console Screen
void hault()
{
    cout << "\n\t\t\tPress any key to Continue......\n";
    getch();
    system("CLS");
}

//To convert Name to Uppercase
void convert(string& name)
{
    for(int i=0;i<name.length();i++)
    name[i] = towupper(name[i]);
}

//Main MENU
int MainMenu()
{
    int a;
    system("CLS");
    cout << "\t\t--------------------------------------------------------------------\n"
            "\t\t\t***** WELCOME TO SUPERMARKET SYSTEM MANAGEMENT *****\n"
            "\t\t--------------------------------------------------------------------\n\n"
            "\t\t\t\t\t||--  MAIN MENU  --||\n\n"
            "\t\t\t\t1. LOGIN AS ADMINISTRATIVE\n"
            "\t\t\t\t2. LOGIN AS MANAGER\n"
            "\t\t\t\t3. LOGIN AS SALESMAN\n"
            "\t\t\t\t4. LOGIN AS STOREKEEPER\n"
            "\t\t\t\t5. TO SAVE ALL DATA\n"
            "\t\t\t\t0. TO CLOSE THE PROGRAM\n\n"
            "\t\t\t\tENTER YOUR OPTION: ";
    cin >> a;
    return a;
}

//Admin MENU
int AdminMenu()
{
    int b;
    system("CLS");
    cout << "\n\n\t\t\t1. ADD MANAGER\n"
            "\t\t\t2. REMOVE MANAGER\n"
            "\t\t\t3. UPDATE MANAGER SALARY\n"
            "\t\t\t4. ADD SALESMAN\n"
            "\t\t\t5. ADD STOREKEEPER\n"
            "\t\t\t6. VIEW SALES OF SALESMAN\n"
            "\t\t\t7. TOTAL SALES\n"
            "\t\t\t8. VIEW ALL DETAILS OF SALESMAN WITH SALARY\n"
            "\t\t\t9. VIEW ALL DETAILS OF STOREKEEPER WITH SALARY\n"
            "\t\t\t10. VIEW ALL DETAILS OF MANAGER WITH SALARYY\n"
            "\t\t\t11. VIEW LOGIN DETAILS OF ALL EMPLOYEES\n"
            "\t\t\t12. VIEW ALL PRODUCTS\n"
            "\t\t\t13. VIEW SALESMAN WITH GREATEST & SMALLEST SALES\n"
            "\t\t\t14. VIEW PRODUCT WITH GREATEST & SMALLEST SALES\n"
            "\t\t\t15. GO BACK TO MAIN MENU\n"
            "\t\t\t16. TO EXIT THE PROGRAM\n"
            "\t\t\tENTER YOUR OPTION: ";
    cin >> b;
    return b;
}

//Manager MENU
int ManagerMenu()
{
    int b;
    system("CLS");
    cout << "\n\n\t\t\t1. GIVE SALESMAN BONUS\n"
            "\t\t\t2. REMOVE SALESMAN\n"
            "\t\t\t3. GIVE STOREKEEPER BONUS\n"
            "\t\t\t4. REMOVE STOREKEEPER\n" 
            "\t\t\t5. UPDATE SALESMAN SALARY\n"
            "\t\t\t6. UPDATE STOREKEEPER SALARY\n"
            "\t\t\t7. VIEW SALES OF SALESMAN\n"
            "\t\t\t8. TOTAL SALES\n"
            "\t\t\t9. VIEW ALL DETAILS OF SALESMAN WITH SALARY\n"
            "\t\t\t10. VIEW ALL DETAILS OF STOREKEEPER WITH SALARY\n"
            "\t\t\t11. VIEW ALL PRODUCTS\n"
            "\t\t\t12. VIEW SALESMAN WITH GREATEST & SMALLEST SALES\n"
            "\t\t\t13. VIEW PRODUCT WITH GREATEST & SMALLEST SALES\n"
            "\t\t\t14. CHANGE YOUR USERNAME OR PASSWORD\n"
            "\t\t\t15. GO BACK TO MAIN MENU\n"
            "\t\t\t16. TO EXIT THE PROGRAM\n\n"
            "\t\t\tENTER YOUR OPTION: ";
    cin >> b;
    return b;
}

//Salesman MENU
int SalesmanMenu()
{
    int b;
    system("CLS");
    cout << "\n\n\t\t\t1. SALE PRODUCT\n"
            "\t\t\t2. RETURN PRODUCT\n"
            "\t\t\t3. VIEW ALL PRODUCTS\n"
            "\t\t\t4. VIEW YOUR SALES\n"
            "\t\t\t5. VIEW YOUR BONUS\n"
            "\t\t\t6. CHANGE YOUR USERNAME OR PASSWORD\n"
            "\t\t\t7. GO BACK TO MAIN MENU\n"
            "\t\t\t8. TO EXIT THE PROGRAM\n\n"
            "\t\t\tENTER YOUR OPTION: ";
    cin >> b;
    return b;
}

//StoreKeeper MENU
int StorekeeperMenu()
{
    int b;
    system("CLS");
    cout << "\n\n\t\t\t1. ADD PRODUCT\n"
            "\t\t\t2. DELETE PRODUCT\n"
            "\t\t\t3. VIEW ALL PRODUCTS\n"
            "\t\t\t4. VIEW THE NO. OF PRODUUCTS YOU ENTERED\n"
            "\t\t\t5. VIEW YOUR BONUS\n"
            "\t\t\t6. UPDATE THE PRICE OF PRODUCTS\n"
            "\t\t\t7. CHANGE YOUR USERNAME OR PASSWORD\n"
            "\t\t\t8. GO BACK TO MAIN MENU\n"
            "\t\t\t9. TO EXIT THE PROGRAM\n\n"
            "\t\t\tENTER YOUR OPTION: ";
    cin >> b;
    return b;
}

//Initialization of Manager Arrays
void initializeManager(string ManData[][10], string ManNamesList[], int ManAgeList[], int ManExpList[], string ManQualList[], string ManMobNoList[] , string ManIDList[], int ManSalaryList[], string ManUsernameList[], string ManPasswordList[],  string ManRegNoList[], int size)
{
    for (short i = 0; i < size ; i++)
    {
        ManNamesList[i] = " ";
        ManQualList[i] = " ";
        ManIDList[i] = " ";
        ManMobNoList[i] = " ";
        ManUsernameList[i] = " ";
        ManPasswordList[i] = " ";
        ManRegNoList[i] = " ";
        ManAgeList[i] = -1;
        ManExpList[i] = -1;
        ManSalaryList[i] = -1;
        for(int j=0;j<10;j++)
        {
            ManData[i][j] = " ";
        }
    }
}

//Initialization of Salesman Arrays
void initializeSalesman(string SalManData[][12], string SalManNamesList[], int SalManAgeList[], int SalManExpList[], string SalManQualList[], string SalMobNoList[] , string SalManIDList[], int SalManSalaryList[], int SalManBonusList[], string SalManUsernameList[], string SalManPasswordList[], string SalManRegNoList[], int SalManSales[], int size)
{
    for (short i = 0; i < size ; i++)
    {
        SalManNamesList[i] = " ";
        SalManQualList[i] = " ";
        SalManIDList[i] = " ";
        SalMobNoList[i] = " ";
        SalManUsernameList[i] = " ";
        SalManPasswordList[i] = " ";
        SalManRegNoList[i] = " ";
        SalManAgeList[i] = -1;
        SalManExpList[i] = -1;
        SalManSalaryList[i] = -1;
        SalManBonusList[i] = -1;
        SalManSales[i] = -1;
        for(int j=0;j<12;j++)
        {
            SalManData[i][j] = " ";
        }
    }
}

//Initialization of Storekeeper Arrays
void initializeStorekeeper(string StrkprData[][11], string StrkprNamesList[], int StrkprAgeList[], int StrkprExpList[], string StrkprQualList[], string StrkprMobNoList[] , string StrkprIDList[], int StrkprSalaryList[], int StrkprBonusList[], string StrkprUsernameList[], string StrkprPasswordList[], string StrkprRegNoList[], int StrkprSales[], int size)
{
    for (short i = 0; i < size ; i++)
    {
        StrkprNamesList[i] = " ";
        StrkprQualList[i] = " ";
        StrkprIDList[i] = " ";
        StrkprMobNoList[i] = " ";
        StrkprUsernameList[i] = " ";
        StrkprPasswordList[i] = " ";
        StrkprRegNoList[i] = " ";
        StrkprAgeList[i] = -1;
        StrkprExpList[i] = -1;
        StrkprSalaryList[i] = -1;
        StrkprBonusList[i] = -1;
        StrkprSales[i] = -1;
        for(int j=0;j<11;j++)
        {
            StrkprData[i][j] = " ";
        }
    }
}

//Initialization of Products Arrays
void initializeProducts(string PdData[][6], string PdIDList[], string PdNamesList[],int PdPriceList[], int PdQtyList[], int PDSale[], int PDSaleQty[], int size)
{
    for (short i = 0; i < size ; i++)
    {
        PdNamesList[i] = " ";
        PdIDList[i] = " ";
        PdPriceList[i] = -1;
        PdQtyList[i] = -1;
        PDSaleQty[i] = 0;
        PDSale[i] = 0;
        for(int j=0;j<6;j++)
        {
            PdData[i][j] = " ";
        }
    }
}

//checking PersonName
bool isValidName(string name)
{
    bool flag = true;
    if (name.length() <= 25)
    {
        for (short i = 0; i < name.length(); i++)
        {
            if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' ')))
            {
                flag = false;
                cout << "\n\t\tNAME CAN ONLY CONTAIN ALPHABETS AND SPACE\n";
                hault();
            }
        }
    }
    else
    {
        cout << "\n\t\tMAXIMUM NAME SIZE IS 25 CHARACTERS\n";
        hault();
        flag = false;
    }
    
    return flag;
}

//checking username
bool isValidUsername(string name)
{
    bool flag = true;
    if (name.length() <= 15)
    {
        for (short i = 0; i < name.length(); i++)
        {
            if (name[i] == ' ')
                {
                    cout <<"\t\tInvalid Username\n\t\tUsername should be any without spaces\n";
                    hault();
                    flag = false;
                    break;
                }
        }
    }
    else
    {
        cout <<"\t\tInvalid Username\n\t\tUsername  can only have  MAX 15 CHARACTER\n";
        hault();
        flag = false;
    }
    

    return flag;
}

//checking Password
bool isValidPassword(string Password)
{
    bool flag = true;
    short c1=0,c2=0,c3=0,c4=0;
    if (Password.length() >= 8)
    {
        for (short i = 0; i < Password.length(); i++)
        {
            if (Password[i] >= 'a' && Password[i] <= 'z')
            {
                c1 = c1+1;
            }
            if (Password[i] >= 'A' && Password[i] <= 'Z')
            {
                c2 = c2+1;
            }
            if (Password[i] >= '0' && Password[i] <= '9')
            {
                c3 = c3+1;
            }
            if (Password[i] =='@' || Password[i] == '!' || Password[i] =='#' || Password[i] == '$' || Password[i] =='*' || Password[i] == '&')
            {
                c4 = c4+1;
            }
        }
        if(c1 >= 1 && c2 >= 1 && c3 >= 1 && c4 >= 1 )
        {
            flag = true;
        }
        else
        {
            cout <<"\t\tInvalid Password\n\t\tPassword Should contain at least: 1 special character, 1 capital letter, 1 small letter, 1 integer\n";
            hault();
            flag = false;
        }
    }
    else
    {
        cout <<"\t\tInvalid Password\n\t\tPassword should contain at least 8 characters\n";
        hault();
        flag = false;
    }
    return flag;
}

//checking validity of Product ID
bool isValidProductID(string PdID)
{
    short x = PdID.length();
    bool flag = true;
    if (x == 5)
    {

        for (short i = 0; i < 3; i++)
        {
            if (!((PdID[i] >= 'a' && PdID[i] <= 'z') || (PdID[i] >= 'A' && PdID[i] <= 'Z')))
            {
                flag = false;
                break;
            }
        }

        for (short i = 3; i < 5 && flag; i++)
        {
            if (!(PdID[i] >= '0' && PdID[i] <= '9'))
            {
                flag = false;
                break;
            }
        }
    }

    return flag;
}

//ID CARD VALIDATOR
bool isValidIDCardNumber(string ID)
{
    bool flag = true;
    short IDsize = ID.length();
    if(IDsize == 15)
    {
        if(!(ID[5]=='-' && ID[13]=='-' && ID[14] >= '0' && ID[14] <= '9'))
        {
            flag = false;
        }

        for (short i = 0; i < 5 && flag; i++)
        {
            if (!(ID[i] >= '0' && ID[i] <= '9'))
            {
                flag = false;
                break;
            }
        }
        
        for (short i = 6; i < 13 && flag; i++)
        {
            if (!(ID[i] >= '0' && ID[i] <= '9'))
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        cout << "\t\tINVALID ID CARD!\n";
        hault();
        flag = false;
    }
    return flag;
}

//Mobile number Validator
bool isValidMobNo(string MobNo)
{
    bool flag = true;
    short Mobsize = MobNo.length();
    if(Mobsize == 12)
    {
        if(!(MobNo[4]=='-'))
        {
            flag = false;
        }

        for (short i = 0; i < 4 && flag; i++)
        {
            if (!(MobNo[i] >= '0' && MobNo[i] <= '9'))
            {
                flag = false;
                break;
            }
        }
        
        for (short i = 5; i < 12 && flag; i++)
        {
            if (!(MobNo[i] >= '0' && MobNo[i] <= '9'))
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        cout << "\t\tInvalid Mobile Number!\n";
        hault();
        flag = false;
    }
    return flag;
}

//checking Manager Age 
bool isValidManAge(int Age)
{
    bool flag = true;
    if (!(Age >= 30 && Age <= 45))
    {
        cout << "\n\t\tMINIMUM & MAXIMUM AGE FOR MANAGER IS 30 YEARS & 45 YEARS RESPECTIVELY\n";
        flag = false;
    }
    return flag;
}

//Checking Salesman Age
bool isValidSalManAge(int Age)
{
    bool flag = true;
    if (!(Age >= 20 && Age <= 45))
    {
        cout << "\n\t\tMINIMUM & MAXIMUM AGE FOR SALESMAN IS 20 YEARS & 35 YEARS RESPECTIVELY\n";
        flag = false;
    }
    return flag;
}

//Checking Storekeeper Age
bool isValidStrkprAge(int Age)
{
    bool flag = true;
    if (!(Age >= 18 && Age <= 30))
    {
        cout << "\n\t\tMINIMUM & MAXIMUM AGE FOR STOREKEEPER IS 18 YEARS & 30 YEARS RESPECTIVELY\n";
        flag = false;
    }
    return flag;
}

//checking Manager Experience 
bool isValidManExp(int Exp)
{
    bool flag = true;
    if (!(Exp >= 3 && Exp <= 8))
    {
        cout << "\n\t\tMINIMUM & MAXIMUM EXPERIENCE FOR MANAGER IS 3 YEARS & 8 YEARS RESPECTIVELY\n";
        flag = false;
    }
    return flag;
}

//checking Salesman Experience 
bool isValidSalManExp(int Exp)
{
    bool flag = true;
    if (!(Exp >= 2 && Exp <= 8))
    {
        cout << "MINIMUM EXPERIENCE FOR SALESMAN IS 2 YEARS\n";
        flag = false;
    }
    return flag;
}

//checking Manager Qualification
bool isValidManQual(string Qual)
{
    bool flag = false;
    if(Qual == "UG" || Qual == "ug" || Qual == "GA" || Qual == "ga" || Qual == "PG" || Qual == "pg" || Qual == "MAT" || Qual == "mat")
    {
        if(!(Qual == "PG" || Qual == "GA" || Qual == "pg" || Qual == "ga"))
        {
            cout << "MINIMUM QUALIFICATION FOR MANAGER IS GRADUATE\n";
        }
        else
        {
            flag = true;
        }
        
    }
    else
    {
        cout << "Invalid Input for Qualification\n";
        flag = false;
    }
    
    return flag;
}

//checking Salesman Qualification
bool isValidSalManQual(string Qual)
{
    bool flag = false;
    if(Qual == "UG" || Qual == "ug" || Qual == "GA" || Qual == "ga" || Qual == "PG" || Qual == "pg"  || Qual == "MAT" || Qual == "mat")
    {
      if(!(Qual == "PG" || Qual == "GA" || Qual == "pg" || Qual == "ga" || Qual == "UG" || Qual == "ug"))
        {
            cout << "MINIMUM QUALIFICATION FOR SALESMAN IS UNDERGRADUATE\n";
        }
        else
        {
            flag = true;
        }
    }
    else
    {
        cout << "Invalid Input for Qualification\n";
        flag = false;
    }
    
    return flag;
}

//checking Storekeeper Qualification
bool isValidStrkprQual(string Qual)
{
    bool flag = false;
    if(Qual == "UG" || Qual == "ug" || Qual == "GA" || Qual == "ga" || Qual == "PG" || Qual == "pg"  || Qual == "MAT" || Qual == "mat")
    {
      flag = true;
    }
    else
    {
        cout << "Invalid Input for Qualification\n";
        flag = false;
    }
    
    return flag;
}

//Store Registration Number Validation for Manager
bool isValidManRegNo(string RegNo)
{
    string a="MN";
    bool flag = false;
    for(short i=1;i<4;i++)
    {
        stringstream ss;
        string b;
        ss << i;
        b = ss.str();
        if(RegNo == a+b)
        {
        flag = true;
        break;
        }
    }
    return flag;
}

//Store Registration Number Validation for Salesman
bool isValidSalManRegNo(string RegNo)
{
    string a="SL";
    bool flag = false;
    for(short i=1;i<11;i++)
    {
        stringstream ss;
        string b;
        ss << i;
        b = ss.str();
        if(RegNo == a+b)
        {
        flag = true;
        break;
        }
    }
    return flag;
}

//Store Registration Number Validation for StoreKeeper
bool isValidStrkprRegNo(string RegNo)
{
    string a="SK";
    bool flag = false;
    for(short i=1;i<9;i++)
    {
        stringstream ss;
        string b;
        ss << i;
        b = ss.str();
        if(RegNo == a+b)
        {
        flag = true;
        break;
        }
    }
    return flag;
}

//VALIDATE ALL MANAGER DATA
bool validateManData(string Name, int Age, int Exp, string Qual, string MobNo, string ID)
{
    if (!(isValidName(Name) && isValidManAge(Age) && isValidManExp(Exp) && isValidManQual(Qual) && isValidMobNo(MobNo) && isValidIDCardNumber(ID)))
    {
        return false;
    }
    return true;
}

//VALIDATE ALL SALESMAN DATA
bool validateSalManData(string Name, int Age, int Exp, string Qual, string MobNo, string ID)
{
    if (!(isValidName(Name) && isValidSalManAge(Age) && isValidSalManExp(Exp) && isValidSalManQual(Qual) && isValidMobNo(MobNo) && isValidIDCardNumber(ID)))
    {
        return false;
    }
    return true;
}

//VALIDATE ALL STOREKEEPER DATA
bool validateStrkprData(string Name, int Age, string Qual, string MobNo, string ID)
{
    if (!(isValidName(Name) && isValidStrkprAge(Age) && isValidStrkprQual(Qual) && isValidMobNo(MobNo) && isValidIDCardNumber(ID)))
    {
        return false;
    }
    return true;
}

//VALIDATE ALL PRODUCT DATA
bool validatePdData(string Name, string PdID)
{
    if (!(isValidName(Name) && isValidProductID(PdID)))
    {
        return false;
    }
    return true;
}

//To FIND INDEX TO GIVE REGISTRATION NUMBER
int searchID(string IDList[], int size, string ID)
{
    int index = -1;
    for (short i = 0; i < size; i++)
    {
      
        if (IDList[i] == ID)
        {
            index = i;
            break;
        }
    }
    return index;
}

//To FIND INDEX TO REMOVE OR UPDATE THINGS
int searchRegNo(string RegNoList[], int size, string RegNo)
{
    int index = -1;
    for (short i = 0; i < size; i++)
    {
      
        if (RegNoList[i] == RegNo)
        {
            index = i;
            break;
        }
    }
    return index;
}

//To FIND INDEX OF REGISTRATION NO. 
void StrRegNo(string IDList[], int size, string ID, string RegNoList[])
{
    string a="MN", b="SL", c="SK";
    stringstream ss;
    string d;
    if(size == 3)
    {
        int j = searchID(IDList, size, ID);
        int i = j+1;
        if(i != -1)
        {
            ss << i;
            d = ss.str();
            cout << "\n\t\tYOUR STORE REGISTRATION NUMBER IS "<<a+d<<" \n";
            RegNoList[j] = a+d;
        }

    }
    else if(size == 10)
    {
        int j = searchID(IDList, size, ID);
        int i = j+1;
        if(i != -1)
        {
            ss << i;
            d = ss.str();
            cout << "\n\t\tYOUR STORE REGISTRATION NUMBER IS "<<b+d<<" \n";
            RegNoList[j] = b+d;
        }

    }
    else if(size == 8)
    {
        int j = searchID(IDList, size, ID);
        int i = j+1;
        if(i != -1)
        {
            ss << i;
            d = ss.str();
            cout << "\n\t\tYOUR STORE REGISTRATION NUMBER IS "<<c+d<<" \n";
            RegNoList[j] = c+d;
        }

    }

}

//To Add Manager with Details
bool AddManager(string ManNamesList[], int ManAgeList[], int ManExpList[], string ManQualList[], string ManMobNoList[] , string ManIDList[],  int ManSalaryList[], string ManUsernameList[] , string ManPasswordList[] , string Name, int Age, int Exp, string Qual,  string MobNo , string ID, int ManSalary, string ManUsername, string ManPassword, int size)
{
    bool flag = false;
    stringstream ss1,ss2,ss3;
    int i = searchID(ManIDList, size, " ");
    if (i != -1)
    {

        ManNamesList[i] = Name;
        ManAgeList[i] = Age;
        ManExpList[i] = Exp;
        ManQualList[i] = Qual;
        ManMobNoList[i] = MobNo;
        ManIDList[i] = ID;
        ManUsernameList[i] = ManUsername;
        ManPasswordList[i] = ManPassword;
        ManSalaryList[i] = ManSalary;
        flag = true;
    }
    return flag;
}

//To Remove Manager with Details
bool RemoveManager(string ManData[][10], string ManNamesList[], int ManAgeList[], int ManExpList[], string ManQualList[], string ManMobNoList[], string ManIDList[], int ManSalaryList[], string ManUsernameList[], string ManPasswordList[], string ManRegNoList[], string RegNo, int size)
{
    bool flag = false;
    int i = searchRegNo(ManRegNoList, size, RegNo);
    if (i != -1)
    {

        ManNamesList[i] = " ";
        ManAgeList[i] = -1;
        ManExpList[i] = -1;
        ManQualList[i] = " ";
        ManMobNoList[i] = " ";
        ManIDList[i] = " ";
        ManUsernameList[i] = " ";
        ManPasswordList[i] = " ";
        ManSalaryList[i] = -1;
        ManRegNoList[i] = " ";
        for(int j=0;j<10;j++)
        {
            ManData[i][j] = " ";
        }       
        flag = true;
    }
    return flag;
}

//To Add Salesman with Details
bool AddSalesman(string SalManNamesList[], int SalManAgeList[], int SalManExpList[], string SalManQualList[], string SalManMobNoList[] , string SalManIDList[],  int SalManSalaryList[], string SalManUsernameList[] , string SalManPasswordList[] , int SalManBonusList[] , int SalManSales[], string Name, int Age, int Exp, string Qual,  string MobNo , string ID, int ManSalary, string ManUsername, string ManPassword, int size)
{
    bool flag = false;
    int i = searchID(SalManIDList, size, " ");
    if (i != -1)
    {

        SalManNamesList[i] = Name;
        SalManAgeList[i] = Age;
        SalManExpList[i] = Exp;
        SalManQualList[i] = Qual;
        SalManMobNoList[i] = MobNo;
        SalManIDList[i] = ID;
        SalManUsernameList[i] = ManUsername;
        SalManPasswordList[i] = ManPassword;
        SalManSalaryList[i] = ManSalary;
        SalManBonusList[i] = 0;
        SalManSales[i] = 0;
        flag = true;
    }
    return flag;
}

//To Remove Salesman with Details
bool RemoveSalesman(string SalManData[][12],string SalManNamesList[], int SalManAgeList[], int SalManExpList[], string SalManQualList[], string SalManMobNoList[], string SalManIDList[], int SalManSalaryList[], string SalManUsernameList[], string SalManPasswordList[], string SalManRegNoList[], int SalManBonusList[] , string RegNo, int SalManSales[] ,int size)
{
    bool flag = false;
    int i = searchRegNo(SalManRegNoList, size, RegNo);
    if (i != -1)
    {

        SalManNamesList[i] = " ";
        SalManAgeList[i] = -1;
        SalManExpList[i] = -1;
        SalManQualList[i] = " ";
        SalManMobNoList[i] = " ";
        SalManIDList[i] = " ";
        SalManUsernameList[i] = " ";
        SalManPasswordList[i] = " ";
        SalManRegNoList[i] = " ";
        SalManSalaryList[i] = -1;
        SalManBonusList[i] = -1;
        SalManSales[i] = -1;
        for(int j=0;j<12;j++)
        {
            SalManData[i][j] = " ";
        }       
        flag = true;
    }
    return flag;
}

//To Add Storekeeper with Details
bool AddStorekeeper(string StrkprNamesList[], int StrkprAgeList[], string StrkprQualList[], string StrkprMobNoList[] , string StrkprIDList[],  int StrkprSalaryList[], string StrkprUsernameList[] , string StrkprPasswordList[] , int StrkprBonusList[] , int StrkprSales[] ,string Name, int Age, string Qual,  string MobNo , string ID, int ManSalary, string ManUsername, string ManPassword, int size)
{
    bool flag = false;
    int i = searchID(StrkprIDList, size, " ");
    if (i != -1)
    {

        StrkprNamesList[i] = Name;
        StrkprAgeList[i] = Age;
        StrkprQualList[i] = Qual;
        StrkprMobNoList[i] = MobNo;
        StrkprIDList[i] = ID;
        StrkprUsernameList[i] = ManUsername;
        StrkprPasswordList[i] = ManPassword;
        StrkprSalaryList[i] = ManSalary;
        StrkprBonusList[i] = 0;
        StrkprSales[i] = 0;
        flag = true;
    }
    return flag;
}

//To Remove Storekeeper with Details
bool RemoveStorekeeper(string StrkprData[][11], string StrkprNamesList[], int StrkprAgeList[], string StrkprQualList[], string StrkprMobNoList[], string StrkprIDList[], int StrkprSalaryList[], string StrkprUsernameList[], string StrkprPasswordList[], string StrkprRegNoList[], int StrkprBonusList[] , string RegNo, int StrkprSales[] ,int size)
{
    bool flag = false;
    int i = searchRegNo(StrkprRegNoList, size, RegNo);
    if (i != -1)
    {

        StrkprNamesList[i] = " ";
        StrkprAgeList[i] = -1;
        StrkprQualList[i] = " ";
        StrkprMobNoList[i] = " ";
        StrkprIDList[i] = " ";
        StrkprUsernameList[i] = " ";
        StrkprPasswordList[i] = " ";
        StrkprRegNoList[i] = " ";
        StrkprSalaryList[i] = -1;
        StrkprBonusList[i] = -1;
        StrkprSales[i] = -1;
        for(int j=0;j<11;j++)
        {
            StrkprData[i][j] = " ";
        }       
        flag = true;
    }
    return flag;
}

//To update Salary of Manager
bool ManSalaryUpdate(string Salary[][10], int SalaryList[],string RegNoList[],string RegNo, int size)
{
    bool flag = false;
    int newSalary;
    stringstream ss;
    int i = searchRegNo(RegNoList, size, RegNo);
    if (i != -1)
    {
        cout << "\t\tEnter New Salary :";
        cin >> newSalary;
        ss << newSalary;
        Salary[i][5] = ss.str();
        SalaryList[i] = newSalary;
        flag = true;
    }
    return flag;
}

//To update Salary of  Storekeeper
bool StrSalaryUpdate(string Salary[][11], int SalaryList[],string RegNoList[],string RegNo, int size)
{
    bool flag = false;
    int newSalary;
    stringstream ss;
    int i = searchRegNo(RegNoList, size, RegNo);
    if (i != -1)
    {
        cout << "\t\tEnter New Salary :";
        cin >> newSalary;
        ss << newSalary;
        Salary[i][5] = ss.str();
        SalaryList[i] = newSalary;
        flag = true;
    }
    return flag;
}

//To update Salary of Salesman
bool SalSalaryUpdate(string Salary[][12], int SalaryList[],string RegNoList[],string RegNo, int size)
{
    bool flag = false;
    int newSalary;
    stringstream ss;
    int i = searchRegNo(RegNoList, size, RegNo);
    if (i != -1)
    {
        cout << "\t\tEnter New Salary :";
        cin >> newSalary;
        ss << newSalary;
        Salary[i][6] = ss.str();
        SalaryList[i] = newSalary;
        flag = true;
    }
    return flag;
}


void changeUserPass(string UsernameList[], string PasswordList[], string RegNoList[], string Username, string Password ,string RegNo, int size)
{
    bool flag = false;
    string newUsername;
    string newPassword;
    int i = searchRegNo(RegNoList, size, RegNo);
    if (i != -1)
    {
        if(Username == UsernameList[i] && Password == PasswordList[i])
        {
            while (flag == false)
            {
                cout << "\n\t\tENTER NEW USERNAME: ";
                cin >> newUsername;
                cout << "\t\tENTER NEW PASSWORD: ";
                cin >> newPassword;
                if(isValidUsername(newUsername) && isValidPassword(newPassword))
                {
                    UsernameList[i] = newUsername;
                    PasswordList[i] = newPassword;
                    cout << "\n\t\tYOUR USERNAME & PASSWORD HAS BEEN CHANGED SUCESSFULLY!\n";
                    flag = true;
                    hault();
                }
                else
                {
                    cout << "\n\t\tINVALID USERNAME OR PASSWORD\n\t\tENTER USERNAME & PASSWORD AGAIN\n\n";
                    hault();
                }
            }
            
        }
        else
        {
            cout << "\n\t\tINCORRECT USERNAME OR PASSWORD\n";
            hault();
        }
        
    }
}

//To Add Product
bool AddProduct(string PdNamesList[], string PdIDList[], int PdPriceList[], int PdQtyList[], int PdQty, string PdName, string PdID, int PdPrice, int size)
{
    bool flag = false;
    int i = searchRegNo(PdIDList, size, " ");
    if (i != -1)
    {
                
        PdNamesList[i] = PdName;
        PdIDList[i] = PdID;
        PdPriceList[i] = PdPrice;
        PdQtyList[i] = PdQty;
        flag = true;
    }
    return flag;
}

//To Remove Product
bool RemoveProduct(string PdData[][6], string PdNamesList[], string PdIDList[], int PdPriceList[], int PdQtyList[], string PdID, int size)
{
    bool flag = false;
    int i = searchRegNo(PdIDList, size, PdID);
    if (i != -1)
    {
                
        PdNamesList[i] = " ";
        PdIDList[i] = " ";
        PdPriceList[i] = -1;
        PdQtyList[i] = -1;
        for(int j=0;j<4;j++)
        {
            PdData[i][j] = " ";
        }
        flag = true;
    }
    return flag;
}

//To update Product Price
bool ProductUpdate(string PdData[][6], int PdPriceList[],string PdIDList[],string PdID, int size)
{
    bool flag = false;
    int newPrice;
    stringstream ss;
    int i = searchRegNo(PdIDList, size, PdID);
    if (i != -1)
    {
        cout << "\n\t\tEnter New Price of Product :";
        cin >> newPrice;
        ss << newPrice;
        PdData[i][2] = ss.str();
        PdPriceList[i] = newPrice;
        flag = true;
    }
    return flag;
}

// This Function will display all course details
void viewAllProducts(string PdData[][6], string PdIDList[], int size)
{

    for (short u = 0; u < 100; u++)
        cout << "_";
    cout << endl;
    cout << left;
    cout << setw(25) << "Product"
         << setw(25) << "Product"
         << setw(25) << "Product"
         << setw(25) << "Product" << endl;
    cout << setw(25) << "Name"
         << setw(25) << " ID"
         << setw(25) << "Price"
         << setw(25) << "Quantity" << endl;
    for (short u = 0; u < 100; u++)
        cout << "_";
    cout << endl;
    for (short i = 0; i < size; i++)
    {
        if (PdIDList[i] != " ")
        {
            for(short j=0;j<4;j++)
            {
                cout << setw(25) << PdData[i][j];
            }
            cout << endl;
            for (short u = 0; u < 100; u++)
            {
                cout << "_";
            }
            cout << endl;
        }
        
    }
    
}

// TO VIEW MANAGER DETAILS
void ViewManager(string ManData[][10], string ManRegNoList[], int size)
{
    for (short u = 0; u < 160; u++)
        cout << "_";
    cout << endl;
    cout << left;
    cout << setw(20) << "Manager"
         << setw(20) << "Manager"
         << setw(20) << "Manager"
         << setw(20) << "Manager"
         << setw(20) << "Manager"
         << setw(20) << "Manager"
         << setw(20) << "Manager"
         << setw(20) << "Manager" << endl;
    cout << setw(20) << "Name"
         << setw(20) << "AGE"
         << setw(20) << "Experience"
         << setw(20) << "Qualification"
         << setw(20) << "Mobile No."
         << setw(20) << "Salary"
         << setw(20) << "ID"
         << setw(20) << "Reg No." << endl;
    for (short u = 0; u < 160; u++)
        cout << "_";
    cout << endl;
    for (short i = 0; i < size; i++)
    {
        if (ManRegNoList[i] != " ")
        {
            for(short j=0;j<8;j++)
            {
                cout << setw(20) << ManData[i][j];
            }
            cout << endl;
            for (short u = 0; u < 160; u++)
            cout << "_";
        }
        cout << endl;
    }
}

// TO VIEW SALESMAN DETAILS
void ViewSalesman(string SalManData[][12], string SalManRegNoList[], int size)
{

    for (short u = 0; u < 165; u++)
        cout << "_";
    cout << endl;
    cout << left;
    cout << setw(18) << "Salesman"
         << setw(18) << "Salesman"
         << setw(18) << "Salesman"
         << setw(18) << "Salesman"
         << setw(18) << "Salesman"
         << setw(18) << "Salesman"
         << setw(18) << "Salesman"
         << setw(18) << "Salesman"
         << setw(18) << "Salesman" << endl;
    cout << setw(18) << "Name"
         << setw(18) << "AGE"
         << setw(18) << "Experience"
         << setw(18) << "Qualification"
         << setw(18) << "Mobile No."
         << setw(18) << "ID"
         << setw(18) << "Salary"
         << setw(18) << "Reg No." 
         << setw(18) << "Bonus" << endl;
    for (short u = 0; u < 165; u++)
        cout << "_";
    cout << endl;
    for (short i = 0; i < size; i++)
    {
        if (SalManRegNoList[i] != " ")
        {
            for(short j=0;j<9;j++)
            {
                cout << setw(18) << SalManData[i][j];
            }
            cout << endl;
            for (short u = 0; u < 165; u++)
            cout << "_";
        }
        cout << endl;
    }
}

// TO VIEW STOREKEEPER DETAILS
void ViewStorekeeper(string StrkprData[][11], string StrkprRegNoList[], int size)
{

    for (short u = 0; u < 160; u++)
        cout << "_";
    cout << endl;
    cout << left;
    cout << setw(20) << "Storekeeper"
         << setw(20) << "Storekeeper"
         << setw(20) << "Storekeeper"
         << setw(20) << "Storekeeper"
         << setw(20) << "Storekeeper"
         << setw(20) << "Storekeeper"
         << setw(20) << "Storekeeper"
         << setw(20) << "Storekeeper" << endl;
    cout << setw(20) << "Name"
         << setw(20) << "AGE"
         << setw(20) << "Qualification"
         << setw(20) << "Mobile No."
         << setw(20) << "ID"
         << setw(20) << "Salary"
         << setw(20) << "Reg No." 
         << setw(20) << "Bonus" << endl;
    for (short u = 0; u < 160; u++)
        cout << "_";
    cout << endl;
for (short i = 0; i < size; i++)
    {
        if (StrkprRegNoList[i] != " ")
        {
            for(short j=0;j<8;j++)
            {
                cout << setw(20) << StrkprData[i][j];
            }
            cout << endl;
            for (short u = 0; u < 160; u++)
            cout << "_";
        }
        cout << endl;
    }
}

//// TO VIEW LOGIN DETAILS OF ALL EMPLOYEES
void ViewLoginDetails(string ManData[][10],string SalManData[][12],string StrkprData[][11], int size1, int size2, int size3)
{
    cout << "\n\n\t\t\t   ||***--- MANAGERS CREDENTIALS ---***||\n\n\n";
    for (short u = 0; u < 100; u++)
        cout << "_";
    cout << endl;
    cout << left;
    cout << setw(40) << "MANAGERS"
         << setw(40) << "MANAGERS"
         << setw(40) << "MANAGERS" << endl;
    cout << setw(40) << "REGISTRATION NO."
         << setw(40) << "USERNAMES"
         << setw(40) << "PASSWORD" << endl;
    for (short i = 0; i < size1; i++)
    {
        if (ManData[i][7] != " ")
        {
            for (short u = 0; u < 100; u++)
            cout << "_";
            cout << endl;
            cout << setw(40) << ManData[i][7]
                 << setw(40) << ManData[i][8]
                 << setw(40) << ManData[i][9] << endl;
        }
    }
    for (short u = 0; u < 100; u++)
        cout << "*";

    cout << "\n\n\t\t\t   ||***--- SALESMAN CREDENTIALS ---***||\n\n\n";
    for (short u = 0; u < 100; u++)
        cout << "_";
    cout << endl;
    cout << left;
    cout << setw(40) << "SALESMAN"
         << setw(40) << "SALESMAN"
         << setw(40) << "SALESMAN" << endl;
    cout << setw(40) << "REGISTRATION NO."
         << setw(40) << "USERNAMES"
         << setw(40) << "PASSWORD" << endl;
    for (short i = 0; i < size1; i++)
    {
        if (SalManData[i][7] != " ")
        {
            for (short u = 0; u < 100; u++)
            cout << "_";
            cout << endl;
            cout << setw(40) << SalManData[i][7]
                 << setw(40) << SalManData[i][9]
                 << setw(40) << SalManData[i][10] << endl;
        }
    }
    for (short u = 0; u < 100; u++)
        cout << "*";

    cout << "\n\n\t\t\t   ||***--- STOREKEEPER CREDENTIALS ---***||\n\n\n";
    for (short u = 0; u < 100; u++)
        cout << "_";
    cout << endl;
    cout << left;
    cout << setw(40) << "STOREKEEPER"
         << setw(40) << "STOREKEEPER"
         << setw(40) << "STOREKEEPER" << endl;
    cout << setw(40) << "REGISTRATION NO."
         << setw(40) << "USERNAMES"
         << setw(40) << "PASSWORD" << endl;
    for (short i = 0; i < size1; i++)
    {
        if (StrkprData[i][6] != " ")
        {
            for (short u = 0; u < 100; u++)
            cout << "_";
            cout << endl;
            cout << setw(40) << StrkprData[i][6]
                 << setw(40) << StrkprData[i][8]
                 << setw(40) << StrkprData[i][9] << endl;
        }
    }
    for (short u = 0; u < 100; u++)
        cout << "*";

}

//ALL MANAGER DATA IN 2D-ARRAY
void ManagerData(string ManData[][10],string ManNamesList[], int ManAgeList[], int ManExpList[], string ManQualList[], string ManMobNoList[], int ManSalaryList[], string ManIDList[], string ManRegNoList[], string ManUsernameList[] , string ManPasswordList[], int size)
{
    for(short i=0;i<size;i++)
    {
        if (ManRegNoList[i] != " ")
        {
            stringstream ss1,ss2,ss3;
            ManData[i][0] = ManNamesList[i];
            ss1 << ManAgeList[i];
            ManData[i][1] = ss1.str();
            ss2 << ManExpList[i];
            ManData[i][2] = ss2.str();
            ManData[i][3] = ManQualList[i];
            ManData[i][4] = ManMobNoList[i];
            ManData[i][6] = ManIDList[i];
            ss3 << ManSalaryList[i];
            ManData[i][5] = ss3.str();
            ManData[i][7] = ManRegNoList[i];
            ManData[i][8] = ManUsernameList[i];
            ManData[i][9] = ManPasswordList[i];
        }
    }
}

//ALL SALESMAN DATA IN 2D-ARRAY
void SalesmanData(string SalManData[][12] ,string SalManNamesList[], int SalManAgeList[], int SalManExpList[], string SalManQualList[], string SalManMobNoList[], string SalManIDList[], int SalManSalaryList[], string SalManRegNoList[], int SalManBonusList[], string SalManUsernameList[] , string SalManPasswordList[], int SalManSales[], int size)
{
    for(short i=0;i<size;i++)
    {
        if (SalManRegNoList[i] != " ")
        {
            stringstream ss1,ss2,ss3,ss4,ss5;
            SalManData[i][0] = SalManNamesList[i];
            ss1 << SalManAgeList[i];
            SalManData[i][1] = ss1.str();
            ss2 << SalManExpList[i];
            SalManData[i][2] = ss2.str();
            SalManData[i][3] = SalManQualList[i];
            SalManData[i][4] = SalManMobNoList[i];
            SalManData[i][5] = SalManIDList[i];
            ss3 << SalManSalaryList[i];
            SalManData[i][6] = ss3.str();
            SalManData[i][7] = SalManRegNoList[i];
            ss4 << SalManBonusList[i];
            SalManData[i][8] = ss4.str();
            SalManData[i][9] = SalManUsernameList[i];
            SalManData[i][10]= SalManPasswordList[i];
            ss5 << SalManSales[i];
            SalManData[i][11]= ss5.str();
        }
    }
}

//ALL STOREKEEPER DATA IN 2D-ARRAY
void StorekeeperData(string StrkprData[][11] ,string StrkprNamesList[], int StrkprAgeList[], string StrkprQualList[], string StrkprMobNoList[], string StrkprIDList[], int StrkprSalaryList[], string StrkprRegNoList[], int StrkprBonusList[], string StrkprUsernameList[] , string StrkprPasswordList[], int StrkprSales[], int size)
{
    for(short i=0;i<size;i++)
    {
        if (StrkprRegNoList[i] != " ")
        {
            stringstream ss1,ss2,ss3,ss4,ss5;
            StrkprData[i][0] = StrkprNamesList[i];
            ss1 << StrkprAgeList[i];
            StrkprData[i][1] = ss1.str();
            StrkprData[i][2] = StrkprQualList[i];
            StrkprData[i][3] = StrkprMobNoList[i];
            StrkprData[i][4] = StrkprIDList[i];
            ss3 << StrkprSalaryList[i];
            StrkprData[i][5] = ss3.str();
            StrkprData[i][6] = StrkprRegNoList[i];
            ss4 << StrkprBonusList[i];
            StrkprData[i][7] = ss4.str();
            StrkprData[i][8] = StrkprUsernameList[i];
            StrkprData[i][9] = StrkprPasswordList[i];
            ss5 << StrkprSales[i];
            StrkprData[i][10] = ss5.str();
        }
    }
}

//ALL STOREKEEPER DATA IN 2D-ARRAY
void ProductsData(string PdData[][6],string PdNamesList[], string PdIDList[], int PdPriceList[] ,int PdQtyList[], int PDSale[], int PDSaleQty[], int size)
{
    for(short i=0;i<size;i++)
    {
        if (PdIDList[i] != " ")
        {
            stringstream ss1,ss2,ss3,ss4;
            PdData[i][0] = PdNamesList[i];
            PdData[i][1] = PdIDList[i];
            ss1 << PdPriceList[i];
            PdData[i][2] = ss1.str();
            ss2 << PdQtyList[i];
            PdData[i][3] = ss2.str();
            ss3 << PDSale[i];
            PdData[i][4] = ss3.str();
            ss4 << PDSaleQty[i];
            PdData[i][5] = ss4.str();
        }
    }
}

//TO CHECK LOGIN DETAILS 
bool UserLogin(string UsernameList[], string PasswordList[], string Username, string Password, int size)
{
    bool flag = false;
    for(short i=0;i<size;i++)
    {
        if(UsernameList[i] == Username && PasswordList[i] == Password && UsernameList[i] != " ")
        {
            flag = true;
            break;
        }
    }
    return flag;
}

//TO CHECK WHETHER USER EXIST
bool UserExist(string UsernameList[], string PasswordList[], int size)
{
    bool flag = false;
    for(short i=0;i<size;i++)
    {
        if(UsernameList[i] != " " || PasswordList[i] != " ")
        {
            flag = true;
            break;
        }
    }
    return flag;
}

//TO CHECK WHETHER PRODUCT AVAILABLE
bool ProductExist(string PdnameList[], string PdIDList[], int size)
{
    bool flag = false;
    for(short i=0;i<size;i++)
    {
        if(PdnameList[i] != " " || PdIDList[i] != " ")
        {
            flag = true;
            break;
        }
    }
    return flag;
}

//TO CHECK LOGIN DETAILS 
int UserIndex(string UsernameList[], string PasswordList[], string Username, string Password, int size)
{
    int index;
    for(short i=0;i<size;i++)
    {
        if(UsernameList[i] == Username && PasswordList[i] == Password && UsernameList[i] != " ")
        {
            index = i;
            break;
        }
    }
    return index;
}

//TO SELL PRODUCT
bool SaleProduct(string PdData[][6], string PdNamesList[], string PdIDList[] , int PdQtyList[], string PdID, int PdQty, int size)
{
    bool flag = false;
    stringstream ss;
    int i = searchRegNo(PdIDList, size, PdID);
    if (i != -1)
    {
        if (PdQtyList[i] == 0)
        {
            cout << "\n\t\tPRODUCT OUT OF STOCK\n";
        }
        
        else if(PdQtyList[i] < PdQty)
        {
            cout << "\n\t\tSORRY THE AVAILBLE QUANTITY IS" << PdQtyList[i] << endl;
        }
        else if(PdQtyList[i] > PdQty)
        {
            cout << "\n\t\tTHANK YOU FOR SELLING\n\t\tREMAINING QUANTITY OF THIS PRODUCT IS " << PdQtyList[i]-PdQty << endl;
            PdQtyList[i] = PdQtyList[i]-PdQty;
            ss << PdQtyList[i];
            PdData[i][3] = ss.str();
            flag = true;
        }
        
    }
    if (i == -1)
    {
        cout << "\n\t\tPRODUCT NOT FOUND\n";
    }
    return flag;   
}

//TO RETURN PRODUCT
bool ReturnProduct(string PdData[][6], string PdNamesList[], string PdIDList[] , int PdQtyList[], string PdID, int PdQty, int size)
{
    bool flag = false;
    stringstream ss;
    int i = searchRegNo(PdIDList, size, PdID);
    if (i != -1)
    {
        PdQtyList[i] = PdQtyList[i]+PdQty;
        ss << PdQtyList[i];
        PdData[i][3] = ss.str();
        flag = true;
    }
    if (i == -1)
    {
        cout << "\n\t\tPRODUCT NOT FOUND\n";
    }
    return flag;   
}

//BILL
int bill(string PdNamesList[],string PdIDList[], string PdID, int PdPriceList[], int PdQty, int size)
{
    int Bill;
    int i = searchRegNo(PdIDList, size, PdID);
    if (i != -1)
    {
        Bill = PdPriceList[i]*PdQty;
        cout << "\n\n\n\t\t\t\t\t||**-- BILL --**||" << endl;
        cout << "\n\n\t\t\t\tPRODUCT NAME    \t\t="<<PdNamesList[i] << endl;
        cout << "\n\t\t\t\tPRODUCT ID      \t\t="<<PdIDList[i] << endl;
        cout << "\n\t\t\t\tPRODUCT QUANTITY\t\t="<<PdQty << endl;
        cout << "\n\t\t\t\tPRODUCT PRICE   \t\t="<<PdPriceList[i] << endl;
        cout <<"\n\t\t\t\t";
        for(int j=0;j<50;j++)
        {
            cout << '-';
        }
        cout << "\n\t\t\t\t        YOUR BILL   \t\t="<<"RS. "<<Bill << endl;
    }
    return Bill;
}

//TO FIND PRODUCT WITH MAX & MIN SALE
void MaxSale(string PdData[][6], string PdIDList[], string PdID, int PdPriceList[], int PdQty, int size, int PD[], int PDQty[])
{
    int Bill;
    stringstream ss1,ss2;
    int i = searchRegNo(PdIDList, size, PdID);
    if (i != -1)
    {
        Bill = PdPriceList[i]*PdQty;
        PD[i] = PD[i]+Bill;
        ss1 << PD[i];
        PdData[i][4] = ss1.str();
        PDQty[i] = PDQty[i]+PdQty;
        PdData[i][5] = ss2.str();
    }
}

void totalSales(string SalManData[][12], int SalManSales[],int size)
{
    int total = 0;
    //stringstream ss;
    for(short i=0;i<size;i++)
    {
        if(SalManSales[i] != -1)
        {
            //ss << SalMan[i][11];
            total = total+stoi(SalManData[i][11]);
        }
    }
    cout << "\n\t\tTOTAL SALES TILL NOW IS " << total;
}

void SalemanSales(string SalManData[][12], string SalManRegNoList[],int size)
{
    cout << "\n\n\t\t\t   ||***--- SALESMAN SALES ---***||\n\n\n";
    for (short u = 0; u < 100; u++)
        cout << "_";
    cout << endl;
    cout << left;
    cout << setw(40) << "SALESMAN"
         << setw(40) << "SALESMAN"
         << setw(40) << "SALESMAN" << endl;
    cout << setw(40) << "REGISTRATION NO."
         << setw(40) << "NAMES"
         << setw(40) << "SALES" << endl;
    for (short u = 0; u < 100; u++)
        cout << "_";
    cout << endl;
    for (short i = 0; i < size; i++)
    {
        if (SalManRegNoList[i] != " ")
        {
            cout << setw(40) << SalManData[i][7]
                 << setw(40) << SalManData[i][0]
                 << setw(40) << SalManData[i][11] << endl;
            for (short u = 0; u < 100; u++)
            cout << "_";
        }
        cout << endl;
    }
  
    for (short u = 0; u < 100; u++)
        cout << "*";
    cout << endl;
}

//TO FIND INDEX FOR HIGHEST SALE
int highest_score(int SalManSale[], int size)
{
    int max = SalManSale[0];
    int a = 0;
    for(short k=0;k<size;k++)
    {
        if(SalManSale[k] != -1)
        {
            if(SalManSale[k]>max)
            {
                a = k;
            }
        }       
    }
	return a;
}

//TO FIND INDEX FOR LOWEST SALE
int lowest_score(int SalManSale[], int size)
{ 
    int min = SalManSale[0];
    int b = 0;
    for(short l=0;l<size;l++)
    {
        if(SalManSale[l] != -1)
        {
            if(SalManSale[l]<min)
            {
                b = l;
            }
        }
    }
    return b;
}

//TO GIVE SALEMAN BONUS
bool SalGiveBonus(string bonus[][12],int BonusList[], string RegNoList[],string RegNo, int size)
{
    int bon;
    bool flag;
    stringstream ss;
    flag = false;
    int i = searchRegNo(RegNoList, size, RegNo);
    if (i != -1)
    {
        cout << "\n\t\tENTER THE AMOUNT OF BONUS YOU WANT TO GIVE :";
        cin >> bon;
        BonusList[i] = BonusList[i]+bon;
        ss << BonusList[i];
        bonus[i][8] = ss.str();
        flag = true;
    }
    return flag;
}

//TO GIVE STOREKEEPER BONUS
bool StrGiveBonus(string Bonus[][11],int BonusList[], string RegNoList[],string RegNo, int size)
{
    int bon;
    bool flag;
    stringstream ss;
    flag = false;
    int i = searchRegNo(RegNoList, size, RegNo);
    if (i != -1)
    {
        cout << "\n\t\tENTER THE AMOUNT OF BONUS YOU WANT TO GIVE :";
        cin >> bon;
        BonusList[i] = BonusList[i]+bon;
        ss << BonusList[i];
        Bonus[i][7] = ss.str();
        flag = true;
    }
    return flag;
}

//TO SAVE MANAGER DATA
bool SaveManager(string ManData[][10], string ManRegNoList[], int size)
{
    // This variable for read data from file
    ofstream manfile;
    /*Open the file if exist if not exist then make new file of this name ios::app maens that the new data will append in file and 
	not remove previous content of file */
    manfile.open("ManagerData.txt");
    //This function will check if the file open then write data from file
    if (manfile.is_open())
    {
        for (short i = 0; i < size; i++)
        {
            if (ManRegNoList[i] != " ")
            {
                for(short j=0;j<9;j++)
                {
                    manfile << ManData[i][j] << ",";
                }
                manfile << ManData[i][9] << endl;
            }
        }

        manfile.close();
        return true;
    }
    else
    {
        //If there is error while opening file this function will return false
        return false;
    }
}

//TO SAVE SALESMAN DATA
bool SaveSalesman(string SalManData[][12], string SalManRegNoList[], int size)
{
    // This variable for read data from file
    ofstream salmanfile;
    /*Open the file if exist if not exist then make new file of this name ios::app maens that the new data will append in file and 
	not remove previous content of file */
    salmanfile.open("SalesmanData.txt");
    //This function will check if the file open then write data from file
    if (salmanfile.is_open())
    {
        for (short i = 0; i < size; i++)
        {
            if (SalManRegNoList[i] != " ")
            {
                for(short j=0;j<11;j++)
                {
                    salmanfile << SalManData[i][j] << ",";
                }
                salmanfile << SalManData[i][11] << endl;
            }
        }

        salmanfile.close();
        return true;
    }
    else
    {
        //If there is error while opening file this function will return false
        return false;
    }
}

//TO SAVE STOREKEEPER DATA
bool SaveStorekeeper(string StrkprData[][11], string StrkprRegNoList[], int size)
{
    // This variable for read data from file
    ofstream strkprfile;
    /*Open the file if exist if not exist then make new file of this name ios::app maens that the new data will append in file and 
	not remove previous content of file */
    strkprfile.open("StorekeeperData.txt");
    //This function will check if the file open then write data from file
    if (strkprfile.is_open())
    {
        for (short i = 0; i < size; i++)
        {
            if (StrkprRegNoList[i] != " ")
            {
                for(short j=0;j<10;j++)
                {
                    strkprfile << StrkprData[i][j] << ",";
                }
                strkprfile << StrkprData[i][10] << endl;
            }
        }

        strkprfile.close();
        return true;
    }
    else
    {
        //If there is error while opening file this function will return false
        return false;
    }
}

//TO SAVE PRODUCT DATA
bool SaveProducts(string PdData[][6], string PdIDList[], int size)
{
    // This variable for read data from file
    ofstream Pdfile;
    /*Open the file if exist if not exist then make new file of this name ios::app maens that the new data will append in file and 
	not remove previous content of file */
    Pdfile.open("ProductData.txt");
    //This function will check if the file open then write data from file
    if (Pdfile.is_open())
    {
        for (short i = 0; i < size; i++)
        {
            if (PdIDList[i] != " ")
            {
                for(short j=0;j<5;j++)
                {
                    Pdfile << PdData[i][j] << ",";
                }
                Pdfile << PdData[i][5] << endl;
            }
        }

        Pdfile.close();
        return true;
    }
    else
    {
        //If there is error while opening file this function will return false
        return false;
    }
}

//Function to load MANAGER DATA 
bool loadManager(string ManData[][10],string ManNamesList[], int ManAgeList[], int ManExpList[], string ManQualList[], string ManMobNoList[], int ManSalaryList[], string ManIDList[], string ManRegNoList[], string ManUsernameList[] , string ManPasswordList[], int size)
{
    int i = 0;
    ifstream getMan("ManagerData.txt");
    if (!getMan.is_open())
    {
        cout << "ManagerData File Not Found" << endl;
        hault();
        return false;
    }
    else
    {
        string name,age,exp,qual,mob,id,salary,reg,user,pass;
        int Age,Exp,Salary;
        string line;
        while (!getMan.eof() && i < size)
        {
            getline(getMan, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, name, ',');
            ManData[i][0] = name;
            ManNamesList[i] = name;
            getline(ss, age, ',');
            ManData[i][1] = age;
            Age = stoi(age);
            ManAgeList[i] = Age;
            getline(ss, exp, ',');
            ManData[i][2] = exp;
            Exp = stoi(exp);
            ManExpList[i] = Exp;
            getline(ss, qual, ',');
            ManData[i][3] = qual;
            ManQualList[i] = qual;
            getline(ss, mob, ',');
            ManData[i][4] = mob;
            ManMobNoList[i] = mob;
            getline(ss, id, ',');
            ManData[i][5] = id;
            ManIDList[i] = id;
            getline(ss, salary, ',');
            ManData[i][6] = salary;
            Salary = stoi(salary);
            ManSalaryList[i] = Salary;
            getline(ss, reg, ',');
            ManData[i][7] = reg;
            ManRegNoList[i] = reg;
            getline(ss, user, ',');
            ManData[i][8] = user;
            ManUsernameList[i] = user;
            getline(ss, pass, ',');
            ManData[i][9] = pass;
            ManPasswordList[i] = pass;
            i++;
        }

        getMan.close();
        return true;
    }
}

//FUNCTION TO LOAD SALESMAN
bool loadSalesman(string SalManData[][12] ,string SalManNamesList[], int SalManAgeList[], int SalManExpList[], string SalManQualList[], string SalManMobNoList[], string SalManIDList[], int SalManSalaryList[], string SalManRegNoList[], int SalManBonusList[], string SalManUsernameList[] , string SalManPasswordList[], int SalManSales[], int size)
{
    int i = 0;
    ifstream getSalMan("SalesmanData.txt");
    if (!getSalMan.is_open())
    {
        cout << "SalesmanData File Not Found" << endl;
        hault();
        return false;
    }
    else
    {
        string name,age,exp,qual,mob,id,salary,reg,bonus,user,pass,sal;
        int Age,Exp,Salary,Bonus,Sal;
        string line;
        while (!getSalMan.eof() && i < size)
        {
            getline(getSalMan, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, name, ',');
            SalManData[i][0] = name;
            SalManNamesList[i] = name;
            getline(ss, age, ',');
            SalManData[i][1] = age;
            Age = stoi(age);
            SalManAgeList[i] = Age;
            getline(ss, exp, ',');
            SalManData[i][2] = exp;
            Exp = stoi(exp);
            SalManExpList[i] = Exp;
            getline(ss, qual, ',');
            SalManData[i][3] = qual;
            SalManQualList[i] = qual;
            getline(ss, mob, ',');
            SalManData[i][4] = mob;
            SalManMobNoList[i] = mob;
            getline(ss, id, ',');
            SalManData[i][5] = id;
            SalManIDList[i] = id;
            getline(ss, salary, ',');
            SalManData[i][6] = salary;
            Salary = stoi(salary);
            SalManSalaryList[i] = Salary;
            getline(ss, reg, ',');
            SalManData[i][7] = reg;
            SalManRegNoList[i] = reg;
            getline(ss, bonus, ',');
            SalManData[i][8] = bonus;
            Bonus = stoi(bonus);
            SalManBonusList[i] = Bonus;
            getline(ss, user, ',');
            SalManData[i][9] = user;
            SalManUsernameList[i] = user;
            getline(ss, pass, ',');
            SalManData[i][10] = pass;
            SalManPasswordList[i] = pass;
            getline(ss, sal, ',');
            SalManData[i][11] = sal;
            Sal = stoi(sal);
            SalManSales[i] = Sal;
            i++;
        }

        getSalMan.close();
        return true;
    }
}

bool loadStorekeeper(string StrkprData[][11] ,string StrkprNamesList[], int StrkprAgeList[], string StrkprQualList[], string StrkprMobNoList[], string StrkprIDList[], int StrkprSalaryList[], string StrkprRegNoList[], int StrkprBonusList[], string StrkprUsernameList[] , string StrkprPasswordList[], int StrkprSales[],int size)
{
    int i = 0;
    ifstream getStrkpr("StorekeeperData.txt");
    if (!getStrkpr.is_open())
    {
        cout << "StorekeeperData File Not Found" << endl;
        hault();
        return false;
    }
    else
    {
        string name,age,qual,mob,id,salary,reg,bonus,user,pass,sal;
        int Age,Salary,Bonus,Sal;
        string line;
        while (!getStrkpr.eof() && i < size)
        {
            getline(getStrkpr, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, name, ',');
            StrkprData[i][0] = name;
            StrkprNamesList[i] = name;
            getline(ss, age, ',');
            StrkprData[i][1] = age;
            Age = stoi(age);
            StrkprAgeList[i] = Age;
            getline(ss, qual, ',');
            StrkprData[i][2] = qual;
            StrkprQualList[i] = qual;
            getline(ss, mob, ',');
            StrkprData[i][3] = mob;
            StrkprMobNoList[i] = mob;
            getline(ss, id, ',');
            StrkprData[i][4] = id;
            StrkprIDList[i] = id;
            getline(ss, salary, ',');
            StrkprData[i][5] = salary;
            Salary = stoi(salary);
            StrkprSalaryList[i] = Salary;
            getline(ss, reg, ',');
            StrkprData[i][6] = reg;
            StrkprRegNoList[i] = reg;
            getline(ss, bonus, ',');
            StrkprData[i][7] = bonus;
            Bonus = stoi(bonus);
            StrkprBonusList[i] = Bonus;
            getline(ss, user, ',');
            StrkprData[i][8] = user;
            StrkprUsernameList[i] = user;
            getline(ss, pass, ',');
            StrkprData[i][9] = pass;
            StrkprPasswordList[i] = pass;
            getline(ss, sal, ',');
            StrkprData[i][10] = sal;
            Sal = stoi(sal);
            StrkprSales[i] = Sal;
            i++;
        }

        getStrkpr.close();
        return true;
    }
}

//TO LOAD PRODUCTS
bool loadProducts(string PdData[][6],string PdNamesList[], string PdIDList[], int PdPriceList[] ,int PdQtyList[], int PDSale[], int PDSaleQty[], int size)
{
    int i = 0;
    ifstream getPd("ProductData.txt");
    if (!getPd.is_open())
    {
        cout << "ProductData File Not Found" << endl;
        hault();
        return false;
    }
    else
    {
        string name,id,price,qty,sal,salqty;
        int Price,Qty,Sal,Salqty;
        string line;
        while (!getPd.eof() && i < size)
        {
            getline(getPd, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, name, ',');
            PdData[i][0] = name;
            PdNamesList[i] = name;
            getline(ss, id, ',');
            PdData[i][1] = id;
            PdIDList[i] = id;
            getline(ss, price, ',');
            PdData[i][2] = price;
            Price = stoi(price);
            PdPriceList[i] = Price;
            getline(ss, qty, ',');
            PdData[i][3] = qty;
            Qty = stoi(qty);
            PdQtyList[i] = Qty;
            getline(ss, sal, ',');
            PdData[i][4] = sal;
            Sal = stoi(sal);
            PDSale[i] = Sal;
            getline(ss, salqty, ',');
            PdData[i][5] = salqty;
            Salqty = stoi(salqty);
            PDSaleQty[i] = Salqty;
            i++;
        }

        getPd.close();
        return true;
    }
}

//Fuunction to read users from file and load then onto the arrays
bool loadUser(string& auser, string& apass)
{
    int i = 0;
    ifstream getUsers("Admin.txt");
    if (!getUsers.is_open())
    {
        cout << "\t\t\tAdmin File failed to open" << endl;
        cout << "\t\t\tPROGRAM CLOSED DUE TO Admin File Not Found";
        return false;
    }
    else
    {
        string username, password;
        string line;
        while (!getUsers.eof())
        {
            getline(getUsers, line);
            stringstream ss(line);
            getline(ss, username, ',');
            auser = username;
            getline(ss, password, ',');
            apass = password;
        }

        getUsers.close();
        return true;
    }
}