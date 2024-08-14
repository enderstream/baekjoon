#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef struct doc_num
{
    int doc; //문서 우선순위
    int num; //초기 순서
}doc_num_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int docs;
        cin >> docs;
        print_queue(docs);
    }

    return 0;
}

void print_queue(int docs)
{
    int M = 0;
    cin >> M;

    list<doc_num_t> L = {};

    for (int i = 0; i < docs; i++)
    {
        doc_num_t page;
        cin >>page.doc;
        page.num = i;
        L.push_back(page);
    }

    list<doc_num_t>::iterator cur = L.begin();

    bool tf = true;

    while(tf)
    {   
        int checker = L.front().doc;
        // int max = cur;
        if(checker < (*cur).doc)
        {

        }
    }


}