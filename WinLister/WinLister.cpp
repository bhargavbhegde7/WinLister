#include "stdafx.h"
#include "dirent.h"
#include <string>
#include <vector>
#include <iostream>
#include <direct.h>
#include <windows.h>

using namespace std;

vector<string> getFiles(const char* path) {
	vector<string> files;

	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(path)) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			files.push_back(ent->d_name);
		}
		closedir(dir);
		return files;
	}
	else {
		perror("could not open directory");
	}
}

char* getPwd() {

	char* buffer;

	if ((buffer = _getcwd(NULL, 0)) == NULL)
		perror("\n _getcwd error : possibly the path is too long \n");
	else {
		//free(buffer);
		return buffer;
	}
}

void printFiles(vector<string> files) {
	vector<string>::iterator v = files.begin();
	cout << endl;
	while (v != files.end()) {
		cout << *v << endl;
		v++;
	}
}

int main()
{
	printFiles(getFiles(getPwd()));
	return 0;
}