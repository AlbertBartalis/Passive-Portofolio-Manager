#pragma once
#include "asset_class.h"

class portofolio
{
public:

    vector<asset_class>assets;
    double value_pf;
public:
    portofolio()
    {
        value_pf=0;
    };
    void add_asset(asset_class a);
    double pf_value(); //it calculates the current value of the portofolio, by adding up all the asset classes
    void asset_allocation(); //it calculates the distribution of different asset classes in the portofolio
    void net_ballance_per_asset_class();
    double average_pf_return(); 
    void print_assets(); //prints the names of the asset clases from the portofolio
    void print_assets_choices();
    void append(int counter,double price, double amount); //new investment in existing asset class
    void current_mk_value_of_asset(int counter, double current_price);
    void sell_asset(int counter,double amount, double current_price); 
    void avg_return_per_assetClass();
};