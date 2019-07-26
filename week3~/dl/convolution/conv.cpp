#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> x{4, 1.0,2.0,3.0,4.0};
    vector<double> y;

    
    x.insert(x.begin(), 0.0);
    x.insert(x.end(), 0.0);

    for(int i=0; i<x.size(); i++){
        cout<<x[i]<<endl;
    }

    return 0;
}
