using System;
using System.IO;
using System.Collections.Generic;

namespace zachet
{
    internal class Program
    {
        private static int n;
        private static int[,] arr;
        private static int max;
        private static int maxi;
        private static int maxj;
        
        
        
        public static void Main(string[] args)
        {

            try
            {
                using (StreamReader reader = new StreamReader("input.txt"))
                {
                    string[] tokens = reader.ReadLine().Split();
                    n = int.Parse(tokens[0]);
            
                    arr = new int[n,n];

                    for (int i = 0; i < n; i++)
                    {
                        tokens = reader.ReadLine().Split();
                        for (int j = 0; j < n; j++)
                        {
                            arr[i, j] = int.Parse(tokens[j]);
                        }
                            
                        
                    }

                    max = 0;
                    maxi = 0;
                    maxj = 0;

                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {

                            if (i == n - 1 && j == n - 1) break;
                            if (i == n - 1)
                            {
                                maxj = Math.Abs(arr[i, j] - arr[i, j + 1]);
                                if (maxj > max) max = maxj;
                                continue;
                                
                            }

                            if (j == n - 1)
                            {
                                maxi = Math.Abs(arr[i, j] - arr[i + 1, j]);
                                if (maxi > max) max = maxi;
                                continue;
                            }
                            maxi = Math.Abs(arr[i, j] - arr[i + 1, j]);
                            maxj = Math.Abs(arr[i, j] - arr[i, j + 1]);

                            if (maxi > max) max = maxi;
                            if (maxj > max) max = maxj;
                        }
                        
                    }


                    

                }
                
            }
            catch (Exception e) {
                Console.WriteLine(e.Message);
            }

            

            try
            {
                using (StreamWriter writer = new StreamWriter("output.txt"))
                {
                    writer.Write(max);
                }
                
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
            
        
         
        }
        
    }
