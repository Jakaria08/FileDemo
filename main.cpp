#include <iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main()
{

string line;
string value;
string fValue;

vector<float> Indices;
vector<vector<float> > Faces;

ifstream file;
file.open("sphere.obj");

if (file.is_open())
{
    cout << "File successfully open !! \n";

}
else
{
    cout << "Error opening file \n";
}

while(getline(file,line))
{

    istringstream iss(line);

    iss >> value;

    if(value[0] =='v')
    {
        float i,j,k;

        iss >> i >> j >> k;

        Indices.push_back(i);
        Indices.push_back(j);
        Indices.push_back(k);

        cout<<i<<j<<k<<"\n";
    }

    if(value[0] == 'f')
    {
        while(iss >> fValue)
        {
        }

    }

}

file.close();

return 0;
}
