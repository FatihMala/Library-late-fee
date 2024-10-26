#include <stdio.h>



int substractDays(int, int, int, int, int, int);
double calculateLateFee(int);


int main(void)
{

    // below are for the date that the user borrowed the book
    int dueDay, dueMonth, dueYear;
    // below are for the date that the user returned the book
    int returnDay, returnMonth, returnYear;
    // day difference between two dates
    int dayDifference;
    // late fee will be returned to lateFee variable
    double lateFee;

    printf("enter due date DD MM YY: ");//Enter dates in the following format  12 12 2023
    scanf("%d%d%d", &dueDay, &dueMonth, &dueYear);

    printf("enter return date DD MM YY: ");//Enter dates in the following format 12 5 2023
    scanf("%d%d%d", &returnDay, &returnMonth, &returnYear);

    // call the substractDays function
    dayDifference = substractDays(dueDay, dueMonth, dueYear, returnDay, returnMonth, returnYear);
    // call the calculateLateFee function and get the lateFee
    lateFee = calculateLateFee(dayDifference);
    // display the output
    printf("You are late %d days and your late fee is %.3lf.", dayDifference, lateFee);
    return 0;
}


int substractDays(int dueDay, int dueMonth, int dueYear, int returnDay, int returnMonth, int returnYear)
{
    int dayDifference,monthDifference,yearDifference,totalDayDifference;
    //In the code below, day, month and year differences are calculated.
    dayDifference=returnDay - dueDay;
    monthDifference=returnMonth - dueMonth;
    yearDifference=returnYear - dueYear;
    //All differences are written in days and the total days are calculated.
    totalDayDifference= dayDifference + monthDifference*30 + yearDifference*360;

    //We find out if the user has submitted the book before.
    if (totalDayDifference>0)
    {


        return totalDayDifference;
    }
    else
    {
        return 0;
    }



}




double calculateLateFee(int dayslate)//
{
    int lateFee;

    if(dayslate<=5)//Here the fee for 5 and less than 5 days is calculated
    {
        lateFee=dayslate*10;//To find the late fee, we multiply the delay day by 10.
        return lateFee;

    }
    else if(6<=dayslate && dayslate<=15)//Here the late fee is calculated for between 6 and 15 days.
    {
    lateFee =50+(dayslate-5)*15;//Late fee is 10 lira per day for the first 5 days. 15 lira per day for the remaining days
    return lateFee;
    }
    else if(16<=dayslate && dayslate<=30)//Here the late fee is calculated for between 16 and 30 days.
    {
        lateFee = 225+ (dayslate-15)*20;//Late fee is 15 lira per day for the first 15 days.
        //20 lira per day for the remaining days
        return lateFee;
    }
    else if(30<dayslate)//Here late fee is calculated for more than 30 days
    {
        lateFee= dayslate*20;//Late fee is 20 lira per day for late days.
        return lateFee;
    }
    else
    {

        return 0;//The book has already been brought.
    }





}
