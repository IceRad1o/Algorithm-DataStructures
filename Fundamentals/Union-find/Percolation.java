//import edu.princeton.cs.algs4.StdRandom;
//import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
   private WeightedQuickUnionUF WQU;
   private int size;
   private int[] state;//0:blocked,1:open
   public Percolation(int n){
     if(n<=0)
       throw new IllegalArgumentException("IllegalArgument");
     size=n;
     WQU= new WeightedQuickUnionUF(n*n+2);
     state=new int[n*n+2];
     for(int i=1;i<n*n+1;i++)
       {state[i]=0;} 
     state[0]=1;
     state[n*n+1]=1;
   }
   public void open(int row, int col) 
   {
      CheckRange(row,col);
      if(isOpen(row,col)) return;
      int index=(row-1)*size+col;
      state[index]=1;
      int up=(row-2)*size+col;
      int down=row*size+col;
      int left=index-1;
      int right=index+1;
      //up
      if(row!=1&&isOpen(row-1,col)){
        union(up,index);
      }else if(row==1){
        union(0,index);
      }
      //down
      if(row!=size&&isOpen(row+1,col)){
        union(down,index);
      }else if(row==size){
        union(index,size*size+1);
      }
      //left
      if(col!=1&&isOpen(row,col-1)){
        union(left,index);
      }
      //right
      if(col!=size&&isOpen(row,col+1)){
        union(right,index);
      }
      
   }   

   public boolean isOpen(int row, int col)  // is site (row, col) open?
   {
     CheckRange(row,col);
     int index=(row-1)*size+col;
     if(state[index]==1) return true;
     else return false;
   }
   
   public boolean isFull(int row, int col)  // is site (row, col) full?
   { 
     CheckRange(row,col);
     int index=(row-1)*size+col;
     return WQU.connected(0,index);
   }
   
   public int numberOfOpenSites()       // number of open sites
   {
    int numberofopensites=0;
    for(int i=1;i<size*size+1;i++)
      if(state[i]==1)
      numberofopensites++;
    return numberofopensites;
   }
   
   public boolean percolates(){
     return WQU.connected(0,size*size+1);
   }
   
   //private methods
   private void CheckRange(int i,int j){
    if(i<=0||j<=0||i>size||j>size)
       throw new IndexOutOfBoundsException("index row: "+i+"index col"+j+"is out of bounds");
   }
   
   private void union(int a,int b){
     if(!WQU.connected(a,b))
       WQU.union(a,b);
   }
   public static void main(String[] args) {
     System.out.println("percolation initialization");
     //Percolation
   } // test client (optional)
}