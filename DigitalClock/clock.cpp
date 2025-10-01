#include<iostream>//header file for input output stream
#include<ctime>//header file for date and time for eg localtime
#include<chrono>//header file for chrono library, used for time manipulation and formatting for eg system_clock
#include<iomanip>//header file for input output manipulation, used for formatting output for eg put_time
#include <windows.h> //header file for windows specific functions like Sleep()

using namespace std;//using standard namespace

int main()
{
    while(1)// infinite loop,it will used to continuously update and display the current time
    {
        auto current=chrono::system_clock::now();//get the current time from the system clock(means our computer clock time)
        //chrono::system_clock::now() returns the current time as a time_point object,which is fetched from the system clock

        time_t current_time=chrono::system_clock::to_time_t(current);//convert the current time to a time_t object
        //time_t is a data type used to represent time in C and C++ and to_time_t is a function that converts a time point to a time_t object

        tm *local_time=localtime(&current_time);//convert the time_t object to a tm* object representing local time
        //localtime is a function that converts a time_t object to a tm structure representing local time
        //tm is a structure that holds various components of time such as hour, minute, second, etc.


        //for clearing the console screen after every 1 second
        system("cls");//this is  for only windows operating system
        //system("clear");//this is for linux and mac operating system

        cout<<put_time(local_time,"%I:%M:%S %p")<<endl;//display the current time in the format HH:MM:SS AM/PM
        //put_time is a manipulator that formats the time according to the specified format string
        //%I is for hour in 12-hour format, %M is for minute, %S is for second, %p is for AM/PM


       //introduce a delay of 1 second before updating the time again
        Sleep(1000); // Sleep for 1000 milliseconds (1 second)
        //this_thread::sleep_for is a function that makes the current thread sleep for the specified duration for eg 1 second here

    }
    return 0;
}