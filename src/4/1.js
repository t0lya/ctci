const { Graph } = require("./graph.js");

const areConnected = (node1, node2, graph) => {
  let ret = false;
  !!graph.bfs(node1, (node) => {
    if (node === node2) {
      ret = true;
    }
  });

  return ret;
};

(() => {
  const graph = new Graph();
  graph.addNodes([0, 1, 2, 3, 4]);
  graph.addEdges([
    [0, 4],
    [0, 1],
    [1, 4],
    [1, 3],
  ]);
  graph.print();
  graph.bfs(0, console.log);

  console.log(areConnected(0, 3, graph));
  console.log(areConnected(0, 2, graph));
})();
