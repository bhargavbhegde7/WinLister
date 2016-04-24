// WinLister.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dirent.h"
#include <string>
#include <vector>
#include<iostream>
#include <direct.h>
//#include <stdlib.h>
//#include <stdio.h>

using namespace std;

vector<string> dowalk(const char* path) {
	vector<string> files;

	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(path)) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			//printf("%s\n", ent->d_name);
			files.push_back(ent->d_name);
		}
		closedir(dir);
		return files;
	}
	else {
		/* could not open directory */
		perror("could not open directory");
		//return EXIT_FAILURE;
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

int main()
{
	vector<string> files = dowalk(getPwd());
	cout << files.size();
	int size = files.size();

	vector<string>::iterator v = files.begin();
	while (v != files.end()) {
		cout << endl << *v << endl;
		v++;
	}

	return 0;
}