const { BSTree } = require("./bst");

// returns 3-tuple [ancestor, hasNode1AsDescendant, hasNode2AsDescendant]
const fca = (head, node1, node2) => {
  if (!head) {
    return [null, false, false];
  }

  const leftChild = fca(head.left, node1, node2);
  const rightChild = fca(head.right, node1, node2);

  if (leftChild[0]) {
    return [leftChild[0], true, true];
  }

  if (rightChild[0]) {
    return [rightChild[0], true, true];
  }

  const hasNode1 = head === node1 || rightChild[1] || leftChild[1];
  const hasNode2 = head === node2 || rightChild[2] || leftChild[2];
  const ret = [null, hasNode1, hasNode2];

  if (hasNode1 && hasNode2) {
    ret[0] = head;
  }

  return ret;
};

const firstCommonAncestor = (tree, node1, node2) => {
  return fca(tree.head, node1, node2)[0];
};

(() => {
  const test = new BSTree([5, 3, 7, 4, 8, 2, 6, 1, 9]);
  console.log(firstCommonAncestor(test, test.getNode(3), test.getNode(8)).data);
  console.log(firstCommonAncestor(test, test.getNode(6), test.getNode(9)).data);
  console.log(firstCommonAncestor(test, test.getNode(7), test.getNode(9)).data);
  console.log(firstCommonAncestor(test, test.getNode(7), {}));
})();
