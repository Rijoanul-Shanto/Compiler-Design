/*
    Rijoanul Hasan
    Compiler Design LAB
    26.02.18

    Comment & White Space Remove
    Language Used: C++
*/

#include <bits/stdc++.h>
#define endl '\n'
#define INPUT freopen("input.in", "rt", stdin);

using namespace std;

int main()
{
    INPUT; //Macro for freopen("input.in", "rt", stdin); which i've defined earlier

    string str;

    while(getline(cin, str)) // Here i'm getting input until End of the File
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '*') // I've used this for Remove comment which start with /* and end with */
            {
                if(i < str.length()-1 and str[i+1] == '/')
                {
                    str.erase(str.begin(), str.begin()+i+2);
                }
            }

            if(str[i] == '/') // This is for comments which start with //. so i removed everything on that line starting with //
            {
                if(i < str.length()-1 and str[i+1] == '/')
                {
                    str.erase(str.begin()+i, str.end());
                }
                else if(i < str.length()-1 and str[i+1] == '*') // I've used this for Remove comment which start with /* and end with */
                {
                    int in = i+2;
                    while(true)
                    {
                        in++;
                        if(str[in] == '*' and str[in+1] == '/') break;
                        if(in >= str.length()) break;
                    }

                    if(in < str.length()) str.erase(str.begin()+i, str.begin()+in+2);
                    else str.erase(str.begin()+i, str.end());
                }
            }

            if(str[i] == ' ') // I've used this for remove black spaces
            {
                if(i < str.length()-1 and str[i+1] == ' ')
                {
                    str.erase(str.begin()+i, str.begin()+i+1);
                    i--;
                }
            }
        }
        cout << str << endl;
    }

    return 0;
}
