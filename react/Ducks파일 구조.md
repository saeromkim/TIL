#### 1. Ducks파일 구조 (리액트를 다루는 기술 14.2(301p) 참고)
- 리덕스에서 사용하는 파일들은 `액션 타입`,`액션 생성 함수`, `리듀서` 이렇게 세 종류로 분리하여 관리한다.
- 파일들의 구조화에 정해진 방식은 없다.
- 이 세가지 파일을 한 파일에서 모듈화하여 관리하는 것이 `Ducks 파일 구조`다.

### 1-1. 예시 모듈
```javascript
//액션 타입
const CREATE='my-app/todos/CREATE';
const REMOVE='my-app/todos/REMOVE';

//액션 생성 함수
export const create = (todo) => ({
  type: CREATE,
  todo,
});

export const remove = (todo) => ({
  type: REMOVE,
  id,
});

const initialState = {
  //초기 상태
}

//리듀서
export default function reducer(state = initialState, action) {
  switch (action.type) {
    //리듀서 관련 코드..
  }
}
```
### 1-2. 규칙
- `export default`를 이용하여 리듀서를 내보내야 한다.
- `export`를 이용하여 액션 생성 함수를 내보내야 한다.
- 액션 타입 이름은 npm-module-or-app/reducer/ACTION_TYPE 형식으로 만들어야 한다. (예: counter/INCREMENT)
- 외부 리듀서에서 모듈의 액션 타입이 필요할 때는 액션타입을 내보내도 된다.

