#include "function.h"


// 以下为考题输入输出框架，此部分代码不建议改动
int main()
{
    string line;
    getline(cin, line);
    int diff = stoi(line);

    getline(cin, line);
    int n = stoi(line);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << Proc(arr, diff) << endl;
    return 0;
}