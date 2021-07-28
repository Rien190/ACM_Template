/*
宽度优先，就是每次都尝试访问同一层的节点。 如果同一层都访问完了，再访问下一层。
这样做的结果是，BFS 算法找到的路径是从起点开始的最短合法路径。换言之，这条路所包含的边数最小。
在 BFS 结束时，每个节点都是通过从起点到该点的最短路径访问的。
*/
bfs(s) {
  q = new queue()
  q.push(s), visited[s] = true
  while (!q.empty()) {
    u = q.pop()
    for each edge(u, v) {
      if (!visited[v]) {
        q.push(v)
        visited[v] = true
      }
    }
  }
}