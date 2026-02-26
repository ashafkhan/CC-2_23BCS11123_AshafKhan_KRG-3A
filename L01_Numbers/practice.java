import java.util.*;

public class practice {

    public static int specialElements(int[] arr) {
        int n = arr.length;
        HashMap<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {

            boolean prefix = false;
            boolean suffix = false;

            if (i >= 2 && arr[i] == arr[i - 1] && arr[i - 1] == arr[i - 2]) {
                prefix = true;
            }

            if (i <= n - 3 && arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]) {
                suffix = true;
            }

            if (prefix || suffix) {
                mp.put(arr[i], mp.getOrDefault(arr[i], 0) + 1);
            }
        }

        int count = 0;
        for (int freq : mp.values()) {
            count += freq;
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int result = specialElements(arr);
        System.out.println(result);

        sc.close();
    }
}
