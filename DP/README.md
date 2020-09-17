
If there is something you can cache , Dynamic Programming</br>
A simple [DP](https://repl.it/@ChrisHuang2/DP#main.cpp) using Cache</br>
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
        cout<<"cal"<<endl;
        hash[n] = 80+n;
      }
      return hash[n];
    }
};
</pre>
