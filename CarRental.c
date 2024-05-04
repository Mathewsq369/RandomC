#include <stdio.h>
int hours(int car);
float calculateCharges(int hrs);

int main()
{
    unsigned int count = 0;
    int car1 = hours(1), car2 = hours(2) , car3 = hours(3);

    // Output
    printf("%s%13s%18s\n","Car","Hours","Charges");
    printf("%2d%13d%18.2f\n",1,car1,calculateCharges(car1));
    printf("%2d%13d%18.2f\n",2,car2,calculateCharges(car2));
    printf("%2d%13d%18.2f\n",3,car3,calculateCharges(car3));
    printf("TOTAL %9d%18.2f\n",car1 + car2 + car3,calculateCharges(car1) + calculateCharges(car2) + calculateCharges(car3));
    return 0;
}

int hours(int car)
{
    int hours = 0;
    printf("Input the hours rented for car%d:", car);
    scanf("%d", &hours);
    return hours;
}

float calculateCharges(int hrs)
{
    int rem = 0;
    float charges = 0;

    if (24 >= hrs)
    {
        if (24 == hrs)
        {
            charges = 50 + 0.5 * 24;
        }
        else
        {
            if (hrs > 8)
            {
                rem = hrs - 8;
            }
            charges = 25 + 5 * rem + hrs * 0.5;
        }
    }
    else if (48 >= hrs && 24 < hrs)
    {
        if (48 == hrs)
        {
            charges = 2 * (calculateCharges(24));
        }
        else
        {
            rem = hrs - 24;
            charges = calculateCharges(rem) + calculateCharges(24);
        }
    }
    else if (72 >= hrs && 48 < hrs)
    {
        if (72 == hrs)
        {
            charges = 3 * (calculateCharges(24));
        }
        else
        {
            rem = hrs - 48;
            charges = calculateCharges(48) + calculateCharges(rem);
        }
    }

    return charges;
}