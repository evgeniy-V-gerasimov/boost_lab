#include <boost/regex.hpp>
#include <string>
#include <iostream>

int main(int argc, char** argv) {
	
boost::regex::flag_type regx_flag = boost::regex::ECMAScript | boost::regex::no_except;

std::string input_regex {""};
std::string input_string {""};

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
	while(std::getline(std::cin, input_string) && !input_string.empty()) {
		bool matched = boost::regex_match(input_string, regx);
		std::cout << (matched ? "MATCH\n" : "DOES NOT MATCH\n");
		std::cout << "Hint: To change regex use - CTRL+Z Enter\n";
		std::cout << "Next string to match: ";
	}
	std::cin.ignore();
	std::cin.clear();
}
while(true);

return 0;
}