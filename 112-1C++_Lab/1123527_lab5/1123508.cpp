#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string clean_word(string s)
{
    string r = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            r = r + static_cast<char>(tolower(s[i]));
        }
    }

    return r;
}

bool is_contain_letter(string s)
{
    // if (s.size())
    //     return true;
    // else
    //     return false;

    return (s.size()) ? true : false;
}

bool is_first_vowel(string s)
{
    int i = 0;
    char c = static_cast<char>(s[i]);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool is_repeat_twice(string s)
{
    int i;
    int l = s.size();
    bool flag = false;

    size_t found1;
    size_t found2;

    for (i = 0; i < l; i++)
    {
        found1 = s.substr(i + 1, l - i - 1).find_first_of(s[i]); // left
        found2 = s.substr(i + 1, l - i - 1).find_last_of(s[i]);  // right
        if ((found1 != string::npos) && (found2 != string::npos))
        {
            // more than twice
            if (found1 != found2)
            {
                return false;
            }

            // twice 暫時
            if (found1 == found2)
            {
                flag = true;
            }
        }
    }

    return flag;
}

void count_word_length(string s, int a[])
{
    int l = s.size();
    if (l >= 15)
    {
        l = 15;
    }
    a[l] += 1;
}

void count_first_letter(string s, int a[])
{
    int i = static_cast<int>(s[0]);
    if (i > 0)
    {
        // a -> 0, b -> 1, ...
        i -= 97;
        a[i] += 1;
    }
    // cout << "s: " << s << " , " << static_cast<int>(s[0]) << endl;
}

int main()
{
    int total_word = 0,
     first_vowel = 0;
    int twice_letter = 0;
    int L[16] = {0};
    int f[26] = {0};

    string S[26] = {"a/A", "b/B", "c/C", "d/D", "e/E",
                    "f/F", "g/G", "h/H", "i/I", "j/J",
                    "k/K", "l/L", "m/M", "n/M", "o/O",
                    "p/P", "q/Q", "r/R", "s/S", "t/T",
                    "u/U", "v/V", "w/W", "x/X", "y/Y",
                    "z/Z"};
    string s;

    while (cin >> s)
    {
        s = clean_word(s);
        // cout << "s: " << s << ", IS_RUN: " << IS_RUN
        //      << ", size: " << s.size() << ", [0]: " << s[0]
        //      << endl;

        if (is_contain_letter(s))
        {
            // cout << "total_word: " << s << endl;
            total_word++;
        }

        if (is_first_vowel(s))
        {
            // cout << "first_vowel: " << s << endl;
            first_vowel++;
        }

        if (is_repeat_twice(s))
        {
            // cout << "twice_letter: " << s << endl;
            twice_letter++;
        }

        count_word_length(s, L);
        count_first_letter(s, f);
    }

    cout << "# Total number of words, each of which has at least a letter: " << total_word << endl;
    cout << "# Total number of words whise first letter hs a vowel: " << first_vowel << endl;
    cout << "# Total number of words containing some letter repeated twice but no letter repeated more than twice: " << twice_letter << endl;

    cout << "# Distribution of words by word length:" << endl;
    for (int i = 0; i < 16; i++)
    {
        cout << "# L" << i << " =  " << L[i] << endl;
    }

    cout << "# Distribution of words by first letter:" << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << "# " << S[i] << ": " << f[i] << endl;
    }

    return 0;
}
