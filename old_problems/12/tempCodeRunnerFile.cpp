    for(int i = 0; i < N; i++){
        std::string temp;
        std::cin >> temp;

        for(int j = 0; j < M; j++){
            board[i][j] = temp[j];
        }
    }