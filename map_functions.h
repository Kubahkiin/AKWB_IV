#ifndef AKWB4_MAP_FUNCTIONS_H
#define AKWB4_MAP_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

string instance = "test";

void load_vector(vector<int> &wektor){
    ifstream fh("instances/"+instance+".txt");
    string line;

    while (getline(fh, line))
    {
        istringstream row(line);
        int val;
        while (row >> val)
        {
            wektor.push_back(val);
        }
    }

    fh.close();
}

void display_vector(vector < int > &wektor){
    cout << "\n";
    for(int x: wektor)
        cout << x << " ";
}

int check_size(int a_size){
    double k = (-3 + sqrt(8*a_size + 1)) / 2;
    if (k == (int)k)
        return (int)k;
    else
        return 0;
}

bool find_element(int key, vector < int > v) {
    if (find(v.begin(), v.end(), key) != v.end())
        return true;
    else
        return false;
}

void delete_element(int key, vector < int > &v) {
    for(int pos = 0; pos < v.size(); pos++)
    {
        if (v[pos] == key) {
            v.erase(begin(v) + pos);
            break;
        }
    }
}

bool check_first_element(vector < int > &multi_a, vector < int > &not_used, vector < int > &restriction_map){
    int max = 0, nd_max = 0;
    for (int e: multi_a){
        if (e > max) {
            nd_max = max;
            max = e;
        }
    }
    //cout <<"\nMax: " << max << " 2nd_Max: " << nd_max;
    int first = max - nd_max;
    //cout << "\n" << first;
    restriction_map.push_back(first);


    delete_element(first, not_used);
    delete_element(nd_max, not_used);

    return find_element(first, multi_a);
}



void seek(vector < int > &multi_a, vector < int > &not_used, vector <int> &restriction_map, int maxInd, int *found) {
    if (restriction_map.size() == maxInd) {
        display_vector(restriction_map);
        *found = 1;
    }
    else for (int frag: not_used){
        cout << "\t" << frag;

        if (*found==1)
            break;
        }

}

#endif //AKWB4_MAP_FUNCTIONS_H
