const { LinkedList } = require("../2/linked-list.js");
const { BSTree } = require("./bst.js");

const listOfDepths = (tree) => {
  const depthMap = new Map();

  const process = (node, depth) => {
    const list = depthMap.get(depth);

    if (list) {
      list.insert(node.data);
    } else {
      depthMap.set(depth, new LinkedList([node.data]));
    }
  };

  const traverse = (node, depth = 0) => {
    if (!node) {
      return;
    }

    process(node, depth);
    traverse(node.left, depth + 1);
    traverse(node.right, depth + 1);
  };

  traverse(tree.head);
  return depthMap;
};

(() => {
  const test = new BSTree([5, 3, 8, 2, 6, 1, 7, 4, 9]);

  console.log(listOfDepths(test));
})();
