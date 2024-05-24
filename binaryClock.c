#include <stdio.h>
#include <time.h>
#include <math.h>

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

int GetSize (char * s) 
{
    char * t;    
    for (t = s; *t != '\0'; ++t)
        ;
    return t - s;
} 

void TrySetUnitFlag(char c[], int tUnit, int pos, int offset)
{
    if (CHECK_BIT(tUnit, pos))
    {
        c[offset - pos] = '|';
    }        
}

char* RecursiveFlagSetter(int time, char c[], int position)
{
    if (time == 0)
    {
        return c;
    }

    int r = time % (int) (pow(2,5-position)); 
    if (time != r)
    {
        c[position] = '|';
    }
    return RecursiveFlagSetter(r,c,++position);
}

void BinaryClockPrinterV1(int hrs, int mins, int secs)
{
    char hrStr[6] = "000000";
    char mStr[6] = "000000"; 
    char sStr[6] = "000000"; 

    for (int i = 5; i >= 0; i--)
    {
        TrySetUnitFlag(hrStr,hrs, i, 5);
        TrySetUnitFlag(mStr,mins, i, 5); 
        TrySetUnitFlag(sStr,secs, i, 5);
    }        

    printf("bitflag version: \n");
    printf("%.6s - hours\n", hrStr);
    printf("%.6s - minutes\n", mStr);
    printf("%.6s - seconds\n\n", sStr);
}

void BinaryClockPrinterV2(int hours, int minutes, int seconds)
{
    char hrStr2[6] = "000000";
    char mStr2[6] = "000000"; 
    char sStr2[6] = "000000"; 

    char* recursiveHrs = RecursiveFlagSetter(hours,hrStr2, 0);
    char* recursiveMins = RecursiveFlagSetter(minutes,mStr2, 0);
    char* RecursiveSecs = RecursiveFlagSetter(seconds, sStr2, 0);

    printf("Recursive version: \n");
    printf("%.6s - hours\n", recursiveHrs);
    printf("%.6s - minutes\n", recursiveMins);
    printf("%.6s - seconds\n", RecursiveSecs);
}

// code contributed by Susobhan Akhuli
void TernaryUsageExample(int yr)
{
    // check whether a year is leap year or not 
    (yr%4==0) ? (yr%100!=0? printf("The year %d is a leap year",yr) 
            : (yr%400==0 ? printf("The year %d is a leap year",yr) 
                : printf("The year %d is not a leap year",yr))) 
        : printf("The year %d is not a leap year",yr);   
}

void ExampleUsageGetSize()
{
    char* sizeTest = "ShitPoopAssPoop";
    printf("Size of string %s: %i\n",sizeTest,GetSize(sizeTest));
}


void NestedScopedMethodsExample()
{
   auto int view(); // declare function with auto keyword 
   view(); 
   printf("Main\n"); 

   int view() 
   { 
       printf("View\n"); 
       return 1; 
   } 
}

void TimeExamples()
{
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    printf("%s", asctime(ptr));

    int hours = ptr->tm_hour;
    int minutes = ptr->tm_min;
    int seconds = ptr->tm_sec;

    printf("Standard 24-hr time:");
    printf("%i hours, %i minutes, %i seconds\n\n", hours, minutes, seconds);

    BinaryClockPrinterV1(hours, minutes, seconds);
    BinaryClockPrinterV2(hours, minutes, seconds);
}

void UsingPow()
{
    printf("Try printing result of 10 to power of 2: %.3i", (int)pow(10,2));
    printf("Try printing result of 10 to power of 2: %.3a", pow(10,2));
}

int main(void)
{
    NestedScopedMethodsExample();
    TimeExamples();
    return 0;
}

