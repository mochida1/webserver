
#include "Configs.hpp"

Configs::Configs(void) {
	return ;
}

Configs::~Configs()
{
	return ;
}

Configs::Configs(int argc, char *argv[], char **envp) {
	ConfigsLoader loader(argc, argv, envp);
	this->_dto = loader.getConfigs();
	ConfigsParser::parseConfigs(this->_dto);

}

static DTO_Configs _recGetContextByName (std::vector<DTO_Configs> & contextVector, std::string pName) {
	for (std::vector<DTO_Configs>::iterator it = contextVector.begin(); it != contextVector.end(); it++){
		if (it->name.find(pName)){
			return *it;
		}
		return *it;
	}
	return *contextVector.end();
}

DTO_Configs Configs::getContextByName(std::string pName) {
	// if context is main
	if (pName == this->_dto.name){
		return this->_dto;
	}
	return _recGetContextByName(this->_dto.context, pName);
}

static std::string _tabulateLevels(int level){
	std::string ret = "";
	for (int i = 0; i < level; i++){
		ret.append("\t");
	}
	return ret;
}

/*
	MOCHIDA ---- daqui para baixo mudar cerr para cout
*/

static void _printContextName(DTO_Configs context, int level){
	std::cerr << _tabulateLevels(level) << context.name << std::endl;
}

static void _printContextProps(DTO_Configs context, int level){
	std::multimap< std::string, std::vector<std::string> >::iterator prop;
	for (prop = context.property.begin(); prop != context.property.end(); prop++){
		std::cerr << _tabulateLevels(level) << "[" << prop->first << "] { ";
		for (size_t i = 0; i < prop->second.size(); i++){
			std::cerr << prop->second[i] << " ";
		}
		std::cerr << "}" << std::endl;
	}
}

static void _recPrintDTO(std::vector<DTO_Configs> contextVector, int level){
	for (std::vector<DTO_Configs>::iterator it = contextVector.begin(); it != contextVector.end(); it++){
		_printContextName(*it, level);
		_printContextProps(*it, level);
		_recPrintDTO(it->context, level + 1);
	}
}

// always call level as 0
void Configs::printDTO(void){
	int level = 0;
	_printContextName(this->_dto, level);
	_printContextProps(this->_dto, level);
	std::cerr << "LVL0 context size: " << this->_dto.context.size() << std::endl;
	_recPrintDTO(this->_dto.context, level + 1);
}


// ConfigsTest::ConfigsTest(void) {
// 	return ;
// }
ConfigsTest::~ConfigsTest(void){
	return ;
}