#include <iostream>
#include <vector>
#include <cstdint> //for uint8_t
using namespace std;

using LetterCanvas = vector<vector<uint8_t>>;

LetterCanvas gLetters = {

    #include "letters.h"
};

LetterCanvas MakeCanvas(const string& input)
{
    LetterCanvas canvas;

    for (size_t i = 0; i < input.size(); i++)
    {
        canvas.push_back(gLetters[input[i]-'A']);
    }

    return canvas;
}

string RenderLine(char ch, uint8_t rep)
{
    //cout<<"\nRender Line called with "<<rep;
    std::string str = "";
    int ctr = 5;
    while (ctr > 0)
    {
        //cout<<"rep:"<<rep;
        if (rep & 1)
            str = ch + str;
        else
            str = ' ' + str;

        rep = rep >> 1;
        ctr--;
    }

    //std::cout << str;
    return str;
}

void RenderCanvas(const string& input, const LetterCanvas& canvas)
{
    //The idea is to render the the i'th row of all letters and then goto the next row

    string result = "";
    int rowCount = 7;
    int rowIter = 0;
    //cout << "\nCanvas Size:" << canvas.size()<<"\n";
    while (rowIter < rowCount)
    {
       
        for (int i = 0; i < canvas.size(); i++)
        {
            result = "";
            string temp = RenderLine(input[i], canvas[i][rowIter]);
            //give a space of 2 spaces between each letter
            result += temp;
            result += "  ";
            //cout << "\nResult Size:"<<result.size();
            cout << result;
        }

        cout << "\n";
        rowIter++;
    }
}

int main()
{
    string input = "HREY";
    LetterCanvas canvas = MakeCanvas(input);
    RenderCanvas(input, canvas);
    return 0;
}