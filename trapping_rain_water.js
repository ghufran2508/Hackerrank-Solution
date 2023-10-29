// 42. Trapping Rain Water
// Hard
// 29.6K
// 427
// Companies

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.





// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.


// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

 

// Constraints:

//     n == height.length
//     1 <= n <= 2 * 104
//     0 <= height[i] <= 105

/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(arr) {
    if (arr.length < 2) return 0;
    let count = 0;
    let i = 0;
    while(arr[i] < arr[i+1]) i++;
    let end = arr.length-1;
    while(arr[end] < arr[end-1]) end--;

    for (; i < end; i++) {
        let index = i + 1;
        let rightBoundary = index;

        while (arr[i] > arr[index] && index < arr.length) {
            if (arr[rightBoundary] <= arr[index]) {
                rightBoundary = index;
            }
            index++;
        }
        if(index < arr.length) {rightBoundary = index;}
        
        let min = Math.min(arr[i], arr[rightBoundary]);

        for(let j = i+1; j < rightBoundary; j++) {
            count += (min - arr[j]);
        }
        {i = rightBoundary-1;}
    }
    return count;
};

console.log(trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]));
console.log(trap([4, 2, 0, 3, 2, 5]));
console.log(trap([4,2,3]));
console.log(trap([1,0,1,4,0,3,0,1]));