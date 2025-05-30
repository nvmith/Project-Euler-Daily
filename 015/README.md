# Problem 015 - 20×20 격자의 좌상단에서 우하단으로 가는 경로의 수 
 
## 📝 문제 설명
아래와 같은 2 × 2 격자의 왼쪽 위 모서리에서 출발하여 오른쪽 아래 모서리까지 도달하는 길은 모두 6가지가 있습니다 (거슬러 가지는 않기로 합니다).  
  
그러면 20 × 20 격자에는 모두 몇 개의 경로가 있습니까?

## 🧠 배운 점
- 이 문제는 격자에서 오른쪽, 아래쪽으로만 이동하는 경로의 수를 구하는 **조합(combination)** 문제
- 총 40번 이동 중 **20번을 오른쪽으로, 20번을 아래로 이동**해야 하므로, 이는 곧 `40C20` 계산
- `nCk = n! / (k! × (n-k)!)` 공식을 직접 쓰면 `n!`이 너무 커져 `long long` 범위를 초과할 수 있음
- 그래서 **(n × (n-1) × ... × (n-k+1)) / (k!)** 형태로 바꿔 계산
- 코드에서는 `res *= (n - i + 1); res /= i;` 식으로 **곱하면서 동시에 나눠주는 방식**을 사용
- 분자와 분모에 겹치는 항을 중복 계산하지 않도록 최적화
