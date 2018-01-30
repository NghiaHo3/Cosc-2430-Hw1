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
    //string inFilename="1.txt";
    string inFilename=am.get("A");
    //string outFilename="out.txt";
	string outFilename=am.get("C");


	ifstream inFile(inFilename.c_str());
	ofstream outFile(outFilename.c_str());
	//checking if file is empty
	inFile.seekg(0,inFile.end);
	if(inFile.tellg()==0){
        cout<<"Error! empty file"<<endl;
        outFile<<endl;
        return 0;
	}
	else{
        inFile.seekg(0,inFile.beg);
	}


    string line;
	double num;
	int x,y,z;

    //finding the required matrix dimension within the first line
    getline(inFile,line);
    stringstream ss(line);
    string word;
    while(ss>>word){
            for(int i=0;i<word.length();i++){
                if(isdigit(word.at(i))){
                    z=stoi(word);
                    break;
                }
            }
    }


    //Checking if the dimension is valid
    if(z<=0||z>20){
        cout<<"Error! invalid matrix dimension"<<endl;
        outFile<<endl;
        return 0;
    }


    //Initializing the matrixA array along with row and column sum array
    double matrixA[20][20],rowS[20],columnS[20];

    //inFile.precision(2);
    //inFile.setf(ios::fixed);
    //Putting read file number into an array
    for(x=0;x<z;x++){
            for(y=0;y<z;y++){
        inFile>>num;
        matrixA[x][y]=num;
        cout<<matrixA[x][y]<<' ';
        }
        cout<<endl;
    }

    //Calculating row sum
    for(x=0;x<z;x++){
        for(y=0;y<z;y++){
            rowS[x]=matrixA[x][y]+rowS[x];
        }
    //Outputting the sum with 2 decimal points
        cout<<fixed<<setprecision(2)<<rowS[x]<<' ';
    }
    cout<<endl;

    //Calculating column sum
    for(y=0;y<z;y++){
            for(x=0;x<z;x++){
                columnS[y]=matrixA[x][y]+columnS[y];
            }
    //Outputting the sum with 2 decimal points
            cout<<fixed<<setprecision(2)<<columnS[y]<<' ';
    }
    cout<<endl;



    //setting precision to ensure 2 decimal points in the .out file
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


