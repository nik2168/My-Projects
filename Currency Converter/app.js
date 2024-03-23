 // evt.preventDefault();

let baseUrl = "https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies"



let dropdowns = document.querySelectorAll(".form select")
let box = document.querySelector(".form input")
let btn = document.querySelector(".btn")
let from = document.querySelector("#from")
let to = document.querySelector("#to")
let result = document.querySelector("#result")


 for(let select of dropdowns){
    for( opt in countryList){
        let newOption = document.createElement("option")
        newOption.innerText = opt
        newOption.value = countryList[opt]
        if(select.name === "from" && opt === "USD"){
            newOption.selected = true;
        }else if(select.name === "to" && opt === "INR"){
            newOption.selected = true;
        }
        select.append(newOption)
    } 
    select.addEventListener("change", (evt) => {
         updateFlag(evt.target)
    })
}


// Update Flag
const updateFlag = (ele) => {
    let opt = ele.value
    console.log(ele)
    let image = ele.parentElement.parentElement.querySelector("img")
    image.src = `https://flagsapi.com/${opt}/flat/64.png`
}


btn.addEventListener("click", async (evt) => {
    evt.preventDefault()
    let box = document.querySelector(".box")
    let amountval = Number(box.value)
    if(!amountval || amountval < 0) {
        box.value = 1
         amountval = 1
    }
    let f =  (from[from.selectedIndex].innerText).toLowerCase()
    let t = (to[to.selectedIndex].innerText).toLowerCase()
    let url = `${baseUrl}/${f}.json`
    let response = await fetch(url)
    let data = await response.json()
    result.innerText = `${amountval * data[f][t]}`
 })




















    //   async function  response(){
    //    let data = await fetch("https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies/usd.json")
    //    let res = await data.json()
    //    console.log(res.usd.inr)
    // }

    // let ans = response()
    // console.log(ans)

          
       
       //    let response =  fetch("https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies/usd.json")
       //     response.then((res) => {
       //         return res.json()
       //     }).then((ans) => {
       //         console.log(ans.usd.inr)
       //     })         