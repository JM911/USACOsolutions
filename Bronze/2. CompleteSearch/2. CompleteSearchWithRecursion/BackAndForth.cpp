#include "bits/stdc++.h"
using namespace std;

int firstBucket[25];
int secondBucket[25];

void syncArr(int target[], int source[])
{
    for(int i=0; i<20; i++)
    {
        target[i] = source[i];
    }
}

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);

    for(int i=0; i<10; i++)
    {
        cin >> firstBucket[i];
    }
    for(int i=0; i<10; i++)
    {
        cin >> secondBucket[i];
    }

    unordered_set<int> s;

    for(int a=0; a<10; a++)
    {
        int newFirstBucket[25];
        int newSecondBucket[25];
        syncArr(newFirstBucket, firstBucket);
        syncArr(newSecondBucket, secondBucket);

        int tueBucket = newFirstBucket[a];

        newSecondBucket[10] = tueBucket;
        newFirstBucket[a] = 0;

        for(int b=0; b<11; b++)
        {
            int wedBucket = newSecondBucket[b];

            newFirstBucket[a] = wedBucket;
            newSecondBucket[b] = 0;

            for(int c=0; c<10; c++)
            {
                int thuBucket = newFirstBucket[c];

                newSecondBucket[b] = thuBucket;
                newFirstBucket[c] = 0;

                for(int d=0; d<11; d++)
                {
                    int friBucket = newSecondBucket[d];

                    int lastReading = 1000 - tueBucket + wedBucket - thuBucket + friBucket;
                    
                    s.insert(lastReading);
                }

                newFirstBucket[c] = thuBucket;
                newSecondBucket[b] = 0;
            }

            newSecondBucket[b] = wedBucket;
            newFirstBucket[a] = 0;
        }

        newFirstBucket[a] = tueBucket;
        newSecondBucket[10] = 0;
    }

    cout << s.size() << '\n';
}