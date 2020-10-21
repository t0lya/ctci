const GRID_SIZE = 8;

const checkValid = (arranged, col) => {
  if (arranged.includes(col)) {
    return false;
  }

  const row = arranged.length;
  for (let aRow = 0; aRow < arranged.length; aRow++) {
    const aCol = arranged[aRow];

    if (Math.abs(aCol - col) === Math.abs(aRow - row)) {
      return false;
    }
  }

  return true;
};

const arrangeQueens = (arranged = [], remaining = GRID_SIZE) => {
  if (remaining === 0) {
    return [arranged];
  }

  return [...Array(GRID_SIZE).keys()]
    .filter((col) => checkValid(arranged, col))
    .map((col) => {
      return arrangeQueens([...arranged, col], remaining - 1);
    })
    .flat();
};

(() => {
  const results = arrangeQueens();
  console.log(results, "\n", results.length);
})();
