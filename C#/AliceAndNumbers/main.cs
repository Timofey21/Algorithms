using System;
namespace zachet
{
    internal class Program
    {
        private static int n;
        private static byte k;
        private static int sum;
        
       
        public static void Main(string[] args)
        {
            string[] tokens = Console.ReadLine().Split();
            n = int.Parse(tokens[0]);
            k = byte.Parse(tokens[1]);
            sum = 0;


            sum = n - n/k;


            
            Console.Write(sum);
            
        }
        
    }
}