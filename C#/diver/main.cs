using System;
namespace zachet
{
    internal class Program
    {
        private static int Xj;
        private static int Yj;
        private static int Hj;
        
        private static int Xs;
        private static int Ys;
        private static int Hs;
        private static int Vs;
        private static float Ts;
        
        
        public static void Main(string[] args)
        {
            string[] tokens1 = Console.ReadLine().Split();
            Xj = int.Parse(tokens1[0]);
            Yj = int.Parse(tokens1[1]);
            Hj = int.Parse(tokens1[2]);
            
            string[] tokens2 = Console.ReadLine().Split();
            Xs = int.Parse(tokens2[0]);
            Ys = int.Parse(tokens2[1]);
            Hs = int.Parse(tokens2[2]);
            Vs = int.Parse(tokens2[3]);

            int S1 = Math.Abs(Xj - Xs);
            int S2 = Math.Abs(Yj - Ys);
            
            Ts = (S1 + S2 + Hs) / Vs;

            if (Hj < Ts)
            {
                Console.Write("YES");
            }

            else
            {
                Console.Write("NO");
            }
                
        }
        
    }
}