#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <iostream>


#include "sexmachine.h"


#include "json11/json11.hpp"
using json11::Json;

//using std::vector;
//using std::string;



CSexMachine::CSexMachine(const std::string & cfgpath) 
{
	std::cout << "CSexMachine - ready" << std::endl;
}

CSexMachine::~CSexMachine()
{
	std::cout << "CSexMachine::~CSexMachine()" << std::endl;
}

std::string CSexMachine::Analyze(const std::string & imgfile, const std::string & faceMetaJSON)
{
//	try
//	{

	std::cout << "CSexMachine::Analyze(\"" << imgfile << "\", \"" << faceMetaJSON << "\")"<< std::endl;

	// load image from file

	// load location from meta
	std::string err;
	//Json json = Json::parse(faceMetaJSON, err);
	//auto coordinates = json["coordinates"];
	Json coordinates = Json::parse(faceMetaJSON, err);


	Json jsonresult = Json::object 	{
		{"isMale", Json((bool)true)},
		{"isMaleProbability", Json((float)0.5)},
		{"isChild", Json((bool)false)},
		{"isChildProbability", Json((float)0.5)},
		{"age_min", Json((int)14)},
		{"age_max", Json((int)28)},
	//	{"processing-time", Json(tmeasure.marksecs2str() + " seconds")}
	};
	std::string stresult = jsonresult.dump();

	std::cout << "CSexMachine::Analyze(\"" << imgfile << "\", \"" << faceMetaJSON << "\") result " << stresult << std::endl;
	return stresult;

//	}
//	catch(const std::ifstream::failure & e)
//	{
//		std::cout << "CMatchMachine::~MatchIndexFiles stream failure: " << e.what() << std::endl;
//		throw;
//	}

}


std::string testsexmachine(
	const std::string& cfgfile, 
	const std::string& imgfile,
	const std::string& faceMeta
	)
{
	std::cout << "testsexmachine cfgfile = '" << cfgfile << "', imgfile = '" << imgfile << "', faceMeta = '" << faceMeta << "'" << std::endl;

	try{

	std::cout << "create SM cfgfile = '" << cfgfile << std::endl;
	std::shared_ptr<CSexMachine> SM = std::make_shared<CSexMachine>(cfgfile);
	
	std::cout << "match firfiles  imgfile = '" << imgfile << "', faceMeta = '" << faceMeta << "'" << std::endl;
	
	auto res = SM->Analyze( imgfile, faceMeta);

	std::cout << "result : '" << res << std::endl;
	
	return res;
	
	}catch(...){
		return "";
	}
	
	
}

