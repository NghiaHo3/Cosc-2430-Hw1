//Nghia Ho
//ID:1251576
#include <iostream>
#include <fstream>
#include<sstream>
#include <string>
#include <iomanip>
#include "ArgumentManager.h"


using namespace std;

int main(int argc, char* argv[]){
    if(argc<2){
        cout<<"Usage: sum_rowcol \"A=<file>;C=<file>\""<<endl;
    }
    ArgumentManager am(argc, argv);

    //getting the input and output filename
    string inFilename=am.get("A");
	string outFilename=am.get("C");

    //Initializing ifstream and ofstream with their respective filename
	ifstream inFile(inFilename.c_str());
	ofstream outFile(outFilename.c_str());

    //Initializing string variable for getline and string stream later on
    string line,word;

    //Initializing the matrixA array along with row and column sum array
    double matrixA[20][20],rowS[20],columnS[20];


    //Initializing int x for x coordinate and y for y coordinate in the array
    //z is for the dimension or size of the array
    //double num is for getting the number input from the file
	int x,y,z;
	double num;


	//checking if infile is empty
	inFile.seekg(0,inFile.end);
	if(inFile.tellg()==0){
        cout<<"Error! empty file"<<endl;
        outFile<<' ';
        return 0;
	}
	else{
        inFile.seekg(0,inFile.beg);
	}


    //finding the required matrix dimension within the first line by
    //using getline and inserting the line into a string stream
    getline(inFile,line);
    stringstream ss(line);
    while(ss>>word){
            for(int i=0;i<word.length();i++){
                if(isdigit(word.at(i))){
                    z=stoi(word);
                    break;
                }
            }
    }


    //Checking if the dimensions given is valid
    if(z<=0||z>20){
        cout<<"Error! invalid matrix dimension"<<endl;
        outFile<<' ';
        return 0;
    }


    //Putting number from the file into an array
    for(x=0;x<z;x++){
            for(y=0;y<z;y++){
        inFile>>num;
        matrixA[x][y]=num;
        }
    }

    //Calculating rows sum using for loops
    for(x=0;x<z;x++){
        for(y=0;y<z;y++){
            rowS[x]=matrixA[x][y]+rowS[x];
        }
    }

    //Calculating columns sum using for loops
    for(y=0;y<z;y++){
            for(x=0;x<z;x++){
                columnS[y]=matrixA[x][y]+columnS[y];
            }
    }

    //setting precision to ensure that we are outputting 2 decimal points in the .out file
    outFile<<fixed<<setprecision(2);

    //outputting rows and columns sum to .out file
    for(x=0;x<z;x++){
        outFile<<rowS[x]<<' ';
    }
    outFile<<endl;
    for(y=0;y<z;y++){
        outFile<<columnS[y]<<' ';
    }

    return 0;
}


