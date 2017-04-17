//http://acm.hdu.edu.cn/showproblem.php?pid=1251
#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX 26
using namespace std;

char tree[26];

struct Trie {
	struct Trie *next[MAX];
	int cnt;
	Trie() {
		cnt = 0;
		memset(next,0,sizeof(next));
	}
};

Trie *root = NULL;

void make_tree(char* tree) {
	Trie* p = root;
	Trie* tmp = NULL;
	int len = strlen(tree);
	for(int i=0; i<len; i++) {
		if(p->next[tree[i]-'a'] == NULL) {
			tmp = new Trie; //一定要重新申请 Trie 
			p->next[tree[i]-'a'] = tmp;
		}
		p = p->next[tree[i]-'a'];
		p->cnt++;
	}
}

void find_tree(char* tree) {
	Trie* p = root;
	int len = strlen(tree);
	for(int i=0; i<len; i++) {
		if(p->next[tree[i]-'a'] == NULL) {
			printf("0\n");
			return;
		}
		p = p->next[tree[i]-'a'];
	}
	printf("%d\n",p->cnt);
}

int main() {
	root = new Trie;
	while(gets(tree) && strlen(tree)) {
		if(strcmp(tree,"")==0) break;
		make_tree(tree);
	}

	while(scanf("%s",&tree)!=EOF) {
		find_tree(tree);
	}
	return 0;
}
/*
ba
b
band
abc
*/
