
import java.util.Vector;



public class mergeSort1{
    public static void merge(Vector<Integer> a, Vector<Integer> b, Vector<Integer> res){
        int i = 0, j = 0, k = 0;
        while(i<a.size() && j<b.size()){
            if(a.get(i) < b.get(j)) res.set(k++, a.get(i++));
            else res.set(k++, b.get(j++)); 
            if(i == a.size()){
                while(j < b.size()) res.set(k++, b.get(j++));
            }
            if(j == b.size()){
                while(i < a.size()) res.set(k++, a.get(i++));
            }
        }
    }
    public static void mergeSort(Vector<Integer> v){
        int n = v.size();
        int n1 = n/2;
        int n2 = n - n/2;
        if(n==1) return;
        Vector<Integer> v1 = new Vector<>(n1);
        Vector<Integer> v2 = new Vector<>(n2);
        for(int i=0;i<n1;i++){
            v1.add(i,v.get(i));
        }
        for(int i=0;i<n2;i++){
            v2.add(i,v.get((i+n1)));
        }
        mergeSort(v1);
        mergeSort(v2);
        merge(v1,v2,v);
        v1.clear();
        v2.clear();
    }
    public static void main(String[] args){
        Vector<Integer> v = new Vector<>();
        v.add(23);
        v.add(3);
        v.add(6);
        v.add(7);
        v.add(2);
        mergeSort(v);
        for(int i=0;i<v.size();i++){
            System.out.print(v.get(i)+" ");
        }
        System.out.println();
    }
}