#include<bits/stdc++.h>
#include<string>
using namespace std;

int n;
complex<double> result;

int main()
{
    scanf("%d", &n);
    string str;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        int pos = 0;
        int len = str.size();
        int end = 0;
        int _end_ = 1;
        if (str[0] == '-')
        {
            _end_ = str[0] == '-' ? -1 : 1;
            str = str.substr(1);
        }
        else if (str[0] == '+')
        {
            _end_ = str[0] == '-' ? -1 : 1;
            str = str.substr(1);
        }
        while (pos <= len)
        {
            if (pos == len || str[pos] == '+' || str[pos] == '-')
            {
                string t = str.substr(end, pos - end);
                complex<double> tmp;
                if (t.back() == 'i')
                {
                    if (t.size() == 1)
                    {
                        tmp. imag(_end_);
                    }
                    else
                    {
                        tmp. imag(stod(t . substr(0, t.size() - 1)) * _end_);
                    }
                }
                else
                {
                    tmp. real(stod(t) * _end_);
                }
                result += tmp;
                end = pos + 1;
                if(pos < len)
                {
                    if (str[pos] == '+')
                    {
                        _end_ = 1;
                    }
                    else
                    {
                        _end_ = -1;
                    }
                }
            }
            pos++;
        }
    }
    if (result.real() != (double)0)
    {
        cout << result.real();
    }
    if (result.real() && result. imag() > 0)
    {
        printf("+");
    }
    if (result. imag() != (double)1 && result. imag() != (double)0)
    {
        cout << result. imag();
    }
    if (result. imag() != (double)0)
    {
        printf("i");
    }
    return 0;

}

