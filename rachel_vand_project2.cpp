/*******************************************************************************
Name:       Rachel Vanderlerly
Due Date:   September 30 2022
Class:      Network Programming
Profesor:   Dr.Zhao
Assignment: Program 2
Description: This program converts an IP v4 address, such as 198.17.223.4 
into network byte order in binary format, and then convert the binary value 
into an equivalent decimal value, and then print the IP v4 address, 
binary stream, and decimal value.  
*******************************************************************************/ 
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <string.h>
#define MAXSIZE 80

using std::cout;
using std::cin;
using std::string;

/****************************************************
                Function Prototypes
*****************************************************/
void decimal_to_binary(unsigned int changeme, char* destination);    

/***************************************************
                        Main 
*****************************************************/
int main()
    {
    char IPV4_address[MAXSIZE];            //A string holding the users input IPV4 address
    char* IPV4_2D[4];                      //To hold the ipv4 numbers without the . in them
	char binary_big_endian[MAXSIZE];       //Holds the binary big endian value
    char binary_little_endian[MAXSIZE];    //Holds the binary big endian value
    unsigned int big_decimal;              //hold the decimal number big endian
    unsigned int little_decimal;           //hold the decimal number big endian
    struct sockaddr_in mine;
    string answer = "Y";

while (answer == "Y" || answer =="y")
    {
    //Get the IPV4 Address
    cout<<"Enter an IP4 Address:";
    fgets(IPV4_address,MAXSIZE,stdin);
	IPV4_address[strlen(IPV4_address)-1] = '\0';
	cout<<"\n\t\tIP Address Entered: "<<IPV4_address<<"\n";
	cout<<"\t\t-----------------------------------\n";

    //Convert your IP4 Address to binary using pton function
    inet_pton(AF_INET,IPV4_address,&(mine.sin_addr));
    big_decimal = mine.sin_addr.s_addr;
    cout<<"Big Endian Decimal Value:    "<<big_decimal<<"\n";

    //Convert decimal to binary with dec to binary function and print
    decimal_to_binary(big_decimal,binary_big_endian);
    printf("Big Endian Binary Value:     %s \n",binary_big_endian);

    //convert decimal big endian to decimal little endian and print
    little_decimal = ntohl(big_decimal);
    cout<<"Little Endian Decimal Value: "<<little_decimal<<"\n";

    //Convert decimal little endian to binary little endian and print
    decimal_to_binary(little_decimal,binary_little_endian);
    cout<<"Little Endian Binary Value:  "<<binary_little_endian<<"\n";

    //Prompt user to run again
    cout<<"\nDo you want to run again?";
    cin>>answer;
    cin.ignore();
    }
return 0;
}

/*********************************************************
                    decimal_to_binary 
This function converts an unsigned int, changeme to a 
binary number and saves it in a char string, destination.
**********************************************************/
void decimal_to_binary(unsigned int changeme, char* destination)
{
int counter = 0;
std::stack<char> st;
int remainder;
for(counter = 0; counter < 32; counter++){
    if(changeme % 2 == 0){
        st.push('0');
    }else{
        st.push('1');
    }
    changeme/= 2;
}
    counter = 0;
    while(!st.empty()){
        destination[counter] = st.top();
        st.pop();
        counter++;
    }
    destination[counter] = '\0';
};
