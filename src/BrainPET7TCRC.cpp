/**
 * \filename CalculateChecksum.cpp (/crcWithClass/src/CalculateChecksum.cpp,/home/neamul/eclipse-workspace/crcWithClass/src/CalculateChecksum.cpp)
 * \ingroup crcWithClass
 * \brief
 *
 * \date:   Created on: Nov 25, 2019
 * \author: neamul
 * \version: 0.0
 *
 * \remarks 
 *
 * \todo TODO
 */
#include "BrainPET7TCRC.h"

#include <boost/crc.hpp>  //!< for boost::crc

#include <cstdlib>    //!< for EXIT_SUCCESS, EXIT_FAILURE
#include <exception>  //!< for std::exception
#include <fstream>    //!< for std::ifstream
#include <ios>        //!< for std::ios_base, etc.
#include <iostream>   //!< for std::cerr, std::cout
#include <ostream>    //!< for std::endl
#ifndef PRIVATE_BUFFER_SIZE
#define PRIVATE_BUFFER_SIZE  9

#endif



BrainPET7TCRC::BrainPET7TCRC(){


};

BrainPET7TCRC::~BrainPET7TCRC() {
	//! TODO Auto-generated destructor stub
}

 int BrainPET7TCRC::checkSum(unsigned char buffer[], unsigned short buffer_Length){




  boost::crc_optimal<16, 0x8085, 0, 0, true, true>  defaultCRC;
  //!<SIze_t Bits size,int TrunPoly,int InitRem,int FinalXor,bool ReflectI,bool ReflectRem>

	 defaultCRC.process_bytes((char *) buffer, buffer_Length);


	return defaultCRC.checksum() ;



}
