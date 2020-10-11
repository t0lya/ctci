const { BSTree } = require("./bst.js");

const treeHeight = (node) => {
  if (!node) return 0;

  const leftHeight = treeHeight(node.left);
  if (leftHeight === false) return false;

  const rightHeight = treeHeight(node.right);
  if (rightHeight === false) return false;

  if (Math.abs(rightHeight - leftHeight) > 1) {
    return false;
  }

  return Math.max(leftHeight, rightHeight) + 1;
};

const isBalancedTree = (tree) => {
  return treeHeight(tree.head) !== false;
};

(() => {
  const test = new BSTree([5, 3, 8, 2, 6, 1, 7, 4, 9]);
  console.log(test);
  console.log(isBalancedTree(test));

  const test2 = new BSTree([1, 2, 4]);
  console.log(test2);
  console.log(isBalancedTree(test2));
})();
