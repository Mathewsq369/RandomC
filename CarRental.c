#include <stdio.h>
int hours(int car);
float calculateCharges(int hrs);
void table(int car, int hours, float charge);

int main()
{
    unsigned int count = 0;
    int car1 = hours(1), car2 = hours(2) , car3 = hours(3);

    // Output
    //printf("%2dCar%13dHours%21.2fCharge");
    table(1,car1,calculateCharges(car1));
    table(2,car2,calculateCharges(car2));
    table(3,car3,calculateCharges(car3));
    printf("TOTAL %d%f",hours,charge)
    return 0;
}

int hours(int car)
{
    int hours = 0;
    printf("\nInput the hours rented for car%d:", car);
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
            charges = 50 + 0.5 * hrs;
        }
        else
        {
            rem = hrs - 8;
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
            charges = 24 * 0.5 + calculateCharges(rem) + calculateCharges(24);
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
            charges = 48 * 0.5 + calculateCharges(48) + calculateCharges(rem);
        }
    }

    return charges;
}

void table(int car,int hours,float charge)
{
    printf("%2d%13d%21f",car,hours,charge);
}