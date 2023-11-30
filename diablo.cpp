// Nguyen Ngoc Nam - ngocnamk3er@gmail.com
#include <iostream>

using namespace std;

int caculateNeededGold(int m, int d, int k, int c)
{
    //Combo là số lần tấn công được nhiều nhất có thể trước khi repair kiếm
    int dameConLaiSau1Combo;
    int soQuaiDietDuocTrong1Combo;
    int soLanCombo;
    int soQuaiConLaiSauNLanCombo;
    int totalGold = 0;
    int soLanRepairKiem = 0;
    // Nếu độ bền d bằng độ hao hụt k và số quái lớn hơn 1 thì sẽ ko thể qua màn,
    // nếu độ bền d bé hơn độ hao hụt k cũng không thể qua màn
    if ((d == k && m > 1) || (d < k))
    {
        return -1;
    }
    else
    {
        if (d % k == 0)// Nếu d chia hết cho k thì trong 1 combo chỉ cho đánh (d - k) / k lần 
        {
            dameConLaiSau1Combo = k;//= độ hao hụt để giết 1 con quái
            soQuaiDietDuocTrong1Combo = (d - k) / k;
            soLanCombo = m / soQuaiDietDuocTrong1Combo;
            soQuaiConLaiSauNLanCombo = m % soLanCombo;
            if (soQuaiConLaiSauNLanCombo == 1)//Nếu chỉ còn 1 con quái thì tấn công thêm 1 lần là thắng (trường hợp mất thanh kiếm nhưng vẫn qua được màn)
            {
                soLanRepairKiem = soLanCombo - 1;
            }
            else//sửa lại thanh kiếm và tấn công hết số quái còn lại (>1)
            {
                soLanRepairKiem = soLanCombo;
            }
        }
        else// Nếu d ko chia hết cho k thì trong 1 combo cho đánh d / k lần sau đó sửa kiếm
        {
            soQuaiDietDuocTrong1Combo = d / k;
            soLanCombo = m / soQuaiDietDuocTrong1Combo;
            soLanRepairKiem = soLanCombo;
        }
    }
    return soLanRepairKiem * c;
}

int main()
{
    //m: số quái
    //d: độ bền
    //k: độ hao hụt sau khi đánh chết 1 quái
    //c: số vàng cho 1 lần reqair
    int m, d, k, c;
    cin >> m >> d >> k >> c;
    cout << caculateNeededGold(m, d, k, c) << endl;
}