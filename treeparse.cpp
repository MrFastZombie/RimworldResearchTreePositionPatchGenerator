#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

int main ()
{
    int counter = 0;
    string line = "";
    string substr = "";
    string value = "";
    string current_def = "";
    regex re("[a-zA-Z<>\\/]*"); //This regex is used to clear the tags to extract the value.
    smatch match;
    ifstream input("input.txt");
    ofstream output("patch.xml", ofstream::trunc);
    
    output << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl << "<Patch>" << endl;
    
    while(getline(input, line)) {
        if (counter%4 == 0) { //Collect every 4th line + first line
            current_def = line;
            cout << "Def: " << current_def << endl;
        }
        if(line.find("<researchViewX>") != string::npos || line.find("<researchViewY>") != string::npos) { //Capture lines that contain research view tags.
            substr = line.substr(0, 16);
            substr.erase(0, substr.find_first_of('<')+1);
            cout << "	Substr: " << substr << endl;
            value = regex_replace(line, re, "");
            value.erase(0, 2);
            cout << "		Value: " << value << endl;

            output << "	<Operation Class=\"PatchOperationReplace\">" << endl;
            output << "		<xpath>Defs/ResearchProjectDef[defName=\"" << current_def << "\"]/" << substr << "</xpath>" << endl;
            output << "		<value>" << endl;
            output << "		    <" << substr << ">" << value << "</" << substr << ">" << endl;
            output << "		</value>" << endl;
            output << "	</Operation>" << endl;
        }
        counter++;
    }

    output << "</Patch>";
    input.close();
    output.close();
    return 0;
}