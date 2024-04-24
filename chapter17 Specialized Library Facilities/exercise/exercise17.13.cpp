#include <bitset>
#include <iostream>

using namespace std;

template <size_t Count>
class Exam
{
public:
    void mark_true(size_t pos);
    void mark_false(size_t pos);
    size_t get_grades(const bitset<Count> &ans) const;
    void print_res(const bitset<Count> &ans) const;
private:
    bitset<Count> record;
};

template <size_t Count>
void Exam<Count>::mark_true(size_t pos)
{
    record.set(pos);
}

template <size_t Count>
void Exam<Count>::mark_false(size_t pos)
{
    record.reset(pos);
}

template <size_t Count>
size_t Exam<Count>::get_grades(const bitset<Count> &ans) const
{
    size_t res = 0;
    for (int i = 0; i < ans.size(); ++i)
    {
        if (record[i] == ans[i])
            ++res;
    }
    return res;
}

template <size_t Count>
void Exam<Count>::print_res(const bitset<Count> &ans) const
{
    cout << record.size() << " quizs, " << get_grades(ans) << " is right." << endl;
}

int main(int argc, char const *argv[])
{
    Exam<30> e1;
    e1.mark_false(2);
    e1.mark_true(21);
    e1.mark_true(20);
    bitset<30> ans;
    ans.set(21);
    e1.print_res(ans);
    return 0;
}

