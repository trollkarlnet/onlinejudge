/* @JUDGE_ID: 10880 - 105 - The Skyline Problem */
/*
drawing images is the elimination of hidden lines — lines obscured by other parts of a drawing.
You are to design a program to assist an architect in drawing the skyline of a city given the locations
of the buildings in the city. To make the problem tractable, all buildings are rectangular in shape and
they share a common bottom (the city they are built in is very flat). The city is also viewed as twodimensional. A building is specified by an ordered triple (Li
, Hi , Ri) where Li and Ri are the left and right coordinates, respectively, of building i (0 < Li < Ri) and Hi is the height of the building. In the
diagram below buildings are shown on the left with triples
(1, 11, 5),(2, 6, 7),(3, 13, 9),(12, 7, 16),(14, 3, 25),(19, 18, 22),(23, 13, 29),(24, 4, 28)
the skyline, shown on the right, is represented by the sequence:
(1, 11, 3, 13, 9, 0, 12, 7, 16, 3, 19, 18, 22, 3, 23, 13, 29, 0)

Input
The input is a sequence of building triples. All coordinates of buildings are integers less than 10,000
and there will be at least one and at most 5,000 buildings in the input file. Each building triple is
on a line by itself in the input file. All integers in a triple are separated by one or more spaces. The
triples will be sorted by Li
, the left x-coordinate of the building, so the building with the smallest left
x-coordinate is first in the input file.

Output
The output should consist of the vector that describes the skyline as shown in the example above. In the
skyline vector (v1, v2, v3, . . . , vn−2, vn−1, vn), the vi such that i is an even number represent a horizontal
line (height). The vi such that i is an odd number represent a vertical line (x-coordinate). The skyline
vector should represent the “path” taken, for example, by a bug starting at the minimum x-coordinate
and traveling horizontally and vertically over all the lines that define the skyline. Thus the last entry
in all skyline vectors will be a ‘0’.

https://onlinejudge.org/external/1/105.pdf
*/


#include <iostream>
using namespace std;

#include <string>
#include <sstream>
#include <istream>
#include <ostream>
#include <stdio.h>

int main () {

#ifndef ONLINE_JUDGE
        (void)!freopen("./myprog.in","r",stdin);
        (void)!freopen("./myprog.out", "w", stdout);
#endif
        int skyline[10000] ={0};
        int start,height,end;
        int swap=0,loop=0,endmax=0,startmin=10000;
        string line;
        stringstream ss;

        while ( getline(cin,line)) {
                ss.str("");
                ss.clear();
                ss << line;
                ss >> start >> height >> end;

                if (end > endmax ) { endmax=end;};
                if (start < startmin ) { startmin=start;};

/* build skyline */

                for (loop=start; loop<=end ; loop++) {
                        if (skyline[loop] < height) { skyline[loop] = height;}

                }
        }

/* print completed skyline */

        cout << startmin << " " << skyline[startmin] << " ";
        height=skyline[startmin];
        for (loop=startmin; loop<=endmax ; loop++) {
                 if (skyline[loop]!= height ) {
                        if (skyline[loop] < height) {
                                /* when we "drop in height need the previous end point */
                                cout << loop -1 << " " << skyline[loop] << " ";
                        } else {
                                /* when we "rise in height need the current end point */
                                cout << loop << " " << skyline[loop] << " ";
                        }
                        height = skyline[loop];
                }
        }
        cout << endmax << " 0" << endl;

        return 0;
}         
