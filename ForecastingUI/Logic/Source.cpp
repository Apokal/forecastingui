//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <fstream>
//#include <iterator>
//#include <functional>
//#include <map>
//#include <string>
//#include "RunEntry.h"
//#include "vectorGenerator.h"
//#include "fileGenerator.h"
//#include "SMA.h"
//#include "WMA.h"
//#include "ES.h"
//#include "NAIVE.h"
//#include "LTP.h"

//typedef std::chrono::high_resolution_clock Clock;
//using namespace std;

//int main() {
//// init
//	srand(time(NULL));
//	vector<float> initVector = vectorGenerator(100000);
//	fileGenerator("C:\\Users\\SP\\ForeCode\\SMA\\SMAProject\\Pliki\\initVector.txt", initVector);
////

//// function mapper
//	std::map<std::string, std::function<vector<float>(vector<float>)>> forecastMap =
//	{
//		{ "SMA", SMA},
//		{ "WMA", WMA},
//		{ "ES", ES},
//		{ "NAIVE", NAIVE},
//		{ "LTP", LTP}
//	};
////

//// calculation
//	RunEntry(initVector, forecastMap, "SMA");
//	RunEntry(initVector, forecastMap, "WMA");
//	RunEntry(initVector, forecastMap, "ES");
//	RunEntry(initVector, forecastMap, "NAIVE");
//	RunEntry(initVector, forecastMap, "LTP");
////

//	cin.get();
//	cin.get();
//	return 0;
	
//}
