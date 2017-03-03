'use strict'

// перевод числа в 10 систему счисления

let anumbers = [0,1,2,3,4,5,6,7,8,9,'a','b','c','d','e','f'];

function translateToDecimal(translatedNumStr, oldNumeric) {
    var decimalResult = 0;

    for (let i = 0; i < translatedNumStr.length; i++) {

        let j = translatedNumStr[translatedNumStr.length - i - 1];
        for (var k = 0; k < anumbers.length; k++)
            if (anumbers[k] == j)
                break;

        decimalResult += k * Math.pow(oldNumeric, i); // k - индекс массива (число соответ. символу строки)
    }

    return decimalResult;
}


function translateFromDecimal(decimalToTranslate, numericTo) {
    let result = []; 

    while (decimalToTranslate > numericTo) {
        let module = (decimalToTranslate % numericTo)

        result.push( anumbers[module] ); 
        decimalToTranslate = decimalToTranslate / numericTo;
        decimalToTranslate = Math.floor(decimalToTranslate);
    }

    result.push( anumbers[decimalToTranslate]); // push from anumbers
    result.reverse();

    return result;
}

function translateNumeralSystem(translatedNumStr, oldNumeral, newNumeral) {
    let inDecimal = translateToDecimal(translatedNumStr, oldNumeral);
    if (newNumeral == 10)
        return inDecimal;
    return translateFromDecimal(inDecimal, newNumeral);
}

let a = '125';

let aArr = a.split('');

console.log( translateNumeralSystem(aArr, 7, 12) );

// console.log( translateToDecimal(aArr, 16) );


/*
for (let k = 0; k < numbers.length; k++)
    if (numbers[k] == j)
        break;

decimalResult += k * Math.pow(oldNumeric, i); // k - индекс массива (число соответ. символу строки)
*/

/*
         // let j = translatedNumStr[translatedNumStr.length - i - 1];
        
        // decimalResult += +numbers[j] * Math.pow(oldNumeric, i); // 16 == numeric system
*/
