#include<stdio.h>
#include<string.h>

float unit_cal(float unit, float charge)
{
    float amount;
    if(unit>=0 && unit<120)
        amount=(unit*20.21)+(unit*charge);
    else if(unit>=120 && unit<=300)
        amount=(unit*25.61)+(unit*charge);
    else if(unit>300)
        amount=(unit*28.59)+(unit*charge);
    return amount;

}

int main()
{
    char a='%';
    float unit,regional_charge,pp_charge,basic_amount,re_charge,total_charge,rebate;
    char meter_number[11];
    puts("Enter Your Meter's UI Number:");
    scanf("%s",meter_number);
    puts("Enter Consumption Unit(KWh):");
    scanf("%f",&unit);

    //Identify region & apply region charge:
    printf("\n\n");
    if(meter_number[2]=='0')
    {
        puts("Hokkaido Electric Power Company(HEPCO)");
        printf("Region: Hokkaido Prefecture\n");
        regional_charge=280.25;
    }
    else if(meter_number[2]=='1')
    {
        puts("Tokyo Electric Power Company(TEPCO)");
        printf("Region: Tokyo Prefecture\n");
        regional_charge=350.50;
    }
    else if(meter_number[2]=='2')
    {
        puts("Kansai Electric Power Company(KEPCO)");
        printf("Region: Kansai Prefecture\n");
        regional_charge=235.60;
    }
    else if(meter_number[2]=='3')
    {
        puts("Kyushu Electric Power Company(KYUDEN)");
        printf("Region: Kyushu Prefecture\n");
        regional_charge=175.40;
    }
    else if(meter_number[2]=='4')
    {
        puts("Okinawa Electric Power Company(OKIDEN)");
        printf("Region: Okinawa Prefecture\n");
        regional_charge=225.55;
    }
    else
    {
        puts("No Region Found !!!");
        printf("Region: N/A\n");
        regional_charge=0.00;
    }




    //Identify & print meter number:
    printf("Meter No.:                                    ");
    for(int i=4; i<9; i++)printf("%c",meter_number[i]);
    printf("\n");




    //Identify user category & apply category rate:
    if(meter_number[10]=='A')
    {
        printf("Category:                        Residential(1DK1R)\n");
        pp_charge=1.10;
    }
    else if(meter_number[10]=='B')
    {
        printf("Category:                        Residential(1DK2R)\n");
        pp_charge=1.20;
    }
    else if(meter_number[10]=='C')
    {
        printf("Category:                          Industry Level-1\n");
        pp_charge=1.60;
    }
    else if(meter_number[10]=='D')
    {
        printf("Category:                          Industry Level-2\n");
        pp_charge=1.80;
    }
    else if(meter_number[10]=='E')
    {
        printf("Category:                       Commercial & Office\n");
        pp_charge=2.00;
    }
    else if(meter_number[10]=='F')
    {
        printf("Category:                                 Temporary\n");
        pp_charge=1.50;
    }
    else
    {
        printf("Category:                                       N/A\n");
        pp_charge=0.00;
    }



    //Print basic amount:
    basic_amount=unit_cal(unit,pp_charge);
    re_charge=(basic_amount*1.0005)/100;
    total_charge=basic_amount+re_charge+regional_charge;
    rebate=(total_charge*2.43)/100;
    printf("Power Plan Rate(per unit):                 %.2f JPY\n",pp_charge);
    printf("Basic Power Charge:                     %.2f JPY\n",basic_amount);
    printf("Renewable Energy Surcharges(1.0005%c):     %.2f JPY\n",a,re_charge);
    printf("Regional Charge(monthly):                %.2f JPY\n",regional_charge);
    printf("Total Energy Cost:                      %.2f JPY\n",total_charge);
    printf("Govt. Rebate of 2024(2.43%c):            -%.2f JPY\n",a,rebate);
    printf("Total Amount to Pay:                    %.2f JPY\n",total_charge-rebate);
    printf("\nby arasaka_arc\n\n\n\n");

}
