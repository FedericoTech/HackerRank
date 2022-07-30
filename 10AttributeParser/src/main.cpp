
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

struct Node {

    string tag;

    Node *parent;

    map <string, Node *> children;
    map <string, string> attrs;

    Node(string tag, Node *parent) : tag(tag), parent{parent} {}
};

int main() {

	int q, n;

	Node *root = new Node("root", NULL);
	Node *current = root;

	cin >> n >> q;

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new

	while(n--){
		string line;
		getline(cin, line);

		line.erase(		//erase characters
			line.begin(),  	//from beginning
			find_if(
				line.begin(), line.end(), //from beginning to end
				not1(				//to the first non space
					ptr_fun<int, int>(isspace) //with the function isspace
				)
			)	//to the first non space
		);

		if(line.substr(0, 2) == "</"){
			current = current->parent;
			continue;
		}

		string token, tag, attr;
		map<string, string> attrs;

		stringstream ss(line);

		while(ss >> token){

			if(token[0] == '='){
				continue;
			}

			//remove closing angle
			if(token[token.length()-1]=='>'){
				token.pop_back();
			}

			//if token is a tag
			if(token[0] == '<'){
				tag = token.erase(0, 1); //remove the angle

			} else if(token[0] == '"') {
				attrs[attr] = token.erase(0, 1); //remoe the quote
				attrs[attr].pop_back();
			} else {
				attr = token;
			}
		}

		current = new Node(tag, current);
		current->attrs = attrs;

		current->parent->children[tag] = current;
	}

	while(q--){
		string line;
		getline(cin, line);
		stringstream ss(line);

		Node *l = root;

		string tag, attr, node;

		while(getline(ss, node, '.')){

			if(node.find('~', 0) != string::npos){
				int pos = node.find('~', 0);

				attr = node.substr(pos, node.length() - pos);
				attr.erase(0, 1);
				node = node.substr(0, pos);
			}

			if(!l->children.count(node)){
				cout << "Not Found!" << endl;
				break;
			}

			l = l->children[node];

			if(attr != ""){
				if(!l->attrs.count(attr)){
					cout << "Not Found!" << endl;
					break;
				}

				cout << l->attrs[attr] << endl;
				break;
			}
		}
	}

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
