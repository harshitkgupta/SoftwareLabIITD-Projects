import java.util.*;
import java.io.*;
public class WaterBody2
{
    public static  int ROW;
    public  static  int COL;
    public  boolean isSafe(int M[][], int row, int col, boolean visited[][])
    {
        return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) &&  (M[row][col]==1) && visited[row][col]==false; 
    }
    public  void DFSUTIL(int M[][], int row, int col, boolean visited[][],int count, int mark [][])
    {   
        int rowNbr[] = {-1, 1, 0,  0};
        int colNbr[] = {0,  0,  1, -1};      
        visited[row][col] = true;
        mark[row][col]=count;
        for (int k = 0; k < 4; ++k)
            if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited) )
             {   
                DFSUTIL(M,row+rowNbr[k],col+colNbr[k],visited,count,mark);
            }
    }
    public  void DFS8UTIL(int M[][], int row, int col, boolean visited[][],int count, int mark [][])
    {   
         int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
         int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};      
        visited[row][col] = true;
        mark[row][col]=count;
        for (int k = 0; k < 8; ++k)
            if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited) )
             {   
                DFS8UTIL(M,row+rowNbr[k],col+colNbr[k],visited,count,mark);
            }
    }
    public  int countIslands(int M[][],boolean visited[][],int mark[][])
    {
        int count = 0;
        for (int i = 1; i < ROW-1; ++i)
            for (int j = 1; j < COL-1; ++j)
                if (M[i][j]==1 && M[i-1][j]==1&& M[i][j-1]==1 && M[i+1][j]==1 && M[i][j+1]==1 && !visited[i][j]) 
                {  
                     ++count;                              
                    DFSUTIL(M,i,j,visited,count,mark);
                                   
                } 
        return count;
    }
    public  int count8Islands(int M[][],boolean visited[][],int mark[][])
    {        
        int count = 0;
        for (int i = 1; i < ROW-1; ++i)
            for (int j = 1; j < COL-1; ++j)
                if (M[i][j]==1 && M[i-1][j]==1&& M[i][j-1]==1 && M[i+1][j]==1 && M[i][j+1]==1&&
                 M[i-1][j-1]==1&&M[i-1][j+1]==1&&M[i+1][j-1]==1 &&M[i+1][j+1]==1&& !visited[i][j]) 
                {   
                    ++count;                            
                    DFS8UTIL(M,i,j,visited,count,mark);
                                     
                } 
        return count;
    }
    public static void main (String argc[]) throws Exception
    {     
        System.setIn(new FileInputStream("in"));             
        Scanner sc=new Scanner(System.in);
        try
        {
        ROW=sc.nextInt();
        COL=sc.nextInt();
        int M[][]=new int[ROW][COL];
        for(int i=0;i<ROW;i++)
        {    
            for(int j=0;j<COL;j++)
                M[i][j]=sc.nextInt();    
        } 
        int choice=sc.nextInt();          
        boolean visited[][]=new boolean[ROW][COL];
        int  mark[][]=new int[ROW][COL];
        WaterBody2 ob=new WaterBody2();
        for (int i = 0; i < ROW; ++i)
            for (int j = 0; j < COL; ++j)
                 visited[i][j]=false;
        for (int i = 0; i < ROW; ++i)
            for (int j = 0; j < COL; ++j)
                 mark[i][j]=0;     
        System.out.println("Original Matrix 1-water  and 0-land");     
        for(int i=0;i<ROW;i++)
        {    
            System.out.println("-------------------------------------------------");
            for(int j=0;j<COL;j++)
                System.out.print("|   "+M[i][j]+"   ");  
            System.out.println("|");
        } 
        System.out.println("-------------------------------------------------\n");
        if(choice==1)
            System.out.println("Number of islands For FourWay is Connectivity: "+ ob.countIslands(M,visited,mark)); 
        else if(choice==2)
            System.out.println("Number of islands For EightWay Connectivity is: "+ ob.count8Islands(M,visited,mark)); 
        System.out.println("\nWater bodies corresponding to matrix index ");
        for(int i=0;i<ROW;i++)
        {    
            System.out.println("-------------------------------------------------");
            for(int j=0;j<COL;j++)
                System.out.print("|"+i+" "+j+" "+((visited[i][j]==true)?"###":"   "));  
            System.out.println("|");
        } 
        System.out.println("-------------------------------------------------\n"); 
        System.out.println("\nWater bodies  Numbering corresponding to matrix index ");
        for(int i=0;i<ROW;i++)
        {    
            System.out.println("-------------------------------------------------");
            for(int j=0;j<COL;j++)
                System.out.print("|"+i+" "+j+" "+((mark[i][j])));  
            System.out.println("|");
        } 
        System.out.println("-------------------------------------------------\n"); 
        System.out.println("Output of All your Queries of points ");
        int query=sc.nextInt();
        while(query>0)
        {
            int m=sc.nextInt();
            int n=sc.nextInt();
            System.out.println("Your point at "+m+" "+n+" is"+(visited[m][n]==true?" inside Water Body number ":" not inside Water Body"));
            query--;
        }  
    }
    catch(Exception InputMismatchException)
    {
        System.out.println("Enter Number should not contain character");
    }

    }
}    