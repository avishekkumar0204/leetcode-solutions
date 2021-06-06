// https://leetcode.com/problems/lru-cache/
class doublyLinkedList
{
public:
    int key, value;
    doublyLinkedList *prev, *next;
    doublyLinkedList(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};
class LRUCache
{
    int cap, length;
    doublyLinkedList *cache = NULL, *tail = NULL;
    map<int, pair<int, doublyLinkedList *>> mp;

public:
    LRUCache(int capacity)
    {
        this->cap = capacity;
        this->length = 0;
    }
    void moveToBack(doublyLinkedList *temp)
    {
        doublyLinkedList *temp1 = temp;
        if (temp1->next != NULL)
        {
            if (temp1->prev != NULL)
                temp1->prev->next = temp1->next;
            else
            {
                cache = cache->next;
            }
            temp1->next->prev = temp1->prev;
            temp1->next = NULL;
            tail->next = temp1;
            temp1->prev = tail;
            tail = temp1;
        }
        return;
    }
    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            doublyLinkedList *temp = mp[key].second;
            moveToBack(temp);
            return mp[key].first;
        }
        else
            return -1;
    }
    void insert(doublyLinkedList *temp, int key, int value)
    {
        if (tail == NULL)
        {
            cache = tail = temp;
            mp[key].first = value;
            mp[key].second = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            mp[key].first = value;
            mp[key].second = temp;
        }
    }
    void deleteFromFront()
    {
        doublyLinkedList *temp1 = cache;
        cache = cache->next;

        if (cache == NULL)
            tail = NULL;
        else
            cache->prev = NULL;
        int key1 = temp1->key;
        mp.erase(key1);
        delete temp1;
    }
    void put(int key, int value)
    {
        // Already present
        if (mp.find(key) != mp.end())
        {
            mp[key].first = value;
            moveToBack(mp[key].second);
        }
        else
        {
            doublyLinkedList *temp = new doublyLinkedList(key, value);
            if (length < cap)
            {
                insert(temp, key, value);
                length++;
            }
            else
            {
                deleteFromFront();
                insert(temp, key, value);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */