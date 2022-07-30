#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value = 0;
   int key = 0;

   //make sure that the initialisers are set in the same order as the declarations (-Wreorder)
   Node(Node* p, Node* n, int k, int val):next(n),prev(p),value(val),key(k){};
   Node(int k, int val):next(NULL),prev(NULL),value(val),key(k){};
};

class Cache{
protected:
	map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function
   virtual ~Cache(){};
};

class LRUCache : public Cache
{

public:
    LRUCache(int cp)
    {
        this->cp = cp;
    };


    void set(int key, int value)
    {
        //if the map is empty...
        if(mp.size() == 0){
            head = new Node(key, value);
            tail = head;
            mp[key] = head;
        //if the map is not empty...
        } else {
            //if the key doesn't exist...
            if(!mp.count(key)){
                head->prev = new Node(NULL, head, key, value);
                head = head->prev;

                mp[key] = head;

                //if we reached the limit...
                if(mp.size() == (unsigned) cp){
                    mp.erase(tail->key);

                    tail = tail->prev;

                    delete tail->next;

                    tail->next = NULL;
                }

            //if the key exists...
            } else {
                //we update the value...
                mp[key]->value = value;

                //if the key is not at the head...
                if(head != mp[key]){
                    //if it's at the tail...
                    if(tail == mp[key]){
                        tail = tail->prev;
                        tail->next = NULL;
                    }

                    head->prev = mp[key];
                    mp[key]->next = head;
                    head = mp[key];
                    head->prev = NULL;
                }
            }
        }
    };

    int get(int key){

        if(!mp.count(key)){
            return -1;
        }

        //if the key is at the head...
        if(head != mp[key]){
            //if it's at the tail...
            if(tail == mp[key]){
                tail = tail->prev;
                tail->next = NULL;
            }

            head->prev = mp[key];
            mp[key]->next = head;
            head = mp[key];
            head->prev = NULL;
        }

        return head->value;
    }

    ~LRUCache() {
        //for(const auto &[key, node]: mp){

        //for (auto iter = mp.begin(); iter != mp.end(); ++iter){
        /*
        for(auto n: mp){}

            mp.erase(n.first);
            // delete iter->second;
        }
        */
    }
};


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

