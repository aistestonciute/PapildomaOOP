#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility> // pair
#include <set>


using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::stringstream;
using std::ofstream;
using std::vector;
using std::istringstream;
using std::transform;
using std::map;
using std::set;
using std::pair;
using std::remove_if;


void OpenFile(stringstream &buffer)
{   
    ifstream in;
    try{
        in.open("data.txt");
        if (!in) throw 1;
        buffer << in.rdbuf();
        in.close();
    }
    catch (int e)
    {
        cout << "Error! ";
        switch(e)
        {  
            case 1: 
                cout << "Input file not opened." << endl;
                break;
            default: 
                cout << "System failure." << endl;
                break;
        }
        exit(1);
    }
}

void InputData(stringstream &buffer, vector <string> &url, map <string, pair <set<int>, int>>& words)
{
    string line, word;
    int line_count = 0;
    while(getline(buffer, line))
    {
        line_count++;
        istringstream read;
        read.str(line);
        while (read >> word)
        {
            if(word.find("http://") != string::npos || word.find("https://") != string::npos ||  word.find("www.") != string::npos)
            {
                url.push_back(word);
            }

            else
            {
                word.erase(remove_if(word.begin(), word.end(), [](char c) {return !isalpha(c);}), word.end());
                if(!word.empty())
                {
                    transform(word.begin(), word.end(), word.begin(), ::tolower);
                    words[word].first.insert(line_count);
                    words[word].second++;
                }
            }

            read.clear();
        }
    }

}

void OutputData(vector <string> url, map <string, pair <set<int>, int>> words)
{   
    ofstream out ("results.txt");
    try{
    if (!out) throw 2;
    
    for(auto& word : words)
    {
        if (word.second.second > 1)
        {
            int i = 0;
            out << "Word: " << word.first << " | Count: " << word.second.second << "| Lines: ";
            
            for(auto line_number : word.second.first)out << line_number << " ";

            out << endl;
            
        }
    }

    out << endl << "URL's:" << endl;
    int size = url.size();
    for (int i = 0; i < size; i ++) out << url[i] << endl;
    out.close();
}
    catch (int e)
    {
        cout << "Error! ";
        switch(e)
        {  
            case 2: 
                cout << "Output file not opened." << endl;
                break;
            default: 
                cout << "System failure." << endl;
                break;
        }
        exit(1);
    }

}

int main(){
    
    vector <string> url;
    map<string, pair <set<int>, int>>words;
    
    stringstream buffer;
    OpenFile(buffer);
    InputData(buffer, url, words);
    OutputData(url, words);
   
}
