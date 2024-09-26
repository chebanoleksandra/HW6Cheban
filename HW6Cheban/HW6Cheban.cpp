#include <iostream>
using namespace std;

class Car {
    char* model;
    char* country;
    int year;
    double price;
public:
    Car() {
        model = nullptr;
        country = nullptr;
        year = 0;
        price = 0;
    }
    Car(const char* Model, const char* Country, int Year, double Price)
    {
        model = new char[strlen(Model) + 1];
        strcpy_s(model, strlen(Model) + 1, Model);
        country = new char[strlen(Country) + 1];
        strcpy_s(country, strlen(Country) + 1, Country);
        year = Year;
        price = Price;
    }
    char* SetModel(const char* Model)
    {
        model = new char[strlen(Model) + 1];
        strcpy_s(model, strlen(Model) + 1, Model);
    }
    char* SeCountry(const char* Country)
    {
        country = new char[strlen(Country) + 1];
        strcpy_s(country, strlen(Country) + 1, Country);
    }
    int SetYear(int Year)
    {
        year = Year;
    }
    double SetPrice(double Price)
    {
        price = Price;
        return price;
    }
    char* GetModel()
    {
        return model;
    }
    char* GetCountry()
    {
        return country;
    }
    int GetYear()
    {
        return year;
    }
    double GetPrice()
    {
        return price;
    }
    void Print() {
        cout << "Model: " << model << endl << "Country: " << country << endl << "Year: " << year << endl << "Price: " << price << endl;
    }
    void Input() {
        cout << "Input model: ";
        cin >> model;
        cout << endl << "Input country: ";
        cin >> country;
        cout << endl << "Input year: ";
        cin >> year;
        cout << endl << "Input price: ";
        cin >> price;
        cout << endl;
    }
    ~Car() { //doesn't work if bmw.Print() works
        delete[] model;
        delete[] country;
        /*cout << "del" << endl; */ //visual check if compiler goes to ~Car()
    }
};

int main()
{
    Car tesla("Tesla Y", "USA", 2020, 44630);
    tesla.Print();
    string s = tesla.GetCountry();
    cout << s << endl;
    tesla.SetPrice(54130);
    tesla.Print();

    Car bmw;
    bmw.Print(); //prints only "Model: " without any variables, doesn't go to the end of the line
    cout << bmw.GetYear();
}
