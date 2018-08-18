#include <boost/config.hpp>
#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <iostream>
#include <tuple>

static const std::string provider =
#ifdef BOOST_WINDOWS
"Microsoft RSA SChannel Cryptographic Provider" //  or - "Microsoft Strong Cryptographic Provider"  
#else
"/dev/urandom" // or - "/dev/random"
#endif
;

int main(int argc, char** argv) {
	std::ignore = argc;
	std::ignore = argv;
	
	boost::random_device device(provider);
	boost::random::uniform_int_distribution<unsigned short> random(1000);

	std::cout << provider << ":\n";
	for(auto i{0};i < 10; ++i)
	{
		auto random_number {random(device)};
		std::cout << random_number << '\n';
	}
	return 0;
}