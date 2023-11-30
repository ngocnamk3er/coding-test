#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Hàm kiểm tra tính cân đối của chuỗi chứa dấu ngoặc
bool checkBalancedString(string str)
{
    // Sử dụng stack để theo dõi dấu ngoặc mở và đóng
    stack<char> stack;

    // Duyệt qua từng ký tự trong chuỗi
    for (int i = 0; i < str.length(); i++)
    {
        // Nếu là dấu ngoặc mở hoặc stack đang rỗng, thêm vào stack
        if (str[i] == '{' || str[i] == '(' || str[i] == '[' || stack.empty())
        {
            stack.push(str[i]);
        }
        // Nếu là dấu ngoặc đóng và stack không rỗng
        else if ((str[i] == '}' && stack.top() == '{') ||
                 (str[i] == ')' && stack.top() == '(') ||
                 (str[i] == ']' && stack.top() == '['))
        {
            // Loại bỏ dấu ngoặc mở tương ứng từ stack
            stack.pop();
        }
        // Trường hợp khác, thêm ký tự vào stack
        else
        {
            stack.push(str[i]);
        }
    }

    // Kiểm tra xem stack có rỗng không, nếu rỗng thì chuỗi cân đối
    if (stack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // Nhập số lượng test case
    int n;
    cin >> n;

    // Vòng lặp qua từng test case
    for (int i = 0; i < n; i++)
    {
        // Nhập chuỗi cần kiểm tra
        string input_string;
        cin >> input_string;

        // Gọi hàm checkBalancedString và in kết quả
        if (checkBalancedString(input_string))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }

    return 0;
}
