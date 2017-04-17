#include <cstdio>
#include <queue>
#define MX 105
using namespace std;

char maze[MX][MX];
bool flag[MX][MX];
int n,m;
int Go[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
struct Node{
	int x, y, t;
	Node(int X, int Y, int T){x=X; y=Y; t=T;}
};

void Get(int n, int m) {
	getchar();
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			scanf("%c",&maze[i][j]);
		getchar();
	}
}

void BFS() {
	Node start(0,0,0);
	queue<Node> q;
	q.push(start);
	maze[0][0] = '!';
	while(!q.empty())
	{
		Node temp = q.front();
		q.pop();
		if(temp.x==n-1 && temp.y==m-1) { //end
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", temp.t);
			printf("FINISH\n");
			return;
		}

		for(int i=0; i<4; i++)
		{
			int x = temp.x + Go[i][0];
			int y = temp.y + Go[i][1];
			int t = temp.t ++;

			if(x>=0 && x<n && y>=0 && y<m)
			{
				if(maze[x][y] == '.') {
					Node next(x,y,t);
					q.push(next);
				}
				else if(maze[x][y] == 'X') {
					continue;
				}
				else if(maze[x][y]<='9' && maze[x][y]>='0'){
					int time = maze[x][y] - '0';
					Node next(x, y, t+time);
					q.push(next);
				}
				maze[x][y] = '!';
			}
		}
	}
	printf("God please help our poor hero.\n");
	return;
}


int main() {
	while(~scanf("%d%d",&n,&m))
	{
		Get(n,m);
		BFS();
	}
	return 0;
}
/*
5 6
.XX.1.
..X.2.
2...X.
...XX.
XXXXX.
*/

