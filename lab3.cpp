#include <iostream>  
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <set>
#include <algorithm>
using namespace std;

//Global Variables:
int Number_Restarted = 0;
vector<int> original_board; //The original board configuration given in the input file. 
vector<int> unchangables; //Positions in the original board which cannot be changed (part of the given sudoku board to solve)
//End of Global Variables

//Successor: returns a vector of possible successor states to the input.
vector<vector<int> > Successor(vector<int> sudoku_state) {
    //Core successor function logic: I choose one of the non-unchangable states at random, and change it to any of its other 3 possible values.  Eg. If a cell with a '1' is chosen at random, then I return the sudoku board with a '2' a '3' and a '4' at that location, in a vector of vectors. 
    vector<vector<int> > list_of_all_successors;
    int random_indice;
    random_indice = rand()%16;
    //make sure it is not one of the unchangable squares
    while((std::find(unchangables.begin(), unchangables.end(), random_indice) != unchangables.end())) 
    {
	random_indice = rand()%16;
    }
    if(sudoku_state[random_indice]==1) {
	sudoku_state[random_indice]=2;
	list_of_all_successors.push_back(sudoku_state);
	sudoku_state[random_indice]=3;
	list_of_all_successors.push_back(sudoku_state);
	sudoku_state[random_indice]=4;
	list_of_all_successors.push_back(sudoku_state);
    }
    else if(sudoku_state[random_indice]==2) {
	sudoku_state[random_indice]=1;
	list_of_all_successors.push_back(sudoku_state);
	sudoku_state[random_indice]=3;
	list_of_all_successors.push_back(sudoku_state);
	sudoku_state[random_indice]=4;
	list_of_all_successors.push_back(sudoku_state);
    }
    else if(sudoku_state[random_indice]==3) {
	sudoku_state[random_indice]=1;
	list_of_all_successors.push_back(sudoku_state);
	sudoku_state[random_indice]=2;
	list_of_all_successors.push_back(sudoku_state);
	sudoku_state[random_indice]=4;
	list_of_all_successors.push_back(sudoku_state);
    }
    else { //then we know == 4
	sudoku_state[random_indice]=2;
	list_of_all_successors.push_back(sudoku_state);
	sudoku_state[random_indice]=3;
	list_of_all_successors.push_back(sudoku_state);
	sudoku_state[random_indice]=1;
	list_of_all_successors.push_back(sudoku_state);
    }
    return list_of_all_successors;
}

//returns the total amount of flaws found in the given sudoku board configuration passed to it.  The logic of finding the flaws in a size 16 vector of int (representing the sudoku board) is here.  
int Evaluator(vector<int> sudoku_configuration) {
    int flaws = 0;
    //Core evaluator logic: It's very simple, since I used a 1d array, is mostly hardcoded.  I simply check every cell, and count how many flaws there are with each cell, totalling all.
    int j =0;
    while(j<sudoku_configuration.size()) {
	if(j==0) {
	    if(sudoku_configuration[0]==1) {
		if(sudoku_configuration[1]==1 || sudoku_configuration[2]==1 || sudoku_configuration[3]==1 || sudoku_configuration[4]==1 || sudoku_configuration[5]==1 || sudoku_configuration[8]==1 || sudoku_configuration[12]==1) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[0]==2) {
		if(sudoku_configuration[1]==2 || sudoku_configuration[2]==2 || sudoku_configuration[3]==2 || sudoku_configuration[4]==2 || sudoku_configuration[5]==2 || sudoku_configuration[8]==2 || sudoku_configuration[12]==2) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[0]==3) {
		if(sudoku_configuration[1]==3 || sudoku_configuration[2]==3 || sudoku_configuration[3]==3 || sudoku_configuration[4]==3 || sudoku_configuration[5]==3 || sudoku_configuration[8]==3 || sudoku_configuration[12]==3) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[0]==4) {
		if(sudoku_configuration[1]==4 || sudoku_configuration[2]==4 || sudoku_configuration[3]==4 || sudoku_configuration[4]==4 || sudoku_configuration[5]==4 || sudoku_configuration[8]==4 || sudoku_configuration[12]==4) {
		    flaws++;
		    
		}
	    }
	}
	if(j==1) {
	    if(sudoku_configuration[1]==1) {
		if(sudoku_configuration[0]==1 || sudoku_configuration[2]==1 || sudoku_configuration[3]==1 || sudoku_configuration[4]==1 || sudoku_configuration[5]==1 || sudoku_configuration[9]==1 || sudoku_configuration[13]==1) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[1]==2) {
		if(sudoku_configuration[0]==2 || sudoku_configuration[2]==2 || sudoku_configuration[3]==2 || sudoku_configuration[4]==2 || sudoku_configuration[5]==2 || sudoku_configuration[9]==2 || sudoku_configuration[13]==2) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[1]==3) {
		if(sudoku_configuration[0]==3 || sudoku_configuration[2]==3 || sudoku_configuration[3]==3 || sudoku_configuration[4]==3 || sudoku_configuration[5]==3 || sudoku_configuration[9]==3 || sudoku_configuration[13]==3) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[1]==4) {
		if(sudoku_configuration[0]==4 || sudoku_configuration[2]==4 || sudoku_configuration[3]==4 || sudoku_configuration[4]==4 || sudoku_configuration[5]==4 || sudoku_configuration[9]==4 || sudoku_configuration[13]==4) {
		    flaws++;
		    
		}
	    }
	}
	if(j==2) {
	    if(sudoku_configuration[2]==1) {
		if(sudoku_configuration[0]==1 || sudoku_configuration[1]==1 || sudoku_configuration[3]==1 || sudoku_configuration[6]==1 || sudoku_configuration[7]==1 || sudoku_configuration[10]==1 || sudoku_configuration[14]==1) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[2]==2) {
		if(sudoku_configuration[0]==2 || sudoku_configuration[1]==2 || sudoku_configuration[3]==2 || sudoku_configuration[6]==2 || sudoku_configuration[7]==2 || sudoku_configuration[10]==2 || sudoku_configuration[14]==2) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[2]==3) {
		if(sudoku_configuration[0]==3 || sudoku_configuration[1]==3 || sudoku_configuration[3]==3 || sudoku_configuration[6]==3 || sudoku_configuration[7]==3 || sudoku_configuration[10]==3 || sudoku_configuration[14]==3) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[2]==4) {
		if(sudoku_configuration[0]==4 || sudoku_configuration[1]==4 || sudoku_configuration[3]==4 || sudoku_configuration[6]==4 || sudoku_configuration[7]==4 || sudoku_configuration[10]==4 || sudoku_configuration[14]==4) {
		    flaws++;
		    
		}
	    }
	}
	if(j==3) {
	    if(sudoku_configuration[3]==1) {
		if(sudoku_configuration[0]==1 || sudoku_configuration[1]==1 || sudoku_configuration[2]==1 || sudoku_configuration[6]==1 || sudoku_configuration[7]==1 || sudoku_configuration[11]==1 || sudoku_configuration[15]==1) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[3]==2) {
		if(sudoku_configuration[0]==2 || sudoku_configuration[1]==2 || sudoku_configuration[2]==2 || sudoku_configuration[6]==2 || sudoku_configuration[7]==2 || sudoku_configuration[11]==2 || sudoku_configuration[15]==2) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[3]==3) {
		if(sudoku_configuration[0]==3 || sudoku_configuration[1]==3 || sudoku_configuration[2]==3 || sudoku_configuration[6]==3 || sudoku_configuration[7]==3 || sudoku_configuration[11]==3 || sudoku_configuration[15]==3) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[3]==4) {
		if(sudoku_configuration[0]==4 || sudoku_configuration[1]==4 || sudoku_configuration[2]==4 || sudoku_configuration[6]==4 || sudoku_configuration[7]==4 || sudoku_configuration[11]==4 || sudoku_configuration[15]==4) {
		    flaws++;
		    
		}
	    }
	}
	if(j==4) {
	    if(sudoku_configuration[4]==1) {
		if(sudoku_configuration[0]==1 || sudoku_configuration[1]==1 || sudoku_configuration[5]==1 || sudoku_configuration[6]==1 || sudoku_configuration[7]==1 || sudoku_configuration[8]==1 || sudoku_configuration[12]==1) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[4]==2) {
		if(sudoku_configuration[0]==2 || sudoku_configuration[1]==2 || sudoku_configuration[5]==2 || sudoku_configuration[6]==2 || sudoku_configuration[7]==2 || sudoku_configuration[8]==2 || sudoku_configuration[12]==2) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[4]==3) {
		if(sudoku_configuration[0]==3 || sudoku_configuration[1]==3 || sudoku_configuration[5]==3 || sudoku_configuration[6]==3 || sudoku_configuration[7]==3 || sudoku_configuration[8]==3 || sudoku_configuration[12]==3) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[4]==4) {
		if(sudoku_configuration[0]==4 || sudoku_configuration[1]==4 || sudoku_configuration[5]==4 || sudoku_configuration[6]==4 || sudoku_configuration[7]==4 || sudoku_configuration[8]==4 || sudoku_configuration[12]==4) {
		    flaws++;
		    
		}
	    }
	}
	if(j==5) {
	    if(sudoku_configuration[5]==1) {
		if(sudoku_configuration[0]==1 || sudoku_configuration[1]==1 || sudoku_configuration[4]==1 || sudoku_configuration[6]==1 || sudoku_configuration[7]==1 || sudoku_configuration[9]==1 || sudoku_configuration[13]==1) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[5]==2) {
		if(sudoku_configuration[0]==2 || sudoku_configuration[1]==2 || sudoku_configuration[4]==2 || sudoku_configuration[6]==2 || sudoku_configuration[7]==2 || sudoku_configuration[9]==2 || sudoku_configuration[13]==2) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[5]==3) {
		if(sudoku_configuration[0]==3 || sudoku_configuration[1]==3 || sudoku_configuration[4]==3 || sudoku_configuration[6]==3 || sudoku_configuration[7]==3 || sudoku_configuration[9]==3 || sudoku_configuration[13]==3) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[5]==4) {
		if(sudoku_configuration[0]==4 || sudoku_configuration[1]==4 || sudoku_configuration[4]==4 || sudoku_configuration[6]==4 || sudoku_configuration[7]==4 || sudoku_configuration[9]==4 || sudoku_configuration[13]==4) {
		    flaws++;
		    
		}
	    }
	}
	if(j==6) {
	    if(sudoku_configuration[6]==1) {
		if(sudoku_configuration[2]==1 || sudoku_configuration[3]==1 || sudoku_configuration[7]==1 || sudoku_configuration[4]==1 || sudoku_configuration[5]==1 || sudoku_configuration[10]==1 || sudoku_configuration[14]==1) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[6]==2) {
		if(sudoku_configuration[2]==2 || sudoku_configuration[3]==2 || sudoku_configuration[7]==2 || sudoku_configuration[4]==2 || sudoku_configuration[5]==2 || sudoku_configuration[10]==2 || sudoku_configuration[14]==2) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[6]==3) {
		if(sudoku_configuration[2]==3 || sudoku_configuration[3]==3 || sudoku_configuration[7]==3 || sudoku_configuration[4]==3 || sudoku_configuration[5]==3 || sudoku_configuration[10]==3 || sudoku_configuration[14]==3) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[6]==4) {
		if(sudoku_configuration[2]==4 || sudoku_configuration[3]==4 || sudoku_configuration[7]==4 || sudoku_configuration[4]==4 || sudoku_configuration[5]==4 || sudoku_configuration[10]==4 || sudoku_configuration[14]==4) {
		    flaws++;
		    
		}
	    }
	}
	if(j==7) {
	    if(sudoku_configuration[7]==1) {
		if(sudoku_configuration[2]==1 || sudoku_configuration[3]==1 || sudoku_configuration[6]==1 || sudoku_configuration[4]==1 || sudoku_configuration[5]==1 || sudoku_configuration[11]==1 || sudoku_configuration[15]==1) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[7]==2) {
		if(sudoku_configuration[2]==2 || sudoku_configuration[3]==2 || sudoku_configuration[6]==2 || sudoku_configuration[4]==2 || sudoku_configuration[5]==2 || sudoku_configuration[11]==2 || sudoku_configuration[15]==2) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[7]==3) {
		if(sudoku_configuration[2]==3 || sudoku_configuration[3]==3 || sudoku_configuration[6]==3 || sudoku_configuration[4]==3 || sudoku_configuration[5]==3 || sudoku_configuration[11]==3 || sudoku_configuration[15]==3) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[7]==4) {
		if(sudoku_configuration[2]==4 || sudoku_configuration[3]==4 || sudoku_configuration[6]==4 || sudoku_configuration[4]==4 || sudoku_configuration[5]==4 || sudoku_configuration[11]==4 || sudoku_configuration[15]==4) {
		    flaws++;
		    
		}
	    }
	}
	if(j==8) {
	    if(sudoku_configuration[8]==1) {
		if(sudoku_configuration[0]==1 || sudoku_configuration[4]==1 || sudoku_configuration[9]==1 || sudoku_configuration[10]==1 || sudoku_configuration[11]==1 || sudoku_configuration[12]==1 || sudoku_configuration[13]==1) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[8]==2) {
		if(sudoku_configuration[0]==2 || sudoku_configuration[4]==2 || sudoku_configuration[9]==2 || sudoku_configuration[10]==2 || sudoku_configuration[11]==2 || sudoku_configuration[12]==2 || sudoku_configuration[13]==2) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[8]==3) {
		if(sudoku_configuration[0]==3 || sudoku_configuration[4]==3 || sudoku_configuration[9]==3 || sudoku_configuration[10]==3 || sudoku_configuration[11]==3 || sudoku_configuration[12]==3 || sudoku_configuration[13]==3) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[8]==4) {
		if(sudoku_configuration[0]==4 || sudoku_configuration[4]==4 || sudoku_configuration[9]==4 || sudoku_configuration[10]==4 || sudoku_configuration[11]==4 || sudoku_configuration[12]==4 || sudoku_configuration[13]==4) {
		    flaws++;
		    
		}
	    }
	}
	if(j==9) {
	    if(sudoku_configuration[9]==1) {
		if(sudoku_configuration[1]==1 || sudoku_configuration[5]==1 || sudoku_configuration[8]==1 || sudoku_configuration[10]==1 || sudoku_configuration[11]==1 || sudoku_configuration[12]==1 || sudoku_configuration[13]==1) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[9]==2) {
		if(sudoku_configuration[1]==2 || sudoku_configuration[5]==2 || sudoku_configuration[8]==2 || sudoku_configuration[10]==2 || sudoku_configuration[11]==2 || sudoku_configuration[12]==2 || sudoku_configuration[13]==2) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[9]==3) {
		if(sudoku_configuration[1]==3 || sudoku_configuration[5]==3 || sudoku_configuration[8]==3 || sudoku_configuration[10]==3 || sudoku_configuration[11]==3 || sudoku_configuration[12]==3 || sudoku_configuration[13]==3) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[9]==4) {
		if(sudoku_configuration[1]==4 || sudoku_configuration[5]==4 || sudoku_configuration[8]==4 || sudoku_configuration[10]==4 || sudoku_configuration[11]==4 || sudoku_configuration[12]==4 || sudoku_configuration[13]==4) {
		    flaws++;
		    
		}
	    }
	}
	if(j==10) {
	    if(sudoku_configuration[10]==1) {
		if(sudoku_configuration[2]==1 || sudoku_configuration[6]==1 || sudoku_configuration[8]==1 || sudoku_configuration[9]==1 || sudoku_configuration[11]==1 || sudoku_configuration[14]==1 || sudoku_configuration[15]==1) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[10]==2) {
		if(sudoku_configuration[2]==2 || sudoku_configuration[6]==2 || sudoku_configuration[8]==2 || sudoku_configuration[9]==2 || sudoku_configuration[11]==2 || sudoku_configuration[14]==2 || sudoku_configuration[15]==2) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[10]==3) {
		if(sudoku_configuration[2]==3 || sudoku_configuration[6]==3 || sudoku_configuration[8]==3 || sudoku_configuration[9]==3 || sudoku_configuration[11]==3 || sudoku_configuration[14]==3 || sudoku_configuration[15]==3) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[10]==4) {
		if(sudoku_configuration[2]==4 || sudoku_configuration[6]==4 || sudoku_configuration[8]==4 || sudoku_configuration[9]==4 || sudoku_configuration[11]==4 || sudoku_configuration[14]==4 || sudoku_configuration[15]==4) {
		    flaws++;
		    
		}
	    }
	}
	if(j==11) {
	    if(sudoku_configuration[11]==1) {
		if(sudoku_configuration[3]==1 || sudoku_configuration[7]==1 || sudoku_configuration[8]==1 || sudoku_configuration[9]==1 || sudoku_configuration[10]==1 || sudoku_configuration[14]==1 || sudoku_configuration[15]==1) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[11]==2) {
		if(sudoku_configuration[3]==2 || sudoku_configuration[7]==2 || sudoku_configuration[8]==2 || sudoku_configuration[9]==2 || sudoku_configuration[10]==2 || sudoku_configuration[14]==2 || sudoku_configuration[15]==2) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[11]==3) {
		if(sudoku_configuration[3]==3 || sudoku_configuration[7]==3 || sudoku_configuration[8]==3 || sudoku_configuration[9]==3 || sudoku_configuration[10]==3 || sudoku_configuration[14]==3 || sudoku_configuration[15]==3) {
		    flaws++;
		    
		}
	    }
	    if(sudoku_configuration[11]==4) {
		if(sudoku_configuration[3]==4 || sudoku_configuration[7]==4 || sudoku_configuration[8]==4 || sudoku_configuration[9]==4 || sudoku_configuration[10]==4 || sudoku_configuration[14]==4 || sudoku_configuration[15]==4) {
		    flaws++;
		}
	    }
	}
	if(j==12) {
	    if(sudoku_configuration[12]==1) {
		if(sudoku_configuration[0]==1 || sudoku_configuration[4]==1 || sudoku_configuration[8]==1 || sudoku_configuration[9]==1 || sudoku_configuration[13]==1 || sudoku_configuration[14]==1 || sudoku_configuration[15]==1) {
		    flaws++;
		}
	    }
	    if(sudoku_configuration[12]==2) {
		if(sudoku_configuration[0]==2 || sudoku_configuration[4]==2 || sudoku_configuration[8]==2 || sudoku_configuration[9]==2 || sudoku_configuration[13]==2 || sudoku_configuration[14]==2 || sudoku_configuration[15]==2) {
		    flaws++;
		}
	    }
	    if(sudoku_configuration[12]==3) {
		if(sudoku_configuration[0]==3 || sudoku_configuration[4]==3 || sudoku_configuration[8]==3 || sudoku_configuration[9]==3 || sudoku_configuration[13]==3 || sudoku_configuration[14]==3 || sudoku_configuration[15]==3) {
		    flaws++;
		}
	    }
	    if(sudoku_configuration[12]==4) {
		if(sudoku_configuration[0]==4 || sudoku_configuration[4]==4 || sudoku_configuration[8]==4 || sudoku_configuration[9]==4 || sudoku_configuration[13]==4 || sudoku_configuration[14]==4 || sudoku_configuration[15]==4) {
		    flaws++;
		}
	    }
	}
	if(j==13) {
	    if(sudoku_configuration[13]==1) {
		if(sudoku_configuration[1]==1 || sudoku_configuration[5]==1 || sudoku_configuration[9]==1 || sudoku_configuration[8]==1 || sudoku_configuration[12]==1 || sudoku_configuration[14]==1 || sudoku_configuration[15]==1) {
		    flaws++;
		}
	    }
	    if(sudoku_configuration[13]==2) {
		if(sudoku_configuration[1]==2 || sudoku_configuration[5]==2 || sudoku_configuration[9]==2 || sudoku_configuration[8]==2 || sudoku_configuration[12]==2 || sudoku_configuration[14]==2 || sudoku_configuration[15]==2) {
		    flaws++;
		}
	    }
	    if(sudoku_configuration[13]==3) {
		if(sudoku_configuration[1]==3 || sudoku_configuration[5]==3 || sudoku_configuration[9]==3 || sudoku_configuration[8]==3 || sudoku_configuration[12]==3 || sudoku_configuration[14]==3 || sudoku_configuration[15]==3) {
		    flaws++;
		}
	    }
	    if(sudoku_configuration[13]==4) {
		if(sudoku_configuration[1]==4 || sudoku_configuration[5]==4 || sudoku_configuration[9]==4 || sudoku_configuration[8]==4 || sudoku_configuration[12]==4 || sudoku_configuration[14]==4 || sudoku_configuration[15]==4) {
		    flaws++;
		}
	    }
	}
	if(j==14) {
	    if(sudoku_configuration[14]==1) {
		if(sudoku_configuration[2]==1 || sudoku_configuration[6]==1 || sudoku_configuration[10]==1 || sudoku_configuration[12]==1 || sudoku_configuration[13]==1 || sudoku_configuration[15]==1 || sudoku_configuration[11]==1) {
		    flaws++;
		}
	    }
	    if(sudoku_configuration[14]==2) {
		if(sudoku_configuration[2]==2 || sudoku_configuration[6]==2 || sudoku_configuration[10]==2 || sudoku_configuration[12]==2 || sudoku_configuration[13]==2 || sudoku_configuration[15]==2 || sudoku_configuration[11]==2) {
		    flaws++;
		}
	    }
	    if(sudoku_configuration[14]==3) {
		if(sudoku_configuration[2]==3 || sudoku_configuration[6]==3 || sudoku_configuration[10]==3 || sudoku_configuration[12]==3 || sudoku_configuration[13]==3 || sudoku_configuration[15]==3 || sudoku_configuration[11]==3) {
		    flaws++;
		}
	    }
	    if(sudoku_configuration[14]==4) {
		if(sudoku_configuration[2]==4 || sudoku_configuration[6]==4 || sudoku_configuration[10]==4 || sudoku_configuration[12]==4 || sudoku_configuration[13]==4 || sudoku_configuration[15]==4 || sudoku_configuration[11]==4) {
		    flaws++;
		}
	    }
	}
	if(j==15) {
	    if(sudoku_configuration[15]==1) {
		if(sudoku_configuration[3]==1 || sudoku_configuration[7]==1 || sudoku_configuration[11]==1 || sudoku_configuration[12]==1 || sudoku_configuration[13]==1 || sudoku_configuration[14]==1 || sudoku_configuration[10]==1) {
		    flaws++;
		}
	    }
	    if(sudoku_configuration[15]==2) {
		if(sudoku_configuration[3]==2 || sudoku_configuration[7]==2 || sudoku_configuration[11]==2 || sudoku_configuration[12]==2 || sudoku_configuration[13]==2 || sudoku_configuration[14]==2 || sudoku_configuration[10]==2) {
		    flaws++;
		}
	    }
	    if(sudoku_configuration[15]==3) {
		if(sudoku_configuration[3]==3 || sudoku_configuration[7]==3 || sudoku_configuration[11]==3 || sudoku_configuration[12]==3 || sudoku_configuration[13]==3 || sudoku_configuration[14]==3 || sudoku_configuration[10]==3) {
		    flaws++;
		}
	    }
	    if(sudoku_configuration[15]==4) {
		if(sudoku_configuration[3]==4 || sudoku_configuration[7]==4 || sudoku_configuration[11]==4 || sudoku_configuration[12]==4 || sudoku_configuration[13]==4 || sudoku_configuration[14]==4 || sudoku_configuration[10]==4) {
		    flaws++;
		}
	    }
	}
	j++;
    }
    return flaws;
}

//The core hillclimbing functionality.  Performs the logic of the hillclimbing algorithm on the given initial sudoku board, called initial_state.  initial_state is represented as a vector of int of size 16.  The returned value called goal_state, is also a vector of int of size 16.
vector<int> hillClimber(vector<int> initial_state) {
    vector<int> goal_state; // the final goal state
    vector<int> sudoku_config_with_lowest_flaws = initial_state; //the state being worked with in each iteration
    int minimum = 500; //the current minimum amount of flaws found in a state (set to 500 initially as a max)
    int iterations = 0; //if iterations reaches a high amount, random restart.
    while(true) {
        cout << "\nBeginning of hillClimber loop reached.\n";
	vector<vector<int> > all_successors = Successor(sudoku_config_with_lowest_flaws);
	cout << "Potential Successors to beginning state determined. Now analyzing.  \n";
	//****Core hillClimber logic:
	//Loop over the successors and determine one with lowest amount of flaws.
	int j = 0;
	while(j<all_successors.size()) {
	    vector<int> next_state = all_successors[j];
	    int number_of_flaws = Evaluator(next_state);
	    if(number_of_flaws <= minimum) {
		minimum = number_of_flaws;
		sudoku_config_with_lowest_flaws = next_state;
	    }
	    if(number_of_flaws<=0) {
		//print the final solution
		cout << "**********A SOLUTION HAS BEEN DETERMINED**********\n";
		for(int i=0; i < sudoku_config_with_lowest_flaws.size(); i++){
		    cout << sudoku_config_with_lowest_flaws[i];
		    if(i==3 || i==7 || i==11)
			cout << '\n';
		}
		return sudoku_config_with_lowest_flaws;
	    }
	    j++;
	}
	//print the next lowest state configuration found:
	cout << "Next configuration (passed into next loop of hillClimber) shown below: (Still has " << minimum << " flaws).  \n";
	for(int i=0; i < sudoku_config_with_lowest_flaws.size(); i++){
	    cout << sudoku_config_with_lowest_flaws[i];
	    if(i==3 || i==7 || i==11)
		cout << '\n';
	}
	
	iterations++;
	if(iterations>100) {
	    //randomized restart area: re-randomizes the initial_state, and runs again.
	    cout << "\n ***Reached a local min -- Had to restart hillClimber with a new initial_state! *** \n";
	    int i = 0;
	    for(i = 0; i<initial_state.size(); i++) {
		if(!(std::find(unchangables.begin(), unchangables.end(), i) != unchangables.end())) {
		    initial_state[i] = rand() % 4 + 1;
		}
	    }
	    cout << "New initial state: \n";
	    for(int i=0; i < initial_state.size(); i++){
		cout << initial_state[i];
		if(i==3 || i==7 || i==11)
		    cout << '\n';
	    }
	    cout << "\n Press Enter to continue \n";
	    getchar();
	    return hillClimber(initial_state);
	}
    }
}

vector<int> Mutate(vector<int> child) {
    int random_indice;
    random_indice = rand()%16;
    //make sure it is not one of the unchangable squares
    while((std::find(unchangables.begin(), unchangables.end(), random_indice) != unchangables.end())) 
    {
	random_indice = rand()%16;
    }
    //change to a random integer between 1-4
    child[random_indice] = rand()%4+1;
    return child;
}

bool isValidSquare(const std::vector<int>& square) {
    if (square.size() == 4) {
        std::set<int> uniqs(square.begin(), square.end());
        return uniqs.count(1) && uniqs.count(2) && uniqs.count(3) && uniqs.count(4);
    }
    return false;
}

//Crossover investigates the given children, and mates each one with another. 
vector<vector<int> > Crossover(vector<vector<int> > population) {
	//Okay, for this CrossOver, we look at all three boards given in the population, and evaluate each of them.  The best 2 boards from the population are then mated to produce three new boards.  The mating is done based on what 2x2 squares are correct in each one.  The third child produced is mutated.
    vector<vector<int> > mating_pop;
    vector<vector<int> > updated_population;
    vector<int> most_fit;
    int Next_Lowest = 500;
    int x = 0;
    //Get 2 lowest valued, so fittest children from population.
    while(x < 2) {
	Next_Lowest = 500; //reset to an artificial maximum
	for(int i = 0; i<population.size(); i++) {
	    int ChildValue = Evaluator(population[i]);
	    if(ChildValue <= Next_Lowest) {
		most_fit=population[i];
	    }
	}
	mating_pop.push_back(most_fit);
	population.erase(std::remove(population.begin(), population.end(), most_fit), population.end());
	x++;
    }

    //crossover:
    int place_1 = rand()%15;
    int place_2 = rand()%15;
    mating_pop[0][place_1] = mating_pop[1][place_1];
    mating_pop[1][place_2] = mating_pop[0][place_2];
    
    mating_pop.push_back(Mutate(mating_pop[0])); //third one is mutated-correct
    return mating_pop;;
}

vector<int> hillClimberGenetic(vector<int> initial_state) {
    //core algorithm for the genetic portion of the lab: uses Crossover, Mutate, and Evaluator functions to "evolve" the sudoku configuration into its final form.
    vector<int> lowest_child;
    int iterations = 0;
    int lowest_number_of_flaws = 500; //set to 500 as an artificial maximum
    //randomly generate the initial family of 3 children: (Successor is random itself so it is used)
    vector<vector<int> > population = Successor(initial_state);
    while(true) {
	int j = 0;
	//Cross the children over:
	population = Crossover(population);
	//Mutation:
	for(int z = 0; z<population.size();z++) {
	    int x = rand()%100;
	    //~70% chance to mutate:
	    if(x<=70) {
		vector<int> mutated = Mutate(population[z]);
		population[z] = mutated;
	    }
	}
	int k = 0;
	//select 3 fittest children according to evaluator function
	vector<vector<int> > new_population;
	while(k<2) {
	    int x = 0;
	    lowest_number_of_flaws = 500; //set to artificial maximum
	    while(x<population.size()) {
		int childs_value = Evaluator(population[x]);
		if(childs_value <= lowest_number_of_flaws) {
		    lowest_number_of_flaws = childs_value;
		    lowest_child = population[x];
		}
		if(lowest_number_of_flaws==0) {
		    cout << "\n**********A SOLUTION HAS EVOLVED FROM POPULATION**********\n";
		    for(int i=0; i < lowest_child.size(); i++){
			cout << lowest_child[i];
			if(i==3 || i==7 || i==11)
			    cout << '\n';
		    }
		    return lowest_child;
		}
		x++;
	    }
	    new_population.push_back(lowest_child);
	    population.erase(std::remove(population.begin(), population.end(), lowest_child), population.end());
	    k++;
	}
	    cout << "\nLowest valued child from previous generation: \n";
	    for(int i=0; i < new_population[0].size(); i++){
		cout << new_population[0][i];
		if(i==3 || i==7 || i==11)
		    cout << '\n';
	    }
	iterations++;
	if(iterations>1500) {
	    //randomized restart area: re-randomizes the initial_state, and runs again.
	    cout << "\n ***Reached a stop -- Had to restart Genetic with a new initial_state! *** \n";
	    int i = 0;
	    for(i = 0; i<initial_state.size(); i++) {
		if(!(std::find(unchangables.begin(), unchangables.end(), i) != unchangables.end())) {
		    initial_state[i] = rand() % 4 + 1;
		}
	    }
	    cout << "New initial state: \n";
	    for(int i=0; i < initial_state.size(); i++){
		cout << initial_state[i];
		if(i==3 || i==7 || i==11)
		    cout << '\n';
	    }
	    cout << "\n Press Enter to continue \n";
	    getchar();
	    return hillClimberGenetic(initial_state);
	}
	population = new_population;
    }
}



//Asks for input file, parses the input file into global original_board, starts the HillClimber with that input file, and performs the printing of the final goal state.  Basically, a good chunk of main is done in this area.
void testHarness() {
    //Ask for input file name:
    cout << "Please enter the file name of the sudoku board (ie. sampleinput.txt): \n";
    string inputfile;
    cin >> inputfile;
    char my_character;
    ifstream fin;
    fin.open(inputfile.c_str());
    fin.get(my_character);
    if(my_character!='4')
	cout << "Error in file formatting, expected '4' at beginning. ";
    fin.get(my_character);
    if(my_character!='\n')
	cout << "Error in file formatting, expected newline after '4'. ";
    int i = 0;
    int j = 0;
    //file reading loop
    while(j<19) {
	fin.get(my_character);
	int my_int = my_character - '0';
	if(my_int==1 || my_int==2 || my_int==3 || my_int==4) {
	    original_board.push_back(my_int); //use 1d vector
	    unchangables.push_back(i); //lists positions of unchangables
	    i++;
	}
	else if(my_character=='*') {
	    int my_rand = rand() % 4 + 1; //random between 1-4
	    original_board.push_back(my_rand);
	    i++;
	}
	j++;
    }

   //print out the original sudoku board
   cout << "The original input board has a randomized format of: \n";
   for(int i=0; i < original_board.size(); i++){
       cout << original_board[i];
       if(i==3 || i==7 || i==11)
	   cout << '\n';
   }
   cout << "\nNow inputting such a board into the HillClimbing algorithm. \n";
   vector<int> answer;
   answer = hillClimber(original_board);
}

//Same as testHarness but completes the same stuff for genetic algorithm instead.
void testHarnessGenetic() {
    //Ask for input file name:
    cout << "Please enter the file name of the sudoku board (ie. sampleinput.txt): \n";
    string inputfile;
    cin >> inputfile;
    char my_character;
    ifstream fin;
    fin.open(inputfile.c_str());
    fin.get(my_character);
    if(my_character!='4')
	cout << "Error in file formatting, expected '4' at beginning. ";
    fin.get(my_character);
    if(my_character!='\n')
	cout << "Error in file formatting, expected newline after '4'. ";
    int i = 0;
    int j = 0;
    while(j<19) {
	fin.get(my_character);
	int my_int = my_character - '0';
	if(my_int==1 || my_int==2 || my_int==3 || my_int==4) {
	    original_board.push_back(my_int); //use 1d vector
	    unchangables.push_back(i); //The positions/numbers which were provided in the input file Sudoku problem, and cannot be changed.
	    i++;
	}
	else if(my_character=='*') {
	    int my_rand = rand() % 4 + 1; //random between 1-4
	    original_board.push_back(my_rand);
	    i++;
	}
	j++;
    }
    //print out the original sudoku board
    cout << "The original board has a randomized format of: \n";
   for(int i=0; i < original_board.size(); i++){
       cout << original_board[i];
       if(i==3 || i==7 || i==11)
	   cout << '\n';
   }
   cout << "\nNow inputting such a board into the Genetic algorithm. \n";
   vector<int> answer;
   answer = hillClimberGenetic(original_board);
}


//The main program area asks whether or not you would like to use HillClimber or Genetic algorithm for solving the Sudoku board, and performs corresponding logic for accomplising this.
int main() {
    srand (time(NULL));
    cout << "*****************Welcome to the Sudoku solver program**************** \n";
    cout << "Please select whether you would like to use hillclimber or genetic algorithm. \nEnter h for hillclimber or g for genetic, and press Enter: \n";
    char decide_which;
    cin >> decide_which;
    if(decide_which=='h') {
	testHarness(); //will do all input parsing, printing, etc
	return 0;
    }
    else if(decide_which=='g') {
	testHarnessGenetic(); //same as above but for genetic alg.
	return 0;
    }
    else {
	cout << "Error!  Did not see an h or a g as input as to which algorithm you wanted. Exiting now, try again please. \n";
	return 0;
    }
}



