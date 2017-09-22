#pragma once



class CMatchMachine 
{
public:
	 CMatchMachine(const std::string & cfgpath);
	~CMatchMachine();

	//std::string Match(const std::string & firfile1, const std::string & firfile2);
	float MatchIndexFiles(const std::string & firfile1, const std::string & firfile2);


private:
	CMatchMachine(const CMatchMachine & ) = delete;
	CMatchMachine & operator=(const CMatchMachine & ) = delete;
};

float testmatchmachine(
	const std::string& cfgfile, 
	const std::string& firfile1, 
	const std::string& firfile2
	);
