#include"UserOptions.h"
bool UserOptions::AddProjectDirectories(string Directory){
	ProjectDirectories.push_back(Directory);
	return true;
}
vector<string> UserOptions::GetProjectDirectories(){
	return ProjectDirectories;
}
bool UserOptions::ReplaceProjectDirectories(vector<string> Directories){
	ProjectDirectories = Directories;
	return true;
}
bool UserOptions::RemoveProjectDirectories(unsigned index){
	ProjectDirectories.erase(ProjectDirectories.begin()+index);
	return true;
}
bool UserOptions::AddIgnoredDirectories(string Directory){
	IgnoredDirectories.push_back(Directory);
	return true;
}
vector<string> UserOptions::GetIgnoredDirectories(){
	return IgnoredDirectories;
}
bool UserOptions::RemoveIgnoredDirectories(unsigned index){
	IgnoredDirectories.erase(IgnoredDirectories.begin()+index);
	return true;
}
bool UserOptions::DeleteIgnoredDirectories(){
	IgnoredDirectories.clear();
	return true;
}
bool UserOptions::ReadOptionFile(vector<string> &listOfStrings){//compile Test Do
	string Data;
	getline(OptionFileRead, Data, ';');
	for (bool a=false;!a;){
		size_t CommaIndex = Data.find(',');
		size_t NextCommaIndex = Data.find(',', CommaIndex + 1);
		if(NextCommaIndex!=string::npos){
			string Temp = Data.substr(CommaIndex, NextCommaIndex - CommaIndex);
			cout << Temp << endl;
			listOfStrings.push_back(Temp);
		}
		else{
			a=true;
		}
	}
	return true;
}
bool UserOptions::WriteOptionFile(vector<string> &listOfStrings){
	if (listOfStrings.size() != 0){
		for (unsigned i = 0; i < listOfStrings.size(); i++){
			cout << i << endl;
			string Data = "";
			if (!OptionFileRead.eof()){
				getline(OptionFileRead, Data, ',');
			}
			if (listOfStrings.size() != i){
				if (listOfStrings[i] != Data){
					cout << listOfStrings[i] << endl;
					OptionFileWrite << ',' << listOfStrings[i];
					if (listOfStrings.size()==1)OptionFileWrite << ';';
				}
			}
			else{
				if (listOfStrings[i] != Data){
					OptionFileWrite << listOfStrings[i] << ';';
				}
			}
		}
		return true;
	}
	else{
		return false;
	}
}
