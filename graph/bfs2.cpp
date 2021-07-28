/*
队列 Q 记录要处理的节点，vis数组来标记某个节点是否已经访问过。
d 数组记录某个点到起点的距离，可以得到起点到一个点的距离。
p 数组是记录从起点到这个点的最短路上的上一个点,可以方便地还原出起点到一个点的最短路径。
restore(x) 输出的是从起点到 x 这个点所经过的点。

开始的时候，我们把起点 s 以外的节点的 vis 值设为 0，意思是没有访问过。然后把起点 s 放入队列 Q 中。
之后，我们每次从队列 Q 中取出队首的点 u，把 u 相邻的所有点 v 标记为已经访问过了并放入队列 Q。
直到某一时刻，队列 Q 为空，这时 BFS 结束。

时间复杂度 O(n + m)
空间复杂度 O(n)（vis 数组和队列）
*/
void bfs(int u) {
  while (!Q.empty()) Q.pop();
  Q.push(u);
  vis[u] = 1;
  d[u] = 0;
  p[u] = -1;
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    for (int i = head[u]; i; i = e[i].x) {
      if (!vis[e[i].t]) {
        Q.push(e[i].t);
        vis[e[i].t] = 1;
        d[e[i].t] = d[u] + 1;
        p[e[i].t] = u;
      }
    }
  }
}
void restore(int x) {
  vector<int> res;
  for (int v = x; v != -1; v = p[v]) {
    res.push_back(v);
  }
  std::reverse(res.begin(), res.end());
  for (int i = 0; i < res.size(); ++i) printf("%d", res[i]);
  puts("");
}