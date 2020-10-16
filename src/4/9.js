const { BSTree } = require("./bst.js");

const weave = (arr1, arr2) => {
  if (arr1.length === 0 && arr2.length === 0) {
    return [];
  }

  if (arr1.length === 0) {
    return [arr2];
  }

  if (arr2.length === 0) {
    return [arr1];
  }

  const ret1 = weave(arr1.slice(1, arr1.length), arr2).map((result) => {
    return [arr1[0], ...result];
  });
  const ret2 = weave(arr1, arr2.slice(1, arr2.length)).map((result) => {
    return [arr2[0], ...result];
  });

  return [...ret1, ...ret2];
};

const bstSequences = (head) => {
  if (head.left === null && head.right === null) {
    return [[head.data]];
  }

  if (head.left === null) {
    return bstSequences(head.right).map((seq) => [head.data, ...seq]);
  }

  if (head.right === null) {
    return bstSequences(head.left).map((seq) => [head.data, ...seq]);
  }

  const leftSequences = bstSequences(head.left);
  const rightSequences = bstSequences(head.right);

  return leftSequences
    .reduce((acc, leftSeq) => {
      return [
        ...acc,
        ...rightSequences
          .map((rightSeq) => {
            return weave(leftSeq, rightSeq);
          })
          .flat(),
      ];
    }, [])
    .map((seq) => {
      return [head.data, ...seq];
    });
};

(() => {
  const test = new BSTree([2, 1, 3]);
  console.log(bstSequences(test.head));

  const test2 = new BSTree([3, 2, 4, 1, 5]);
  console.log(bstSequences(test2.head));
})();
