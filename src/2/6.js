const { LinkedList } = require("./linked-list.js");

const isPalindrome = (list) => {
  return isPalindromeRecursive(list.head, list.length);
};

const isPalindromeRecursive = (node, count, pair = { node: null }) => {
  if (count === 0) {
    pair.node = node;
    return true;
  }

  if (node && count === 1) {
    pair.node = node.next;
    return true;
  }

  const isMiddlePalindrome = isPalindromeRecursive(node.next, count - 2, pair);
  if (!isMiddlePalindrome) return false;
  const isPalindrome = node.data === pair.node.data && isMiddlePalindrome;
  pair.node = pair.node.next;

  return isPalindrome;
};

(() => {
  console.log(isPalindrome(new LinkedList([3, 6, 1, 1, 6, 3])));
  console.log(isPalindrome(new LinkedList([3, 6, 1, 7, 1, 6, 3])));
  console.log(isPalindrome(new LinkedList([3, 5])));
  console.log(isPalindrome(new LinkedList([3, 5, 2, 6, 9, 2, 5, 3])));
})();
