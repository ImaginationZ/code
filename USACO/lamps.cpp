/*
 ID:frequen1
 PROB:lamps
 LANG:C++
 */
// 只用一种优化,利用6盏之后的灯都是前6盏的重复,加上位运算,全部0.0sec
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
using namespace std;

ifstream fin("lamps.in");
ofstream fout("lamps.out");

static int N, C;
static vector<int> on, off;  // 存放最后亮与不亮的位数
const char OP1 = 63, OP2 = 42, OP3 = 21, OP4 = 36;  // 位运算的四种操作,用于异或
void Search();
vector<int> Convert(char c);
bool IsMatch(char c);
void Show(char c);

int main() {
    fin >> N >> C;
    int final;
    while (fin >> final && final != -1)
        on.push_back(final);
    while (fin >> final && final != -1)
        off.push_back(final);
    Search();
    return 0;
}

bool IsMatch(char c) {
	// 用存放6位的字符判断是否满足最后亮灭的位数
    vector<int> lamp = Convert(c);
	// 因为6位之后的位都是前6位的重复,所以求模比较即可
    for (vector<int>::iterator iter = on.begin(); iter != on.end(); ++iter) {
        if (lamp[*iter % 6] != 1)
            return false;
    }
    for (vector<int>::iterator iter = off.begin(); iter != off.end(); ++iter) {
        if (lamp[*iter % 6] != 0)
            return false;
    }
    return true;
}

vector<int> Convert(char c) {
	// 把6字符的6位转换成数组,便于计算
    vector<int> vec(7, 0);
    char bit = 32;
    for (int i = 1; i <= 6; ++i) {
        if (c & bit)
            vec[i] = 1;
        bit >>= 1;
    }
    vec[0] = vec[6];  // 用于求余,第0位存放第6位的数据,余6等于余0
    return vec;
}

void Show(char c) {
    vector<int> lamp = Convert(c);
	// 同理,反复输出前6位即可
    for (int i = 1; i <= N; ++i)
        fout << lamp[i % 6];
    fout << endl;
}

void Search() {
    char lamp = 63;									// 用一个字符存放6位数据,一开始灯全亮
    queue<char> states;
	bitset<65> d;										// 保存一轮循环产生的状态,减去重复计算,最多2^6种
	int pre_cnt = 1, curr_cnt = 0;  // 计数器,一个保存上一轮入队的个数,表示一次(亮灯灭灯的)操作,一个保存本轮操作的个数
    states.push(lamp);							// 一开始灯全亮
    for (int count = 0; count < C; ++count) {
		// 广度优先搜索,一趟搜索表示对灯的一次操作
        for (int cnt = 0; cnt < pre_cnt; ++cnt) {
            lamp = states.front();
            states.pop();
			if (!d[lamp ^ OP1]) {       // 先判断操作1产生的状态是否已入队
				states.push(lamp ^ OP1);  // 状态不存在,则入队
				d.set(lamp ^ OP1);				// 设置d
				++curr_cnt;								// 本轮产生的状态数+1
			}
            if (!d[lamp ^ OP2]) {
				states.push(lamp ^ OP2);
				d.set(lamp ^ OP2);
				++curr_cnt;
			}
            if (!d[lamp ^ OP3]) {
				states.push(lamp ^ OP3);
				d.set(lamp ^ OP3);
				++curr_cnt;
			}
            if (!d[lamp ^ OP4]) {
				states.push(lamp ^ OP4);
				d.set(lamp ^ OP4);
				++curr_cnt;
			}
        }
		d.reset();					 // 保存状态位的bitset清零
		pre_cnt = curr_cnt;  // 更新计数器,准备下一趟搜索
		curr_cnt = 0;
    }
    set<char> res;  // 利用set自动排序的特性
    while (!states.empty()) {
        if (IsMatch(states.front()))
            res.insert(states.front());  // 将满足最后状态的灯入队
        states.pop();
    }
    if (res.empty())
        fout << "IMPOSSIBLE" << endl;
    else
        for (set<char>::iterator iter = res.begin(); iter != res.end(); ++iter)
            Show(*iter);
}