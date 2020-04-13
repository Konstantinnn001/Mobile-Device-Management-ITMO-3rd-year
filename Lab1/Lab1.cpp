#include <string>
#include <locale.h>
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;


int main()
{
    ifstream text("input.csv");
    string line;
    string timestamp;
    string msisdn_origin;
    string msisdn_dest;
    string call_duration;
    string sms_number;
    int sum=0;
    int mess = 0;
    double in_call = 0;
    double out_call = 0;
    getline(text, line);
    while (!text.eof())
    {
        getline(text, timestamp, ',');
        getline(text, msisdn_origin, ',');
        getline(text, msisdn_dest, ',');
        getline(text, call_duration, ',');
        getline(text, sms_number);
            if (msisdn_origin == "968247916")
            {
                if (stoi(call_duration) < stod(call_duration))
                {
                    in_call = in_call + stoi(call_duration) + 1;
                }
                else
                {
                    in_call = in_call + stoi(call_duration);
                }
                
                mess = mess + stoi(sms_number);
            }
            if (msisdn_dest == "968247916")
                if (stod(call_duration) > 5)    
                {
                    out_call = out_call + stoi(call_duration) - 4;
                }
    }
    sum = mess + in_call * 4 + out_call;
    cout << sum;
}

