public class WaterBody
{
    public  final int ROW=5;
    public  final int COL=5;
    public  boolean isSafe(int M[][], int row, int col, boolean visited[][])
    {
        return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) &&  (M[row][col]==1) && visited[row][col]==false; 
    }
    public  void DFSUTIL(int M[][], int row, int col, boolean visited[][])
    {   
        int rowNbr[] = {-1, 1, 0,  0};
        int colNbr[] = {0,  0,  1, -1};      
        visited[row][col] = true;
        for (int k = 0; k < 4; ++k)
            if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited) )
             {   
                DFSUTIL(M,row+rowNbr[k],col+colNbr[k],visited);
            }
    }
    public  int countIslands(int M[][])
    {
        boolean visited[][]=new boolean[ROW][COL];
        for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            visited[i][j]=false; 
        int count = 0;
        for (int i = 1; i < ROW; ++i)
            for (int j = 1; j < COL; ++j)
                if (M[i][j]==1 && M[i-1][j]==1&& M[i][j-1]==1 && M[i+1][j]==1 && M[i][j+1]==1 && !visited[i][j]) 
                {                              
                    DFSUTIL(M,i,j,visited);
                    ++count;                  
                } 
        return count;
    }
    public static void main (String argc[])
    {
        int M[][]= {  {0, 1, 0, 1, 0},
                  {1, 1, 1, 1, 1},
                  {0, 1, 0, 1, 0},
                  {1, 0, 1, 1, 1},
                  {1, 1, 0, 1, 0}};
        WaterBody ob=new WaterBody();
        System.out.println("Number of islands is: "+ ob.countIslands(M));   
    }
}    