
#include<iostream>
using namespace std;

struct Environment
{
    float temperature;
    float humidity;
    float pollution;
};

int main()
{
    Environment data[50], temp;
    int n;

    cout<<"Enter number of readings: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter Temperature: ";
        cin>>data[i].temperature;

        cout<<"Enter Humidity: ";
        cin>>data[i].humidity;

        cout<<"Enter Pollution: ";
        cin>>data[i].pollution;
    }

    float maxTemp=data[0].temperature;
    float minTemp=data[0].temperature;

    float maxHum=data[0].humidity;
    float minHum=data[0].humidity;

    float maxPoll=data[0].pollution;
    float minPoll=data[0].pollution;

    float sumTemp=0, sumHum=0, sumPoll=0;

    for(int i=0; i<n; i++)
    {
        if(data[i].temperature>maxTemp)
            maxTemp=data[i].temperature;

        if(data[i].temperature<minTemp)
            minTemp=data[i].temperature;

        if(data[i].humidity>maxHum)
            maxHum=data[i].humidity;

        if(data[i].humidity<minHum)
            minHum=data[i].humidity;

        if(data[i].pollution>maxPoll)
            maxPoll=data[i].pollution;

        if(data[i].pollution<minPoll)
            minPoll=data[i].pollution;

        sumTemp=sumTemp+data[i].temperature;
        sumHum=sumHum+data[i].humidity;
        sumPoll=sumPoll+data[i].pollution;
    }

    cout<<"\nMaximum Temperature: "<<maxTemp;
    cout<<"\nMinimum Temperature: "<<minTemp;

    cout<<"\nMaximum Humidity: "<<maxHum;
    cout<<"\nMinimum Humidity: "<<minHum;

    cout<<"\nMaximum Pollution: "<<maxPoll;
    cout<<"\nMinimum Pollution: "<<minPoll;

    cout<<"\nAverage Temperature: "<<sumTemp/n;
    cout<<"\nAverage Humidity: "<<sumHum/n;
    cout<<"\nAverage Pollution: "<<sumPoll/n;

    // Sorting according to temperature

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(data[j].temperature>data[j+1].temperature)
            {
                temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
    }

    cout<<"\n\nSorted Data according to Temperature:\n";

    for(int i=0; i<n; i++)
    {
        cout<<data[i].temperature<<"  ";
        cout<<data[i].humidity<<"  ";
        cout<<data[i].pollution<<endl;
    }

    // Safe pollution range

    int found=0;
    float safeMin=0, safeMax=0;

    for(int i=0; i<n; i++)
    {
        if(data[i].pollution<=50)
        {
            if(found==0)
            {
                safeMin=data[i].pollution;
                safeMax=data[i].pollution;
                found=1;
            }

            if(data[i].pollution<safeMin)
                safeMin=data[i].pollution;

            if(data[i].pollution>safeMax)
                safeMax=data[i].pollution;
        }
    }

    if(found==1)
    {
        cout<<"\nLowest Safe Pollution: "<<safeMin;
        cout<<"\nHighest Safe Pollution: "<<safeMax;
    }
    else
    {
        cout<<"\nNo Safe Pollution Reading";
    }

    // Environmental Impact and Health Safety

    for(int i=0; i<n; i++)
    {
        cout<<"\n\nReading "<<i+1;

        if(data[i].pollution>100)
            cout<<"\nEnvironmental Impact: High Risk";
        else if(data[i].pollution>50)
            cout<<"\nEnvironmental Impact: Moderate";
        else
            cout<<"\nEnvironmental Impact: Safe";

        if(data[i].temperature>35)
            cout<<"\nHealth: Heat Risk";

        if(data[i].pollution>100)
            cout<<"\nHealth: Respiratory Risk";

        if(data[i].humidity<30 || data[i].humidity>70)
            cout<<"\nHealth: Humidity Risk";
    }

    cout<<"\n\nPrivacy: No personal data is collected.";
    cout<<"\nData is used only during this program.";

    return 0;
}
