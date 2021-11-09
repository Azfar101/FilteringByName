//Azfar Azdi Arfakhsyad
//21/481865/TK/53183

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream logWindows;

void getInformation()
{
    logWindows.open("event_log_windows_1000.txt");

    string iline;
    
    while(getline(logWindows, iline))
    {
        size_t ifound = iline.find("Information");
        if(ifound != string::npos && iline[0] == 'I')
        {
            ofstream informationOutput;
            informationOutput.open("information.txt", ios::app);
            informationOutput << iline << endl;
        }
    }
    logWindows.close();
    cout << "The information index has been stored in information.txt" << endl;
}

void getWarning()
{
    logWindows.open("event_log_windows_1000.txt");

    string wline;
    
    while(getline(logWindows, wline))
    {
        size_t wfound = wline.find("Warning");
        if(wfound != string::npos && wline[0] == 'W')
        {
            ofstream warningOutput;
            warningOutput.open("warning.txt", ios::app);
            warningOutput << wline << endl;
        }
    }
    logWindows.close();
    cout << "The warning index has been stored in warning.txt" << endl;
}

void getError()
{
    logWindows.open("event_log_windows_1000.txt");

    string eline;
    
    while(getline(logWindows, eline))
    {
        size_t efound = eline.find("Error");
        if(efound != string::npos && eline[0] == 'E')
        {
            ofstream errorOutput;
            errorOutput.open("error.txt", ios::app);
            errorOutput << eline << endl;
        }
    }
    logWindows.close();
    cout << "The error index has been stored in error.txt" << endl;
}

int main()
{
    logWindows.open("event_log_windows_1000.txt");
    if(logWindows.is_open())
    {
        logWindows.close();
        getInformation();
        getWarning();
        getError();
    }
    else{
        cout << "The file cannot be accessed, please check the file name and location" << endl;
    }
    return 0;
}
