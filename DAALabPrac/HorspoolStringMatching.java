import java.util.Scanner;

public class HorspoolStringMatching {
    
    // Function to create the shift table
    public static int[] shiftTable(String pattern) {
        int[] table = new int[256]; // ASCII character set size
        int m = pattern.length();

        // Initialize table with the length of pattern
        for (int i = 0; i < 256; i++) {
            table[i] = m;
        }

        // Fill table based on pattern characters
        for (int i = 0; i < m - 1; i++) {
            table[pattern.charAt(i)] = m - 1 - i;
        }
        return table;
    }

    // Function to perform Horspool's string matching
    public static int horspoolSearch(String text, String pattern) {
        int n = text.length();
        int m = pattern.length();
        int[] table = shiftTable(pattern); // Compute shift table

        int i = m - 1; // Start comparing from end of pattern
        while (i < n) {
            int k = 0;
            
            // Compare pattern from right to left
            while (k < m && pattern.charAt(m - 1 - k) == text.charAt(i - k)) {
                k++;
            }

            if (k == m) {
                return i - m + 1; // Pattern found at index i - m + 1
            } else {
                i += table[text.charAt(i)]; // Shift based on bad character rule
            }
        }
        return -1; // Pattern not found
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the text: ");
        String text = scanner.nextLine();

        System.out.print("Enter the pattern to search for: ");
        String pattern = scanner.nextLine();

        long startTime = System.nanoTime();
        int index = horspoolSearch(text, pattern);
        long endTime = System.nanoTime();

        if (index != -1) {
            System.out.println("Pattern found at index: " + index);
        } else {
            System.out.println("Pattern not found.");
        }

        double timeElapsed = (endTime - startTime) / 1e6; // Convert nanoseconds to milliseconds
        System.out.println("Time complexity: " + timeElapsed + " milliseconds");

        scanner.close();
    }
}