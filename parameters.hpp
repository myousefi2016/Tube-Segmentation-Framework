#ifndef PARAMETERS_HPP_
#define PARAMETERS_HPP_

#include <string>
#include <vector>
#ifdef CPP11
#include <unordered_map>
#include <tuple>
using std::unordered_map;
using std::tuple;
#else
#include <boost/unordered_map.hpp>
#include <boost/tuple/tuple.hpp>
using boost::unordered_map;
using boost::tuple;
#endif

typedef struct asd {
	unordered_map<BoolParameter> bools;
	unordered_map<NumericParameter> numerics;
	unordered_map<StringParameter> strings;
} paramList;

paramList initParameters();
paramList getParameters(int argc, char ** argv);
float getParam(paramList parameters, std::string parameterName);
bool getParamBool(paramList parameters, std::string parameterName);
std::string getParamStr(paramList parameters, std::string parameterName);

class BoolParameter {
public:
	BoolParameter(bool defaultValue);
	bool get();
	void set(bool value);
private:
	bool value;
};

class NumericParameter {
public:
	NumericParameter(float defaultValue, float min, float max, float step);
	float get();
	void set(float value);
	bool validate(float value);
private:
	float value;
	float min;
	float max;
	float step;
};

class StringParameter {
public:
	StringParameter(std::string defaultValue, std::vector<std::string> possibilities);
	std::string get();
	void set(std::string value);
	bool validate(std::string value);
private:
	std::string value;
	std::vector<std::string> possibilities;
};

#endif /* PARAMETERS_HPP_ */