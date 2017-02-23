import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.StdOut;
//import Percolation;

public class PercolationStats{
   private double[] threshold;
   public PercolationStats(int n, int trials)    // perform trials independent experiments on an n-by-n grid
   {
     if(n<=0||trials<=0)
       throw new IllegalArgumentException();
     threshold=new double [trials];
     
     for(int i=0;i<trials;i++)
     {
       Percolation pl=new Percolation(n);
       int count=0;
       while(!pl.percolates())
       {
         int row=StdRandom.uniform(1,n+1);
         int col=StdRandom.uniform(1,n+1);
         if(pl.isOpen(row,col))
           continue;
         else
           pl.open(row,col);
           count++;
       }
       threshold[i]=(double)count/(n*n);
     }
   }
   public double mean()                          // sample mean(average) of percolation threshold
   {
     return StdStats.mean(threshold);
   }
   public double stddev()                        // sample standard deviation of percolation threshold
   {
     return StdStats.stddev(threshold);
   }
   public double confidenceLo()                  // low  endpoint of 95% confidence interval
   {
     return mean()-((1.96*stddev())/Math.sqrt(threshold.length)); 
   }
   public double confidenceHi()                  // high endpoint of 95% confidence interval
   {
     return mean()+((1.96*stddev())/Math.sqrt(threshold.length)); 
   }
  
  public static void main(String[] args){
    System.out.println("PercolationStats");
     PercolationStats ps=new PercolationStats(200,100); 
     StdOut.print("mean = "+ps.mean()+"\n");
     StdOut.print("std dev = "+ps.stddev()+"\n");
     StdOut.print("95% confidence interval = "+ps.confidenceLo()+", "+ps.confidenceHi());
    
  }
}