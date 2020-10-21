const waysToRepresent = (target) => {
  const DENOMS = [25, 10, 5];
  const memoByDenom = new Map();
  DENOMS.forEach((denom) => {
    memoByDenom.set(denom, new Map());
  });

  const _waysToRepresent = (target, denoms, index = 0) => {
    if (index === denoms.length) {
      return 1;
    }

    const memo = memoByDenom.get(denoms[index]);
    let ret = 0;
    let current = 0;

    while (current <= target) {
      const newTarget = target - current;

      if (memo.has(newTarget)) {
        ret += memo.get(newTarget);
      } else {
        const ways = _waysToRepresent(target - current, denoms, index + 1);
        memo.set(newTarget, ways);
        ret += ways;
      }

      current += denoms[index];
    }

    return ret;
  };

  return _waysToRepresent(target, DENOMS);
};

(() => {
  console.log(waysToRepresent(7));
  console.log(waysToRepresent(123));

  console.time("waysToRepresent");
  console.log(waysToRepresent(54321));
  console.timeEnd("waysToRepresent");
})();
