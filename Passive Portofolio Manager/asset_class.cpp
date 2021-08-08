#include "asset_class.h"

void asset_class::get_prices(const char* s)
{
    ifstream in(s);
    if (!in.is_open())
    {
        cout << "Could not open file! \n";
        return;
    }
    double x;
    while (in >> x)
    {
        price.push_back(x);
    }
    in.close();
}

void asset_class::get_investments(const char* s)
{
    ifstream in(s);
    if (!in.is_open())
    {
        cout << "Could not open file! \n";
        return;
    }
    float x;
    while (in >> x)
    {
        initialInvestments.push_back(x);
    }
    in.close();
}

void asset_class::get_price_console(double p)
{
    this->price.push_back(p);
}

void asset_class::get_investment_console(double i)
{
    this->initialInvestments.push_back(i);
}

void asset_class::set_name(string s)
{
    this->name = s;
}

void asset_class::get_admin_cost()
{
    cout << "Admin cost (%): ";
    double x;
    cin >> x;
    x /= 100;
    this->administrative_cost = x;
}

void asset_class::get_admin_cost_file(const char* s)
{
    ifstream in(s);
    if (!in.is_open())
    {
        cout << "Could not open file! \n";
        return;
    }
    float x;
    in >> x;
    x /= 100;
    this->administrative_cost = x;
    in.close();
}

double asset_class::total_investments()
{
    double total = 0;
    for (vector<double>::iterator i = initialInvestments.begin(); i != initialInvestments.end(); ++i)
    {
        total += *i;
    }
    return total;
}

double asset_class::net_ballance()
{
    double current_mk_value = this->total_units* this->price.back();
    double total = this->total_investments();
    double admin_cost = this->cost_at_pf_value();
    return (current_mk_value - total - admin_cost);
}

double asset_class::cost_at_pf_value()
{
    return this->total_investments() * administrative_cost;
}

double asset_class::current_value_assetClass(double curr_price) 
{
    return  this->total_units * curr_price;
}

void asset_class::calculate_number_of_units() 
{
    for (int i = 0; i < price.size(); i++)
    {
        number_of_fund_units.push_back(initialInvestments[i] / price[i]);
    }
}

double asset_class::value_of_assetClass()
{
    double value_of_pf = 0;
    for (int i = 0; i < price.size(); ++i)
    {
        value_of_pf += ((price[i]) *    (number_of_fund_units[i]));
    }
    return value_of_pf;
}

double asset_class::average_return()
{
    double sum_of_returns = 0;
    for (vector<double>::iterator i = returns.begin(); i != returns.end(); ++i)
    {
        sum_of_returns += *i;
    }
    return (sum_of_returns / returns.size());
}

void asset_class::return_calculator()
{
    for (int i = 1; i < price.size(); i++)
    {
        returns.push_back(((price[i] - price[i - 1]) / (price[i - 1])));
    }
}

void asset_class::append_existing_asset(double price, double amount)
{
    this->price.push_back(price);
    this->return_calculator();
    this->initialInvestments.push_back(amount);
    this->calculate_number_of_units();
    this->total_units_calculator(); 
}

void asset_class::sell_fund_unit(double amount, double current_price)
{
    double sold_units = amount / current_price;
    this->total_units = this->total_units - sold_units;
}

void asset_class::total_units_calculator()
{
    for (vector<double>::iterator i = number_of_fund_units.begin(); i != number_of_fund_units.end(); ++i)
    {
        total_units += (*i);
    }
}

