const { Tree } = require("./tree.js");

const pathsWithSum = (head, sum, mustIncludeHead = false) => {
  if (!head) {
    return 0;
  }

  const ret =
    (head.data === sum ? 1 : 0) +
    (mustIncludeHead
      ? 0
      : pathsWithSum(head.left, sum) + pathsWithSum(head.right, sum)) +
    pathsWithSum(head.left, sum - head.data, true) +
    pathsWithSum(head.right, sum - head.data, true);

  return ret;
};

(() => {
  const test = new Tree(10);
  test.insert(5, [0]);
  test.insert(-3, [1]);
  test.insert(3, [0, 0]);
  test.insert(3, [0, 0]);
  test.insert(2, [0, 1]);
  test.insert(1, [0, 1, 1]);
  test.insert(-2, [0, 0, 1]);
  test.insert(-3, [1, 1]);
  test.insert(11, [1, 1, 1]);
  test.insert(8, [1, 1, 1, 1]);
  test.insert(-8, [1, 1, 1, 1, 1]);

  console.log(pathsWithSum(test.head, 8));
})();
