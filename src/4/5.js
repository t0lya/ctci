const { BSTree } = require("./bst.js");

const isValidBST = (node, min = null, max = null) => {
  if (!node) return true;

  const validNode =
    (min === null || min <= node.data) && (max === null || node.data < max);

  return (
    validNode &&
    isValidBST(node.left, min, node.data) &&
    isValidBST(node.right, node.data, max)
  );
};

(() => {
  const test = new BSTree([5, 1, 9, 2, 8, 3, 7, 4, 6]);
  console.log(isValidBST(test));
})();
