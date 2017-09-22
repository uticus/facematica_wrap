
#include <iostream>
#include <string>
#include <facemachine.h>
#include <matchmachine.h>
#include <sexmachine.h>

int main()
{
	//int init = InitLibraries();

	std::string FACESDK_CFG = "nothing here";
	std::string tmpfolder = "../tmp";

    std::string check;

	check = testfacemachine( FACESDK_CFG, "../P/47.jpg", tmpfolder );
	if( check.compare("bad result") == 0 ){
		std::cout << "test failed" << std::endl;
		return 0;
	}


	check = testsexmachine( FACESDK_CFG, "../P/47.jpg", "{\"angle\": 0, \"width\": 50, \"x\": 100, \"y\": 100}" );
	if( check.compare("") == 0 ){
		std::cout << "test failed" << std::endl;
		return 0;
	}


	float res = testmatchmachine( FACESDK_CFG, tmpfolder + "/0.fir", tmpfolder + "/0.fir" );
	if( res < 99 ){
		std::cout << "test failed" << std::endl;
		return 0;
	}

	std::cout << "test passed" << std::endl;
	return 0;

}
