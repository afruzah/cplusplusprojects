#include <vector>
#include <iostream>
#include <string>
using namespace std;

class HashTable {
public:
	
    HashTable() { //create hash table
        for (int i = 0; i < 26; i++) {
			hashtable.push_back(""); //creates empty elements in hash table for all 26 letters
			tombstone.push_back(0); //sets tombstone value to 0 in vector size same length as hashtable
        }
    };
	
    int search(string find) { //search string value to see if exists within hash table
		int hkey = find[find.length()-1] - 97; //the hash key is the last letter of the string value which is where the string value should be put if it is not already used by another value
        if (hashtable[hkey] == find && tombstone[hkey] == 0) {
            return hkey;
        }
        else {
            int location = hkey + 1; //if not found at initial location where it is expected to be, function will iterate through the next values in the hashtable to see if value exists
            for(int j = 0; j < 26; j++) {
                location = location%26;
                
                if (hashtable[location] == find && tombstone[location] == 0) {
                    return location; //returns where value exists
                }
				else if (hashtable[location].empty() && tombstone[location] == 0) { //if an empty element that has never had deletions is encountered during this iteration, this indicates that the value is not in the hastable and the function will return -1;
                    return -1;
                }
                location++;
            }
            return 0;
        }
        return 0;
    };
	
    void deleteVal(string toDelete) { //deletes value in hash table
        int hkey = search(toDelete); //searches for value in hash table using previously defined function

        if (hkey == -1) { //if the search function returns -1, this means that the value is not in the hash table and does not need to be deleted
            return;
        }
        else {
            tombstone[hkey] = 1; //setting the tombstone value for corresponding hash table value inherently "kills" this entry and therefore when going through the hash table this value is now invalid
        }
        return;
	};
	
    void insert(string toInsert) {
        if (search(toInsert) != -1) { //checks if string value exists in hash table
            return;
        }

        int hkey = toInsert[toInsert.length()-1] - 97; //hash key is the int value of last letter in string
		
		
		if (hashtable[hkey] == "" || tombstone[hkey] == 1) { //if the entry point in the hash table is empty or the hash table is holding a dead value, function will add string value to hashtable and set tombstone value back to 0
            hashtable[hkey] = toInsert;
            tombstone[hkey] = 0;
        }
        else {
			int location = hkey + 1; //if the hash table is not empty at location of hash key, function will iterate through hash table to find an empty spot to put the value in
            for(int j = 0; j < 26; j++) {
                location = location%26;
                
                if (hashtable[location] == "" || tombstone[location] == 1) { //this is what happened before else statement, this step is repeated once an empty spot is found to put value in from function
                    hashtable[location] = toInsert;
                    tombstone[location] = 0;
                    return;
                }
                location++;
            }
        }
        return;
    };
	
    void printVal() {
		int sizeofhashtable = hashtable.size(); //creates an int value that represents number of elements in hashtable
		
        for (int i = 0; i < sizeofhashtable; i++) { //iterates through hash table elements and prints out all the values stored in the hash table
            if (hashtable[i] != "" && tombstone[i] == 0) {
				if (i == sizeofhashtable - 1) { //if function is printing out the last element it will add an end of line statement
					cout << hashtable[i] << " " << endl;
					break;
				}
                cout << hashtable[i] << " ";
            }
        }
    };
	
private:
	vector<int> tombstone; //initialise vector for tombstone values
	vector<string> hashtable; //initialise hashtable
};

int main() {
	vector<string> entries; //initialise vector to store values to be entered in hash table
	string line; //this variable will hold input from stdin

	getline(cin, line); //this reads in the input from stdin and stores in variable line
	int iter = -1;
	int whichEntry = 0;
	for (int i = 0; i < (int)line.length(); i++) {
		if (line[i] == ' ' || i == line.length()-1) {
			if (i == (int)line.length()-1) {
				i++;
			}
			entries.push_back("");

			for (int j = iter + 1; j < i; j++) {
				entries[whichEntry] += line[j];
			}
			iter = i;
			whichEntry++;
		}
	}

	HashTable hashtable;

	for (unsigned i = 0; i < (int)entries.size(); i++) {
		if (entries[i][0] == 'A') {
			entries[i].erase(entries[i].begin());
			hashtable.insert(entries[i]);
		}
		else if (entries[i][0] == 'D') {
			entries[i].erase(entries[i].begin());
			hashtable.deleteVal(entries[i]);
		}
	}
	
	hashtable.printVal();
	return 0;
}
