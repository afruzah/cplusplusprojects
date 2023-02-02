#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Edge {
	int w, u, v;
	
}
edges[126000];

int parent[600];
int n, sc = 0;

bool smallerEdge(Edge one, Edge two) {
	//function returns true or false depending on which one weighs less
	return one.w < two.w;
}

int search(int num) {
	//function checks to see if value can be found when indexed as the element in the parent array, if not the function is recursively called using the parent array with the previous parameter as the new parameter
	if (num != parent[num]) {
		num = search(parent[num]);
	}
	return num;
}

int shortestPathKruskal() {
	int shortestPath = 0;
	
	//n is the variable initialised to hold the number of cities given by input, this for loop sets each element of the parent array to correlate to the city collected by input in order
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	//sorts edges using function that finds smaller edge
    sort(edges, edges + sc, smallerEdge);
	
    for(int i = 0; i < sc; i++) {
        int u1 = search(edges[i].u);
        int v1 = search(edges[i].v);
        if(u1 != v1) {
            parent[u1] = v1;
            shortestPath += edges[i].w;
        }
    }
    return shortestPath;
}

int* ASCII(int array[], int len) {
	//checks input which may be 0,1 or A-Z or a-z, input is being read as ASCII characters therefore numbers need to be manipulated so that they refer to the actual number value, ASCII '0' and '1' should represent 0 and 1 respectively. A-Z should represent {0...25} and a-z should represent {26...51}
    for (int i = 0; i < len; i++) {
		//checks input for ASCII character '0' and '1';
        if (array[i] == 48 || array[i] == 49) {
            array[i] = array[i] - 48;
		} else if (array[i] >= 65 && array[i] <= 90) {
			//checks input for ASCII characters A-Z and changes array element
            array[i] = array[i] - 65;
		} else if (array[i] >= 97 && array[i] <= 122) {
			//checks input for ASCII characters a-z and changes array element
            array[i] = array[i] - 71;
        }
    }
    return array;
}

int main() {
    string line;
    getline(cin, line);
    
	int countries = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] != ',' && line[i] != ' ') {
			countries++;
		} else {
			break;
		}
	}
	
	n = countries;

	line.erase(remove(line.begin(), line.end(),','), line.end());
    line.erase(remove(line.begin(), line.end(),' '), line.end());
    
	int len = line.length();
    int array[len];
    for (int i = 0; i < len; i++) {
        array[i] = line[i];
    }
	
    int * finalArray = ASCII(array, len);

    int element = 0;

    int country[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
			country[i][j] = finalArray[element];
            element++;
        }
    }
    
    int build[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            build[i][j] = finalArray[element];
            element++;
        }
    }

    int destroy[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            destroy[i][j] = finalArray[element];
            element++;
        }
    }

    int cost[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (country[i][j] == 1) {
                cost[i][j] = -destroy[i][j];
            } else {
                cost[i][j] = build[i][j];
            }
        }
    }
    
    int cost1 = 0;
    for(int i = 1; i < n; i++) {
        for(int j=0;j<i;j++) {
            if (country[i][j] == 1) {
                cost1 = cost1 -(destroy[i][j]);
            }
        }
    }
	

    sc = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++, sc++) {
            edges[sc].u = i;
            edges[sc].v = j;
            edges[sc].w = cost[i][j];
        }
    }
	
    cout << shortestPathKruskal() - cost1 << endl;
}


