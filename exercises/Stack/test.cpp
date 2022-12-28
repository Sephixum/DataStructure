#include <iostream>
bool Is_empty() {
	int rear ;
	int front = 1;
	int size = 5;
    // if (((rear + 2) % (size)) == ((front) % (size)))
    //   return true;
    // else
    //   return false;
	
	std::cout << ((rear+2)%(size)==((front)%(size)));
	if (front == rear + 1){
		return 1;
	}
	return 0;

}

int main(){
	int arr[5]{1,2,3,4,5};
	arr[4] = 6;
	std::cout << arr[4];
	std::cout << Is_empty();
	return 0;
}
