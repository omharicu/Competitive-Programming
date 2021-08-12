#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;
#define int long long
#define pb push_back
#define ll long long
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll A, ll B) {return uniform_int_distribution<ll>(A, B)(rng);}
int starting_idx = 1; // Test Case Gen starts from input01.txt
 
const string in = "input";
const string out = "output";
 
string get_filename() {
    if (starting_idx >= 10) {
        return in + to_string(starting_idx) + ".txt";
    } else {
        return in + "0" + to_string(starting_idx) + ".txt";
    }
}
void make_sample() {
 
}
void make_random() {
 
}
void make_edge() {
    
}
void make_stress() {
 
}
signed main()
{
    // Dont use Fast i/o
    srand(time(0));
    int stress_tests, random_tests, edge_tests, samples;
    cout << "Enter the number of samples : ";
    cin >> samples;
    cout << "Enter number of random tests : ";
    cin >> random_tests;
    cout << "Enter number of edge tests : ";
    cin >> edge_tests;
    cout << "Enter number of stress tests : ";
    cin >> stress_tests;
    assert(min({stress_tests, random_tests, edge_tests, samples}) >= 0);
     
    while (samples--) {
        freopen(get_filename().c_str(), "w", stdout);
        make_sample();
        ++starting_idx;
    }
    while (random_tests--) {
        freopen(get_filename().c_str(), "w", stdout);
        make_random();
        ++starting_idx;
    }
    while (edge_tests--) {
        freopen(get_filename().c_str(), "w", stdout);
        make_edge();
        ++starting_idx;
    }
    while (stress_tests--) {
        freopen(get_filename().c_str(), "w", stdout);
        make_stress();
        ++starting_idx;
    }
}
