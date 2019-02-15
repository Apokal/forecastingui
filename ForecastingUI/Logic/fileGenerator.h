#pragma once
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;
void fileGenerator(string Path, vector<float> Vector) {
    ofstream generatedFile;
    generatedFile.open(Path);
    ostream_iterator<float> output_iterator_generated(generatedFile, "\n");
    copy(Vector.begin(), Vector.end(), output_iterator_generated);
    generatedFile.close();
}
