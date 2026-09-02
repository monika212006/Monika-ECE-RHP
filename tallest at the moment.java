import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        List<int[]> data = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int h = input.nextInt();
            int time = input.nextInt();
            data.add(new int[]{h, time});
        }

        data.sort((x, y) -> Integer.compare(y[0], x[0]));

        int[] height = new int[n];
        int[] times = new int[n];

        height[0] = data.get(0)[0];
        times[0] = data.get(0)[1];

        for (int i = 1; i < n; i++) {
            if (data.get(i)[1] > times[i - 1]) {
                times[i] = data.get(i)[1];
                height[i] = data.get(i)[0];
            } else {
                times[i] = times[i - 1];
                height[i] = height[i - 1];
            }
        }

        int queries = input.nextInt();

        while (queries-- > 0) {
            int time = input.nextInt();
            int pos = upperBound(times, time);

            if (pos == n)
                System.out.println(-1);
            else
                System.out.println(height[pos]);
        }

        input.close();
    }

    private static int upperBound(int[] values, int key) {
        int left = 0;
        int right = values.length;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (values[mid] > key)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
}
