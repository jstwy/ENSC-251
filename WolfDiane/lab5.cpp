#include <iostream>
#include <string>

void printPrompt();
void validSize(std::string& timeString);
void validChars(std::string& timeString);
void validHours(std::string& timeString);
void validMins(std::string& timeString);
//void printError(std::string& timeString);
//int extractHour(std::string& timeString);
//int extractMinute(std::string& timeString);
bool tryAgain();
void endMessage();

int main()
{
    std::string userTime;
    
    do
    {
        printPrompt();
        try
        {
            std::cin >> userTime;
            validSize(userTime);
            validChars(userTime);
            validHours(userTime);
            validMins(userTime);
        }
        catch(std::string& e)
        {
            std::cout << "There is no such time as "
                      << e
                      << "\n";
        }    
    } while (tryAgain());
    
    endMessage();
    return 0;
}

void printPrompt()
{
    std::cout << "Enter time in 24-hour notation\n";
}

void validSize(std::string& timeString)
{
    if (timeString.size() < 4 || timeString.size() > 5)
    {
        throw timeString;
    }
}

void validChars(std::string& timeString)
{
    bool hasColon;
    hasColon = false;
    for (unsigned int i = 0; i < timeString.size(); i++)
    {
        if (!isdigit(timeString.at(i)) && timeString.at(i) != ':')
        {
            throw timeString;
        }
        else if (timeString.at(i) == ':')
        {
            hasColon = true;
        }
    }
    if (hasColon == false)
    {
        throw timeString;
    }
}

void validHours(std::string& timeString)
{
    int hour;
    
    if (timeString.size() == 4)
    {
        hour = std::stoi(timeString.substr(0));
    }
    else
    {
        hour = std::stoi(timeString.substr(0,1));
    }
    
    if (hour > 23)
    {
        throw timeString;
    }
}

void validMins(std::string& timeString)
{
    int mins;
    
    if (timeString.size() == 4)
    {
        mins = std::stoi(timeString.substr(2,3));
    }
    else
    {
        mins = std::stoi(timeString.substr(3,4));
    }
    
    if (mins > 59)
    {
        throw timeString;
    }
}
/*
void printError(std::string& timeString)
{
    std::cout << "There is no such time as "
              << timeString
              << "\n";
}

int extractHour(std::string& timeString)
{
    int hour;
    char strPos;
    
    for (int i = 0; i < timeString.strlen(); i++)
    {
        strPos = timeString.at(i);
        if (strPos == ':')
        {
            hour = 
        }
    }
}

int extractMinute(std::string& timeString)
{
    
}
*/
bool tryAgain()
{
    char ans;
    std::cout << "Again? (y/n)\n";
    std::cin >> ans;
    if (ans == 'n' || ans == 'N')
    {
        return false;
    }
    else if (ans == 'y' || ans == 'Y')
    {
        return true;
    }
    else
    {
        std::cout << "Invalid command. Terminating program...\n";
        return false;
    }
}

void endMessage()
{
    std::cout << "End of program\n";
}