const powerSet = (arr = []) => {
  const ret = [[]];
  for (let i = 0; i < arr.length; i++) {
    const length = ret.length;
    for (let j = 0; j < length; j++) {
      ret.push([...ret[j], arr[i]]);
    }
  }

  return ret;
};

(() => {
  console.log(powerSet([1, 2, 3]));
})();
