





class CFaceMachine 
{
public:
	CFaceMachine( const std::string& cfgfile);
    std::string Detect(const std::string& imgfile, const std::string& tmpfolder);
    

};


std::string testfacemachine(
	const std::string& cfgfile, 
	const std::string& imgfile, 
	const std::string& tmpfolder
	);

