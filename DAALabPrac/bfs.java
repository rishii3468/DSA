import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
import java.util.HashSet;

public class bfs{
    void bfstrav(int[][] matrix, int startVertex){
        int v = matrix.length;
        HashSet<Integer> visited = new HashSet<>();
        
    }

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        int vertices = s.nextInt();
        int[][] matrix = new int[vertices][vertices];
        System.out.println("Enter the adjacency matrix: ");
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                matrix[i][j] = s.nextInt();
            }
        }
        System.out.print("Enter the starting vertex: ");
        int startVertex = s.nextInt();
        bfstrav(matrix,startVertex);
        
    }
}