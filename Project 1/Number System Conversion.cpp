#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
using namespace std;

// Function to convert binary to decimal
int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

void decToOctal(int n)
{

    // array to store octal number
    int octalNum[100];

    // counter for octal number array
    int i = 0;
    while (n != 0) {

        // storing remainder in octal array
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }

    // printing octal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << octalNum[j];
}


int octalToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 8^0
    int base = 1;

    int temp = num;
    while (temp) {

        // Extracting last digit
        int last_digit = temp % 10;
        temp = temp / 10;

        // Multiplying last digit with appropriate
        // base value and adding it to dec_value
        dec_value += last_digit * base;

        base = base * 8;
    }

    return dec_value;
}

void decToHexa(int n)
{
    // char array to store hexadecimal number
    char hexaDeciNum[100];

    // counter for hexadecimal number array
    int i = 0;
    while(n!=0)
    {
        // temporary variable to store remainder
        int temp  = 0;

        // storing remainder in temp variable.
        temp = n % 16;

        // check if temp < 10
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }

        n = n/16;
    }

    // printing hexadecimal number array in reverse order
    for(int j=i-1; j>=0; j--)
        cout << hexaDeciNum[j];
}

void HexToBin(string hexdec)
{
    long int i = 0;

    while (hexdec[i]) {

        switch (hexdec[i]) {
        case '0':
            cout << "0000";
            break;
        case '1':
            cout << "0001";
            break;
        case '2':
            cout << "0010";
            break;
        case '3':
            cout << "0011";
            break;
        case '4':
            cout << "0100";
            break;
        case '5':
            cout << "0101";
            break;
        case '6':
            cout << "0110";
            break;
        case '7':
            cout << "0111";
            break;
        case '8':
            cout << "1000";
            break;
        case '9':
            cout << "1001";
            break;
        case 'A':
        case 'a':
            cout << "1010";
            break;
        case 'B':
        case 'b':
            cout << "1011";
            break;
        case 'C':
        case 'c':
            cout << "1100";
            break;
        case 'D':
        case 'd':
            cout << "1101";
            break;
        case 'E':
        case 'e':
            cout << "1110";
            break;
        case 'F':
        case 'f':
            cout << "1111";
            break;
        default:
            cout << "\nInvalid hexadecimal digit "
                 << hexdec[i];
        }
        i++;
    }
}


string OctToBin(string octnum)
{
    long int i = 0;

    string binary = "";

    while (octnum[i]) {
        switch (octnum[i]) {
        case '0':
            binary += "000";
            break;
        case '1':
            binary += "001";
            break;
        case '2':
            binary += "010";
            break;
        case '3':
            binary += "011";
            break;
        case '4':
            binary += "100";
            break;
        case '5':
            binary += "101";
            break;
        case '6':
            binary += "110";
            break;
        case '7':
            binary += "111";
            break;
        default:
            cout << "\nInvalid Octal Digit "
                 << octnum[i];
            break;
        }
        i++;
    }
    return binary;
}


long long int hex_to_bin(char hex[])
{
    long long int bin, place;
    int i = 0, rem, val;

    bin = 0ll;
    place = 0ll;

    // Hexadecimal to binary conversion
    for (i = 0; hex[i] != '\0'; i++) {
        bin = bin * place;

        switch (hex[i]) {
        case '0':
            bin += 0;
            break;
        case '1':
            bin += 1;
            break;
        case '2':
            bin += 10;
            break;
        case '3':
            bin += 11;
            break;
        case '4':
            bin += 100;
            break;
        case '5':
            bin += 101;
            break;
        case '6':
            bin += 110;
            break;
        case '7':
            bin += 111;
            break;
        case '8':
            bin += 1000;
            break;
        case '9':
            bin += 1001;
            break;
        case 'a':
        case 'A':
            bin += 1010;
            break;
        case 'b':
        case 'B':
            bin += 1011;
            break;
        case 'c':
        case 'C':
            bin += 1100;
            break;
        case 'd':
        case 'D':
            bin += 1101;
            break;
        case 'e':
        case 'E':
            bin += 1110;
            break;
        case 'f':
        case 'F':
            bin += 1111;
            break;
        default:
            cout << "Invalid hexadecimal input.";
        }

        place = 10000;
    }

    return bin;
}

// Function to convert Binary to Octal
long long int bin_to_oct(long long bin)
{
    long long int octal, place;
    int i = 0, rem, val;

    octal = 0ll;
    place = 0ll;

    place = 1;

    // Binary to octal conversion
    while (bin > 0) {
        rem = bin % 1000;

        switch (rem) {
        case 0:
            val = 0;
            break;
        case 1:
            val = 1;
            break;
        case 10:
            val = 2;
            break;
        case 11:
            val = 3;
            break;
        case 100:
            val = 4;
            break;
        case 101:
            val = 5;
            break;
        case 110:
            val = 6;
            break;
        case 111:
            val = 7;
            break;
        }

        octal = (val * place) + octal;
        bin /= 1000;

        place *= 10;
    }

    return octal;
}

// Function to Convert
// Hexadecimal Number to Octal Number
long long int hex_to_oct(char hex[])
{
    long long int octal, bin;

    // convert HexaDecimal to Binary
    bin = hex_to_bin(hex);

    // convert Binary to Octal
    octal = bin_to_oct(bin);

    return octal;
}



int main(){
    int t;
    cout<<"Menu"<<endl;
    cout<<"1.binary to decimal"<<endl;
    cout<<"2.decimal to binary"<<endl;
    cout<<"3.decimal to octal"<<endl;
    cout<<"4.octal to decimal"<<endl;
    cout<<"5.binary to hexa"<<endl;
    cout<<"6.hexa to binary"<<endl;
    cout<<"7.hexa to octa"<<endl;
    cout<<"8.octal to hexa"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>t;
int n,d,x=0,de;
string s,sr,p;
char hex[20];

switch(t){
    case 1:
        cout<<"enter the binary no"<<endl;
        cin>>n;
        cout<<binaryToDecimal(n);
        break;

    case 2:
        cout<<"enter the decimal no"<<endl;
        cin>>n;
        decToBinary(n);
        break;

    case 3:
        cout<<"enter the decimal no"<<endl;
        cin>>n;
        decToOctal(n);
        break;

    case 4:
        cout<<"enter the octal no"<<endl;
        cin>>n;
        cout<<octalToDecimal(n);
        break;

    case 5:
            //int n,d;
            cout<<"enter the binary no"<<endl;
            cin>>n;
            d=binaryToDecimal(n);
            decToHexa(d);
            break;
    case 6:
            //string s;
            cout<<"enter the hexadecimal no";
            cin>>s;
            HexToBin(s);
            break;
    case 7:
            //string sr,p;
           cout<<"enter the hexadecimal no";
           cin>>hex;
           cout<<hex_to_oct(hex);
           break;

    case 8:


            cout<<"enter the octal no";
            cin>>sr;
            p=OctToBin(sr);
            stringstream g(p);
            //int x=0;
            g>>x;
            de=binaryToDecimal(x);
            decToHexa(de);
            break;




    }
    return 0;
    }
