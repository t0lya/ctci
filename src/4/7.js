const { Graph } = require("./graph.js");

const topSort = (graph) => {
  // INIT | PROCESSING | COMPLETE
  const nodeState = new Map();
  graph.nodes.forEach((_, key) => {
    nodeState.set(key, "INIT");
  });
  const ret = [];

  const dfs = (graph, node) => {
    nodeState.set(node, "PROCESSING");

    graph.nodes.get(node).forEach((adjNode) => {
      if (nodeState.get(adjNode) === "PROCESSING") {
        throw Error("Cycle detected");
      }

      if (nodeState.get(adjNode) === "INIT") {
        dfs(graph, adjNode);
      }
    });

    ret.unshift(node);

    nodeState.set(node, "COMPLETE");
  };

  try {
    graph.nodes.forEach((_, node) => {
      if (nodeState.get(node) === "INIT") {
        dfs(graph, node);
      }
    });
    return ret;
  } catch (error) {
    return error;
  }
};

(() => {
  const test = new Graph(null, true);
  test.addNodes(["a", "b", "c", "d", "e", "f"]);
  test.addEdges([
    ["a", "d"],
    ["f", "b"],
    ["b", "d"],
    ["f", "a"],
    ["d", "c"],
  ]);
  console.log(topSort(test));

  test.addEdge("c", "f");
  console.log(topSort(test));
})();
