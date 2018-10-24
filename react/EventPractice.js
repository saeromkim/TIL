import React, { Component } from 'react';

class EventPractice extends Component {

    state={
        message:'',
        username:''
    }

    // constructor(props){
    //     super(props);
    //     this.handleChange=this.handleChange.bind(this);;
    //     this.handleClick=this.handleClick.bind(this);
    // } 메소드가 this를 사용할 수 있도록 바인딩 해준다.

    handleChange=(e)=>{
        this.setState({
            [e.target.name]: e.target.value
        }); //[]안의 값을 key 값으로 사용한다. 
    }
    handleClick=()=>{
        alert(this.state.username+':'+this.state.message);
        this.setState({
            message:'',
            username:''
        })
    }
    handleKeyPress=(e)=>{
        if(e.key==='Enter'){
            this.handleClick();
        }
    }
    render() {
        return (
            <div>
                <h1>event practice</h1>
                <input
                    type="text"
                    name="message"
                    placeholder="input something"
                    value={this.state.message}
                    onChange={this.handleChange}
                ></input>
                <input 
                    type="text"
                    name="username"
                    placeholder="this is username"
                    value={this.state.username}
                    onChange={this.handleChange}
                    onKeyPress={this.handleKeyPress}
                    ></input>
                <button onClick={this.handleClick}>confirm</button>
            </div>
        );
    }
}

export default EventPractice;