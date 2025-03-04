#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "students.txt";

enum Speicalty
{
	UNKNOWN = -1,
	MATHEMATICS,
	COMPUTER_SCIENCE,
	INFORMATICS,
	COUNT
};


struct Student
{
	char firstName[30];
	char lastName[30];
	char fn[10];
	char email[20];
	Speicalty specialty;

};
void printStudent(Student& student)
{
	std::cout << student.firstName << " " << student.lastName << " " << student.fn 
		<< " " << student.email << " ";

	switch (student.specialty)
	{
	case 0: std::cout << "MATHEMATICS"; break;
	case 1: std::cout <<"COMPUTER_SCIENCE"; break;
	case 2: std::cout <<"INFORMATICS"; break;
	default: std::cout <<"UNKNOWN"; break;

	}
	std::cout << "\n";

}
void  generateStudent(Student& student)
{
	
	const char* firstNames[] = {"Ivan","Petar","Stoyan","Georgi"};
	const char* lastNames[] = { "Ivanov", "Petrov", "Stoyanov", "Gerogiev" };
	const char* fns[] = { "123456789", "369852147", "756541972", "548524564" };
	const char* emails[] = { "@gmail", "@email", "@abv", "@proton" };
	Speicalty speicalties[] = { {Speicalty::MATHEMATICS}, {Speicalty::COMPUTER_SCIENCE}, 
	{Speicalty::INFORMATICS} };


	strcpy_s(student.firstName, firstNames[std::rand() % 4]);
	strcpy_s(student.lastName, lastNames[std::rand() % 4]);
	strcpy_s(student.fn, fns[std::rand() % 4]);
	strcpy_s(student.email, emails[std::rand() % 4]);

	student.specialty = speicalties[std::rand() % 3];


}
void writeStudentToFile(const Student& student,std::ofstream& out)
{
	out << student.firstName << " " << student.lastName << " " << student.fn 
	<< " " << student.email << " ";

	out << (int)student.specialty ;; // ??? do i convert it to int or no 
}
void readStudentInFile(Student& student,std::ifstream& in)
{
	in >> student.firstName >> student.lastName >> student.fn >> student.email;
	int num;
	in >> num;
	switch (num)
	{
	case 0: student.specialty = Speicalty::MATHEMATICS; break;
	case 1: student.specialty = Speicalty::COMPUTER_SCIENCE; break;
	case 2: student.specialty = Speicalty::INFORMATICS; break;
	default: student.specialty = Speicalty::UNKNOWN; break;
	}

}


void writeArrStudentsToFile(const Student* students, int size,std::ofstream& out)
{
	out << size << "\n";
	for (size_t i = 0; i < size; ++i) 
	{
		writeStudentToFile(students[i],out);
		out << "\n";
	}
}
void readArrStudentsInFile(Student* students,std::ifstream& in)
{
	int size;
	in >> size;

	for (size_t i = 0; i < size; i++)
	{
		readStudentInFile(students[i], in);
	}

}



int main()
{

	std::srand(std::time(0));
	int n;
	std::cout << "Enter number of students: ";
	std::cin >> n;
	Student *  students = new Student[n];
	
	for (size_t i = 0; i < n; i++)
	{
		generateStudent(students[i]);
	}



	std::ofstream out(FILE_NAME, std::ios::out);

	if (!out)
	{
		std::cerr << "Error with opening the file";
		return -1;
	}

	writeArrStudentsToFile(students, n, out);

	if (!out)
	{
		std::cerr << "Error with writing to the file";
		return -2;

	}
	out.close();

	Student studentsRead[30];
	std::ifstream in(FILE_NAME, std::ios::in);
	if (!in)
	{
		std::cerr << "Error with opening the file";
		return -1;
	}

	readArrStudentsInFile(studentsRead, in);

	if (!in)
	{
		std::cerr << "Error with reading the file";
		return -2;
	}

	for (size_t i = 0; i < n; i++)
	{
		printStudent(studentsRead[i]);
	}

	in.close();
	
	




}