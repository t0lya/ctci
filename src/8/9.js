const generateParens = (pairs) => {
  let ret = [[0, 0, ""]];
  for (let i = 0; i < pairs * 2; i++) {
    const newRet = [];
    ret.forEach(([used, sum, str]) => {
      used < pairs &&
        sum < pairs &&
        newRet.push([used + 1, sum + 1, str + "("]);
      sum > 0 && newRet.push([used, sum - 1, str + ")"]);
    });
    ret = newRet;
  }

  return ret.map((item) => item[2]);
};

const printParens = (pairs) => {
  if (pairs < 1) {
    return;
  }

  console.log(generateParens(pairs));
};

(() => {
  printParens(2);
  printParens(3);
  printParens(5);
})();
