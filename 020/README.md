# Problem 020 - 100! 의 자릿수를 모두 더하면? 
 
## 📝 문제 설명

n! 이라는 표기법은 n × (n − 1) × ... × 3 × 2 × 1을 뜻합니다.  
  
예를 들자면 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800 이 되는데,  
여기서 10!의 각 자릿수를 더해 보면 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27 입니다.  
  
100! 의 자릿수를 모두 더하면 얼마입니까?

## 🧠 배운 점

- 지난번 구현한 🔁 **문자열 곱셈(`string × int`) 로직**을 그대로 활용
- `factorial()` 함수는 `1`부터 `100`까지 순차적으로 곱하면서 문자열로 누적
- **한 자리씩 곱하고 carry 처리**를 통해 큰 정수도 정확하게 계산 가능
- 최종 결과는 문자열이므로, 각 자릿수를 하나씩 더해서 `digitSum()`으로 해결
- **문자열로 큰 수를 다루는 방식**은 정수형 오버플로 없이 유연하게 확장 가능
