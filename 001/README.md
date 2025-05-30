# Problem 001 - 1000보다 작은 자연수 중에서 3 또는 5의 배수를 모두 더하면?

## 📝 문제 설명
10보다 작은 자연수 중에서 3 또는 5의 배수는 3, 5, 6, 9 이고, 이것을 모두 더하면 23입니다.  
1000보다 작은 자연수 중에서 3 또는 5의 배수를 모두 더하면 얼마일까요?

## 🧠 배운 점
- 처음엔 단순한 반복문 문제로 생각했지만, 사실 수학적으로는 **합집합(A ∪ B)의 합을 구하는 문제** 
- 이 과정에서 **포함배제의 원리**가 적용된다는 것을 깨달음 
- 즉, A ∪ B = A + B − A ∩ B 이고, 이때 A ∩ B는 15의 배수
