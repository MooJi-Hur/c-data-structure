### 전위 연산자, 후위 연산자
- 할당을 할 때 값에 차이가 있음
    - `++i` : 증가한 값이 곧 반환 값
        ```c
        int preIncrement(int i) {
            i = i + 1;
            return i;
        }
        ```
    - `i++` : 반환 값과 증가하는 값을 별개로 관리 
        - `count = count++;`를 실행할 경우, count 값은 변하지 않음
        ```c
        int postIncrement(int i) {
            int temp = i;
            i = i + 1;
            return temp;
        }
        ```
