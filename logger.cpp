#define _CRT_SECURE_NO_WARNINGS // For Windows-Users (ctime gets warnings) - all other can delete or ignore this line
#include <ctime>
#include <iostream>

#include "logger.hpp"
#include "policy.hpp"
#include "consolepolicy.hpp"

using namespace std;

/// \brief Helper function to get a time-string with second resolution.
static string getTimeString()
{
	string timeStr;
	time_t rawTime;
	time(&rawTime);
	timeStr = ctime(&rawTime);
	return timeStr.substr(0, timeStr.size() - 1);
}

void Logger::write(const string &file, long line, const string &message)
{
	//cout << getTimeString() << " [" << file << " : " << line << "] " << message << "\n";
	this->m_history += getTimeString() + " [" + file + " : " + to_string(line) + "] " + message + "\n";
	// for (size_t i = 0; i < 2; i++)
	// {
	// 	this->myPolicies[0]->get()->write("message");
	// }
}

void Logger::registerPolicy(std::unique_ptr<Policy> _policy)
{
	//*_policy = m_history + *_policy; //make_unique<string>(m_history);
	// auto sad = &_policy;
	// this->myPolicies[myNum] = sad;
	// myNum++;
	_policy->write(m_history);
}

//bearbeitet bei Abdelhalim Abdelhalim, Abdelrahman Abdelhalim, Hannan Mahadik, Moayad Okal