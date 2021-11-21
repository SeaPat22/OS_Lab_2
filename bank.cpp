/* Program built by: 
   SEAN KING */

/* Operating System Lab 2 -- Banker's Algorithm

This program utilizes Banker's Algorithm to avoid deadlock. Through the five 
Processes used in this program: P0, P1, P2, P3, P4, are allocated Resources and
through use of Banker's Algorithm, can find the Safe Sequence so that the
Processes in the system can avoid deadlock. */


#include <iostream>
#include <fstream>

int main() { 
    
    // Declares the number of Processes 'r' and the number of Resources 'c'
    // for each Process of the system.
    int r = 5;
    int c = 3; 
    ///////////

    // Opens the 'Allocation.txt' file and declares the input file object,
    // 'InputFile.'
    std::ifstream InputFile;
    InputFile.open("Allocation.txt");
    //////////////////////////////////

    // If the 'Allocation.txt' file could not open, stop the program.
    if(!InputFile) {
	std::cout << "Could not open input file." << '\n';
	system("pause");
	exit(-1);
    }
    ///////////////////////////////////////////////////////

    // Gathers the current amount of allocated Resources to each Process
    // in the system.
    int Allocation[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
	    InputFile >> Allocation[i][j];
	}
    }

    // Prints out the Allocation Array.
    std::cout << "The five Processes' allocated Resources are:\n";
    for (int i = 0; i < r; i++) {
        std::cout << 'P' << i << " -> ";
	for (int j = 0; j < c; j++) {
	    std::cout << Allocation[i][j] << ' ';
	}
	std::cout << '\n';
    }
    ///////////////////////////////////////////////////////////////

    // Closes the 'Allocation.txt' and opens the 'MAX.txt' file.
    InputFile.close();
    InputFile.open("MAX.txt");
    ///////////////////////////

    // If the 'MAX.txt' file could not open, stop the program.
    if(!InputFile) {
        std::cout << "Could not open input file." << '\n';
	system("pause");
	exit(-1);
    }
    ///////////////////////////////////////////////////////

    // Gathers the maximum number of instances of each Resource that each
    // Process can request in the system.
    int MAX[r][c];
    for (int i = 0; i < r; i++) {
	for (int j = 0; j < c; j++) {
	    InputFile >> MAX[i][j];
	}
    }

    // Prints out the MAX Array.
    std::cout << "\nThe five Processes' maximum amount of Resources are:\n";
    for (int i = 0; i < r; i++) {
        std::cout << 'P' << i << " -> ";
	for (int j = 0; j < c; j++) {
	    std::cout << MAX[i][j] << ' ';
	}
	std::cout << '\n';
    }
    /////////////////////////////////////////////////////////////////////////

    // Closes the 'MAX.txt' and opens the 'Open.txt' file.
    InputFile.close();
    InputFile.open("Open.txt");
    ////////////////////////////

    // If the 'Open.txt' file could not open, stop the program.
    if(!InputFile) {
	std::cout << "Could not open input file." << '\n';
	system("pause");
	exit(-1);
    }
    ///////////////////////////////////////////////////////

    // Gathers the amount of available Resources for the Processes of the 
    // system.
    int Open[c];
    for (int i = 0; i < c; i++) {
	InputFile >> Open[i];
    }
    
    // Prints out the Open Array.
    std::cout << "\nThe available Resources for the Processes are:\n";
    for (int i = 0; i < c; i++) {
	std::cout << Open[i] << ' ';
    }
    std::cout << '\n';
    /////////////////////////////////////////////////////////////////// 

    // Closes the 'Open.txt' file.
    InputFile.close();
    ///////////////////
    
    // Calculates the Need Matrix, which tells how much of each Resource
    // that each Process in the system needs.
    int Need[r][c]; 
    for (int i = 0; i < r; i++) { 
        for (int j = 0; j < c; j++) {
	    Need[i][j] = MAX[i][j] - Allocation[i][j];
        } 
    } 
    ///////////////////////////////////////////////////

    // Sets all of the elements of the 'f' Array to false, meaning that the
    // number of available resources is now represented by the Open Array. 
    int f[r];
    for (int k = 0; k < r; k++) { 
        f[k] = 0; 
    }
    //////////////////////////////

    // Calculating the Safe Sequence of the system.
    int ans[r], ind = 0;
    for (int k = 0; k < 5; k++) { 
        for (int i = 0; i < r; i++) {

	    // If f[i] == 0, allocate resources to that index.
	    if (f[i] == 0) { 
	        int flag = 0; 
		for (int j = 0; j < c; j++) { 
		    if (Need[i][j] > Available[j]){ 
		    flag = 1; 
		    break; 
		    } 
		} 

                // Putting the requested Resources in the index of the 'ans' 
		// Array.
		if (flag == 0) { 
		    ans[ind++] = i; 
		    for (int y = 0; y < r; y++) { 
		        Available[y] += Allocation[i][y]; 
                    }
		    f[i] = 1; 
		} 
	    } 
	} 
    }
    //////////////////////////////////////////////////////

    // Printing out the SAFE Sequence of the system throught the 'ans' Array.
    std::cout << "\nThe SAFE Sequence of the system is: "; 
        for (int i = 0; i < r - 1; i++) { 
	    std::cout << " P" << ans[i] << " ->";
        } 
	std::cout << " P" << ans[r - 1] << '\n';
    ///////////////////////////////////////////////////////

    return 0; 
} 
