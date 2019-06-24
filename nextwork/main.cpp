#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Edge {
public:
	int distance;
	int node[2];
public:
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator<(Edge& edge) {
		return this->distance < edge.distance;
	}

};

int getParents(int set[], int x) {			//부모 노드 찾기
		if (set[x] == x) return x;
	return set[x] = getParents(set, set[x]);
}

void unionParents(int a, int b, int set[]) {	//부모 합치기
	a = getParents(set, a);
	b = getParents(set, b);
	if (a < b) set[b] = a;
	else set[a] = b;
}

int find(int a, int b, int set[]) {				//부모가 같은지 확인
	a = getParents(set, a);
	b = getParents(set, b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	int sum = 0;
	vector<Edge> v;
	int computer, pair, a, b, distance;
	cin >> computer >> pair;
	for (int i = 0; i < pair; i++) {
		cin >> a >> b >> distance;
		v.push_back(Edge(a, b, distance));
	}

	sort(v.begin(), v.end());

	int *set = new int[computer];
	for (int i = 0; i < computer; i++) {
		set[i] = i;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!find(v[i].node[0] -1, v[i].node[1] -1, set)) {
			sum += v[i].distance;
			unionParents(v[i].node[0] -1, v[i].node[1] -1, set);
		}
	}
	cout << sum << endl;
}