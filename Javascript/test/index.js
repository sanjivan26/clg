//To print
//console.log(`Hello`);

//popup
//window.alert(`This is an alert`);

/*Edits header and p
document.getElementById("h1").textContent=`Hello`;
document.getElementById("p1").textContent=`lmao`;*/

/*let fullName = "Bro Code";
let age = 25;
let isStudent = false;

console.log(typeof gpa);
document.getElementById("p1").textContent = `Your name is ${fullName}`;
document.getElementById("p2").textContent = `You are ${age} years old`;
document.getElementById("p3").textContent = `Enrolled: ${isStudent}`;
*/

/*
    operator precedence
    1. parenthesis ()
    2. exponents
    3. multiplication & division & modulo
    4. addition & subtraction
*/

// How to accept user input

// 1. EASY WAY = window prompt
// 2. PROFESSIONAL WAY = HTML textbox

// ------------------------ EASY WAY ------------------------
// let username = window.prompt("What's your username?");

// console.log(username);

// -------------------- PROFESSIONAL WAY --------------------
let username;

document.getElementById("mySubmit").onclick = function()
{
    username = document.getElementById("text").value;
    console.log(username);
    document.getElementById("h1").textContent = `Hello ${username}`
}