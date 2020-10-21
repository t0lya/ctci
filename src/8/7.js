const memo = new Map();

const permutationWithoutDupes = (str) => {
  if (str.length <= 1) {
    return [str];
  }

  if (memo.has(str)) {
    return memo.get(str);
  }

  const ret = str.split("").reduce((acc, char, index) => {
    const remaining = str.slice(0, index) + str.slice(index + 1, str.length);

    return [
      ...acc,
      ...permutationWithoutDupes(remaining).map((remPerm) => {
        return char + remPerm;
      }),
    ];
  }, []);

  memo.set(str, ret);

  return ret;
};

(() => {
  console.time("permutationWithoutDupes");
  const result = permutationWithoutDupes("abdefghijk");
  console.log(result, "\n", result.length);
  console.timeEnd("permutationWithoutDupes");
})();
