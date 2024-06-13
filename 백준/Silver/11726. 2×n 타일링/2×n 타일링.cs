    internal class Program
    {
        static int[] dp = new int[1001];
        static void Main(string[] args)
        {
            int n;
            dp[1] = 1;
            dp[2] = 2;
            n = int.Parse(Console.ReadLine());
            for(int i=3;i<=n;i++)
            {
                dp[i] = dp[i - 1] % 10007 + dp[i - 2] % 10007;
                dp[i] %= 10007;
            }
            Console.WriteLine(dp[n] % 10007);
        }
    }