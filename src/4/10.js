const { BSTree } = require("./bst.js");

const compareNodes = (n1, n2) => {
  if (n1 === null || n2 === null) {
    return n1 === n2;
  }

  if (n1.data === n2.data) {
    return compareNodes(n1.left, n2.left) && compareNodes(n1.right, n2.right);
  }

  return compareNodes(n1.left, n2) || compareNodes(n1.right, n2);
};

const checkSubtree = (t1, t2) => {
  return compareNodes(t1.head, t2.head);
};

(() => {
  const bigTree = new BSTree([5, 3, 7, 4, 6, 2, 8, 1, 9]);
  const smallTree = new BSTree([8, 9]);

  console.log(checkSubtree(bigTree, smallTree));
})();
