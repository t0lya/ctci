const memo = new Map();

const _tallestStack = (boxes, topBox = null, index = 0, height = 0) => {
  if (index === boxes.length) {
    return height;
  }

  const current = boxes[index];

  const heightWithoutCurrentBox = _tallestStack(
    boxes,
    topBox,
    index + 1,
    height
  );

  if (
    topBox &&
    (current[0] >= topBox[0] ||
      current[1] >= topBox[1] ||
      current[2] >= topBox[2])
  ) {
    return heightWithoutCurrentBox;
  }

  let heightWithCurrentBox = 0;
  if (memo.has(index)) {
    heightWithCurrentBox = height + memo.get(index);
  } else {
    heightWithCurrentBox = _tallestStack(
      boxes,
      current,
      index + 1,
      height + current[0]
    );
    memo.set(index, heightWithCurrentBox - height);
  }

  return Math.max(heightWithCurrentBox, heightWithoutCurrentBox);
};

const tallestStack = (boxes) => {
  return _tallestStack(
    boxes.sort((a, b) => {
      return a[0] > b[0] ? -1 : 1;
    })
  );
};

(() => {
  const n = 5000;
  const test = Array(n)
    .fill(null)
    .map(() => {
      return [
        Math.floor(Math.random() * n),
        Math.floor(Math.random() * n),
        Math.floor(Math.random() * n),
      ];
    });

  console.time("tallestStack");
  const results = tallestStack(test);
  console.timeEnd("tallestStack");

  console.log(results);
})();
