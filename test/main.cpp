#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class User
{
private:
    string name,phone,email,password,id,drivinglicense,nationalid;
    public:
        list <float> Ratings;
        User();
        void setName(string name){this->name=name;}
        void setPhone(string phone) {this->phone = phone;}
        void setEmail(string email) {this->email=email;}
        void setPassword(string password){this->password=password;}
        void setId(string id){this->id=id;}
        void setDrivinglicense(string drivinglicense){this->drivinglicense = drivinglicense;}
        void setNationalid(string nationalid){this->nationalid = nationalid;}
        string getName();
        string getPhone();
        string getEmail();
        string getPassword();
        string getId();
        string getDrivingLicense();
        string getNationalId();
        virtual ~User();
};


class Driver:public User{
private:
    User user;
public:
        Driver();
        vector<string> fav;
        void AddFav(){
            string f;
            cin>>f;
            fav.push_back(f);
            cout<<f<<" is added"<<endl;}
        void printFav(){
            for(int i = 0 ; i < fav.size();i++)
                cout<<fav.at(i)<<' ';}
        //string GetNotifications(); SRP is not applied applied
        void ListUserRatings(User user){
            for (float rate : Ratings ) cout << rate << "\n";
        }
        void SuggestPrice(int price)
        {

            cout<<"The suggested price is 50 EGP"<<endl;
        }
        void NotifyUser(){

        }
        virtual ~Driver();
};

class Registration
{
    User user;
    string name,phone,email,password,id;

    public:
    list <string> PendingDrivers;
    list <string> customers;
    list <string> drivers;

    Registration()
    {
     this->name = name;
     this->password = password;
     this->email = email;
     this->id = id;
     this->phone = phone;
    }
    void adduser(User user)
    {
       Registration r ;
       r.user = user;
       cout<<"please enter user name"<<endl;
       cin>>r.name;
       cout<<"please enter user password"<<endl;
       cin>>r.password;
    } //SRP is applied
    void verify(){
        Registration r2;
        if (r2.password.length()<5){
            cout<<"password must be more than 4 characters";

        }
    }//SRP is applied
    virtual ~Registration();

};


class Customer:public User{
private:
   Driver d1;
   string source,dest;

    public:
        Customer();
        void requestRide(string source , string dest)
        {
            this->source = source;
            this->dest=dest;



        }
        void rateDriver(Driver d)
        {
            cout<<"Rate the driver from 1 to 5 stars"<<endl;
            int rate;
            cin>>rate;
            Ratings.push_back(rate);
        }
        float checkAverageRating(Driver d);
        string getSource();
        string getDest();
        virtual ~Customer();

    protected:

    private:
};

class Admin
{
    private:
        User u;
        Customer c;
        Driver d;
        Registration r;
        vector<User> Suspended;
        list <Driver> drivers;
    public:
        Admin();
        void Suspend(User user){ Suspended.push_back(user);} //SRP applied
        void VerifyDriverRegisteration(){
            for(string driver: r.PendingDrivers)
            {
                //drivers.push_back(driver);
            }
        }//SRP applied
        void ListRegistrations()
        {   cout<<"Drivers:   "<<endl;
            for( string driver: r.drivers) cout<<driver<<' ';
            cout<<endl;
            cout<<"Customers:   "<<endl;
            for( string customer : r.customers)cout<<customer<<' ';
            cout<<endl;}//SRP applied

        virtual ~Admin();
};

class Notifications{
private:
    Customer c1;
    Driver d1;
public:
    string getNotificationsD(Driver driver)
    {
        for (string place : d1.fav){
            if(place==c1.getSource() || place==c1.getDest())
                cout<<"A customer has requested a place from your favorites"<<endl;
        }
    }
    string getNotificationsC(Customer customer)
    {

    }
};


int main()
{
    User user1;
    Admin admin1;

    Driver d1;
    d1.AddFav();
    d1.AddFav();
    d1.printFav();

    admin1.Suspend(user1);
    admin1.ListRegistrations();
    admin1.VerifyDriverRegisteration();

};
