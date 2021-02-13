function getvals(passport,fields){
  for(let field of fields){
  for(let i in passport){
    if(passport[i][1]==field){
      let value = (field=="byr"|| field=="iyr"||field=="eyr") ? Number(passport[i][2]):passport[i][2];
      Object.defineProperty(passport,field,{
        value:value
      });
    }
  }
}
return passport;
}
function check(passport){
  try{
  if (passport.byr<1920 || passport.byr>2002){
    //console.log("check1");
    return 0;
  }
  else if(passport.iyr<2010 || passport.byr>2030){
    //console.log("check2");

    return 0
  }
  else if(passport.eyr<2020 || passport.eyr>2030){
    //console.log("check3");

    return 0;
  }
  var hgt_unit=passport.hgt.slice(-2,);
  var hgt_val=passport.hgt.slice(0,-2);
  //console.log("hgt_unit:"+hgt_unit);


  if(hgt_unit=="cm" && (hgt_val<150 || hgt_val>193)){
    //console.log("check4");
    return 0;
  }
  else if(hgt_unit=="in" && (hgt_val<59 || hgt_val>76)){
    //console.log("check5");
    return 0;
  }
  else if(hgt_unit!="cm" && hgt_unit!="in"){
    //console.log("check6");
    return 0;
  }
  else if(!passport.hcl.match(/#[\w]{6}/g)){
    //console.log("check7");
    return 0;
  }
  else if(!passport.ecl.match(/(amb)|(blu)|(brn)|(gry)|(grn)|(hzl)|(oth)/g)){
    //console.log("check8");
    return 0;
  }
  else if(passport.pid.length!=9){
    //console.log("check9");
    return 0;
  }
} catch(error){
  //console.log(error);
  return 0;
}
  return 1;
}
var fields = ["byr","iyr","eyr","hgt","hcl","ecl","pid"];
var doc = document.body.innerText.split("\n\n");
var passports = [];
var count =0;
for(let i in doc){
  var passport_arr = [...doc[i].matchAll(/(\w+):([\w#]+)/g)];
  var passport=getvals(passport_arr,fields);
  var status = check(passport);
  ////console.log(passport+" "+status);
  if(status){
    count++;
  }
}
console.log(count);
