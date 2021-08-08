#pragma once
#include "portofolio.h"
#include "portofolio.h"

using namespace std;
int get_command()
{
    int cmd;
    bool correct = true;
    cout << "Choice: ";
    do
    {   
        cin >> cmd;
        if (cmd < 1 || cmd >11)
        {   
            cout << "Please select one option from the menu, [1-11]!" << endl;
            correct = false;
        }
        else
        {
            correct = true;
        }
    } while (!correct);
    return cmd;
}

void print_menu()
{
   cout << "********************************************************************" << endl;
   cout << "1. Add new asset from file                                         *" << endl;
   cout << "2. Add new asset from console                                      *" << endl;
   cout << "3. Print asset allocation                                          *" << endl;
   cout << "4. Buy fund units of existing asset                                *" << endl;
   cout << "5. Sell fund units                                                 *" << endl;
   cout << "6. Portofolio value - at investment prices                         *" << endl;
   cout << "7. Net ballance per asset class                                    *" << endl;
   cout << "8. Average return per asset class                                  *" << endl;
   cout << "9. Average portofolio return                                       *" << endl;
   cout << "10. Current market value of asset class                            *" << endl;
   cout << "11. Exit                                                           *" << endl;
   cout << "********************************************************************" << endl;
}

void intro()
{
    cout << "Wellcome to passive portofolio manager!" << endl;
}

void menu()
{


    portofolio p;
    int x = 100;
    intro();
    while (x != 11)
    {
        print_menu();
        x = get_command();
        switch (x)
        {
        case 1: 
        {
            asset_class a;
            string name;
            cout << "Name of the asset: ";
            cin >> name;
            a.set_name(name);
            string file_investments;
            string file_prices;
            string admin_cost;
            cout << "Type in name of file which contains the prices" << endl;
            ifstream in;
            do
            {
                cin >> file_prices;
                in.open(file_prices);
                if (in.fail())
                {
                    cout << "Wrong filename entered, please try again!" << endl;
                }
            } while (in.fail());
            a.get_prices(file_prices.c_str()); //works
            a.return_calculator();
            ifstream inv;
            cout << "Type in name of file which contains the invested amount " << endl;
            do
            {
                cin >> file_investments;
                inv.open(file_investments);
                if (inv.fail())
                {
                    cout << "Wrong filename entered, please try again!" << endl;
                }
            } while (inv.fail());
            a.get_investments(file_investments.c_str()); //works
            a.calculate_number_of_units();
            a.total_units_calculator();
            cout << "Type in the file, which holds the administrative cost of the fund " << endl;
            ifstream ad;
            do
            {
                cin >> admin_cost;
                ad.open(admin_cost);
                if (ad.fail())
                {
                    cout << "Wrong filename entered, please try again!" << endl;
                }
            } while (ad.fail());
            a.get_admin_cost_file(admin_cost.c_str());
            p.add_asset(a);
            break;
        }
        case 2: 
        {
            asset_class a;
            string name;
            cout << "Name of asset: ";
            cin >> name;
            a.set_name(name);
            double price;
            double invested_amount;
            cout << "Type in the current price of the asset: " << endl;
            cin >> price;
            a.get_price_console(price);
            a.return_calculator();
            cout << "Type in the amount you want to invest: " << endl;
            cin >> invested_amount;
            a.get_investment_console(invested_amount);
            a.calculate_number_of_units();
            a.total_units_calculator();
            cout << "Type in the administrative costs (%): " << endl;
            a.get_admin_cost();
            p.add_asset(a);
            break;
        }
        case 3: 
        {
            p.asset_allocation();
            break;
        }
        case 4:
        {
            int choice;
            double price, amount;
            p.print_assets_choices();
            cout << "Enter your choice: ";
            cin >> choice;
            cout << "Type in the current price of the asset: " << endl;
            cin >> price;
            cout << "Type in amount you want to invest: " << endl;
            cin >> amount;
            p.append(choice, price, amount);
            break;
        }
        case 5:
        {
            int choice;
            double price, amount;
            p.print_assets_choices();
            cout << "Enter your choice: ";
            cin >> choice;
            cout << "Type in the current price of the asset you want to sell: " << endl;
            cin >> price;
            cout << "Type the amount you want to retrive: " << endl;
            cin >> amount;
            p.append(choice, price, amount);
            break;
        }
        case 6:
        {
            cout << "Value of portofolio: " << p.pf_value() << endl;
            break;
        }
        case 7:
        {
            p.net_ballance_per_asset_class();
            break;
        }
        case 8:
        {
            p.avg_return_per_assetClass();
            break;
        }
        case 9:
        {
            cout << p.average_pf_return() << "%" << endl;
            break;
        }
        case 10:
        {
            int choice;
            double price, amount;
            p.print_assets_choices();
            cout << "Enter the order number of the asset class: ";
            cin >> choice;
            cout << "Type in the current price of the asset you want to sell: " << endl;
            cin >> price;
            p.current_mk_value_of_asset(choice,price);
            break;
        }
        default:
            break;
        }
    }
}
