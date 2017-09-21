#include <iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
/////////////// File read /////////////////////////
    string line;
    string value;

    vector<float> Indices;
    vector<vector<int> > Faces;

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
            float Ivalue;

            while(iss >> Ivalue)
            {

                Indices.push_back(Ivalue);

                cout<<Ivalue;

            }
        }

        if(value[0] == 'f')
        {

            int fValue;
            vector<int> temp;

            while(iss >> fValue)
            {
                temp.push_back(fValue);
                cout<<fValue;
            }

            Faces.push_back(temp);
            temp.clear();

        }

    }


    file.close();

///////// File Write ////////////////

    ofstream outObj;

    outObj.open("out.obj");

    outObj << "v" << " " << Indices[0] << " ";

    for(long int i=1; i<Indices.size(); i++)
    {
        if((i%3)==0)
        {
            outObj << "\n" << "v" << " ";
        }

        outObj << Indices[i] << " ";

    }

    outObj << "\n";

    for(long int j=0; j<Faces.size(); j++)
    {
        outObj << "f" << " ";

        for(int k=0; k<Faces[j].size(); k++)
        {
            outObj << Faces[j][k] << " ";
        }

        outObj << "\n";

    }

    return 0;
}

