#include "Input_and_Output.h"

void getInput(Graph& G, char** files_name, int& u, int& v)
{
    ifstream f;
    f.open(files_name[1]);
    checkFilesOpen(f);

    int n, m;
    f >> n;
    checkifInt(n, files_name[2], f);
    G.MakeEmptyGraph(n);

    f >> m;
    checkifInt(m, files_name[2], f);

    int from, to, wight;
    for (int i = 0; i < m; i++)
    {
        f >> from >> to >> wight; // sets EOF flag if no value found

        checkEdgeInput(from, to, wight, n, files_name[2], f);
        G.AddEdge(from, to, wight);
    }

    checkConectedGraph(G, files_name[2]);

    f >> u >> v;
    checkEdgeInput(u, v, 0, n, files_name[2], f);

    f.close();
}

void checkFilesOpen(ifstream& f)
{
    if (!f)
    {
        cout << "Error: file could not be opened" << endl;
        exit(1);
    }
}
void checkInRange(int v, int n, char* output, ifstream& f)
{
    if (v < 1 || v > n)
    {
        invalidOutputMessage(output, "Invalid input!!");
        f.close();
        exit(1);
    }
}
void checkifInt(int v, char* output, ifstream& f)
{
    string s = to_string(v);

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]) == false)
        {
            invalidOutputMessage(output, "Invalid input!!");
            f.close();
            exit(1);
        }
    }
}
void checkEdgeInput(int u, int v, int w, int n, char* output, ifstream& f)
{
    checkifInt(u, output, f);
    checkInRange(u, n, output, f);

    checkifInt(v, output, f);
    checkInRange(v, n, output, f);

    checkifInt(w, output, f);
}
void checkConectedGraph(Graph& G, char* output)
{
    if (G.IsNotConectedGraph())
    {
        wightsOutputMessage(output, "No MST", "No MST", "No MST");
        exit(1);
    }
}

void invalidOutputMessage(char* fileName, const string message)
{
    cout << message << endl;

    ofstream outputFile;
    outputFile.open(fileName);

    if (!outputFile)
        cout << "Error: output file could not be opened";
    else
    {
        outputFile << message;
        outputFile.close();
    }
}
void wightsOutputMessage(char* fileName, string K1, string P, string K2)
{
    cout << "Kruskal  <" << K1 << ">" << endl;
    cout << "Prim     <" << P << ">" << endl;
    cout << "Kruskal2 <" << K2 << ">" << endl;

    ofstream outputFile;
    outputFile.open(fileName);
    if (!outputFile)
        cout << "Error: output file could not be opened";
    else
    {
        outputFile << "Kruskal  <" << K1 << ">" << endl;
        outputFile << "Prim      <" << P << ">" << endl;
        outputFile << "Kruskal2 <" << K2 << ">" << endl;
        outputFile.close();
    }
}