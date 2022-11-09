#include <iostream>
using namespace std;

int main()
{
    cout<<"\n\t    1         2      3       4       5       6       7       8    "<<endl;
    for (int i = 0; i < 8; i++)
    {
        cout<<"  \t_________________________________________________________________"<<endl;
        if ((i==0)||(i==7))
            cout<<i+1<<"\t|   ♖    |    ♘   |  ♗   |   ♕    |  ♔   |   ♗   |   ♘   |   ♖   |"<<endl;
        else if((i==1)||(i==6))
            cout<<i+1<<"\t|   ♙    |    ♙   |  ♙   |   ♙    |  ♙   |   ♙   |   ♙   |   ♙   |"<<endl;
        else
            cout<<i+1<<"\t|\t |\t |\t |\t |\t |\t |\t |\t |"<<endl;
    }
    cout<<"  \t_________________________________________________________________"<<endl;
    cout<<"\n\t    1         2      3       4       5       6       7       8    \n"<<endl;
    
    
}