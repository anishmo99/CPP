class MyHashSet
{
public:
    /** Initialize your data structure here. */
    vector<bool> myhash;
    MyHashSet()
    {
        myhash = vector(1000000, false);
    }

    void add(int key)
    {
        myhash[key] = true;
    }

    void remove(int key)
    {
        myhash[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return myhash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */