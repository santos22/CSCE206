// Santos Solorzano
// CSCE 206-301
// A4/9.13

// This program gathers statistical data about
// the number of movies college students
// see in a month; it calculates the average,
// median, and mode of our data

#include <iostream>

// function prototypes
void students(int);
void average(double *, int);
void median(double *, int);
int mode(double *, int);

using namespace std;

int main()
{
    int numStudents; // variable to hold the number of students surveyed
    
    cout << "How many students were surveyed? " << endl;
    cin >> numStudents;

	while (numStudents < 0)
        {
            cout << "Please enter a non-negative number for the number of students you surveyed: ";
            cin >> numStudents;
        }
    
	cout << "Enter the number of movies each student saw." << endl;

	// function call to dynamically enter the number of
	// movies each student saw into an array
	students(numStudents);

	return 0;
}

// function that allows the user to dynamically create an array
void students(int num)
{
	int least; // variable to hold least-occurring number of movies seen

	// to dynamically allocate an array
    double *summerMovies;
    
    // dynamically allocates an array large enough to hold
    // the number of movies viewed by each student
    summerMovies = new double[num];
    
    // user input for # of movies for each student
    for (int count = 0; count < num; count++)
    {
        cout << "Student " << (count + 1) << ": ";
        cin >> *(summerMovies + count);
        
        // input validation that does not accept negative values for number of movies
        while (*(summerMovies + count) < 0)
        {
            cout << "Please enter a non-negative number for the number of movies you viewed: ";
            cin >> *(summerMovies + count);
        }
    }

	average(summerMovies, num); // function call that calculates the average number of movies seen
	median(summerMovies, num); // function call that calculates the median number of movies seen
	least = mode(summerMovies, num); // function call that calculates the mode for the least-occurring number of movies seen

	cout << "The least frequent of the number of movies seen is: " << least << endl;

	// frees dynamically allocated memory
	delete [] summerMovies;

	// sets summerMovies array equal to null
	summerMovies = 0;
}

// function that calculates the average number of movies seen
void average(double *array, int num)
{
	double total = 0; // counter to hold total number of movies watched
    
    // for loop that sums the number of movies each student watched
    for (int count = 0; count < num; count++)
        total += *(array + count); // adds up number of movies watched and assigns to total
    
	cout << "The average number of movies watched over the summer was: " << (total/num) << endl;
}

// function that calculates the median number of movies seen
void median(double *array, int num)
{
	double median; // holds median value
	int middle; // to access middle element(s)

	if (num % 2 != 0) // if-statement to see if number of elements in array is odd or even
	{
		middle = (num + 1)/(2);
		median = *(array + middle); // odd number of elements so median is the middle value
	}
	else
	{
		middle = (num/2);
		median = (*(array + middle - 1) + *(array + middle))/(2); // even number of elements so median is the average of the two middle values
	}
    
	cout << "The median was: " << median << endl;
}

// function that calculates the mode for number of movies seen
int mode(double *array, int num)
{
	int mostFrequent = 0;
    int leastFrequency = num;
    int leastFrequentNumber = -1;

	// for loop that compares values in array and determines value
	// that occurs first in the array and is the least frequent
	// occurring value
    for (int startScan = 0; startScan < num - 1; startScan++)
    {
        // counter for mode of each value
        int count = 0;

        // inefficient for-loop that finds mode for each value
        for (int index = 0; index < num; index++)
        {
            if (*(array + startScan) == *(array + index))
            {
                count++;
            }
        }

		// most frequent value occurring
        if (count > mostFrequent)
            mostFrequent = count;

		// if we encounter a mode of 1, it is automatically
		// the least frequent and we return the value
        if (count == 1)
            return  *(array + startScan);

        // if least frequent is not = 1, we need to calculate
		// how many times the least frequent value occurs and
		// save its position
        if (count < leastFrequency)
        {
            leastFrequency = count;
            leastFrequentNumber = *(array + startScan);
        }

    }

	return leastFrequentNumber;
}