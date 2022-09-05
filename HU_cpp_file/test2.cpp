#include <iostream>

using namespace std;

int main() {
	int len[41], i =0;
	int len_size =0;
	while (1) {
		int i = 0;
		cin >> i;
		len[len_size++] = i;
		if (!i) break;
	}
	int height = 0;
	int wide =0;
	for (int i = 1; i < len_size; i += 2) {
		height += len[i];
	}
	for(int i=0;i<len_size;i+=2){
		wide += len[i];
	}
	int k = 0;
	int x, y;
	int results[15];
	for (int i = 0; i< 15;i++) {
		results[i] = 0;
	}

	while (k<15 && cin>>x>>y) {
		if (x>wide && x<0){
			results[k++] = -1;continue;
		}
		int result = 0;
		int xptr = 0, yptr = 1, h = height, x_left = 0, x_right = len[xptr] + x_left;
		while (xptr < len_size) {
			if (x_left < x && x < x_right) {
				if (y < h) {
					result = 1;
				}
				else if (y > h) {
					result = -1;
				}
				break;
			}
			else {
				if (x == x_right) {
					if (y > h) {
						result = -1;
					}
					else if (y < h - len[yptr]) {
						result = 1;
					}
					break;
				}
				x_left = x_right;
				xptr += 2;
				x_right += len[xptr];
				h -= len[yptr];
				yptr += 2;
			}
		}
		results[k++] = result;
	}
	for(int i=0;i<k;i++){
		if (results[i] == 0) {
			cout << "on" << endl;
		}
		else if (results[i] == -1) {
			cout << "out" << endl;
		}
		else {
			cout << "in" << endl;
		}
	}

	return 0;
}
