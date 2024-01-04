/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int  maxProfit(int price[],int buy,int sell)
{
    int profit =0;
    if(sell<=buy)
        return 0;
    for(int i=buy;i<sell;i++)
    {
        for(int j=i+1;j<=sell;j++)
        {
            if(price[j]>price[i])
            {
                int current_profit = price[j]-price[i]+maxProfit(price,buy,i-1)+maxProfit(price,j+1,sell);
                profit = max(profit,current_profit);
            }
        }
    }
    return profit;
}
int main()
{
    cout<<"Hello World";
    int price[]={100, 180, 260, 310, 40, 535, 695};
    int no_of_days=sizeof(price)/sizeof(price[0]);
   cout<<"\n days: "<<no_of_days<<endl;
    int max_profit = maxProfit(price,0,no_of_days-1);
    
    cout<<"\nMaximum profit made is :"<<max_profit<<endl;
    return 0;
}
