#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>

using namespace std;

#define SIZE 1000

int main(){

    string input[SIZE]; //array to store the strings from the file
    string line; //a string that will be a copy of each line of the file
    int i = 0; //stores the number of lines in the array of the input
    int total = 0; //total sum of all 2 digit numbers
    string writtenNumbers[9];
    int firstNum;
    int lastNum;

    writtenNumbers[0] = "zero"; writtenNumbers[1] = "one"; 
    writtenNumbers[2] = "two"; writtenNumbers[3] = "three";
    writtenNumbers[4] = "four"; writtenNumbers[5] = "five"; 
    writtenNumbers[6] = "six"; writtenNumbers[7] ="seven";
    writtenNumbers[8] = "eight"; writtenNumbers[9] = "nine"; 


    ifstream file("test.txt");

    if (file.is_open()){
	while (getline(file,line)) {
	    input[i] = line;
	    i++;
	}
	file.close();
    }

   //check the first number of the string

    for(int p = 0; p < i; p++){

	int first = 0;

	first = input[p].find_first_of("0123456789");

	for(int n = 0; n < 10; n++){ 

	    if(input[p].find(writtenNumbers[n]) < first){

		first = input[p].find(writtenNumbers[n]);
		total += n*10;
		break;
	    }
	}

	if (input[p].find_first_of("0123456789") <= first){
	    first = input[p].find_first_of("0123456789");
	    firstNum = input[p][first] - '0';
	    total += firstNum*10;
	}
    }
    
    // check the last number of the string

    for(int u = 0; u < i; u++){
	
	int lastDigit = 0;

	size_t found = input[u].find_last_of("0123456789");
	lastNum = input[u][found] - '0';

	cout << found;
	cout << " <- pos do ultimo numero que encontrou\n";
	cout << lastNum;
	cout << " <- the corresponding number\n";
	
	for(int n = 0; n < 10; n++){

	    found = input[u].find(writtenNumbers[n],found + 1); 

	    if(found != string::npos){
		cout << found;
		cout << " <- pos na string depois de encontrar o primeiro numero\n";
		cout << n;
		cout << " <- corresponding number\n";
	    }
	    /*if (found == 0){
		total += n;
		break;
	    }*/
	}

	/*if (input[u].find_last_of("0123456789") >= found){
	    total += lastNum;
	}*/
    }


    cout << total;
    cout << "\n";

    return 0;
}
