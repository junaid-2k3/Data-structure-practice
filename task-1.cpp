#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int WEEKS = 4;
const int DAYS = 7;

void fillArray(int temps[WEEKS][DAYS])
{
    srand(time(0)); 
    for (int i = 0; i < WEEKS; i++)
    {
        for (int j = 0; j < DAYS; j++)
        {
            temps[i][j] = rand() % 21 + 10; // random values for the temperature
        }
    }
}

void displayArray(int temps[WEEKS][DAYS])
{
    for (int i = 0; i < WEEKS; i++)
    {
        for (int j = 0; j < DAYS; j++)
        {
            cout << temps[i][j] << " ";
        }
        cout << endl;
    }
}

void Find_hottest_day(int temps[WEEKS][DAYS])
{
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    for (int i = 0; i < WEEKS; i++)
    {
        int maxTemp = temps[i][0]; 
        int maxDayIndex = 0;

        for (int j = 1; j < DAYS; j++)
        {
            if (temps[i][j] > maxTemp)
            {
                maxTemp = temps[i][j];
                maxDayIndex = j;
            }
        }

        cout << "Hottest day of week " << i + 1 << " is: "
             << days[maxDayIndex] << " having a temperature: " << maxTemp << endl;
    }
}

int main()
{
    int temperatures[WEEKS][DAYS];

    fillArray(temperatures);
    cout << "Temperatures of each week:" << endl;
    
    displayArray(temperatures);

    cout << endl;
    Find_hottest_day(temperatures);

    return 0;
}
