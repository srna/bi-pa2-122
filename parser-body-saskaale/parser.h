/*
    Program for parsing points for Tomas Srna
    coded by Saska Ales (mail@alessaska.cz)
*/

bool isValidName(char*);
void parseFile(std::string filename, std::map<std::string, int>& data);
int getdata(std::string dir, std::map<std::string, int>&data);
void dumpOut(std::ostream &os, std::map<std::string, int>& data);
int main(int argc, char* argv[]);
