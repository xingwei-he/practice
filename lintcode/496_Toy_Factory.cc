/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:496_Toy_Factory.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/29 10:18:57 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Factory is a design pattern in common usage. Please implement a ToyFactory which can generate proper toy based on the given type.
 *
 * Example
 * ToyFactory tf = ToyFactory();
 * Toy toy = tf.getToy('Dog');
 * toy.talk(); 
 * >> Wow
 * toy = tf.getToy('Cat');
 * toy.talk();
 * >> Meow
 */

/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
class Toy {
public:
  virtual void talk() const=0;
  virtual ~Toy() {}
};

class Dog: public Toy {
  void talk() const {
    cout << "Wow" << endl;
  }
};

class Cat: public Toy {
  void talk () const {
    cout << "Meow" << endl;
  }
};

class ToyFactory {
public:
  /**
   * @param type a string
   * @return Get object of the type
   */
  Toy* toy;

  ToyFactory() {}
  ~ToyFactory() {
    if (nullptr != toy) {
      delete toy;
    }
  }

  Toy* getToy(string& type) {
    if (type.compare("Cat") == 0) {
      toy = new Cat();
    } else if (type.compare("Dog") == 0) {
      toy = new Dog();
    }
    return toy;
  }
};

int main() {
  string type = "Cat";
  ToyFactory* tf = new ToyFactory();
  Toy* toy = tf->getToy(type);
  toy->talk();
  return 0;
}

