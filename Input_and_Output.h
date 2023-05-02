#ifndef _VALID_H
#define _VALID_H

#include "Graph.h"
#include <fstream>

void getInput(Graph& G, char** files_name, int& u, int& v);

void checkFilesOpen(ifstream& f);

void checkInRange(int v, int n, char* output, ifstream& f);
void checkifInt(int v, char* output, ifstream& f);
void checkEdgeInput(int u, int v, int w, int n, char* output, ifstream& f);
void checkConectedGraph(Graph& G, char* output);

void invalidOutputMessage(char* fileName, const string message);
void wightsOutputMessage(char* fileName, string K1, string P, string K2);

#endif 
