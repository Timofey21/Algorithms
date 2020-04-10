using System;
using System.IO;

namespace zachet
{
    internal class Program
    {
        private static int n;
        private static int sum;
        
      
        
        
        public static void Main(string[] args)
        {

            try
            {
                using (StreamReader reader = new StreamReader("input.txt"))
                {
                    string[] tokens = reader.ReadLine().Split();
                    n = int.Parse(tokens[0]);
            
            
                    string [] score = reader.ReadLine().Split();
            
                    string plus = reader.ReadLine();

                    sum = 0;

                    for (int i = 0; i < n; i++)
                    {
                        if (plus[i] == '+')
                        {
                            sum += int.Parse(score[i]);
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
                    writer.Write(sum);
                }
                
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
            
        
         
        }
        
    }
