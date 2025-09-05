/**
 * @param {number} num1
 * @param {number} num2
 * @return {number}
 */
var makeTheIntegerZero = function(n1, n2) {
    for (let op = 1; op <= 60; op++) {
            let rem = n1 - op * n2;
            if (rem < op) continue;
            let pop = rem.toString(2).split('1').length - 1;
            if (pop <= op && op <= rem) return op;
        }
        return -1;
};