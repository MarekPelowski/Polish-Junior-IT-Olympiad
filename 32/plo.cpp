#include <iostream>
#include <vector>

int checkTriangularity(std::vector<int> out){

    int n = out.size();
    std::vector<int> openedLines = {out[0]};

    for(int i = 0; i < n; i++){
        if(out[i] > openedLines[openedLines.size() - 1]){
            return i + 1;
        }

        openedLines.push_back(out[i]);
    }

    return 0;
}

int main()
{
    int N; // amount of sets
    std::cin >> N;

    std::vector<int> out(N, 0);

    for(int i = 0; i < N - 2; i++){
        int x, y; // the beginning and end of each fence
        std::cin >> x >> y;
        out[x - 1] = (out[x - 1] == 0) ? y : std::min(out[x - 1], y);
        out[y - 1] = (out[y - 1] == 0) ? x : std::min(out[y - 1], x);
    }

    std::cout << checkTriangularity(out) << " " << out[checkTriangularity(out)];

    return 0;
}