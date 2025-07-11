# Problem 027 - 연속되는 n에 대해 가장 많은 소수를 만들어내는 이차식 
 
## 📝 문제 설명  
오일러는 다음과 같은 멋진 이차식을 제시했습니다.  
n² + n + 41  
이 식의 n에다 0부터 39 사이의 수를 넣으면, 그 결과는 모두 소수가 됩니다.  
하지만 n = 40일 때의 값 40² + 40 + 41 은 40×(40 + 1) + 41 이므로 41로 나누어지고, n = 41일 때 역시 41² + 41 + 41 이므로 소수가 아닙니다.  
  
컴퓨터의 발전에 힘입어 n² − 79n + 1601 이라는 엄청난 이차식이 발견되었는데, 이것은 n이 0에서 79 사이일 때 모두 80개의 소수를 만들어냅니다. 이 식의 계수의 곱은 -79 × 1601 = -126479가 됩니다.  
  
아래와 같은 모양의 이차식이 있다고 가정했을 때,  
  
n² + an + b   (단 |a| < 1000, |b| < 1000)  
  
0부터 시작하는 연속된 n에 대해 가장 많은 소수를 만들어내는 이차식을 찾아서, 그 계수 a와 b의 곱을 구하세요.

## 🧠 배운 점  
- n이 0일 때의 값은 **f(0) = b**이므로, b는 **반드시 소수**  
- 소수를 연속적으로 만들기 위해서는 **n 증가마다 결과가 소수인지 판별**해야 함  
- b는 2 이상 999 이하의 소수로만 제한하여 **탐색 범위 축소**  
- a는 -999 ~ 999 전체를 순회하며, 각 (a, b) 조합마다 n을 증가시키며 소수 판별  
- 최대 연속 소수 길이를 만든 (a, b) 조합을 저장하고, **최종적으로 a × b 출력**  
