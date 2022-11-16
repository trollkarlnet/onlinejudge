/* @JUDGE_ID: 10880 - 100 - The 3n + 1 problem */
/*
Consider the following algorithm:
1. input n
2. print n
3. if n = 1 then STOP
4. if n is odd then n ←− 3n + 1
5. else n ←− n/2
6. GOTO 2
Given the input 22, the following sequence of numbers will be printed
22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
Input
The input will consist of a series of pairs of integers i and j, one pair of integers per line. All integers
will be less than 10,000 and greater than 0.
You should process all pairs of integers and for each pair determine the maximum cycle length over
all integers between and including i and j.
You can assume that no operation overflows a 32-bit integer.
Output
For each pair of input integers i and j you should output i, j, and the maximum cycle length for integers
between and including i and j. These three numbers should be separated by at least one space with all
three numbers on one line and with one line of output for each line of input. The integers i and j must
appear in the output in the same order in which they appeared in the input and should be followed by
the maximum cycle length (on the same line).
*/


#include <iostream>
using namespace std;

#include <string>
#include <sstream>
#include <istream>
#include <ostream>
#include <stdio.h>

int sequence (int m ) {
        int i=1;
        while (m !=1 ) {
                 m = ( m%2)?3*m+1:m/2;
                i++;
        }
        return i;
}

int main () {

#ifndef ONLINE_JUDGE
        (void)!freopen("./myprog.in","r",stdin);
        (void)!freopen("./myprog.out", "w", stdout);
#endif
        int i,j;
        int iOrig,jOrig;
        int max=0,swap=0,loop=0;
        string line;
        stringstream ss;
        while ( getline(cin,line)) {
                ss.str("");
                ss.clear();
                ss << line;
                ss >> i >> j;
                iOrig=i;
                jOrig=j;
                if (j < i ) { swap = i ; i = j ; j = swap ; }
                swap=0; max=0;
                for (loop=i; loop<=j ; loop++) {
                        swap=sequence(loop);
                        if (swap > max) { max = swap;} ;
                }
                cout << iOrig << " " << jOrig <<" " << max << endl;

        }


        return 0;
}       
        
