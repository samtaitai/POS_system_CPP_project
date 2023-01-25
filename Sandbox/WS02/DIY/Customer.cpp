#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"
using namespace sdds;

namespace sdds {

    // complete

    
    void EmptyRecord(Customers& c_rec) {
        c_rec.user_name; //???
        c_rec.retweets_count = 0;
        c_rec.likes_count = 0;
        c_rec.replies_count = 0;
        c_rec.share_videos = 0;

    }
    void EmptyRecord(CustomersRecord& t_rec) {
        t_rec.ptr_rec = nullptr;
        t_rec.noOfRecords = 0;
    }

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    // complete
    bool read(Customers& rec) {
        char name[21]{};
        bool check = true;

        cout << "Enter User name: ";
        read(name, 21);     //not 20
        strCpy(rec.user_name, name); //copy
        //cout << "Let's see.." << rec.user_name << endl; ok 

        if (rec.user_name[0] != 0) { //if receiving name successful, 
            cout << "Enter likes_count: ";
            cin >> rec.likes_count;
            cout << "Enter retweets_count: ";
            cin >> rec.retweets_count;
            cout << "Enter User replies_count: ";
            cin >> rec.replies_count;
            cout << "Enter User share videos (y/n): ";
            cin >> rec.share_videos;
        }
        else {              //if name inputting goes wrong OR user enter to quit
            check = false;
        }
        return check;
    }
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {
        //cout << "arrived!" << endl;
        t_rec.noOfRecords++; //0 to 1
        t_rec.ptr_rec = new Customers[t_rec.noOfRecords]; //size 1
        t_rec.ptr_rec[t_rec.noOfRecords] = c_rec; //t_rec.ptr_rec = &c_rec (x) something's wrong here
        
        //cout << "arrived! 2" << endl;
         
    }
    void display(const Customers& c_rec) {
        cout << c_rec.user_name << " ," << c_rec.likes_count << " ," << c_rec.retweets_count << " ," << c_rec.replies_count
            << " ," << c_rec.share_videos << endl;
    }
    void display(const CustomersRecord& t_rec) {
        int i{};
        for (i = 0; i < t_rec.noOfRecords; i++) {
            cout << i << ". ";
            display(*t_rec.ptr_rec);
            cout << endl;
        }
    }
    
   

  }

