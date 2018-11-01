#include <boost/format.hpp>
#include <iostream>
#include <tuple>
#include <iomanip>

int main(int argc, char** argv) {
	std::ignore = argc;
	std::ignore = argv;
	std::cout << boost::format{"Date format: %1%.%2%.%3%"} % 12 % 5 % 2018 << '\n';
	std::cout << boost::format("%1%: %2%.%3%.%4%.%5%:%6% \n") % "IPv4 format" % 127 % 0 % 0 % 1 % 80;
	
	boost::format second_first_fmt("%2% %1%");
	second_first_fmt % 36; 
	second_first_fmt % 77;
	std::cout << second_first_fmt << std::endl;
	
	std::string formatted_str1 {second_first_fmt.str()}; // convert to string
	std::cout << formatted_str1 << std::endl;
	
	std::string formatted_str2 = str( boost::format("%1% %1% %2%") % 42 % '\n' ); // convert to string with free function
	std::cout << formatted_str2;
	
	second_first_fmt % 222 % 111;				// format reuse
	std::cout << second_first_fmt << std::endl;

//[ N$ ] [ flags ] [ width ] [ . precision ] [ argument-type ] conversion-specifier
// _flags_
//	'-'	left alignment
//	'='	centered alignment	
//	'_'	internal alignment	
//	'+'	show sign even for positive numbers	(sets showpos)
//	'#'	show numerical base, and decimal point	(sets showbase and showpoint)
//	'0'	pad with 0's (inserted after sign or base indicator)
//	' '	if the string does not begin with + or -, insert a space before the converted string
// _conversion-specifier_
// b		boolean string output	(sets boolalpha) (only works for type bool)
// p or x	hexadecimal output	(sets hex)
// o		octal output	(sets oct)
// a		hexadecimal exponent notation	(sets floatfield bits to scientific | fixed (equivalent to hexfloat)
// e		scientific float format	(sets floatfield bits to scientific)
// f		fixed float format	(sets floatfield bits to fixed)
// g		general -default- float format	(unset all floatfield bits)
// X, A, E, F, G	(same effects as 'x', 'a', 'e', 'f', or 'g' respectively, plus uppercase)
// d, i or u	decimal type output	(sets basefield bits to dec)
// s or S	string output	
// c or C	1-character output	(only the first character of the conversion string is used.)
// %	print the character %

	std::cout << boost::format("(x,y) = (%1$+#=10.4f,%2$+#=10.4f) \n") % -3.1 % 35.01;     // Posix-Printf style
	std::cout << boost::format("(x,y) = (%2$-5d,%1$-5d) \n") % -23 % 35; 

	std::cout << boost::format("(x,y) = (%+5d,%+5d) \n") % -23 % 35;
	std::cout << boost::format("(x,y) = (%|+5|,%|+5|) \n") % -23 % 35;
	std::cout << boost::format("(x,y) = (%1$+5d,%2$+5d) \n") % -23 % 35;	
	std::cout << boost::format("(x,y) = (%|1$+5|,%|2$+5|) \n") % -23 % 35;

	std::cout << boost::format("writing %s,  x=%s : %d-th step \n") % "str" % 40.23 % 50; // Classical printf directive
	
	// Using manipulators to modify the format-string
	boost::format fmter1("_%1$+5d_ %1$d \n");
	boost::format fmter2("_%1%_ %1% \n");
	fmter2.modify_item(1, boost::io::group(std::showpos, std::setw(5)) ); 
	
	std::cout << fmter1 % 101 ;
	std::cout << fmter2 % 101 ;

	std::cout << boost::format("_%1%_ %1% \n") % boost::io::group(std::showpos, std::setw(5), 101);
	
	std::vector<std::string> names{"Bjarne", "Scott", "Andrey"};
	std::vector<std::string> surname{"Stroustrupp", "Meyers", "Alexandrescu"};
	std::vector<std::string> tel{"+33 (0) 123 456 789", "+33 (0) 987 654 321", "+33 (0) 654 321 789"};
	for(unsigned int i=0; i < names.size(); ++i) {
		std::cout << boost::format("%1%, %2%, %|40t|%3%\n") % names[i] % surname[i] % tel[i];
	}

	boost::format f1("--{%1%}");
	try {
		std::cout << f1 << std::endl;
	}
	catch(boost::io::too_few_args& fe){
		std::cout << "Provide arguments to format.\n" << fe.what() << std::endl;
	}
	
	boost::format f2("--[%1%]"); 
	try {
		f2 % 13 % 22;
	}
	catch(boost::io::too_many_args& fe){
		std::cout << "Too many args provided.\n" << fe.what() << std::endl;
	}

	try {
		std::cout << boost::format("(x,y) = (%|1$+5|,%+5d) \n") % -23 % 35;
	}
	catch(boost::io::bad_format_string& fe){
		std::cout << "Mixing of positional and non-positional format specification is not allowed.\n" << fe.what() << std::endl;
	}
	return 0;
}