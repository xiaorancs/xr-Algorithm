/**
 *Author: xiaoran
 *Time: 2017-12-07 10:52
 *Problem:
 * 题目：给你一系列的由两个字符组成的块，这个块中包含所有的26个字符（全部大写或者小写），
 * 现在给一你一个单词，你是否可以从这些块中拼写出这个单词。
 * 每一块只能用一次，且每次只能选择一个字符。给定的单词不区分大小写。
 * 例如这些所有的块如下：
 *  (B O),(X K),(D Q),(C P),(N A),(G T),(R E),(T G),(Q D),(F S),
 *  (J W),(H U),(V I),(A N),(O B),(E R),(F S),(L Y),(P C),(Z M)
 *
 * 例如：
 *  "A" ---> true
 *  "a" ---> true	
 *  "BARK" ----> true  一种选择方案：(B O) (X K) (N A) (E R)
 *  "BOOK" ----> false 
 *
 *分析：
 *  竟然每一个块只能选择一次，我们可以用一个标记数据visit，进行dfs的深度优先搜索
 *  我们可以使用两层循环，每一次标记前一次使用过的单词。是否会有问题?
 */
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<string>
#include<cctype>
using namespace std;


typedef vector<string> list_t;

bool is_make_word(const string& w, const list_t& vals){
	//注意单词的长度不能大于块的个数。
	if(w.size() > vals.size()) return false;

	set<int> used;//纪录使用的块	
	while(used.size() < w.size()){//最多选择w.size()个块
		const char c = toupper(w[used.size()]);
		int x = used.size();	
	
		for(int i=0; i < vals.size(); ++i){
			if(used.find(i) == used.end()){//第i个块没有使用
				if(toupper(vals[i][0]) == c || toupper(vals[i][1]) == c){
					//判断当前块是否可用
					used.insert(i);//纪录可用的块的下标
					break;//这是以个O(w.size() * vals.size())的复杂度
				}
			}
		}
		if(x == used.size()){//当有一个循环没有添加的可用的块，就可以直接退出while
			break;
		}
		
	}
	return used.size() == w.size();
}


int main()
{	
	string val[] = {"BO", "XK", "DQ", "CP", "NA", "GT", "RE", "TG", "QD", "FS",
		          "JW", "HU", "VI", "AN", "OB", "ER", "FS", "LY", "PC", "ZM"};
	list_t vals(val,val+20);
	
	string word[] = {"A","a","BARK","TREAT","COMMON","SQUAD","CONFUSE"};
	vector<string> words(word,word+7);	
//	cout<<vals[18]<<endl;

	for(int i = 0;i < words.size(); ++i){
		string w = words[i];
		cout<<w<<": "<<boolalpha<<is_make_word(w,vals)<<endl;
	}
	return 0;
}
