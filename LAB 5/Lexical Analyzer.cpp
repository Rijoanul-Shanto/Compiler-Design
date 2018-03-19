#include <bits/stdc++.h>
using namespace std;

bool comment = 0, flag = 0;

bool isKey(string temp)
{
    string keyword[] =
    {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float" "for", "goto", "if", "int",
        "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };

    return binary_search(keyword, keyword+32, temp);
}

bool isNum(string temp)
{
    for(int i = 0; i < temp.length(); i++)
        if(temp[i] < '0' or temp[i] > '9')
            return false;
    return true;
}

string tokenCheck(string str)
{
    string temp;
    int len = str.length();

    for(int i = 0; i < len; i++)
    {
        if(str[i] == '(' and str[i+1] == ')') continue;

        else if(str[i] == ' ' or str[i] == ';' or str[i] == '(' or str[i] == ',' or str[i] == '=' or i == len-1)
        {
            //cout << '`' << temp << '`' << endl;
            if(temp[0] == ' ')
            {
                temp.erase(temp.begin(), temp.begin()+1);
            }

            if(temp.length() == 1 and (temp[0] == '+' or temp[0] == '-' or temp[0] == '*' or temp[0] == '/' or temp[0] == '%' or temp[0] == '='))
                cout << temp << "\t is Operator!" << endl;

            else if(isKey(temp)) cout << temp << "\t is Keyword!" << endl;

            else if(isNum(temp)) cout << temp << "\t is Number!" << endl;

            else if((temp[0] >= 'a' and temp[0] <= 'z') or (temp[0] >= 'A' and temp[0] <= 'Z')) cout << temp << "\t is Identifier!" << endl;

            else cout << temp << "\t is not Token!" << endl;

            temp.clear();
            continue;
        }
        else if(str[i] == '\"')
        {
            int in = i;
            while(str[in] != ')')
            {
                temp+=str[in];
                in++;
            }
            cout << temp << "\t is a string" << endl;
            temp.clear();
            break;
        }
        temp += str[i];
    }

    return str;
}

string commentWhiteSpaceRemove(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '*') // I've used this for Remove comment which start with /* and end with */
        {
            if(i < str.length()-1 and str[i+1] == '/')
            {
                str.erase(str.begin(), str.begin()+i+2);
                comment = 0;
                flag = 1;
            }
        }

        else if(str[i] == '/') // This is for comments which start with //. so i removed everything on that line starting with //
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
                    if(str[in] == '*' and str[in+1] == '/')
                    {
                        comment = 0;
                        break;
                    }
                    if(in >= str.length())
                    {
                        comment = 1;
                        break;
                    }
                    in++;
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
    //if(flag) comment = 0;
    //if(comment) str.erase(str.begin(), str.end());
    return str;
}

int main()
{
    string str;

    while(getline(cin, str))
    {
        string temp;
        temp = commentWhiteSpaceRemove(str);
        cout << endl << "OUTPUT: \t" << temp << endl << endl;
        if(temp[0] == ' ') temp.erase(temp.begin(), temp.begin()+1);

        //cout << "After comment: " << temp << "comment: " << comment << endl;

        str.clear();

        str = tokenCheck(temp);
        cout << endl;
    }

    return 0;
}
