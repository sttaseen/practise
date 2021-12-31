#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline char charToInt(char target)
{
    return target - 'a';
}

int getMaxDismissals(string loyalty, bool fromLeft)
{
    if(!fromLeft)
    {
        reverse(loyalty.begin(), loyalty.end());
    }

    int dismissed = 0;
    int index = 0;
    //From preprocess to end of the string do dismissals
    while(index<loyalty.size())
    {
        bool left = (charToInt(loyalty[index])-charToInt(loyalty[index-1])==1)&&!(index==0);
        bool right = (charToInt(loyalty[index])-charToInt(loyalty[index+1])==1)&&!(index==loyalty.size()-1);
        if(left||right)
        {
            dismissed++;
            loyalty.erase(loyalty.begin()+index); //Delete the i'th index
            index -= (index==0)?0:1;
            cout << loyalty << endl;
        }else
        {
            index++;
        }
    }
    cout << fromLeft << ": " << dismissed << endl;
    return dismissed;
}

int getMaxDismissals(string& loyalty)
{
    int leftRight = getMaxDismissals(loyalty, true);
    int rightLeft = getMaxDismissals(loyalty, false);

    return (leftRight>rightLeft)?leftRight:rightLeft;
}

int main()
{
    int n_size;
    cin>> n_size;
    string loyalty;
    cin>>loyalty;
    cout<<getMaxDismissals(loyalty)<<"\n";
    return 0;
}