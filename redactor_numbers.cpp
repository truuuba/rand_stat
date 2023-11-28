#ifndef REDACTOR_NUMBERS_CPP
#define REDACTOR_NUMBERS_CPP
#include <QVector>

class Stat_for_diag{
    private:
        QVector<double> orig_ch;
        QVector<double> amount_ch;
    public:
        void set_orig_ch(QVector<double> orig_){
            orig_ch = orig_;
        }
        void set_amount_ch(QVector<double> amount_){
            amount_ch = amount_;
        }
        QVector<double> get_orig_ch(){
            return orig_ch;
        }
        QVector<double> get_amount_ch(){
            return amount_ch;
        }
};

Stat_for_diag count_vect(QVector<int> a){
    Stat_for_diag res;
    QVector<double> numbers;
    QVector<double> am_numb;
    bool flag = true;
    while (flag)
    {
        int n = a.size() - 1;
        int count = 0;
        double ch = a[0], count_ch = 1;
        a.erase(a.begin());
        while(count < n)
        {
            if (a[count] == ch)
            {
                count_ch++;
                a.erase(a.begin() + count);
                n -= 1;
            }
            count++;
        }
        numbers.push_back(ch);
        am_numb.push_back(count_ch);
        if (a.size() <= 1)
            flag = false;
    }
    res.set_amount_ch(am_numb);
    res.set_orig_ch(numbers);
    return res;
}

double minimum(QVector<double> a){
    double min_ = a[0];
    int n = a.size();
    for (int i = 1; i < n; i++){
        if(a[i] < min_)
            min_ = a[i];
    }
    return min_;
}

double maximum(QVector<double> a){
    double max_ = a[0];
    int n = a.size();
    for (int i = 1; i < n; i++){
        if(a[i] > max_)
            max_ = a[i];
    }
    return max_;
}

#endif // REDACTOR_NUMBERS_CPP
