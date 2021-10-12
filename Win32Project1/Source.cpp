#include "../Win32Project2/Header2.h"
#include "Header.h"
#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char** argv)
{/*
	std::cout << "argv[0]: " << argv[0] << std::endl;
	std::cout << "argv[1]: " << argv[1] << std::endl;
	std::cout << "argc: " << argc << std::endl << std::endl;
*/

	// Declare the supported options.
	po::options_description desc("Allowed options");
	desc.add_options()
		("help", "produce help message")
		("width", po::value<int>()->default_value(3), "width arr")
		;

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	if (vm.count("help")) {
		std::cout << desc << "\n";
		return 1;
	}

	if (vm.count("width")) {
		std::cout << vm["width"].as<int>() << "\n";
	}
	else {
		std::cout << "Compression level was not set.\n";
	}




	int const size = vm["width"].as<int>();

	double **arr = new double *[size];;

	setArr(arr, size);

	printArr(arr, size);

	

	return 0;
}
