#include<iostream>
using namespace std;
int main () {
  int n;
  cin >> n;
  int arr[n];
  for (int i=0; i<n; i++) {
    cin >> arr[i];
  }

  bool isSorted = true;
  for (size_t i=1; i < n; i++) {
    // TODO: FILL CODE HERE...

    // เปลี่ยนค่าตัวแปรเป็น false เมื่อพบเจอว่าไม่เรียง - อาจจะ break ไปเลยก็ได้
    // ทั้งนี้ขึ้นกับวิธีที่น้อง ๆ สะดวกหรือถนัดกันเลยครับ ^ ^
    if(arr[i] < arr[i-1]) isSorted = false;
  }

  switch (isSorted)
  {
  case true:
    cout << "sorted!" << endl;
    break;
    
  default:
    cout << "un-sorted!" << endl;
    break;
  }
}