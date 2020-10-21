const memo = new Map();

const countEval = (str, eval) => {
  if (str.length === 1) {
    return (eval && str === "1") || (!eval && str === "0") ? 1 : 0;
  }

  if (memo.has(str + eval)) {
    return memo.get(str + eval);
  }

  let count = 0;
  for (let i = 1; i < str.length; i += 2) {
    const operator = str[i];
    const left = str.slice(0, i);
    const right = str.slice(i + 1, str.length);

    switch (operator) {
      case "&":
        count += eval
          ? countEval(left, true) * countEval(right, true)
          : countEval(left, false) * countEval(right, true) +
            countEval(left, true) * countEval(right, false) +
            countEval(left, false) * countEval(right, false);
        break;
      case "|":
        count += eval
          ? countEval(left, false) * countEval(right, true) +
            countEval(left, true) * countEval(right, false) +
            countEval(left, true) * countEval(right, true)
          : countEval(left, false) * countEval(right, false);
        break;
      case "^":
        count += eval
          ? countEval(left, false) * countEval(right, true) +
            countEval(left, true) * countEval(right, false)
          : countEval(left, true) * countEval(right, true) +
            countEval(left, false) * countEval(right, false);
        break;
    }
  }

  memo.set(str + eval, count);
  return count;
};

(() => {
  console.log(countEval("0&0&0&1^1|0", true));

  console.time("countEval");
  console.log(countEval("1^0|0|1&0&1^1|1|0&1|1&0&1&0&1^1|0", false));
  console.timeEnd("countEval");
})();
