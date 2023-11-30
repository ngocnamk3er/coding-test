// Nguyen Ngoc Nam - ngocnamk3er@gmail.com
#include <iostream>
#include <vector>
using namespace std;

int sum = 0;

vector<string> result_array(1000000);

int count = 0;

void solution()
{
    // liệt kê tất cả trường hợp
    // for (int i = 1; i <= sum; i++)
    // {
    //     cout << result_array[i] << " ghi ban || ";
    // }
    // cout << endl;
    count++;
}

void Try(int turn, vector<int> scores) // Hàm đệ quy, turn = x đại diện cho bàn thứ x được ghi, vector scores có 2 phần tử thể hiện cho điểm số 2 đội
{
    if (turn == sum + 1) // Nếu đệ quy tới tổng số bàn ghi được + 1 thì in ra kết quả
    {
        solution();
    }
    else
    {
        for (int i = 0; i <= 1; i++)
        {
            if (i == 0 && scores[i] != 0)
            {
                result_array[turn] = "TTLap";
                scores[0] = scores[0] - 1; // giả sử đội TTLap ghi bàn, trừ 1 đi ở giá trị scores[0]
                Try(turn + 1, scores);     // đệ quy với giá trị turn + 1 cho bàn tiếp theo
                scores[0] = scores[0] + 1; // cập nhật lại giá trị cho scores[0] sau khi thoát nhánh đệ quy
            }
            else if (i == 1 && scores[i] != 0)
            {
                result_array[turn] = "TT";
                scores[1] = scores[1] - 1; // giả sử đội TT ghi bàn, trừ 1 đi ở giá trị scores[1]
                Try(turn + 1, scores);     // đệ quy với giá trị turn + 1 cho bàn tiếp theo
                scores[1] = scores[1] + 1; // cập nhật lại giá trị cho scores[1] sau khi thoát nhánh đệ quy
            }
        }
    }
}

void countWays(int TTLapPoint, int TTPoint)
{
    sum = TTLapPoint + TTPoint;
    vector<int> scores(2);
    scores[0] = TTLapPoint; // Lưu số bàn thắng của TTlap
    scores[1] = TTPoint;    // Lưu số bàn thắng của TTPoint
    Try(1, scores);         // Bắt đầu đệ quy bàn thắng đầu tiên
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int TTLapPoint;
        int TTPoint;
        cin >> TTLapPoint >> TTPoint;   // Nhập số bàn của mỗi đội
        count = 0;                      // Biến đếm số trường hợp
        countWays(TTLapPoint, TTPoint); // Hàm tính ra kết quả
        cout << count << endl;          // i ra kết quả
    }
}