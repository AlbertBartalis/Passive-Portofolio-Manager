#include "portofolio.h"
#include "asset_class.h"

double portofolio::average_pf_return()
{
    double returns = 0;
    cout << "Average portofolio return:" << endl;
    for (vector<asset_class>::iterator i = assets.begin(); i != assets.end(); ++i)
    {
        returns += (*i).average_return();
    }

    return ((returns / assets.size()) * 100);
}

void portofolio::net_ballance_per_asset_class()
{
    cout << "Net ballance of assets: "<<endl;
    for (vector<asset_class>::iterator i = assets.begin(); i != assets.end(); ++i)
    {
        cout << (*i).name << ": " << (*i).net_ballance() << endl;
    }
}

void portofolio::asset_allocation()
{
    vector<double>values;
    if (this->assets.empty())
    {
        cout << "Portofolio is empty!" << endl;
        return;
    }
    cout << "Asset allocation of the portofolio: " << endl;
    for (vector<asset_class>::iterator i = assets.begin(); i != assets.end(); ++i)
    {
        cout << (*i).name << ": " << (((*i).value_of_assetClass()) / this->pf_value()) * 100 << " %" << endl;
    }

}

double portofolio::pf_value()
{
    double val = 0;
    for (int i = 0; i < assets.size(); i++)
    {
        val += assets[i].value_of_assetClass();
    }
    return val;
}

void portofolio::print_assets()
{
    for (int i = 0; i < assets.size(); ++i)
    {
        cout << assets[i].name << endl;
    }
}
void portofolio::print_assets_choices()
{
    for (int i = 0; i < assets.size(); ++i)
    {
        cout <<i<<" "<< assets[i].name << endl;
    }
}

void portofolio::add_asset(asset_class a)
{
    assets.push_back(a);
    this->pf_value();
}

void portofolio::append(int counter, double price, double amount)
{
    int ctr = 0;
    for (vector<asset_class>::iterator i = assets.begin(); i != assets.end(); ++i)
    {

        if (ctr == counter)
        {
            (*i).append_existing_asset(price, amount);
        }
        ctr++;
    }
}

void portofolio::sell_asset(int counter, double price, double amount)
{
    int ctr = 0;
    double sold_units_value = price * amount;
    for (vector<asset_class>::iterator i = assets.begin(); i != assets.end(); ++i)
    {
        if (ctr == counter)
        {
            (*i).sell_fund_unit(price, amount);
        }
        ctr++;
    }
    this->value_pf = this->value_pf - sold_units_value;
}

void portofolio::avg_return_per_assetClass()
{
    cout << "Average returns" << endl;
    for (vector<asset_class>::iterator i = assets.begin(); i != assets.end(); ++i)
    {
        cout << (*i).name << " " << (*i).average_return() * 100 << "%" << endl;
    }
}

void portofolio::current_mk_value_of_asset(int counter, double current_price)
{
    int ctr = 0;
    for (vector<asset_class>::iterator i = assets.begin(); i != assets.end(); ++i)
    {
        if (ctr == counter)
        {
            cout << (*i).name << ": " << (*i).current_value_assetClass(current_price) << endl  ;
        }
        ctr++;
    }
}