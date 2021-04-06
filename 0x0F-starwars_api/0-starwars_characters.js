#!/usr/bin/node
const req = require('request');
const film = process.argv[2];
const theUrl = 'https://swapi-api.hbtn.io/api/films/';

req.get({ url: theUrl + film }, async function (err, res, body) {
  if (err) {
    console.log('code: ' + res.statusCode);
  } else {
    const json = JSON.parse(body);
    for (const urlc of json.characters) {
      const code = await new Promise((resolve, reject) => {
        req.get({ url: urlc }, async function getname (err1, res1, body1) {
          if (err1) {
            console.log('code: ' + res1.statusCode);
          } else {
            const json1 = await JSON.parse(body1);
            // console.log(json1.name);
            resolve(await json1.name);
          }
        });
      });
      // console.log(urlc);
      console.log(code);
    }
  }
});
