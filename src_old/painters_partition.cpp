int check(vector<int> &board, int at_most, int k) 
{ 
    int n = board.size();
    int s = 0, painters = 1; 
  
    for (int i = 0; i < n; i++) 
    { 
        s += board[i]; 
  
        if (s > at_most) 
        { 
            s = board[i]; 
            painters++; 
        } 
    } 
  
    return painters <= k; 
} 

int partition(vector<int> &board, int k) 
{ 
    int n = board.size(), s = 0, m = 0;
    for(int i = 0; i < n; i++)
    {
        m = max(m, board[i]);
        s += board[i];
    }
    
    int low = m, high = s;
    while (low < high) 
    { 
        int mid = low + (high - low) / 2;  
        if (check(board, k, mid)) high = mid; 
        else low = mid + 1; 
    } 
    return low; 
} 
