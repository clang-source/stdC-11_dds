// readerWriterLock.cpp

#include <iostream>
#include <map>
#include <string>
#include "rwmap.h"
#include <thread>
#include <queue>


RwLockMap<std::string,int> m;

void printNumber(std::string msg){
   //  m.printNumber(msg);
}

void addToTeleBook(std::string msg,int num){
     m.insert(msg,num);
}

void init(){

    std::string k1 ="Dijkstra";
    m.insert(k1,1972);
    std::string k2 ="Scott";
    m.insert(k2,1976);
    std::string k3 ="Ritchie";
    m.insert(k3,1983);
}


void readSize(){

    std::cout << " ... readSize:" << m.size() << std::endl;
}
static void testmap(){
    init();
    std::thread reader1([]{
        printNumber("Scott");
    });
    std::thread reader2([]{ printNumber("Ritchie"); });
    std::thread w1([]{ addToTeleBook("Scott",1968); });
    std::thread reader3([]{ printNumber("Dijkstra"); });
    std::thread reader4([]{ printNumber("Scott"); });
    std::thread w2([]{ addToTeleBook("Bjarne",1965); });
    std::thread reader5([]{ printNumber("Scott"); });
    std::thread reader6([]{ printNumber("Ritchie"); });
    std::thread reader7([]{ printNumber("Scott"); });
    std::thread reader8([]{ printNumber("Bjarne"); });

    std::thread reader9([]{ readSize(); });

    reader1.join();
    reader2.join();
    reader3.join();
    reader4.join();
    reader5.join();
    reader6.join();
    reader7.join();
    reader8.join();
    w1.join();
    w2.join();
}



int main(){






/*  std::cout << "\nThe new telephone book" << std::endl;
  for (auto teleIt: m.teleBook){
    std::cout << teleIt.first << ": " << teleIt.second << std::endl;
  }*/

}
