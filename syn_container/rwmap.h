//
// Created by Administrator on 2019/9/26.
//

#ifndef RWLOCK_RWMAP_H
#define RWLOCK_RWMAP_H

#include <shared_mutex>
#include <map>

template  <typename  K,typename V>
class RwLockMap{
private:
    std::map<std::string,int> kvMap;
private:
    std::shared_timed_mutex  mtx;
public:
    RwLockMap();
    bool isExist(K &k);
    void insert(K &k,V v);
    void remove(K &k);
    unsigned long long  size();
};

template  <typename  K,typename V>
RwLockMap<K,V>::RwLockMap() {
}

template  <typename  K,typename V>
void RwLockMap<K,V>::insert(K &k, V v) {
    std::lock_guard<std::shared_timed_mutex> writerLock(mtx);
    kvMap[k]= v;
}

template  <typename  K,typename V>
unsigned long long  RwLockMap<K,V>::size() {
    std::shared_lock<std::shared_timed_mutex> readerLock(mtx);
    return this->kvMap.size();
}

template  <typename  K,typename V>
void RwLockMap<K,V>::remove(K& k) {
    std::lock_guard<std::shared_timed_mutex> writerLock(mtx);
    typename std::map<K,V>::iterator iter = this->kvMap.find(k);
    if(iter != this->kvMap.end()){
        this->kvMap.erase(iter);
    }
}

template  <typename  K,typename V>
bool RwLockMap<K,V>::isExist(K &k) {
    std::shared_lock<std::shared_timed_mutex> readerLock(mtx);
    typename std::map<K,V>::iterator iter = this->kvMap.find(k);
    return (iter != this->kvMap.end());
}
#endif //RWLOCK_RWMAP_H

/*
std::cout << "\nThe new  book" << std::endl;
for (auto teleIt: m.teleBook){
std::cout << teleIt.first << ": " << teleIt.second << std::endl;
}*/
