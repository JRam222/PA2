#include <iostream>
#include <string>
#include <sys/dir.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "version.cpp"

using namespace std;
void exploreDirectory(char* in); //method to explore the directory given
int getFilesize(string filename);//method to retrieve file size in bytes
int dirCount =0; //counters
int fileCount =0;
int byteCount =0;
//add comment
int main(int argc, char** input){
	double version = 1.2;
	displayVersion(version);
	exploreDirectory(input[1]);
}

void exploreDirectory(char* in){
	char* path = in;
	DIR *dir;
	struct dirent *ent;
	struct stat st;
	//if directory exists and there is a next item in the directory
	if((dir = opendir (path)) != NULL){
		while((ent = readdir (dir)) !=NULL){
			//if directory item is another directory, then increment directory counter
			if(ent->d_type == DT_DIR){
				dirCount++;
			}else if(ent->d_type == DT_REG){ //if directory item is a file, then increment file directory
				fileCount++;
				string file(ent->d_name);	 // convert file name to string
				string path(in);		 // convert path to directory 
				string filePath = path + file;   // concatenate strings together
				byteCount += getFilesize(filePath);	//calculate byte file size and add it to counter
			}
		}
		closedir (dir);
		// print out results
		cout <<"The total number of directories in directory "<< in << " is: " <<dirCount<< "\n";
		cout <<"The total number of files in directory "<< in <<" is: " << fileCount<< "\n";
		cout <<"The total number of bytes occupied by all files in directory "<<in<< " is: "<< byteCount<< "\n";
	}
}

int getFilesize(string filename){
	FILE *p_file = NULL;
	p_file = fopen(filename.c_str(),"rb");
	fseek(p_file,0,SEEK_END);
	int size = ftell(p_file);
	fclose(p_file);
	return size; // return size of file
}
