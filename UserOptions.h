#ifndef _H_USEROPTIONS_H_
#define _H_USEROPTIONS_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class UserOptions{
	public:
		UserOptions(string FirstDirectory,string OptionFilename){
			AddProjectDirectories(FirstDirectory);
			OptionFileWrite.open(OptionFilename, ios::in | ios::out );
			OptionFileRead.open(OptionFilename, ios::in | ios::out);
			cout << ProjectDirectories[0] << endl;
		}
		UserOptions(string OptionFilename){
			OptionFileWrite.open(OptionFilename, ios::in | ios::out );
			OptionFileRead.open(OptionFilename, ios::in | ios::out);
			ReadOptionFile(ProjectDirectories);
			ReadOptionFile(IgnoredDirectories);
		}
		~UserOptions(){
			WriteOptionFile(ProjectDirectories);
			WriteOptionFile(IgnoredDirectories);
			OptionFileWrite.close();
			OptionFileRead.close();
		}
		bool AddProjectDirectories(string Directory);
		bool RemoveProjectDirectories(unsigned index);
		bool ReplaceProjectDirectories(vector<string> Directories);
		vector<string> GetProjectDirectories();
		vector<string> GetIgnoredDirectories();
		bool AddIgnoredDirectories(string Directory);
		bool RemoveIgnoredDirectories(unsigned index);
		bool DeleteIgnoredDirectories();
	private:
		bool ReadOptionFile(vector<string> &listOfStrings);
		bool WriteOptionFile(vector<string> &listOfStrings);
		fstream OptionFileWrite;
		fstream OptionFileRead;
		vector<string> ProjectDirectories;
		vector<string> IgnoredDirectories;
};
#endif //_H_USEROPTIONS_H_