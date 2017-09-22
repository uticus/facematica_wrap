#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <memory>

#include "matchmachine.h"

using std::vector;
using std::string;


CMatchMachine::CMatchMachine(const std::string & cfgpath) 
{
	std::cout << "CMatchMachine - ready" << std::endl;
}

CMatchMachine::~CMatchMachine()
{
	std::cout << "CMatchMachine::~CMatchMachine()" << std::endl;
}

float CMatchMachine::MatchIndexFiles(const string & firfile1, const string & firfile2)
{
//	try
//	{

	//TODO appropriate logging
	std::cout << "CMatchMachine::MatchIndexFiles(\"" << firfile1 << "\", \"" << firfile2 << "\")"<< std::endl;

	std::ifstream fs1, fs2;

#define BUFF_SIZE 256
	char buff1[BUFF_SIZE];
	std::memset(buff1, 0, BUFF_SIZE);
	char buff2[BUFF_SIZE];
	std::memset(buff2, 0, BUFF_SIZE);


	fs1.open(firfile1, std::istream::binary);
	fs2.open(firfile2, std::istream::binary);

	fs1.read(buff1, BUFF_SIZE);
	fs2.read(buff2, BUFF_SIZE);

    float l = 0;
    for( int i=0; i < BUFF_SIZE; i++){
    	l += (1.0 *(buff1[i] - buff2[i]) ) / BUFF_SIZE;
    }

	float result = 100 - l * 50 / 255;
	std::cout << "CMatchMachine::MatchIndexFiles(\"" << firfile1 << "\", \"" << firfile2 << "\") result " << result << std::endl;
	return result;

//	}
//	catch(const std::ifstream::failure & e)
//	{
//		std::cout << "CMatchMachine::~MatchIndexFiles stream failure: " << e.what() << std::endl;
//		throw;
//	}

}


float testmatchmachine(
	const std::string& cfgfile, 
	const std::string& firfile1, 
	const std::string& firfile2
	)
{
	std::cout << "testmatchmachine cfgfile = '" << cfgfile << "', firfile1 = '" << firfile1 << "', firfile2 = '" << firfile2 << "'" << std::endl;

	try{

	std::cout << "create MM cfgfile = '" << cfgfile << std::endl;
	std::shared_ptr<CMatchMachine> MM = std::make_shared<CMatchMachine>(cfgfile);
	
	std::cout << "match firfiles  firfile1 = '" << firfile1 << "', firfile2 = '" << firfile2 << "'" << std::endl;
	
	auto res = MM->MatchIndexFiles( firfile1, firfile2);

	std::cout << "result : '" << res << std::endl;
	
	return res;
	
	}catch(...){
		return 0;
	}
	
	
}

