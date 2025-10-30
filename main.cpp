// Diego A. Costoso Vázquez - 801199097
// CCOM 3034 - Data Structures
// Lab 08 - Breadth-first traversal of binary tree


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BinarySearchTree.hpp"
#include "doctest.h"
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

TEST_CASE("BinarySearchTree basic operations") {
  BinarySearchTree<int> B;
  B.insert(10);
  B.insert(4);
  B.insert(2);
  B.insert(15);
  B.insert(31);
  B.insert(1);
  B.insert(56);
  CHECK(B.toInorderStr() == "1,2,4,10,15,31,56");
  CHECK(B.BFT() == "[[10],[4,15],[2,31],[1,56]]");
  BinarySearchTree<int> C;
  for (auto e :
       {16, 8, 24, 28, 20, 12, 4, 2, 6, 10, 14, 18, 22, 26, 30, 15, 7, 3}) {
    C.insert(e);
  }

  CHECK(C.isEmpty() == false);
  CHECK(C.contains(10) == true);
  CHECK(C.findMax() == 30);
  CHECK(C.findMin() == 2);


  BinarySearchTree<int> D;
  for (auto v :
  {1, 3, 7, 21, 28, 36, 44, 56, 62, 74, 82, 86, 92, 100}){
    D.insert(v);
  }

  CHECK(D.isEmpty() == false);
  CHECK(D.contains(7) == true);
  CHECK(D.findMax() == 100);
  CHECK(D.findMin() == 1);

  BinarySearchTree<string> E;
  for (auto x :
  {"Sierra", "Hotel", "India", "Echo", "Lima", "Delta", "Shield"}){
    E.insert(x);
  }

  CHECK(E.isEmpty() == false);
  CHECK(E.contains("Hotel") == true);


  CHECK(C.toInorderStr() == "2,3,4,6,7,8,10,12,14,15,16,18,20,22,24,26,28,30");
  CHECK(D.toInorderStr() == "1,3,7,21,28,36,44,56,62,74,82,86,92,100");
  //CHECK(E.toInorderStr() == "Sierra,Hotel,India,Echo,Lima,Delta,Shield");
  CHECK(C.BFT() == "[[16],[8,24],[4,12,20,28],[2,6,10,14,18,22,26,30],[3,7,15]]");


  D.makeEmpty();
  CHECK(D.isEmpty() == true);
}
