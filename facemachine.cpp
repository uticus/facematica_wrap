

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <memory>

#include "facemachine.h"


#include "json11/json11.hpp"
using json11::Json;


CFaceMachine::CFaceMachine( const std::string& cfgfile) {
	
	std::cout << "CFaceMachine - ready" << std::endl;
}

std::string CFaceMachine::Detect(const std::string& imgfile, const std::string& tmpfolder) { 
		
	std::cout << "CFaceMachine::Detect() invoked imgfile = " << imgfile << std::endl;

    int found_faces_as_if_found = 1;

	std::vector<Json> vjsonfaces;
	for (int i = 0; i < found_faces_as_if_found ; ++i)
	{
		vjsonfaces.push_back(Json::object {
			{ "coordinates", Json::object {
					{"x", 100},
					{"y", 100},
					{"width", 50},
					{"angle", 0},
				}
//			{"confidence", l.confidence}
			}
		});
	}


#define BUFF_SIZE 256
	char buff[BUFF_SIZE];
	std::memset(buff, 0, BUFF_SIZE);


	std::ifstream imgstream (imgfile, std::istream::binary);

	std::vector<std::string> vfirfiles;
	if (!tmpfolder.empty())
	{
		for (int i = 0; i < found_faces_as_if_found; ++i)
		{
			std::string vidfname = std::to_string(vfirfiles.size()) + ".fir";

			imgstream.read(buff, BUFF_SIZE);


			std::ofstream vidstream(tmpfolder + "/" + vidfname, std::ostream::binary);
			vidstream.write(buff, BUFF_SIZE);


			vfirfiles.push_back(vidfname);
		}
	}

	//std::cout << "CFaceMachine::Detect() finished, firbuff size=" << m_firbuff.size() << std::endl;

	Json jsonresult = Json::object 	{
		{"faces", vjsonfaces},
		{"firs", Json(vfirfiles)},
	//	{"processing-time", Json(tmeasure.marksecs2str() + " seconds")}
	};

	std::string stresult = jsonresult.dump();
	
	std::cout << "CFaceMachine::Detect() finished, stresult=" << stresult << std::endl;
	
	return stresult;		
		
}




std::string testfacemachine(
	const std::string& cfgfile, 
	const std::string& imgfile, 
	const std::string& tmpfolder
	)
{

	std::cout << "testfacemachine cfgfile = '" << cfgfile << "', imgfile = '" << imgfile << "', tmpfolder = '" << tmpfolder << "'" << std::endl;

	try{

	std::cout << "create FM cfgfile = '" << cfgfile << std::endl;
	std::shared_ptr<CFaceMachine> FM = std::make_shared<CFaceMachine>(cfgfile);
	
	std::cout << "detect imgfile = '" << imgfile << std::endl;
	
	std::string res = FM->Detect( imgfile, tmpfolder);

	std::cout << "result : '" << res << std::endl;
	
	return res;
	
	}catch(...){
		return "bad result";
	}
	
	
	
}

int testInitProcessint(int v1, int v2)
{
	return v1 + v2;
}
