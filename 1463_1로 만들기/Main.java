import java.io.*;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader BR = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(BR.readLine());

        int[] nums = new int[N + 1];

        for (int i = 2; i <= N; i++) {
            nums[i] = nums[i - 1] + 1;
            if (i % 2 == 0)
                nums[i] = Math.min(nums[i / 2] + 1, nums[i]);
            if (i % 3 == 0)
                nums[i] = Math.min(nums[i / 3] + 1, nums[i]);
        }
        System.out.println(nums[N]);
    }
}