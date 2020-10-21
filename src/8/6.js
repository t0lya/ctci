const moveTower = (src, dest, amountOfDiscs = 1, temp = null) => {
  if (amountOfDiscs === 1) {
    dest.push(src.pop());
    return;
  }

  moveTower(src, temp, amountOfDiscs - 1, dest);
  moveTower(src, dest, 1);
  moveTower(temp, dest, amountOfDiscs - 1, src);
};

(() => {
  const stack1 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
  const stack2 = [];
  const stack3 = [];

  moveTower(stack1, stack3, stack1.length, stack2);
  console.log(stack3);
})();
