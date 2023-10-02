#ifndef AKWB4_MAP_FUNCTIONS_H
#define AKWB4_MAP_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

vector < int > find_maxes(vector < int > &multi_a){
    vector < int > maxes;
    int max = 0, nd_max = 0;
    for (int e: multi_a){
        if (e > max) {
            nd_max = max;
            max = e;
        }
    }
    maxes.push_back(max);
    maxes.push_back(nd_max);

    return maxes;
}

bool check_first_element(vector < int > &multi_a, vector < int > &not_used, vector < int > &restriction_map, int max, int nd_max){
    int first = max - nd_max;
    restriction_map.push_back(first);


    delete_element(first, not_used);
    delete_element(nd_max, not_used);

    return find_element(first, multi_a);
}

bool can_add_element(vector < int > &not_used, vector <int> &restriction_map, int max) {
    int checks = restriction_map.size() - 1;
    int frag = restriction_map[restriction_map.size() - 1];
    int sum = frag;
    for(int i = 0; i < checks; i++){
        sum += restriction_map[checks-1 - i];


        if(find_element(sum, not_used)){
            delete_element(sum, not_used);
            if (not_used.size() == 2){
                if (find_element(max-sum, not_used)){
                    restriction_map.push_back(max-sum);
                    return true;
                }
            }
        }
        else
            return false;


    }

    if(find_element(max-sum, not_used)){
        delete_element(max-sum, not_used);
        return true;
    }
    else
        return false;
}

void seek(vector < int > &not_used, vector <int> &restriction_map, int maxInd, int *found, int max) {
    bool ok;
    if (restriction_map.size() == maxInd + 1) {
        display_vector(restriction_map);
        *found = 1;
    }
    else for (int frag: not_used){
        vector < int > not_used_new;
        copy(not_used.begin(), not_used.end(), back_inserter(not_used_new));

        restriction_map.push_back(frag);
        delete_element(frag,not_used_new);

        ok = can_add_element(not_used_new, restriction_map, max);


        if(ok)
        {
            seek(not_used_new, restriction_map, maxInd, found, max);
        }

        restriction_map.pop_back();

        if (*found==1)
            break;

        }

}

#endif
