
If there is something you can cache , Dynamic Programming</br>
A simple [program](https://repl.it/@ChrisHuang2/DP#main.cpp) using Cache</br>
Using hash table to cache. Calculate only once if input parameters are the same.

<pre>
class cache{
  private:
    unordered_map<int,int> hash;
  public:
    int add80(int n)
    { 
      if(hash.find(n)==hash.end())
      {
        hash[n] = 80+n;
      }
      return hash[n];
    }
};
</pre>
Dynamic Programming = Divide & Conquer + Memorization</br>
List to check if the problem can be solved by DP
1. Can be divided into subproblem
2. Recursive Solution
3. Are there repetitive subproblems?
4. Memorize subproblems

Steps to do ([ref](https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.))
1. Find recusive relation
2. Recursive(top-down)
3. Recursive +memo (top-down)
4. Iterative + memo(bottom-up)
5. Iterative + N variables(bottom-up)



