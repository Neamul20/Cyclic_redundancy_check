//============================================================================
// Name        : crcWithClass.cpp
// Author      : Neamul
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>      //!<for std::cerr, std::cout
#include <boost/crc.hpp>  //!< for boost::crc_32_type
#include <cstdlib>    //!< for EXIT_SUCCESS, EXIT_FAILURE
#include <exception>  //!< for std::exception
#include <fstream>    //!< for std::ifstream
#include <ios>        //!<for std::ios_base, etc.
#include <ostream>    //!< for std::endl

#include "BrainPET7TCRC.h"
//!< Redefine this to change to processing buffer size
#ifndef PRIVATE_BUFFER_SIZE
#define PRIVATE_BUFFER_SIZE  9
#endif


int main(int argc, char const * argv[]) {
	std::streamsize const  buffer_size = PRIVATE_BUFFER_SIZE;

	BrainPET7TCRC bufferChecksum;
	try {

		for ( int i = 1 ; i < argc ; ++i ){

		std::ifstream  ifs( argv[i], std::ios_base::binary );


		if (ifs) {
			do {
			unsigned char buffer[buffer_size];
			ifs.read((char *) buffer, buffer_size);
			for (unsigned short n = 0; n < ifs.gcount(); n++) {
			std::cout << std::hex << "0x"<< (unsigned short) buffer[n] << std::dec<< ' ';
							}
			std::cout << std::endl;
			//!<our class

			int checkSum = bufferChecksum.checkSum(buffer,ifs.gcount());{
				std::cout << std::hex<< std::uppercase<<"Checksum: " << checkSum << std::endl;




			}


	}while (ifs);
		}else {
			std::cerr << "Failed to open file '" << argv[i] << "."<< std::endl;

		}



			}
		return EXIT_SUCCESS;
	}
catch (std::exception &e) {
				std::cerr << "Found an exception with '" << e.what() << "'."
						<< std::endl;
				return EXIT_FAILURE;
			} catch (...) {
				std::cerr << "Found an unknown exception." << std::endl;
				return EXIT_FAILURE;
			}

		return 0;
}


