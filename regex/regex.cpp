#include <boost/regex.hpp>
#include <string>
#include <iostream>

int main(int argc, char** argv) {

// Ctor #1
//explicit basic_regex ();
	boost::regex default_c;
	
// Ctor #2
//explicit basic_regex(const  charT* p, flag_type f = regex_constants::normal);
	boost::regex cstr_wflag("\\d+", boost::regex_constants::perl);

// Ctor #3
//basic_regex(const charT* p1, const  charT* p2, flag_type f = regex_constants::normal);
	char cstr1[] = "abcdef";
	boost::regex two_cstr_wflag(cstr1, cstr1+3 , boost::regex_constants::ECMAScript);

// Ctor #4
//basic_regex(const charT* p, size_type len, flag_type f);
	boost::regex ctr_and_length("\\d+abcd", 4, boost::regex_constants::basic);

// Ctor #5
//basic_regex(const basic_regex& e);
	boost::regex regx_copy(cstr_wflag);

// Ctor #6
//template <class ST, class SA>basic_regex(const basic_string<charT, ST, SA>& s, flag_type f = regex_constants::normal);
	boost::regex str_wflag(std::string("\\d+abc"), boost::regex_constants::JavaScript);

// Ctor #7
//template <class ForwardIterator>basic_regex(ForwardIterator first, ForwardIterator last, flag_type f = regex_constants::normal);
	std::string temp_str {"\\w+post"};
	boost::regex regx_witer(temp_str.begin(), temp_str.end()-2, boost::regex_constants::JScript);

//basic_regex& operator=(const basic_regex& e);
//basic_regex& operator=(const charT* ptr);
//template <class ST, class SA>basic_regex& operator=(const basic_string<charT, ST, SA>& p);
	boost::regex r1("\\s+(abcd)\\d+");
	boost::regex r2;
	r2 = r1;
	r2 = "abcd";
	r2 = std::string("dcba");

//std::pair<const_iterator, const_iterator> subexpression(size_type n) const;
	boost::regex r3("xx.?yy|(xx.?zz|aa.*?bb)", boost::regex::save_subexpression_location);
	auto [sub_it_b, sub_it_e] = r3.subexpression(0);
	std::cout << std::string(sub_it_b, sub_it_e+1) << '\n';

//size_type mark_count() const;
	auto count_subexpr = r3.mark_count();
	std::cout << "Counted sub-expressions: " << count_subexpr << '\n';

//const_iterator begin() const;
//const_iterator end() const;
	auto r2_it_b = r2.begin();
	auto r2_it_e = r2.end();
	
//size_type size() const;
//size_type max_size() const;
	std::cout <<  r2.size() << "\nmax size: " << r2.max_size() << '\n';
	
//bool empty() const;
	if(not r2.empty()) std::cout << "r2 not empty" << '\n';
	
//basic_regex& assign(const basic_regex& that);
//basic_regex& assign(const charT* ptr, flag_type f = regex_constants::normal);
//basic_regex& assign(const charT* ptr, unsigned int len, flag_type f);
//template <class string_traits, class A> basic_regex& assign(const basic_string<charT, string_traits, A>& s, flag_type f = regex_constants::normal);
	boost::regex r4;
	r4.assign(r2);
	r4.assign("qwerty");
	r4.assign(cstr1, 3, boost::regex_constants::normal);
	r4.assign(std::string("\\d+"));
	
//flag_type flags() const;
	boost::regex r5("aagg", r3.flags());
	
//int status() const;
	if(r5.status() == 0) std::cout << "r5 status: Expression valid." << std::endl;
	
//basic_string<charT> str() const;
	std::string r5str = r5.str();
	
//int compare(basic_regex& e)const;
	auto cmp_r5r4 = r5.compare(r4);
	std::cout << "Compare return: " << cmp_r5r4 << std::endl;
	
//locale_type imbue(locale_type l);
//locale_type getloc() const;

//template <class charT, class traits>bool operator == (const basic_regex<charT, traits>& lhs, const basic_regex<charT, traits>& rhs);
//template <class charT, class traits>bool operator != (const basic_regex<charT, traits>& lhs, const basic_regex<charT, traits>& rhs);
//template <class charT, class traits>bool operator < (const basic_regex<charT, traits>& lhs, const basic_regex<charT, traits>& rhs);
//template <class charT, class traits>bool operator <= (const basic_regex<charT, traits>& lhs, const basic_regex<charT, traits>& rhs);
//template <class charT, class traits>bool operator >= (const basic_regex<charT, traits>& lhs, const basic_regex<charT, traits>& rhs);
//template <class charT, class traits>bool operator > (const basic_regex<charT, traits>& lhs, const basic_regex<charT, traits>& rhs);
	if (r5 == r4) std::cout << "r5 and r4 are equal\n";
	if (r5 != r4) std::cout << "r5 and r4 are not equal\n";
	if (r5 <  r4) std::cout << "r5 is less than r4\n";
	if (r5 <= r4) std::cout << "r5 is less than or equal to r4\n";
	if (r5 >  r4) std::cout << "r5 is greater than r4\n";
	if (r5 >= r4) std::cout << "r5 is greater than or equal to r4\n";

//void swap(basic_regex& e) throw();
//template <class charT, class traits>
//void swap(basic_regex<charT, traits>& lhs, basic_regex<charT, traits>& rhs);
	r4.swap(r5);
	swap(r5, r4);
	
//template <class charT, class io_traits, class re_traits>
//basic_ostream<charT, io_traits>& operator << (basic_ostream<charT, io_traits>& os const basic_regex<charT, re_traits>& e);
	std::cout << r5 << std::endl;

return 0;
}