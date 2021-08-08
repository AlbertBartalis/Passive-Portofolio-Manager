#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <string>
using namespace std;

class asset_class //it can be: index funds, bond fund, reits
{
public: //need to set it back to private after project is finished (now I need to test functions and print stuff)
    string name;
    vector<double>price;
    vector<double>returns;
    vector <double>initialInvestments; // get it from file   
    vector<double>number_of_fund_units; //calculate it based on purchase price and initial investment
    double administrative_cost;
    double total_units;
    friend class portofolio;
public:
    asset_class()
    {
        total_units = 0;
    }
    void set_name(string s);
    void get_prices(const char* s);
    void get_admin_cost(); 
    void get_admin_cost_file(const char* s);
    void get_investments(const char* s);//this method reads the initial investments of the investor (for now I will read them from a file)
    void get_price_console(double p);
    void get_investment_console(double i);
    void return_calculator(); //it returns the price returns of the asset
    double current_value_assetClass(double curr_price); //number of fund units* current price //it makes it possible for the current market value of portofoliu
    double average_return(); 
    double value_of_assetClass(); //value of investments (price*fund units)
    void calculate_number_of_units();
    double cost_at_pf_value(); //returns the nominal cost of administration APPLIED TO INITIAL INVESTMENTS
    double net_ballance(); //it returns the net profit/loss of the asset class (current market value - invested amount-admin cost) 
    double total_investments(); 
    void append_existing_asset(double price, double amount); //method used for purchasing new fund units
    void sell_fund_unit(double amount,double current_price);
    void total_units_calculator(); 
};

