class Graph {
  constructor(adjacencyList, directed) {
    this.nodes = adjacencyList || new Map();
    this.directed = directed || false;
  }

  addEdge(src, dest) {
    this.nodes.get(src).push(dest);
    if (!this.directed) {
      this.nodes.get(dest).push(src);
    }
  }

  addEdges(edges) {
    edges.forEach(([src, dest]) => {
      this.addEdge(src, dest);
    });
  }

  addNode(node) {
    this.nodes.set(node, []);
  }

  addNodes(nodes) {
    nodes.forEach((node) => {
      this.addNode(node);
    });
  }

  _traverse(node, processNode, type) {
    const discoveredMap = new Map();
    this.nodes.forEach((node) => {
      discoveredMap.set(node, false);
    });
    discoveredMap.set(node, true);

    const queue = [node];

    while (queue.length > 0) {
      const nodeToCheck = type === "bfs" ? queue.shift() : queue.pop();
      processNode && processNode(nodeToCheck);
      this.nodes
        .get(nodeToCheck)
        .filter((adjNode) => !discoveredMap.get(adjNode))
        .forEach((undiscoveredNode) => {
          discoveredMap.set(undiscoveredNode, true);
          queue.push(undiscoveredNode);
        });
    }
  }

  dfs(node, processNode) {
    this._traverse(node, processNode, "dfs");
  }

  bfs(node, processNode) {
    this._traverse(node, processNode, "bfs");
  }

  print() {
    this.nodes.forEach((adjNodes, node) => {
      console.log(node, adjNodes);
    });
  }
}

module.exports = { Graph };
