#include <boost/regex.hpp>
#include <string>
#include <iostream>

int main(int argc, char** argv) {
	std::string s = "Boost Libraries";
	boost::regex expr {"(\\w)\\w+"};
	
//typedef regex_token_iterator<const char*>                   cregex_token_iterator;
//typedef regex_token_iterator<std::string::const_iterator>   sregex_token_iterator;
//regex_token_iterator(BidirectionalIterator a, 
//                     BidirectionalIterator b, 
//                     const regex_type& re, 
//                     int submatch = 0, 
//                     match_flag_type m = match_default);
	boost::regex_token_iterator<std::string::iterator> it{s.begin(), s.end(),expr, 1};
	boost::regex_token_iterator<std::string::iterator> end;
	while (it != end) {
		std::cout << *it++ << '\n';
	}

// Getting urls from string, and print out using regex_token_iterator
	std::string html =	"<p><a href=\"http://google.com\">google</a> "
						"< a HREF =\"http://cppreference.com\">cppreference</a>\n</p>";
	boost::regex url_regx("<\\s*A\\s+[^>]*href\\s*=\\s*\"([^\"]*)\"", boost::regex::icase);
	std::copy(boost::sregex_token_iterator(html.begin(), html.end(), url_regx, 1),
              boost::sregex_token_iterator(),
              std::ostream_iterator<std::string>(std::cout, "\n"));

//regex_token_iterator<...> make_regex_token_iterator()

	boost::regex regx2 {"\\d{3,5}"};
	auto regx_tkn_iter = boost::make_regex_token_iterator("string 123, 94827, 44, 3337777", regx2);
	boost::cregex_token_iterator endch;
	while (regx_tkn_iter != endch) {
		std::cout << *regx_tkn_iter++ << '\n';
	}
	return 0;
}