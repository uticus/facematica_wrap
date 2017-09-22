#pragma once



class CSexMachine 
{
public:
	CSexMachine(const std::string & cfgpath);
	~CSexMachine();

	std::string Analyze(const std::string & imgfile, const std::string & faceMetaJSON);


private:
	CSexMachine(const CSexMachine & ) = delete;
	CSexMachine & operator=(const CSexMachine & ) = delete;
};

std::string testsexmachine(
	const std::string& cfgfile, 
	const std::string& imgfile,
	const std::string& faceMetaJSON
	);
