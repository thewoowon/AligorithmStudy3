using System;
using System.Collections.Generic;

namespace Matrix
{
	class Program
	{
		static void Main(string[] args)
		{
			Solution solution = new Solution();
			int[,] dummy = { {2,2,5,5 } };
			solution.solution(5,5,dummy);
		}


	public partial class Solution
		{
			public int[] solution(int rows, int columns, int[,] queries)
			{
				int[] answer = new int[] { };
				List<int> list = new List<int>();

				for (int i = 0; i < rows * columns; i++)
				{
					list.Add(i + 1); // 초기화
				}

				int pre = 0;
				int max = 0;

				//배열에 다 채워 놓는다?
				for (int i = 0; i < queries.GetLength(0); i++)
				{
					// ((행-1) * columns) + 열-1 -> 위치의 인덱스
					int s = ((queries[i,0] - 1) * columns) + queries[i, 1] - 1;
					int wGap = queries[i, 2] - queries[i,0];
					int hGap = queries[i, 3] - queries[i, 1];
					int whole = ((rows + columns) * 2) - 4;
					int count = 0;

					for (int j = 0; j < wGap; j++)
					{
						if (pre == 0)
						{
							pre = list[s];
							max = list[s];
							s += 1;
						}
						else
						{
							if (pre < list[s])
							{
								max = list[s];
							}
							int temp = list[s];
							list[s] = pre;
							pre = temp;
							s += 1;
						}
					}
					for (int k = 0; k < hGap; k++)
					{
						if (pre == 0)
						{
							pre = list[s];
							max = list[s];
							s += hGap;
						}
						else
						{
							if (pre < list[s])
							{
								max = list[s];
							}
							int temp = list[s];
							list[s] = pre;
							pre = temp;
							s += hGap;
						}
					}
					for (int l = 0; l < wGap; l++)
					{
						if (pre == 0)
						{
							pre = list[s];
							max = list[s];
							s -= 1;
						}
						else
						{
							if (pre < list[s])
							{
								max = list[s];
							}
							int temp = list[s];
							list[s] = pre;
							pre = temp;
							s -= 1;
						}
					}
					for (int m = 0; m < hGap; m++)
					{
						if (pre == 0)
						{
							pre = list[s];
							max = list[s];
							s -= hGap;
						}
						else
						{
							if (pre < list[s])
							{
								max = list[s];
							}
							int temp = list[s];
							list[s] = pre;
							pre = temp;
							s -= hGap;
						}
					}
				}


				for (int i = 0; i < list.Count; i++)
				{
					Console.Write(list[i]);
					Console.Write("   ");
					if (i % rows == 4)
					{
						Console.WriteLine();
					}
				}
				return answer;
			}
		}
	}
}
