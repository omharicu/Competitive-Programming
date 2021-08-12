int n = myRand(2, 20);
n=5;
cout<<n<<el;
vector<pair<int,int>> edges;
for(int i = 2; i <= n; ++i) {
    edges.emplace_back(myRand(1, i - 1), i);
}

vector<int> perm(n + 1); // re-naming vertices
for(int i = 1; i <= n; ++i) {
    perm[i] = i;
}
random_shuffle(perm.begin() + 1, perm.end());

random_shuffle(edges.begin(), edges.end()); // random order of edges

for(pair<int, int> edge : edges) {
    int a = edge.first, b = edge.second;
    if(myRand(0, 1)) {
        swap(a, b); // random order of two vertices
    }
    cout<<perm[a]<<" "<<perm[b]<<el;
}
