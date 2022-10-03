/*
Name:       Rachel Vanderlerly
Due Date:   September 30 2022
Class:      Network Programming
Profesor:   Dr.Zhao
Assignment: Program 2
Description: This program converts an IP v4 address, such as 198.17.223.4 
into network byte order in binary format, and then convert the binary value 
into an equivalent decimal value, and then print the IP v4 address, 
binary stream, and decimal value.  
*/ 
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

/**************************
    Function Prototypes
***************************/
void decimal_to_binary(unsigned int changeme, char* destination);    

/**************************
           Main 
***************************/
int main()
    {
    char IPV4_address[MAXSIZE];         //A string holding the users input IPV4 address
    char* IPV4_2D[4];                   //To hold the ipv4 numbers without the . in them
	char binary_big_endian[MAXSIZE];
    unsigned int big_decimal;           //hold the decimal number big endian
    struct sockaddr_in mine;
    std::string answer = "Y";

while (answer == "Y" || answer =="y")
    {

    //Get the IPV4 Address
    cout<<"Enter an IP4 Address:";
    fgets(IPV4_address,MAXSIZE,stdin);
	IPV4_address[strlen(IPV4_address)-1] = '\0';
    printf("Your IPV4 address is %s \n",IPV4_address);
		
    //Convert your IP Address to binary
    cout<<inet_pton(AF_INET,IPV4_address,&(mine.sin_addr));
    //cout<<" is the result of your inet_pton() call\n";
    cout<<"Your result of inet_pton on IPV4 is "<<mine.sin_addr.s_addr<<"\n";
    big_decimal = mine.sin_addr.s_addr;
    cout<<"Your result of inet_pton on IPV4 is "<<big_decimal<<"\n";
    //htonl(mine.sin_addr.s_addr);

    //Convert the number in s_addr to binary. 
    //Right now its the decimal equivelent inside mine.sin_addr.s_addr
    decimal_to_binary(big_decimal,binary_big_endian);
    printf("\nThe BIG endian of the binary number is %s \n",binary_big_endian);

    //Try to get little endian to print
    //little_decimal = ntohl(big_decimal);
    //cout<<"The little decimal is "<<little_decimal<<"\n";


    cout<<"Do you want to run again?";
    cin>>answer;
    cin.ignore();
    }
return 0;
}

void decimal_to_binary(unsigned int changeme, char* destination)
{
int counter = 0;
std::stack<char> st;
int remainder;
for(counter = 0; counter < 32; counter++)
{
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












// //This function takes an unsigned integer and turns it to a char pointer containing the decimal equivelent. 
// void decimal_to_binary(unsigned int changeme, char* destination)
// {
// int counter = 0;
// int remainder;
// for(counter = 0; counter < 32; counter++)
//     {
// 				std::cout << "in forloop ";
//         remainder = changeme % 2;
//         if (remainder == 1){
//             destination[counter]= '1';
//             //cout<<"I am adding 1 to spot"<<counter<<"\n";
//         }
//         else{
//             destination[counter] = '0';
//             //cout<<"I am adding 0 to spot"<<counter<<"\n";
//         }
//         changeme = changeme / 2;
//     }
// 		destination[counter] = '\0';
//     cout<<"Changing the number to bianry";
// };



