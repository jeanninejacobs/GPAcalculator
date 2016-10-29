//Jeannine Jacobs
//C++ - SCCC
//May 3, 2015
// FINAL PROJECT - GPA

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class student
{
public:
	void setNumCourses(int);
	void setName(string);
private:
	string name;
	int numCourses;
};

//***** setNumCourses assigns value to numCourses member. *****//
void student::setNumCourses(int num)
{
	numCourses = num;
}

//**** setNae assigns value to the name member. *****//
void student::setName(string n)
{
	name = n;
}


class Course
{
public:
	Course();
	Course(string, double, double, double, double);
	void setName(string);
	void setCreditHours(double);
	void setHWGrade(double);
	void setFinal(double);
	void setTestAvg(double);
	void setHWPercent(double);
	void setFinalPercent(double);
	void setTestPercent(double);
	void calcCourseAvg();
	double getCourseAvg();
	double getCreditHours();
	string getName();
private:
	string name;
	double creditHours;
	double hwGrade;
	double finalGrade;
	double testAvg;
	double hwPercent;
	double finalPercent;
	double testPercent;
	double courseGrade;
};

//***** Default Constructor *****//
Course::Course()
{
	name = " ";
	creditHours = 0.0;
	hwGrade = 0.0;
	finalGrade = 0.0;
	testAvg = 0.0;
}

//***** setName assigns value to name member. *****//
void Course::setName(string title)
{
	name = title;
}

//***** setCreditHours assigns value to creditHours member. ****//
void Course::setCreditHours(double c)
{
	creditHours = c;
}

//***** setHWGrade assigns a value to hwGrade member *****//
void Course::setHWGrade(double h)
{
	hwGrade = h;
}

//*****setFinal assigns a value to the finalGrade member *****//
void Course::setFinal(double f)
{
	finalGrade = f;
}

//***** setTestAvg assigns a value to the testAvg member *****//
void Course::setTestAvg(double t)
{
	testAvg = t;
}

//***** setHWPercent assigns a value to the hwPercent member *****//
void Course::setHWPercent(double h)
{
	hwGrade = h;
}

//***** setFinalPercent assigns a value to the finalPercent member *****//
void Course::setFinalPercent(double f)
{
	finalPercent = f;
}

//***** setTestPercent assigns a value to the testPercent mamber. *****//
void Course::setTestPercent(double tp)
{
	testPercent = tp;
}

//***** calcCourseAvg calculates and returns the overall average for a single course *****//
void Course::calcCourseAvg()
{
	double h,f,t;
	h = hwGrade * hwPercent;
	cout << h << endl;
	f = finalGrade * finalPercent;
	cout << f << endl;
	t = testAvg * testPercent;
	cout << t << endl;
	courseGrade = h + f + t;
	cout << courseGrade;
}

//***** getCourseAvg returns the value of courseAvg member *****//
double Course::getCourseAvg()
{
	return courseGrade;
}

//***** getCreditHours returns the value of creditHours member *****//
double Course::getCreditHours()
{
	return creditHours;
}

//***** getName returns the value of name member *****//
string Course::getName()
{
	return name;
}

int main()
{
	string name, cName, *courseList = nullptr;
	int num = 0, numTests = 0;
	double creditHours = 0, hwGrade = 0, finalGrade = 0, testAvg = 0, test = 0, allTests = 0;
	double homeworkP = 0, testsP = 0, finalP = 0, gpa = 0;

	cout << "Enter the name of the student: ";
	cin >> name;

	student myStudent;
	myStudent.setName(name);

	cout << "How many courses has " << name << " taken? ";
	cin >> num;
		
	myStudent.setNumCourses(num);
	Course *listPtr = nullptr;
	listPtr = new Course[num];

	for (int i = 0; i < num; i++)
	{
		cin.ignore();
		cout << "Enter the name of course: " << i + 1 << " : ";
		getline(cin, cName);
		listPtr[i].setName(cName);		

		cout << "How many credit hours? ";
		cin >> creditHours;
		listPtr[i].setCreditHours(creditHours);

		cout << "Enter the final homework grade: ";
		cin >> hwGrade;
		listPtr[i].setHWGrade(hwGrade);

		cout << "What is the percentage for the homework grade? \nEnter amount as a decimal: ";
		cin >> homeworkP;
		listPtr[i].setHWPercent(homeworkP);

		cout << "Enter the final exam grade: ";
		cin >> finalGrade;
		listPtr[i].setFinal(finalGrade);

		cout << "What is the percentage of final exam towards course grade? \nEnter amount as a decimal: ";
		cin >> finalP;
		listPtr[i].setFinalPercent(finalP);

		cout << "How many tests were given? ";
		cin >> numTests;

		for (int j = 0; j < numTests; j++)
		{
			cout << "Enter the grade for test " << j + 1 << ": ";
			cin >> test;
			allTests += test;
		}
		
		testAvg = allTests / numTests;
		listPtr[i].setTestAvg(testAvg);

		cout << "What is the percentage for the test average grade? \nEnter amount as a decimal: ";
		cin >> testsP;
		listPtr[i].setTestPercent(testsP);		
	}
	
	double totalpoints = 0.0, totalgrades = 0.0, cGrade = 0.0;
		
	for (int i = 0; i < num; i++)
	{
		totalpoints += listPtr[i].getCreditHours();
		cGrade = listPtr[i].getCourseAvg();

		if (cGrade >= 90)
		{
			cGrade = 4.0;
		}

		if (cGrade < 90 && cGrade >= 80)
		{
			cGrade = 3.0;
		}

		if (cGrade < 80 && cGrade >= 70)
		{
			cGrade = 2.0;
		}

		if (cGrade < 70 && cGrade >= 60)
		{
			cGrade = 1.0;
		}

		totalgrades += (cGrade * creditHours);
	}

	gpa = totalgrades / totalpoints;
	
	cout << "\n\n\n   Student Transcript" << endl;
	cout << "______________________________" << endl;
	cout << "\nStudent Name: " << name << endl;
	cout << "\n" << endl;
	cout << "Course Name \t Course Grade" << endl;
	cout << "----------------------------------" << endl;

	cout << setprecision(2) << fixed;
	for (int i = 0; i < num; i++)
	{
		cout << listPtr[i].getName() << "\t\t" << listPtr[i].getCourseAvg() << endl;
	}

	cout << "\nFinal GPA: " << gpa;

	cin.get();
	cin.get();
	return 0;
}