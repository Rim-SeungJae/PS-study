  #include<cstdio>
  #include<string>
  #include<algorithm>
  #include<iostream>

  using namespace std;

  int main()
  {
      string s, t;
      cin >> s >> t;
      bool isReversed = false;
      int l = 0, r = t.size() - 1;

      while(l <= r)
      {
          string sub = t.substr(l, r - l + 1);
          if(isReversed) reverse(sub.begin(), sub.end());
          if(s == sub)
          {
              printf("1");
              return 0;
          }
          if(isReversed)
          {
              if(t[l] == 'A')      { l++; }
              else if(t[l] == 'B') { l++; isReversed = !isReversed; }
              else break;
          }
          else
          {
              if(t[r] == 'A')      { r--; }
              else if(t[r] == 'B') { r--; isReversed = !isReversed; }
              else break;
          }
      }
      printf("0");
      return 0;
  }