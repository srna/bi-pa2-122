/*
    Program for parsing points for Tomas Srna
    coded by Saska Ales (mail@alessaska.cz)
*/

#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <limits>
#include <string.h>

#include "parser.h"

using namespace std;

char* EXTENSION;
char* OUTFILE;

//check if file end with EXTENSION
bool isValidName(char* name){
    if(strlen(name) < strlen(EXTENSION)){
	return false;
    }else{
	return strcmp(name+strlen(name)-strlen(EXTENSION), EXTENSION) == 0;
    }
}

void parseFile(string filename, map<string, int>& data){
    cout << "Processing file "<<filename<<endl;

    ifstream ifs(filename.c_str(), ifstream::in);
    int linenum = 0;
    while(!ifs.eof() && ++linenum){
	string name = "";
	int value;
	try{
	    ifs >> name;
	    if (ifs.fail())
		break;
	    ifs >> value;
	    if (ifs.fail())
		throw "Error loading bonuses";
	    if(data.find(name) != data.end())
		data[name]+=value;
	    else
		data[name]=value;
	}catch(const char * err){
	    cerr << "Error parsing file " << filename << " on line " << linenum << " (" << err << ")" << endl;
	    ifs.clear();
	    ifs.ignore(std::numeric_limits<streamsize>::max(),'\n');
	}
    }
    ifs.close();
}

int getdata(string dir, map<string, int>&data){
    DIR * dp;
    struct dirent *dirp;
    if((dp = opendir(dir.c_str())) == NULL){
	cerr << "Error opening " << dir << endl;
    }
    
    while((dirp = readdir(dp)) != NULL){
	switch(dirp->d_type){
	    case DT_REG:
		if(strlen(dirp->d_name) > 0 && dirp->d_name[0] != '.')
		    if(isValidName(dirp->d_name)){
			parseFile(dir+"/"+string(dirp->d_name), data);
		    }
		break;
	    case DT_DIR:
		if(strlen(dirp->d_name) > 0 && dirp->d_name[0] != '.'){
		    string newdir = dir;
		    newdir = newdir+"/"+string(dirp->d_name);
		    getdata(newdir, data);
		}
		break;
	}
    }
    closedir(dp);
    return 0;
}

void dumpOut(ostream &os, map<string, int>& data){
    map<string, int>::iterator it = static_cast<map<string, int>&>(data).begin();
    for(it=data.begin(); it != data.end(); it++)
	os << it->first << " " << (it->second>0?"+":"") << (it->second) << endl;
}


int main(int argc, char* argv[]){
    if(argc < 4){
	cerr << "Error, not enough arguments." << endl;
	cerr << "Usage: " << argv[0] << " dir input_files_suffix output_file" << endl;
    }else{

    EXTENSION = argv[2];
	OUTFILE = argv[3];

	map<string, int> data;
	getdata(argv[1], data);

	ofstream ofs(OUTFILE);
	dumpOut(ofs, data);
	ofs.close();
	
	cout << "Successfully generated to " << OUTFILE << endl;
    }
}
