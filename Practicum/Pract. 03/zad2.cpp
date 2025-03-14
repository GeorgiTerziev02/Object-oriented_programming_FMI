#include <iostream>
#include <fstream>

constexpr char INPUT_NAME[] = "Input.txt";
constexpr char OUTPUT_NAME[] = "Output.txt";




void copyOneFileToOther(std::ifstream& in,std::ofstream& out)
{
	char ch;
	while (in.get(ch))
	{
		out.put(ch);
	}
	in.clear();
	if (!in || !out)
	{
		std::cerr << "The copy operation failed\n";
		return;
	}
}
int main()
{
	std::ifstream in(INPUT_NAME, std::ios::in);

	if (!in)
	{
		std::cerr << "Problem with opeining file " << INPUT_NAME << "\n";
		return -1;
	}


	std::ofstream out(OUTPUT_NAME, std::ios::out);

	if (!out)
	{
		std::cerr << "Problem with opeining file " << OUTPUT_NAME << "\n";
		return -1;
	}

	copyOneFileToOther(in, out);


}