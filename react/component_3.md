#### 리액트를 다루는 기술 2장
- jsx는 html과 비슷하게 사용할 수 있지만 조금 다르다.
- create-react-app을 사용하면 개발환경을 따로 구축할 필요없이 바로 실습을 할 수 있다.
- cmd창에서 `npm start` 또는 `yarn start`를 하면 3000번 포트로 웹서버가 만들어지고 렌더링 결과를 실시간으로 확인가능.

#### 리액트를 다루는 기술 3장 실습
- props는 해당 컴포넌트를 불러와서 사용하는 부모컴포넌트에서 값을 설정하고 렌더링과 초기값 설정과 검사 등은 해당 컴포넌트에서 한다.  
- state를 사용하면 부모컴포넌트가 아닌 해당 컴포넌트에서 값을 설정하고 업데이트를 할 수 있다.

#### App.js
```
import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';
import MyComponent from './MyComponent';

class App extends Component {
  render(){
    const text="어썸";
    const condition=true;

    return(
      <MyComponent name="React" age={3}></MyComponent>
      )
  }
}

export default App;
```
#### MyComponents.js
```
import React, { Component } from 'react';
import PropTypes from 'prop-types';

class MyComponent extends Component {
    static defaultProps={
        name: 'defaultname'
    }
    // constructor(props){
    //     super(props);
    //     this.state={
    //         number:0
    //     }
    // }
    state={
        number:0
    }
    render() {
        return (
            <div>
                <p>Hi, My name is {this.props.name}.</p>
                <p>and I'm {this.props.age} years old.</p>
                <p>number:{this.state.number}</p>
                <button onClick={()=>{
                    this.setState({
                        number: this.state.number+1
                    })
                }}>plus</button>
            </div>
        )
    }
}

MyComponent.propTypes={
    name: PropTypes.string,
    age: PropTypes.number.isRequired
}


export default MyComponent;

```
