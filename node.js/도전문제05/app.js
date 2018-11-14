//Express 기본 모듈
var express=require('express'),
    http=require('http'),
    path=require('path');
//Express의 미들웨어
var bodyParser=require('body-parser'),
    static=require('serve-static');

var expressErrorHandler = require('express-error-handler');    

var mongoose=require('mongoose');

var app=express();

app.set('port',process.env.PORT||3000);

app.use(bodyParser.urlencoded({extended:false}));

app.use(bodyParser.json());

app.use('/public',static(path.join(__dirname,'public')));

var MongoClient =require('mongodb').MongoClient;

var database;

var UserSchema;

var UserModel;

function connectDB(){
    var databaseUrl='mongodb://localhost:27017/local';

    console.log('tying db connection');
    mongoose.Promise=global.Promise;
    mongoose.connect(databaseUrl);
    database=mongoose.connection;

    database.on('error', console.error.bind(console,'mongoose error'));
    database.on('open',function(){
        console.log('database connected'+databaseUrl);

        createUserSchema();
    });

    database.on('disconnected',function(){
        console.log('db disconnected');
        setInterval(connectDB,5000);
    });
}

function createUserSchema(){
    UserSchema=mongoose.Schema({
        id:{type:String, require:true, unique:true, 'default':' '},
        name:{type:String, 'default':' '},
        date:{type:String, 'default':' '},
        content:{type:String, 'default':' '}
    });

    console.log('UserSchema defined');

    UserModel=mongoose.model("memo1",UserSchema);
    console.log('db memo1 defined');
}

var router=express.Router();

router.route('/memo').post(function(req,res){
    console.log('/memo 호출됨');

    var paramName=req.body.name||req.query.name;
    var paramDate=req.body.date||req.query.date;
    var paramContent=req.body.content||req.query.content;

    if(database){
        addMemo(database, paramName, paramDate, paramContent, function(err, addedMemo){
            if(err){
                console.error('메모 저장 중 에러 발생 : ' + err.stack);
                
                res.writeHead('200', {'Content-Type':'text/html;charset=utf8'});
				res.write('<h2>메모 저장 중 에러 발생</h2>');
                res.write('<p>' + err.stack + '</p>');
				res.end();
                
                return;
            }

            if(addedMemo){
                console.dir(addedMemo);

                res.writeHead('200', {'Content-Type':'text/html;charset=utf8'});
                res.write('<h1>나의 메모</h1>');
                res.write('<p>메모가 저장되었습니다.</p>');
                res.write('<div><p>Param Name : ' + paramName + '</p></div>');
                res.write('<div><p>Param Content : ' + paramContent + '</p></div>');
                res.write('<a href="/public/memo.html"><input type="submit" value="다시작성" name=""></a>');
                res.end();
            }else{
                res.writeHead('200', {'Content-Type':'text/html;charset=utf8'});
                res.write('<h1>메모 추가 실패</h1>');
                res.end();
            }
        });  
    }else{
        res.writeHead('200', {'Content-Type':'text/html;charset=utf8'});
		res.write('<h2>데이터베이스 연결 실패</h2>');
		res.end();
    }

   
});

app.use('/',router);

var addMemo=function(database,id,name,date,content){
    console.log('addMemo called');

    var memo=new UserModel({
        "id":id,
        "name":name,
        "date":date,
        "content":content
    });

    memo.save(function(err,addedMemo){
        if(err){
            callback(err, null);
            return;
        }
        console.log("memo added");
        callback(null,addedMemo);
    });
};

var errorHandler=expressErrorHandler({
    static:{
        '404':'./public/404.html'
    }
});

app.use(expressErrorHandler.httpError(404));
app.use(errorHandler);

http.createServer(app).listen(3000,function(){
    console.log('서버가 시작되었습니다. 포트 : ' + app.get('port'));

    connectDB();
});
