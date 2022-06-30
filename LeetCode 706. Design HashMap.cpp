class MyHashMap {
public:
    vector<int> m;
    int size;
    MyHashMap() {
        size=1e6+1;
        m.resize(size);
        fill(m.begin(),m.end(),-1);
    }
    
    void put(int key, int value) {
        m[key]=value;
    }
    
    int get(int key) {
        return m[key];
    }
    
    void remove(int key) {
        m[key]=-1;
    }
};
