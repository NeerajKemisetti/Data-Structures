vector<vector<int> > d;
int val;
for(int i = 0; i < in; i++){
    vector<int> temp;
    for(int j = 0; j < in; j++){
        cin >> val;
        temp.push_back(val);
    }
    d.push_back(temp);
    temp.clear();
}
