# Problem 026 - 1000 이하의 d 중에서 1/d 이 가장 긴 순환마디를 갖는 수는? 
 
## 📝 문제 설명
분자가 1인 분수를 단위분수라고 합니다. 분모가 2에서 10까지의 단위분수는 아래와 같습니다.  
[예시 이미지](https://euler.synap.co.kr/images/repetend.png)  
숫자 위에 찍힌 점은 순환마디를 나타내는데, 1/6의 경우 순환마디는 "6"으로 0.166666...처럼 6이 무한히 반복됨을 뜻합니다. 같은 식으로 1/7은 6자리의 순환마디(142857)를 가집니다.  
d 를 1000 이하의 정수라고 할 때, 단위분수 1/d 의 순환마디가 가장 긴 수는 무엇입니까?

## 🧠 배운 점
- 순환소수는 결국 **나눗셈에서 나머지가 반복**되는 순간 생김  
- 나머지를 계속 추적하면서, **같은 나머지가 다시 나오면 순환 시작**  
- 순환마디 길이는 `visited[cur]`로 이전 나머지를 기억하면서 **반복되기 전까지의 길이**  
- 불필요한 소수 계산 없이도 **나머지만 추적해서** 순환길이 구할 수 있음  
- `cur == 0`이면 순환 없이 나눗셈이 끝났다는 뜻이므로 예외 처리  
- 전체 탐색은 2~1000까지 진행, 순환 길이 가장 긴 수만 추적
