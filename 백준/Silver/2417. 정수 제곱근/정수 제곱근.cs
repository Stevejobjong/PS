
            long n = long.Parse(Console.ReadLine());
            long left = 0;
            long right = n;
            long q = 0;
            while (left <= right)
            {
                long mid = (left + right) / 2;
                if (Math.Pow(mid,2) >= n)
                {
                    q = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            Console.WriteLine(q);
