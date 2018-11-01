#include <boost/regex.hpp>
#include <string>
#include <iostream>

int main(int argc, char** argv) {
	
boost::regex::flag_type regx_flag = boost::regex::ECMAScript | boost::regex::no_except;

std::string input_regex {""};
std::string input_string {""};
std::string replace_string {""};

do{
	std::cout << "Please input regex code: ";
	if (!std::getline(std::cin, input_regex) || input_regex.empty()) {
		return 0;
	}
	const boost::regex regx(input_regex, regx_flag);
	if(regx.status()) {
		std::cout << "Incorrect regex pattern!\n";
		continue;
	}
	std::cout << "String to match: ";
	while(std::getline(std::cin, input_string) && !input_string.empty()) 
	{	
		boost::smatch results;

		if( boost::regex_search(input_string, results, regx) ) 
		{
			std::cout << "MATCH: ";
			std::copy( results.begin() + 1
					 , results.end()
					 , std::ostream_iterator<std::string>( std::cout, ", ") );
			std::cout << "\nReplace pattern: ";
			if (std::getline(std::cin, replace_string) && !replace_string.empty())
			{
				std::cout << "RESULT: " << boost::regex_replace(input_string, regx, replace_string) << std::endl;
			} 
			else 
			{
				std::cin.ignore();
				std::cin.clear();
			}
		}
		else 
		{
			std::cout << "DOES NOT MATCH" << std::endl;
		}
		std::cout << "Hint: To change regex use - CTRL+Z Enter\n";
		std::cout << "Next string to match: ";
	}
	std::cin.ignore();
	std::cin.clear();
}
while(true);

return 0;
}