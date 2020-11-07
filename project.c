/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* << Aimee Lin, alin404, 581200669 >> */

#include "project.h"

/* TASK 1
TimeWorked computes the number of seconds elapsed between a worker clocking in and clocking out.

It takes two pairs of inputs: minuteA and secondA= positive integers representing minutes and seconds elapsed since warehouse opened
					  		  minuteB and secondB = positive integers representing minutes and seconds elapsed since warehouse opened			

Each pair of inputs is combined into one integer variable which represents the total seconds elapsed
since the warehouse opened. The function then checks which elapsed time is greater to identify the
time the worker clocked out. Therefore, the other time must be the time the worker clocked in.

Once these are identified, the function then subtracts the time elapsed at clocking in from the time
elapsed at clocking out to compute the number of seconds that have elapsed between clocking in and
clocking out.
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{
	int timeA, timeB;
	timeA = minuteA * 60 + secondA;
	timeB = minuteB * 60 + secondB;
	if (timeA > timeB) {
		return timeA - timeB;
	} else if (timeB > timeA) {
		return timeB - timeA;
	} else {
		return 0;
	}
}

/* TASK 2
WarehouseAddress returns the largest prime number that is less than the upper bound.

It takes one input: maximum = a positive integer input greater than 2 representing the upper bound

While no prime numbers are found, the function loops through numbers starting at one less than
the maximum and decreasing. For each number, the function uses an inner loop to check for factors
between 2 and itself to check for factors excluding 1 and itself. The inner loops stops when a factor
is found or if all potential factors have been checked.

The function then evaluates whether the number is prime depending on whether it has factors
or not. If there are factors, the number of factors is reset to 0 and the function continues
through the outer loop. If there are no factors, the variable "prime" is set to the prime
number and is returned.
*/
int WarehouseAddress(int maximum)
{
	int i, number;
	int factors = 0;
	int prime = 0;

	number = maximum - 1;

	// Loops through numbers starting at one less than the maximum and decreasing
	while (!prime) {
		// Looks for factors (excluding 1 and itself)
		for (i = 2; (i < number && !factors); i++) {
			if (number % i == 0) {
				factors = 1;
			}
		}
		// Checks if number is a prime
		if (factors) {
			number--;
			factors = 0;
		} else {
			prime = number;
		}
	}

	return prime;
}

/* TASK 3
Advertise rotates the characters in an input string so that every character moves one position
to the left and the leftmost character wraps around and joins the right hand end of the string.

It takes one input: words = a string containing at least one character

First, the function find the length of the string using a while loop to loop through the characters
until the null character is reached. Next, the leftmost character is stored in a temporary variable
as it will be overwritten as characters are shifted to the left. The function shifts characters to the
left using a for loop, and then brings the leftmost character to the right hand end of the string 
by setting the last character to the temporary variable.
*/
void Advertise(char *words)
{
	// Finds length of string
	int length = 0;
	while (words[length] != '\0') {
		length++;
	}

	// Stores leftmost character in a temporary variable	
	char temp = words[0];

	// Moves every character one position to the left
	for (int i = 0; i < length; i++) {
		words[i] = words[i+1];
	}
	// Brings leftmost character to the right hand end
	words[length-1] = temp;
}

/* TASK 4
WinningBid calculates the winning bid in a unique bid auction. The winning bid is the lowest bid
that is submitted by just one person (lowest unique bid).

It takes two inputs: values = an array of positive integers representing all of the bids
					 length = a positive integer representing the number of elements in the values array

First, the function creates an array of unique bids using nested for loops. Next, the function finds
the lowest bid in the array of unique bids and returns this. If there are no unique bids, the function
returns -1.
*/
int WinningBid(int *values, int length)
{
	int i, j, found, min;
	int unique[1000] = {0};
	int count = 0;

	// Creates array of unique values
	for (i = 0; i < length; i++) {
		found = 0;
		for (j = 0; j < length; j++) {
			if (i != j && values[j] == values[i]) {
				found = 1;
				break;
			}
		}
		if (!found) {
			unique[count] = values[i];
			count++;
		}
	}

	// Finds lowest unique value
	if (count == 0) {
		return -1;
	} else {
		min = unique[0];
		for (i = 0; i < count; i++) {
			if (unique[i] < min) {
				min = unique[i];
			}
		}
	}

	return min;
}

/* TASK 5
BoxDesign generates a string representing the boz as viewed from the side.
It takes three inputs: design = a string into which the final design will be stored
					   width = an integer representing the width of the box
					   height = an integer representing the height of the box

First, the function generates a string the box. The variable "length" is used to keep
track of the length of the string, and nested for loops are used to set the appropriate
characters to asterisks, new line characters, and spaces. Next, the function finds the
position(s) of the centre(s) of the box and sets these to X.
*/
void BoxDesign(char *design, int width, int height)
{
	int length = 0;
	int i, j;
	// Generates box
	while (length < (width + 1) * height) {
		for (i = 0; i < height; i++) {
			for (j = 0; j <= width; j++) {
				if (i == 0 && j < width) {
					design[length] = '*';
					length++;
				} else if (j == width) {
					design[length] = '\n';
					length++;
				} else if (i > 0 && i < height - 1 && (j == 0 || j == width - 1)) {
					design[length] = '*';
					length++;
				} else if (i == height - 1 && j < width) {
					design[length] = '*';
					length++;
				} else {
					design[length] = ' ';
					length++;
				}
			}
		}
	}

	// Generates centre mark(s)
	if (height >= 3 && height % 2 == 1) {
		int y1 = height / 2;
		if (width >= 3 && width % 2 == 1) {
			int x1 = width / 2;
			int centre1 = (width + 1) * y1 + x1;
			design[centre1] = 'X';
		} else if (width >= 3 && width % 2 == 0) {
			int x1 = width / 2;
			int x2 = (width / 2) - 1;
			int centre1 = (width + 1) * y1 + x1;
			int centre2 = (width + 1) * y1 + x2;
			design[centre1] = 'X';
			design[centre2] = 'X';
		}
	} else if (height >= 3 && height % 2 == 0) {
		int y1 = height / 2;
		int y2 = (height / 2) - 1;
		if (width >= 3 && width % 2 == 1) {
			int x1 = width / 2;
			int centre1 = (width + 1) * y1 + x1;
			int centre2 = (width + 1) * y2 + x1;
			design[centre1] = 'X';
			design[centre2] = 'X';
		} else if (width >= 3 && width % 2 == 0) {
			int x1 = width / 2;
			int x2 = (width / 2) - 1;
			int centre1 = (width + 1) * y1 + x1;
			int centre2 = (width + 1) * y1 + x2;
			int centre3 = (width + 1) * y2 + x1;
			int centre4 = (width + 1) * y2 + x2;
			design[centre1] = 'X';
			design[centre2] = 'X';
			design[centre3] = 'X';
			design[centre4] = 'X';
		}
	}
}

/* TASK 6
WorkerRoute calculates a direct route form the worker to the box using an algorithm
which moves the worker horizontally until they line up with the box and then vertically
until they reach the box.
It takes one input: warehouse = a 2D array of integers with 10 rows and 10 columns
								representing the layout of the warehouse floor where
								every element is 0 except for 1 (representing
								the worker), and 2 (representing the box)

First, the function uses nested for loops to find the array indices of the worker and box
to determine their positions. Next, the function "moves" the worker horizontally right if the 
column index of the worker is less than the column index of the box and left if the column
index of the worker is greater than the column index of the box. The function then "moves" 
the worker vertically down if the row index of the worker is less than the row index of the box
and up if the row index of the worker is greater than the row index of the box.
*/
void WorkerRoute(int warehouse[10][10])
{
	int workerRow = 0;
	int workerCol = 0;
	int boxRow = 0;
	int boxCol = 0;
	int i, j;
	// Finds positions of worker and box
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == 1) {
				workerRow = i;
				workerCol = j;
			} else if (warehouse[i][j] == 2) {
				boxRow = i;
				boxCol = j;
			}
		}
	}

	int moves = 0;

	// "Moves" the worker horizontally
	if (boxCol > workerCol) {
		for (j = workerCol + 1; j < boxCol; j++) {
			warehouse[workerRow][j] = 3;
		}
		moves++;
	} else if (boxCol < workerCol) {
		for (j = workerCol - 1; j > boxCol; j--) {
			warehouse[workerRow][j] = 3;
		}
		moves++;
	}

	// "Moves" the worker vertically
	if (moves == 0) {
		if (boxRow > workerRow) {
			for (i = workerRow + 1; i < boxRow; i++) {
				warehouse[i][boxCol] = 3;
			}
		} else if (boxRow < workerRow) {
			for (i = workerRow - 1; i > boxRow; i--) {
				warehouse[i][boxCol] = 3;
			}
		}
	} else {
		if (boxRow > workerRow) {
			for (i = workerRow; i < boxRow; i++) {
				warehouse[i][boxCol] = 3;
			}
		} else if (boxRow < workerRow) {
			for (i = workerRow; i > boxRow; i--) {
				warehouse[i][boxCol] = 3;
			}
		}
	}
	
}

/* TASKS 7-10
MakeMove moves the worker up, left, down, or right, by one position if there is an
empty space in front of the worker in the direction of movement (ie - there is no
wall in front of them).
It takes two inputs: warehouse = a 2D array of integers with 10 rows and 10 columns
								representing the layout of the warehouse floor where
								0 is an empty space, 1 is a wall, 2 is a target,
								3 is a box, 4 is a box on a target, 5 is the worker,
								and 6 is the worker on a target
					 move = a single character representing the direction the worker 
					 		should move by one position where 'w' is up, 's' is down,
							'a' is left, and 'd' is right

First, the function uses nested for loops to find the position of the worker. Next, the
function identifies the move that the user wants to make and evaluates if the move is possible.
If so, the move is executed. If not, the array remains unchanged. If all of the targets are
covered (ie - no targets left) and the worker is on a target, the function returns 1 to
represent that the game is complete. If not, the function returns 0 to represent that the game
is incomplete.
*/
int MakeMove(int warehouse[10][10], char move)
{
	int workerRow = 0;
	int workerCol = 0;
	int i, j;
	int targets = 0;
	int workerOnTarget = 0;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			// Finds position of worker
			if (warehouse[i][j] == WORKER || warehouse[i][j] == WORKER_ON_TARGET) {
				workerRow = i;
				workerCol = j;
			}
		}
	}

	// Up
	if (move == 'w' && warehouse[workerRow - 1][workerCol] != WALL) {
		if (warehouse[workerRow][workerCol] == WORKER) { // Worker
			if (warehouse[workerRow - 1][workerCol] == SPACE) { // Space in front of the worker
				warehouse[workerRow][workerCol] = SPACE;
				warehouse[workerRow - 1][workerCol] = WORKER;
			} else if (warehouse[workerRow - 1][workerCol] == TARGET) { // Target in front of worker
				warehouse[workerRow][workerCol] = SPACE;
				warehouse[workerRow - 1][workerCol] = WORKER_ON_TARGET;
			} else if (warehouse[workerRow - 1][workerCol] == BOX) { // Box in front of worker
				if (warehouse[workerRow - 2][workerCol] == SPACE) { // Space in front of box
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow - 1][workerCol] = WORKER;
					warehouse[workerRow - 2][workerCol] = BOX;
				} else if (warehouse[workerRow - 2][workerCol] == TARGET) { // Target in front of box
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow - 1][workerCol] = WORKER;
					warehouse[workerRow - 2][workerCol] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else if (warehouse[workerRow - 1][workerCol] == BOX_ON_TARGET) { // Box on target in front of worker
				if (warehouse[workerRow - 2][workerCol] == SPACE) { // Space in front of box on target
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow - 1][workerCol] = WORKER_ON_TARGET;
					warehouse[workerRow - 2][workerCol] = BOX;
				} else if (warehouse[workerRow - 2][workerCol] == TARGET) { // Target in front of box on target
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow - 1][workerCol] = WORKER_ON_TARGET;
					warehouse[workerRow - 2][workerCol] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else {
				return 0;
			}
		} else if (warehouse[workerRow][workerCol] == WORKER_ON_TARGET) { // Worker on target
			if (warehouse[workerRow - 1][workerCol] == SPACE) { // Space in front of worker on target
				warehouse[workerRow][workerCol] = TARGET;
				warehouse[workerRow - 1][workerCol] = WORKER;
			} else if (warehouse[workerRow - 1][workerCol] == TARGET) { // Target in front of worker on target
				warehouse[workerRow][workerCol] = TARGET;
				warehouse[workerRow - 1][workerCol] = WORKER_ON_TARGET;
			} else if (warehouse[workerRow - 1][workerCol] == BOX) { // Box in front of worker on target
				if (warehouse[workerRow - 2][workerCol] == SPACE) { // Space in front of box
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow - 1][workerCol] = WORKER;
					warehouse[workerRow - 2][workerCol] = BOX;
				} else if (warehouse[workerRow - 2][workerCol] == TARGET) { // Target in front of box
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow - 1][workerCol] = WORKER;
					warehouse[workerRow - 2][workerCol] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else if (warehouse[workerRow - 1][workerCol] == BOX_ON_TARGET) { // Box on target in front of worker on target
				if (warehouse[workerRow - 2][workerCol] == SPACE) { // Space in front of box on target
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow - 1][workerCol] = WORKER_ON_TARGET;
					warehouse[workerRow - 2][workerCol] = BOX;
				} else if (warehouse[workerRow - 2][workerCol] == TARGET) { // Target in front of box on target
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow - 1][workerCol] = WORKER_ON_TARGET;
					warehouse[workerRow - 2][workerCol] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else {
				return 0;
			}
		}
	} // Down
	else if (move == 's' && warehouse[workerRow + 1][workerCol] != WALL) {
		if (warehouse[workerRow][workerCol] == WORKER) { // Worker
			if (warehouse[workerRow + 1][workerCol] == SPACE) { // Space in front of the worker
				warehouse[workerRow][workerCol] = SPACE;
				warehouse[workerRow + 1][workerCol] = WORKER;
			} else if (warehouse[workerRow + 1][workerCol] == TARGET) { // Target in front of worker
				warehouse[workerRow][workerCol] = SPACE;
				warehouse[workerRow + 1][workerCol] = WORKER_ON_TARGET;
			} else if (warehouse[workerRow + 1][workerCol] == BOX) { // Box in front of worker
				if (warehouse[workerRow + 2][workerCol] == SPACE) { // Space in front of box
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow + 1][workerCol] = WORKER;
					warehouse[workerRow + 2][workerCol] = BOX;
				} else if (warehouse[workerRow + 2][workerCol] == TARGET) { // Target in front of box
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow + 1][workerCol] = WORKER;
					warehouse[workerRow + 2][workerCol] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else if (warehouse[workerRow + 1][workerCol] == BOX_ON_TARGET) { // Box on target in front of worker
				if (warehouse[workerRow + 2][workerCol] == SPACE) { // Space in front of box on target
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow + 1][workerCol] = WORKER_ON_TARGET;
					warehouse[workerRow + 2][workerCol] = BOX;
				} else if (warehouse[workerRow + 2][workerCol] == TARGET) { // Target in front of box on target
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow + 1][workerCol] = WORKER_ON_TARGET;
					warehouse[workerRow + 2][workerCol] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else {
				return 0;
			}
		} else if (warehouse[workerRow][workerCol] == WORKER_ON_TARGET) { // Worker on target
			if (warehouse[workerRow + 1][workerCol] == SPACE) { // Space in front of worker on target
				warehouse[workerRow][workerCol] = TARGET;
				warehouse[workerRow + 1][workerCol] = WORKER;
			} else if (warehouse[workerRow + 1][workerCol] == TARGET) { // Target in front of worker on target
				warehouse[workerRow][workerCol] = TARGET;
				warehouse[workerRow + 1][workerCol] = WORKER_ON_TARGET;
			} else if (warehouse[workerRow + 1][workerCol] == BOX) { // Box in front of worker on target
				if (warehouse[workerRow + 2][workerCol] == SPACE) { // Space in front of box
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow + 1][workerCol] = WORKER;
					warehouse[workerRow + 2][workerCol] = BOX;
				} else if (warehouse[workerRow + 2][workerCol] == TARGET) { // Target in front of box
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow + 1][workerCol] = WORKER;
					warehouse[workerRow + 2][workerCol] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else if (warehouse[workerRow + 1][workerCol] == BOX_ON_TARGET) { // Box on target in front of worker on target
				if (warehouse[workerRow + 2][workerCol] == SPACE) { // Space in front of box on target
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow + 1][workerCol] = WORKER_ON_TARGET;
					warehouse[workerRow + 2][workerCol] = BOX;
				} else if (warehouse[workerRow + 2][workerCol] == TARGET) { // Target in front of box on target
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow + 1][workerCol] = WORKER_ON_TARGET;
					warehouse[workerRow + 2][workerCol] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else {
				return 0;
			}
		}
	} // Left
	 else if (move == 'a' && warehouse[workerRow][workerCol - 1] != WALL) {
		if (warehouse[workerRow][workerCol] == WORKER) { // Worker
			if (warehouse[workerRow][workerCol - 1] == SPACE) { // Space in front of the worker
				warehouse[workerRow][workerCol] = SPACE;
				warehouse[workerRow][workerCol - 1] = WORKER;
			} else if (warehouse[workerRow][workerCol - 1] == TARGET) { // Target in front of worker
				warehouse[workerRow][workerCol] = SPACE;
				warehouse[workerRow][workerCol - 1] = WORKER_ON_TARGET;
			} else if (warehouse[workerRow][workerCol - 1] == BOX) { // Box in front of worker
				if (warehouse[workerRow][workerCol - 2] == SPACE) { // Space in front of box
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow][workerCol - 1] = WORKER;
					warehouse[workerRow][workerCol - 2] = BOX;
				} else if (warehouse[workerRow][workerCol - 2] == TARGET) { // Target in front of box
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow][workerCol - 1] = WORKER;
					warehouse[workerRow][workerCol - 2] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else if (warehouse[workerRow][workerCol - 1] == BOX_ON_TARGET) { // Box on target in front of worker
				if (warehouse[workerRow][workerCol - 2] == SPACE) { // Space in front of box on target
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow][workerCol - 1] = WORKER_ON_TARGET;
					warehouse[workerRow][workerCol - 2] = BOX;
				} else if (warehouse[workerRow][workerCol - 2] == TARGET) { // Target in front of box on target
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow][workerCol - 1] = WORKER_ON_TARGET;
					warehouse[workerRow][workerCol - 2] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else {
				return 0;
			}
		} else if (warehouse[workerRow][workerCol] == WORKER_ON_TARGET) { // Worker on target
			if (warehouse[workerRow][workerCol - 1] == SPACE) { // Space in front of worker on target
				warehouse[workerRow][workerCol] = TARGET;
				warehouse[workerRow][workerCol - 1] = WORKER;
			} else if (warehouse[workerRow][workerCol - 1] == TARGET) { // Target in front of worker on target
				warehouse[workerRow][workerCol] = TARGET;
				warehouse[workerRow][workerCol - 1] = WORKER_ON_TARGET;
			} else if (warehouse[workerRow][workerCol - 1] == BOX) { // Box in front of worker on target
				if (warehouse[workerRow][workerCol - 2] == SPACE) { // Space in front of box
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow][workerCol - 1] = WORKER;
					warehouse[workerRow][workerCol - 2] = BOX;
				} else if (warehouse[workerRow][workerCol - 2] == TARGET) { // Target in front of box
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow][workerCol - 1] = WORKER;
					warehouse[workerRow][workerCol - 2] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else if (warehouse[workerRow][workerCol - 1] == BOX_ON_TARGET) { // Box on target in front of worker on target
				if (warehouse[workerRow][workerCol - 2] == SPACE) { // Space in front of box on target
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow][workerCol - 1] = WORKER_ON_TARGET;
					warehouse[workerRow][workerCol - 2] = BOX;
				} else if (warehouse[workerRow][workerCol - 2] == TARGET) { // Target in front of box on target
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow][workerCol - 1] = WORKER_ON_TARGET;
					warehouse[workerRow][workerCol - 2] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else {
				return 0;
			}
		}
	} // Right
	 else if (move == 'd' && warehouse[workerRow][workerCol + 1] != WALL) {
		if (warehouse[workerRow][workerCol] == WORKER) { // Worker
			if (warehouse[workerRow][workerCol + 1] == SPACE) { // Space in front of the worker
				warehouse[workerRow][workerCol] = SPACE;
				warehouse[workerRow][workerCol + 1] = WORKER;
			} else if (warehouse[workerRow][workerCol + 1] == TARGET) { // Target in front of worker
				warehouse[workerRow][workerCol] = SPACE;
				warehouse[workerRow][workerCol + 1] = WORKER_ON_TARGET;
			} else if (warehouse[workerRow][workerCol + 1] == BOX) { // Box in front of worker
				if (warehouse[workerRow][workerCol + 2] == SPACE) { // Space in front of box
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow][workerCol + 1] = WORKER;
					warehouse[workerRow][workerCol + 2] = BOX;
				} else if (warehouse[workerRow][workerCol + 2] == TARGET) { // Target in front of box
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow][workerCol + 1] = WORKER;
					warehouse[workerRow][workerCol + 2] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else if (warehouse[workerRow][workerCol + 1] == BOX_ON_TARGET) { // Box on target in front of worker
				if (warehouse[workerRow][workerCol + 2] == SPACE) { // Space in front of box on target
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow][workerCol + 1] = WORKER_ON_TARGET;
					warehouse[workerRow][workerCol + 2] = BOX;
				} else if (warehouse[workerRow][workerCol + 2] == TARGET) { // Target in front of box on target
					warehouse[workerRow][workerCol] = SPACE;
					warehouse[workerRow][workerCol + 1] = WORKER_ON_TARGET;
					warehouse[workerRow][workerCol + 2] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else {
				return 0;
			}
		} else if (warehouse[workerRow][workerCol] == WORKER_ON_TARGET) { // Worker on target
			if (warehouse[workerRow][workerCol + 1] == SPACE) { // Space in front of worker on target
				warehouse[workerRow][workerCol] = TARGET;
				warehouse[workerRow][workerCol + 1] = WORKER;
			} else if (warehouse[workerRow][workerCol + 1] == TARGET) { // Target in front of worker on target
				warehouse[workerRow][workerCol] = TARGET;
				warehouse[workerRow][workerCol + 1] = WORKER_ON_TARGET;
			} else if (warehouse[workerRow][workerCol + 1] == BOX) { // Box in front of worker on target
				if (warehouse[workerRow][workerCol + 2] == SPACE) { // Space in front of box
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow][workerCol + 1] = WORKER;
					warehouse[workerRow][workerCol + 2] = BOX;
				} else if (warehouse[workerRow][workerCol + 2] == TARGET) { // Target in front of box
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow][workerCol + 1] = WORKER;
					warehouse[workerRow][workerCol + 2] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else if (warehouse[workerRow][workerCol + 1] == BOX_ON_TARGET) { // Box on target in front of worker on target
				if (warehouse[workerRow][workerCol + 2] == SPACE) { // Space in front of box on target
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow][workerCol + 1] = WORKER_ON_TARGET;
					warehouse[workerRow][workerCol + 2] = BOX;
				} else if (warehouse[workerRow][workerCol + 2] == TARGET) { // Target in front of box on target
					warehouse[workerRow][workerCol] = TARGET;
					warehouse[workerRow][workerCol + 1] = WORKER_ON_TARGET;
					warehouse[workerRow][workerCol + 2] = BOX_ON_TARGET;
				} else {
					return 0;
				}
			} else {
				return 0;
			}
		}
	}
	
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == TARGET) {
				targets++;
			} else if (warehouse[i][j] ==  WORKER_ON_TARGET) {
				workerOnTarget = 1;
			}
		}
	}

	if (targets == 0 && workerOnTarget) {
		return 1;
	} else {
		return 0;
	}
}