#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef struct _cloth {
  string name;
  int price;
  int size;
} cloth;

void print_option() {
  cout << "1. 필터링 by 카테고리 이름" << endl;
  cout << "2. 필터링 by 가격" << endl;
  cout << "3. 필터링 by 사이즈" << endl;
}

void print_cloth(cloth cloth) {
  cout << cloth.name << " " << cloth.price << " " << cloth.size << endl;
}

int main(void) {
  cloth cloths[5] = {{"상의", 20000, 1},
                     {"하의", 30000, 2},
                     {"원피스", 40000, 3},
                     {"상의", 20000, 1},
                     {"하의", 30000, 2}};

  print_option();
  int option;
  cin >> option;
  switch (option) {
    case 1:
      cout << "카테고리 이름에 따라 정렬을 시작합니다" << endl;
      sort(begin(cloths), end(cloths),
           [](cloth first, cloth second) { return first.name < second.name; });
      break;
    case 2:
      cout << "카테고리 가격에 따라 정렬을 시작합니다" << endl;
      sort(begin(cloths), end(cloths), [](cloth first, cloth second) {
        return first.price < second.price;
      });
      break;
    case 3:
      cout << "카테고리 사이즈에 따라 정렬을 시작합니다" << endl;
      sort(begin(cloths), end(cloths),
           [](cloth first, cloth second) { return first.size < second.size; });
      break;
  }

  for (int i = 0; i < 5; i++) {
    print_cloth(cloths[i]);
  }

  return 0;
}