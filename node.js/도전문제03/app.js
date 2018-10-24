//Express 기본 모듈
var express=require('express'),
    http=require('http'),
    path=require('path');
//Express의 미들웨어
var bodyParser=require('body-parser'),
    static=require('serve-static');
//파일 업로드용 미들웨어
// var multer=require('multer');
// var fs=require('fs');

var app=express();

app.set('port',process.env.PORT||3030);

app.use(bodyParser.urlencoded({extended:false}));

app.use(bodyParser.json());

app.use('/public',static(path.join(__dirname,'public')));

var router=express.Router();

router.route('/memo').post(function(req,res){
    console.log('/memo 호출됨');

    var paramName=req.body.name||req.query.name;
    var paramDate=req.body.date||req.query.date;
    var paramContent=req.body.content||req.query.content;

    res.writeHead('200', {'Content-Type':'text/html;charset=utf8'});
    res.write('<h1>나의 메모</h1>');
    res.write('<p>메모가 저장되었습니다.</p>');
    res.write('<div><p>Param Name : ' + paramName + '</p></div>');
    res.write('<div><p>Param Content : ' + paramContent + '</p></div>');
    res.write('<a href="/public/memo.html"><input type="submit" value="다시작성" name=""></a>');
    res.end();
});

app.use('/',router);

http.createServer(app).listen(3030,function(){
    console.log('3030번 포트에서 서버가 시작됨');
});
