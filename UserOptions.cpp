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
bool UserOptions::ReadOptionFile(vector<string> &listOfStrings){
	string Data = "";
	getline(OptionFile, Data, ';');
	for (unsigned i = 0 ;i<Data.size(); i++){
		unsigned NextCommaIndex = Data.find(',',i+1);
		for (unsigned CommaIndex = Data.find(',', i);CommaIndex < NextCommaIndex; CommaIndex++){
			string Temp = "";
			Temp.push_back(Data[CommaIndex]);
			listOfStrings.push_back(Temp);
		}
	}
	return true;
}
bool UserOptions::WriteOptionFile(vector<string> &listOfStrings){
	for (unsigned i = 0; i < listOfStrings.size(); i++){
		cout << i << endl;
		string Data = "";
		if (!OptionFile.eof()){
			getline(OptionFile, Data, ',');
		}
		if (listOfStrings.size() != i ){
			if (listOfStrings[i] != Data){
				cout << listOfStrings[i] << endl;
				OptionFile << ',' << listOfStrings[i];
			}
		}
		else{
			if (listOfStrings[i] != Data){
				OptionFile << listOfStrings[i] << ';';
			}
		}
	}
	return true;
}