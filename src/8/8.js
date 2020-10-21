const memo = new Map();

const permutationWithDupes = (str) => {
  if (str.length <= 1) {
    return [str];
  }

  if (memo.has(str)) {
    return memo.get(str);
  }

  const charToRemaining = new Map();

  str.split("").forEach((char, index) => {
    if (!charToRemaining.has(char)) {
      charToRemaining.set(
        char,
        str.slice(0, index) + str.slice(index + 1, str.length)
      );
    }
  });

  const ret = Array.from(charToRemaining.entries()).reduce(
    (acc, [char, remaining]) => {
      return [
        ...acc,
        ...permutationWithDupes(remaining).map((remPerm) => {
          return char + remPerm;
        }),
      ];
    },
    []
  );

  memo.set(str, ret);

  return ret;
};

(() => {
  console.time("permutationWithDupes");
  const result = permutationWithDupes("abbcdddefg");
  console.log(result, "\n", result.length);
  console.timeEnd("permutationWithDupes");
})();
