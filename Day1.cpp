#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>

using namespace std;

#define SIZE 1000

int main(){

    string input[SIZE]; //array to store the strings from the file
    string line; //a string that will be a copy of each line of the file
    int i = 0; 
    int firstNum; //stores the first digit of each line
    int lastNum; //stores the last digit of each line
    int total = 0; //total sum of all 2 digit numbers

    ifstream file("inputDay1.txt");

    if (file.is_open()){
	while (getline(file,line)) {
	    input[i] = line;
	    i++;
	}
	file.close();
    }
    
    for(int j = 0; j < i; j++){

	size_t first = input[j].find_first_of("1234567890");
	size_t last = input[j].find_last_of("1234567890");
	firstNum = (input[j][first] - '0');
	lastNum = (input[j][last] - '0');

	total = total + firstNum*10;
	total = total + lastNum; 
    }

    cout << total;
    cout << "\n";

    return 0;
}
