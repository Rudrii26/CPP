//5.2_25CS027
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
    ifstream file("sample.txt");

    if (!file)
    {
        cout << "Error: File could not be opened!" << endl;
        return 1;
    }

    string line;
    int wordcount = 0;
    int linecount = 0;
    int charcount = 0;

    while (getline(file, line))
    {
        linecount++;

        bool inword = false;

        for (int i = 0; i < line.length(); i++)
        {
            charcount++;

            if (isalnum(line[i]))
            {
                if (!inword)
                {
                    wordcount++;
                    inword = true;
                }
            }
            else
            {
                inword = false;
            }
        }
    }

    file.close();

    cout << "Total lines: " << linecount << endl;
    cout << "Total words: " << wordcount << endl;
    cout << "Total characters: " << charcount << endl;

    return 0;
}