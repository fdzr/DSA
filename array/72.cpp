#include <bits/stdc++.h>

using namespace std;

int maxDistance(vector<int>& colors) {
    int cornerLeftElement = colors[0];
    int cornerRightElement = colors[colors.size() - 1];
    int indexLeftToRight = -1;
    int indexRightToLeft = -1;

    for(int i = 1; i < colors.size(); ++i) {
        if(colors[i] != cornerLeftElement)
            indexLeftToRight = i;
    }

    for(int i = colors.size() - 2; i >= 0; --i) {
        if(colors[i] != cornerRightElement)
            indexRightToLeft = i;
    }

    int ans = max(indexLeftToRight - 0, static_cast<int>( colors.size() - 1 - indexRightToLeft));

    return ans;
}


int main() {
    vector<int> colors = {1,2,3,1,1,1,1,1,1,1,1,1};
    cout<<maxDistance(colors);

    return 0;
}