/*----------------------------------------------------------------------
Title   : Assignment
Author  : AS2020979
Version : 1.7
Remark  : System for ICT tuition class
----------------------------------------------------------------------*/

#include <stdio.h>
#include<stdlib.h>

int intexit;            //initialize a variable for exit
int intgetindex;        //initialize a variable for input index
int intindex;           //initialize a variable for available index
int intchoice;          //initialize a variable for choice
int intfees[2]={1500,1000};



struct
{
    char name[20];
    char address[10];
    char index[10];
    char classcode[10];
    char phonenumber[10];

}add,check;


/*-------------------------------------------------------------------
[Begin of the function declare block]
--------------------------------------------------------------------*/

void new_account();        //Declare new_account function
void view_profile();       //Declare view_profile function
void payment();            //Declare payment function
void close();              //Declare close function
void staff();              //Declare staff function
void back();               //Declare back function
void income();             //Declare fincome function
void view_list();          //Declare view_list function
void payment_records();    //Declare payment_records function
void invalid();            //Declare invalid function
void functionpaid();       //Declare funtionpaid function



/*-------------------------------------------------------------------
[End of the function declare block]
--------------------------------------------------------------------*/

/*-------------------------------------------------------------------
[Begin of the main function]
--------------------------------------------------------------------*/

int main()
{
    printf("\n\n  Welcome to A PLUS Institute\n");
    printf("\n\n\tPlease enter the last taken index number (4 digit integer / EX : 1000) ) :");     //User have to input the last taken index . Because then system can supply the next available index automatically. This institute use 4 digit index number format.
    scanf("%d",&intindex);


    menu();

    return 0;
}

/*-------------------------------------------------------------------
[End of the main function]
--------------------------------------------------------------------*/


/*-----------------------------------------------------------------
IMPORTANT DETAILS

O Every month system user need to reset the payments and paid text files.
O Index number is always given by the system when a new registration happens.
O This Institute is only for ICT subject under a one teacher. So the both AL and OL students fees calculated as one total income.

--------------------------------------------------------------------*/

/*---------------------------------------------------
[Begin of the menu function]
precondition : menu of the system
postcondition : choice made by the user
Description : Decide what to do next using system
-----------------------------------------------------*/

void menu (void)
{
    system("cls");   //Going to another window
    int intchoice;   //initialize a variable for choice made by the user

    //The main menu

    printf("\n\n\t\t\tA PLUS TUITION CLASS SYSTEM\n");
    printf("\n\t\t\tWelcome to the main menu\n\n\n");
    printf("\t1.Create a student account\n");
    printf("\t2.Pay fees\n");
    printf("\t3.View student profile\n");
    printf("\t4.Students records\n");
    printf("\t5.Payment records records\n");
    printf("\t6.Institute staff options\n");
    printf("\t7.Exit\n\n\n");


    printf("\tEnter your choice :");
    scanf("%d",&intchoice);

    //according to choice calling functions.

    switch(intchoice)
    {
        case 1:new_account();
        break;
        case 2:payment();
        break;
        case 3:view_profile();
        break;
        case 4:view_list();
        break;
        case 5:payment_records();
        break;
        case 6:staff();
        break;
        case 7:close();
        break;
        default :menu();

    }



}

/*---------------------------------------------------
[End of the menu function]
--------------------------------------------------*/

/*---------------------------------------------------
[Begin of the new_account function]
precondition : Students.txt
postcondition : printing values to students.txt as strings
Description : Get values from user and enter them to register him/her to this system
-----------------------------------------------------*/


void new_account()

{
    system("cls");                          //Going to another window
    intindex=intindex+1;                    //If new student come, by this system will automatically update the index numbers.


    system("cls");                          //Going to another window
    int intchoice;                          //initialize a variable for choice made by the user
    FILE *accounts;
    accounts=fopen("Students.txt","a+");    //open a file to append data


    printf("\n\nPlease enter %d as your index number.\n\n\n",intindex);                          //Giving the index number

    //Asking for details to create the account and assign the values for variables to write on a text file

    printf("--------------------------------------------------------------------------\n");
    printf("\t\t\tADD NEW ACCOUNT\n");
    printf("--------------------------------------------------------------------------\n\n\n");
    printf("Enter student's name with initials (A.B.C.Perera)                              : ");
    scanf("%s",add.name);
    printf("\nEnter Index                                                                    : ");
    scanf("%s",&add.index);
    add.index==check.index;
    printf("\nEnter city                                                                     : ");
    scanf("%s",add.address);
    printf("\nEnter phone number                                                             : ");
    scanf("%s",add.phonenumber);
    printf("\nEnter level ('OL' for grade 10 and 11 / 'AL' for grade 12,13 and after OLs  )  : ");
    scanf("%s",add.classcode);

    fprintf(accounts,"%20s\t%10s\t%10s\t%10s\t%10s\n",add.name,add.index,add.address,add.phonenumber,add.classcode);    //print values in a text file
    fclose(accounts);                                                                                                   //closing the text file (student.txt)

    printf("\n\nStudent account was created.\n");
    back();


}

/*---------------------------------------------------
[End of the new_account function]
--------------------------------------------------*/

/*---------------------------------------------------
[Begin of the new_profile function]
precondition  : Students.txt
postcondition : Asked Student profile
Description   : get values from text files and show it if it was asked
-----------------------------------------------------*/

void view_profile()
{


    FILE *accounts;
    accounts=fopen("Students.txt","r");                   //open a file to read data
    system("cls");                                        //Going to another window
    printf("Enter Index number (ex 1000/1111) :");
    scanf("%s",&check.index);


    printf("\n\n--------------------------------------------------------------------------\n");
    printf("                          Student Profile                                 \n");
    printf("--------------------------------------------------------------------------\n\n");

    while(fscanf(accounts,"%20s %10s %10s %10s %10s\n",&add.name,&add.index,&add.address,&add.phonenumber,&add.classcode)!=EOF)    //scan the input text file
    {

         if(strcmpi(add.index,check.index)==0)              //check if the input index number is equal to any record in the text file and identify it.
         {
             //if yes print the details according to this order

             printf("Index         : %s\n",add.index);
             printf("Name          : %s\n",add.name);
             printf("Address       : %s\n",add.address);
             printf("Class code    : %s\n",add.classcode);
             printf("Phone number  : %s\n",add.phonenumber);

         }


    }
    fclose(accounts);     //close the text file
    printf("\n");
    back();



}
/*---------------------------------------------------
[End of the new_profile function]
--------------------------------------------------*/


/*---------------------------------------------------
[Begin of the payment function]
precondition  : payments.txt , paid.txt
postcondition : list of paid students and list of amount to payments.txt
Description   : When student made a payment record it.
-----------------------------------------------------*/

void payment()
{
    int intchoice;                                //initialize a variable for choice made by the user
    int intconfirmation;                          //initialize a variable for confirm if he/her paid previous months fees
    int intstatus;                                //initialize a variable for identify the reason to not having the class card

    FILE *paid;
    paid=fopen("paid.txt","a+");                  //open a file to append data
    FILE *payments;
    payments=fopen("payments.txt","a+");          //open a file to append data
    system("cls");                                //Going to another window

    printf("--------------------------------------------------------------------------\n");
    printf("\t\t\tPayment Counter\n");
    printf("--------------------------------------------------------------------------\n\n");

    printf("\n\n\n\t1.Advance level Student\n");
    printf("\t2.Ordinary Level Student\n");
    printf("\t3.Exit\n\n\n");


    printf("Enter your choice :");
    scanf("%d",&intchoice);
    system("cls");                                 //Going to another window


    //according to choice display how much that student have to pay. For OLs its Rs.1000.00 for a month and for ALs it is Rs.1500.00 for a month.

    switch(intchoice)
    {
        case 1:
            //Asking for last month card to identify if that student paid for previous month or not.

            printf("--------------------------------------------------------------------------\n");
            printf("\t\tConfirm the last month payment by class card \n");
            printf("--------------------------------------------------------------------------\n\n");
            printf("\n\nIf the confirmation got press 1 or not press 2: ");
            scanf("%d",&intconfirmation);


            if (intconfirmation==1)
            {
                //if he paid display this month fees value and print his data on payment.txt to calculate the income as well as in paid.txt to identify him/her as paid student

                printf("\n\nYou can pay. Your payment is Rs.%d.00\n",intfees[intchoice-1]);
                functionpaid();
                fprintf(paid,"%6s %2s\n",add.index,"AL");
                fprintf(payments,"%d\n",1500);

             }
            else if (intconfirmation==2)
            {
                //if not ask the reason for not having card.If it was lost inform him/her to meet a staff member or if he didn't pay asking for two month payments.
                printf("\n\nIf you paid and lost your card press 1. Didn't paid 2.\n");
                scanf("%d", &intstatus);
                if (intstatus==1)
                {
                    printf("\nPlease meet our staff member\n");

                }
                if (intstatus==2)
                {
                    printf("\n\nYou can pay. Your payment is Rs.%d.00\n",(intfees[intchoice-1])*2);
                    functionpaid();
                    //print his data on payment.txt to calculate the income as well as in paid.txt to identify him/her as paid student
                    fprintf(paid,"%6s %2s\n",add.index,"AL");
                    fprintf(payments,"%d\n",3000);

                }
                else
                {
                    void invalid();
                }
            }
            else
            {
                void invalid();
            }


        break;
        case 2:
            //Asking for last month card to identify if that student paid for previous month or not.
             printf("\n\n\nConfirm your last month payment by class card \n");
             printf("\nIf the confirmation got press 1 or not press 2: ");
             scanf("%d",&intconfirmation);



             if (intconfirmation==1)
             {
                 //if he paid display this month fees value and print his data on payment.txt to calculate the income as well as in paid.txt to identify him/her as paid student
                 printf("\n\nYou can pay. Your payment is Rs.%d.00\n",intfees[intchoice-1]);
                 functionpaid();
                 fprintf(paid,"%6s %2s\n",add.index,"OL");
                 fprintf(payments,"%d\n",1000);

             }
             else if (intconfirmation==2)
             {
                 //if not ask the reason for not having card.If it was lost inform him/her to meet a staff member or if he didn't pay asking for two month payments.
                 printf("\nIf you paid and lost your card press 1. Didn't paid 2.\n");
                 scanf("%d", &intstatus);
                 if (intstatus==1)
                 {
                     printf("\nPlease meet our staff member\n");

                 }
                 else if (intstatus==2)
                 {

                     printf("\n\nYou can pay. Your payment is Rs.%d.00\n",(intfees[intchoice-1])*2);
                     functionpaid();
                     //print his data on payment.txt to calculate the income as well as in paid.txt to identify him/her as paid student
                     fprintf(paid,"%6s %2s\n",add.index,"OL");
                     fprintf(payments,"%d\n",2000);

                 }
                 else
                {
                    void invalid();
                }

             }
             else
            {
                void invalid();
            }


        break;
        case 3:close();
        break;
        default : payment();
    }
     //closing the text files
    fclose(paid);
    fclose(payments);
    back();

}
/*---------------------------------------------------
[End of the payment function]
--------------------------------------------------*/


/*---------------------------------------------------
[Begin of the close function]
precondition  :
postcondition : closing the system
Description   : Display authors name at the end of the system
-----------------------------------------------------*/

void close()
{
    printf("\n\n\nYeshani Niwarthana - AS2020979\n");


}

/*---------------------------------------------------
[End of the close function]
--------------------------------------------------*/


/*----------------------------------------------------------------------------------------------------
[Begin of the staff function]
precondition  : paid.txt
postcondition : Print values of paid amount
Description   : To prepare data to calculate the monthly income and print values in a text file.
                In the end of the month that text file transfer to an array and calculate the income.
-------------------------------------------------------------------------------------------------------*/

void staff()
{
    system("cls");           //Going to another window
    int intchoice;
    int password;           //initialize a variable for choice made by the user

    printf("Enter your password : ");
    scanf("%d",&password);
    if(password==1234)
    {
        printf("--------------------------------------------------------------------------\n");
        printf("\t\t\tA PLUS TUITION CLASS SYSTEM\n");
        printf("\t\t\t\tStaff options\n");
        printf("--------------------------------------------------------------------------\n\n");
        printf("If it is a new month, please reset the paid and payments documents \n\n\n");


        printf("\t1.Monthly income\n");
        printf("\t2.Exit\n\n\n");

        printf("Enter your choice :");
        scanf("%d",&intchoice);




        switch(intchoice)
        {
            case 1:income();
            break;

            case 2:close();
            break;
            default:invalid();


        }


    }
    else
    {
        printf("invalid password\n\n");
        back();
    }



}

/*---------------------------------------------------
[End of the staff function]
--------------------------------------------------*/


/*----------------------------------------------------------------------------------------------------
[Begin of the back function]
precondition  :
postcondition : come back to the main menu
Description   : To come back to the main menu to do another task without closing the system.
-------------------------------------------------------------------------------------------------------*/

void back()
{
    printf("Back to main menu press 1, to exit press 0:");
    scanf("%d",&intexit);

    if (intexit==1)
    {
        menu();
    }
    else if (intexit==0)
    {
        close();
    }
    else
    {
        invalid();
    }
}

/*---------------------------------------------------
[End of the back function]
--------------------------------------------------*/


/*----------------------------------------------------------------------------------------------------
[Begin of the income function]
precondition  : payments.txt
postcondition : Total income
Description   : To calculate the monthly by using text file.
-------------------------------------------------------------------------------------------------------*/

void income() {
    system("cls");  // Going to another window (Windows-specific)
    printf("--------------------------------------------------------------------------\n");
    printf("\t\t\tIncome of this month\n");
    printf("--------------------------------------------------------------------------\n\n");

    int intnumbers[100];  // Initialize a variable to array
    int intcount = 0;     // Initialize a variable for count
    int inttotal = 0;     // Initialize a variable for calculating the income (total)

    FILE *allfees;
    allfees = fopen("payments.txt", "r");  // Open a file to read data
    if (allfees == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Read integers from the file and calculate total income
    while (fscanf(allfees, "%d", &intnumbers[intcount]) == 1) {
        inttotal += intnumbers[intcount];
        intcount++;
    }

    fclose(allfees);

    // Print the total monthly income
    printf("\n\n\nTotal Monthly income is %d\n", inttotal);
    back();
}

/*---------------------------------------------------
[End of the income function]
--------------------------------------------------*/


/*----------------------------------------------------------------------------------------------------
[Begin of the view_list function]
precondition  : students.txt
postcondition : Print the all students details.
Description   : Get the student details from a text file and print all of them as a list.
-------------------------------------------------------------------------------------------------------*/

void view_list()
{
    FILE *view;
    view=fopen("Students.txt","r");               //open a file to read data
    system("cls");                                //Going to another window

    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("                            Student records of A PLUS Institute                                                           \n");
    printf("---------------------------------------------------------------------------------------------------------------------\n\n\n");
    printf("\t\tName\t\tINDEX\t\tCity\t\tPhone Number\t\t\tClass Code\n");
    printf("\n");
    while(fscanf(view,"%20s %10s %10s %10s %10s\n",&add.name,&add.index,&add.address,&add.phonenumber,&add.classcode)!=EOF)      //scan the text file
    {
        printf("%20s\t   %10s     %10s\t\t%10s\t\t       %10s\n",add.name,add.index,add.address,add.phonenumber,add.classcode);  //print values as a list

    }
    printf("\n\n");

    //closing the txt files
    fclose(view);
    back();



}

/*---------------------------------------------------
[End of the view_list function]
--------------------------------------------------*/


/*----------------------------------------------------------------------------------------------------
[Begin of the payment_records function]
precondition  : paid.txt
postcondition : Print who paid the class fees in past month
Description   : Get the paid student details from a text file and print all of them as a list.
-------------------------------------------------------------------------------------------------------*/


void payment_records()
{
    FILE *records;
    records=fopen("Paid.txt","r");         //open a file to read data
    system("cls");                         //Going to another window


    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("                                    Paid students in this month                                                         \n");
    printf("---------------------------------------------------------------------------------------------------------------------\n\n\n");
    printf("\tINDEX\t\t\tClass Code\n");
    printf("\n");
    while(fscanf(records,"%10s %10s\n",&add.index,&add.classcode)!=EOF)    //scan the text file
    {
        printf("   %10s\t\t\t%10s\n",add.index,add.classcode);             //display the values
    }
    printf("\n");

    //closing the text files
    fclose(records);
    back();

}


/*---------------------------------------------------
[End of the payment_records function]
--------------------------------------------------*/

/*---------------------------------------------------
[begin of the invalid function]
description : if givven command is invalid this will guide user to main menu
--------------------------------------------------*/

void invalid()
{
    printf("Invalid command\n\n");
    back();



}
/*---------------------------------------------------
[End of the invalid function]
--------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------
[Begin of the function paid function]
precondition  :
postcondition : get index of the paying student
Description   : To come back to the main menu to do another task without closing the system.
-------------------------------------------------------------------------------------------------------*/

void functionpaid()
{

    printf("Enter index number :");
    scanf("%s",add.index);
    printf("\nThank You! Payment was successful. \n\n");

}

/*---------------------------------------------------
[End of the function paid function]
--------------------------------------------------*/

