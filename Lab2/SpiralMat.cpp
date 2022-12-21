#include<iostream>
using namespace std;
#include<vector>
void Spiral (vector<vector<int>> &matrix, int &n, int &m)
{
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<matrix[i][j]<<"  ";
        }
    cout<<endl;
    
    }
    int ite{0};
    int left{0},top{0},direction{0};
    int right{m-1},bottom{n-1};
    cout<<"\n\n Printing in Spiral form:\n";
    while (true)
    {
        if(direction ==0)
        {
        for (int col =left;col<= right;col++)
        {
            cout<<matrix[top][col]<<"  ";
        }
        top++;
        direction =1;
        }
        if(direction ==1)
        {
            for (int row = top; row<=bottom;row++)
            {
                cout<< matrix[row][right]<< " ";
            }
            right --;
            direction++;
        }
        if (direction ==2)
        {
             for (int col =right;col>=left;col--)
        {
            cout<<matrix[bottom][col]<<"  ";
        }
        direction++;
        if(bottom>top)
        {
            bottom --;
        }
        
        }
         if(direction ==3)
        {
            for (int row = bottom; row>=top;row--)
            {
                cout<< matrix[row][left]<< " ";
            }
            if (left<right)
            {
                /* code */
                left++;
            }
            
            
            direction =0;
        }
        cout<<"Top: "<<top<<"\tBottom: "<<bottom<<"\nLeft: "<<left<<"\tRight: "<<right<<endl;
        ite++;
        if(left==right && top==bottom)
        {
            break;
        }
    }
    

}
int main()
{
    int n{},m{};
    cout<<"Enter the number of rows and columns";
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand()%10;
        }
        
    }

    Spiral(matrix,n,m);

    return 0;
}
