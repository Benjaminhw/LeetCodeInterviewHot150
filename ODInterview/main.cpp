#include "function.h"


// ����Ϊ�������������ܣ��˲��ִ��벻����Ķ�
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