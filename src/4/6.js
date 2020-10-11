const { BSTree } = require("./bst.js");

const getMinNode = (node) => {
  let current = node.right;

  while (current && current.left) {
    current = current.left;
  }

  return current;
};

const getSuccessorNode = (node) => {
  const minNode = getMinNode(node);

  if (minNode) {
    return minNode;
  } else {
    let parent = node.parent;
    let current = node;
    while (parent && parent.left !== current) {
      current = parent;
      parent = current.parent;
    }

    return parent;
  }
};

(() => {
  const test = new BSTree([5, 3, 7, 2, 8, 1, 9, 4, 6]);
  console.log(getSuccessorNode(test.head.left));
  console.log(getSuccessorNode(test.head.right.right.right));
})();
