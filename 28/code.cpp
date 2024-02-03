#include <iostream>
#include <vector>
#include <stack>

int countMoves( std::vector<int> &placeFrom,
                std::vector<int> &placeTo,
                std::stack<char> &bar1,
                std::stack<char> &bar2,
                std::stack<char> &bar3, int size ){

    int R = 0; // the counter of moves
    int bStreak = 0; // streak of right brackets

    while(bar3.size() != size){
        R++;

        if(!bar1.empty() && bar1.top() == '('){
            if(bStreak > 0){
                // update moves
                placeFrom.push_back(1);
                placeTo.push_back(3);
 
                bar3.push('(');
                bar1.pop();

                bStreak--;

                continue;
            } else {
                // update moves
                placeFrom.push_back(1);
                placeTo.push_back(2);

                bar2.push('(');
                bar1.pop();

                continue;
            }

        } else if(bar1.empty() && bStreak > 0 && !bar2.empty()){
            // update moves
            placeFrom.push_back(2);
            placeTo.push_back(3);

            bStreak--;

            bar3.push('('); // because bar2 only holds left brackets
            bar2.pop();

            continue;

        } else if (bar1.top() == ')'){
            // update moves
            placeFrom.push_back(1);
            placeTo.push_back(3);

            // because the right bracket is moved the streak is increased
            bStreak++;

            bar3.push(')');
            bar1.pop();
        }
    }

    if(bStreak != 0) return -1;

    return R;
}

int main()
{
    // define bars
    std::stack<char> bar1;
    std::stack<char> bar2;
    std::stack<char> bar3;

    std::string brackets; // the discs ')' or '('
    std::cin >> brackets;

    int size = brackets.length(); // the amount of discs (brackets)

    // define vectors that will contain the moves of each disc
    std::vector<int> placeFrom;
    std::vector<int> placeTo;

    int leftBrackets = 0,
        rightBrackets = 0;

    // fill the first bar with discs
    for(int i = size - 1; i >= 0; i--){
        bar1.push(brackets[i]);

        if(brackets[i] == '(') leftBrackets++;
        if(brackets[i] == ')') rightBrackets++;
    }

    // if the amount of left and right brackets is not equal then finish
    if(leftBrackets != rightBrackets){
        std::cout << "NIE";
    } else {
        // how many moves were needed
        int result = countMoves(placeFrom, placeTo, bar1, bar2, bar3, size);

        if(result == -1){
            std::cout << "NIE";
        } else {
            std::cout << result << std::endl;

            for(int i = 0; i < placeFrom.size(); i++){
                std::cout << placeFrom[i] << " " << placeTo[i] << std::endl;
            }
        }
    }



    return 0;
}