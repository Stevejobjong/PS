using System;
using System.Text;

namespace CodingTest
{
    internal class Program
    {
        static int m;
        static int n;
        static int k;
        static int[,] map;
        static int[] dx = { 0, 0, 1, -1 };
        static int[] dy = { 1, -1, 0, 0 };
        static void DFS(int x, int y)
        {
            map[x, y] = 0;
            for (int i = 0; i < 4; i++) // 주변 좌표로 이동.
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (map[nx, ny] == 1) DFS(nx, ny);
            }
        }
        static void Main(string[] args)
        {
            int test = int.Parse(Console.ReadLine());
            StringBuilder sb = new StringBuilder();
            while (test > 0)
            {
                string[] s = Console.ReadLine().Split();
                m = int.Parse(s[0]);
                n = int.Parse(s[1]);
                k = int.Parse(s[2]);
                map = new int[2501, 2501];

                for (int i = 0; i < k; i++)
                {
                    string[] input = Console.ReadLine().Split();
                    int x = int.Parse(input[0]);
                    int y = int.Parse(input[1]);
                    map[x + 1, y + 1] = 1;
                }

                int count = 0;
                for (int i = 1; i <= m; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        if (map[i, j] == 1)
                        {
                            DFS(i, j);
                            count++;
                        }
                    }
                }
                test--;
                sb.AppendLine(count.ToString());
            }
            Console.WriteLine(sb);
        }
    }
}