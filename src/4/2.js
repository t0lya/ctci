const { BSTree } = require("./bst.js");

const insertSorted = (arr, bst) => {
  if (arr.length === 0) {
    return;
  }

  if (arr.length === 1) {
    bst.insert(arr[0]);
    return;
  }

  const mid = Math.floor(arr.length / 2);
  bst.insert(arr[mid]);
  insertSorted(arr.slice(0, mid), bst);
  mid < arr.length && insertSorted(arr.slice(mid + 1, arr.length), bst);
};

(() => {
  const bst = new BSTree();
  insertSorted([1, 2, 3, 4, 5, 6, 7, 8], bst);
  console.log(bst.head);
  console.log("height: ", bst.height());
})();
